
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>

#include "RuleAnalyzer.h"

RuleAnalyzer::RuleAnalyzer(vector<RuleMap> *rules)
{
    this->atomRuleMap = this->constructAtomRuleMap(rules);
    this->ruleAtomMap = this->constructRuleAtomMap(rules);
    this->dg = this->constructDependencyGraph(rules);

    // this->sccs = this->computeRuleSccs(this->dg->dependency);
    this->sccs1 = this->computeRuleSccs1(this->dg->dependency);

    // this->stratifiable = this->checkNegationCycle(this->sccs, this->dg->negDependency);
    this->stratifiable = this->checkNegationCycle1(this->sccs1, this->dg->negDependency);

    // this->ruleGroups = this->groupRules(this->ruleAtomMap, this->sccs, this->dg->dependency);
    this->ruleGroups = this->groupRules1(this->ruleAtomMap, this->sccs1, this->dg->dependency);
}

RuleAnalyzer::~RuleAnalyzer()
{
    
    delete this->atomRuleMap;
    delete this->ruleAtomMap;
    delete this->dg;
    delete this->sccs;
    delete this->sccs1;
    delete this->ruleGroups;
}

/**
 * @brief (head atom, rules)
 * 
 * @param rules 
 * @return map<string, vector<int>>* 
 */
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

/**
 * @brief rule head atom name
 * 
 * @param rules 
 * @return vector<string>* 
 */
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

        unordered_set<string> flag;
        for (auto atom : rule.body.atoms)
        {
            if (headRuleMap->find(atom.name) != headRuleMap->end())
            {
                if (flag.find(atom.name) == flag.end()) {
                    flag.insert(atom.name);
                    for (auto dependentRuleIndex : (*headRuleMap)[atom.name])
                    {
                        dg->dependency->at(i).emplace_back(dependentRuleIndex);
                    }
                }
            }
        }

        flag.clear();
        for (auto atom : rule.body.negations)
        {
            if (headRuleMap->find(atom.name) != headRuleMap->end())
            {
                if (flag.find(atom.name) == flag.end()) {
                    flag.insert(atom.name);
                    for (auto dependentRuleIndex : (*headRuleMap)[atom.name]) {
                        dg->dependency->at(i).emplace_back(dependentRuleIndex);
                        dg->negDependency->at(i).emplace_back(dependentRuleIndex);
                    }
                }
            }
        }
    }

    return dg;
}


