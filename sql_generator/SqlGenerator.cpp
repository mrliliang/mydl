
#include <sstream>
#include <map>
#include <utility>
#include <string>
#include <cmath>

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

const string SqlGenerator::BACK_QUOTE = "`";



string SqlGenerator::generateRuleEval(RuleMap &rule, DatalogProgram& pg) {
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
        headArgType, headAggregation, bodyAtomAlias, pg);
    
    string from = this->generateFrom(rule.body.atoms, bodyAtomAlias);
    string join = this->generateJoin(rule.body.atoms, joinArgs, bodyAtomAlias, pg);
    string compare = this->generateComparision(rule.body.atoms, comparisonArgs, bodyAtomAlias, pg);
    string constantConstraint = this->generateConstantConstraint(rule.body.atoms, constantArgs, 
        bodyAtomAlias, pg);
    string negation = this->generateNegation(rule.body.atoms, rule.body.negations, antiJoinArgs, 
        bodyAtomAlias, negAlias, pg);
    string groupBy = this->generateGroupBy(rule.head, pg);

    string where;
    if (join.size() > 0) {
        if (where.size() > 0) {
            where.append(" AND ");
        }
        where.append(join);
    }
    if (compare.size() > 0) {
        if (where.size() > 0) {
            where.append(" AND ");
        }
        where.append(compare);
    }
    if (constantConstraint.size() > 0) {
        if (where.size() > 0) {
            where.append(" AND ");
        }
        where.append(constantConstraint);
    }
    if (negation.size() > 0) {
        if (where.size() > 0) {
            where.append(" AND ");
        }
        where.append(negation);
    }
    if (where.size() > 0) {
        where = "WHERE" + where;
    }

    ostringstream oss;
    oss << select
        << " "
        << from;
    if (where.size() > 0) {
        oss << " "
            << where;
    }
    if (groupBy.size() > 0) {
        oss << " "
            << groupBy;
    }

    return oss.str();

    // string insert = this->generateInsertion(rule.head.name, oss.str());
    // return insert;
}

string SqlGenerator::generateRulesEval(vector<RuleMap> &rules, bool recursive, DatalogProgram& pg) {
    return "";
}


vector<string> SqlGenerator::generateRecursiveRuleEval(RuleMap& rule, 
    map<string, vector<RuleMap*>>& recursiveRuleGroups, 
    int iterateNum, 
    DatalogProgram& pg) {
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

    //TODO: enumerate the bodies of delta rules
    vector<vector<string>> deltaGroups;
    deltaBodyGroups(rule.body.atoms, recursiveRuleGroups, iterateNum, deltaGroups);

    string select = this->generateSelection(rule.head, rule.body.atoms, headArgBodyIndex,
        headArgType, headAggregation, bodyAtomAlias, pg);
    
    //TODO: generate from clauses of delta rules
    vector<string> fromStrs = this->generateFromRecursive(deltaGroups, bodyAtomAlias);

    string join = this->generateJoin(rule.body.atoms, joinArgs, bodyAtomAlias, pg);
    string compare = this->generateComparision(rule.body.atoms, comparisonArgs, bodyAtomAlias, pg);
    string constantConstraint = this->generateConstantConstraint(rule.body.atoms, constantArgs, 
        bodyAtomAlias, pg);
    string negation = this->generateNegation(rule.body.atoms, rule.body.negations, antiJoinArgs, 
        bodyAtomAlias, negAlias, pg);
    string groupBy = this->generateGroupBy(rule.head, pg);

    string where;
    if (join.size() > 0) {
        if (where.size() > 0) {
            where.append(" AND ");
        }
        where.append(join);
    }
    if (compare.size() > 0) {
        if (where.size() > 0) {
            where.append(" AND ");
        }
        where.append(compare);
    }
    if (constantConstraint.size() > 0) {
        if (where.size() > 0) {
            where.append(" AND ");
        }
        where.append(constantConstraint);
    }
    if (negation.size() > 0) {
        if (where.size() > 0) {
            where.append(" AND ");
        }
        where.append(negation);
    }
    if (where.size() > 0) {
        where = "WHERE" + where;
    }

    vector<string> subQueries;
    for (auto from : fromStrs) {
        ostringstream oss;
        oss << select
            << " "
            << from;
        if (where.size() > 0) {
            oss << " "
                << where;
        }
        if (groupBy.size() > 0) {
            oss << " "
                << groupBy;
        }
        subQueries.emplace_back(oss.str());
    }

    return subQueries;
}

