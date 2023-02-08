#include <sstream>


#include "Executor.h"

using namespace std;


Executor::Executor() {
    Driver *driver = get_driver_instance();
    this->conn = driver->connect("tcp://localhost:3306/mydatalog", "admin", "Admin1234567890");
    // this->conn = driver->connect("jdbc:mysql://localhost:3306/mydatalog", "admin", "Admin1234567890");
}

Executor::~Executor() {
    delete this->conn;
}

void Executor::nonRecursiveRuleEval() {
}

void Executor::recursiveRuleEval() {
}

void Executor::dropTable(string tableName) {
    ostringstream oss;
    oss << "DROP TALBE "
        << tableName;
    
    string sqlStr = oss.str();
    Statement *stmt = this->conn->createStatement();
    stmt->execute(sqlStr);
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
    string sqlStr = oss.str();
    std::cout << sqlStr << std::endl;
    // this->conn->execute(sqlStr);
}

void Executor::createTables(vector<Schema>& relations) {
    for (auto relation : relations) {
        this->createTable(relation);
    }
}

void Executor::loadData(vector<Schema>& relations) {
    // load data infile "your csv file path" into table [tablename] fields terminated by ','
}