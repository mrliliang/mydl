grammar MyDatalog;

@header {

}

@lexer::preinclude {
#include "basetype.h"
}

@parser::preinclude {
#include "basetype.h"
}

@parser::postinclude {
using namespace std;
}

datalog_edb_declare returns[vector<Schema> r] :
    {vector<Schema> edb_list;} 
    TOKEN_EDB TOKEN_COLON 
    schema1 = datalog_relation_schema {edb_list.emplace_back($schema1.r);} 
    (schema2 = datalog_relation_schema {edb_list.emplace_back($schema2.r);})* 
    {$r = edb_list;};

datalog_idb_declare returns[vector<Schema> r] : 
    {vector<Schema> idb_list;}
    TOKEN_IDB TOKEN_COLON
    schema1 = datalog_relation_schema {idb_list.emplace_back($schema1.r);}
    (schema2 = datalog_relation_schema {idb_list.emplace_back($schema2.r);})*
    {$r = idb_list;}
;

datalog_relation_schema returns[Schema r] : 
    {Schema schema;}
    relation_name = TOKEN_ID {schema.name = $relation_name.text;}
    TOKEN_LEFT_PAREN
    // t1 = attribute {schema.attributes.emplace_back(AtomArg($t1.r.name, $t1.r.type, $t1.r.isKey));}
    t1 = attribute {schema.attributes.emplace_back($t1.r);}
    (TOKEN_COMMA
    // t2 = attribute {schema.attributes.emplace_back(AtomArg($t2.r.name, $t2.r.type, $t2.r.isKey));})*
    t2 = attribute {schema.attributes.emplace_back($t2.r);})*
     TOKEN_RIGHT_PAREN
    {$r = schema;}
;

datalog_rule_declare returns[vector<RuleMap> r] : 
    TOKEN_RULE TOKEN_COLON dp = datalog_program {$r = $dp.r;} EOF
;

datalog_program returns[vector<RuleMap> r] :
    {vector<RuleMap> rule_list;}
    r1 = datalog_rule {rule_list.emplace_back($r1.r);}
    (r2 = datalog_rule {rule_list.emplace_back($r2.r);})*
    {$r = rule_list;}
;

datalog_rule returns[RuleMap r] :
    {RuleMap rule_map;}
    (TOKEN_NON_DEDUP {rule_map.nonDedup = true;})?
    (TOKEN_NON_SET_DIFF {rule_map.nonSetDiff = true;})?
    (TOKEN_DEDUP_ONLY {rule_map.dedupOnly = true;})?
    h = head {rule_map.head = $h.r;}
    TOKEN_BODY_HEAD_SEP
    (b = body {rule_map.body = $b.r;})?
    TOKEN_DOT
    {$r = rule_map;}
;

head returns[AtomMap r] :
    a = atom {$r = $a.r;}
;

body returns [BodyMap r] :
    {BodyMap body_map;}
    ((b1 = atom {body_map.atoms.emplace_back($b1.r);} |
      b2 = compare_expr {body_map.compares.emplace_back($b2.r);} |
      b3 = assign {body_map.assigns.emplace_back($b3.r);} |
      b4 = negation {body_map.negations.emplace_back($b4.r);})
      TOKEN_COMMA)*
    ( b5 = atom {body_map.atoms.emplace_back($b5.r);} |
      b6 = compare_expr {body_map.compares.emplace_back($b6.r);} |
      b7 = assign {body_map.assigns.emplace_back($b7.r);} |
      b8 = negation {body_map.negations.emplace_back($b8.r);})
    {$r = body_map;}
;

negation returns [AtomMap r] : 
    TOKEN_NOT a = atom {$r = $a.r;}
;