string SqlGenerator::generateInsertion(string relation, string query) {
    ostringstream oss;
    oss << "INSERT INTO "
        << SqlGenerator::BACK_QUOTE
        << relation
        << SqlGenerator::BACK_QUOTE
        << " "
        << query;
    return oss.str();
}

string SqlGenerator::generateSelection(AtomMap& head, 
    vector<AtomMap>& bodyAtoms, 
    map<int, HeadArgStruct> headArgBodyIndex,
    vector<string>& headArgType, 
    map<int, string>& headAggregation, 
    vector<string>& bodyAtomAlias,
    DatalogProgram& pg) {
    
    ostringstream oss;
    oss << "SELECT ";
    for (int argIndex = 0; argIndex < head.argList.size(); argIndex++) {
        if (argIndex != 0) {
            oss << ", ";
        }

        AtomArg& arg = head.argList[argIndex];
        if (arg.isVar()) {
            int bodyAtomIndex = headArgBodyIndex[argIndex].var.first;
            int argIndexInAtom = headArgBodyIndex[argIndex].var.second;
            oss << SqlGenerator::BACK_QUOTE
                << bodyAtomAlias[bodyAtomIndex]
                << SqlGenerator::BACK_QUOTE
                << "."
                << SqlGenerator::BACK_QUOTE
                << pg.getRelation(bodyAtoms[bodyAtomIndex].name).attributes[argIndexInAtom].name
                << SqlGenerator::BACK_QUOTE;
        } else if (arg.isAgg()) {
            if (arg.aggmap.aggOp == "COUNT_DISTINCT") {
                oss << "COUNT(DISTINCT ";
            } else {
                oss << arg.aggmap.aggOp
                    << "(";
            }
            if (arg.aggmap.aggArg.isAttribute()) {
                int bodyAtomIndex = headArgBodyIndex[argIndex].agg.attr.first;
                int argIndexInAtom = headArgBodyIndex[argIndex].agg.attr.second;
                oss << SqlGenerator::BACK_QUOTE
                    << bodyAtomAlias[bodyAtomIndex]
                    << SqlGenerator::BACK_QUOTE
                    << "."
                    << SqlGenerator::BACK_QUOTE
                    << pg.getRelation(bodyAtoms[bodyAtomIndex].name).attributes[argIndexInAtom].name
                    << SqlGenerator::BACK_QUOTE;
            } else if (arg.aggmap.aggArg.isMath()) {
                int lhsBodyAtomIndex = headArgBodyIndex[argIndex].agg.lhs.first;
                int lhsArgIndexInAtom = headArgBodyIndex[argIndex].agg.lhs.second;
                oss << SqlGenerator::BACK_QUOTE
                    << bodyAtomAlias[lhsBodyAtomIndex]
                    << SqlGenerator::BACK_QUOTE
                    << "."
                    << SqlGenerator::BACK_QUOTE
                    << pg.getRelation(bodyAtoms[lhsBodyAtomIndex].name).attributes[lhsArgIndexInAtom].name
                    << SqlGenerator::BACK_QUOTE;
                
                oss << " "
                    << headArgBodyIndex[argIndex].agg.mathOp
                    << " ";

                int rhsBodyAtomIndex = headArgBodyIndex[argIndex].agg.rhs.first;
                int rhsArgIndexInAtom = headArgBodyIndex[argIndex].agg.rhs.second;
                oss << SqlGenerator::BACK_QUOTE
                    << bodyAtomAlias[rhsBodyAtomIndex]
                    << SqlGenerator::BACK_QUOTE
                    << "."
                    << SqlGenerator::BACK_QUOTE
                    << pg.getRelation(bodyAtoms[rhsBodyAtomIndex].name).attributes[rhsArgIndexInAtom].name
                    << SqlGenerator::BACK_QUOTE;
            }
            oss << ")";
        } else if (arg.isMathExpr()) {
            int lhsBodyAtomIndex = headArgBodyIndex[argIndex].math.lhs.first;
            int lhsArgIndexInAtom = headArgBodyIndex[argIndex].math.lhs.second;
            oss << SqlGenerator::BACK_QUOTE
                << bodyAtomAlias[lhsBodyAtomIndex]
                << SqlGenerator::BACK_QUOTE
                << "."
                << SqlGenerator::BACK_QUOTE
                << pg.getRelation(bodyAtoms[lhsBodyAtomIndex].name).attributes[lhsArgIndexInAtom].name
                << SqlGenerator::BACK_QUOTE;

            oss << " "
                << headArgBodyIndex[argIndex].math.mathOp
                << " ";

            int rhsBodyAtomIndex = headArgBodyIndex[argIndex].math.rhs.first;
            int rhsArgIndexInAtom = headArgBodyIndex[argIndex].math.rhs.second;
            oss << SqlGenerator::BACK_QUOTE
                << bodyAtomAlias[rhsBodyAtomIndex]
                << SqlGenerator::BACK_QUOTE
                << "."
                << SqlGenerator::BACK_QUOTE
                << pg.getRelation(bodyAtoms[rhsBodyAtomIndex].name).attributes[rhsArgIndexInAtom].name
                << SqlGenerator::BACK_QUOTE;
        } else if (arg.isConst()) {
            oss << headArgBodyIndex[argIndex].constant;
        }

        oss << " AS "
            << SqlGenerator::BACK_QUOTE
            << pg.getRelation(head.name).attributes[argIndex].name
            << SqlGenerator::BACK_QUOTE;
    }

    return oss.str();
}

