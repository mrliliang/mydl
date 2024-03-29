#include <iostream>
#include <sstream>
#include <memory>
#include <set>


#include "Executor.h"
#include "../config/Config.h"
#include "../sql_generator/SqlGenerator.h"

using namespace std;


Executor::Executor() {
    try {
        Driver *driver = get_driver_instance();
        this->conn = driver->connect("tcp://localhost:3306/mydatalog", "admin", "Admin1234567890");
    } catch (sql::SQLException e) {
        std::cout << "ERROR: " << e.what() << std::endl;
        exit(-1);
    }
}

Executor::~Executor() {
    if (this->conn != nullptr) {
        this->conn->close();
    }
    delete this->conn;
}

void Executor::nonRecursiveEval(vector<RuleMap> &rules, DatalogProgram& pg) {
    //for non-recursive rules, rules with the same idb head are in the same group
    string idb = rules[0].head.name;
    Schema& relation = pg.getIdbRelation(idb);
    //create a temporary table idb_tmp to save the result with duplication
    string tmpTable{idb + "_tmp"};
    this->createTable(relation, tmpTable);

    SqlGenerator sqlGen;
    for (auto rule : rules) {
        string query{sqlGen.generateRuleEval(rule, pg)};
        //keep the evaluation result in the tmp table idb_tmp
        string insert{sqlGen.generateInsertion(tmpTable, query)};
        std::cout << insert << std::endl;
        this->execute(insert);
    }
    //perform deduplication in tmp table and save the result in idb table
    //FIXME: 是否需要考虑aggregation?
    this->deduplicate(tmpTable, idb, relation);
    this->dropTable(tmpTable);
}

void Executor::recursiveEval(vector<RuleMap> &rules, DatalogProgram& pg) {
    //rules with the same head idb are grouped together
    map<string, vector<RuleMap*>> recursiveRuleGroups;
    for (auto& r : rules) {
        recursiveRuleGroups[r.head.name].emplace_back(&r);
    }

    //initialize delta tables for recursive idbs to store new facts in the current iteration
    //FIXME: delta idb初始化是否正确？
    this->initDeltaTables(recursiveRuleGroups, pg);

    //initialize prev tables for recursive idbs to store all facts before the current iteration
    //FIXME: prev table初始化是否正确？
    vector<string> prevTables;
    this->initPrevTables(prevTables, rules, recursiveRuleGroups, pg);


    int iterateNum = 0;
    bool deltaEmpty = this->checkEmptyDelta(recursiveRuleGroups, iterateNum);
    while (!deltaEmpty) {
        iterateNum++;

        //create delta tables of the recursive idbs for current iteration
        this->createDeltaTables(recursiveRuleGroups, iterateNum, pg);

        for (auto& group : recursiveRuleGroups) {
            string idb = group.first;
            Schema& relation = pg.getIdbRelation(idb);
            string idbDeltaTable = idb + string("_delta_") + std::to_string(iterateNum);

            //create temporay tmp_delta_dup table to store result without deduplication for current idb
            string tmpDeltaDupTable = idb + "_tmp_delta_dup";
            this->createTable(relation, tmpDeltaDupTable);

            vector<string> queries;
            map<int, string> headAggregation;
            for (RuleMap* rule : group.second) {
                AtomMap& head = rule->head;
                for (int i = 0; i < head.argList.size(); i++) {
                    if (head.argList[i].isAgg()) {
                        headAggregation[i] = head.argList[i].aggmap.aggOp;
                    }
                }

                //generate a set of sql for the delta rules of a recursive rule
                SqlGenerator sqlGen;
                vector<string> subQueries = sqlGen.generateRecursiveRuleEval(*rule, 
                    recursiveRuleGroups, iterateNum - 1, pg);
                queries.insert(queries.end(), subQueries.begin(), subQueries.end());
                for (auto& subquery : subQueries) {
                    string insertion = sqlGen.generateInsertion(tmpDeltaDupTable, subquery);
                    std::cout << insertion << std::endl;
                    this->execute(insertion);
                }
            }

            //create tmp_delta_nodup table for the current idb to be used for deduplication
            string tmpDeltaNodupTable = idb + "_tmp_delta_nodup";
            this->createTable(relation, tmpDeltaNodupTable);

            //perform deduplication in tmp_delta_dup table, and store the result in 
            //tmp_delta_nodup table, then drop the tmp_delta_dup table
            this->deduplicate(tmpDeltaDupTable, tmpDeltaNodupTable, relation);
            this->dropTable(tmpDeltaDupTable);

            //TODO: perform set difference between tmp_delta_nodup table and idb table, save the diff in 
            // idb delta table, then drop the tmp_delta_nodup table.
            //FIXME: diff做aggregation操作可能结果不正确
            this->diff(tmpDeltaNodupTable, idb, idbDeltaTable, relation, headAggregation);
            // drop tmp_delta_nodup table
            this->dropTable(tmpDeltaNodupTable);

            //TODO: if current idb is non-linear recursive, move current idb facts to idb_prev table
            string prevTable = idb + "_prev";
            if (std::find(prevTables.begin(), prevTables.end(), prevTable) != prevTables.end()) {
                this->createTable(relation, prevTable);
                this->moveData(idb, prevTable);
            }

            //TODO: merge new facts in idb delta table into idb table
            //FIXME: is it right the merge delta into idb here?
            this->moveData(idbDeltaTable, idb);
        }

        //drop old delta tables in the last iteration
        this->dropDeltaTables(recursiveRuleGroups, iterateNum - 1);

        //check fixpoint
        deltaEmpty = this->checkEmptyDelta(recursiveRuleGroups, iterateNum);
    }

    //drop all prev tables for nonlinear idbs
    for (auto table : prevTables) {
        this->dropTable(table);
    }
    
    //drop delta tables in the final iteration
    this->dropDeltaTables(recursiveRuleGroups, iterateNum);
}

