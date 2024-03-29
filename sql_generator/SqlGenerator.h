#pragma once

#include <string>

#include "../parser/basetype.h"
#include "../parser/DatalogProgram.h"

using namespace std;

struct AggStruct {
    static const string TYPE_ATTR;
    static const string TYPE_MATH_EXPR;

    string type;
    pair<int, int> attr;
    pair<int, int> lhs;
    pair<int, int> rhs;
    string mathOp;

    bool isAttr() {
        return type == AggStruct::TYPE_ATTR;
    }

    bool isMath() {
        return type == AggStruct::TYPE_MATH_EXPR;
    }
};
// const string AggStruct::TYPE_ATTR = "attribute";
// const string AggStruct::TYPE_MATH_EXPR = "math_expr";

struct MathStruct {
    pair<int, int> lhs;
    pair<int, int> rhs;
    string mathOp;
};

struct HeadArgStruct {
    static const string TYPE_VAR;
    static const string TYPE_AGG;
    static const string TYPE_MATH_EXPR;
    static const string TYPE_CONST;

    string type;
    pair<int, int> var;
    AggStruct agg;
    MathStruct math;
    string constant;

    bool isVar() {
        return type == HeadArgStruct::TYPE_VAR;
    }

    bool isAgg() {
        return type == HeadArgStruct::TYPE_AGG;
    }

    bool isMath() {
        return type == HeadArgStruct::TYPE_MATH_EXPR;
    }

    bool isConstant() {
        return type == HeadArgStruct::TYPE_CONST;
    }
};
// const string HeadArgStruct::TYPE_VAR = "variable";
// const string HeadArgStruct::TYPE_AGG = "aggregation";
// const string HeadArgStruct::TYPE_MATH_EXPR = "math_expr";
// const string HeadArgStruct::TYPE_CONST = "constant";


struct ComparisonStruct {
    static const string LSIDE;
    static const string RSIDE;
    static const string TYPE_VAR;
    static const string TYPE_NUM;

    string baseVar;
    string baseVarType;
    string baseVarSide;
    string compareOp;
    string otherSideType;
    float numVal;
    int otherSideAtomIndex;
    int otherSideArgIndex;
};
// const string ComparisonStruct::LSIDE = "l";
// const string ComparisonStruct::RSIDE = "r";
// const string ComparisonStruct::TYPE_VAR = "var";
// const string ComparisonStruct::TYPE_NUM = "num";


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
void negAtomAlias(vector<AtomMap>& negAtoms, vector<string>& negAlias);
void deltaBodyGroups(vector<AtomMap>& bodyAtoms, 
    map<string, vector<RuleMap*>>& recursiveRuleGroups,
    int iterateNum, 
    vector<vector<string>>& deltaGroups);

class SqlGenerator {
    public:
        string generateRuleEval(RuleMap &rule, DatalogProgram& pg);
        string generateRulesEval(vector<RuleMap> &rules, bool recursive, DatalogProgram& pg);
        vector<string> generateRecursiveRuleEval(RuleMap& rule, 
            map<string, vector<RuleMap*>>& recursiveRuleGroups,
            int iterateNum, 
            DatalogProgram& pg);

        string generateInsertion(string relation, string query);
        string generateSelection(AtomMap& head, 
            vector<AtomMap>& bodyAtoms, 
            map<int, HeadArgStruct> headArgBodyIndex,
            vector<string>& headArgType, 
            map<int, string>& headAggregation, 
            vector<string>& bodyAtomAlias,
            DatalogProgram& pg);
        string generateFrom(vector<AtomMap>& bodyAtoms, vector<string>& bodyAtomAlias);
        vector<string> generateFromRecursive(vector<vector<string>>& deltaBodyGroups, 
            vector<string>& bodyAtomAlias);
        string generateJoin(vector<AtomMap>& bodyAtoms, 
            map<string, map<int, vector<int>>>& joinArgs, 
            vector<string>& bodyAtomAlias,
            DatalogProgram& pg);
        string generateComparision(vector<AtomMap>& bodyAtoms, 
            map<int, map<int, vector<ComparisonStruct>>> comparisonArgs,
            vector<string>& bodyAtomAlias, 
            DatalogProgram& pg);
        string generateConstantConstraint(vector<AtomMap>& bodyAtoms,
            map<int, map<int, string>>& constantArgs,
            vector<string>& bodyAtomAlias,
            DatalogProgram& pg);
        string generateNegation(vector<AtomMap>& bodyAtoms, 
            vector<AtomMap>& negAtoms, 
            map<int, map<int, pair<int, int>>>& antiJoinArgs,
            vector<string>& bodyAtomAlias,
            vector<string>& negAtomAlias,
            DatalogProgram& pg);
        string generateGroupBy(AtomMap& head, DatalogProgram& pg);
        string generateIntersection(string tmpIdbDelta, 
            string idb, 
            Schema& relation, 
            map<int, string>& headAggregation);
        string generateSetDiff(string tmpIdbDelta, 
            string idb, 
            string idbDelta, 
            Schema& relation, 
            map<int, string>& headAggregation);
        string generateDrop(string tableName);
        string generateCreate(Schema& relation, string tableName);

        static const string BACK_QUOTE;
};