string SqlGenerator::generateFrom(vector<AtomMap>& bodyAtoms, vector<string>& bodyAtomAlias) {
    ostringstream oss;
    oss << "FROM ";
    for (int i = 0; i < bodyAtoms.size(); i++) {
        if (i != 0) {
            oss << ", ";
        }
        oss << SqlGenerator::BACK_QUOTE
            << bodyAtoms[i].name
            << SqlGenerator::BACK_QUOTE
            << " "
            << SqlGenerator::BACK_QUOTE
            << bodyAtomAlias[i]
            << SqlGenerator::BACK_QUOTE;
    }
    return oss.str();
}

vector<string> SqlGenerator::generateFromRecursive(vector<vector<string>>& deltaBodyGroups, 
        vector<string>& bodyAtomAlias) {
    //TODO: generate from clauses of delta rules, to be completed.
    vector<string> fromStrs;
    for (auto& group : deltaBodyGroups) {
        ostringstream oss;
        oss << "FROM ";
        for (int atomIndex = 0; atomIndex < bodyAtomAlias.size(); atomIndex++) {
            if (atomIndex != 0) {
                oss << ", ";
            }
            oss << SqlGenerator::BACK_QUOTE
                << group[atomIndex]
                << SqlGenerator::BACK_QUOTE
                << " "
                << SqlGenerator::BACK_QUOTE
                << bodyAtomAlias[atomIndex]
                << SqlGenerator::BACK_QUOTE;
        }
        fromStrs.emplace_back(oss.str());
    }
    return fromStrs;
}


string SqlGenerator::generateJoin(vector<AtomMap>& bodyAtoms, 
    map<string, map<int, vector<int>>>& joinArgs, 
    vector<string>& bodyAtomAlias,
    DatalogProgram& pg) {

    vector<string> equalStrs;
    for (auto& argIt : joinArgs) {
        string lastArg;
        string argName = argIt.first;
        for (auto atomIt : argIt.second) {
            int atomIndex = atomIt.first;
            AtomMap& atom = bodyAtoms[atomIndex];
            Schema& relation = pg.getRelation(atom.name);
            for (auto joinArgIndex : atomIt.second) {
                string equalStr;
                string currentArg = SqlGenerator::BACK_QUOTE 
                    + bodyAtomAlias[atomIndex]
                    + SqlGenerator::BACK_QUOTE 
                    + "." 
                    + SqlGenerator::BACK_QUOTE
                    + relation.attributes[joinArgIndex].name
                    + SqlGenerator::BACK_QUOTE;
                if (lastArg.size() > 0) {
                    equalStr = lastArg + " = " + currentArg;
                    equalStrs.emplace_back(equalStr);
                }
                lastArg = currentArg;
            }
        }
    }

    ostringstream oss;
    for (int i = 0; i < equalStrs.size(); i++) {
        if (i != 0) {
            oss << " AND ";
        }
        oss << equalStrs[i];
    }
    return oss.str();
}

