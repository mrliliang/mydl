#pragma once

#include <mysql/jdbc.h>
#include "../parser/basetype.h"
#include "../parser/DatalogProgram.h"

using namespace std;
using namespace sql;

class Executor {
    public:
        Executor();
        ~Executor();

        void nonRecursiveEval(vector<RuleMap> &rules, DatalogProgram& pg);
        void recursiveEval(vector<RuleMap> &rules, DatalogProgram& pg);

        void dropTable(string tableName);
        void createTable(Schema& relation);
        void createTables(vector<Schema>& relations);
        void loadData(Schema& relation);
        void loadData(vector<Schema>& relations);

    private:
        Connection *conn = nullptr;
};