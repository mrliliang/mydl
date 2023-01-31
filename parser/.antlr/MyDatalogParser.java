// Generated from /Users/liliang/VSCode/mydatalog/parser/MyDatalog.g4 by ANTLR 4.9.2



import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MyDatalogParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		TOKEN_EDB=1, TOKEN_IDB=2, TOKEN_RULE=3, TOKEN_INTEGER=4, TOKEN_STRING=5, 
		TOKEN_INT=6, TOKEN_LONG=7, TOKEN_FLOAT=8, TOKEN_DOUBLE=9, TOKEN_VARCHAR=10, 
		TOKEN_CHAR=11, TOKEN_DATE=12, TOKEN_DATETIME=13, TOKEN_MIN=14, TOKEN_MAX=15, 
		TOKEN_SUM=16, TOKEN_COUNT=17, TOKEN_COUNT_DISTINCT=18, TOKEN_ID=19, TOKEN_BODY_HEAD_SEP=20, 
		TOKEN_ANY=21, TOKEN_COMMA=22, TOKEN_SEMICOLON=23, TOKEN_COLON=24, TOKEN_DOT=25, 
		TOKEN_PLUS=26, TOKEN_MINUS=27, TOKEN_MULT=28, TOKEN_DIV=29, TOKEN_NOT=30, 
		TOKEN_NON_DEDUP=31, TOKEN_NON_SET_DIFF=32, TOKEN_DEDUP_ONLY=33, TOKEN_NOT_EQUALS=34, 
		TOKEN_EQUALS=35, TOKEN_GREATER_EQUAL_THAN=36, TOKEN_GREATER_THAN=37, TOKEN_LESS_EQUAL_THAN=38, 
		TOKEN_LESS_THAN=39, TOKEN_LEFT_PAREN=40, TOKEN_RIGHT_PAREN=41, TOKEN_LEFT_BRACKET=42, 
		TOKEN_RIGHT_BRACKET=43, TOKEN_WS=44;
	public static final int
		RULE_datalog_edb_declare = 0, RULE_datalog_idb_declare = 1, RULE_datalog_relation_schema = 2, 
		RULE_datalog_rule_declare = 3, RULE_datalog_program = 4, RULE_datalog_rule = 5, 
		RULE_head = 6, RULE_body = 7, RULE_negation = 8, RULE_atom = 9, RULE_assign = 10, 
		RULE_math_expr = 11, RULE_compare_expr = 12, RULE_aggregation_expr = 13, 
		RULE_attribute = 14, RULE_key_attribute = 15, RULE_non_key_attribute = 16, 
		RULE_compare_op = 17, RULE_aggregation_op = 18, RULE_math_op = 19, RULE_constant = 20, 
		RULE_data_type = 21;
	private static String[] makeRuleNames() {
		return new String[] {
			"datalog_edb_declare", "datalog_idb_declare", "datalog_relation_schema", 
			"datalog_rule_declare", "datalog_program", "datalog_rule", "head", "body", 
			"negation", "atom", "assign", "math_expr", "compare_expr", "aggregation_expr", 
			"attribute", "key_attribute", "non_key_attribute", "compare_op", "aggregation_op", 
			"math_op", "constant", "data_type"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'EDB_DECL'", "'IDB_DECL'", "'RULE_DECL'", null, null, null, null, 
			null, null, null, null, null, null, "'MIN'", "'MAX'", "'SUM'", "'COUNT'", 
			"'COUNT_DISTINCT'", null, "':-'", "'_'", "','", "';'", "':'", "'.'", 
			"'+'", "'-'", "'*'", "'/'", "'!'", "'[!dedup]'", "'[!set-diff]'", "'[dedup-only]'", 
			"'!='", "'='", "'>='", "'>'", "'<='", "'<'", "'('", "')'", "'['", "']'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "TOKEN_EDB", "TOKEN_IDB", "TOKEN_RULE", "TOKEN_INTEGER", "TOKEN_STRING", 
			"TOKEN_INT", "TOKEN_LONG", "TOKEN_FLOAT", "TOKEN_DOUBLE", "TOKEN_VARCHAR", 
			"TOKEN_CHAR", "TOKEN_DATE", "TOKEN_DATETIME", "TOKEN_MIN", "TOKEN_MAX", 
			"TOKEN_SUM", "TOKEN_COUNT", "TOKEN_COUNT_DISTINCT", "TOKEN_ID", "TOKEN_BODY_HEAD_SEP", 
			"TOKEN_ANY", "TOKEN_COMMA", "TOKEN_SEMICOLON", "TOKEN_COLON", "TOKEN_DOT", 
			"TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULT", "TOKEN_DIV", "TOKEN_NOT", 
			"TOKEN_NON_DEDUP", "TOKEN_NON_SET_DIFF", "TOKEN_DEDUP_ONLY", "TOKEN_NOT_EQUALS", 
			"TOKEN_EQUALS", "TOKEN_GREATER_EQUAL_THAN", "TOKEN_GREATER_THAN", "TOKEN_LESS_EQUAL_THAN", 
			"TOKEN_LESS_THAN", "TOKEN_LEFT_PAREN", "TOKEN_RIGHT_PAREN", "TOKEN_LEFT_BRACKET", 
			"TOKEN_RIGHT_BRACKET", "TOKEN_WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "MyDatalog.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MyDatalogParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Datalog_edb_declareContext extends ParserRuleContext {
		public vector<Schema> r;
		public Datalog_relation_schemaContext schema1;
		public Datalog_relation_schemaContext schema2;
		public TerminalNode TOKEN_EDB() { return getToken(MyDatalogParser.TOKEN_EDB, 0); }
		public TerminalNode TOKEN_COLON() { return getToken(MyDatalogParser.TOKEN_COLON, 0); }
		public List<Datalog_relation_schemaContext> datalog_relation_schema() {
			return getRuleContexts(Datalog_relation_schemaContext.class);
		}
		public Datalog_relation_schemaContext datalog_relation_schema(int i) {
			return getRuleContext(Datalog_relation_schemaContext.class,i);
		}
		public Datalog_edb_declareContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_datalog_edb_declare; }
	}

	public final Datalog_edb_declareContext datalog_edb_declare() throws RecognitionException {
		Datalog_edb_declareContext _localctx = new Datalog_edb_declareContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_datalog_edb_declare);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			vector<Schema> edb_list;
			setState(45);
			match(TOKEN_EDB);
			setState(46);
			match(TOKEN_COLON);
			setState(47);
			((Datalog_edb_declareContext)_localctx).schema1 = datalog_relation_schema();
			edb_list.emplace_back(((Datalog_edb_declareContext)_localctx).schema1.r);
			setState(54);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==TOKEN_ID) {
				{
				{
				setState(49);
				((Datalog_edb_declareContext)_localctx).schema2 = datalog_relation_schema();
				edb_list.emplace_back(((Datalog_edb_declareContext)_localctx).schema2.r);
				}
				}
				setState(56);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			((Datalog_edb_declareContext)_localctx).r =  edb_list;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Datalog_idb_declareContext extends ParserRuleContext {
		public vector<Schema> r;
		public Datalog_relation_schemaContext schema1;
		public Datalog_relation_schemaContext schema2;
		public TerminalNode TOKEN_IDB() { return getToken(MyDatalogParser.TOKEN_IDB, 0); }
		public TerminalNode TOKEN_COLON() { return getToken(MyDatalogParser.TOKEN_COLON, 0); }
		public List<Datalog_relation_schemaContext> datalog_relation_schema() {
			return getRuleContexts(Datalog_relation_schemaContext.class);
		}
		public Datalog_relation_schemaContext datalog_relation_schema(int i) {
			return getRuleContext(Datalog_relation_schemaContext.class,i);
		}
		public Datalog_idb_declareContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_datalog_idb_declare; }
	}

	public final Datalog_idb_declareContext datalog_idb_declare() throws RecognitionException {
		Datalog_idb_declareContext _localctx = new Datalog_idb_declareContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_datalog_idb_declare);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			vector<Schema> idb_list;
			setState(60);
			match(TOKEN_IDB);
			setState(61);
			match(TOKEN_COLON);
			setState(62);
			((Datalog_idb_declareContext)_localctx).schema1 = datalog_relation_schema();
			idb_list.emplace_back(((Datalog_idb_declareContext)_localctx).schema1.r);
			setState(69);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==TOKEN_ID) {
				{
				{
				setState(64);
				((Datalog_idb_declareContext)_localctx).schema2 = datalog_relation_schema();
				idb_list.emplace_back(((Datalog_idb_declareContext)_localctx).schema2.r);
				}
				}
				setState(71);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			((Datalog_idb_declareContext)_localctx).r =  idb_list;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Datalog_relation_schemaContext extends ParserRuleContext {
		public Schema r;
		public Token relation_name;
		public AttributeContext t1;
		public AttributeContext t2;
		public TerminalNode TOKEN_LEFT_PAREN() { return getToken(MyDatalogParser.TOKEN_LEFT_PAREN, 0); }
		public TerminalNode TOKEN_RIGHT_PAREN() { return getToken(MyDatalogParser.TOKEN_RIGHT_PAREN, 0); }
		public TerminalNode TOKEN_ID() { return getToken(MyDatalogParser.TOKEN_ID, 0); }
		public List<AttributeContext> attribute() {
			return getRuleContexts(AttributeContext.class);
		}
		public AttributeContext attribute(int i) {
			return getRuleContext(AttributeContext.class,i);
		}
		public List<TerminalNode> TOKEN_COMMA() { return getTokens(MyDatalogParser.TOKEN_COMMA); }
		public TerminalNode TOKEN_COMMA(int i) {
			return getToken(MyDatalogParser.TOKEN_COMMA, i);
		}
		public Datalog_relation_schemaContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_datalog_relation_schema; }
	}

	public final Datalog_relation_schemaContext datalog_relation_schema() throws RecognitionException {
		Datalog_relation_schemaContext _localctx = new Datalog_relation_schemaContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_datalog_relation_schema);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			Schema schema;
			setState(75);
			((Datalog_relation_schemaContext)_localctx).relation_name = match(TOKEN_ID);
			schema.name = (((Datalog_relation_schemaContext)_localctx).relation_name!=null?((Datalog_relation_schemaContext)_localctx).relation_name.getText():null);
			setState(77);
			match(TOKEN_LEFT_PAREN);
			setState(78);
			((Datalog_relation_schemaContext)_localctx).t1 = attribute();
			schema.attributes.emplace_back(AtomArg(((Datalog_relation_schemaContext)_localctx).t1.r.name, ((Datalog_relation_schemaContext)_localctx).t1.r.type, ((Datalog_relation_schemaContext)_localctx).t1.r.isKey));
			setState(86);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==TOKEN_COMMA) {
				{
				{
				setState(80);
				match(TOKEN_COMMA);
				setState(81);
				((Datalog_relation_schemaContext)_localctx).t2 = attribute();
				schema.attributes.emplace_back(AtomArg(((Datalog_relation_schemaContext)_localctx).t2.r.name, ((Datalog_relation_schemaContext)_localctx).t2.r.type, ((Datalog_relation_schemaContext)_localctx).t2.r.isKey));
				}
				}
				setState(88);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(89);
			match(TOKEN_RIGHT_PAREN);
			((Datalog_relation_schemaContext)_localctx).r =  schema;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Datalog_rule_declareContext extends ParserRuleContext {
		public vector<RuleMap> r;
		public Datalog_programContext dp;
		public TerminalNode TOKEN_RULE() { return getToken(MyDatalogParser.TOKEN_RULE, 0); }
		public TerminalNode TOKEN_COLON() { return getToken(MyDatalogParser.TOKEN_COLON, 0); }
		public TerminalNode EOF() { return getToken(MyDatalogParser.EOF, 0); }
		public Datalog_programContext datalog_program() {
			return getRuleContext(Datalog_programContext.class,0);
		}
		public Datalog_rule_declareContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_datalog_rule_declare; }
	}

	public final Datalog_rule_declareContext datalog_rule_declare() throws RecognitionException {
		Datalog_rule_declareContext _localctx = new Datalog_rule_declareContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_datalog_rule_declare);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(92);
			match(TOKEN_RULE);
			setState(93);
			match(TOKEN_COLON);
			setState(94);
			((Datalog_rule_declareContext)_localctx).dp = datalog_program();
			((Datalog_rule_declareContext)_localctx).r =  ((Datalog_rule_declareContext)_localctx).dp.r;
			setState(96);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Datalog_programContext extends ParserRuleContext {
		public vector<RuleMap> r;
		public Datalog_ruleContext r1;
		public Datalog_ruleContext r2;
		public List<Datalog_ruleContext> datalog_rule() {
			return getRuleContexts(Datalog_ruleContext.class);
		}
		public Datalog_ruleContext datalog_rule(int i) {
			return getRuleContext(Datalog_ruleContext.class,i);
		}
		public Datalog_programContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_datalog_program; }
	}

	public final Datalog_programContext datalog_program() throws RecognitionException {
		Datalog_programContext _localctx = new Datalog_programContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_datalog_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			vector<RuleMap> rule_list;
			setState(99);
			((Datalog_programContext)_localctx).r1 = datalog_rule();
			rule_list.emplace_back(((Datalog_programContext)_localctx).r1.r);
			setState(106);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << TOKEN_ID) | (1L << TOKEN_NON_DEDUP) | (1L << TOKEN_NON_SET_DIFF) | (1L << TOKEN_DEDUP_ONLY))) != 0)) {
				{
				{
				setState(101);
				((Datalog_programContext)_localctx).r2 = datalog_rule();
				rule_list.emplace_back(((Datalog_programContext)_localctx).r2.r);
				}
				}
				setState(108);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			((Datalog_programContext)_localctx).r =  rule_list;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Datalog_ruleContext extends ParserRuleContext {
		public RuleMap r;
		public HeadContext h;
		public BodyContext b;
		public TerminalNode TOKEN_BODY_HEAD_SEP() { return getToken(MyDatalogParser.TOKEN_BODY_HEAD_SEP, 0); }
		public TerminalNode TOKEN_DOT() { return getToken(MyDatalogParser.TOKEN_DOT, 0); }
		public HeadContext head() {
			return getRuleContext(HeadContext.class,0);
		}
		public TerminalNode TOKEN_NON_DEDUP() { return getToken(MyDatalogParser.TOKEN_NON_DEDUP, 0); }
		public TerminalNode TOKEN_NON_SET_DIFF() { return getToken(MyDatalogParser.TOKEN_NON_SET_DIFF, 0); }
		public TerminalNode TOKEN_DEDUP_ONLY() { return getToken(MyDatalogParser.TOKEN_DEDUP_ONLY, 0); }
		public BodyContext body() {
			return getRuleContext(BodyContext.class,0);
		}
		public Datalog_ruleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_datalog_rule; }
	}

	public final Datalog_ruleContext datalog_rule() throws RecognitionException {
		Datalog_ruleContext _localctx = new Datalog_ruleContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_datalog_rule);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			RuleMap rule_map;
			setState(114);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TOKEN_NON_DEDUP) {
				{
				setState(112);
				match(TOKEN_NON_DEDUP);
				rule_map.nonDedup = true;
				}
			}

			setState(118);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TOKEN_NON_SET_DIFF) {
				{
				setState(116);
				match(TOKEN_NON_SET_DIFF);
				rule_map.nonSetDiff = true;
				}
			}

			setState(122);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TOKEN_DEDUP_ONLY) {
				{
				setState(120);
				match(TOKEN_DEDUP_ONLY);
				rule_map.dedupOnly = true;
				}
			}

			setState(124);
			((Datalog_ruleContext)_localctx).h = head();
			rule_map.head = ((Datalog_ruleContext)_localctx).h.r;
			setState(126);
			match(TOKEN_BODY_HEAD_SEP);
			setState(130);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << TOKEN_INTEGER) | (1L << TOKEN_ID) | (1L << TOKEN_NOT))) != 0)) {
				{
				setState(127);
				((Datalog_ruleContext)_localctx).b = body();
				rule_map.body = ((Datalog_ruleContext)_localctx).b.r;
				}
			}

			setState(132);
			match(TOKEN_DOT);
			((Datalog_ruleContext)_localctx).r =  rule_map;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class HeadContext extends ParserRuleContext {
		public AtomMap r;
		public AtomContext a;
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public HeadContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_head; }
	}

	public final HeadContext head() throws RecognitionException {
		HeadContext _localctx = new HeadContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_head);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(135);
			((HeadContext)_localctx).a = atom();
			((HeadContext)_localctx).r =  ((HeadContext)_localctx).a.r;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BodyContext extends ParserRuleContext {
		public BodyMap r;
		public AtomContext b1;
		public Compare_exprContext b2;
		public AssignContext b3;
		public NegationContext b4;
		public AtomContext b5;
		public Compare_exprContext b6;
		public AssignContext b7;
		public NegationContext b8;
		public List<TerminalNode> TOKEN_COMMA() { return getTokens(MyDatalogParser.TOKEN_COMMA); }
		public TerminalNode TOKEN_COMMA(int i) {
			return getToken(MyDatalogParser.TOKEN_COMMA, i);
		}
		public List<AtomContext> atom() {
			return getRuleContexts(AtomContext.class);
		}
		public AtomContext atom(int i) {
			return getRuleContext(AtomContext.class,i);
		}
		public List<Compare_exprContext> compare_expr() {
			return getRuleContexts(Compare_exprContext.class);
		}
		public Compare_exprContext compare_expr(int i) {
			return getRuleContext(Compare_exprContext.class,i);
		}
		public List<AssignContext> assign() {
			return getRuleContexts(AssignContext.class);
		}
		public AssignContext assign(int i) {
			return getRuleContext(AssignContext.class,i);
		}
		public List<NegationContext> negation() {
			return getRuleContexts(NegationContext.class);
		}
		public NegationContext negation(int i) {
			return getRuleContext(NegationContext.class,i);
		}
		public BodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_body; }
	}

	public final BodyContext body() throws RecognitionException {
		BodyContext _localctx = new BodyContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_body);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			BodyMap body_map;
			setState(157);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(151);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
					case 1:
						{
						setState(139);
						((BodyContext)_localctx).b1 = atom();
						body_map.atoms.emplace_back(((BodyContext)_localctx).b1.r);
						}
						break;
					case 2:
						{
						setState(142);
						((BodyContext)_localctx).b2 = compare_expr();
						body_map.compares.emplace_back(((BodyContext)_localctx).b2.r);
						}
						break;
					case 3:
						{
						setState(145);
						((BodyContext)_localctx).b3 = assign();
						body_map.assigns.emplace_back(((BodyContext)_localctx).b3.r);
						}
						break;
					case 4:
						{
						setState(148);
						((BodyContext)_localctx).b4 = negation();
						body_map.negations.emplace_back(((BodyContext)_localctx).b4.r);
						}
						break;
					}
					setState(153);
					match(TOKEN_COMMA);
					}
					} 
				}
				setState(159);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			}
			setState(172);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				setState(160);
				((BodyContext)_localctx).b5 = atom();
				body_map.atoms.emplace_back(((BodyContext)_localctx).b5.r);
				}
				break;
			case 2:
				{
				setState(163);
				((BodyContext)_localctx).b6 = compare_expr();
				body_map.compares.emplace_back(((BodyContext)_localctx).b6.r);
				}
				break;
			case 3:
				{
				setState(166);
				((BodyContext)_localctx).b7 = assign();
				body_map.assigns.emplace_back(((BodyContext)_localctx).b7.r);
				}
				break;
			case 4:
				{
				setState(169);
				((BodyContext)_localctx).b8 = negation();
				body_map.negations.emplace_back(((BodyContext)_localctx).b8.r);
				}
				break;
			}
			((BodyContext)_localctx).r =  body_map;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NegationContext extends ParserRuleContext {
		public AtomMap r;
		public AtomContext a;
		public TerminalNode TOKEN_NOT() { return getToken(MyDatalogParser.TOKEN_NOT, 0); }
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public NegationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_negation; }
	}

	public final NegationContext negation() throws RecognitionException {
		NegationContext _localctx = new NegationContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_negation);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(176);
			match(TOKEN_NOT);
			setState(177);
			((NegationContext)_localctx).a = atom();
			((NegationContext)_localctx).r =  ((NegationContext)_localctx).a.r;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AtomContext extends ParserRuleContext {
		public AtomMap r;
		public Token a1;
		public Token a2;
		public Aggregation_exprContext a3;
		public Token a4;
		public ConstantContext a5;
		public Math_exprContext a6;
		public Token a7;
		public Aggregation_exprContext a8;
		public Token a9;
		public ConstantContext a10;
		public Math_exprContext a11;
		public TerminalNode TOKEN_LEFT_PAREN() { return getToken(MyDatalogParser.TOKEN_LEFT_PAREN, 0); }
		public TerminalNode TOKEN_RIGHT_PAREN() { return getToken(MyDatalogParser.TOKEN_RIGHT_PAREN, 0); }
		public List<TerminalNode> TOKEN_ID() { return getTokens(MyDatalogParser.TOKEN_ID); }
		public TerminalNode TOKEN_ID(int i) {
			return getToken(MyDatalogParser.TOKEN_ID, i);
		}
		public List<Aggregation_exprContext> aggregation_expr() {
			return getRuleContexts(Aggregation_exprContext.class);
		}
		public Aggregation_exprContext aggregation_expr(int i) {
			return getRuleContext(Aggregation_exprContext.class,i);
		}
		public List<TerminalNode> TOKEN_ANY() { return getTokens(MyDatalogParser.TOKEN_ANY); }
		public TerminalNode TOKEN_ANY(int i) {
			return getToken(MyDatalogParser.TOKEN_ANY, i);
		}
		public List<ConstantContext> constant() {
			return getRuleContexts(ConstantContext.class);
		}
		public ConstantContext constant(int i) {
			return getRuleContext(ConstantContext.class,i);
		}
		public List<Math_exprContext> math_expr() {
			return getRuleContexts(Math_exprContext.class);
		}
		public Math_exprContext math_expr(int i) {
			return getRuleContext(Math_exprContext.class,i);
		}
		public List<TerminalNode> TOKEN_COMMA() { return getTokens(MyDatalogParser.TOKEN_COMMA); }
		public TerminalNode TOKEN_COMMA(int i) {
			return getToken(MyDatalogParser.TOKEN_COMMA, i);
		}
		public AtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_atom; }
	}

	public final AtomContext atom() throws RecognitionException {
		AtomContext _localctx = new AtomContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_atom);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			AtomMap atom_map;
			setState(181);
			((AtomContext)_localctx).a1 = match(TOKEN_ID);
			atom_map.name = (((AtomContext)_localctx).a1!=null?((AtomContext)_localctx).a1.getText():null);
			setState(183);
			match(TOKEN_LEFT_PAREN);
			setState(197);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				{
				setState(184);
				((AtomContext)_localctx).a2 = match(TOKEN_ID);
				atom_map.argList.emplace_back(AtomArg((((AtomContext)_localctx).a2!=null?((AtomContext)_localctx).a2.getText():null), "variable", false));
				}
				break;
			case 2:
				{
				setState(186);
				((AtomContext)_localctx).a3 = aggregation_expr();
				atom_map.argList.emplace_back(AtomArg(((AtomContext)_localctx).a3.r, "aggregation", false));
				}
				break;
			case 3:
				{
				setState(189);
				((AtomContext)_localctx).a4 = match(TOKEN_ANY);
				atom_map.argList.emplace_back(AtomArg((((AtomContext)_localctx).a4!=null?((AtomContext)_localctx).a4.getText():null), "any", false));
				}
				break;
			case 4:
				{
				setState(191);
				((AtomContext)_localctx).a5 = constant();
				atom_map.argList.emplace_back(AtomArg((((AtomContext)_localctx).a5!=null?_input.getText(((AtomContext)_localctx).a5.start,((AtomContext)_localctx).a5.stop):null), "constant", false));
				}
				break;
			case 5:
				{
				setState(194);
				((AtomContext)_localctx).a6 = math_expr();
				atom_map.argList.emplace_back(AtomArg(((AtomContext)_localctx).a6.r, "math_expr", false));
				}
				break;
			}
			setState(217);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==TOKEN_COMMA) {
				{
				{
				setState(199);
				match(TOKEN_COMMA);
				setState(213);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
				case 1:
					{
					setState(200);
					((AtomContext)_localctx).a7 = match(TOKEN_ID);
					atom_map.argList.emplace_back(AtomArg((((AtomContext)_localctx).a7!=null?((AtomContext)_localctx).a7.getText():null), "variable", false));
					}
					break;
				case 2:
					{
					setState(202);
					((AtomContext)_localctx).a8 = aggregation_expr();
					atom_map.argList.emplace_back(AtomArg(((AtomContext)_localctx).a8.r, "aggregation", false));
					}
					break;
				case 3:
					{
					setState(205);
					((AtomContext)_localctx).a9 = match(TOKEN_ANY);
					atom_map.argList.emplace_back(AtomArg((((AtomContext)_localctx).a9!=null?((AtomContext)_localctx).a9.getText():null), "any", false));
					}
					break;
				case 4:
					{
					setState(207);
					((AtomContext)_localctx).a10 = constant();
					atom_map.argList.emplace_back(AtomArg((((AtomContext)_localctx).a10!=null?_input.getText(((AtomContext)_localctx).a10.start,((AtomContext)_localctx).a10.stop):null), "constant", false));
					}
					break;
				case 5:
					{
					setState(210);
					((AtomContext)_localctx).a11 = math_expr();
					atom_map.argList.emplace_back(AtomArg(((AtomContext)_localctx).a11.r, "math_expr", false));
					}
					break;
				}
				}
				}
				setState(219);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(220);
			match(TOKEN_RIGHT_PAREN);
			((AtomContext)_localctx).r =  atom_map;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignContext extends ParserRuleContext {
		public AssignMap r;
		public Token a1;
		public Math_exprContext a2;
		public TerminalNode TOKEN_EQUALS() { return getToken(MyDatalogParser.TOKEN_EQUALS, 0); }
		public TerminalNode TOKEN_ID() { return getToken(MyDatalogParser.TOKEN_ID, 0); }
		public Math_exprContext math_expr() {
			return getRuleContext(Math_exprContext.class,0);
		}
		public AssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assign; }
	}

	public final AssignContext assign() throws RecognitionException {
		AssignContext _localctx = new AssignContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_assign);
		try {
			enterOuterAlt(_localctx, 1);
			{
			AssignMap assign_map;
			setState(224);
			((AssignContext)_localctx).a1 = match(TOKEN_ID);
			assign_map.lhs = (((AssignContext)_localctx).a1!=null?((AssignContext)_localctx).a1.getText():null);
			setState(226);
			match(TOKEN_EQUALS);
			setState(227);
			((AssignContext)_localctx).a2 = math_expr();
			assign_map.rhs = ((AssignContext)_localctx).a2.r;
			((AssignContext)_localctx).r =  assign_map;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Math_exprContext extends ParserRuleContext {
		public MathMap r;
		public Token m1;
		public Math_opContext m2;
		public Token m3;
		public List<TerminalNode> TOKEN_ID() { return getTokens(MyDatalogParser.TOKEN_ID); }
		public TerminalNode TOKEN_ID(int i) {
			return getToken(MyDatalogParser.TOKEN_ID, i);
		}
		public Math_opContext math_op() {
			return getRuleContext(Math_opContext.class,0);
		}
		public Math_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_math_expr; }
	}

	public final Math_exprContext math_expr() throws RecognitionException {
		Math_exprContext _localctx = new Math_exprContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_math_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			MathMap math_map;
			setState(232);
			((Math_exprContext)_localctx).m1 = match(TOKEN_ID);
			math_map.lhs = (((Math_exprContext)_localctx).m1!=null?((Math_exprContext)_localctx).m1.getText():null);
			setState(234);
			((Math_exprContext)_localctx).m2 = math_op();
			math_map.op = (((Math_exprContext)_localctx).m2!=null?_input.getText(((Math_exprContext)_localctx).m2.start,((Math_exprContext)_localctx).m2.stop):null);
			setState(236);
			((Math_exprContext)_localctx).m3 = match(TOKEN_ID);
			math_map.rhs = (((Math_exprContext)_localctx).m3!=null?((Math_exprContext)_localctx).m3.getText():null);
			((Math_exprContext)_localctx).r =  math_map;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Compare_exprContext extends ParserRuleContext {
		public CompareMap r;
		public Token c1;
		public Token c2;
		public Compare_opContext op;
		public Token c3;
		public Token c4;
		public Compare_opContext compare_op() {
			return getRuleContext(Compare_opContext.class,0);
		}
		public List<TerminalNode> TOKEN_ID() { return getTokens(MyDatalogParser.TOKEN_ID); }
		public TerminalNode TOKEN_ID(int i) {
			return getToken(MyDatalogParser.TOKEN_ID, i);
		}
		public List<TerminalNode> TOKEN_INTEGER() { return getTokens(MyDatalogParser.TOKEN_INTEGER); }
		public TerminalNode TOKEN_INTEGER(int i) {
			return getToken(MyDatalogParser.TOKEN_INTEGER, i);
		}
		public Compare_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compare_expr; }
	}

	public final Compare_exprContext compare_expr() throws RecognitionException {
		Compare_exprContext _localctx = new Compare_exprContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_compare_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			CompareMap compare_map;
			setState(245);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TOKEN_ID:
				{
				setState(241);
				((Compare_exprContext)_localctx).c1 = match(TOKEN_ID);
				compare_map.lhsText = (((Compare_exprContext)_localctx).c1!=null?((Compare_exprContext)_localctx).c1.getText():null); compare_map.lhsType = "var";
				}
				break;
			case TOKEN_INTEGER:
				{
				setState(243);
				((Compare_exprContext)_localctx).c2 = match(TOKEN_INTEGER);
				compare_map.lhsText = (((Compare_exprContext)_localctx).c2!=null?((Compare_exprContext)_localctx).c2.getText():null); compare_map.lhsType = "num";
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(247);
			((Compare_exprContext)_localctx).op = compare_op();
			compare_map.op = ((Compare_exprContext)_localctx).op.r;
			setState(253);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TOKEN_ID:
				{
				setState(249);
				((Compare_exprContext)_localctx).c3 = match(TOKEN_ID);
				compare_map.rhsText = (((Compare_exprContext)_localctx).c3!=null?((Compare_exprContext)_localctx).c3.getText():null); compare_map.rhsType = "var";
				}
				break;
			case TOKEN_INTEGER:
				{
				setState(251);
				((Compare_exprContext)_localctx).c4 = match(TOKEN_INTEGER);
				compare_map.rhsText = (((Compare_exprContext)_localctx).c4!=null?((Compare_exprContext)_localctx).c4.getText():null); compare_map.rhsType = "num";
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			((Compare_exprContext)_localctx).r =  compare_map;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Aggregation_exprContext extends ParserRuleContext {
		public AggMap r;
		public Aggregation_opContext a1;
		public Token a2;
		public Math_exprContext a3;
		public TerminalNode TOKEN_LEFT_PAREN() { return getToken(MyDatalogParser.TOKEN_LEFT_PAREN, 0); }
		public TerminalNode TOKEN_RIGHT_PAREN() { return getToken(MyDatalogParser.TOKEN_RIGHT_PAREN, 0); }
		public Aggregation_opContext aggregation_op() {
			return getRuleContext(Aggregation_opContext.class,0);
		}
		public TerminalNode TOKEN_ID() { return getToken(MyDatalogParser.TOKEN_ID, 0); }
		public Math_exprContext math_expr() {
			return getRuleContext(Math_exprContext.class,0);
		}
		public Aggregation_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_aggregation_expr; }
	}

	public final Aggregation_exprContext aggregation_expr() throws RecognitionException {
		Aggregation_exprContext _localctx = new Aggregation_exprContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_aggregation_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			AggMap agg_map;
			setState(258);
			((Aggregation_exprContext)_localctx).a1 = aggregation_op();
			agg_map.aggOp = ((Aggregation_exprContext)_localctx).a1.r;
			setState(260);
			match(TOKEN_LEFT_PAREN);
			setState(266);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				{
				setState(261);
				((Aggregation_exprContext)_localctx).a2 = match(TOKEN_ID);
				agg_map.aggArg.type = "attribute", agg_map.aggArg.attr = (((Aggregation_exprContext)_localctx).a2!=null?((Aggregation_exprContext)_localctx).a2.getText():null);
				}
				break;
			case 2:
				{
				setState(263);
				((Aggregation_exprContext)_localctx).a3 = math_expr();
				agg_map.aggArg.type = "math_expr", agg_map.aggArg.mathExpr = ((Aggregation_exprContext)_localctx).a3.r;
				}
				break;
			}
			setState(268);
			match(TOKEN_RIGHT_PAREN);
			((Aggregation_exprContext)_localctx).r =  agg_map;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AttributeContext extends ParserRuleContext {
		public AttributeMap r;
		public Non_key_attributeContext a1;
		public Key_attributeContext a2;
		public Non_key_attributeContext non_key_attribute() {
			return getRuleContext(Non_key_attributeContext.class,0);
		}
		public Key_attributeContext key_attribute() {
			return getRuleContext(Key_attributeContext.class,0);
		}
		public AttributeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_attribute; }
	}

	public final AttributeContext attribute() throws RecognitionException {
		AttributeContext _localctx = new AttributeContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_attribute);
		try {
			setState(277);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TOKEN_ID:
				enterOuterAlt(_localctx, 1);
				{
				setState(271);
				((AttributeContext)_localctx).a1 = non_key_attribute();
				((AttributeContext)_localctx).r =  ((AttributeContext)_localctx).a1.r;
				}
				break;
			case TOKEN_LEFT_BRACKET:
				enterOuterAlt(_localctx, 2);
				{
				setState(274);
				((AttributeContext)_localctx).a2 = key_attribute();
				((AttributeContext)_localctx).r =  ((AttributeContext)_localctx).a2.r;
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Key_attributeContext extends ParserRuleContext {
		public AttributeMap r;
		public Token a1;
		public Data_typeContext d1;
		public TerminalNode TOKEN_LEFT_BRACKET() { return getToken(MyDatalogParser.TOKEN_LEFT_BRACKET, 0); }
		public TerminalNode TOKEN_RIGHT_BRACKET() { return getToken(MyDatalogParser.TOKEN_RIGHT_BRACKET, 0); }
		public TerminalNode TOKEN_ID() { return getToken(MyDatalogParser.TOKEN_ID, 0); }
		public Data_typeContext data_type() {
			return getRuleContext(Data_typeContext.class,0);
		}
		public Key_attributeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_key_attribute; }
	}

	public final Key_attributeContext key_attribute() throws RecognitionException {
		Key_attributeContext _localctx = new Key_attributeContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_key_attribute);
		try {
			enterOuterAlt(_localctx, 1);
			{
			AttributeMap attr_map{"", "", true};
			setState(280);
			match(TOKEN_LEFT_BRACKET);
			setState(281);
			((Key_attributeContext)_localctx).a1 = match(TOKEN_ID);
			attr_map.name = (((Key_attributeContext)_localctx).a1!=null?((Key_attributeContext)_localctx).a1.getText():null);
			setState(283);
			match(TOKEN_RIGHT_BRACKET);
			setState(284);
			((Key_attributeContext)_localctx).d1 = data_type();
			attr_map.type = ((Key_attributeContext)_localctx).d1.r;
			((Key_attributeContext)_localctx).r =  attr_map;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Non_key_attributeContext extends ParserRuleContext {
		public AttributeMap r;
		public Token a1;
		public Data_typeContext d1;
		public TerminalNode TOKEN_ID() { return getToken(MyDatalogParser.TOKEN_ID, 0); }
		public Data_typeContext data_type() {
			return getRuleContext(Data_typeContext.class,0);
		}
		public Non_key_attributeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_non_key_attribute; }
	}

	public final Non_key_attributeContext non_key_attribute() throws RecognitionException {
		Non_key_attributeContext _localctx = new Non_key_attributeContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_non_key_attribute);
		try {
			enterOuterAlt(_localctx, 1);
			{
			AttributeMap attr_map{"", "", false};
			setState(289);
			((Non_key_attributeContext)_localctx).a1 = match(TOKEN_ID);
			attr_map.name = (((Non_key_attributeContext)_localctx).a1!=null?((Non_key_attributeContext)_localctx).a1.getText():null);
			setState(291);
			((Non_key_attributeContext)_localctx).d1 = data_type();
			attr_map.type = ((Non_key_attributeContext)_localctx).d1.r;
			((Non_key_attributeContext)_localctx).r =  attr_map;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Compare_opContext extends ParserRuleContext {
		public string r;
		public Token op1;
		public Token op2;
		public Token op3;
		public Token op4;
		public Token op5;
		public Token op6;
		public TerminalNode TOKEN_NOT_EQUALS() { return getToken(MyDatalogParser.TOKEN_NOT_EQUALS, 0); }
		public TerminalNode TOKEN_EQUALS() { return getToken(MyDatalogParser.TOKEN_EQUALS, 0); }
		public TerminalNode TOKEN_GREATER_THAN() { return getToken(MyDatalogParser.TOKEN_GREATER_THAN, 0); }
		public TerminalNode TOKEN_GREATER_EQUAL_THAN() { return getToken(MyDatalogParser.TOKEN_GREATER_EQUAL_THAN, 0); }
		public TerminalNode TOKEN_LESS_THAN() { return getToken(MyDatalogParser.TOKEN_LESS_THAN, 0); }
		public TerminalNode TOKEN_LESS_EQUAL_THAN() { return getToken(MyDatalogParser.TOKEN_LESS_EQUAL_THAN, 0); }
		public Compare_opContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compare_op; }
	}

	public final Compare_opContext compare_op() throws RecognitionException {
		Compare_opContext _localctx = new Compare_opContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_compare_op);
		try {
			setState(307);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TOKEN_NOT_EQUALS:
				enterOuterAlt(_localctx, 1);
				{
				setState(295);
				((Compare_opContext)_localctx).op1 = match(TOKEN_NOT_EQUALS);
				((Compare_opContext)_localctx).r =  (((Compare_opContext)_localctx).op1!=null?((Compare_opContext)_localctx).op1.getText():null);
				}
				break;
			case TOKEN_EQUALS:
				enterOuterAlt(_localctx, 2);
				{
				setState(297);
				((Compare_opContext)_localctx).op2 = match(TOKEN_EQUALS);
				((Compare_opContext)_localctx).r =  (((Compare_opContext)_localctx).op2!=null?((Compare_opContext)_localctx).op2.getText():null);
				}
				break;
			case TOKEN_GREATER_THAN:
				enterOuterAlt(_localctx, 3);
				{
				setState(299);
				((Compare_opContext)_localctx).op3 = match(TOKEN_GREATER_THAN);
				((Compare_opContext)_localctx).r =  (((Compare_opContext)_localctx).op3!=null?((Compare_opContext)_localctx).op3.getText():null);
				}
				break;
			case TOKEN_GREATER_EQUAL_THAN:
				enterOuterAlt(_localctx, 4);
				{
				setState(301);
				((Compare_opContext)_localctx).op4 = match(TOKEN_GREATER_EQUAL_THAN);
				((Compare_opContext)_localctx).r =  (((Compare_opContext)_localctx).op4!=null?((Compare_opContext)_localctx).op4.getText():null);
				}
				break;
			case TOKEN_LESS_THAN:
				enterOuterAlt(_localctx, 5);
				{
				setState(303);
				((Compare_opContext)_localctx).op5 = match(TOKEN_LESS_THAN);
				((Compare_opContext)_localctx).r =  (((Compare_opContext)_localctx).op5!=null?((Compare_opContext)_localctx).op5.getText():null);
				}
				break;
			case TOKEN_LESS_EQUAL_THAN:
				enterOuterAlt(_localctx, 6);
				{
				setState(305);
				((Compare_opContext)_localctx).op6 = match(TOKEN_LESS_EQUAL_THAN);
				((Compare_opContext)_localctx).r =  (((Compare_opContext)_localctx).op6!=null?((Compare_opContext)_localctx).op6.getText():null);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Aggregation_opContext extends ParserRuleContext {
		public string r;
		public Token op1;
		public Token op2;
		public Token op3;
		public Token op4;
		public Token op5;
		public TerminalNode TOKEN_MIN() { return getToken(MyDatalogParser.TOKEN_MIN, 0); }
		public TerminalNode TOKEN_MAX() { return getToken(MyDatalogParser.TOKEN_MAX, 0); }
		public TerminalNode TOKEN_SUM() { return getToken(MyDatalogParser.TOKEN_SUM, 0); }
		public TerminalNode TOKEN_COUNT() { return getToken(MyDatalogParser.TOKEN_COUNT, 0); }
		public TerminalNode TOKEN_COUNT_DISTINCT() { return getToken(MyDatalogParser.TOKEN_COUNT_DISTINCT, 0); }
		public Aggregation_opContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_aggregation_op; }
	}

	public final Aggregation_opContext aggregation_op() throws RecognitionException {
		Aggregation_opContext _localctx = new Aggregation_opContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_aggregation_op);
		try {
			setState(319);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TOKEN_MIN:
				enterOuterAlt(_localctx, 1);
				{
				setState(309);
				((Aggregation_opContext)_localctx).op1 = match(TOKEN_MIN);
				((Aggregation_opContext)_localctx).r =  (((Aggregation_opContext)_localctx).op1!=null?((Aggregation_opContext)_localctx).op1.getText():null);
				}
				break;
			case TOKEN_MAX:
				enterOuterAlt(_localctx, 2);
				{
				setState(311);
				((Aggregation_opContext)_localctx).op2 = match(TOKEN_MAX);
				((Aggregation_opContext)_localctx).r =  (((Aggregation_opContext)_localctx).op2!=null?((Aggregation_opContext)_localctx).op2.getText():null);
				}
				break;
			case TOKEN_SUM:
				enterOuterAlt(_localctx, 3);
				{
				setState(313);
				((Aggregation_opContext)_localctx).op3 = match(TOKEN_SUM);
				((Aggregation_opContext)_localctx).r =  (((Aggregation_opContext)_localctx).op3!=null?((Aggregation_opContext)_localctx).op3.getText():null);
				}
				break;
			case TOKEN_COUNT:
				enterOuterAlt(_localctx, 4);
				{
				setState(315);
				((Aggregation_opContext)_localctx).op4 = match(TOKEN_COUNT);
				((Aggregation_opContext)_localctx).r =  (((Aggregation_opContext)_localctx).op4!=null?((Aggregation_opContext)_localctx).op4.getText():null);
				}
				break;
			case TOKEN_COUNT_DISTINCT:
				enterOuterAlt(_localctx, 5);
				{
				setState(317);
				((Aggregation_opContext)_localctx).op5 = match(TOKEN_COUNT_DISTINCT);
				((Aggregation_opContext)_localctx).r =  (((Aggregation_opContext)_localctx).op5!=null?((Aggregation_opContext)_localctx).op5.getText():null);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Math_opContext extends ParserRuleContext {
		public string r;
		public Token op1;
		public Token op2;
		public Token op3;
		public Token op4;
		public TerminalNode TOKEN_PLUS() { return getToken(MyDatalogParser.TOKEN_PLUS, 0); }
		public TerminalNode TOKEN_MINUS() { return getToken(MyDatalogParser.TOKEN_MINUS, 0); }
		public TerminalNode TOKEN_MULT() { return getToken(MyDatalogParser.TOKEN_MULT, 0); }
		public TerminalNode TOKEN_DIV() { return getToken(MyDatalogParser.TOKEN_DIV, 0); }
		public Math_opContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_math_op; }
	}

	public final Math_opContext math_op() throws RecognitionException {
		Math_opContext _localctx = new Math_opContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_math_op);
		try {
			setState(329);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TOKEN_PLUS:
				enterOuterAlt(_localctx, 1);
				{
				setState(321);
				((Math_opContext)_localctx).op1 = match(TOKEN_PLUS);
				((Math_opContext)_localctx).r =  (((Math_opContext)_localctx).op1!=null?((Math_opContext)_localctx).op1.getText():null);
				}
				break;
			case TOKEN_MINUS:
				enterOuterAlt(_localctx, 2);
				{
				setState(323);
				((Math_opContext)_localctx).op2 = match(TOKEN_MINUS);
				((Math_opContext)_localctx).r =  (((Math_opContext)_localctx).op2!=null?((Math_opContext)_localctx).op2.getText():null);
				}
				break;
			case TOKEN_MULT:
				enterOuterAlt(_localctx, 3);
				{
				setState(325);
				((Math_opContext)_localctx).op3 = match(TOKEN_MULT);
				((Math_opContext)_localctx).r =  (((Math_opContext)_localctx).op3!=null?((Math_opContext)_localctx).op3.getText():null);
				}
				break;
			case TOKEN_DIV:
				enterOuterAlt(_localctx, 4);
				{
				setState(327);
				((Math_opContext)_localctx).op4 = match(TOKEN_DIV);
				((Math_opContext)_localctx).r =  (((Math_opContext)_localctx).op4!=null?((Math_opContext)_localctx).op4.getText():null);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantContext extends ParserRuleContext {
		public string r;
		public Token c1;
		public Token c2;
		public TerminalNode TOKEN_INTEGER() { return getToken(MyDatalogParser.TOKEN_INTEGER, 0); }
		public TerminalNode TOKEN_STRING() { return getToken(MyDatalogParser.TOKEN_STRING, 0); }
		public ConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant; }
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_constant);
		try {
			setState(335);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TOKEN_INTEGER:
				enterOuterAlt(_localctx, 1);
				{
				setState(331);
				((ConstantContext)_localctx).c1 = match(TOKEN_INTEGER);
				((ConstantContext)_localctx).r =  (((ConstantContext)_localctx).c1!=null?((ConstantContext)_localctx).c1.getText():null);
				}
				break;
			case TOKEN_STRING:
				enterOuterAlt(_localctx, 2);
				{
				setState(333);
				((ConstantContext)_localctx).c2 = match(TOKEN_STRING);
				((ConstantContext)_localctx).r =  (((ConstantContext)_localctx).c2!=null?((ConstantContext)_localctx).c2.getText():null);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Data_typeContext extends ParserRuleContext {
		public string r;
		public Token dt1;
		public Token dt2;
		public Token dt3;
		public Token dt4;
		public Token dt5;
		public Token dt6;
		public Token dt7;
		public Token dt8;
		public TerminalNode TOKEN_INT() { return getToken(MyDatalogParser.TOKEN_INT, 0); }
		public TerminalNode TOKEN_LONG() { return getToken(MyDatalogParser.TOKEN_LONG, 0); }
		public TerminalNode TOKEN_FLOAT() { return getToken(MyDatalogParser.TOKEN_FLOAT, 0); }
		public TerminalNode TOKEN_DOUBLE() { return getToken(MyDatalogParser.TOKEN_DOUBLE, 0); }
		public TerminalNode TOKEN_VARCHAR() { return getToken(MyDatalogParser.TOKEN_VARCHAR, 0); }
		public TerminalNode TOKEN_CHAR() { return getToken(MyDatalogParser.TOKEN_CHAR, 0); }
		public TerminalNode TOKEN_DATE() { return getToken(MyDatalogParser.TOKEN_DATE, 0); }
		public TerminalNode TOKEN_DATETIME() { return getToken(MyDatalogParser.TOKEN_DATETIME, 0); }
		public Data_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_data_type; }
	}

	public final Data_typeContext data_type() throws RecognitionException {
		Data_typeContext _localctx = new Data_typeContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_data_type);
		try {
			setState(353);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TOKEN_INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(337);
				((Data_typeContext)_localctx).dt1 = match(TOKEN_INT);
				((Data_typeContext)_localctx).r =  (((Data_typeContext)_localctx).dt1!=null?((Data_typeContext)_localctx).dt1.getText():null);
				}
				break;
			case TOKEN_LONG:
				enterOuterAlt(_localctx, 2);
				{
				setState(339);
				((Data_typeContext)_localctx).dt2 = match(TOKEN_LONG);
				((Data_typeContext)_localctx).r =  (((Data_typeContext)_localctx).dt2!=null?((Data_typeContext)_localctx).dt2.getText():null);
				}
				break;
			case TOKEN_FLOAT:
				enterOuterAlt(_localctx, 3);
				{
				setState(341);
				((Data_typeContext)_localctx).dt3 = match(TOKEN_FLOAT);
				((Data_typeContext)_localctx).r =  (((Data_typeContext)_localctx).dt3!=null?((Data_typeContext)_localctx).dt3.getText():null);
				}
				break;
			case TOKEN_DOUBLE:
				enterOuterAlt(_localctx, 4);
				{
				setState(343);
				((Data_typeContext)_localctx).dt4 = match(TOKEN_DOUBLE);
				((Data_typeContext)_localctx).r =  (((Data_typeContext)_localctx).dt4!=null?((Data_typeContext)_localctx).dt4.getText():null);
				}
				break;
			case TOKEN_VARCHAR:
				enterOuterAlt(_localctx, 5);
				{
				setState(345);
				((Data_typeContext)_localctx).dt5 = match(TOKEN_VARCHAR);
				((Data_typeContext)_localctx).r =  (((Data_typeContext)_localctx).dt5!=null?((Data_typeContext)_localctx).dt5.getText():null);
				}
				break;
			case TOKEN_CHAR:
				enterOuterAlt(_localctx, 6);
				{
				setState(347);
				((Data_typeContext)_localctx).dt6 = match(TOKEN_CHAR);
				((Data_typeContext)_localctx).r =  (((Data_typeContext)_localctx).dt6!=null?((Data_typeContext)_localctx).dt6.getText():null);
				}
				break;
			case TOKEN_DATE:
				enterOuterAlt(_localctx, 7);
				{
				setState(349);
				((Data_typeContext)_localctx).dt7 = match(TOKEN_DATE);
				((Data_typeContext)_localctx).r =  (((Data_typeContext)_localctx).dt7!=null?((Data_typeContext)_localctx).dt7.getText():null);
				}
				break;
			case TOKEN_DATETIME:
				enterOuterAlt(_localctx, 8);
				{
				setState(351);
				((Data_typeContext)_localctx).dt8 = match(TOKEN_DATETIME);
				((Data_typeContext)_localctx).r =  (((Data_typeContext)_localctx).dt8!=null?((Data_typeContext)_localctx).dt8.getText():null);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3.\u0166\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\7\2\67\n\2\f\2\16\2:\13\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\7\3F\n\3\f\3\16\3I\13\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\7\4W\n\4\f\4\16\4Z\13\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\6\3\6\3\6\3\6\3\6\3\6\7\6k\n\6\f\6\16\6n\13\6\3\6\3\6\3\7\3\7\3\7\5"+
		"\7u\n\7\3\7\3\7\5\7y\n\7\3\7\3\7\5\7}\n\7\3\7\3\7\3\7\3\7\3\7\3\7\5\7"+
		"\u0085\n\7\3\7\3\7\3\7\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t"+
		"\3\t\3\t\3\t\3\t\5\t\u009a\n\t\3\t\3\t\7\t\u009e\n\t\f\t\16\t\u00a1\13"+
		"\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\5\t\u00af\n\t\3\t\3"+
		"\t\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3"+
		"\13\3\13\3\13\3\13\3\13\3\13\3\13\5\13\u00c8\n\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\5\13\u00d8\n\13\7\13"+
		"\u00da\n\13\f\13\16\13\u00dd\13\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f"+
		"\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3"+
		"\16\5\16\u00f8\n\16\3\16\3\16\3\16\3\16\3\16\3\16\5\16\u0100\n\16\3\16"+
		"\3\16\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\5\17\u010d\n\17\3\17"+
		"\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\20\5\20\u0118\n\20\3\21\3\21\3\21"+
		"\3\21\3\21\3\21\3\21\3\21\3\21\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\23"+
		"\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\5\23\u0136\n\23"+
		"\3\24\3\24\3\24\3\24\3\24\3\24\3\24\3\24\3\24\3\24\5\24\u0142\n\24\3\25"+
		"\3\25\3\25\3\25\3\25\3\25\3\25\3\25\5\25\u014c\n\25\3\26\3\26\3\26\3\26"+
		"\5\26\u0152\n\26\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27\3\27"+
		"\3\27\3\27\3\27\3\27\3\27\5\27\u0164\n\27\3\27\2\2\30\2\4\6\b\n\f\16\20"+
		"\22\24\26\30\32\34\36 \"$&(*,\2\2\2\u017f\2.\3\2\2\2\4=\3\2\2\2\6L\3\2"+
		"\2\2\b^\3\2\2\2\nd\3\2\2\2\fq\3\2\2\2\16\u0089\3\2\2\2\20\u008c\3\2\2"+
		"\2\22\u00b2\3\2\2\2\24\u00b6\3\2\2\2\26\u00e1\3\2\2\2\30\u00e9\3\2\2\2"+
		"\32\u00f2\3\2\2\2\34\u0103\3\2\2\2\36\u0117\3\2\2\2 \u0119\3\2\2\2\"\u0122"+
		"\3\2\2\2$\u0135\3\2\2\2&\u0141\3\2\2\2(\u014b\3\2\2\2*\u0151\3\2\2\2,"+
		"\u0163\3\2\2\2./\b\2\1\2/\60\7\3\2\2\60\61\7\32\2\2\61\62\5\6\4\2\628"+
		"\b\2\1\2\63\64\5\6\4\2\64\65\b\2\1\2\65\67\3\2\2\2\66\63\3\2\2\2\67:\3"+
		"\2\2\28\66\3\2\2\289\3\2\2\29;\3\2\2\2:8\3\2\2\2;<\b\2\1\2<\3\3\2\2\2"+
		"=>\b\3\1\2>?\7\4\2\2?@\7\32\2\2@A\5\6\4\2AG\b\3\1\2BC\5\6\4\2CD\b\3\1"+
		"\2DF\3\2\2\2EB\3\2\2\2FI\3\2\2\2GE\3\2\2\2GH\3\2\2\2HJ\3\2\2\2IG\3\2\2"+
		"\2JK\b\3\1\2K\5\3\2\2\2LM\b\4\1\2MN\7\25\2\2NO\b\4\1\2OP\7*\2\2PQ\5\36"+
		"\20\2QX\b\4\1\2RS\7\30\2\2ST\5\36\20\2TU\b\4\1\2UW\3\2\2\2VR\3\2\2\2W"+
		"Z\3\2\2\2XV\3\2\2\2XY\3\2\2\2Y[\3\2\2\2ZX\3\2\2\2[\\\7+\2\2\\]\b\4\1\2"+
		"]\7\3\2\2\2^_\7\5\2\2_`\7\32\2\2`a\5\n\6\2ab\b\5\1\2bc\7\2\2\3c\t\3\2"+
		"\2\2de\b\6\1\2ef\5\f\7\2fl\b\6\1\2gh\5\f\7\2hi\b\6\1\2ik\3\2\2\2jg\3\2"+
		"\2\2kn\3\2\2\2lj\3\2\2\2lm\3\2\2\2mo\3\2\2\2nl\3\2\2\2op\b\6\1\2p\13\3"+
		"\2\2\2qt\b\7\1\2rs\7!\2\2su\b\7\1\2tr\3\2\2\2tu\3\2\2\2ux\3\2\2\2vw\7"+
		"\"\2\2wy\b\7\1\2xv\3\2\2\2xy\3\2\2\2y|\3\2\2\2z{\7#\2\2{}\b\7\1\2|z\3"+
		"\2\2\2|}\3\2\2\2}~\3\2\2\2~\177\5\16\b\2\177\u0080\b\7\1\2\u0080\u0084"+
		"\7\26\2\2\u0081\u0082\5\20\t\2\u0082\u0083\b\7\1\2\u0083\u0085\3\2\2\2"+
		"\u0084\u0081\3\2\2\2\u0084\u0085\3\2\2\2\u0085\u0086\3\2\2\2\u0086\u0087"+
		"\7\33\2\2\u0087\u0088\b\7\1\2\u0088\r\3\2\2\2\u0089\u008a\5\24\13\2\u008a"+
		"\u008b\b\b\1\2\u008b\17\3\2\2\2\u008c\u009f\b\t\1\2\u008d\u008e\5\24\13"+
		"\2\u008e\u008f\b\t\1\2\u008f\u009a\3\2\2\2\u0090\u0091\5\32\16\2\u0091"+
		"\u0092\b\t\1\2\u0092\u009a\3\2\2\2\u0093\u0094\5\26\f\2\u0094\u0095\b"+
		"\t\1\2\u0095\u009a\3\2\2\2\u0096\u0097\5\22\n\2\u0097\u0098\b\t\1\2\u0098"+
		"\u009a\3\2\2\2\u0099\u008d\3\2\2\2\u0099\u0090\3\2\2\2\u0099\u0093\3\2"+
		"\2\2\u0099\u0096\3\2\2\2\u009a\u009b\3\2\2\2\u009b\u009c\7\30\2\2\u009c"+
		"\u009e\3\2\2\2\u009d\u0099\3\2\2\2\u009e\u00a1\3\2\2\2\u009f\u009d\3\2"+
		"\2\2\u009f\u00a0\3\2\2\2\u00a0\u00ae\3\2\2\2\u00a1\u009f\3\2\2\2\u00a2"+
		"\u00a3\5\24\13\2\u00a3\u00a4\b\t\1\2\u00a4\u00af\3\2\2\2\u00a5\u00a6\5"+
		"\32\16\2\u00a6\u00a7\b\t\1\2\u00a7\u00af\3\2\2\2\u00a8\u00a9\5\26\f\2"+
		"\u00a9\u00aa\b\t\1\2\u00aa\u00af\3\2\2\2\u00ab\u00ac\5\22\n\2\u00ac\u00ad"+
		"\b\t\1\2\u00ad\u00af\3\2\2\2\u00ae\u00a2\3\2\2\2\u00ae\u00a5\3\2\2\2\u00ae"+
		"\u00a8\3\2\2\2\u00ae\u00ab\3\2\2\2\u00af\u00b0\3\2\2\2\u00b0\u00b1\b\t"+
		"\1\2\u00b1\21\3\2\2\2\u00b2\u00b3\7 \2\2\u00b3\u00b4\5\24\13\2\u00b4\u00b5"+
		"\b\n\1\2\u00b5\23\3\2\2\2\u00b6\u00b7\b\13\1\2\u00b7\u00b8\7\25\2\2\u00b8"+
		"\u00b9\b\13\1\2\u00b9\u00c7\7*\2\2\u00ba\u00bb\7\25\2\2\u00bb\u00c8\b"+
		"\13\1\2\u00bc\u00bd\5\34\17\2\u00bd\u00be\b\13\1\2\u00be\u00c8\3\2\2\2"+
		"\u00bf\u00c0\7\27\2\2\u00c0\u00c8\b\13\1\2\u00c1\u00c2\5*\26\2\u00c2\u00c3"+
		"\b\13\1\2\u00c3\u00c8\3\2\2\2\u00c4\u00c5\5\30\r\2\u00c5\u00c6\b\13\1"+
		"\2\u00c6\u00c8\3\2\2\2\u00c7\u00ba\3\2\2\2\u00c7\u00bc\3\2\2\2\u00c7\u00bf"+
		"\3\2\2\2\u00c7\u00c1\3\2\2\2\u00c7\u00c4\3\2\2\2\u00c8\u00db\3\2\2\2\u00c9"+
		"\u00d7\7\30\2\2\u00ca\u00cb\7\25\2\2\u00cb\u00d8\b\13\1\2\u00cc\u00cd"+
		"\5\34\17\2\u00cd\u00ce\b\13\1\2\u00ce\u00d8\3\2\2\2\u00cf\u00d0\7\27\2"+
		"\2\u00d0\u00d8\b\13\1\2\u00d1\u00d2\5*\26\2\u00d2\u00d3\b\13\1\2\u00d3"+
		"\u00d8\3\2\2\2\u00d4\u00d5\5\30\r\2\u00d5\u00d6\b\13\1\2\u00d6\u00d8\3"+
		"\2\2\2\u00d7\u00ca\3\2\2\2\u00d7\u00cc\3\2\2\2\u00d7\u00cf\3\2\2\2\u00d7"+
		"\u00d1\3\2\2\2\u00d7\u00d4\3\2\2\2\u00d8\u00da\3\2\2\2\u00d9\u00c9\3\2"+
		"\2\2\u00da\u00dd\3\2\2\2\u00db\u00d9\3\2\2\2\u00db\u00dc\3\2\2\2\u00dc"+
		"\u00de\3\2\2\2\u00dd\u00db\3\2\2\2\u00de\u00df\7+\2\2\u00df\u00e0\b\13"+
		"\1\2\u00e0\25\3\2\2\2\u00e1\u00e2\b\f\1\2\u00e2\u00e3\7\25\2\2\u00e3\u00e4"+
		"\b\f\1\2\u00e4\u00e5\7%\2\2\u00e5\u00e6\5\30\r\2\u00e6\u00e7\b\f\1\2\u00e7"+
		"\u00e8\b\f\1\2\u00e8\27\3\2\2\2\u00e9\u00ea\b\r\1\2\u00ea\u00eb\7\25\2"+
		"\2\u00eb\u00ec\b\r\1\2\u00ec\u00ed\5(\25\2\u00ed\u00ee\b\r\1\2\u00ee\u00ef"+
		"\7\25\2\2\u00ef\u00f0\b\r\1\2\u00f0\u00f1\b\r\1\2\u00f1\31\3\2\2\2\u00f2"+
		"\u00f7\b\16\1\2\u00f3\u00f4\7\25\2\2\u00f4\u00f8\b\16\1\2\u00f5\u00f6"+
		"\7\6\2\2\u00f6\u00f8\b\16\1\2\u00f7\u00f3\3\2\2\2\u00f7\u00f5\3\2\2\2"+
		"\u00f8\u00f9\3\2\2\2\u00f9\u00fa\5$\23\2\u00fa\u00ff\b\16\1\2\u00fb\u00fc"+
		"\7\25\2\2\u00fc\u0100\b\16\1\2\u00fd\u00fe\7\6\2\2\u00fe\u0100\b\16\1"+
		"\2\u00ff\u00fb\3\2\2\2\u00ff\u00fd\3\2\2\2\u0100\u0101\3\2\2\2\u0101\u0102"+
		"\b\16\1\2\u0102\33\3\2\2\2\u0103\u0104\b\17\1\2\u0104\u0105\5&\24\2\u0105"+
		"\u0106\b\17\1\2\u0106\u010c\7*\2\2\u0107\u0108\7\25\2\2\u0108\u010d\b"+
		"\17\1\2\u0109\u010a\5\30\r\2\u010a\u010b\b\17\1\2\u010b\u010d\3\2\2\2"+
		"\u010c\u0107\3\2\2\2\u010c\u0109\3\2\2\2\u010d\u010e\3\2\2\2\u010e\u010f"+
		"\7+\2\2\u010f\u0110\b\17\1\2\u0110\35\3\2\2\2\u0111\u0112\5\"\22\2\u0112"+
		"\u0113\b\20\1\2\u0113\u0118\3\2\2\2\u0114\u0115\5 \21\2\u0115\u0116\b"+
		"\20\1\2\u0116\u0118\3\2\2\2\u0117\u0111\3\2\2\2\u0117\u0114\3\2\2\2\u0118"+
		"\37\3\2\2\2\u0119\u011a\b\21\1\2\u011a\u011b\7,\2\2\u011b\u011c\7\25\2"+
		"\2\u011c\u011d\b\21\1\2\u011d\u011e\7-\2\2\u011e\u011f\5,\27\2\u011f\u0120"+
		"\b\21\1\2\u0120\u0121\b\21\1\2\u0121!\3\2\2\2\u0122\u0123\b\22\1\2\u0123"+
		"\u0124\7\25\2\2\u0124\u0125\b\22\1\2\u0125\u0126\5,\27\2\u0126\u0127\b"+
		"\22\1\2\u0127\u0128\b\22\1\2\u0128#\3\2\2\2\u0129\u012a\7$\2\2\u012a\u0136"+
		"\b\23\1\2\u012b\u012c\7%\2\2\u012c\u0136\b\23\1\2\u012d\u012e\7\'\2\2"+
		"\u012e\u0136\b\23\1\2\u012f\u0130\7&\2\2\u0130\u0136\b\23\1\2\u0131\u0132"+
		"\7)\2\2\u0132\u0136\b\23\1\2\u0133\u0134\7(\2\2\u0134\u0136\b\23\1\2\u0135"+
		"\u0129\3\2\2\2\u0135\u012b\3\2\2\2\u0135\u012d\3\2\2\2\u0135\u012f\3\2"+
		"\2\2\u0135\u0131\3\2\2\2\u0135\u0133\3\2\2\2\u0136%\3\2\2\2\u0137\u0138"+
		"\7\20\2\2\u0138\u0142\b\24\1\2\u0139\u013a\7\21\2\2\u013a\u0142\b\24\1"+
		"\2\u013b\u013c\7\22\2\2\u013c\u0142\b\24\1\2\u013d\u013e\7\23\2\2\u013e"+
		"\u0142\b\24\1\2\u013f\u0140\7\24\2\2\u0140\u0142\b\24\1\2\u0141\u0137"+
		"\3\2\2\2\u0141\u0139\3\2\2\2\u0141\u013b\3\2\2\2\u0141\u013d\3\2\2\2\u0141"+
		"\u013f\3\2\2\2\u0142\'\3\2\2\2\u0143\u0144\7\34\2\2\u0144\u014c\b\25\1"+
		"\2\u0145\u0146\7\35\2\2\u0146\u014c\b\25\1\2\u0147\u0148\7\36\2\2\u0148"+
		"\u014c\b\25\1\2\u0149\u014a\7\37\2\2\u014a\u014c\b\25\1\2\u014b\u0143"+
		"\3\2\2\2\u014b\u0145\3\2\2\2\u014b\u0147\3\2\2\2\u014b\u0149\3\2\2\2\u014c"+
		")\3\2\2\2\u014d\u014e\7\6\2\2\u014e\u0152\b\26\1\2\u014f\u0150\7\7\2\2"+
		"\u0150\u0152\b\26\1\2\u0151\u014d\3\2\2\2\u0151\u014f\3\2\2\2\u0152+\3"+
		"\2\2\2\u0153\u0154\7\b\2\2\u0154\u0164\b\27\1\2\u0155\u0156\7\t\2\2\u0156"+
		"\u0164\b\27\1\2\u0157\u0158\7\n\2\2\u0158\u0164\b\27\1\2\u0159\u015a\7"+
		"\13\2\2\u015a\u0164\b\27\1\2\u015b\u015c\7\f\2\2\u015c\u0164\b\27\1\2"+
		"\u015d\u015e\7\r\2\2\u015e\u0164\b\27\1\2\u015f\u0160\7\16\2\2\u0160\u0164"+
		"\b\27\1\2\u0161\u0162\7\17\2\2\u0162\u0164\b\27\1\2\u0163\u0153\3\2\2"+
		"\2\u0163\u0155\3\2\2\2\u0163\u0157\3\2\2\2\u0163\u0159\3\2\2\2\u0163\u015b"+
		"\3\2\2\2\u0163\u015d\3\2\2\2\u0163\u015f\3\2\2\2\u0163\u0161\3\2\2\2\u0164"+
		"-\3\2\2\2\318GXltx|\u0084\u0099\u009f\u00ae\u00c7\u00d7\u00db\u00f7\u00ff"+
		"\u010c\u0117\u0135\u0141\u014b\u0151\u0163";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}