string SqlGenerator::generateComparision(vector<AtomMap>& bodyAtoms, 
    map<int, map<int, vector<ComparisonStruct>>> comparisonArgs,
    vector<string>& bodyAtomAlias, 
    DatalogProgram& pg) {

    vector<string> comparisonItems;
    for (auto& atomIt : comparisonArgs) {
        int atomIndex = atomIt.first;
        string atomName = bodyAtoms[atomIndex].name;
        string atomAlias = bodyAtomAlias[atomIndex];
        for (auto& argIt : atomIt.second) {
            int argIndex = argIt.first;
            string attr = pg.getRelation(atomName).attributes[argIndex].name;
            for (auto& cmp : argIt.second) {
                ostringstream oss;
                if (cmp.otherSideType == ComparisonStruct::TYPE_NUM) {
                    if (cmp.baseVarSide == ComparisonStruct::LSIDE) {
                        oss << SqlGenerator::BACK_QUOTE
                            << atomAlias
                            << SqlGenerator::BACK_QUOTE
                            << "."
                            << SqlGenerator::BACK_QUOTE
                            << attr
                            << SqlGenerator::BACK_QUOTE
                            << " "
                            << cmp.compareOp
                            << " "
                            << cmp.numVal;
                    } else {
                        oss << cmp.numVal
                            << " "
                            << cmp.compareOp
                            << " "
                            << SqlGenerator::BACK_QUOTE
                            << atomAlias
                            << SqlGenerator::BACK_QUOTE
                            << "."
                            << SqlGenerator::BACK_QUOTE
                            << attr
                            << SqlGenerator::BACK_QUOTE;
                    }
                } else if (cmp.otherSideType == ComparisonStruct::TYPE_VAR) {
                    string otherAtomAlias = bodyAtomAlias[cmp.otherSideAtomIndex];
                    string otherAttr = pg.getRelation(bodyAtoms[cmp.otherSideAtomIndex].name)
                        .attributes[cmp.otherSideArgIndex].name;
                    if (cmp.baseVarSide == ComparisonStruct::RSIDE) {
                        oss << SqlGenerator::BACK_QUOTE
                            << atomAlias
                            << SqlGenerator::BACK_QUOTE
                            << "."
                            << SqlGenerator::BACK_QUOTE
                            << attr
                            << SqlGenerator::BACK_QUOTE
                            << " "
                            << cmp.compareOp
                            << " "
                            << SqlGenerator::BACK_QUOTE
                            << otherAtomAlias
                            << SqlGenerator::BACK_QUOTE
                            << "."
                            << SqlGenerator::BACK_QUOTE
                            << otherAttr
                            << SqlGenerator::BACK_QUOTE;
                    } else {
                        oss << SqlGenerator::BACK_QUOTE
                            << otherAtomAlias
                            << SqlGenerator::BACK_QUOTE
                            << "."
                            << SqlGenerator::BACK_QUOTE
                            << otherAttr
                            << SqlGenerator::BACK_QUOTE
                            << " "
                            << cmp.compareOp
                            << " "
                            << SqlGenerator::BACK_QUOTE
                            << atomAlias
                            << SqlGenerator::BACK_QUOTE
                            << "."
                            << SqlGenerator::BACK_QUOTE
                            << attr
                            << SqlGenerator::BACK_QUOTE;
                    }
                }
                comparisonItems.emplace_back(oss.str());
            }
        }
    }

    ostringstream oss;
    for (auto it = comparisonItems.begin(); it != comparisonItems.end(); it++) {
        if (it != comparisonItems.begin()) {
            oss << " AND ";
        }
        oss << *it;
    }

    return oss.str();
}

string SqlGenerator::generateConstantConstraint(vector<AtomMap>& bodyAtoms,
    map<int, map<int, string>>& constantArgs,
    vector<string>& bodyAtomAlias,
    DatalogProgram& pg) {
    
    vector<string> constantStrs;
    for (auto& atomIt : constantArgs) {
        int atomIndex = atomIt.first;
        string atomName = bodyAtoms[atomIndex].name;
        string atomAlias = bodyAtomAlias[atomIt.first];
        for (auto& argIt : atomIt.second) {
            ostringstream oss;
            int argIndex = argIt.first;
            Attribute& attr = pg.getRelation(atomName).attributes[argIndex]; 
            oss << SqlGenerator::BACK_QUOTE
                << atomAlias
                << SqlGenerator::BACK_QUOTE
                << "."
                << SqlGenerator::BACK_QUOTE
                << attr.name
                << SqlGenerator::BACK_QUOTE
                << " = ";
            string constant = argIt.second;
            if (attr.isNumeric()) {
                oss << constant;
            } else {
                oss << "'"
                    << constant
                    << "'";
            }
            constantStrs.emplace_back(oss.str());
        }
    }

    ostringstream oss;
    for (auto it = constantStrs.begin(); it != constantStrs.end(); it++) {
        if (it != constantStrs.begin()) {
            oss << " AND ";
        }
        oss << *it;
    }
    return oss.str();
}

