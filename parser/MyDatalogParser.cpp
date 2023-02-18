



// Generated from MyDatalog.g4 by ANTLR 4.11.1


#include "basetype.h"



#include "MyDatalogParser.h"


using namespace std;


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MyDatalogParserStaticData final {
  MyDatalogParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MyDatalogParserStaticData(const MyDatalogParserStaticData&) = delete;
  MyDatalogParserStaticData(MyDatalogParserStaticData&&) = delete;
  MyDatalogParserStaticData& operator=(const MyDatalogParserStaticData&) = delete;
  MyDatalogParserStaticData& operator=(MyDatalogParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mydatalogParserOnceFlag;
MyDatalogParserStaticData *mydatalogParserStaticData = nullptr;

void mydatalogParserInitialize() {
  assert(mydatalogParserStaticData == nullptr);
  auto staticData = std::make_unique<MyDatalogParserStaticData>(
    std::vector<std::string>{
      "datalog_edb_declare", "datalog_idb_declare", "datalog_relation_schema", 
      "datalog_rule_declare", "datalog_program", "datalog_rule", "head", 
      "body", "negation", "atom", "assign", "math_expr", "compare_expr", 
      "aggregation_expr", "attribute", "key_attribute", "non_key_attribute", 
      "compare_op", "aggregation_op", "math_op", "constant", "data_type"
    },
    std::vector<std::string>{
      "", "'EDB_DECL'", "'IDB_DECL'", "'RULE_DECL'", "", "", "", "", "", 
      "", "", "", "", "", "'MIN'", "'MAX'", "'SUM'", "'COUNT'", "'COUNT_DISTINCT'", 
      "", "':-'", "'_'", "','", "';'", "':'", "'.'", "'+'", "'-'", "'*'", 
      "'/'", "'!'", "'[!dedup]'", "'[!set-diff]'", "'[dedup-only]'", "'!='", 
      "'='", "'>='", "'>'", "'<='", "'<'", "'('", "')'", "'['", "']'"
    },
    std::vector<std::string>{
      "", "TOKEN_EDB", "TOKEN_IDB", "TOKEN_RULE", "TOKEN_INTEGER", "TOKEN_STRING", 
      "TOKEN_INT", "TOKEN_LONG", "TOKEN_FLOAT", "TOKEN_DOUBLE", "TOKEN_VARCHAR", 
      "TOKEN_CHAR", "TOKEN_DATE", "TOKEN_DATETIME", "TOKEN_MIN", "TOKEN_MAX", 
      "TOKEN_SUM", "TOKEN_COUNT", "TOKEN_COUNT_DISTINCT", "TOKEN_ID", "TOKEN_BODY_HEAD_SEP", 
      "TOKEN_ANY", "TOKEN_COMMA", "TOKEN_SEMICOLON", "TOKEN_COLON", "TOKEN_DOT", 
      "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULT", "TOKEN_DIV", "TOKEN_NOT", 
      "TOKEN_NON_DEDUP", "TOKEN_NON_SET_DIFF", "TOKEN_DEDUP_ONLY", "TOKEN_NOT_EQUALS", 
      "TOKEN_EQUALS", "TOKEN_GREATER_EQUAL_THAN", "TOKEN_GREATER_THAN", 
      "TOKEN_LESS_EQUAL_THAN", "TOKEN_LESS_THAN", "TOKEN_LEFT_PAREN", "TOKEN_RIGHT_PAREN", 
      "TOKEN_LEFT_BRACKET", "TOKEN_RIGHT_BRACKET", "TOKEN_WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,44,356,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,5,0,53,8,0,10,0,12,0,56,9,0,1,0,1,
  	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,68,8,1,10,1,12,1,71,9,1,1,1,1,1,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,85,8,2,10,2,12,2,88,9,2,1,
  	2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,5,4,105,8,4,
  	10,4,12,4,108,9,4,1,4,1,4,1,5,1,5,1,5,3,5,115,8,5,1,5,1,5,3,5,119,8,5,
  	1,5,1,5,3,5,123,8,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,131,8,5,1,5,1,5,1,5,1,
  	6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,152,
  	8,7,1,7,1,7,5,7,156,8,7,10,7,12,7,159,9,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,3,7,173,8,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,198,8,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,214,8,9,5,9,216,
  	8,9,10,9,12,9,219,9,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,
  	1,12,3,12,246,8,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,254,8,12,1,12,1,
  	12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,267,8,13,1,13,1,
  	13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,3,14,278,8,14,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,
  	17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,308,8,17,1,
  	18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,320,8,18,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,330,8,19,1,20,1,20,1,20,1,20,3,
  	20,336,8,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,3,21,354,8,21,1,21,0,0,22,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,38,40,42,0,0,381,0,44,1,0,0,0,2,59,1,0,
  	0,0,4,74,1,0,0,0,6,92,1,0,0,0,8,98,1,0,0,0,10,111,1,0,0,0,12,135,1,0,
  	0,0,14,138,1,0,0,0,16,176,1,0,0,0,18,180,1,0,0,0,20,223,1,0,0,0,22,231,
  	1,0,0,0,24,240,1,0,0,0,26,257,1,0,0,0,28,277,1,0,0,0,30,279,1,0,0,0,32,
  	288,1,0,0,0,34,307,1,0,0,0,36,319,1,0,0,0,38,329,1,0,0,0,40,335,1,0,0,
  	0,42,353,1,0,0,0,44,45,6,0,-1,0,45,46,5,1,0,0,46,47,5,24,0,0,47,48,3,
  	4,2,0,48,54,6,0,-1,0,49,50,3,4,2,0,50,51,6,0,-1,0,51,53,1,0,0,0,52,49,
  	1,0,0,0,53,56,1,0,0,0,54,52,1,0,0,0,54,55,1,0,0,0,55,57,1,0,0,0,56,54,
  	1,0,0,0,57,58,6,0,-1,0,58,1,1,0,0,0,59,60,6,1,-1,0,60,61,5,2,0,0,61,62,
  	5,24,0,0,62,63,3,4,2,0,63,69,6,1,-1,0,64,65,3,4,2,0,65,66,6,1,-1,0,66,
  	68,1,0,0,0,67,64,1,0,0,0,68,71,1,0,0,0,69,67,1,0,0,0,69,70,1,0,0,0,70,
  	72,1,0,0,0,71,69,1,0,0,0,72,73,6,1,-1,0,73,3,1,0,0,0,74,75,6,2,-1,0,75,
  	76,5,19,0,0,76,77,6,2,-1,0,77,78,5,40,0,0,78,79,3,28,14,0,79,86,6,2,-1,
  	0,80,81,5,22,0,0,81,82,3,28,14,0,82,83,6,2,-1,0,83,85,1,0,0,0,84,80,1,
  	0,0,0,85,88,1,0,0,0,86,84,1,0,0,0,86,87,1,0,0,0,87,89,1,0,0,0,88,86,1,
  	0,0,0,89,90,5,41,0,0,90,91,6,2,-1,0,91,5,1,0,0,0,92,93,5,3,0,0,93,94,
  	5,24,0,0,94,95,3,8,4,0,95,96,6,3,-1,0,96,97,5,0,0,1,97,7,1,0,0,0,98,99,
  	6,4,-1,0,99,100,3,10,5,0,100,106,6,4,-1,0,101,102,3,10,5,0,102,103,6,
  	4,-1,0,103,105,1,0,0,0,104,101,1,0,0,0,105,108,1,0,0,0,106,104,1,0,0,
  	0,106,107,1,0,0,0,107,109,1,0,0,0,108,106,1,0,0,0,109,110,6,4,-1,0,110,
  	9,1,0,0,0,111,114,6,5,-1,0,112,113,5,31,0,0,113,115,6,5,-1,0,114,112,
  	1,0,0,0,114,115,1,0,0,0,115,118,1,0,0,0,116,117,5,32,0,0,117,119,6,5,
  	-1,0,118,116,1,0,0,0,118,119,1,0,0,0,119,122,1,0,0,0,120,121,5,33,0,0,
  	121,123,6,5,-1,0,122,120,1,0,0,0,122,123,1,0,0,0,123,124,1,0,0,0,124,
  	125,3,12,6,0,125,126,6,5,-1,0,126,130,5,20,0,0,127,128,3,14,7,0,128,129,
  	6,5,-1,0,129,131,1,0,0,0,130,127,1,0,0,0,130,131,1,0,0,0,131,132,1,0,
  	0,0,132,133,5,25,0,0,133,134,6,5,-1,0,134,11,1,0,0,0,135,136,3,18,9,0,
  	136,137,6,6,-1,0,137,13,1,0,0,0,138,157,6,7,-1,0,139,140,3,18,9,0,140,
  	141,6,7,-1,0,141,152,1,0,0,0,142,143,3,24,12,0,143,144,6,7,-1,0,144,152,
  	1,0,0,0,145,146,3,20,10,0,146,147,6,7,-1,0,147,152,1,0,0,0,148,149,3,
  	16,8,0,149,150,6,7,-1,0,150,152,1,0,0,0,151,139,1,0,0,0,151,142,1,0,0,
  	0,151,145,1,0,0,0,151,148,1,0,0,0,152,153,1,0,0,0,153,154,5,22,0,0,154,
  	156,1,0,0,0,155,151,1,0,0,0,156,159,1,0,0,0,157,155,1,0,0,0,157,158,1,
  	0,0,0,158,172,1,0,0,0,159,157,1,0,0,0,160,161,3,18,9,0,161,162,6,7,-1,
  	0,162,173,1,0,0,0,163,164,3,24,12,0,164,165,6,7,-1,0,165,173,1,0,0,0,
  	166,167,3,20,10,0,167,168,6,7,-1,0,168,173,1,0,0,0,169,170,3,16,8,0,170,
  	171,6,7,-1,0,171,173,1,0,0,0,172,160,1,0,0,0,172,163,1,0,0,0,172,166,
  	1,0,0,0,172,169,1,0,0,0,173,174,1,0,0,0,174,175,6,7,-1,0,175,15,1,0,0,
  	0,176,177,5,30,0,0,177,178,3,18,9,0,178,179,6,8,-1,0,179,17,1,0,0,0,180,
  	181,6,9,-1,0,181,182,5,19,0,0,182,183,6,9,-1,0,183,197,5,40,0,0,184,185,
  	5,19,0,0,185,198,6,9,-1,0,186,187,3,26,13,0,187,188,6,9,-1,0,188,198,
  	1,0,0,0,189,190,5,21,0,0,190,198,6,9,-1,0,191,192,3,40,20,0,192,193,6,
  	9,-1,0,193,198,1,0,0,0,194,195,3,22,11,0,195,196,6,9,-1,0,196,198,1,0,
  	0,0,197,184,1,0,0,0,197,186,1,0,0,0,197,189,1,0,0,0,197,191,1,0,0,0,197,
  	194,1,0,0,0,198,217,1,0,0,0,199,213,5,22,0,0,200,201,5,19,0,0,201,214,
  	6,9,-1,0,202,203,3,26,13,0,203,204,6,9,-1,0,204,214,1,0,0,0,205,206,5,
  	21,0,0,206,214,6,9,-1,0,207,208,3,40,20,0,208,209,6,9,-1,0,209,214,1,
  	0,0,0,210,211,3,22,11,0,211,212,6,9,-1,0,212,214,1,0,0,0,213,200,1,0,
  	0,0,213,202,1,0,0,0,213,205,1,0,0,0,213,207,1,0,0,0,213,210,1,0,0,0,214,
  	216,1,0,0,0,215,199,1,0,0,0,216,219,1,0,0,0,217,215,1,0,0,0,217,218,1,
  	0,0,0,218,220,1,0,0,0,219,217,1,0,0,0,220,221,5,41,0,0,221,222,6,9,-1,
  	0,222,19,1,0,0,0,223,224,6,10,-1,0,224,225,5,19,0,0,225,226,6,10,-1,0,
  	226,227,5,35,0,0,227,228,3,22,11,0,228,229,6,10,-1,0,229,230,6,10,-1,
  	0,230,21,1,0,0,0,231,232,6,11,-1,0,232,233,5,19,0,0,233,234,6,11,-1,0,
  	234,235,3,38,19,0,235,236,6,11,-1,0,236,237,5,19,0,0,237,238,6,11,-1,
  	0,238,239,6,11,-1,0,239,23,1,0,0,0,240,245,6,12,-1,0,241,242,5,19,0,0,
  	242,246,6,12,-1,0,243,244,5,4,0,0,244,246,6,12,-1,0,245,241,1,0,0,0,245,
  	243,1,0,0,0,246,247,1,0,0,0,247,248,3,34,17,0,248,253,6,12,-1,0,249,250,
  	5,19,0,0,250,254,6,12,-1,0,251,252,5,4,0,0,252,254,6,12,-1,0,253,249,
  	1,0,0,0,253,251,1,0,0,0,254,255,1,0,0,0,255,256,6,12,-1,0,256,25,1,0,
  	0,0,257,258,6,13,-1,0,258,259,3,36,18,0,259,260,6,13,-1,0,260,266,5,40,
  	0,0,261,262,5,19,0,0,262,267,6,13,-1,0,263,264,3,22,11,0,264,265,6,13,
  	-1,0,265,267,1,0,0,0,266,261,1,0,0,0,266,263,1,0,0,0,267,268,1,0,0,0,
  	268,269,5,41,0,0,269,270,6,13,-1,0,270,27,1,0,0,0,271,272,3,32,16,0,272,
  	273,6,14,-1,0,273,278,1,0,0,0,274,275,3,30,15,0,275,276,6,14,-1,0,276,
  	278,1,0,0,0,277,271,1,0,0,0,277,274,1,0,0,0,278,29,1,0,0,0,279,280,6,
  	15,-1,0,280,281,5,42,0,0,281,282,5,19,0,0,282,283,6,15,-1,0,283,284,5,
  	43,0,0,284,285,3,42,21,0,285,286,6,15,-1,0,286,287,6,15,-1,0,287,31,1,
  	0,0,0,288,289,6,16,-1,0,289,290,5,19,0,0,290,291,6,16,-1,0,291,292,3,
  	42,21,0,292,293,6,16,-1,0,293,294,6,16,-1,0,294,33,1,0,0,0,295,296,5,
  	34,0,0,296,308,6,17,-1,0,297,298,5,35,0,0,298,308,6,17,-1,0,299,300,5,
  	37,0,0,300,308,6,17,-1,0,301,302,5,36,0,0,302,308,6,17,-1,0,303,304,5,
  	39,0,0,304,308,6,17,-1,0,305,306,5,38,0,0,306,308,6,17,-1,0,307,295,1,
  	0,0,0,307,297,1,0,0,0,307,299,1,0,0,0,307,301,1,0,0,0,307,303,1,0,0,0,
  	307,305,1,0,0,0,308,35,1,0,0,0,309,310,5,14,0,0,310,320,6,18,-1,0,311,
  	312,5,15,0,0,312,320,6,18,-1,0,313,314,5,16,0,0,314,320,6,18,-1,0,315,
  	316,5,17,0,0,316,320,6,18,-1,0,317,318,5,18,0,0,318,320,6,18,-1,0,319,
  	309,1,0,0,0,319,311,1,0,0,0,319,313,1,0,0,0,319,315,1,0,0,0,319,317,1,
  	0,0,0,320,37,1,0,0,0,321,322,5,26,0,0,322,330,6,19,-1,0,323,324,5,27,
  	0,0,324,330,6,19,-1,0,325,326,5,28,0,0,326,330,6,19,-1,0,327,328,5,29,
  	0,0,328,330,6,19,-1,0,329,321,1,0,0,0,329,323,1,0,0,0,329,325,1,0,0,0,
  	329,327,1,0,0,0,330,39,1,0,0,0,331,332,5,4,0,0,332,336,6,20,-1,0,333,
  	334,5,5,0,0,334,336,6,20,-1,0,335,331,1,0,0,0,335,333,1,0,0,0,336,41,
  	1,0,0,0,337,338,5,6,0,0,338,354,6,21,-1,0,339,340,5,7,0,0,340,354,6,21,
  	-1,0,341,342,5,8,0,0,342,354,6,21,-1,0,343,344,5,9,0,0,344,354,6,21,-1,
  	0,345,346,5,10,0,0,346,354,6,21,-1,0,347,348,5,11,0,0,348,354,6,21,-1,
  	0,349,350,5,12,0,0,350,354,6,21,-1,0,351,352,5,13,0,0,352,354,6,21,-1,
  	0,353,337,1,0,0,0,353,339,1,0,0,0,353,341,1,0,0,0,353,343,1,0,0,0,353,
  	345,1,0,0,0,353,347,1,0,0,0,353,349,1,0,0,0,353,351,1,0,0,0,354,43,1,
  	0,0,0,23,54,69,86,106,114,118,122,130,151,157,172,197,213,217,245,253,
  	266,277,307,319,329,335,353
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mydatalogParserStaticData = staticData.release();
}

}

MyDatalogParser::MyDatalogParser(TokenStream *input) : MyDatalogParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MyDatalogParser::MyDatalogParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MyDatalogParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mydatalogParserStaticData->atn, mydatalogParserStaticData->decisionToDFA, mydatalogParserStaticData->sharedContextCache, options);
}

MyDatalogParser::~MyDatalogParser() {
  delete _interpreter;
}

const atn::ATN& MyDatalogParser::getATN() const {
  return *mydatalogParserStaticData->atn;
}

std::string MyDatalogParser::getGrammarFileName() const {
  return "MyDatalog.g4";
}

const std::vector<std::string>& MyDatalogParser::getRuleNames() const {
  return mydatalogParserStaticData->ruleNames;
}

const dfa::Vocabulary& MyDatalogParser::getVocabulary() const {
  return mydatalogParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MyDatalogParser::getSerializedATN() const {
  return mydatalogParserStaticData->serializedATN;
}


//----------------- Datalog_edb_declareContext ------------------------------------------------------------------

MyDatalogParser::Datalog_edb_declareContext::Datalog_edb_declareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Datalog_edb_declareContext::TOKEN_EDB() {
  return getToken(MyDatalogParser::TOKEN_EDB, 0);
}

tree::TerminalNode* MyDatalogParser::Datalog_edb_declareContext::TOKEN_COLON() {
  return getToken(MyDatalogParser::TOKEN_COLON, 0);
}

std::vector<MyDatalogParser::Datalog_relation_schemaContext *> MyDatalogParser::Datalog_edb_declareContext::datalog_relation_schema() {
  return getRuleContexts<MyDatalogParser::Datalog_relation_schemaContext>();
}

MyDatalogParser::Datalog_relation_schemaContext* MyDatalogParser::Datalog_edb_declareContext::datalog_relation_schema(size_t i) {
  return getRuleContext<MyDatalogParser::Datalog_relation_schemaContext>(i);
}


size_t MyDatalogParser::Datalog_edb_declareContext::getRuleIndex() const {
  return MyDatalogParser::RuleDatalog_edb_declare;
}


MyDatalogParser::Datalog_edb_declareContext* MyDatalogParser::datalog_edb_declare() {
  Datalog_edb_declareContext *_localctx = _tracker.createInstance<Datalog_edb_declareContext>(_ctx, getState());
  enterRule(_localctx, 0, MyDatalogParser::RuleDatalog_edb_declare);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    vector<Schema> edb_list;
    setState(45);
    match(MyDatalogParser::TOKEN_EDB);
    setState(46);
    match(MyDatalogParser::TOKEN_COLON);
    setState(47);
    antlrcpp::downCast<Datalog_edb_declareContext *>(_localctx)->schema1 = datalog_relation_schema();
    edb_list.emplace_back(antlrcpp::downCast<Datalog_edb_declareContext *>(_localctx)->schema1->r);
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyDatalogParser::TOKEN_ID) {
      setState(49);
      antlrcpp::downCast<Datalog_edb_declareContext *>(_localctx)->schema2 = datalog_relation_schema();
      edb_list.emplace_back(antlrcpp::downCast<Datalog_edb_declareContext *>(_localctx)->schema2->r);
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    antlrcpp::downCast<Datalog_edb_declareContext *>(_localctx)->r =  edb_list;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Datalog_idb_declareContext ------------------------------------------------------------------

MyDatalogParser::Datalog_idb_declareContext::Datalog_idb_declareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Datalog_idb_declareContext::TOKEN_IDB() {
  return getToken(MyDatalogParser::TOKEN_IDB, 0);
}

tree::TerminalNode* MyDatalogParser::Datalog_idb_declareContext::TOKEN_COLON() {
  return getToken(MyDatalogParser::TOKEN_COLON, 0);
}

std::vector<MyDatalogParser::Datalog_relation_schemaContext *> MyDatalogParser::Datalog_idb_declareContext::datalog_relation_schema() {
  return getRuleContexts<MyDatalogParser::Datalog_relation_schemaContext>();
}

MyDatalogParser::Datalog_relation_schemaContext* MyDatalogParser::Datalog_idb_declareContext::datalog_relation_schema(size_t i) {
  return getRuleContext<MyDatalogParser::Datalog_relation_schemaContext>(i);
}


size_t MyDatalogParser::Datalog_idb_declareContext::getRuleIndex() const {
  return MyDatalogParser::RuleDatalog_idb_declare;
}


MyDatalogParser::Datalog_idb_declareContext* MyDatalogParser::datalog_idb_declare() {
  Datalog_idb_declareContext *_localctx = _tracker.createInstance<Datalog_idb_declareContext>(_ctx, getState());
  enterRule(_localctx, 2, MyDatalogParser::RuleDatalog_idb_declare);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    vector<Schema> idb_list;
    setState(60);
    match(MyDatalogParser::TOKEN_IDB);
    setState(61);
    match(MyDatalogParser::TOKEN_COLON);
    setState(62);
    antlrcpp::downCast<Datalog_idb_declareContext *>(_localctx)->schema1 = datalog_relation_schema();
    idb_list.emplace_back(antlrcpp::downCast<Datalog_idb_declareContext *>(_localctx)->schema1->r);
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyDatalogParser::TOKEN_ID) {
      setState(64);
      antlrcpp::downCast<Datalog_idb_declareContext *>(_localctx)->schema2 = datalog_relation_schema();
      idb_list.emplace_back(antlrcpp::downCast<Datalog_idb_declareContext *>(_localctx)->schema2->r);
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    antlrcpp::downCast<Datalog_idb_declareContext *>(_localctx)->r =  idb_list;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Datalog_relation_schemaContext ------------------------------------------------------------------

MyDatalogParser::Datalog_relation_schemaContext::Datalog_relation_schemaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Datalog_relation_schemaContext::TOKEN_LEFT_PAREN() {
  return getToken(MyDatalogParser::TOKEN_LEFT_PAREN, 0);
}

tree::TerminalNode* MyDatalogParser::Datalog_relation_schemaContext::TOKEN_RIGHT_PAREN() {
  return getToken(MyDatalogParser::TOKEN_RIGHT_PAREN, 0);
}

tree::TerminalNode* MyDatalogParser::Datalog_relation_schemaContext::TOKEN_ID() {
  return getToken(MyDatalogParser::TOKEN_ID, 0);
}

std::vector<MyDatalogParser::AttributeContext *> MyDatalogParser::Datalog_relation_schemaContext::attribute() {
  return getRuleContexts<MyDatalogParser::AttributeContext>();
}

MyDatalogParser::AttributeContext* MyDatalogParser::Datalog_relation_schemaContext::attribute(size_t i) {
  return getRuleContext<MyDatalogParser::AttributeContext>(i);
}

std::vector<tree::TerminalNode *> MyDatalogParser::Datalog_relation_schemaContext::TOKEN_COMMA() {
  return getTokens(MyDatalogParser::TOKEN_COMMA);
}

tree::TerminalNode* MyDatalogParser::Datalog_relation_schemaContext::TOKEN_COMMA(size_t i) {
  return getToken(MyDatalogParser::TOKEN_COMMA, i);
}


size_t MyDatalogParser::Datalog_relation_schemaContext::getRuleIndex() const {
  return MyDatalogParser::RuleDatalog_relation_schema;
}


MyDatalogParser::Datalog_relation_schemaContext* MyDatalogParser::datalog_relation_schema() {
  Datalog_relation_schemaContext *_localctx = _tracker.createInstance<Datalog_relation_schemaContext>(_ctx, getState());
  enterRule(_localctx, 4, MyDatalogParser::RuleDatalog_relation_schema);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    Schema schema;
    setState(75);
    antlrcpp::downCast<Datalog_relation_schemaContext *>(_localctx)->relation_name = match(MyDatalogParser::TOKEN_ID);
    schema.name = (antlrcpp::downCast<Datalog_relation_schemaContext *>(_localctx)->relation_name != nullptr ? antlrcpp::downCast<Datalog_relation_schemaContext *>(_localctx)->relation_name->getText() : "");
    setState(77);
    match(MyDatalogParser::TOKEN_LEFT_PAREN);
    setState(78);
    antlrcpp::downCast<Datalog_relation_schemaContext *>(_localctx)->t1 = attribute();
    schema.attributes.emplace_back(antlrcpp::downCast<Datalog_relation_schemaContext *>(_localctx)->t1->r);
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyDatalogParser::TOKEN_COMMA) {
      setState(80);
      match(MyDatalogParser::TOKEN_COMMA);
      setState(81);
      antlrcpp::downCast<Datalog_relation_schemaContext *>(_localctx)->t2 = attribute();
      schema.attributes.emplace_back(antlrcpp::downCast<Datalog_relation_schemaContext *>(_localctx)->t2->r);
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(89);
    match(MyDatalogParser::TOKEN_RIGHT_PAREN);
    antlrcpp::downCast<Datalog_relation_schemaContext *>(_localctx)->r =  schema;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Datalog_rule_declareContext ------------------------------------------------------------------

MyDatalogParser::Datalog_rule_declareContext::Datalog_rule_declareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Datalog_rule_declareContext::TOKEN_RULE() {
  return getToken(MyDatalogParser::TOKEN_RULE, 0);
}

tree::TerminalNode* MyDatalogParser::Datalog_rule_declareContext::TOKEN_COLON() {
  return getToken(MyDatalogParser::TOKEN_COLON, 0);
}

tree::TerminalNode* MyDatalogParser::Datalog_rule_declareContext::EOF() {
  return getToken(MyDatalogParser::EOF, 0);
}

MyDatalogParser::Datalog_programContext* MyDatalogParser::Datalog_rule_declareContext::datalog_program() {
  return getRuleContext<MyDatalogParser::Datalog_programContext>(0);
}


size_t MyDatalogParser::Datalog_rule_declareContext::getRuleIndex() const {
  return MyDatalogParser::RuleDatalog_rule_declare;
}


MyDatalogParser::Datalog_rule_declareContext* MyDatalogParser::datalog_rule_declare() {
  Datalog_rule_declareContext *_localctx = _tracker.createInstance<Datalog_rule_declareContext>(_ctx, getState());
  enterRule(_localctx, 6, MyDatalogParser::RuleDatalog_rule_declare);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(MyDatalogParser::TOKEN_RULE);
    setState(93);
    match(MyDatalogParser::TOKEN_COLON);
    setState(94);
    antlrcpp::downCast<Datalog_rule_declareContext *>(_localctx)->dp = datalog_program();
    antlrcpp::downCast<Datalog_rule_declareContext *>(_localctx)->r =  antlrcpp::downCast<Datalog_rule_declareContext *>(_localctx)->dp->r;
    setState(96);
    match(MyDatalogParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Datalog_programContext ------------------------------------------------------------------

MyDatalogParser::Datalog_programContext::Datalog_programContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MyDatalogParser::Datalog_ruleContext *> MyDatalogParser::Datalog_programContext::datalog_rule() {
  return getRuleContexts<MyDatalogParser::Datalog_ruleContext>();
}

MyDatalogParser::Datalog_ruleContext* MyDatalogParser::Datalog_programContext::datalog_rule(size_t i) {
  return getRuleContext<MyDatalogParser::Datalog_ruleContext>(i);
}


size_t MyDatalogParser::Datalog_programContext::getRuleIndex() const {
  return MyDatalogParser::RuleDatalog_program;
}


MyDatalogParser::Datalog_programContext* MyDatalogParser::datalog_program() {
  Datalog_programContext *_localctx = _tracker.createInstance<Datalog_programContext>(_ctx, getState());
  enterRule(_localctx, 8, MyDatalogParser::RuleDatalog_program);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    vector<RuleMap> rule_list;
    setState(99);
    antlrcpp::downCast<Datalog_programContext *>(_localctx)->r1 = datalog_rule();
    rule_list.emplace_back(antlrcpp::downCast<Datalog_programContext *>(_localctx)->r1->r);
    setState(106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15032909824) != 0) {
      setState(101);
      antlrcpp::downCast<Datalog_programContext *>(_localctx)->r2 = datalog_rule();
      rule_list.emplace_back(antlrcpp::downCast<Datalog_programContext *>(_localctx)->r2->r);
      setState(108);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    antlrcpp::downCast<Datalog_programContext *>(_localctx)->r =  rule_list;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Datalog_ruleContext ------------------------------------------------------------------

MyDatalogParser::Datalog_ruleContext::Datalog_ruleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Datalog_ruleContext::TOKEN_BODY_HEAD_SEP() {
  return getToken(MyDatalogParser::TOKEN_BODY_HEAD_SEP, 0);
}

tree::TerminalNode* MyDatalogParser::Datalog_ruleContext::TOKEN_DOT() {
  return getToken(MyDatalogParser::TOKEN_DOT, 0);
}

MyDatalogParser::HeadContext* MyDatalogParser::Datalog_ruleContext::head() {
  return getRuleContext<MyDatalogParser::HeadContext>(0);
}

tree::TerminalNode* MyDatalogParser::Datalog_ruleContext::TOKEN_NON_DEDUP() {
  return getToken(MyDatalogParser::TOKEN_NON_DEDUP, 0);
}

tree::TerminalNode* MyDatalogParser::Datalog_ruleContext::TOKEN_NON_SET_DIFF() {
  return getToken(MyDatalogParser::TOKEN_NON_SET_DIFF, 0);
}

tree::TerminalNode* MyDatalogParser::Datalog_ruleContext::TOKEN_DEDUP_ONLY() {
  return getToken(MyDatalogParser::TOKEN_DEDUP_ONLY, 0);
}

MyDatalogParser::BodyContext* MyDatalogParser::Datalog_ruleContext::body() {
  return getRuleContext<MyDatalogParser::BodyContext>(0);
}


size_t MyDatalogParser::Datalog_ruleContext::getRuleIndex() const {
  return MyDatalogParser::RuleDatalog_rule;
}


MyDatalogParser::Datalog_ruleContext* MyDatalogParser::datalog_rule() {
  Datalog_ruleContext *_localctx = _tracker.createInstance<Datalog_ruleContext>(_ctx, getState());
  enterRule(_localctx, 10, MyDatalogParser::RuleDatalog_rule);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    RuleMap rule_map;
    setState(114);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyDatalogParser::TOKEN_NON_DEDUP) {
      setState(112);
      match(MyDatalogParser::TOKEN_NON_DEDUP);
      rule_map.nonDedup = true;
    }
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyDatalogParser::TOKEN_NON_SET_DIFF) {
      setState(116);
      match(MyDatalogParser::TOKEN_NON_SET_DIFF);
      rule_map.nonSetDiff = true;
    }
    setState(122);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MyDatalogParser::TOKEN_DEDUP_ONLY) {
      setState(120);
      match(MyDatalogParser::TOKEN_DEDUP_ONLY);
      rule_map.dedupOnly = true;
    }
    setState(124);
    antlrcpp::downCast<Datalog_ruleContext *>(_localctx)->h = head();
    rule_map.head = antlrcpp::downCast<Datalog_ruleContext *>(_localctx)->h->r;
    setState(126);
    match(MyDatalogParser::TOKEN_BODY_HEAD_SEP);
    setState(130);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1074266128) != 0) {
      setState(127);
      antlrcpp::downCast<Datalog_ruleContext *>(_localctx)->b = body();
      rule_map.body = antlrcpp::downCast<Datalog_ruleContext *>(_localctx)->b->r;
    }
    setState(132);
    match(MyDatalogParser::TOKEN_DOT);
    antlrcpp::downCast<Datalog_ruleContext *>(_localctx)->r =  rule_map;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeadContext ------------------------------------------------------------------

MyDatalogParser::HeadContext::HeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyDatalogParser::AtomContext* MyDatalogParser::HeadContext::atom() {
  return getRuleContext<MyDatalogParser::AtomContext>(0);
}


size_t MyDatalogParser::HeadContext::getRuleIndex() const {
  return MyDatalogParser::RuleHead;
}


MyDatalogParser::HeadContext* MyDatalogParser::head() {
  HeadContext *_localctx = _tracker.createInstance<HeadContext>(_ctx, getState());
  enterRule(_localctx, 12, MyDatalogParser::RuleHead);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    antlrcpp::downCast<HeadContext *>(_localctx)->a = atom();
    antlrcpp::downCast<HeadContext *>(_localctx)->r =  antlrcpp::downCast<HeadContext *>(_localctx)->a->r;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

MyDatalogParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MyDatalogParser::BodyContext::TOKEN_COMMA() {
  return getTokens(MyDatalogParser::TOKEN_COMMA);
}

tree::TerminalNode* MyDatalogParser::BodyContext::TOKEN_COMMA(size_t i) {
  return getToken(MyDatalogParser::TOKEN_COMMA, i);
}

std::vector<MyDatalogParser::AtomContext *> MyDatalogParser::BodyContext::atom() {
  return getRuleContexts<MyDatalogParser::AtomContext>();
}

MyDatalogParser::AtomContext* MyDatalogParser::BodyContext::atom(size_t i) {
  return getRuleContext<MyDatalogParser::AtomContext>(i);
}

std::vector<MyDatalogParser::Compare_exprContext *> MyDatalogParser::BodyContext::compare_expr() {
  return getRuleContexts<MyDatalogParser::Compare_exprContext>();
}

MyDatalogParser::Compare_exprContext* MyDatalogParser::BodyContext::compare_expr(size_t i) {
  return getRuleContext<MyDatalogParser::Compare_exprContext>(i);
}

std::vector<MyDatalogParser::AssignContext *> MyDatalogParser::BodyContext::assign() {
  return getRuleContexts<MyDatalogParser::AssignContext>();
}

MyDatalogParser::AssignContext* MyDatalogParser::BodyContext::assign(size_t i) {
  return getRuleContext<MyDatalogParser::AssignContext>(i);
}

std::vector<MyDatalogParser::NegationContext *> MyDatalogParser::BodyContext::negation() {
  return getRuleContexts<MyDatalogParser::NegationContext>();
}

MyDatalogParser::NegationContext* MyDatalogParser::BodyContext::negation(size_t i) {
  return getRuleContext<MyDatalogParser::NegationContext>(i);
}


size_t MyDatalogParser::BodyContext::getRuleIndex() const {
  return MyDatalogParser::RuleBody;
}


MyDatalogParser::BodyContext* MyDatalogParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 14, MyDatalogParser::RuleBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    BodyMap body_map;
    setState(157);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(151);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          setState(139);
          antlrcpp::downCast<BodyContext *>(_localctx)->b1 = atom();
          body_map.atoms.emplace_back(antlrcpp::downCast<BodyContext *>(_localctx)->b1->r);
          break;
        }

        case 2: {
          setState(142);
          antlrcpp::downCast<BodyContext *>(_localctx)->b2 = compare_expr();
          body_map.compares.emplace_back(antlrcpp::downCast<BodyContext *>(_localctx)->b2->r);
          break;
        }

        case 3: {
          setState(145);
          antlrcpp::downCast<BodyContext *>(_localctx)->b3 = assign();
          body_map.assigns.emplace_back(antlrcpp::downCast<BodyContext *>(_localctx)->b3->r);
          break;
        }

        case 4: {
          setState(148);
          antlrcpp::downCast<BodyContext *>(_localctx)->b4 = negation();
          body_map.negations.emplace_back(antlrcpp::downCast<BodyContext *>(_localctx)->b4->r);
          break;
        }

        default:
          break;
        }
        setState(153);
        match(MyDatalogParser::TOKEN_COMMA); 
      }
      setState(159);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(172);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(160);
      antlrcpp::downCast<BodyContext *>(_localctx)->b5 = atom();
      body_map.atoms.emplace_back(antlrcpp::downCast<BodyContext *>(_localctx)->b5->r);
      break;
    }

    case 2: {
      setState(163);
      antlrcpp::downCast<BodyContext *>(_localctx)->b6 = compare_expr();
      body_map.compares.emplace_back(antlrcpp::downCast<BodyContext *>(_localctx)->b6->r);
      break;
    }

    case 3: {
      setState(166);
      antlrcpp::downCast<BodyContext *>(_localctx)->b7 = assign();
      body_map.assigns.emplace_back(antlrcpp::downCast<BodyContext *>(_localctx)->b7->r);
      break;
    }

    case 4: {
      setState(169);
      antlrcpp::downCast<BodyContext *>(_localctx)->b8 = negation();
      body_map.negations.emplace_back(antlrcpp::downCast<BodyContext *>(_localctx)->b8->r);
      break;
    }

    default:
      break;
    }
    antlrcpp::downCast<BodyContext *>(_localctx)->r =  body_map;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NegationContext ------------------------------------------------------------------

