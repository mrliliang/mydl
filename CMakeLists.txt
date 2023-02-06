cmake_minimum_required(VERSION 3.15)

project(mydatalog)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_CXX_FLAGS "-O3")
# set(CMAKE_C_COMPILER, gcc-12)
# set(CMAKE_CXX_COMPILER, g++-12)


add_executable(parser 
    ./parser/parser.cpp 
    ./parser/MyDatalogLexer.cpp 
    ./parser/MyDatalogParser.cpp
    ./parser/DatalogProgram.cpp
    ./rule_analyzer/RuleAnalyzer.cpp
)
target_link_libraries(parser antlr4-runtime)

add_executable(engine 
    ./parser/MyDatalogLexer.cpp 
    ./parser/MyDatalogParser.cpp
    ./parser/DatalogProgram.cpp
    ./rule_analyzer/RuleAnalyzer.cpp
    ./execution/Executor.cpp
    engine.cpp
)

# target_link_libraries(parser /usr/local/lib/libantlr4-runtime.a)
target_link_libraries(engine antlr4-runtime)

add_executable(demo demo.cpp)