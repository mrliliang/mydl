#pragma once

#include <string>
#include <vector>
#include <map>

#include "basetype.h"
#include "MyDatalogLexer.h"
#include "MyDatalogParser.h"
#include "../rule_analyzer/RuleAnalyzer.h"

using namespace std;


// struct DependencyGraph {
//     vector<vector<int>> posDependency;
//     vector<vector<int>> negDependency;
// };

// struct RuleGroup {
//     vector<int> group;
//     bool isRecursive;
// };

class DatalogProgram {
public:
    DatalogProgram(string datalogFile);
    ~DatalogProgram();

    vector<Schema> &getEdbs();
    vector<Schema> &getIdbs();
    vector<RuleMap> &getRules();
    RuleMap &getRule(int index);
    void print();

private:
    vector<Schema> edbs;
    vector<Schema> idbs;
    vector<RuleMap> rules;

    // DependencyGraph dg;
    // map<int, vector<int>> sccs;
    // vector<RuleGroup> ruleGroups;

    void iterateDatalogProgram(vector<RuleMap> &rules);
    void iterateDatalogRule(RuleMap &rule);
    void iterateEdbIdb(vector<Schema> &relations);

};
