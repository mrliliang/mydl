



// Generated from MyDatalog.g4 by ANTLR 4.11.1

#pragma once


#include "basetype.h"


#include "antlr4-runtime.h"


using namespace std;




class  MyDatalogParser : public antlr4::Parser {
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

  enum {
    RuleDatalog_edb_declare = 0, RuleDatalog_idb_declare = 1, RuleDatalog_relation_schema = 2, 
    RuleDatalog_rule_declare = 3, RuleDatalog_program = 4, RuleDatalog_rule = 5, 
    RuleHead = 6, RuleBody = 7, RuleNegation = 8, RuleAtom = 9, RuleAssign = 10, 
    RuleMath_expr = 11, RuleCompare_expr = 12, RuleAggregation_expr = 13, 
    RuleAttribute = 14, RuleKey_attribute = 15, RuleNon_key_attribute = 16, 
    RuleCompare_op = 17, RuleAggregation_op = 18, RuleMath_op = 19, RuleConstant = 20, 
    RuleData_type = 21
  };

  explicit MyDatalogParser(antlr4::TokenStream *input);

  MyDatalogParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MyDatalogParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Datalog_edb_declareContext;
  class Datalog_idb_declareContext;
  class Datalog_relation_schemaContext;
  class Datalog_rule_declareContext;
  class Datalog_programContext;
  class Datalog_ruleContext;
  class HeadContext;
  class BodyContext;
  class NegationContext;
  class AtomContext;
  class AssignContext;
  class Math_exprContext;
  class Compare_exprContext;
  class Aggregation_exprContext;
  class AttributeContext;
  class Key_attributeContext;
  class Non_key_attributeContext;
  class Compare_opContext;
  class Aggregation_opContext;
  class Math_opContext;
  class ConstantContext;
  class Data_typeContext; 

  class  Datalog_edb_declareContext : public antlr4::ParserRuleContext {
  public:
    vector<Schema> r;
    MyDatalogParser::Datalog_relation_schemaContext *schema1 = nullptr;
    MyDatalogParser::Datalog_relation_schemaContext *schema2 = nullptr;
    Datalog_edb_declareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_EDB();
    antlr4::tree::TerminalNode *TOKEN_COLON();
    std::vector<Datalog_relation_schemaContext *> datalog_relation_schema();
    Datalog_relation_schemaContext* datalog_relation_schema(size_t i);

   
  };

  Datalog_edb_declareContext* datalog_edb_declare();

  class  Datalog_idb_declareContext : public antlr4::ParserRuleContext {
  public:
    vector<Schema> r;
    MyDatalogParser::Datalog_relation_schemaContext *schema1 = nullptr;
    MyDatalogParser::Datalog_relation_schemaContext *schema2 = nullptr;
    Datalog_idb_declareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_IDB();
    antlr4::tree::TerminalNode *TOKEN_COLON();
    std::vector<Datalog_relation_schemaContext *> datalog_relation_schema();
    Datalog_relation_schemaContext* datalog_relation_schema(size_t i);

   
  };

  Datalog_idb_declareContext* datalog_idb_declare();

