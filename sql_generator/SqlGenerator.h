#pragma once

#include <string>

#include "../parser/basetype.h"

using namespace std;

class SqlGenerator {
    public:
        string generateRuleEval(RuleMap &rule, bool recursive);
        string generateRulesEval(vector<RuleMap> &rules, bool recursive);

        string generateInsertion();
        string generateSelection();
        string generateFrom();
        string generateFromRecursive();
        string generateJoin();
        string generateComparision();
        string generateConstantConstraint();
        string generateNegation();
        string generateGroupBy();
        string generateIntersection();
        string generateSetDiff();
};