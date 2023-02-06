#include "../parser/basetype.h"

class Executor {
    public:
        Executor();

        void nonRecursiveRuleEval();
        void recursiveRuleEval();

        void createRelation(Schema &relation);
        void createRelations(vector<Schema> &relations);
        void loadData(vector<Schema> &relations);
};