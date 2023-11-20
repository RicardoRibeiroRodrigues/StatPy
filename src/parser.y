%code requires {
      # define YYLTYPE_IS_DECLARED 1 /* alert the parser that we have our own definition */
}

%{
      #include "nodes/AstNode.h"
      #include "nodes/FunctionDeclaration.h"
      #include "nodes/Return.h"
      #include "nodes/FunctionDeclaration.h"
      #include "nodes/Conditional.h"
      #include "nodes/UnaryOperator.h"
      #include "nodes/BinaryOperator.h"
      #include "nodes/CompareOperator.h"
      #include "nodes/Assignment.h"
      #include "nodes/MethodCall.h"
      #include "nodes/Declaration.h"
      #include "nodes/WhileLoop.h"
      #include "nodes/ForLoop.h"
      #include "nodes/ClassDeclaration.h"
      #include "nodes/Array.h"
      #include <stack>
      statpy::Block *programBlock; /* the top level root node of our final AST */

      extern int yylex();
      int yyerror(char const * s );
      extern std::stack<std::string> fileNames;

 # define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
          (Current).file_name = fileNames.top();            \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
          (Current).file_name = fileNames.top();            \
        }                                                               \
    while (0)

    #define YYDEBUG 1
    #define YYERROR_VERBOSE
%}

/* Represents the many different ways we can access our data */
%union {
    statpy::Node *node;
    statpy::Block *block;
    statpy::Expression *expr;
    statpy::Statement *stmt;
    statpy::Identifier *ident;
    statpy::VariableDeclaration *var_decl;
    std::vector<statpy::VariableDeclaration*> *varvec;
    std::vector<statpy::Expression*> *exprvec;
    std::string *string;
    long long integer;
    double number;
    int boolean;
    int token;
}
/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <string> TIDENTIFIER TSTRING
%token <integer> TINTEGER
%token <number> TDOUBLE
%token <boolean> TBOOL_LIT
%token <token> INDENT DEDENT TNEWLINE
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <token> TLPAREN TRPAREN TCOMMA TDOT TLBRACE TRBRACE
%token <token> TPLUS TMINUS TMUL TDIV TINC TDEC
%token <token> TNOT TAND TOR TFUNC TFUNC_RETURN_TYPE TCOLON TMOD
%token <token> TIF TFOR TWHILE TELIF TELSE TRETURN TSEMICOLON TVAR

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident
%type <expr> expr boolean_expr literals factor term
%type <varvec> func_decl_args
%type <exprvec> call_args
%type <block> program stmts block 
%type <stmt> stmt var_decl func_decl conditional while var_assign return for
%type <token> comparison end_of_stmt

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV TMOD
%left TAND TNOT
%left TEQUAL TCLT TCLE TCGT TCGE TCNE TCEQ

%start program

%%

program : %empty { programBlock = new statpy::Block(); }
        | stmts { programBlock = $1; }
        ;

stmts : stmt { $$ = new statpy::Block(); $$->statements.push_back($<stmt>1); }
      | stmts stmt { $1->statements.push_back($<stmt>2);}
      ;

stmt : var_decl end_of_stmt
     | var_assign end_of_stmt
     | return end_of_stmt
     | ident TLPAREN call_args TRPAREN end_of_stmt { $$ = new statpy::MethodCall($<ident>1, $<exprvec>3, @$); }
     | conditional
     | func_decl
     | while
     | for
     ;

end_of_stmt : TNEWLINE
            ;

ident : TIDENTIFIER { $$ = new statpy::Identifier(*$1, @1); delete $1; }
      ;

block : INDENT stmts DEDENT { $$ = $2; }
      | INDENT DEDENT { $$ = new statpy::Block(); }
      ;

conditional : TIF boolean_expr TCOLON TNEWLINE block TELSE TCOLON TNEWLINE block { $$ = new statpy::Conditional($2, $5, $9); }
            | TIF boolean_expr TCOLON TNEWLINE block { $$ = new statpy::Conditional($2, $5); }
            ;

while : TWHILE boolean_expr TCOLON TNEWLINE block { $$ = new statpy::WhileLoop($2, $5); }
      ;