//可能有问题需要修正
atom returns [AtomMap r] : 
    {AtomMap atom_map;}
    a1 = TOKEN_ID {atom_map.name = $a1.text;}
    TOKEN_LEFT_PAREN
    (a2 = TOKEN_ID {atom_map.argList.emplace_back(AtomArg($a2.text, "variable", false));} |
     a3 = aggregation_expr {atom_map.argList.emplace_back(AtomArg($a3.r, "aggregation", false));} |
     a4 = TOKEN_ANY {atom_map.argList.emplace_back(AtomArg($a4.text, "any", false));} |
     a5 = constant {atom_map.argList.emplace_back(AtomArg($a5.text, "constant", false));} |
     a6 = math_expr {atom_map.argList.emplace_back(AtomArg($a6.r, "math_expr", false));})
    (TOKEN_COMMA 
     (a7 = TOKEN_ID {atom_map.argList.emplace_back(AtomArg($a7.text, "variable", false));} |
      a8 = aggregation_expr {atom_map.argList.emplace_back(AtomArg($a8.r, "aggregation", false));} |
      a9 = TOKEN_ANY {atom_map.argList.emplace_back(AtomArg($a9.text, "any", false));} |
      a10 = constant {atom_map.argList.emplace_back(AtomArg($a10.text, "constant", false));} |
      a11 = math_expr {atom_map.argList.emplace_back(AtomArg($a11.r, "math_expr", false));}))*
    TOKEN_RIGHT_PAREN
    {$r = atom_map;}
;

assign returns [AssignMap r] : 
    {AssignMap assign_map;}
    a1 = TOKEN_ID {assign_map.lhs = $a1.text;}
    TOKEN_EQUALS
    a2 = math_expr {assign_map.rhs = $a2.r;}
    {$r = assign_map;}
;

math_expr returns [MathMap r] : 
    {MathMap math_map;}
    m1 = TOKEN_ID {math_map.lhs = $m1.text;}
    m2 = math_op {math_map.op = $m2.text;}
    m3 = TOKEN_ID {math_map.rhs = $m3.text;}
    {$r = math_map;}
;

compare_expr returns [CompareMap r] : 
    {CompareMap compare_map;}
    (c1 = TOKEN_ID {compare_map.lhsText = $c1.text; compare_map.lhsType = "var";} | 
     c2 = TOKEN_INTEGER {compare_map.lhsText = $c2.text; compare_map.lhsType = "num";})
     op = compare_op {compare_map.op = $op.r;}
    (c3 = TOKEN_ID {compare_map.rhsText = $c3.text; compare_map.rhsType = "var";} | 
     c4 = TOKEN_INTEGER {compare_map.rhsText = $c4.text; compare_map.rhsType = "num";})
    {$r = compare_map;}
;

//有问题需要修正
aggregation_expr returns [AggMap r] : 
    {AggMap agg_map;}
    a1 = aggregation_op {agg_map.aggOp = $a1.r;}
    TOKEN_LEFT_PAREN
    (a2 = TOKEN_ID {agg_map.aggArg.type = "attribute", agg_map.aggArg.attr = $a2.text;} | 
     a3 = math_expr {agg_map.aggArg.type = "math_expr", agg_map.aggArg.mathExpr = $a3.r;})
    TOKEN_RIGHT_PAREN
    {$r = agg_map;}
;

attribute returns [Attribute r] : 
    a1 = non_key_attribute {$r = $a1.r;} | 
    a2 = key_attribute {$r = $a2.r;} 
;

key_attribute returns [Attribute r] : 
    {Attribute attr{"", "", true};}
    TOKEN_LEFT_BRACKET
    a1 = TOKEN_ID {attr.name = $a1.text;}
    TOKEN_RIGHT_BRACKET
    d1 = data_type {attr.type = $d1.r;}
    {$r = attr;}
;

non_key_attribute returns [Attribute r] : 
    {Attribute attr{"", "", false};}
    a1 = TOKEN_ID {attr.name = $a1.text;}
    d1 = data_type {attr.type = $d1.r;}
    {$r = attr;}
;

compare_op returns [string r] : 
    op1 = TOKEN_NOT_EQUALS {$r = $op1.text;} | 
    op2 = TOKEN_EQUALS {$r = $op2.text;} | 
    op3 = TOKEN_GREATER_THAN {$r = $op3.text;} | 
    op4 = TOKEN_GREATER_EQUAL_THAN {$r = $op4.text;} | 
    op5 = TOKEN_LESS_THAN {$r = $op5.text;} | 
    op6 = TOKEN_LESS_EQUAL_THAN {$r = $op6.text;}
;

aggregation_op returns [string r] : 
    op1 = TOKEN_MIN {$r = $op1.text;} | 
    op2 = TOKEN_MAX {$r = $op2.text;} | 
    op3 = TOKEN_SUM {$r = $op3.text;} | 
    op4 = TOKEN_COUNT {$r = $op4.text;} | 
    op5 = TOKEN_COUNT_DISTINCT {$r = $op5.text;}
;