string SqlGenerator::generateNegation(vector<AtomMap>& bodyAtoms, 
    vector<AtomMap>& negAtoms, 
    map<int, map<int, pair<int, int>>>& antiJoinArgs,
    vector<string>& bodyAtomAlias,
    vector<string>& negAtomAlias,
    DatalogProgram& pg) {
    
    vector<string> negStrs;
    for (int negIndex = 0; negIndex < negAtoms.size(); negIndex++) {
        AtomMap& negAtom = negAtoms[negIndex];
        Schema& relation = pg.getRelation(negAtom.name);
        vector<string> negEqStrs;
        for (int argIndex = 0; argIndex < negAtom.argList.size(); argIndex++) {
            AtomArg& arg = negAtom.argList[argIndex];
            Attribute& attr = relation.attributes[argIndex];
            if (arg.isConst()) {
                ostringstream oss;
                oss << SqlGenerator::BACK_QUOTE
                    << negAtomAlias[negIndex]
                    << SqlGenerator::BACK_QUOTE
                    << "."
                    << SqlGenerator::BACK_QUOTE
                    << attr.name
                    << SqlGenerator::BACK_QUOTE
                    << " = ";
                if (attr.isNumeric()) {
                    oss << arg.name;
                } else {
                    oss << "'"
                        << arg.name
                        << "'";
                }
                negEqStrs.emplace_back(oss.str());
            } else if (arg.isVar()) {
                ostringstream oss;
                oss << SqlGenerator::BACK_QUOTE
                    << negAtomAlias[negIndex]
                    << SqlGenerator::BACK_QUOTE
                    << "."
                    << SqlGenerator::BACK_QUOTE
                    << attr.name
                    << SqlGenerator::BACK_QUOTE
                    << " = ";
                int posAtomIndex = antiJoinArgs[negIndex][argIndex].first;
                AtomMap& posAtom = bodyAtoms[posAtomIndex];
                Schema& posRelation = pg.getRelation(posAtom.name);
                int argIndexInPosAtom = antiJoinArgs[negIndex][argIndex].second;
                oss << SqlGenerator::BACK_QUOTE
                    << bodyAtomAlias[posAtomIndex]
                    << SqlGenerator::BACK_QUOTE
                    << "."
                    << SqlGenerator::BACK_QUOTE
                    << posRelation.attributes[argIndexInPosAtom].name
                    << SqlGenerator::BACK_QUOTE;
                negEqStrs.emplace_back(oss.str());
            }
        }

        ostringstream oss;
        oss << "NOT EXISTS (SELECT * FROM "
            << SqlGenerator::BACK_QUOTE
            << negAtom.name
            << SqlGenerator::BACK_QUOTE
            << " "
            << SqlGenerator::BACK_QUOTE
            << negAtomAlias[negIndex]
            << SqlGenerator::BACK_QUOTE;
        if (negEqStrs.size() > 0) {
            oss << " WHERE ";
            for (auto it = negEqStrs.begin(); it != negEqStrs.end(); it++) {
                if (it != negEqStrs.begin()) {
                    oss << " AND ";
                }
                oss << *it;
            }
        }
        oss << ")";

        negStrs.emplace_back(oss.str());
    }

    ostringstream oss;
    for (auto it = negStrs.begin(); it != negStrs.end(); it++) {
        if (it != negStrs.begin()) {
            oss << " AND ";
        }
        oss << *it;
    }
    return oss.str();
}

