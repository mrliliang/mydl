cmake_minimum_required(VERSION 3.15)

project(mydatalog)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)



add_executable(parser ./parser/parser.cpp ./parser/MyDatalogLexer.cpp ./parser/MyDatalogParser.cpp
    ./parser/DatalogProgram.cpp
    ./rule_analyzer/RuleAnalyzer.cpp
)
# target_link_libraries(parser /usr/local/lib/libantlr4-runtime.a)
target_link_libraries(parser antlr4-runtime)
