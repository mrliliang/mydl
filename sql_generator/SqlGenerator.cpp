
#include <sstream>
#include <map>
#include <utility>
#include <string>

#include "SqlGenerator.h"

using namespace std;


const string AggStruct::TYPE_ATTR = "attribute";
const string AggStruct::TYPE_MATH_EXPR = "math_expr";

const string HeadArgStruct::TYPE_VAR = "variable";
const string HeadArgStruct::TYPE_AGG = "aggregation";
const string HeadArgStruct::TYPE_MATH_EXPR = "math_expr";
const string HeadArgStruct::TYPE_CONST = "constant";

const string ComparisonStruct::LSIDE = "l";
const string ComparisonStruct::RSIDE = "r";
const string ComparisonStruct::TYPE_VAR = "var";
const string ComparisonStruct::TYPE_NUM = "num";



string SqlGenerator::generateRuleEval(RuleMap &rule, bool recursive) {
    //var index
    map<string, map<int, vector<int>>> varBodyIndex;
    extractVarBodyIndex(rule.body.atoms, varBodyIndex);
    // select args
    map<int, HeadArgStruct> headArgBodyIndex;
    vector<string> headArgType;
    map<int, string> headAggregation;
    extractSelectionArgs(rule.head, varBodyIndex, headArgBodyIndex, headArgType, headAggregation);
    // join args
    map<string, map<int, vector<int>>> joinArgs;
    extractJoinArgs(varBodyIndex, joinArgs);
    // comparison args
    map<int, map<int, vector<ComparisonStruct>>> comparisonArgs;
    extractComparisonArgs(rule.body.compares, varBodyIndex, comparisonArgs);
    // constant args
    map<int, map<int, string>> constantArgs;
    extractConstantArgs(rule.body.atoms, constantArgs);
    // negation args
    map<int, map<string, string>> negArgs;
    map<int, map<int, pair<int, int>>> antiJoinArgs;
    extractNegationArgs(rule.body.negations, varBodyIndex, negArgs, antiJoinArgs);
    // body atom alias
    vector<string> bodyAtomAlias;
    atomAlias(rule.body.atoms, bodyAtomAlias);
    // negation atom alias
    vector<string> negAlias;
    negAtomAlias(rule.body.negations, negAlias);

    string select = this->generateSelection(rule.head, rule.body.atoms, headArgBodyIndex,
        headArgType, headAggregation, bodyAtomAlias);
    
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

string SqlGenerator::generateSelection(AtomMap& head, 
    vector<AtomMap>& bodyAtoms, 
    map<int, HeadArgStruct> headArgBodyIndex,
    vector<string>& headArgType, 
    map<int, string>& headAggregation, 
    vector<string>& bodyAtomAlias) {
    
    ostringstream oss;
    for (int argIndex = 0; argIndex < head.argList.size(); argIndex++) {
        oss.str("");

        AtomArg& arg = head.argList[argIndex];
        if (arg.isVar()) {
            bodyAtomIndex = headArgBodyIndex[argIndex].var.first;
            argIndexInAtom = headArgBodyIndex[argIndex].var.second;
            oss << bodyAtomAlias[bodyAtomIndex]
                << ".";
        } else if (arg.isAgg()) {

        } else if (arg.isMathExpr()) {
            
        } else if (arg.isConst()) {

        }
    }


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


/**
 * @brief 计算每个var在哪个atom的哪些位置
 * 
 * @param bodyAtoms 
 * @param varBodyIndex 
 */
void extractVarBodyIndex(vector<AtomMap>& bodyAtoms, 
    map<string, map<int, vector<int>>>& varBodyIndex) {
    //TODO 可能需要修正参数的顺序
    for (int atomIndex = 0; atomIndex < bodyAtoms.size(); atomIndex++) {
        AtomMap& atom = bodyAtoms[atomIndex];
        for (int argIndex = 0; argIndex < atom.argList.size(); argIndex++) {
            AtomArg& arg = atom.argList[argIndex];
            if (arg.type != "variable") {
                continue;
            }
            if (varBodyIndex.find(arg.name) == varBodyIndex.end()) {
                varBodyIndex[arg.name] = map<int, vector<int>>();
            }
            if (varBodyIndex[arg.name].find(atomIndex) == varBodyIndex[arg.name].end()) {
                varBodyIndex[arg.name][atomIndex] = vector<int>();
            }
            varBodyIndex[arg.name][atomIndex].emplace_back(argIndex);
        }
    }
}


void extractSelectionArgs(AtomMap& head,
    map<string, map<int, vector<int>>>& varBodyIndex, 
    map<int, HeadArgStruct>& headArgBodyIndex, 
    vector<string>& headArgType, 
    map<int, string>& headAggregation) {
    for (int argIndex = 0; argIndex < head.argList.size(); argIndex++) {
        AtomArg& headArg = head.argList[argIndex];
        if (headArg.type == "variable") {
            headArgType.emplace_back("var");
            headArgBodyIndex[argIndex].type = HeadArgStruct::TYPE_VAR;
            int firstAtomPos = varBodyIndex[headArg.name].begin()->first;
            int firstArgPos = varBodyIndex[headArg.name].begin()->second[0];
            headArgBodyIndex[argIndex].var = std::make_pair(firstAtomPos, firstArgPos); 
        } else if (headArg.type == "aggregation") {
            headArgType.emplace_back("agg");
            headArgBodyIndex[argIndex].type = HeadArgStruct::TYPE_AGG;
            headAggregation[argIndex] = headArg.aggmap.aggOp;
            if (headArg.aggmap.aggArg.type == "attribute") {
                headArgBodyIndex[argIndex].agg.type = AggStruct::TYPE_ATTR;
                int firstAtomPos = varBodyIndex[headArg.aggmap.aggArg.attr].begin()->first;
                int firstArgPos = varBodyIndex[headArg.aggmap.aggArg.attr].begin()->second[0];
                headArgBodyIndex[argIndex].agg.attr = std::make_pair(firstAtomPos, firstArgPos);
            } else if (headArg.aggmap.aggArg.type == "math_expr") {
                headArgBodyIndex[argIndex].agg.type = AggStruct::TYPE_MATH_EXPR;
                int lhsFirstAtomPos = varBodyIndex[headArg.aggmap.aggArg.mathExpr.lhs].begin()->first;
                int lhsFirstArgPos = varBodyIndex[headArg.aggmap.aggArg.mathExpr.lhs].begin()->second[0];
                headArgBodyIndex[argIndex].agg.lhs = std::make_pair(lhsFirstAtomPos, lhsFirstArgPos);
                int rhsFirstAtomPos = varBodyIndex[headArg.aggmap.aggArg.mathExpr.rhs].begin()->first;
                int rhsFirstArgPos = varBodyIndex[headArg.aggmap.aggArg.mathExpr.rhs].begin()->second[0];
                headArgBodyIndex[argIndex].agg.rhs = std::make_pair(rhsFirstAtomPos, rhsFirstArgPos);
                headArgBodyIndex[argIndex].agg.mathOp = headArg.aggmap.aggArg.mathExpr.op;
            }
        } else if (headArg.type == "math_expr") {
            headArgType.emplace_back("math_expr");
            headArgBodyIndex[argIndex].type = HeadArgStruct::TYPE_MATH_EXPR;
            int lhsFirstAtomPos = varBodyIndex[headArg.mathmap.lhs].begin()->first;
            int lhsFirstArgPos = varBodyIndex[headArg.mathmap.lhs].begin()->second[0];
            headArgBodyIndex[argIndex].math.lhs = std::make_pair(lhsFirstAtomPos, lhsFirstArgPos);
            int rhsFirstAtomPos = varBodyIndex[headArg.mathmap.rhs].begin()->first;
            int rhsFirstArgPos = varBodyIndex[headArg.mathmap.rhs].begin()->second[0];
            headArgBodyIndex[argIndex].math.rhs = std::make_pair(rhsFirstAtomPos, rhsFirstArgPos);
            headArgBodyIndex[argIndex].math.mathOp = headArg.mathmap.op;
        } else if (headArg.type == "constant") {
            headArgType.emplace_back("constant");
            headArgBodyIndex[argIndex].type = HeadArgStruct::TYPE_CONST;
            headArgBodyIndex[argIndex].constant = headArg.name;
        }
    }
}


/**
 * @brief 计算一个atom的哪个变量需要与其他atom的哪个变量连接
 * 
 * @param varBodyIndex 
 * @param joinArgs 
 */
void extractJoinArgs(map<string, map<int, vector<int>>>& varBodyIndex, map<string, map<int, vector<int>>>& joinArgs) {
    //TODO 可能需要修正参数的顺序
    for (auto varIt = varBodyIndex.begin(); varIt != varBodyIndex.end(); varIt++) {
        const string& var = varIt->first;
        bool join{false};
        if (varIt->second.size() > 1) {
            join = true;
        }
        for (auto atomIt = varIt->second.begin(); atomIt != varIt->second.end(); atomIt++) {
            if (atomIt->second.size() > 1) {
                join = true;
                break;
            }
        }
        if (join) {
            joinArgs[var] = varIt->second;
        }
    }
}

/**
 * @brief 计算哪个atom的哪个变量需要与其他atom的哪些变量或常量比较
 * 
 * @param comparisons 
 * @param varBodyIndex 
 * @param comparisonArgs 
 */
void extractComparisonArgs(vector<CompareMap>& comparisons, 
    map<string, map<int, vector<int>>>& varBodyIndex, 
    map<int, map<int, vector<ComparisonStruct>>>& comparisonArgs) {
    //TODO 可能需要修正参数的顺序
    for (CompareMap& cmp : comparisons) {
        ComparisonStruct cs;
        cs.compareOp = cmp.op;

        string cmpArg;
        string cmpArgType;
        string baseVar;
        if (cmp.lhsType == "var") {
            cs.baseVarSide = ComparisonStruct::LSIDE;
            baseVar = cmp.lhsText;
            cmpArg = cmp.rhsText;
            cmpArgType = cmp.rhsType;
        } else {
            cs.baseVarSide = ComparisonStruct::RSIDE;
            baseVar = cmp.rhsText;
            cmpArg = cmp.lhsText;
            cmpArgType = cmp.lhsType;
        }

        if (cmpArgType == "num") {
            cs.otherSideType = ComparisonStruct::TYPE_NUM;
            cs.numVal = stof(cmpArg);
        } else {
            int otherSideFirstAtomIndex = varBodyIndex[cmpArg].begin()->first;
            int otherSideFirstArgIndex = varBodyIndex[cmpArg].begin()->second[0];
            cs.otherSideType = ComparisonStruct::TYPE_VAR;
            cs.otherSideAtomIndex = otherSideFirstAtomIndex;
            cs.otherSideArgIndex = otherSideFirstAtomIndex;
        }

        int baseSideFirstAtomIndex = varBodyIndex[baseVar].begin()->first;
        int baseSideFirstArgIndex = varBodyIndex[baseVar].begin()->second[0];
        comparisonArgs[baseSideFirstAtomIndex][baseSideFirstArgIndex].emplace_back(cs);
    }
}


/**
 * @brief 计算哪些atom的哪些位置的参数是常量
 * 
 * @param bodyAtoms 
 * @param constantArgs 
 */
void extractConstantArgs(vector<AtomMap>& bodyAtoms, map<int, map<int, string>>& constantArgs) {
    //TODO 可能需要修正参数的顺序
    for (int atomIndex = 0; atomIndex < bodyAtoms.size(); atomIndex++) {
        AtomMap& atom = bodyAtoms[atomIndex];
        for (int argIndex = 0; argIndex < atom.argList.size(); argIndex++) {
            AtomArg& arg = atom.argList[argIndex];
            if (arg.type != "constant") {
                continue;
            }
            if (constantArgs.find(atomIndex) == constantArgs.end()) {
                constantArgs[atomIndex] = map<int, string>{};
            }
            constantArgs[atomIndex][argIndex] = arg.name;
        }
    }
}


/**
 * @brief 计算否定atom中的变量出现在哪些atom中
 * 
 * @param bodyAtoms 
 * @param varBodyIndex 
 * @param negArgs 
 * @param antiJoinArgs 
 */
void extractNegationArgs(vector<AtomMap>& bodyNegAtoms, 
    map<string, map<int, vector<int>>>& varBodyIndex, 
    map<int, map<string, string>>& negArgs, 
    map<int, map<int, pair<int, int>>>& antiJoinArgs) {
    for (int negIndex = 0; negIndex < bodyNegAtoms.size(); negIndex++) {
        AtomMap& neg = bodyNegAtoms[negIndex];
        for (int argIndex = 0; argIndex < neg.argList.size(); argIndex++) {
            AtomArg& negArg = neg.argList[argIndex];
            //TODO negArgs好像没有必要
        }
    }

    for (int negIndex = 0; negIndex < bodyNegAtoms.size(); negIndex++) {
        AtomMap& neg = bodyNegAtoms[negIndex];
        for (int argIndex = 0; argIndex < neg.argList.size(); argIndex++) {
            AtomArg& negArg = neg.argList[argIndex];
            if (negArg.type != "variable") {
                continue;
            }
            map<int, vector<int>>& atomIndexToArgIndex = varBodyIndex[negArg.name];
            int firstAtomPos = atomIndexToArgIndex.begin()->first;
            int firstArgPos = atomIndexToArgIndex.begin()->second[0];
            if (antiJoinArgs.find(negIndex) == antiJoinArgs.end()) {
                antiJoinArgs[negIndex] = map<int, pair<int, int>>{};
            }
            antiJoinArgs[negIndex][argIndex] = std::make_pair(firstAtomPos, firstArgPos);
        }
    }
}


void atomAlias(vector<AtomMap>& bodyAtoms, vector<string>& alias) {
    ostringstream oss;
    for (int atomIndex = 0; atomIndex < bodyAtoms.size(); atomIndex++) {
        oss.str("");
        oss << bodyAtoms[atomIndex].name[0]
            << "_"
            << atomIndex;
        alias.emplace_back(oss.str());
    }
}

void negAtomAlias(vector<AtomMap>& negAtoms, vector<string>& negAlias) {
    ostringstream oss;
    for (int atomIndex = 0; atomIndex < negAtoms.size(); atomIndex++) {
        oss.str("");
        oss << "neg_"
            << negAtoms[atomIndex].name[0]
            << "_"
            << atomIndex;
        negAlias.emplace_back(oss.str());
    }
}