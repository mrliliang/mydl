#include <sstream>
#include <mysql.h>


#include "Executor.h"

using namespace std;


Executor::Executor() {
}

void Executor::nonRecursiveRuleEval() {
}

void Executor::recursiveRuleEval() {
}

void Executor::dropTable(string tableName) {
    ostringstream oss;
    oss << "DROP TALBE "
        << tableName;
    
    MYSQL mysql;
}

void Executor::createTable(Schema& relation) {
    this->dropTable(relation.name);

    ostringstream oss;
    oss << "CREATE TALBE "
        << relation.name
        << " "
        << "(";

    for (auto it = relation.attributes.begin(); it != relation.attributes.end(); it++) {
        if (it != relation.attributes.begin()) {
            oss << ",";
        }
        oss << it->name
            << " "
            << it->type;
    }
    oss << ")";
    string sql = oss.str();
    
}

void Executor::createTables(vector<Schema>& relations) {
    for (auto relation : relations) {
        this->createTable(relation);
    }
}

void Executor::loadData(vector<Schema>& relations) {
    // load data infile "your csv file path" into table [tablename] fields terminated by ','
}