
#include <sstream>
#include <map>
#include <utility>

#include "SqlGenerator.h"


struct AggStruct {
    static const string TYPE_ATTR = "attribute";
    static const string TYPE_MATH_EXPR = "math_expr";

    string type;
    pair<int, int> attr;
    pair<int, int> lhs;
    pair<int, int> rhs;
    string mathOp;

    bool isAttr() {
        return type == TYPE_ATTR;
    }

    bool isMath() {
        return type == TYPE_MATH_EXPR;
    }
};

struct MathStruct {

};

struct HeadArgStruct {
    static const string TYPE_VAR = "variable";
    static const string TYPE_AGG = "aggregation";
    static const string TYPE_MATH_EXPR = "math_expr";
    static const string TYPE_CONST = "constant";

    string type;
    pair<int, int> var;
    AggStruct agg;
    MathStruct math;
    string constant;

    bool isVar() {
        return type == TYPE_VAR;
    }

    bool isAgg() {
        return type == TYPE_AGG;
    }

    bool isMath() {
        return type == TYPE_MATH_EXPR;
    }

    bool isConstant() {
        return type = TYPE_CONST;
    }
};
struct ComparisonStruct {

};


void extractVarBodyIndex(vector<AtomMap>& bodyAtoms, map<string, map<int, vector<int>>>& varBodyIndex);
void extractSelectionArgs(AtomMap& head, map<string, map<int, vector<int>>>& varBodyIndex, 
    map<int, HeadArgStruct>& headArgBodyIndex, vector<string>& headArgType, map<int, string>& headAggregation);
void extractJoinArgs(map<string, map<int, vector<int>>>& varBodyIndex, map<string, map<int, vector<int>>>& joinArgs);
void extractComparisonArgs(vector<CompareMap>& comparisons, map<string, map<int, vector<int>>>& varBodyIndex, 
    map<int, map<int, vector<ComparisonStruct>>>& comparisonArgs);
void extractConstantArgs(vector<AtomMap>& bodyAtoms, map<int, map<int, string>>& constantArgs);
void extractNegationArgs(vector<AtomMap>& bodyNegAtoms, map<string, map<int, vector<int>>>& varBodyIndex, 
    map<int, map<string, string>>& negArgs, map<int, map<int, pair<int, int>>>& antiJoinArgs);
void atomAlias(vector<AtomMap>& bodyAtoms, vector<string>& alias);


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
            int firstAtomPos = varBodyIndex[headArg.name].begin()->first;
            int firstArgPos = varBodyIndex[headArg.name].begin()->second[0];
            headArgBodyIndex[argIndex] = std::make_pair(firstAtomPos, firstArgPos); 
        } else if (headArg.type == "aggregation") {
            headArgType.emplace_back("agg");
            headAggregation[argIndex] = headArg.aggmap.aggOp;
            if (headArg.aggmap.aggArg.type == "attribute") {

            } else if (headArg.aggmap.aggArg.type == "math_expr") {

            }
        } else if (headArg.type == "math_expr") {

        } else if (headArg.type == "constant") {

        }
    }
}


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

void extractComparisonArgs(vector<CompareMap>& comparisons, 
    map<string, map<int, vector<int>>>& varBodyIndex, 
    map<int, map<int, vector<ComparisonStruct>>>& comparisonArgs) {
    //TODO 可能需要修正参数的顺序

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