//TODO: 是正确的strata顺序吗？
map<int, vector<int>> *RuleAnalyzer::computeRuleSccs(vector<vector<int>> *dependency) {
    vector<int> visitFlag(dependency->size(), 0);
    stack<int> dfsReversePostOrder;
    map<int, vector<int>> *sccs = new map<int, vector<int>>{};

    for (int rule = 0; rule < dependency->size(); rule++) {
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

    std::fill(visitFlag.begin(), visitFlag.end(), 0);
    while (!dfsReversePostOrder.empty())
    {
            auto rule = dfsReversePostOrder.top();
            dfsReversePostOrder.pop();
            this->assign(rule, rule, &transpose, &visitFlag, sccs);
    }

    return sccs;
}

vector<vector<int>> *RuleAnalyzer::computeRuleSccs1(vector<vector<int>> *dependency) {
    vector<int> visitFlag(dependency->size(), 0);
    stack<int> dfsReversePostOrder;
    int count = 0;
    vector<int> sccIds(dependency->size(), -1);

    for (int rule = 0; rule < dependency->size(); rule++) {
        this->visit(rule, dependency, &visitFlag, &dfsReversePostOrder);
    }

    vector<vector<int>> transpose{dependency->size(), vector<int>{}};
    for (int rule = 0; rule < dependency->size(); rule++) {
        for (auto dependentRule : dependency->at(rule)) {
            transpose[dependentRule].emplace_back(rule);
        }
    }

    std::fill(visitFlag.begin(), visitFlag.end(), 0);
    while (!dfsReversePostOrder.empty()) {
            auto rule = dfsReversePostOrder.top();
            dfsReversePostOrder.pop();
            if (!visitFlag[rule]) {
                this->assign(rule, count, &transpose, &visitFlag, &sccIds);
                count++;
            }
    }

    vector<vector<int>> *sccs = new vector<vector<int>>(count);
    int ruleIndex = 0;
    for (int sccId : sccIds) {
        sccs->at(sccId).emplace_back(ruleIndex);
        ruleIndex++;
    }

    return sccs;
}

void RuleAnalyzer::visit(int rule, vector<vector<int>> *dependency, vector<int> *visitFlag,
                         stack<int> *dfsReversePostOrder)
{
    if ((*visitFlag)[rule])
    {
        return;
    }
    (*visitFlag)[rule] = 1;
    for (auto dependentRule : dependency->at(rule))
    {
        visit(dependentRule, dependency, visitFlag, dfsReversePostOrder);
    }
    dfsReversePostOrder->push(rule);
}

void RuleAnalyzer::assign(int rule, int root, vector<vector<int>> *transpose, 
                          vector<int> *visitFlag, map<int, vector<int>> *sccs)
{
    if (visitFlag->at(rule)) {
        return;
    }
    (*visitFlag)[rule] = 1;
    if (sccs->find(root) == sccs->end()) {
        (*sccs)[root] = vector<int>();
        // sccs->at(root).emplace_back(root);
    }
    sccs->at(root).emplace_back(rule);

    for (auto reverseDependentRule : transpose->at(rule)) {
        assign(reverseDependentRule, root, transpose, visitFlag, sccs);
    }
}

void RuleAnalyzer::assign(int rule, int count, vector<vector<int>> *transpose,
            vector<int> *visitFlag, vector<int> *sccIds) {
    (*visitFlag)[rule] = 1;
    (*sccIds)[rule] = count;
    for (auto reverseDependentRule : transpose->at(rule)) {
        if (!visitFlag->at(reverseDependentRule)) {
            assign(reverseDependentRule, count, transpose, visitFlag, sccIds);
        }
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

bool RuleAnalyzer::checkNegationCycle1(vector<vector<int>> *sccs, vector<vector<int>> *negDependency) {
    bool negCycle{false};

    for (int sccIndex = 0; sccIndex < sccs->size(); sccIndex++) {
        vector<int> &scc = sccs->at(sccIndex);

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
            std::cout << "Negation cycle is detected in scc[" << sccIndex << "]" << endl;
        }
    }

    return negCycle;
}

bool RuleAnalyzer::isRecursiveScc(vector<int> *scc, vector<vector<int>> *dependency)
{
    if (scc->size() >= 2) {
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
    unordered_map<string, vector<int>> nonRecursiveGroup;

    for (auto it : *sccs) {
        int sccKey = it.first;
        vector<int> &scc = it.second;

        if (this->isRecursiveScc(&scc, dependency)) {
            groups->emplace_back(RuleGroup(scc, true));
        }
        else {
            string headName = ruleAtomMap->at(sccKey);
            if (nonRecursiveGroup.find(headName) == nonRecursiveGroup.end())
            {
                nonRecursiveGroup[headName] = scc;
            }
            else {
                nonRecursiveGroup[headName]
                    .insert(nonRecursiveGroup[headName].end(), scc.begin(), scc.end());
            }
        }
    }

    for (auto it : nonRecursiveGroup) {
        groups->emplace_back(RuleGroup(it.second, false));
    }

    std::reverse(groups->begin(), groups->end());

    return groups;
}

vector<RuleGroup> *RuleAnalyzer::groupRules1(vector<string> *ruleAtomMap, vector<vector<int>> *sccs, vector<vector<int>> *dependency) {
    vector<RuleGroup> *groups = new vector<RuleGroup>{};
    unordered_map<string, RuleGroup*> nonRecursiveGroup;

    for (auto scc : *sccs) {
        if (this->isRecursiveScc(&scc, dependency)) {
            groups->emplace_back(RuleGroup(scc, true));
        }
        else {
            string headName = ruleAtomMap->at(scc[0]);
            if (nonRecursiveGroup.find(headName) == nonRecursiveGroup.end()) {
                groups->emplace_back(RuleGroup(scc, false));
                nonRecursiveGroup[headName] = &groups->back();
            }
            else {
                nonRecursiveGroup[headName]
                    ->rules.insert(nonRecursiveGroup[headName]->rules.end(), scc.begin(), scc.end());
            }
        }
    }

    std::reverse(groups->begin(), groups->end());

    return groups;
}

void RuleAnalyzer::printDependencyGraph() {
    if (this->dg == nullptr) {
        return;
    }
    vector<vector<int>> *dependencies = this->dg->dependency;
    for (int i = 0; i < dependencies->size(); i++) {
        std::cout << "rule "
                  << i 
                  << ": ";
        vector<int>& dp = dependencies->at(i);
        for (auto it = dp.begin(); it != dp.end(); it++) {
            if (it != dp.begin()) {
                std::cout << ", ";
            }
            std::cout << *it;
        }
        std::cout << endl;
    }
}

void RuleAnalyzer::printSccs() {
    if (this->sccs == nullptr) {
        return;
    }
    std::cout << "Number of rule sccs: "
              << this->sccs->size() 
              << std::endl;
    int ruleIndex = 0;
    for (auto kv : *(this->sccs)) {
        std::cout << "rscc "
                  << ruleIndex
                  << ": "
                  << kv.first
                  << "-";
        for (auto it = kv.second.begin(); it != kv.second.end(); it++) {
            if (it != kv.second.begin()) {
                std::cout << ", ";
            }
            std::cout << *it;
        }
        std::cout << std::endl;
        ruleIndex++;
    }
}

void RuleAnalyzer::printSccs1() {
    if (this->sccs1 == nullptr) {
        return;
    }
    std::cout << "Number of rule sccs: "
              << this->sccs1->size() 
              << std::endl;

    for (int i = 0; i < this->sccs1->size(); i++) {
        auto scc = this->sccs1->at(i);
        std::cout << "rscc "
                  << i
                  << ": "
                  << scc[0]
                  << "-";
        for (auto it = scc.begin(); it != scc.end(); it++) {
            if (it != scc.begin()) {
                std::cout << ", ";
            }
            std::cout << *it;
        }
        std::cout << std::endl;
    }
}

void RuleAnalyzer::printRuleGroups() {
    if (this->ruleGroups == nullptr) {
        return;
    }

    int groupIndex = 0;
    for (RuleGroup &group : *(this->ruleGroups)) {
        std::cout << "Group "
                  << groupIndex
                  << ": ";
        vector<int> &rules = group.rules;
        for (auto it = rules.begin(); it != rules.end(); it++) {
            if (it != rules.begin()) {
                std::cout << ", ";
            }
            std::cout << *it;
        }
        std::cout << std::endl;
        groupIndex++;
    }
}

vector<RuleGroup> *RuleAnalyzer::getRuleGroups() {
    return this->ruleGroups;
}