
#include <iostream>
#include <fstream>

#include "antlr4-runtime.h"

// #include "DatalogCPPLexer.h"
// #include "DatalogCPPParser.h"

#include "MyDatalogLexer.h"
#include "MyDatalogParser.h"

using namespace std;
using namespace antlr4;

/*
    EDB_DECL:
    Arc(x int, y int)

    IDB_DECL :
    Cc3(x int, y int)
    Cc2(x int, y int)
    Cc(x int)

    RULE_DECL :
    Cc3(x, MIN(x)) : -Arc(x, _).
    Cc3(y, MIN(z)) : -Cc3(x, z),Arc(x, y).
    Cc2(x, MIN(y)) : -Cc3(x, y).
    Cc(x) : -Cc2(_, x).
*/

int main(int argc, char * args[]) {
    // ANTLRInputStream input(u8"🍴 = 🍐 + \"😎\";(((x * π))) * µ + ∰; a + (x * (y ? 0 : 1) + z);");

    string str{"EDB_DECL:\n"
               "Arc(x int, y int)\n"
               "IDB_DECL:\n"
               "Cc3(x int, y int)\n"
               "Cc2(x int, y int)\n"
               "Cc(x int)\n"
               "RULE_DECL:\n"
               "Cc3(x, MIN(x)) :- Arc(x, _).\n"
               "Cc3(y, MIN(z)) :- Cc3(x, z),Arc(x, y).\n"
               "Cc2(x, MIN(y)) :- Cc3(x, y).\n"
               "Cc(x) :- Cc2(_, x)."};

    ifstream ifs{"../benchmark_datalog_programs/cc.datalog"};
    ANTLRInputStream input(ifs);
    MyDatalogLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();
    for (auto token : tokens.getTokens())
    {
        std::cout << token->toString() << std::endl;
    }

    MyDatalogParser parser(&tokens);

    MyDatalogParser::Datalog_edb_declareContext *tree1 = parser.datalog_edb_declare();
    std::cout << tree1->toStringTree(&parser) << std::endl;

    std::cout << endl
              << endl
              << endl;

    MyDatalogParser::Datalog_idb_declareContext *tree2 = parser.datalog_idb_declare();
    std::cout << tree2->toStringTree(&parser) << std::endl;

    std::cout << endl
              << endl
              << endl;

    MyDatalogParser::Datalog_rule_declareContext *tree3 = parser.datalog_rule_declare();
    std::cout << tree3->toStringTree(&parser) << std::endl;

    std::cout << endl
              << endl
              << endl;

    MyDatalogParser::Datalog_programContext *tree = tree3->dp;
    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}