string SqlGenerator::generateGroupBy(AtomMap& head, DatalogProgram& pg) {
    vector<string> groupByAttrs;
    Schema& relation = pg.getRelation(head.name);
    int aggCount = 0;
    for (int i = 0; i < head.argList.size(); i++) {
        AtomArg& arg = head.argList[i];
        if (!arg.isAgg()) {
            groupByAttrs.emplace_back(relation.attributes[i].name);
        } else {
            aggCount++;
        }
    }
    if (aggCount == 0) {
        return "";
    }
    
    ostringstream oss;
    if (groupByAttrs.size() > 0) {
        oss << "GROUP BY ";
    }
    for (auto it = groupByAttrs.begin(); it != groupByAttrs.end(); it++) {
        if (it != groupByAttrs.begin()) {
            oss << ", ";
        }
        oss << SqlGenerator::BACK_QUOTE
            << *it
            << SqlGenerator::BACK_QUOTE;
    }
    return oss.str();
}

string SqlGenerator::generateIntersection(string tmpIdbDelta, 
            string idb, 
            Schema& relation, 
            map<int, string>& headAggregation) {
    //TODO: generate sql to compute set intersection, to be complete
    ostringstream oss;
    for (auto it = relation.attributes.begin(); it != relation.attributes.end(); it++) {
        if (it != relation.attributes.begin()) {
            oss << ", ";
        }
        oss << SqlGenerator::BACK_QUOTE
            << idb
            << SqlGenerator::BACK_QUOTE
            << "."
            << SqlGenerator::BACK_QUOTE
            << it->name
            << SqlGenerator::BACK_QUOTE;
    }
    string projection{oss.str()};

    string aggOp;
    int aggAttrIndex = -1;
    for (auto it : headAggregation) {
        aggOp = it.second;
        aggAttrIndex = it.first;
    }

    oss.str("");
    for (int i = 0; i < relation.attributes.size(); i++) {
        //FIXME: 此处执行aggregation是否正确？
        string compareOp;
        if (i != aggAttrIndex) {
            compareOp = "=";
        } else if (aggOp == "MIN") {
            compareOp = ">=";
        } else if (aggOp == "MAX") {
            compareOp = "<=";
        } else {
            //TODO: how to handle other aggregation? to be completed

        }

        if (i != 0) {
            oss << " AND ";
        }
        Attribute& attr = relation.attributes[i];
        oss << SqlGenerator::BACK_QUOTE
            << tmpIdbDelta
            << SqlGenerator::BACK_QUOTE
            << "."
            << SqlGenerator::BACK_QUOTE
            << attr.name
            << SqlGenerator::BACK_QUOTE
            << " "
            << compareOp
            << " "
            << SqlGenerator::BACK_QUOTE
            << idb
            << SqlGenerator::BACK_QUOTE
            << "."
            << SqlGenerator::BACK_QUOTE
            << attr.name
            << SqlGenerator::BACK_QUOTE;
    }
    string constraints{oss.str()};

    oss.str("");
    oss << "SELECT "
        << projection
        << " FROM "
        << SqlGenerator::BACK_QUOTE
        << idb
        << SqlGenerator::BACK_QUOTE
        << " WHERE "
        << constraints;
    string intersection{oss.str()};

    return intersection;
}

string SqlGenerator::generateSetDiff(string tmpIdbDelta, 
            string idb, 
            string idbDelta, 
            Schema& relation, 
            map<int, string>& headAggregation) {
    //generate sql to compute set difference
    string aggOp;
    int aggAttrIndex = -1;
    for (auto it : headAggregation) {
        aggOp = it.second;
        aggAttrIndex = it.first;
    }
    
    ostringstream oss;
    oss.str("");
    for (int i = 0; i < relation.attributes.size(); i++) {
        //FIXME: 此处执行aggregation是否正确？
        string compareOp;
        if (i != aggAttrIndex) {
            compareOp = "=";
        } else if (aggOp == "MIN") {
            compareOp = ">=";
        } else if (aggOp == "MAX") {
            compareOp = "<=";
        } else {
            //TODO: how to handle other aggregation? to be completed
        }

        if (i != 0) {
            oss << " AND ";
        }
        Attribute& attr = relation.attributes[i];
        oss << SqlGenerator::BACK_QUOTE
            << tmpIdbDelta
            << SqlGenerator::BACK_QUOTE
            << "."
            << SqlGenerator::BACK_QUOTE
            << attr.name
            << SqlGenerator::BACK_QUOTE
            << " "
            << compareOp
            << " "
            << SqlGenerator::BACK_QUOTE
            << idb
            << SqlGenerator::BACK_QUOTE
            << "."
            << SqlGenerator::BACK_QUOTE
            << attr.name
            << SqlGenerator::BACK_QUOTE;
    }
    string constraints{oss.str()};

    oss.str("");
    oss << "INSERT INTO "
        << SqlGenerator::BACK_QUOTE
        << idbDelta
        << SqlGenerator::BACK_QUOTE
        << " SELECT * FROM "
        << SqlGenerator::BACK_QUOTE
        << tmpIdbDelta
        << SqlGenerator::BACK_QUOTE
        << " WHERE NOT EXISTS "
        << "("
        << "SELECT * FROM "
        << SqlGenerator::BACK_QUOTE
        << idb
        << SqlGenerator::BACK_QUOTE
        << " WHERE "
        << constraints
        << ")";
    return oss.str();
}