MyDatalogParser::NegationContext::NegationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::NegationContext::TOKEN_NOT() {
  return getToken(MyDatalogParser::TOKEN_NOT, 0);
}

MyDatalogParser::AtomContext* MyDatalogParser::NegationContext::atom() {
  return getRuleContext<MyDatalogParser::AtomContext>(0);
}


size_t MyDatalogParser::NegationContext::getRuleIndex() const {
  return MyDatalogParser::RuleNegation;
}


MyDatalogParser::NegationContext* MyDatalogParser::negation() {
  NegationContext *_localctx = _tracker.createInstance<NegationContext>(_ctx, getState());
  enterRule(_localctx, 16, MyDatalogParser::RuleNegation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(MyDatalogParser::TOKEN_NOT);
    setState(177);
    antlrcpp::downCast<NegationContext *>(_localctx)->a = atom();
    antlrcpp::downCast<NegationContext *>(_localctx)->r =  antlrcpp::downCast<NegationContext *>(_localctx)->a->r;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

MyDatalogParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::AtomContext::TOKEN_LEFT_PAREN() {
  return getToken(MyDatalogParser::TOKEN_LEFT_PAREN, 0);
}

tree::TerminalNode* MyDatalogParser::AtomContext::TOKEN_RIGHT_PAREN() {
  return getToken(MyDatalogParser::TOKEN_RIGHT_PAREN, 0);
}

std::vector<tree::TerminalNode *> MyDatalogParser::AtomContext::TOKEN_ID() {
  return getTokens(MyDatalogParser::TOKEN_ID);
}

tree::TerminalNode* MyDatalogParser::AtomContext::TOKEN_ID(size_t i) {
  return getToken(MyDatalogParser::TOKEN_ID, i);
}

std::vector<MyDatalogParser::Aggregation_exprContext *> MyDatalogParser::AtomContext::aggregation_expr() {
  return getRuleContexts<MyDatalogParser::Aggregation_exprContext>();
}

MyDatalogParser::Aggregation_exprContext* MyDatalogParser::AtomContext::aggregation_expr(size_t i) {
  return getRuleContext<MyDatalogParser::Aggregation_exprContext>(i);
}

std::vector<tree::TerminalNode *> MyDatalogParser::AtomContext::TOKEN_ANY() {
  return getTokens(MyDatalogParser::TOKEN_ANY);
}

tree::TerminalNode* MyDatalogParser::AtomContext::TOKEN_ANY(size_t i) {
  return getToken(MyDatalogParser::TOKEN_ANY, i);
}

std::vector<MyDatalogParser::ConstantContext *> MyDatalogParser::AtomContext::constant() {
  return getRuleContexts<MyDatalogParser::ConstantContext>();
}

MyDatalogParser::ConstantContext* MyDatalogParser::AtomContext::constant(size_t i) {
  return getRuleContext<MyDatalogParser::ConstantContext>(i);
}

std::vector<MyDatalogParser::Math_exprContext *> MyDatalogParser::AtomContext::math_expr() {
  return getRuleContexts<MyDatalogParser::Math_exprContext>();
}

MyDatalogParser::Math_exprContext* MyDatalogParser::AtomContext::math_expr(size_t i) {
  return getRuleContext<MyDatalogParser::Math_exprContext>(i);
}

std::vector<tree::TerminalNode *> MyDatalogParser::AtomContext::TOKEN_COMMA() {
  return getTokens(MyDatalogParser::TOKEN_COMMA);
}

tree::TerminalNode* MyDatalogParser::AtomContext::TOKEN_COMMA(size_t i) {
  return getToken(MyDatalogParser::TOKEN_COMMA, i);
}


size_t MyDatalogParser::AtomContext::getRuleIndex() const {
  return MyDatalogParser::RuleAtom;
}


MyDatalogParser::AtomContext* MyDatalogParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 18, MyDatalogParser::RuleAtom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    AtomMap atom_map;
    setState(181);
    antlrcpp::downCast<AtomContext *>(_localctx)->a1 = match(MyDatalogParser::TOKEN_ID);
    atom_map.name = (antlrcpp::downCast<AtomContext *>(_localctx)->a1 != nullptr ? antlrcpp::downCast<AtomContext *>(_localctx)->a1->getText() : "");
    setState(183);
    match(MyDatalogParser::TOKEN_LEFT_PAREN);
    setState(197);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(184);
      antlrcpp::downCast<AtomContext *>(_localctx)->a2 = match(MyDatalogParser::TOKEN_ID);
      atom_map.argList.emplace_back(AtomArg((antlrcpp::downCast<AtomContext *>(_localctx)->a2 != nullptr ? antlrcpp::downCast<AtomContext *>(_localctx)->a2->getText() : ""), "variable", false));
      break;
    }

    case 2: {
      setState(186);
      antlrcpp::downCast<AtomContext *>(_localctx)->a3 = aggregation_expr();
      atom_map.argList.emplace_back(AtomArg(antlrcpp::downCast<AtomContext *>(_localctx)->a3->r, "aggregation", false));
      break;
    }

    case 3: {
      setState(189);
      antlrcpp::downCast<AtomContext *>(_localctx)->a4 = match(MyDatalogParser::TOKEN_ANY);
      atom_map.argList.emplace_back(AtomArg((antlrcpp::downCast<AtomContext *>(_localctx)->a4 != nullptr ? antlrcpp::downCast<AtomContext *>(_localctx)->a4->getText() : ""), "any", false));
      break;
    }

    case 4: {
      setState(191);
      antlrcpp::downCast<AtomContext *>(_localctx)->a5 = constant();
      atom_map.argList.emplace_back(AtomArg((antlrcpp::downCast<AtomContext *>(_localctx)->a5 != nullptr ? _input->getText(antlrcpp::downCast<AtomContext *>(_localctx)->a5->start, antlrcpp::downCast<AtomContext *>(_localctx)->a5->stop) : nullptr), "constant", false));
      break;
    }

    case 5: {
      setState(194);
      antlrcpp::downCast<AtomContext *>(_localctx)->a6 = math_expr();
      atom_map.argList.emplace_back(AtomArg(antlrcpp::downCast<AtomContext *>(_localctx)->a6->r, "math_expr", false));
      break;
    }

    default:
      break;
    }
    setState(217);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MyDatalogParser::TOKEN_COMMA) {
      setState(199);
      match(MyDatalogParser::TOKEN_COMMA);
      setState(213);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(200);
        antlrcpp::downCast<AtomContext *>(_localctx)->a7 = match(MyDatalogParser::TOKEN_ID);
        atom_map.argList.emplace_back(AtomArg((antlrcpp::downCast<AtomContext *>(_localctx)->a7 != nullptr ? antlrcpp::downCast<AtomContext *>(_localctx)->a7->getText() : ""), "variable", false));
        break;
      }

      case 2: {
        setState(202);
        antlrcpp::downCast<AtomContext *>(_localctx)->a8 = aggregation_expr();
        atom_map.argList.emplace_back(AtomArg(antlrcpp::downCast<AtomContext *>(_localctx)->a8->r, "aggregation", false));
        break;
      }

      case 3: {
        setState(205);
        antlrcpp::downCast<AtomContext *>(_localctx)->a9 = match(MyDatalogParser::TOKEN_ANY);
        atom_map.argList.emplace_back(AtomArg((antlrcpp::downCast<AtomContext *>(_localctx)->a9 != nullptr ? antlrcpp::downCast<AtomContext *>(_localctx)->a9->getText() : ""), "any", false));
        break;
      }

      case 4: {
        setState(207);
        antlrcpp::downCast<AtomContext *>(_localctx)->a10 = constant();
        atom_map.argList.emplace_back(AtomArg((antlrcpp::downCast<AtomContext *>(_localctx)->a10 != nullptr ? _input->getText(antlrcpp::downCast<AtomContext *>(_localctx)->a10->start, antlrcpp::downCast<AtomContext *>(_localctx)->a10->stop) : nullptr), "constant", false));
        break;
      }

      case 5: {
        setState(210);
        antlrcpp::downCast<AtomContext *>(_localctx)->a11 = math_expr();
        atom_map.argList.emplace_back(AtomArg(antlrcpp::downCast<AtomContext *>(_localctx)->a11->r, "math_expr", false));
        break;
      }

      default:
        break;
      }
      setState(219);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(220);
    match(MyDatalogParser::TOKEN_RIGHT_PAREN);
    antlrcpp::downCast<AtomContext *>(_localctx)->r =  atom_map;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

MyDatalogParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::AssignContext::TOKEN_EQUALS() {
  return getToken(MyDatalogParser::TOKEN_EQUALS, 0);
}

tree::TerminalNode* MyDatalogParser::AssignContext::TOKEN_ID() {
  return getToken(MyDatalogParser::TOKEN_ID, 0);
}

MyDatalogParser::Math_exprContext* MyDatalogParser::AssignContext::math_expr() {
  return getRuleContext<MyDatalogParser::Math_exprContext>(0);
}


size_t MyDatalogParser::AssignContext::getRuleIndex() const {
  return MyDatalogParser::RuleAssign;
}


MyDatalogParser::AssignContext* MyDatalogParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 20, MyDatalogParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    AssignMap assign_map;
    setState(224);
    antlrcpp::downCast<AssignContext *>(_localctx)->a1 = match(MyDatalogParser::TOKEN_ID);
    assign_map.lhs = (antlrcpp::downCast<AssignContext *>(_localctx)->a1 != nullptr ? antlrcpp::downCast<AssignContext *>(_localctx)->a1->getText() : "");
    setState(226);
    match(MyDatalogParser::TOKEN_EQUALS);
    setState(227);
    antlrcpp::downCast<AssignContext *>(_localctx)->a2 = math_expr();
    assign_map.rhs = antlrcpp::downCast<AssignContext *>(_localctx)->a2->r;
    antlrcpp::downCast<AssignContext *>(_localctx)->r =  assign_map;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Math_exprContext ------------------------------------------------------------------

