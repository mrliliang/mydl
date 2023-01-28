



// Generated from MyDatalog.g4 by ANTLR 4.11.1


#include "basetype.h"


#include "MyDatalogLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MyDatalogLexerStaticData final {
  MyDatalogLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MyDatalogLexerStaticData(const MyDatalogLexerStaticData&) = delete;
  MyDatalogLexerStaticData(MyDatalogLexerStaticData&&) = delete;
  MyDatalogLexerStaticData& operator=(const MyDatalogLexerStaticData&) = delete;
  MyDatalogLexerStaticData& operator=(MyDatalogLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mydataloglexerLexerOnceFlag;
MyDatalogLexerStaticData *mydataloglexerLexerStaticData = nullptr;

void mydataloglexerLexerInitialize() {
  assert(mydataloglexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<MyDatalogLexerStaticData>(
    std::vector<std::string>{
      "TOKEN_EDB", "TOKEN_IDB", "TOKEN_RULE", "TOKEN_INTEGER", "TOKEN_STRING", 
      "TOKEN_INT", "TOKEN_LONG", "TOKEN_FLOAT", "TOKEN_DOUBLE", "TOKEN_VARCHAR", 
      "TOKEN_CHAR", "TOKEN_DATE", "TOKEN_DATETIME", "TOKEN_MIN", "TOKEN_MAX", 
      "TOKEN_SUM", "TOKEN_COUNT", "TOKEN_COUNT_DISTINCT", "TOKEN_ID", "TOKEN_BODY_HEAD_SEP", 
      "TOKEN_ANY", "TOKEN_COMMA", "TOKEN_SEMICOLON", "TOKEN_COLON", "TOKEN_DOT", 
      "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULT", "TOKEN_DIV", "TOKEN_NOT", 
      "TOKEN_NON_DEDUP", "TOKEN_NON_SET_DIFF", "TOKEN_DEDUP_ONLY", "TOKEN_NOT_EQUALS", 
      "TOKEN_EQUALS", "TOKEN_GREATER_EQUAL_THAN", "TOKEN_GREATER_THAN", 
      "TOKEN_LESS_EQUAL_THAN", "TOKEN_LESS_THAN", "TOKEN_LEFT_PAREN", "TOKEN_RIGHT_PAREN", 
      "TOKEN_LEFT_BRACKET", "TOKEN_RIGHT_BRACKET", "TOKEN_WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,44,309,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,3,3,119,
  	8,3,1,3,4,3,122,8,3,11,3,12,3,123,1,4,1,4,4,4,128,8,4,11,4,12,4,129,1,
  	4,1,4,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,
  	1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,5,18,218,8,18,10,18,12,18,
  	221,9,18,1,19,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,
  	1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,30,
  	1,30,1,30,1,30,1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,
  	1,31,1,31,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,
  	1,32,1,32,1,32,1,33,1,33,1,33,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,37,
  	1,37,1,37,1,38,1,38,1,39,1,39,1,40,1,40,1,41,1,41,1,42,1,42,1,43,4,43,
  	304,8,43,11,43,12,43,305,1,43,1,43,0,0,44,1,1,3,2,5,3,7,4,9,5,11,6,13,
  	7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,
  	19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,
  	61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,38,77,39,79,40,81,41,83,
  	42,85,43,87,44,1,0,23,2,0,43,43,45,45,1,0,48,57,3,0,48,57,65,90,97,122,
  	2,0,73,73,105,105,2,0,78,78,110,110,2,0,84,84,116,116,2,0,76,76,108,108,
  	2,0,79,79,111,111,2,0,71,71,103,103,2,0,70,70,102,102,2,0,65,65,97,97,
  	2,0,68,68,100,100,2,0,85,85,117,117,2,0,66,66,98,98,2,0,69,69,101,101,
  	2,0,86,86,118,118,2,0,82,82,114,114,2,0,67,67,99,99,2,0,72,72,104,104,
  	2,0,77,77,109,109,2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,122,3,0,9,
  	10,13,13,32,32,313,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,
  	9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,
  	0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,
  	0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,
  	41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,
  	0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,
  	0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,
  	73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,
  	0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,1,89,1,0,0,0,3,98,1,0,0,0,5,107,1,0,0,
  	0,7,118,1,0,0,0,9,125,1,0,0,0,11,133,1,0,0,0,13,137,1,0,0,0,15,142,1,
  	0,0,0,17,148,1,0,0,0,19,155,1,0,0,0,21,163,1,0,0,0,23,168,1,0,0,0,25,
  	173,1,0,0,0,27,182,1,0,0,0,29,186,1,0,0,0,31,190,1,0,0,0,33,194,1,0,0,
  	0,35,200,1,0,0,0,37,215,1,0,0,0,39,222,1,0,0,0,41,225,1,0,0,0,43,227,
  	1,0,0,0,45,229,1,0,0,0,47,231,1,0,0,0,49,233,1,0,0,0,51,235,1,0,0,0,53,
  	237,1,0,0,0,55,239,1,0,0,0,57,241,1,0,0,0,59,243,1,0,0,0,61,245,1,0,0,
  	0,63,254,1,0,0,0,65,266,1,0,0,0,67,279,1,0,0,0,69,282,1,0,0,0,71,284,
  	1,0,0,0,73,287,1,0,0,0,75,289,1,0,0,0,77,292,1,0,0,0,79,294,1,0,0,0,81,
  	296,1,0,0,0,83,298,1,0,0,0,85,300,1,0,0,0,87,303,1,0,0,0,89,90,5,69,0,
  	0,90,91,5,68,0,0,91,92,5,66,0,0,92,93,5,95,0,0,93,94,5,68,0,0,94,95,5,
  	69,0,0,95,96,5,67,0,0,96,97,5,76,0,0,97,2,1,0,0,0,98,99,5,73,0,0,99,100,
  	5,68,0,0,100,101,5,66,0,0,101,102,5,95,0,0,102,103,5,68,0,0,103,104,5,
  	69,0,0,104,105,5,67,0,0,105,106,5,76,0,0,106,4,1,0,0,0,107,108,5,82,0,
  	0,108,109,5,85,0,0,109,110,5,76,0,0,110,111,5,69,0,0,111,112,5,95,0,0,
  	112,113,5,68,0,0,113,114,5,69,0,0,114,115,5,67,0,0,115,116,5,76,0,0,116,
  	6,1,0,0,0,117,119,7,0,0,0,118,117,1,0,0,0,118,119,1,0,0,0,119,121,1,0,
  	0,0,120,122,7,1,0,0,121,120,1,0,0,0,122,123,1,0,0,0,123,121,1,0,0,0,123,
  	124,1,0,0,0,124,8,1,0,0,0,125,127,5,39,0,0,126,128,7,2,0,0,127,126,1,
  	0,0,0,128,129,1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,0,130,131,1,0,0,0,
  	131,132,5,39,0,0,132,10,1,0,0,0,133,134,7,3,0,0,134,135,7,4,0,0,135,136,
  	7,5,0,0,136,12,1,0,0,0,137,138,7,6,0,0,138,139,7,7,0,0,139,140,7,4,0,
  	0,140,141,7,8,0,0,141,14,1,0,0,0,142,143,7,9,0,0,143,144,7,6,0,0,144,
  	145,7,7,0,0,145,146,7,10,0,0,146,147,7,5,0,0,147,16,1,0,0,0,148,149,7,
  	11,0,0,149,150,7,7,0,0,150,151,7,12,0,0,151,152,7,13,0,0,152,153,7,6,
  	0,0,153,154,7,14,0,0,154,18,1,0,0,0,155,156,7,15,0,0,156,157,7,10,0,0,
  	157,158,7,16,0,0,158,159,7,17,0,0,159,160,7,18,0,0,160,161,7,10,0,0,161,
  	162,7,16,0,0,162,20,1,0,0,0,163,164,7,17,0,0,164,165,7,18,0,0,165,166,
  	7,10,0,0,166,167,7,16,0,0,167,22,1,0,0,0,168,169,7,11,0,0,169,170,7,10,
  	0,0,170,171,7,5,0,0,171,172,7,14,0,0,172,24,1,0,0,0,173,174,7,11,0,0,
  	174,175,7,10,0,0,175,176,7,5,0,0,176,177,7,14,0,0,177,178,7,5,0,0,178,
  	179,7,3,0,0,179,180,7,19,0,0,180,181,7,14,0,0,181,26,1,0,0,0,182,183,
  	5,77,0,0,183,184,5,73,0,0,184,185,5,78,0,0,185,28,1,0,0,0,186,187,5,77,
  	0,0,187,188,5,65,0,0,188,189,5,88,0,0,189,30,1,0,0,0,190,191,5,83,0,0,
  	191,192,5,85,0,0,192,193,5,77,0,0,193,32,1,0,0,0,194,195,5,67,0,0,195,
  	196,5,79,0,0,196,197,5,85,0,0,197,198,5,78,0,0,198,199,5,84,0,0,199,34,
  	1,0,0,0,200,201,5,67,0,0,201,202,5,79,0,0,202,203,5,85,0,0,203,204,5,
  	78,0,0,204,205,5,84,0,0,205,206,5,95,0,0,206,207,5,68,0,0,207,208,5,73,
  	0,0,208,209,5,83,0,0,209,210,5,84,0,0,210,211,5,73,0,0,211,212,5,78,0,
  	0,212,213,5,67,0,0,213,214,5,84,0,0,214,36,1,0,0,0,215,219,7,20,0,0,216,
  	218,7,21,0,0,217,216,1,0,0,0,218,221,1,0,0,0,219,217,1,0,0,0,219,220,
  	1,0,0,0,220,38,1,0,0,0,221,219,1,0,0,0,222,223,5,58,0,0,223,224,5,45,
  	0,0,224,40,1,0,0,0,225,226,5,95,0,0,226,42,1,0,0,0,227,228,5,44,0,0,228,
  	44,1,0,0,0,229,230,5,59,0,0,230,46,1,0,0,0,231,232,5,58,0,0,232,48,1,
  	0,0,0,233,234,5,46,0,0,234,50,1,0,0,0,235,236,5,43,0,0,236,52,1,0,0,0,
  	237,238,5,45,0,0,238,54,1,0,0,0,239,240,5,42,0,0,240,56,1,0,0,0,241,242,
  	5,47,0,0,242,58,1,0,0,0,243,244,5,33,0,0,244,60,1,0,0,0,245,246,5,91,
  	0,0,246,247,5,33,0,0,247,248,5,100,0,0,248,249,5,101,0,0,249,250,5,100,
  	0,0,250,251,5,117,0,0,251,252,5,112,0,0,252,253,5,93,0,0,253,62,1,0,0,
  	0,254,255,5,91,0,0,255,256,5,33,0,0,256,257,5,115,0,0,257,258,5,101,0,
  	0,258,259,5,116,0,0,259,260,5,45,0,0,260,261,5,100,0,0,261,262,5,105,
  	0,0,262,263,5,102,0,0,263,264,5,102,0,0,264,265,5,93,0,0,265,64,1,0,0,
  	0,266,267,5,91,0,0,267,268,5,100,0,0,268,269,5,101,0,0,269,270,5,100,
  	0,0,270,271,5,117,0,0,271,272,5,112,0,0,272,273,5,45,0,0,273,274,5,111,
  	0,0,274,275,5,110,0,0,275,276,5,108,0,0,276,277,5,121,0,0,277,278,5,93,
  	0,0,278,66,1,0,0,0,279,280,5,33,0,0,280,281,5,61,0,0,281,68,1,0,0,0,282,
  	283,5,61,0,0,283,70,1,0,0,0,284,285,5,62,0,0,285,286,5,61,0,0,286,72,
  	1,0,0,0,287,288,5,62,0,0,288,74,1,0,0,0,289,290,5,60,0,0,290,291,5,61,
  	0,0,291,76,1,0,0,0,292,293,5,60,0,0,293,78,1,0,0,0,294,295,5,40,0,0,295,
  	80,1,0,0,0,296,297,5,41,0,0,297,82,1,0,0,0,298,299,5,91,0,0,299,84,1,
  	0,0,0,300,301,5,93,0,0,301,86,1,0,0,0,302,304,7,22,0,0,303,302,1,0,0,
  	0,304,305,1,0,0,0,305,303,1,0,0,0,305,306,1,0,0,0,306,307,1,0,0,0,307,
  	308,6,43,0,0,308,88,1,0,0,0,8,0,118,123,127,129,217,219,305,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mydataloglexerLexerStaticData = staticData.release();
}

}

MyDatalogLexer::MyDatalogLexer(CharStream *input) : Lexer(input) {
  MyDatalogLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *mydataloglexerLexerStaticData->atn, mydataloglexerLexerStaticData->decisionToDFA, mydataloglexerLexerStaticData->sharedContextCache);
}

MyDatalogLexer::~MyDatalogLexer() {
  delete _interpreter;
}

std::string MyDatalogLexer::getGrammarFileName() const {
  return "MyDatalog.g4";
}

const std::vector<std::string>& MyDatalogLexer::getRuleNames() const {
  return mydataloglexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MyDatalogLexer::getChannelNames() const {
  return mydataloglexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MyDatalogLexer::getModeNames() const {
  return mydataloglexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MyDatalogLexer::getVocabulary() const {
  return mydataloglexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MyDatalogLexer::getSerializedATN() const {
  return mydataloglexerLexerStaticData->serializedATN;
}

const atn::ATN& MyDatalogLexer::getATN() const {
  return *mydataloglexerLexerStaticData->atn;
}




void MyDatalogLexer::initialize() {
  ::antlr4::internal::call_once(mydataloglexerLexerOnceFlag, mydataloglexerLexerInitialize);
}
