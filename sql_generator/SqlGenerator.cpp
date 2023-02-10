
#include <sstream>
#include <map>
#include "SqlGenerator.h"


string SqlGenerator::generateRuleEval(RuleMap &rule, bool recursive) {
    map<string, map<int, int>> bodyVarIndex;
    // select_map
    // join_map
    // comparison_map
    // constant_constraint_map
    // negation_map
    // body_atom_alias
    // negation_atom_alias


    string select = this->generateSelection();
    string from = this->generateFrom();
    string where;
    string join = this->generateJoin();
    string groupBy = this->generateGroupBy();
    string insert = this->generateInsertion();

    ostringstream oss;
    oss << select
        << " "
        << from
        << " "
        << where
        << " "
        << groupBy;
    return oss.str();
}

string SqlGenerator::generateRulesEval(vector<RuleMap> &rules, bool recursive) {
    return "";
}

string SqlGenerator::generateInsertion() {
    return "";
}

string SqlGenerator::generateSelection() {
    return "";
}

string SqlGenerator::generateFrom() {
    return "";
}

string SqlGenerator::generateFromRecursive() {
    return "";
}

string SqlGenerator::generateJoin() {
    return "";
}

string SqlGenerator::generateComparision() {
    return "";
}

string SqlGenerator::generateConstantConstraint() {
    return "";
}

string SqlGenerator::generateNegation() {
    return "";
}

string SqlGenerator::generateGroupBy() {
    return "";
}

string SqlGenerator::generateIntersection() {
    return "";
}

string SqlGenerator::generateSetDiff() {
    return "";
}