math_op returns [string r] : 
    op1 = TOKEN_PLUS {$r = $op1.text;} | 
    op2 = TOKEN_MINUS {$r = $op2.text;} | 
    op3 = TOKEN_MULT {$r = $op3.text;} | 
    op4 = TOKEN_DIV {$r = $op4.text;}
;

constant returns [string r] : 
    c1 = TOKEN_INTEGER {$r = $c1.text;} | 
    c2 = TOKEN_STRING {$r = $c2.text;}
;

data_type returns [string r] : 
    dt1 = TOKEN_INT {$r = $dt1.text;} | 
    dt2 = TOKEN_LONG {$r = $dt2.text;} | 
    dt3 = TOKEN_FLOAT {$r = $dt3.text;} | 
    dt4 = TOKEN_DOUBLE {$r = $dt4.text;} | 
    dt5 = TOKEN_VARCHAR {$r = $dt5.text;} | 
    dt6 = TOKEN_CHAR {$r = $dt6.text;} | 
    dt7 = TOKEN_DATE {$r = $dt7.text;} | 
    dt8 = TOKEN_DATETIME {$r = $dt8.text;}
;



/** Declaration **/
TOKEN_EDB: 'EDB_DECL';
TOKEN_IDB: 'IDB_DECL';
TOKEN_RULE: 'RULE_DECL';

/** Constants **/
TOKEN_INTEGER: [-+]? [0-9]+;
TOKEN_STRING: '\'' ([A-Za-z] | [0-9])+ '\'';

/** Data Types **/
TOKEN_INT: ('i' | 'I') ('n' | 'N') ('t' | 'T');
TOKEN_LONG: ('l' | 'L') ('o' | 'O') ('n' | 'N') ('g' | 'G');
TOKEN_FLOAT: ('f' | 'F') ('l' | 'L') ('o' | 'O') ('a' | 'A') (
		't'
		| 'T'
	);
TOKEN_DOUBLE: ('d' | 'D') ('o' | 'O') ('u' | 'U') ('b' | 'B') (
		'l'
		| 'L'
	) ('e' | 'E');
TOKEN_VARCHAR: ('v' | 'V') ('a' | 'A') ('r' | 'R') ('c' | 'C') (
		'h'
		| 'H'
	) ('a' | 'A') ('r' | 'R');
TOKEN_CHAR: ('c' | 'C') ('h' | 'H') ('a' | 'A') ('r' | 'R');
TOKEN_DATE: ('d' | 'D') ('a' | 'A') ('t' | 'T') ('e' | 'E');
TOKEN_DATETIME: ('d' | 'D') ('a' | 'A') ('t' | 'T') ('e' | 'E') (
		't'
		| 'T'
	) ('i' | 'I') ('m' | 'M') ('e' | 'E');

/** Aggregation Operators **/
TOKEN_MIN: 'MIN';
TOKEN_MAX: 'MAX';
TOKEN_SUM: 'SUM';
TOKEN_COUNT: 'COUNT';
TOKEN_COUNT_DISTINCT: 'COUNT_DISTINCT';

/**  Datalog Rules **/
TOKEN_ID: [A-Za-z]([A-Za-z] | [0-9] | '_')*;
TOKEN_BODY_HEAD_SEP: ':-';
TOKEN_ANY: '_';
TOKEN_COMMA: ',';
TOKEN_SEMICOLON: ';';
TOKEN_COLON: ':';
TOKEN_DOT: '.';

/** Arithmetic Operators **/
TOKEN_PLUS: '+';
TOKEN_MINUS: '-';
TOKEN_MULT: '*';
TOKEN_DIV: '/';

TOKEN_NOT: '!';

/** Rule Computation Flags **/
TOKEN_NON_DEDUP: '[!dedup]';
TOKEN_NON_SET_DIFF: '[!set-diff]';
TOKEN_DEDUP_ONLY: '[dedup-only]';

/** Comparison Operators **/
TOKEN_NOT_EQUALS: '!=';
TOKEN_EQUALS: '=';
TOKEN_GREATER_EQUAL_THAN: '>=';
TOKEN_GREATER_THAN: '>';
TOKEN_LESS_EQUAL_THAN: '<=';
TOKEN_LESS_THAN: '<';

TOKEN_LEFT_PAREN: '(';
TOKEN_RIGHT_PAREN: ')';
TOKEN_LEFT_BRACKET: '[';
TOKEN_RIGHT_BRACKET: ']';
TOKEN_WS: [ \t\r\n]+ -> skip;