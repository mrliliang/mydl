#pragma once

#include "../parser/basetype.h"
#include <mysql/jdbc.h>

using namespace std;
using namespace sql;

class Executor {
    public:
        Executor();
        ~Executor();

        void nonRecursiveRuleEval(vector<RuleMap> &rules);
        void recursiveRuleEval();

        void dropTable(string tableName);
        void createTable(Schema& relation);
        void createTables(vector<Schema>& relations);
        void loadData(Schema& relation);
        void loadData(vector<Schema>& relations);

    private:
        Connection *conn = nullptr;
};