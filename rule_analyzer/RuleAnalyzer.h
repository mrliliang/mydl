#pragma once

#include <vector>
#include <map>
#include <stack>

#include "../parser/basetype.h"

struct DependencyGraph
{
    vector<vector<int>> *dependency;
    vector<vector<int>> *negDependency;

    DependencyGraph()
    {
        this->dependency = new vector<vector<int>>{};
        this->negDependency = new vector<vector<int>>{};
    }

    ~DependencyGraph()
    {
        delete dependency;
        delete negDependency;
    }
};

struct RuleGroup
{
    RuleGroup(vector<int> &rules, bool recursive) : rules{rules}, isRecursive{recursive} {

    }
    vector<int> rules;
    bool isRecursive;
};

class RuleAnalyzer
{
public:
    RuleAnalyzer(vector<RuleMap> *rules);
    ~RuleAnalyzer();

    

private:
    map<string, vector<int>> *atomRuleMap = nullptr;
    vector<string> *ruleAtomMap = nullptr;
    DependencyGraph *dg = nullptr;
    map<int, vector<int>> *sccs = nullptr;
    bool stratifiable;
    vector<RuleGroup> *ruleGroups = nullptr;

    map<string, vector<int>> *constructAtomRuleMap(vector<RuleMap> *rules);

    vector<string> *constructRuleAtomMap(vector<RuleMap> *rules);

    DependencyGraph *constructDependencyGraph(vector<RuleMap> *rules);

    map<int, vector<int>> *computeRuleSccs(vector<vector<int>> *dependency);

    bool checkNegationCycle(map<int, vector<int>> *sccs, vector<vector<int>> *negDependency);

    bool isRecursiveScc(vector<int> *scc, vector<vector<int>> *dependency);

    vector<RuleGroup> *groupRules(vector<string> *ruleAtomMap, map<int, vector<int>> *sccs, vector<vector<int>> *dependency);

    void visit(int rule, vector<vector<int>> *dependency, vector<bool> *visitFlag,
               stack<int> *dfsReversePostOrder);

    void assign(int rule, int root, vector<vector<int>> *transpose,
                vector<bool> *visitFlag, map<int, vector<int>> *sccs);
};
