
#include <iostream>
#include <unordered_set>

#include "RuleAnalyzer.h"

RuleAnalyzer::RuleAnalyzer(vector<RuleMap> *rules)
{
    this->atomRuleMap = this->constructAtomRuleMap(rules);
    this->ruleAtomMap = this->constructRuleAtomMap(rules);
    this->dg = this->constructDependencyGraph(rules);
    this->sccs = this->computeRuleSccs(this->dg->dependency);
    this->stratifiable = this->checkNegationCycle(this->sccs, this->dg->negDependency);
    this->ruleGroups = this->groupRules(this->ruleAtomMap, this->sccs, this->dg->dependency);
}

RuleAnalyzer::~RuleAnalyzer()
{
    delete this->atomRuleMap;
    delete this->ruleAtomMap;
    delete this->dg;
    delete this->sccs;
    delete this->ruleGroups;
}

map<string, vector<int>> *RuleAnalyzer::constructAtomRuleMap(vector<RuleMap> *rules)
{
    map<string, vector<int>> *headRuleMap = new map<string, vector<int>>{};
    for (auto i = 0; i < rules->size(); i++)
    {
        auto rule = rules->at(i);
        string name = rule.head.name;
        if (headRuleMap->find(name) == headRuleMap->end())
        {
            (*headRuleMap)[name] = vector<int>();
        }
        headRuleMap->at(name).emplace_back(i);
    }
    return headRuleMap;
}

vector<string> *RuleAnalyzer::constructRuleAtomMap(vector<RuleMap> *rules)
{
    vector<string> *ruleAtomMap = new vector<string>{};
    for (auto rule : *rules)
    {
        ruleAtomMap->emplace_back(rule.head.name);
    }
    return ruleAtomMap;
}

DependencyGraph *RuleAnalyzer::constructDependencyGraph(vector<RuleMap> *rules)
{
    map<string, vector<int>> *headRuleMap = this->constructAtomRuleMap(rules);
    DependencyGraph *dg = new DependencyGraph{};

    for (int i = 0; i < rules->size(); i++)
    {
        auto rule = (*rules)[i];
        dg->dependency->emplace_back(vector<int>());
        dg->negDependency->emplace_back(vector<int>());

        for (auto atom : rule.body.atoms)
        {
            if (headRuleMap->find(atom.name) != headRuleMap->end())
            {
                for (auto dependentRuleIndex : (*headRuleMap)[atom.name])
                {
                    dg->dependency->at(i).emplace_back(dependentRuleIndex);
                }
            }
        }

        for (auto atom : rule.body.negations)
        {
            if (headRuleMap->find(atom.name) != headRuleMap->end())
            {
                for (auto dependentRuleIndex : (*headRuleMap)[atom.name])
                {
                    dg->dependency->at(i).emplace_back(dependentRuleIndex);
                    dg->negDependency->at(i).emplace_back(dependentRuleIndex);
                }
            }
        }
    }

    return dg;
}

map<int, vector<int>> *RuleAnalyzer::computeRuleSccs(vector<vector<int>> *dependency)
{
    vector<bool> visitFlag{static_cast<bool>(dependency->size()), false};
    vector<int> ruleAssignedMap{static_cast<int>(dependency->size()), 0};
    stack<int> dfsReversePostOrder;
    map<int, vector<int>> *sccs;

    for (int rule = 0; rule < dependency->size(); rule++)
    {
        this->visit(rule, dependency, &visitFlag, &dfsReversePostOrder);
    }

    vector<vector<int>> transpose{dependency->size(), vector<int>{}};
    for (int rule = 0; rule < dependency->size(); rule++)
    {
        for (auto dependentRule : dependency->at(rule))
        {
            transpose[dependentRule].emplace_back(rule);
        }
    }

    std::fill(visitFlag.begin(), visitFlag.end(), false);
    while (!dfsReversePostOrder.empty())
    {
            auto rule = dfsReversePostOrder.top();
            dfsReversePostOrder.pop();
            this->assign(rule, rule, &transpose, &visitFlag, sccs);
    }

    return sccs;
}

void RuleAnalyzer::visit(int rule, vector<vector<int>> *dependency, vector<bool> *visitFlag,
                         stack<int> *dfsReversePostOrder)
{
    if ((*visitFlag)[rule])
    {
        return;
    }
    (*visitFlag)[rule] = true;
    for (auto dependentRule : dependency->at(rule))
    {
        visit(dependentRule, dependency, visitFlag, dfsReversePostOrder);
    }
    dfsReversePostOrder->push(rule);
}

void RuleAnalyzer::assign(int rule, int root, vector<vector<int>> *transpose, 
                          vector<bool> *visitFlag, map<int, vector<int>> *sccs)
{
    if (visitFlag->at(rule)) {
        return;
    }
    (*visitFlag)[rule] = true;
    if (sccs->find(root) == sccs->end()) {
        (*sccs)[root] = vector<int>();
        sccs->at(root).emplace_back(root);
    }
    sccs->at(root).emplace_back(rule);

    for (auto reverseDependentRule : transpose->at(rule)) {
        assign(reverseDependentRule, root, transpose, visitFlag, sccs);
    }
}

bool RuleAnalyzer::checkNegationCycle(map<int, vector<int>> *sccs,
                                      vector<vector<int>> *negDependency)
{
    bool negCycle{false};

    for (auto it : *sccs) {
        int sccKey = it.first;
        vector<int> &scc = it.second;

        bool curNegCycle{false};
        bool findNegCycle = false;
        for (auto rule : scc) {
            if (findNegCycle) {
                break;
            }
            for (auto dependentRule : negDependency->at(rule)) {
                if (std::find(scc.begin(), scc.end(), dependentRule) != scc.end()) {
                    findNegCycle = true;
                    curNegCycle = true;
                    negCycle = true;
                    break;
                }
            }
        }
        if (curNegCycle) {
            std::cout << "Negation cycle is detected in scc[" << sccKey << "]" << endl;
        }
    }

    return negCycle;
}

bool RuleAnalyzer::isRecursiveScc(vector<int> *scc, vector<vector<int>> *dependency)
{
    if (scc->size() >=2) {
        return true;
    }

    int rule = scc->at(0);
    vector<int> &depRules = dependency->at(rule);
    if (std::find(depRules.begin(), depRules.end(), rule) == depRules.end()) {
        return false;
    }

    return true;
}

vector<RuleGroup> *RuleAnalyzer::groupRules(vector<string> *ruleAtomMap, map<int, vector<int>> *sccs,
                                            vector<vector<int>> *dependency)
{
    vector<RuleGroup> *groups = new vector<RuleGroup>{};
    unordered_set<string> nonRecursiveRuleHeads;

    for (auto it : *sccs) {
        int sccKey = it.first;
        vector<int> &scc = it.second;

        if (this->isRecursiveScc(&scc, dependency)) {
            groups->emplace_back(RuleGroup(scc, true));
        }
        else {
            string headName = ruleAtomMap->at(sccKey);
            if (nonRecursiveRuleHeads.find(headName) == nonRecursiveRuleHeads.end()) {
                groups->emplace_back(RuleGroup(scc, false));
            }
            else {
                nonRecursiveRuleHeads.insert(headName);
            }
        }
    }

    return groups;
}