var_assign : ident TEQUAL boolean_expr { $$ = new statpy::Assignment($<ident>1, $3, @$); }
      | ident TINC { $$ = new statpy::Assignment($1, new statpy::BinaryOp($<expr>1, TPLUS, new statpy::Integer(1), @$), @$); }
      | ident TDEC { $$ = new statpy::Assignment($1, new statpy::BinaryOp($<expr>1, TMINUS, new statpy::Integer(1), @$), @$); }
      | ident TPLUS TEQUAL boolean_expr { $$ = new statpy::Assignment($1, new statpy::BinaryOp($<expr>1, TPLUS, $4, @$), @$); }
      | ident TMINUS TEQUAL boolean_expr { $$ = new statpy::Assignment($1, new statpy::BinaryOp($<expr>1, TMINUS, $4, @$), @$); }
      | ident TMUL TEQUAL boolean_expr { $$ = new statpy::Assignment($1, new statpy::BinaryOp($<expr>1, TMUL, $4, @$), @$); }
      | ident TDIV TEQUAL boolean_expr { $$ = new statpy::Assignment($1, new statpy::BinaryOp($<expr>1, TDIV, $4, @$), @$); }
      ;

var_decl : ident ident TEQUAL boolean_expr { $$ = new statpy::VariableDeclaration($1, $2, $<expr>4, @$); }
         | ident ident { $$ = new statpy::VariableDeclaration($1, $2, @$);}
         | TVAR ident TEQUAL boolean_expr { $$ = new statpy::VariableDeclaration($2, $4, @$); }
         ;


for : TFOR var_assign TSEMICOLON boolean_expr TSEMICOLON var_assign TCOLON TNEWLINE block { $$ = new statpy::ForLoop($2, $4, $6, $9); }
    | TFOR var_decl TSEMICOLON boolean_expr TSEMICOLON var_assign TCOLON  TNEWLINE block { $$ = new statpy::ForLoop($2, $4, $6, $9); }
    ;

func_decl : TFUNC ident TLPAREN func_decl_args TRPAREN TFUNC_RETURN_TYPE ident TCOLON TNEWLINE block { $$ = new statpy::FunctionDeclaration($7, $2, $4, $10, @$); }
          ;

func_decl_args : %empty { $$ = new statpy::VariableList(); }
            | ident TCOLON ident { $$ = new statpy::VariableList(); $$->push_back(new statpy::VariableDeclaration($3, $1, @$));}
            | func_decl_args TCOMMA ident TCOLON ident { $1->push_back(new statpy::VariableDeclaration($5, $3, @$)); }
            ;

return : TRETURN boolean_expr { $$ = new statpy::Return(@$, $2); }
       ;

expr : term
      | term TPLUS term    { $<expr>$ = new statpy::BinaryOp($<expr>1, $<token>2, $<expr>3, @$); }
      | term TMINUS term   { $<expr>$ = new statpy::BinaryOp($<expr>1, $<token>2, $<expr>3, @$); }
      ;

term :  factor
      | factor TMUL factor { $<expr>$ = new statpy::BinaryOp($<expr>1, $<token>2, $<expr>3, @$); }
      | factor TDIV factor { $<expr>$ = new statpy::BinaryOp($<expr>1, $<token>2, $<expr>3, @$); }
      | factor TMOD factor { $<expr>$ = new statpy::BinaryOp($<expr>1, $<token>2, $<expr>3, @$); }
      ;

factor : literals
      | TLPAREN boolean_expr TRPAREN { $<expr>$ = $2; }
      | TMINUS factor { $<expr>$ = new statpy::UnaryOp($1, $2);}
      | TNOT factor { $<expr>$ = new statpy::UnaryOp($1, $2);}
      | ident TLPAREN call_args TRPAREN { $<expr>$ = new statpy::MethodCall($<ident>1, $<exprvec>3, @$); }
      | ident { $<ident>$ = $<ident>1; }
      ;

literals : TINTEGER { $<expr>$ = new statpy::Integer($1); }
         | TDOUBLE { $<expr>$ = new statpy::Double($1);}
         | TSTRING { $<expr>$ = new statpy::String(*$1); delete $1; }
         | TBOOL_LIT { $<expr>$ = new statpy::Boolean($1); }
         ;

boolean_expr : expr
            | expr comparison expr { $<expr>$ = new statpy::CompOperator($1, $2, $3); }
            | expr TAND expr { $<expr>$ = new statpy::BinaryOp($<expr>1, $<token>2, $<expr>3, @$); }
            | expr TOR expr  { $<expr>$ = new statpy::BinaryOp($<expr>1, $<token>2, $<expr>3, @$); }
            ;

comparison : TEQUAL
           | TCLT
           | TCLE
           | TCGT
           | TCGE
           | TCNE
           | TCEQ
           ;

call_args : %empty { $$ = new statpy::ExpressionList(); }
          | boolean_expr { $$ = new statpy::ExpressionList(); $$->push_back($1);}
          | call_args TCOMMA boolean_expr { $1->push_back($3); }
          ;
%%