# APS-Linguagem


## EBNF

```ebnf
PROGRAM = { STATEMENT } ;
STATEMENT = (VARIABLE_DECLARATION | ASSIGNMENT_STATEMENT | IF_STATEMENT | WHILE_LOOP | FOR_LOOP | FUNCTION_DECLARE | RETURN_STATEMENT) ;
VARIABLE_DECLARATION = "var", IDENTIFIER, ":", TYPE, ["=", EXPRESSION] ;
ASSIGNMENT_STATEMENT = IDENTIFIER, [ BINARY_OPERATOR ], "=", EXPRESSION ;
IF_STATEMENT = "if", EXPRESSION, ":", INDENTED_PROGRAM, { "elif", EXPRESSION, ":", INDENTED_PROGRAM }, ["else", ":", INDENTED_PROGRAM] ;
WHILE_LOOP = "while", EXPRESSION, ":", INDENTED_PROGRAM ;
FOR_LOOP = "for", ASSIGNMENT_STATEMENT, ";", EXPRESSION, ";" ASSIGNMENT_STATEMENT, ":", INDENTED_PROGRAM;
FUNCTION_DECLARE = "fn", IDENTIFIER, "(", [PARAMETER_LIST], ")", "->", TYPE, ":", INDENTED_PROGRAM ;
return_statement = "return", EXPRESSION ;

PARAMETER_LIST = IDENTIFIER, ":", TYPE, { ",", IDENTIFIER, ":", TYPE} ;
TYPE = "int" | "float" | "bool" | "string" ;

EXPRESSION = (LITERAL | IDENTIFIER | FUNCTION_CALL | EXPRESSION, BINARY_OPERATOR, EXPRESSION | UNARY_OPERATOR, EXPRESSION ;

LITERAL = (INT | FLOAT | BOOL | STRING);

BINARY_OPERATOR = ("+" | "-" | "*" | "/" | "==" | "!=" | "<" | ">" | "<=" | ">=") ;
UNARY_OPERATOR = ("-" | "!" | "++" | "--") ;

FUNCTION_CALL = IDENTIFIER, "(", [ARGUMENT_LIST], ")" ;
ARGUMENT_LIST = EXPRESSION, { ",", EXPRESSION } ;

INDENTED_PROGRAM = "\n", INDENT, { STATEMENT, "\n" }, DEDENT ;

LETTER = ( a | ... | z | A | ... | Z ) ;
DIGIT = ( 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 ) ;

IDENTIFIER = LETTER, { LETTER | DIGIT | "_" } ;
INTEGER = DIGIT, { DIGIT };
FLOAT = DIGIT, { DIGIT }, ".", { DIGIT };
BOOLEAN = ("true" | "false") ;
STRING = `"`, { (DIGIT | LETTER) }, `"`;

INDENT = "INDENT" ;  (* Token representing an increase in indentation level *)
DEDENT = "DEDENT" ;  (* Token representing a decrease in indentation level *)
```
