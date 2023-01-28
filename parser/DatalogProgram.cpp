#include <fstream>
#include <string>


#include "DatalogProgram.h"
#include "antlr4-runtime.h"

using namespace std;
using namespace antlr4;

DatalogProgram::DatalogProgram(string &datalogFilePath) {
    ifstream ifs{datalogFilePath};
    ANTLRInputStream input{ifs};
    MyDatalogLexer lexer{&input};
    CommonTokenStream tokens{&lexer};
    MyDatalogParser parser{&tokens};

    this->edbs = parser.datalog_edb_declare()->r;
    this->idbs = parser.datalog_idb_declare()->r;
    this->rules = parser.datalog_rule_declare()->r;

    // RuleAnalyzer analyzer{&this->rules};
    // this->dg = ;
    // this.sccs = ;
    // this.ruleGroups = ;
}

vector<Schema>& DatalogProgram::getEdbs() {
    return this->edbs;
}

vector<Schema>& DatalogProgram::getIdbs() {
    return this->idbs;
}

vector<RuleMap>& DatalogProgram::getRules() {
    return this->rules;
}

DatalogProgram::~DatalogProgram()
{
}

void DatalogProgram::iterateDatalogProgram(vector<RuleMap> &rules)
{
    for (auto count = 0; count < rules.size(); count++) {
        std::cout << count << ":";
        this->iterateDatalogRule(rules[count]);
    }
}

void DatalogProgram::iterateDatalogRule(RuleMap &rule)
{
    AtomMap &head = rule.head;
    BodyMap &body = rule.body;
    vector<AtomArg> &headArgs = head.argList;

    vector<string> headArgsStrs;
    for (auto arg : headArgs) {
        string argStr;
        if (arg.type == "aggregaton") {
            if (arg.aggmap.aggArg.type == "attribute") {
                argStr.append(arg.aggmap.aggOp)
                    .append("(")
                    .append(arg.aggmap.aggArg.attr)
                    .append(")");
            }
            if (arg.aggmap.aggArg.type == "math_expr") {
                argStr.append(arg.aggmap.aggOp)
                    .append("(")
                    .append(arg.aggmap.aggArg.mathmap.lhs)
                    .append(arg.aggmap.aggArg.mathmap.op)
                    .append(arg.aggmap.aggArg.mathmap.rhs)
                    .append(")");
            }
        } else if (arg.type == "math_expr") {
            argStr.append(arg.mathmap.lhs)
                .append(arg.mathmap.op)
                .append(arg.mathmap.rhs);
        } else {
            argStr = arg.name;
        }
        headArgsStr.emplace_back(argStr);
    }

    //TODO to be completed
    string headStr{""};
    headStr.append(head.name).append("(");
    if (headArgs.size() > 0) {
        headStr.append(headArgsStrs[0]);
    }
    for (int i = 1; i < headArgs.size(); i++) {
        headStr.append(", ").append(headArgsStrs[i]);
    }
    headStr.append(")");

    vector<string> bodyItemStrs;
    string bodyStr{""};

    std::cout << headStr << " :- " << bodyStr << std::endl;
}

void DatalogProgram::iterateEdbIdb(vector<Schema> &relations)
{
    for (auto relation : relations) {
        string attrStr{""};
        vector<AtomArg> &attrs = relation.attributes;
        AtomArg &firstAttr = attrs[0];
        attrStr.append(firstAttr.name)
            .append(" ")
            .append(firstAttr.type);
        for (int i = 1; i < attrs.size(); i++) {
            attrStr.append(", ")
                .append(attrs[i].name)
                .append(" ")
                .append(attrs[i].type);
        }
        std::cout << relation.name
                  << "("
                  << attrStr
                  << ")"
                  << std::endl;
    }
}
