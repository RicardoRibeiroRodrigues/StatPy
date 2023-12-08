# APS-Linguagem


## EBNF

```ebnf
PROGRAM = { STATEMENT } ;
STATEMENT = (VARIABLE_DECLARE, "\n" | ASSIGNMENT_STATEMENT, "\n" | IF_STATEMENT | WHILE_LOOP | FOR_LOOP | FUNCTION_DECLARE | RETURN_STATEMENT, "\n" | FUNCTION_CALL, "\n") ;

VARIABLE_DECLARE = (TYPE, IDENTIFIER, ["=", BOOL_EXPR] | "VAR", IDENTIFIER, "=", BOOL_EXPR) ;

ASSIGNMENT_STATEMENT = (IDENTIFIER, [ ARITHMETIC_OPERATOR ], "=", BOOL_EXPR | INC_DEC | BINOP_ASSIGN) ;
BINOP_ASSIGN = IDENTIFIER, ARITHMETIC_OPERATOR, "=", BOOL_EXPR;
INC_DEC = IDENTIFIER, ("++" | "--");

IF_STATEMENT = "if", BOOL_EXPR, ":", INDENTED_PROGRAM, { "elif", BOOL_EXPR, ":", INDENTED_PROGRAM }, ["else", ":", INDENTED_PROGRAM] ;

WHILE_LOOP = "while", BOOL_EXPR, ":", INDENTED_PROGRAM ;
FOR_LOOP = "for", (ASSIGNMENT_STATEMENT | VARIABLE_DECLARE), ";", BOOL_EXPR, ";", ASSIGNMENT_STATEMENT, ":", INDENTED_PROGRAM;

FUNCTION_DECLARE = "fn", IDENTIFIER, "(", [PARAMETER_LIST], ")", "->", TYPE, ":", INDENTED_PROGRAM ; 
PARAMETER_LIST = IDENTIFIER, ":", TYPE, { ",", IDENTIFIER, ":", TYPE} ;

RETURN_STATEMENT = "return", BOOL_EXPR ;

TYPE = "int" | "float" | "boolean" | "string";
COMPARISON = ( "==", ">", "<", ">=", "<=", "!=" );
BOOL_EXPR = EXPR, { (COMPARISON | "and" | "or"), EXPR };
EXPR = TERM, { ("+" | "-"), TERM };
TERM = FACTOR, { ( "*" | "/" | "%" ), FACTOR };
FACTOR = ( LITERAL | "(", BOOL_EXPR, ")" | "-" FACTOR | "!" FACTOR | IDENTIFIER "(" ARGUMENT_LIST ")" | IDENTIFIER);

LITERAL = INTEGER | FLOAT | BOOLEAN | STRING ;

ARITHMETIC_OPERATOR = "+" | "-" | "*" | "/" ;
BINARY_OPERATOR = ARITHMETIC_OPERATOR | "==" | "!=" | "<" | ">" | "<=" | ">=" ;
UNARY_OPERATOR = "-" | "!" ;

FUNCTION_CALL = IDENTIFIER, "(", [ARGUMENT_LIST], ")" ;
ARGUMENT_LIST = [ BOOL_EXPR ], { ",", BOOL_EXPR } ;

INDENTED_PROGRAM = "\n", INDENT, { STATEMENT }, DEDENT ;

LETTER = "a" | ... | "z" | "A" | ... | "Z" ;
DIGIT = "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" | "0" ;

IDENTIFIER = LETTER, { LETTER | DIGIT | "_" } ;
INTEGER = DIGIT, { DIGIT };
FLOAT = DIGIT, { DIGIT }, ".", { DIGIT };
BOOLEAN = "true" | "false" ;
STRING = `"`, { DIGIT | LETTER }, `"` ;

INDENT = "INDENT" ;  (* Token representing an increase in indentation level *)
DEDENT = "DEDENT" ;  (* Token representing a decrease in indentation level *) ;
```
