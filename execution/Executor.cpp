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
    SqlGenerator sqlGen;
    unique_ptr<Statement> stmt{this->conn->createStatement()};
    for (auto rule : rules) {
        string evalStr{sqlGen.generateRuleEval(rule, pg)};
        stmt->execute(evalStr);
        //TODO: perform deduplication
        
    }
}

void Executor::recursiveEval(vector<RuleMap> &rules, DatalogProgram& pg) {
    map<string, vector<RuleMap*>> recursiveRuleGroups;
    for (auto r : rules) {
        recursiveRuleGroups[r.head.name].emplace_back(&r);
    }

    //initialize delta tables for recursive idbs to store new facts in the current iteration
    this->initDeltaTables(recursiveRuleGroups, pg);

    //initialize prev tables for recursive idbs to store all facts before the current iteration
    vector<string> prevTables;
    this->initPrevTables(prevTables, rules, recursiveRuleGroups, pg);


    int iterateNum = 0;
    bool deltaEmpty = this->checkEmptyDelta(recursiveRuleGroups);
    while (!deltaEmpty) {
        iterateNum++;

        //TODO: create delta tables of the recursive idbs for current iteration
        this->createDeltaTables(recursiveRuleGroups, iterateNum, pg);

        for (auto group : recursiveRuleGroups) {
            string idb = group.first;

            //TODO: create m_delta table for the current idb to be used for deduplication later
            Schema& relation = pg.getIdbRelation(idb);
            string mDeltaTable = idb + "_m_delta";
            this->createTable(relation, mDeltaTable);

            //TODO: create temporay table to store result before deduplication
            string tmpDeltaTable = idb + "tmp_m_delta";
            this->createTable(relation, tmpDeltaTable);

            unique_ptr<Statement> stmt{this->conn->createStatement()};
            vector<string> queries;
            for (RuleMap* rule : group.second) {
                //TODO: generate a set of sql for the delta rules of a recursive rule
                SqlGenerator sqlGen;
                vector<string> subQueries = sqlGen.generateRecursiveRuleEval(*rule, 
                    recursiveRuleGroups, iterateNum, pg);
                queries.insert(queries.end(), subQueries.begin(), subQueries.end());
                for (auto subquery : subQueries) {
                    string insertion = this->generateInsertion(tmpDeltaTable, subquery);
                    stmt->execute(insertion);
                }
            }

            //TODO: perform deduplication
            this->deduplicate(tmpDeltaTable, relation);

            //TODO: perform set difference, merge new facts into the result table
            // this->diff();

            //TODO: drop m_delta table

            //TODO: save current idb

        }

        //TODO: drop all old delta tables


        //TODO: check fixpoint
        deltaEmpty = this->checkEmptyDelta(recursiveRuleGroups);
    }
}

void Executor::dropTable(string tableName) {
    ostringstream oss;
    oss << "DROP TABLE IF EXISTS `"
        << tableName
        << "`;";
    
    string sqlStr = oss.str();
    std::cout << sqlStr << std::endl;
    unique_ptr<Statement> stmt{this->conn->createStatement()};
    stmt->execute(sqlStr);
}

void Executor::createTable(Schema& relation, string tableName) {
    this->dropTable(tableName);

    ostringstream oss;
    oss << "CREATE TABLE `"
        << tableName
        << "` (";

    for (auto it = relation.attributes.begin(); it != relation.attributes.end(); it++) {
        if (it != relation.attributes.begin()) {
            oss << ", ";
        }
        oss << "`"
            << it->name
            << "` "
            << it->type;
    }
    oss << ");";
    string sqlStr = oss.str();
    std::cout << sqlStr << std::endl;
    unique_ptr<Statement> stmt{this->conn->createStatement()};
    stmt->execute(sqlStr);
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
    unique_ptr<Statement> stmt{this->conn->createStatement()};
    stmt->execute(sqlStr);
}

void Executor::loadData(vector<Schema>& relations) {
    // load data infile "your csv file path" into table [tablename] fields terminated by ','
    for (auto relation : relations) {
        loadData(relation);
    }
}


void Executor::initDeltaTables(map<string, vector<RuleMap*>>& recursiveRuleGroups, 
    DatalogProgram& pg) {
    //TODO: initialize delta_0, m_delta, common_delta
    for (auto group : recursiveRuleGroups) {
        string idb = group.first;
        vector<RuleMap*>& rules = group.second;
        string deltaTableName{idb + "_delta_0"};
        Schema& relation = pg.getIdbRelation(idb);
        this->createTable(relation, deltaTableName);
    }
}


void Executor::initPrevTables(vector<string> prevTables, 
            vector<RuleMap>& recursiveRules, 
            map<string, vector<RuleMap*>>& recursiveRuleGroups, 
            DatalogProgram& pg) {
    //TODO: initialize prev table for nonlinear recursive idbs to store all facts till the last iteration
    vector<string> nonlinearIdbs;
    for (auto rule : recursiveRules) {
        int count = 0;
        vector<string> candidates;
        for (auto atom : rule.body.atoms) {
            if (recursiveRuleGroups.find(atom.name) != recursiveRuleGroups.end()) {
                count++;
                candidates.emplace_back(atom.name);
            }
        }
        if (count >= 2) {
            nonlinearIdbs.insert(nonlinearIdbs.end(), candidates.begin(), candidates.end());
        }
    }

    for (auto idb : nonlinearIdbs) {
        Schema& relation = pg.getIdbRelation(idb);
        string prevTableName = idb + "_prev";
        prevTables.emplace_back(prevTableName);
        this->createTable(relation, prevTableName);
    }
}


bool Executor::checkEmptyDelta(map<string, vector<RuleMap*>>& recursiveRuleGroups) {
    //TODO: to be completed
    return false;
}


void Executor::createDeltaTables(map<string, vector<RuleMap*>>& recursiveRuleGroups, 
    int iterateNum,
    DatalogProgram& pg) {
    //TODO: to be competed
    for (auto group : recursiveRuleGroups) {
        string idb = group.first;
        Schema& relation = pg.getIdbRelation(idb);
        ostringstream oss;
        oss << idb 
            << "_delta_"
            << iterateNum;
        this->createTable(relation, oss.str());
    }
}


void Executor::deduplicate(string tableName, Schema& relation) {
    //TODO: perform deduplication, to be completed
}