  class  Datalog_relation_schemaContext : public antlr4::ParserRuleContext {
  public:
    Schema r;
    antlr4::Token *relation_name = nullptr;
    MyDatalogParser::AttributeContext *t1 = nullptr;
    MyDatalogParser::AttributeContext *t2 = nullptr;
    Datalog_relation_schemaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_LEFT_PAREN();
    antlr4::tree::TerminalNode *TOKEN_RIGHT_PAREN();
    antlr4::tree::TerminalNode *TOKEN_ID();
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);
    std::vector<antlr4::tree::TerminalNode *> TOKEN_COMMA();
    antlr4::tree::TerminalNode* TOKEN_COMMA(size_t i);

   
  };

  Datalog_relation_schemaContext* datalog_relation_schema();

  class  Datalog_rule_declareContext : public antlr4::ParserRuleContext {
  public:
    vector<RuleMap> r;
    MyDatalogParser::Datalog_programContext *dp = nullptr;
    Datalog_rule_declareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_RULE();
    antlr4::tree::TerminalNode *TOKEN_COLON();
    antlr4::tree::TerminalNode *EOF();
    Datalog_programContext *datalog_program();

   
  };

  Datalog_rule_declareContext* datalog_rule_declare();

  class  Datalog_programContext : public antlr4::ParserRuleContext {
  public:
    vector<RuleMap> r;
    MyDatalogParser::Datalog_ruleContext *r1 = nullptr;
    MyDatalogParser::Datalog_ruleContext *r2 = nullptr;
    Datalog_programContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Datalog_ruleContext *> datalog_rule();
    Datalog_ruleContext* datalog_rule(size_t i);

   
  };

  Datalog_programContext* datalog_program();

  class  Datalog_ruleContext : public antlr4::ParserRuleContext {
  public:
    RuleMap r;
    MyDatalogParser::HeadContext *h = nullptr;
    MyDatalogParser::BodyContext *b = nullptr;
    Datalog_ruleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_BODY_HEAD_SEP();
    antlr4::tree::TerminalNode *TOKEN_DOT();
    HeadContext *head();
    antlr4::tree::TerminalNode *TOKEN_NON_DEDUP();
    antlr4::tree::TerminalNode *TOKEN_NON_SET_DIFF();
    antlr4::tree::TerminalNode *TOKEN_DEDUP_ONLY();
    BodyContext *body();

   
  };

  Datalog_ruleContext* datalog_rule();

  class  HeadContext : public antlr4::ParserRuleContext {
  public:
    AtomMap r;
    MyDatalogParser::AtomContext *a = nullptr;
    HeadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();

   
  };

  HeadContext* head();

  class  BodyContext : public antlr4::ParserRuleContext {
  public:
    BodyMap r;
    MyDatalogParser::AtomContext *b1 = nullptr;
    MyDatalogParser::Compare_exprContext *b2 = nullptr;
    MyDatalogParser::AssignContext *b3 = nullptr;
    MyDatalogParser::NegationContext *b4 = nullptr;
    MyDatalogParser::AtomContext *b5 = nullptr;
    MyDatalogParser::Compare_exprContext *b6 = nullptr;
    MyDatalogParser::AssignContext *b7 = nullptr;
    MyDatalogParser::NegationContext *b8 = nullptr;
    BodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> TOKEN_COMMA();
    antlr4::tree::TerminalNode* TOKEN_COMMA(size_t i);
    std::vector<AtomContext *> atom();
    AtomContext* atom(size_t i);
    std::vector<Compare_exprContext *> compare_expr();
    Compare_exprContext* compare_expr(size_t i);
    std::vector<AssignContext *> assign();
    AssignContext* assign(size_t i);
    std::vector<NegationContext *> negation();
    NegationContext* negation(size_t i);

   
  };

  BodyContext* body();

  class  NegationContext : public antlr4::ParserRuleContext {
  public:
    AtomMap r;
    MyDatalogParser::AtomContext *a = nullptr;
    NegationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_NOT();
    AtomContext *atom();

   
  };

  NegationContext* negation();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomMap r;
    antlr4::Token *a1 = nullptr;
    antlr4::Token *a2 = nullptr;
    MyDatalogParser::Aggregation_exprContext *a3 = nullptr;
    antlr4::Token *a4 = nullptr;
    MyDatalogParser::ConstantContext *a5 = nullptr;
    MyDatalogParser::Math_exprContext *a6 = nullptr;
    antlr4::Token *a7 = nullptr;
    MyDatalogParser::Aggregation_exprContext *a8 = nullptr;
    antlr4::Token *a9 = nullptr;
    MyDatalogParser::ConstantContext *a10 = nullptr;
    MyDatalogParser::Math_exprContext *a11 = nullptr;
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_LEFT_PAREN();
    antlr4::tree::TerminalNode *TOKEN_RIGHT_PAREN();
    std::vector<antlr4::tree::TerminalNode *> TOKEN_ID();
    antlr4::tree::TerminalNode* TOKEN_ID(size_t i);
    std::vector<Aggregation_exprContext *> aggregation_expr();
    Aggregation_exprContext* aggregation_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> TOKEN_ANY();
    antlr4::tree::TerminalNode* TOKEN_ANY(size_t i);
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    std::vector<Math_exprContext *> math_expr();
    Math_exprContext* math_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> TOKEN_COMMA();
    antlr4::tree::TerminalNode* TOKEN_COMMA(size_t i);

   
  };

  AtomContext* atom();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    AssignMap r;
    antlr4::Token *a1 = nullptr;
    MyDatalogParser::Math_exprContext *a2 = nullptr;
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_EQUALS();
    antlr4::tree::TerminalNode *TOKEN_ID();
    Math_exprContext *math_expr();

   
  };

  AssignContext* assign();

  class  Math_exprContext : public antlr4::ParserRuleContext {
  public:
    MathMap r;
    antlr4::Token *m1 = nullptr;
    MyDatalogParser::Math_opContext *m2 = nullptr;
    antlr4::Token *m3 = nullptr;
    Math_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> TOKEN_ID();
    antlr4::tree::TerminalNode* TOKEN_ID(size_t i);
    Math_opContext *math_op();

   
  };

  Math_exprContext* math_expr();

  class  Compare_exprContext : public antlr4::ParserRuleContext {
  public:
    CompareMap r;
    antlr4::Token *c1 = nullptr;
    antlr4::Token *c2 = nullptr;
    MyDatalogParser::Compare_opContext *op = nullptr;
    antlr4::Token *c3 = nullptr;
    antlr4::Token *c4 = nullptr;
    Compare_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Compare_opContext *compare_op();
    std::vector<antlr4::tree::TerminalNode *> TOKEN_ID();
    antlr4::tree::TerminalNode* TOKEN_ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> TOKEN_INTEGER();
    antlr4::tree::TerminalNode* TOKEN_INTEGER(size_t i);

   
  };

  Compare_exprContext* compare_expr();

  class  Aggregation_exprContext : public antlr4::ParserRuleContext {
  public:
    AggMap r;
    MyDatalogParser::Aggregation_opContext *a1 = nullptr;
    antlr4::Token *a2 = nullptr;
    MyDatalogParser::Math_exprContext *a3 = nullptr;
    Aggregation_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_LEFT_PAREN();
    antlr4::tree::TerminalNode *TOKEN_RIGHT_PAREN();
    Aggregation_opContext *aggregation_op();
    antlr4::tree::TerminalNode *TOKEN_ID();
    Math_exprContext *math_expr();

   
  };

  Aggregation_exprContext* aggregation_expr();

  class  AttributeContext : public antlr4::ParserRuleContext {
  public:
    Attribute r;
    MyDatalogParser::Non_key_attributeContext *a1 = nullptr;
    MyDatalogParser::Key_attributeContext *a2 = nullptr;
    AttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Non_key_attributeContext *non_key_attribute();
    Key_attributeContext *key_attribute();

   
  };

  AttributeContext* attribute();

  class  Key_attributeContext : public antlr4::ParserRuleContext {
  public:
    Attribute r;
    antlr4::Token *a1 = nullptr;
    MyDatalogParser::Data_typeContext *d1 = nullptr;
    Key_attributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_LEFT_BRACKET();
    antlr4::tree::TerminalNode *TOKEN_RIGHT_BRACKET();
    antlr4::tree::TerminalNode *TOKEN_ID();
    Data_typeContext *data_type();

   
  };

  Key_attributeContext* key_attribute();

  class  Non_key_attributeContext : public antlr4::ParserRuleContext {
  public:
    Attribute r;
    antlr4::Token *a1 = nullptr;
    MyDatalogParser::Data_typeContext *d1 = nullptr;
    Non_key_attributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_ID();
    Data_typeContext *data_type();

   
  };

  Non_key_attributeContext* non_key_attribute();

  class  Compare_opContext : public antlr4::ParserRuleContext {
  public:
    string r;
    antlr4::Token *op1 = nullptr;
    antlr4::Token *op2 = nullptr;
    antlr4::Token *op3 = nullptr;
    antlr4::Token *op4 = nullptr;
    antlr4::Token *op5 = nullptr;
    antlr4::Token *op6 = nullptr;
    Compare_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_NOT_EQUALS();
    antlr4::tree::TerminalNode *TOKEN_EQUALS();
    antlr4::tree::TerminalNode *TOKEN_GREATER_THAN();
    antlr4::tree::TerminalNode *TOKEN_GREATER_EQUAL_THAN();
    antlr4::tree::TerminalNode *TOKEN_LESS_THAN();
    antlr4::tree::TerminalNode *TOKEN_LESS_EQUAL_THAN();

   
  };

  Compare_opContext* compare_op();

  class  Aggregation_opContext : public antlr4::ParserRuleContext {
  public:
    string r;
    antlr4::Token *op1 = nullptr;
    antlr4::Token *op2 = nullptr;
    antlr4::Token *op3 = nullptr;
    antlr4::Token *op4 = nullptr;
    antlr4::Token *op5 = nullptr;
    Aggregation_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_MIN();
    antlr4::tree::TerminalNode *TOKEN_MAX();
    antlr4::tree::TerminalNode *TOKEN_SUM();
    antlr4::tree::TerminalNode *TOKEN_COUNT();
    antlr4::tree::TerminalNode *TOKEN_COUNT_DISTINCT();

   
  };

  Aggregation_opContext* aggregation_op();

  class  Math_opContext : public antlr4::ParserRuleContext {
  public:
    string r;
    antlr4::Token *op1 = nullptr;
    antlr4::Token *op2 = nullptr;
    antlr4::Token *op3 = nullptr;
    antlr4::Token *op4 = nullptr;
    Math_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_PLUS();
    antlr4::tree::TerminalNode *TOKEN_MINUS();
    antlr4::tree::TerminalNode *TOKEN_MULT();
    antlr4::tree::TerminalNode *TOKEN_DIV();

   
  };

  Math_opContext* math_op();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    string r;
    antlr4::Token *c1 = nullptr;
    antlr4::Token *c2 = nullptr;
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_INTEGER();
    antlr4::tree::TerminalNode *TOKEN_STRING();

   
  };

  ConstantContext* constant();

  class  Data_typeContext : public antlr4::ParserRuleContext {
  public:
    string r;
    antlr4::Token *dt1 = nullptr;
    antlr4::Token *dt2 = nullptr;
    antlr4::Token *dt3 = nullptr;
    antlr4::Token *dt4 = nullptr;
    antlr4::Token *dt5 = nullptr;
    antlr4::Token *dt6 = nullptr;
    antlr4::Token *dt7 = nullptr;
    antlr4::Token *dt8 = nullptr;
    Data_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN_INT();
    antlr4::tree::TerminalNode *TOKEN_LONG();
    antlr4::tree::TerminalNode *TOKEN_FLOAT();
    antlr4::tree::TerminalNode *TOKEN_DOUBLE();
    antlr4::tree::TerminalNode *TOKEN_VARCHAR();
    antlr4::tree::TerminalNode *TOKEN_CHAR();
    antlr4::tree::TerminalNode *TOKEN_DATE();
    antlr4::tree::TerminalNode *TOKEN_DATETIME();

   
  };

  Data_typeContext* data_type();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

