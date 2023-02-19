#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

using namespace std;

struct Attribute
{
    Attribute() {

    }
    Attribute(string name, string type, bool isKey=false) : name{name}, type{type}, isKey{isKey}
    {
    }
    string name{""};
    string type{""};
    bool isKey{false};
};

struct MathMap
{
    MathMap() {}
    MathMap(string lhs, string op, string rhs) : lhs{lhs}, op{op}, rhs{rhs}
    {
    }
    string lhs;
    string op;
    string rhs;
};

struct AggArg
{
    AggArg() {}
    AggArg(string type, string attr) : type{type}, attr{attr} {
        
    };
    //TODO 可能需要修改
    AggArg(string type, MathMap mathExpr) : type{type}, mathExpr{mathExpr}
    {
    }

    bool isAttribute() {
        return type == AggArg::AGG_ARG_TYPE_ATTR;
    }

    bool isMath() {
        return type == AggArg::AGG_ARG_TYPE_MATH;
    }

    string type{""};
    string attr{""};
    MathMap mathExpr;
    static const string AGG_ARG_TYPE_ATTR;
    static const string AGG_ARG_TYPE_MATH;
};

struct AggMap
{
    AggMap() {}
    //TODO 可能需要修改
    AggMap(string aggOp, AggArg aggArg) : aggOp{aggOp}, aggArg{aggArg}
    {
    }
    string aggOp{""};
    AggArg aggArg;
};

struct CompareMap
{
    CompareMap() {}
    CompareMap(string lhsText, string lhsType, string op, string rhsText, string rhsType)
        : lhsText{lhsText}, lhsType{lhsType}, op{op}, rhsText{rhsText}, rhsType{rhsType} {}
    string lhsText;
    string lhsType;
    string op;
    string rhsText;
    string rhsType;
};

struct AssignMap
{
    AssignMap() {}
    //TODO 可能需要修改
    AssignMap(string lhs, MathMap rhs) : lhs{lhs}, rhs{rhs}
    {
    }
    string lhs;
    MathMap rhs;
};

struct AtomArg
{
    static const string ARG_TYPE_VAR;
    static const string ARG_TYPE_AGG;
    static const string ARG_TYPE_CONST;
    static const string ARG_TYPE_MATH;

    string name;
    string type;
    bool isKeyAttr{false};
    AggMap aggmap;
    MathMap mathmap;

    AtomArg() {}
    AtomArg(string name, string type, bool isKeyAttr = false) : name{name}, type{type}, isKeyAttr{isKeyAttr}
    {
    }
    AtomArg(AggMap aggmap, string type, bool isKeyAttr = false) : aggmap{aggmap}, type{type}, isKeyAttr{isKeyAttr}
    {
    }
    AtomArg(MathMap mathmap, string type, bool isKeyAttr = false) : mathmap{mathmap}, type{type}, isKeyAttr{isKeyAttr}
    {
    }

    bool isVar() {
        return type == AtomArg::ARG_TYPE_VAR;
    }

    bool isAgg() {
        return type == AtomArg::ARG_TYPE_AGG;
    }

    bool isConst() {
        return type == AtomArg::ARG_TYPE_CONST;
    }

    bool isMathExpr() {
        return type == AtomArg::ARG_TYPE_MATH;
    }
};
// const string AtomArg::ARG_TYPE_VAR = "variable";
// const string AtomArg::ARG_TYPE_AGG = "aggregation";
// const string AtomArg::ARG_TYPE_CONST = "constant";
// const string AtomArg::ARG_TYPE_MATH = "math_expr";

struct AtomMap
{
    AtomMap() {}
    AtomMap(string name, vector<AtomArg> args) : name{name}, argList{args} {

    }
    ~AtomMap() {
        argList.clear();
    }

    string name;
    vector<AtomArg> argList;
};

struct BodyMap
{
    // BodyMap() {}
    // BodyMap(vector<AtomMap> &atoms, vector<CompareMap> &compares,
    //     vector<AssignMap> &assigns, vector<AtomMap> &negations)
    //     : atoms{atoms}, compares{compares}, assigns{assigns}, negations{negations} {

    // }
    // ~BodyMap() {
    //     atoms.clear();
    //     compares.clear();
    //     assigns.clear();
    //     negations.clear();
    // }

    vector<AtomMap> atoms;
    vector<CompareMap> compares;
    vector<AssignMap> assigns;
    vector<AtomMap> negations;
};

struct RuleMap
{
    // RuleMap() {}
    // RuleMap(bool nonDedup, bool nonSetDiff, bool dedupOnly, AtomMap head, 
    // BodyMap body): nonDedup{nonDedup}, nonSetDiff{nonSetDiff}, dedupOnly{dedupOnly}, 
    // head{head}, body{body} {

    // }
    bool nonDedup;
    bool nonSetDiff;
    bool dedupOnly;
    AtomMap head;
    BodyMap body;
};

struct Schema
{
    // Schema() {}
    // Schema(string name, vector<AtomArg> &attributes) : name{name}, 
    // attributes{attributes} {

    // }
    // ~Schema() {
    //     attributes.clear();
    // }
    string name;
    // vector<AtomArg> attributes;
    vector<Attribute> attributes;
};