MyDatalogParser::Math_exprContext::Math_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MyDatalogParser::Math_exprContext::TOKEN_ID() {
  return getTokens(MyDatalogParser::TOKEN_ID);
}

tree::TerminalNode* MyDatalogParser::Math_exprContext::TOKEN_ID(size_t i) {
  return getToken(MyDatalogParser::TOKEN_ID, i);
}

MyDatalogParser::Math_opContext* MyDatalogParser::Math_exprContext::math_op() {
  return getRuleContext<MyDatalogParser::Math_opContext>(0);
}


size_t MyDatalogParser::Math_exprContext::getRuleIndex() const {
  return MyDatalogParser::RuleMath_expr;
}


MyDatalogParser::Math_exprContext* MyDatalogParser::math_expr() {
  Math_exprContext *_localctx = _tracker.createInstance<Math_exprContext>(_ctx, getState());
  enterRule(_localctx, 22, MyDatalogParser::RuleMath_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    MathMap math_map;
    setState(232);
    antlrcpp::downCast<Math_exprContext *>(_localctx)->m1 = match(MyDatalogParser::TOKEN_ID);
    math_map.lhs = (antlrcpp::downCast<Math_exprContext *>(_localctx)->m1 != nullptr ? antlrcpp::downCast<Math_exprContext *>(_localctx)->m1->getText() : "");
    setState(234);
    antlrcpp::downCast<Math_exprContext *>(_localctx)->m2 = math_op();
    math_map.op = (antlrcpp::downCast<Math_exprContext *>(_localctx)->m2 != nullptr ? _input->getText(antlrcpp::downCast<Math_exprContext *>(_localctx)->m2->start, antlrcpp::downCast<Math_exprContext *>(_localctx)->m2->stop) : nullptr);
    setState(236);
    antlrcpp::downCast<Math_exprContext *>(_localctx)->m3 = match(MyDatalogParser::TOKEN_ID);
    math_map.rhs = (antlrcpp::downCast<Math_exprContext *>(_localctx)->m3 != nullptr ? antlrcpp::downCast<Math_exprContext *>(_localctx)->m3->getText() : "");
    antlrcpp::downCast<Math_exprContext *>(_localctx)->r =  math_map;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compare_exprContext ------------------------------------------------------------------

MyDatalogParser::Compare_exprContext::Compare_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyDatalogParser::Compare_opContext* MyDatalogParser::Compare_exprContext::compare_op() {
  return getRuleContext<MyDatalogParser::Compare_opContext>(0);
}

std::vector<tree::TerminalNode *> MyDatalogParser::Compare_exprContext::TOKEN_ID() {
  return getTokens(MyDatalogParser::TOKEN_ID);
}

tree::TerminalNode* MyDatalogParser::Compare_exprContext::TOKEN_ID(size_t i) {
  return getToken(MyDatalogParser::TOKEN_ID, i);
}

std::vector<tree::TerminalNode *> MyDatalogParser::Compare_exprContext::TOKEN_INTEGER() {
  return getTokens(MyDatalogParser::TOKEN_INTEGER);
}

tree::TerminalNode* MyDatalogParser::Compare_exprContext::TOKEN_INTEGER(size_t i) {
  return getToken(MyDatalogParser::TOKEN_INTEGER, i);
}


size_t MyDatalogParser::Compare_exprContext::getRuleIndex() const {
  return MyDatalogParser::RuleCompare_expr;
}


MyDatalogParser::Compare_exprContext* MyDatalogParser::compare_expr() {
  Compare_exprContext *_localctx = _tracker.createInstance<Compare_exprContext>(_ctx, getState());
  enterRule(_localctx, 24, MyDatalogParser::RuleCompare_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    CompareMap compare_map;
    setState(245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyDatalogParser::TOKEN_ID: {
        setState(241);
        antlrcpp::downCast<Compare_exprContext *>(_localctx)->c1 = match(MyDatalogParser::TOKEN_ID);
        compare_map.lhsText = (antlrcpp::downCast<Compare_exprContext *>(_localctx)->c1 != nullptr ? antlrcpp::downCast<Compare_exprContext *>(_localctx)->c1->getText() : ""); compare_map.lhsType = "var";
        break;
      }

      case MyDatalogParser::TOKEN_INTEGER: {
        setState(243);
        antlrcpp::downCast<Compare_exprContext *>(_localctx)->c2 = match(MyDatalogParser::TOKEN_INTEGER);
        compare_map.lhsText = (antlrcpp::downCast<Compare_exprContext *>(_localctx)->c2 != nullptr ? antlrcpp::downCast<Compare_exprContext *>(_localctx)->c2->getText() : ""); compare_map.lhsType = "num";
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(247);
    antlrcpp::downCast<Compare_exprContext *>(_localctx)->op = compare_op();
    compare_map.op = antlrcpp::downCast<Compare_exprContext *>(_localctx)->op->r;
    setState(253);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyDatalogParser::TOKEN_ID: {
        setState(249);
        antlrcpp::downCast<Compare_exprContext *>(_localctx)->c3 = match(MyDatalogParser::TOKEN_ID);
        compare_map.rhsText = (antlrcpp::downCast<Compare_exprContext *>(_localctx)->c3 != nullptr ? antlrcpp::downCast<Compare_exprContext *>(_localctx)->c3->getText() : ""); compare_map.rhsType = "var";
        break;
      }

      case MyDatalogParser::TOKEN_INTEGER: {
        setState(251);
        antlrcpp::downCast<Compare_exprContext *>(_localctx)->c4 = match(MyDatalogParser::TOKEN_INTEGER);
        compare_map.rhsText = (antlrcpp::downCast<Compare_exprContext *>(_localctx)->c4 != nullptr ? antlrcpp::downCast<Compare_exprContext *>(_localctx)->c4->getText() : ""); compare_map.rhsType = "num";
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    antlrcpp::downCast<Compare_exprContext *>(_localctx)->r =  compare_map;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Aggregation_exprContext ------------------------------------------------------------------

MyDatalogParser::Aggregation_exprContext::Aggregation_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Aggregation_exprContext::TOKEN_LEFT_PAREN() {
  return getToken(MyDatalogParser::TOKEN_LEFT_PAREN, 0);
}

tree::TerminalNode* MyDatalogParser::Aggregation_exprContext::TOKEN_RIGHT_PAREN() {
  return getToken(MyDatalogParser::TOKEN_RIGHT_PAREN, 0);
}

MyDatalogParser::Aggregation_opContext* MyDatalogParser::Aggregation_exprContext::aggregation_op() {
  return getRuleContext<MyDatalogParser::Aggregation_opContext>(0);
}

tree::TerminalNode* MyDatalogParser::Aggregation_exprContext::TOKEN_ID() {
  return getToken(MyDatalogParser::TOKEN_ID, 0);
}

MyDatalogParser::Math_exprContext* MyDatalogParser::Aggregation_exprContext::math_expr() {
  return getRuleContext<MyDatalogParser::Math_exprContext>(0);
}


size_t MyDatalogParser::Aggregation_exprContext::getRuleIndex() const {
  return MyDatalogParser::RuleAggregation_expr;
}


MyDatalogParser::Aggregation_exprContext* MyDatalogParser::aggregation_expr() {
  Aggregation_exprContext *_localctx = _tracker.createInstance<Aggregation_exprContext>(_ctx, getState());
  enterRule(_localctx, 26, MyDatalogParser::RuleAggregation_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    AggMap agg_map;
    setState(258);
    antlrcpp::downCast<Aggregation_exprContext *>(_localctx)->a1 = aggregation_op();
    agg_map.aggOp = antlrcpp::downCast<Aggregation_exprContext *>(_localctx)->a1->r;
    setState(260);
    match(MyDatalogParser::TOKEN_LEFT_PAREN);
    setState(266);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(261);
      antlrcpp::downCast<Aggregation_exprContext *>(_localctx)->a2 = match(MyDatalogParser::TOKEN_ID);
      agg_map.aggArg.type = "attribute", agg_map.aggArg.attr = (antlrcpp::downCast<Aggregation_exprContext *>(_localctx)->a2 != nullptr ? antlrcpp::downCast<Aggregation_exprContext *>(_localctx)->a2->getText() : "");
      break;
    }

    case 2: {
      setState(263);
      antlrcpp::downCast<Aggregation_exprContext *>(_localctx)->a3 = math_expr();
      agg_map.aggArg.type = "math_expr", agg_map.aggArg.mathExpr = antlrcpp::downCast<Aggregation_exprContext *>(_localctx)->a3->r;
      break;
    }

    default:
      break;
    }
    setState(268);
    match(MyDatalogParser::TOKEN_RIGHT_PAREN);
    antlrcpp::downCast<Aggregation_exprContext *>(_localctx)->r =  agg_map;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeContext ------------------------------------------------------------------

MyDatalogParser::AttributeContext::AttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyDatalogParser::Non_key_attributeContext* MyDatalogParser::AttributeContext::non_key_attribute() {
  return getRuleContext<MyDatalogParser::Non_key_attributeContext>(0);
}

MyDatalogParser::Key_attributeContext* MyDatalogParser::AttributeContext::key_attribute() {
  return getRuleContext<MyDatalogParser::Key_attributeContext>(0);
}


size_t MyDatalogParser::AttributeContext::getRuleIndex() const {
  return MyDatalogParser::RuleAttribute;
}


MyDatalogParser::AttributeContext* MyDatalogParser::attribute() {
  AttributeContext *_localctx = _tracker.createInstance<AttributeContext>(_ctx, getState());
  enterRule(_localctx, 28, MyDatalogParser::RuleAttribute);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(277);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyDatalogParser::TOKEN_ID: {
        enterOuterAlt(_localctx, 1);
        setState(271);
        antlrcpp::downCast<AttributeContext *>(_localctx)->a1 = non_key_attribute();
        antlrcpp::downCast<AttributeContext *>(_localctx)->r =  antlrcpp::downCast<AttributeContext *>(_localctx)->a1->r;
        break;
      }

      case MyDatalogParser::TOKEN_LEFT_BRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(274);
        antlrcpp::downCast<AttributeContext *>(_localctx)->a2 = key_attribute();
        antlrcpp::downCast<AttributeContext *>(_localctx)->r =  antlrcpp::downCast<AttributeContext *>(_localctx)->a2->r;
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Key_attributeContext ------------------------------------------------------------------

MyDatalogParser::Key_attributeContext::Key_attributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Key_attributeContext::TOKEN_LEFT_BRACKET() {
  return getToken(MyDatalogParser::TOKEN_LEFT_BRACKET, 0);
}

tree::TerminalNode* MyDatalogParser::Key_attributeContext::TOKEN_RIGHT_BRACKET() {
  return getToken(MyDatalogParser::TOKEN_RIGHT_BRACKET, 0);
}

tree::TerminalNode* MyDatalogParser::Key_attributeContext::TOKEN_ID() {
  return getToken(MyDatalogParser::TOKEN_ID, 0);
}

MyDatalogParser::Data_typeContext* MyDatalogParser::Key_attributeContext::data_type() {
  return getRuleContext<MyDatalogParser::Data_typeContext>(0);
}


size_t MyDatalogParser::Key_attributeContext::getRuleIndex() const {
  return MyDatalogParser::RuleKey_attribute;
}


MyDatalogParser::Key_attributeContext* MyDatalogParser::key_attribute() {
  Key_attributeContext *_localctx = _tracker.createInstance<Key_attributeContext>(_ctx, getState());
  enterRule(_localctx, 30, MyDatalogParser::RuleKey_attribute);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    Attribute attr{"", "", true};
    setState(280);
    match(MyDatalogParser::TOKEN_LEFT_BRACKET);
    setState(281);
    antlrcpp::downCast<Key_attributeContext *>(_localctx)->a1 = match(MyDatalogParser::TOKEN_ID);
    attr.name = (antlrcpp::downCast<Key_attributeContext *>(_localctx)->a1 != nullptr ? antlrcpp::downCast<Key_attributeContext *>(_localctx)->a1->getText() : "");
    setState(283);
    match(MyDatalogParser::TOKEN_RIGHT_BRACKET);
    setState(284);
    antlrcpp::downCast<Key_attributeContext *>(_localctx)->d1 = data_type();
    attr.type = antlrcpp::downCast<Key_attributeContext *>(_localctx)->d1->r;
    antlrcpp::downCast<Key_attributeContext *>(_localctx)->r =  attr;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Non_key_attributeContext ------------------------------------------------------------------

MyDatalogParser::Non_key_attributeContext::Non_key_attributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Non_key_attributeContext::TOKEN_ID() {
  return getToken(MyDatalogParser::TOKEN_ID, 0);
}

MyDatalogParser::Data_typeContext* MyDatalogParser::Non_key_attributeContext::data_type() {
  return getRuleContext<MyDatalogParser::Data_typeContext>(0);
}


size_t MyDatalogParser::Non_key_attributeContext::getRuleIndex() const {
  return MyDatalogParser::RuleNon_key_attribute;
}


MyDatalogParser::Non_key_attributeContext* MyDatalogParser::non_key_attribute() {
  Non_key_attributeContext *_localctx = _tracker.createInstance<Non_key_attributeContext>(_ctx, getState());
  enterRule(_localctx, 32, MyDatalogParser::RuleNon_key_attribute);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    Attribute attr{"", "", false};
    setState(289);
    antlrcpp::downCast<Non_key_attributeContext *>(_localctx)->a1 = match(MyDatalogParser::TOKEN_ID);
    attr.name = (antlrcpp::downCast<Non_key_attributeContext *>(_localctx)->a1 != nullptr ? antlrcpp::downCast<Non_key_attributeContext *>(_localctx)->a1->getText() : "");
    setState(291);
    antlrcpp::downCast<Non_key_attributeContext *>(_localctx)->d1 = data_type();
    attr.type = antlrcpp::downCast<Non_key_attributeContext *>(_localctx)->d1->r;
    antlrcpp::downCast<Non_key_attributeContext *>(_localctx)->r =  attr;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compare_opContext ------------------------------------------------------------------

MyDatalogParser::Compare_opContext::Compare_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Compare_opContext::TOKEN_NOT_EQUALS() {
  return getToken(MyDatalogParser::TOKEN_NOT_EQUALS, 0);
}

tree::TerminalNode* MyDatalogParser::Compare_opContext::TOKEN_EQUALS() {
  return getToken(MyDatalogParser::TOKEN_EQUALS, 0);
}

tree::TerminalNode* MyDatalogParser::Compare_opContext::TOKEN_GREATER_THAN() {
  return getToken(MyDatalogParser::TOKEN_GREATER_THAN, 0);
}

tree::TerminalNode* MyDatalogParser::Compare_opContext::TOKEN_GREATER_EQUAL_THAN() {
  return getToken(MyDatalogParser::TOKEN_GREATER_EQUAL_THAN, 0);
}

tree::TerminalNode* MyDatalogParser::Compare_opContext::TOKEN_LESS_THAN() {
  return getToken(MyDatalogParser::TOKEN_LESS_THAN, 0);
}

tree::TerminalNode* MyDatalogParser::Compare_opContext::TOKEN_LESS_EQUAL_THAN() {
  return getToken(MyDatalogParser::TOKEN_LESS_EQUAL_THAN, 0);
}


size_t MyDatalogParser::Compare_opContext::getRuleIndex() const {
  return MyDatalogParser::RuleCompare_op;
}


MyDatalogParser::Compare_opContext* MyDatalogParser::compare_op() {
  Compare_opContext *_localctx = _tracker.createInstance<Compare_opContext>(_ctx, getState());
  enterRule(_localctx, 34, MyDatalogParser::RuleCompare_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(307);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyDatalogParser::TOKEN_NOT_EQUALS: {
        enterOuterAlt(_localctx, 1);
        setState(295);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->op1 = match(MyDatalogParser::TOKEN_NOT_EQUALS);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->r =  (antlrcpp::downCast<Compare_opContext *>(_localctx)->op1 != nullptr ? antlrcpp::downCast<Compare_opContext *>(_localctx)->op1->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_EQUALS: {
        enterOuterAlt(_localctx, 2);
        setState(297);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->op2 = match(MyDatalogParser::TOKEN_EQUALS);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->r =  (antlrcpp::downCast<Compare_opContext *>(_localctx)->op2 != nullptr ? antlrcpp::downCast<Compare_opContext *>(_localctx)->op2->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_GREATER_THAN: {
        enterOuterAlt(_localctx, 3);
        setState(299);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->op3 = match(MyDatalogParser::TOKEN_GREATER_THAN);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->r =  (antlrcpp::downCast<Compare_opContext *>(_localctx)->op3 != nullptr ? antlrcpp::downCast<Compare_opContext *>(_localctx)->op3->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_GREATER_EQUAL_THAN: {
        enterOuterAlt(_localctx, 4);
        setState(301);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->op4 = match(MyDatalogParser::TOKEN_GREATER_EQUAL_THAN);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->r =  (antlrcpp::downCast<Compare_opContext *>(_localctx)->op4 != nullptr ? antlrcpp::downCast<Compare_opContext *>(_localctx)->op4->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_LESS_THAN: {
        enterOuterAlt(_localctx, 5);
        setState(303);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->op5 = match(MyDatalogParser::TOKEN_LESS_THAN);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->r =  (antlrcpp::downCast<Compare_opContext *>(_localctx)->op5 != nullptr ? antlrcpp::downCast<Compare_opContext *>(_localctx)->op5->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_LESS_EQUAL_THAN: {
        enterOuterAlt(_localctx, 6);
        setState(305);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->op6 = match(MyDatalogParser::TOKEN_LESS_EQUAL_THAN);
        antlrcpp::downCast<Compare_opContext *>(_localctx)->r =  (antlrcpp::downCast<Compare_opContext *>(_localctx)->op6 != nullptr ? antlrcpp::downCast<Compare_opContext *>(_localctx)->op6->getText() : "");
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Aggregation_opContext ------------------------------------------------------------------

MyDatalogParser::Aggregation_opContext::Aggregation_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Aggregation_opContext::TOKEN_MIN() {
  return getToken(MyDatalogParser::TOKEN_MIN, 0);
}

tree::TerminalNode* MyDatalogParser::Aggregation_opContext::TOKEN_MAX() {
  return getToken(MyDatalogParser::TOKEN_MAX, 0);
}

tree::TerminalNode* MyDatalogParser::Aggregation_opContext::TOKEN_SUM() {
  return getToken(MyDatalogParser::TOKEN_SUM, 0);
}

tree::TerminalNode* MyDatalogParser::Aggregation_opContext::TOKEN_COUNT() {
  return getToken(MyDatalogParser::TOKEN_COUNT, 0);
}

tree::TerminalNode* MyDatalogParser::Aggregation_opContext::TOKEN_COUNT_DISTINCT() {
  return getToken(MyDatalogParser::TOKEN_COUNT_DISTINCT, 0);
}


size_t MyDatalogParser::Aggregation_opContext::getRuleIndex() const {
  return MyDatalogParser::RuleAggregation_op;
}


MyDatalogParser::Aggregation_opContext* MyDatalogParser::aggregation_op() {
  Aggregation_opContext *_localctx = _tracker.createInstance<Aggregation_opContext>(_ctx, getState());
  enterRule(_localctx, 36, MyDatalogParser::RuleAggregation_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(319);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyDatalogParser::TOKEN_MIN: {
        enterOuterAlt(_localctx, 1);
        setState(309);
        antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op1 = match(MyDatalogParser::TOKEN_MIN);
        antlrcpp::downCast<Aggregation_opContext *>(_localctx)->r =  (antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op1 != nullptr ? antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op1->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_MAX: {
        enterOuterAlt(_localctx, 2);
        setState(311);
        antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op2 = match(MyDatalogParser::TOKEN_MAX);
        antlrcpp::downCast<Aggregation_opContext *>(_localctx)->r =  (antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op2 != nullptr ? antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op2->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_SUM: {
        enterOuterAlt(_localctx, 3);
        setState(313);
        antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op3 = match(MyDatalogParser::TOKEN_SUM);
        antlrcpp::downCast<Aggregation_opContext *>(_localctx)->r =  (antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op3 != nullptr ? antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op3->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_COUNT: {
        enterOuterAlt(_localctx, 4);
        setState(315);
        antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op4 = match(MyDatalogParser::TOKEN_COUNT);
        antlrcpp::downCast<Aggregation_opContext *>(_localctx)->r =  (antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op4 != nullptr ? antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op4->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_COUNT_DISTINCT: {
        enterOuterAlt(_localctx, 5);
        setState(317);
        antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op5 = match(MyDatalogParser::TOKEN_COUNT_DISTINCT);
        antlrcpp::downCast<Aggregation_opContext *>(_localctx)->r =  (antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op5 != nullptr ? antlrcpp::downCast<Aggregation_opContext *>(_localctx)->op5->getText() : "");
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Math_opContext ------------------------------------------------------------------

MyDatalogParser::Math_opContext::Math_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Math_opContext::TOKEN_PLUS() {
  return getToken(MyDatalogParser::TOKEN_PLUS, 0);
}

tree::TerminalNode* MyDatalogParser::Math_opContext::TOKEN_MINUS() {
  return getToken(MyDatalogParser::TOKEN_MINUS, 0);
}

tree::TerminalNode* MyDatalogParser::Math_opContext::TOKEN_MULT() {
  return getToken(MyDatalogParser::TOKEN_MULT, 0);
}

tree::TerminalNode* MyDatalogParser::Math_opContext::TOKEN_DIV() {
  return getToken(MyDatalogParser::TOKEN_DIV, 0);
}


size_t MyDatalogParser::Math_opContext::getRuleIndex() const {
  return MyDatalogParser::RuleMath_op;
}


MyDatalogParser::Math_opContext* MyDatalogParser::math_op() {
  Math_opContext *_localctx = _tracker.createInstance<Math_opContext>(_ctx, getState());
  enterRule(_localctx, 38, MyDatalogParser::RuleMath_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(329);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyDatalogParser::TOKEN_PLUS: {
        enterOuterAlt(_localctx, 1);
        setState(321);
        antlrcpp::downCast<Math_opContext *>(_localctx)->op1 = match(MyDatalogParser::TOKEN_PLUS);
        antlrcpp::downCast<Math_opContext *>(_localctx)->r =  (antlrcpp::downCast<Math_opContext *>(_localctx)->op1 != nullptr ? antlrcpp::downCast<Math_opContext *>(_localctx)->op1->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(323);
        antlrcpp::downCast<Math_opContext *>(_localctx)->op2 = match(MyDatalogParser::TOKEN_MINUS);
        antlrcpp::downCast<Math_opContext *>(_localctx)->r =  (antlrcpp::downCast<Math_opContext *>(_localctx)->op2 != nullptr ? antlrcpp::downCast<Math_opContext *>(_localctx)->op2->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_MULT: {
        enterOuterAlt(_localctx, 3);
        setState(325);
        antlrcpp::downCast<Math_opContext *>(_localctx)->op3 = match(MyDatalogParser::TOKEN_MULT);
        antlrcpp::downCast<Math_opContext *>(_localctx)->r =  (antlrcpp::downCast<Math_opContext *>(_localctx)->op3 != nullptr ? antlrcpp::downCast<Math_opContext *>(_localctx)->op3->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_DIV: {
        enterOuterAlt(_localctx, 4);
        setState(327);
        antlrcpp::downCast<Math_opContext *>(_localctx)->op4 = match(MyDatalogParser::TOKEN_DIV);
        antlrcpp::downCast<Math_opContext *>(_localctx)->r =  (antlrcpp::downCast<Math_opContext *>(_localctx)->op4 != nullptr ? antlrcpp::downCast<Math_opContext *>(_localctx)->op4->getText() : "");
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

MyDatalogParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::ConstantContext::TOKEN_INTEGER() {
  return getToken(MyDatalogParser::TOKEN_INTEGER, 0);
}

tree::TerminalNode* MyDatalogParser::ConstantContext::TOKEN_STRING() {
  return getToken(MyDatalogParser::TOKEN_STRING, 0);
}


size_t MyDatalogParser::ConstantContext::getRuleIndex() const {
  return MyDatalogParser::RuleConstant;
}


MyDatalogParser::ConstantContext* MyDatalogParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 40, MyDatalogParser::RuleConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(335);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyDatalogParser::TOKEN_INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(331);
        antlrcpp::downCast<ConstantContext *>(_localctx)->c1 = match(MyDatalogParser::TOKEN_INTEGER);
        antlrcpp::downCast<ConstantContext *>(_localctx)->r =  (antlrcpp::downCast<ConstantContext *>(_localctx)->c1 != nullptr ? antlrcpp::downCast<ConstantContext *>(_localctx)->c1->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_STRING: {
        enterOuterAlt(_localctx, 2);
        setState(333);
        antlrcpp::downCast<ConstantContext *>(_localctx)->c2 = match(MyDatalogParser::TOKEN_STRING);
        antlrcpp::downCast<ConstantContext *>(_localctx)->r =  (antlrcpp::downCast<ConstantContext *>(_localctx)->c2 != nullptr ? antlrcpp::downCast<ConstantContext *>(_localctx)->c2->getText() : "");
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Data_typeContext ------------------------------------------------------------------

MyDatalogParser::Data_typeContext::Data_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyDatalogParser::Data_typeContext::TOKEN_INT() {
  return getToken(MyDatalogParser::TOKEN_INT, 0);
}

tree::TerminalNode* MyDatalogParser::Data_typeContext::TOKEN_LONG() {
  return getToken(MyDatalogParser::TOKEN_LONG, 0);
}

tree::TerminalNode* MyDatalogParser::Data_typeContext::TOKEN_FLOAT() {
  return getToken(MyDatalogParser::TOKEN_FLOAT, 0);
}

tree::TerminalNode* MyDatalogParser::Data_typeContext::TOKEN_DOUBLE() {
  return getToken(MyDatalogParser::TOKEN_DOUBLE, 0);
}

tree::TerminalNode* MyDatalogParser::Data_typeContext::TOKEN_VARCHAR() {
  return getToken(MyDatalogParser::TOKEN_VARCHAR, 0);
}

tree::TerminalNode* MyDatalogParser::Data_typeContext::TOKEN_CHAR() {
  return getToken(MyDatalogParser::TOKEN_CHAR, 0);
}

tree::TerminalNode* MyDatalogParser::Data_typeContext::TOKEN_DATE() {
  return getToken(MyDatalogParser::TOKEN_DATE, 0);
}

tree::TerminalNode* MyDatalogParser::Data_typeContext::TOKEN_DATETIME() {
  return getToken(MyDatalogParser::TOKEN_DATETIME, 0);
}


size_t MyDatalogParser::Data_typeContext::getRuleIndex() const {
  return MyDatalogParser::RuleData_type;
}


MyDatalogParser::Data_typeContext* MyDatalogParser::data_type() {
  Data_typeContext *_localctx = _tracker.createInstance<Data_typeContext>(_ctx, getState());
  enterRule(_localctx, 42, MyDatalogParser::RuleData_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(353);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyDatalogParser::TOKEN_INT: {
        enterOuterAlt(_localctx, 1);
        setState(337);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->dt1 = match(MyDatalogParser::TOKEN_INT);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->r =  (antlrcpp::downCast<Data_typeContext *>(_localctx)->dt1 != nullptr ? antlrcpp::downCast<Data_typeContext *>(_localctx)->dt1->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_LONG: {
        enterOuterAlt(_localctx, 2);
        setState(339);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->dt2 = match(MyDatalogParser::TOKEN_LONG);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->r =  (antlrcpp::downCast<Data_typeContext *>(_localctx)->dt2 != nullptr ? antlrcpp::downCast<Data_typeContext *>(_localctx)->dt2->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(341);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->dt3 = match(MyDatalogParser::TOKEN_FLOAT);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->r =  (antlrcpp::downCast<Data_typeContext *>(_localctx)->dt3 != nullptr ? antlrcpp::downCast<Data_typeContext *>(_localctx)->dt3->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_DOUBLE: {
        enterOuterAlt(_localctx, 4);
        setState(343);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->dt4 = match(MyDatalogParser::TOKEN_DOUBLE);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->r =  (antlrcpp::downCast<Data_typeContext *>(_localctx)->dt4 != nullptr ? antlrcpp::downCast<Data_typeContext *>(_localctx)->dt4->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_VARCHAR: {
        enterOuterAlt(_localctx, 5);
        setState(345);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->dt5 = match(MyDatalogParser::TOKEN_VARCHAR);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->r =  (antlrcpp::downCast<Data_typeContext *>(_localctx)->dt5 != nullptr ? antlrcpp::downCast<Data_typeContext *>(_localctx)->dt5->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_CHAR: {
        enterOuterAlt(_localctx, 6);
        setState(347);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->dt6 = match(MyDatalogParser::TOKEN_CHAR);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->r =  (antlrcpp::downCast<Data_typeContext *>(_localctx)->dt6 != nullptr ? antlrcpp::downCast<Data_typeContext *>(_localctx)->dt6->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_DATE: {
        enterOuterAlt(_localctx, 7);
        setState(349);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->dt7 = match(MyDatalogParser::TOKEN_DATE);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->r =  (antlrcpp::downCast<Data_typeContext *>(_localctx)->dt7 != nullptr ? antlrcpp::downCast<Data_typeContext *>(_localctx)->dt7->getText() : "");
        break;
      }

      case MyDatalogParser::TOKEN_DATETIME: {
        enterOuterAlt(_localctx, 8);
        setState(351);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->dt8 = match(MyDatalogParser::TOKEN_DATETIME);
        antlrcpp::downCast<Data_typeContext *>(_localctx)->r =  (antlrcpp::downCast<Data_typeContext *>(_localctx)->dt8 != nullptr ? antlrcpp::downCast<Data_typeContext *>(_localctx)->dt8->getText() : "");
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void MyDatalogParser::initialize() {
  ::antlr4::internal::call_once(mydatalogParserOnceFlag, mydatalogParserInitialize);
}