void Executor::dropTable(string tableName) {
    // ostringstream oss;
    // oss << "DROP TABLE IF EXISTS `"
    //     << tableName
    //     << "`;";
    
    SqlGenerator sqlGen;
    string sqlStr = sqlGen.generateDrop(tableName);
    std::cout << sqlStr << std::endl;
    this->execute(sqlStr);
}

void Executor::createTable(Schema& relation, string tableName) {
    this->dropTable(tableName);

    // ostringstream oss;
    // oss << "CREATE TABLE `"
    //     << tableName
    //     << "` (";

    // for (auto it = relation.attributes.begin(); it != relation.attributes.end(); it++) {
    //     if (it != relation.attributes.begin()) {
    //         oss << ", ";
    //     }
    //     oss << "`"
    //         << it->name
    //         << "` "
    //         << it->type;
    // }
    // oss << ");";
    SqlGenerator sqlGen;
    string sqlStr = sqlGen.generateCreate(relation, tableName);
    std::cout << sqlStr << std::endl;
    this->execute(sqlStr);
}

void Executor::createTables(vector<Schema>& relations) {
    for (auto relation : relations) {
        this->createTable(relation, relation.name);
    }
}

void Executor::loadData(Schema& relation) {
    ostringstream oss;
    oss << "LOAD DATA INFILE '"
        << Config::INPUT_DIR
        << "/"
        << relation.name
        << ".csv' INTO TABLE `"
        << relation.name
        << "` FIELDS TERMINATED BY ',';";
    string sqlStr{oss.str()};
    std::cout << sqlStr << std::endl;
    this->execute(sqlStr);
}

void Executor::loadData(vector<Schema>& relations) {
    // load data infile "your csv file path" into table [table name] fields terminated by ','
    for (auto relation : relations) {
        loadData(relation);
    }
}


void Executor::execute(string sql) {
    unique_ptr<Statement> stmt{this->conn->createStatement()};
    stmt->execute(sql);
}

unique_ptr<ResultSet> Executor::executeQuery(string sql) {
    unique_ptr<Statement> stmt{this->conn->createStatement()};
    unique_ptr<ResultSet> ret{stmt->executeQuery(sql)};
    return ret;
}


void Executor::initDeltaTables(map<string, vector<RuleMap*>>& recursiveRuleGroups, 
    DatalogProgram& pg) {
    //TODO: initialize delta_0, m_delta, common_delta, tmp_m_delta
    for (auto& group : recursiveRuleGroups) {
        string idb = group.first;
        vector<RuleMap*>& rules = group.second;
        string deltaTableName{idb + "_delta_0"};
        Schema& relation = pg.getIdbRelation(idb);
        this->createTable(relation, deltaTableName);
        //copy idb to idb_delta_0
        this->moveData(idb, deltaTableName);

        //TODO: common_delta, may not need

        //TODO: m_delta, may not need

        //TODO: tmp_m_delta, may not need
    }
}


