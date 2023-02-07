#pragma once

#include "../parser/basetype.h"

class Executor {
public:
    Executor();

    void nonRecursiveRuleEval();
    void recursiveRuleEval();

    void dropTable(string tableName);
    void createTable(Schema& relation);
    void createTables(vector<Schema>& relations);
    void loadData(vector<Schema>& relations);
};