



// Generated from MyDatalog.g4 by ANTLR 4.11.1

#pragma once


#include "basetype.h"


#include "antlr4-runtime.h"




class  MyDatalogLexer : public antlr4::Lexer {
public:
  enum {
    TOKEN_EDB = 1, TOKEN_IDB = 2, TOKEN_RULE = 3, TOKEN_INTEGER = 4, TOKEN_STRING = 5, 
    TOKEN_INT = 6, TOKEN_LONG = 7, TOKEN_FLOAT = 8, TOKEN_DOUBLE = 9, TOKEN_VARCHAR = 10, 
    TOKEN_CHAR = 11, TOKEN_DATE = 12, TOKEN_DATETIME = 13, TOKEN_MIN = 14, 
    TOKEN_MAX = 15, TOKEN_SUM = 16, TOKEN_COUNT = 17, TOKEN_COUNT_DISTINCT = 18, 
    TOKEN_ID = 19, TOKEN_BODY_HEAD_SEP = 20, TOKEN_ANY = 21, TOKEN_COMMA = 22, 
    TOKEN_SEMICOLON = 23, TOKEN_COLON = 24, TOKEN_DOT = 25, TOKEN_PLUS = 26, 
    TOKEN_MINUS = 27, TOKEN_MULT = 28, TOKEN_DIV = 29, TOKEN_NOT = 30, TOKEN_NON_DEDUP = 31, 
    TOKEN_NON_SET_DIFF = 32, TOKEN_DEDUP_ONLY = 33, TOKEN_NOT_EQUALS = 34, 
    TOKEN_EQUALS = 35, TOKEN_GREATER_EQUAL_THAN = 36, TOKEN_GREATER_THAN = 37, 
    TOKEN_LESS_EQUAL_THAN = 38, TOKEN_LESS_THAN = 39, TOKEN_LEFT_PAREN = 40, 
    TOKEN_RIGHT_PAREN = 41, TOKEN_LEFT_BRACKET = 42, TOKEN_RIGHT_BRACKET = 43, 
    TOKEN_WS = 44
  };

  explicit MyDatalogLexer(antlr4::CharStream *input);

  ~MyDatalogLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