void Executor::initPrevTables(vector<string>& prevTables, 
            vector<RuleMap>& recursiveRules, 
            map<string, vector<RuleMap*>>& recursiveRuleGroups, 
            DatalogProgram& pg) {
    //TODO: initialize prev table for nonlinear recursive idbs to store all facts till the last iteration
    vector<string> nonlinearIdbs;
    for (auto& rule : recursiveRules) {
        vector<string> candidates;
        for (auto& atom : rule.body.atoms) {
            if (recursiveRuleGroups.find(atom.name) != recursiveRuleGroups.end()) {
                candidates.emplace_back(atom.name);
            }
        }
        if (candidates.size() >= 2) {
            nonlinearIdbs.insert(nonlinearIdbs.end(), candidates.begin(), candidates.end());
        }
    }

    for (auto& idb : nonlinearIdbs) {
        Schema& relation = pg.getIdbRelation(idb);
        string prevTableName = idb + "_prev";
        prevTables.emplace_back(prevTableName);
        this->createTable(relation, prevTableName);
    }
}


bool Executor::checkEmptyDelta(map<string, vector<RuleMap*>>& recursiveRuleGroups, int iterateNum) {
    for (auto& group : recursiveRuleGroups) {
        string idb = group.first;
        string idbDeltaTable = idb + string("_delta_") + std::to_string(iterateNum);
        int rowCount = this->countRows(idbDeltaTable);
        if (rowCount > 0) {
            return false;
        }
    }
    return true;
}


void Executor::createDeltaTables(map<string, vector<RuleMap*>>& recursiveRuleGroups, 
    int iterateNum,
    DatalogProgram& pg) {
    for (auto& group : recursiveRuleGroups) {
        string idb = group.first;
        Schema& relation = pg.getIdbRelation(idb);
        ostringstream oss;
        oss << idb 
            << "_delta_"
            << iterateNum;
        this->createTable(relation, oss.str());
    }
}


void Executor::dropDeltaTables(map<string, vector<RuleMap*>>& recursiveRuleGroups, int iterateNum) {
    for (auto& group : recursiveRuleGroups) {
        string idb = group.first;
        ostringstream oss;
        oss << idb 
            << "_delta_"
            << iterateNum;
        this->dropTable(oss.str());
    }
}


void Executor::deduplicate(string dupTable, string noDupTable, Schema& relation) {
    ostringstream oss;
    oss << "INSERT INTO "
        << noDupTable
        << " SELECT * FROM "
        << dupTable
        << " GROUP BY ";
    for (auto it = relation.attributes.begin(); it != relation.attributes.end(); it++) {
        if (it != relation.attributes.begin()) {
            oss << ", ";
        }
        oss << it->name;
    }
    this->execute(oss.str());
}


void Executor::diff(string tmpIdbDelta, 
    string idb, 
    string idbDelta, 
    Schema& relation, 
    map<int, string>& headAggregation) {
    //delta = tmpIdbDelta - idb, store delta in idbDelta table
    int tmpIdbDeltaCount = this->countRows(tmpIdbDelta);
    if (tmpIdbDeltaCount == 0) {
        return;
    }

    int idbCount = this->countRows(idb);
    if (idbCount == 0) {
        this->moveData(tmpIdbDelta, idbDelta);
        return;
    }

    SqlGenerator sqlGen;
    string diffSql{sqlGen.generateSetDiff(tmpIdbDelta, idb, idbDelta, relation, headAggregation)};
    this->execute(diffSql);
}


void Executor::moveData(string srcTable, string destTable) {
    ostringstream oss;
    oss << "INSERT INTO "
        << destTable
        << " SELECT * FROM "
        << srcTable;
    this->execute(oss.str());
}


int Executor::countRows(string table) {
    ostringstream oss;
    oss << "SELECT COUNT(*) FROM "
        << table;
    unique_ptr<ResultSet> ret = this->executeQuery(oss.str());
    int count = 0;
    while (ret->next()) {
        count = ret->getInt(1);
    }
    return count;
}


