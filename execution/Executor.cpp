#include <iostream>
#include <sstream>
#include <memory>


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

void Executor::nonRecursiveEval(vector<RuleMap> &rules) {
    SqlGenerator sqlGen;
    unique_ptr<Statement> stmt{this->conn->createStatement()};
    for (auto rule : rules) {
        string evalStr{sqlGen.generateRuleEval(rule, false)};
        stmt->execute(evalStr);
    }
}

void Executor::recursiveEval(vector<RuleMap> &rules) {
    bool deltaEmpty{false};
    while (!deltaEmpty) {
        SqlGenerator sqlGen;
        string evalStr{sqlGen.generateRulesEval(rules, true)};
        Statement *stmt = this->conn->createStatement();
        stmt->execute(evalStr);
        //TODO to be completed
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

void Executor::createTable(Schema& relation) {
    this->dropTable(relation.name);

    ostringstream oss;
    oss << "CREATE TABLE `"
        << relation.name
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
        this->createTable(relation);
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