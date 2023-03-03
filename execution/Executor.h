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
        void createTable(Schema& relation, string tableName);
        void createTables(vector<Schema>& relations);
        void loadData(Schema& relation);
        void loadData(vector<Schema>& relations);
        void execute(string sql);
        unique_ptr<ResultSet> executeQuery(string sql);

    private:
        Connection *conn = nullptr;

        void initDeltaTables(map<string, vector<RuleMap*>>& recursiveRuleGroups, DatalogProgram& pg);
        void initPrevTables(vector<string> prevTables, 
            vector<RuleMap>& recursiveRules, 
            map<string, vector<RuleMap*>>& recursiveRuleGroups, 
            DatalogProgram& pg);
        bool checkEmptyDelta(map<string, vector<RuleMap*>>& recursiveRuleGroups, int iterateNum);
        void createDeltaTables(map<string, vector<RuleMap*>>& recursiveRuleGroups, 
            int iterateNum, 
            DatalogProgram& pg);
        void dropDeltaTables(map<string, vector<RuleMap*>>& recursiveRuleGroups, int iterateNum);
        void deduplicate(string dupTable, string noDupTable, Schema& relation);
        void diff(string tmpIdbDelta, string idb, string idbDelta, Schema& relation, 
            map<int, string>& headAggregation);
        void moveData(string srcTable, string destTable);
        int countRows(string table);
};