string SqlGenerator::generateDrop(string tableName) {
    ostringstream oss;
    oss << "DROP TABLE IF EXISTS "
        << SqlGenerator::BACK_QUOTE
        << tableName
        << SqlGenerator::BACK_QUOTE
        << ";";
    
    return oss.str();
}


string SqlGenerator::generateCreate(Schema& relation, string tableName) {
    ostringstream oss;
    oss << "CREATE TABLE "
        << SqlGenerator::BACK_QUOTE
        << tableName
        << SqlGenerator::BACK_QUOTE
        << " (";

    for (auto it = relation.attributes.begin(); it != relation.attributes.end(); it++) {
        if (it != relation.attributes.begin()) {
            oss << ", ";
        }
        oss << SqlGenerator::BACK_QUOTE
            << it->name
            << SqlGenerator::BACK_QUOTE
            << " "
            << it->type;
    }
    oss << ");";
    
    return oss.str();
}

/**
 * @brief 计算每个var在哪个atom的哪些位置
 * 
 * @param bodyAtoms 
 * @param varBodyIndex 
 */
void extractVarBodyIndex(vector<AtomMap>& bodyAtoms, 
    map<string, map<int, vector<int>>>& varBodyIndex) {
    //TODO: 可能需要修正参数的顺序
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
    //TODO: 可能需要修正参数的顺序
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
    //TODO: 可能需要修正参数的顺序
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
    //TODO: 可能需要修正参数的顺序
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
            //TODO: negArgs好像没有必要
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

void deltaBodyGroups(vector<AtomMap>& bodyAtoms, 
    map<string, vector<RuleMap*>>& recursiveRuleGroups,
    int iterateNum, 
    vector<vector<string>>& deltaGroups) {
    //generate the bodies of delta rules, to be completed.

    int recursiveIdbCount = 0;
    for (auto& atom : bodyAtoms) {
        string idb = atom.name;
        if (recursiveRuleGroups.find(idb) != recursiveRuleGroups.end()) {
            recursiveIdbCount++;
        }
    }

    // deltaGroups = vector<vector<string>>(std::pow(2, recursiveIdbCount) + 1, vector<string>{});
    deltaGroups.emplace_back(vector<string>{});
    for (auto& atom : bodyAtoms) {
        if (recursiveRuleGroups.find(atom.name) == recursiveRuleGroups.end()) {
            for (auto& deltaGroup : deltaGroups) {
                deltaGroup.emplace_back(atom.name);
            }
        } else {
            string prevAtom{atom.name + "_prev"};
            string deltaAtom{atom.name + string("_delta_") + std::to_string(iterateNum)};
            // for (int i = 0; i < deltaGroups.size() / 2; i++) {
            //     deltaGroup[i].emplace_back(deltaGroup[i].back());
            //     deltaGroups[2 * i + 1].emplace_back(prevAtom);
            //     deltaGroups[2 * i + 2].emplace_back(deltaAtom);
            // }

            vector<vector<string>> childrenGroups;
            for (auto& group : deltaGroups) {
                vector<string> childGroup{group};
                childGroup.emplace_back(deltaAtom);
                childrenGroups.emplace_back(childGroup);
                group.emplace_back(prevAtom);
            }
            deltaGroups.insert(deltaGroups.end(), childrenGroups.begin(), childrenGroups.end());
        }
    }

    if (recursiveIdbCount >= 1) {
        deltaGroups.erase(deltaGroups.begin(), deltaGroups.begin() + 1);
    }
}