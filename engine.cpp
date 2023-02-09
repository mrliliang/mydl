#include <iostream>
#include <string>
#include <vector>

#include "parser/DatalogProgram.h"
#include "rule_analyzer/RuleAnalyzer.h"
#include "execution/Executor.h"

using namespace std;

void createTables(vector<Schema> &relations);

int main(int argc, char *args[])
{
    if (argc <= 1)
    {
        std::cout << "no datalog program file" << std::endl;
        exit(0);
    }

    string dlogFile{args[1]};
    std::cout << dlogFile << endl;

    DatalogProgram prog{dlogFile};
    prog.print();

    vector<RuleMap> &rules = prog.getRules();
    RuleAnalyzer analyzer{&prog.getRules()};

    std::cout << "Rule dependency" << endl;
    analyzer.printDependencyGraph();

    std::cout << "Rule sccs in reverse evaluation order" << endl;
    // analyzer.printSccs();
    analyzer.printSccs1();

    std::cout << "Rule groups in evaluation order" << endl;
    analyzer.printRuleGroups();

    Executor executor;

    vector<Schema> &edbs = prog.getEdbs();
    executor.createTables(edbs);

    vector<Schema> &idbs = prog.getIdbs();
    executor.createTables(idbs);

    executor.loadData(edbs);

    vector<RuleMap> &allRuels = prog.getRules();
    vector<RuleGroup> *groups = analyzer.getRuleGroups();
    for (RuleGroup &ruleGroup : *groups) {
        vector<RuleMap> evalRules;
        for (int r : ruleGroup.rules) {
            evalRules.push_back(allRules[r]);
        }
        if (ruleGroup.isRecursive) {
            executor.nonRecursiveRuleEval(evalRules);
        }
        else {
            executor.recursiveRuleEval();
        }
    }

    return 0;
}
