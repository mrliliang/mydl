#include <iostream>
#include <string>
#include <vector>

#include "parser/DatalogProgram.h"
#include "rule_analyzer/RuleAnalyzer.h"



using namespace std;

int main(int argc, char *args[])
{
    if (argc <= 1) {
        std::cout << "no datalog program file" << std::endl;
        exit(0);
    }

    string dlogFile{args[1]};
    std::cout << dlogFile << endl;

    DatalogProgram prog{dlogFile};
    prog.print();

    vector<RuleMap> &rules = prog.getRules();
    RuleAnalyzer analyzer{&prog.getRules()};

    // vector<Schema> &edbs = prog.getEdbs();
    // prog.iterateEdbIdb(edbs);

    // vector<Schema> &idbs = prog.getIdbs();
    // prog.iterateEdbIdb(idbs);

    // vector<RuleMap> &rules = prog.getRules();
    // prog.iterateDatalogProgram(rules);

    return 0;
}