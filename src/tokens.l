%{
    #include <string>
    #include <stack>
    #include "nodes/AstNode.h"
    #include "parser.hpp"
    #define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
    #define SAVE_INT yylval.integer = std::stoll(std::string(yytext, yyleng))
    #define SAVE_FLOAT yylval.number = std::stod(std::string(yytext, yyleng))
    #define SAVE_BOOL yylval.boolean = std::string(yytext, yyleng) == "true" ? 1 : 0
    #define TOKEN(t) (yylval.token = t)
    extern "C" int yywrap() { }

    int yycolumn = 1;
    #define YYERROR_VERBOSE 1
    int yyerror(char const * s )
    {
        printf("ERROR %s in '%s' at line %d col %d\n", s, yytext, yylineno, yycolumn);
        printf("  parsed %s %d.%d-%d.%d\n", yylloc.file_name.c_str(), yylloc.first_line, yylloc.first_column, yylloc.last_line, yylloc.last_column);
        return 1;
    }


    /* globals to track current indentation */
    int current_line_indent = 0;   /* indentation of the current line */
    int indent_level = 0;          /* indentation level passed to the parser */
    std::stack<int> curr_indents;
    int first_time = 1 ;
    
    std::stack<std::string> fileNames;

    #define YY_USER_ACTION do { \
    if( yylloc.last_line < yylineno ) yycolumn = 1 ; \
        yylloc.first_line = yylloc.last_line = yylineno; \
        yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + (int)yyleng - 1; \
        yycolumn += (int)yyleng; \
        yylloc.file_name = fileNames.top(); \
    } while(0) ;

%}

%option yylineno

%x indent 
%s normal

%%
    if( first_time ) {
        first_time = 0;
        curr_indents.push(0);
        BEGIN(indent);
    }

<indent>" "      { current_line_indent++; }
<indent>"\t"     { current_line_indent = (current_line_indent + 8) & ~7; }
<indent>"\n"     { current_line_indent = 0; yycolumn = 1;/*ignoring blank line */ }
<indent>"\r"     { current_line_indent = 0; yycolumn = 1;/*ignoring blank line */ }
<indent>.        {
                   unput(*yytext);
                   yycolumn--;
                   if (current_line_indent > curr_indents.top()) {
                       curr_indents.push(current_line_indent);
                       return TOKEN(INDENT);
                   } else if (current_line_indent < curr_indents.top()) {
                       curr_indents.pop();
                       return TOKEN(DEDENT);
                   } else {
                       BEGIN(normal);
                   }
                 }
<normal>"\n"            {current_line_indent = 0; BEGIN(indent); yycolumn = 1; return TOKEN(TNEWLINE); }
<<EOF>>                 {
                            if (curr_indents.size() > 1) {
                                curr_indents.pop();
                                return TOKEN(DEDENT);
                            }
                            yyterminate();
                        }
"++"                    return TOKEN(TINC);
"--"                    return TOKEN(TDEC);
"="                     return TOKEN(TEQUAL);
"=="                    return TOKEN(TCEQ);
"!="                    return TOKEN(TCNE);
"<"                     return TOKEN(TCLT);
"<="                    return TOKEN(TCLE);
">"                     return TOKEN(TCGT);
">="                    return TOKEN(TCGE);
"("                     return TOKEN(TLPAREN);
")"                     return TOKEN(TRPAREN);
"{"                     return TOKEN(TLBRACE);
"}"                     return TOKEN(TRBRACE);
"."                     return TOKEN(TDOT);
","                     return TOKEN(TCOMMA);
"+"                     return TOKEN(TPLUS);
"-"                     return TOKEN(TMINUS);
"*"                     return TOKEN(TMUL);
"/"                     return TOKEN(TDIV);
"!"                     return TOKEN(TNOT);
";"                     return TOKEN(TSEMICOLON);
"%"                     return TOKEN(TMOD);
"and"                   return TOKEN(TAND);
"or"                    return TOKEN(TOR);
"while"                 return TOKEN(TWHILE);
"for"                   return TOKEN(TFOR);
"if"                    return TOKEN(TIF);
"elif"                  return TOKEN(TELIF);
"else"                  return TOKEN(TELSE);
"fn"                    return TOKEN(TFUNC);
"->"                    return TOKEN(TFUNC_RETURN_TYPE);
":"                     return TOKEN(TCOLON);
"var"                   return TOKEN(TVAR);   
"return"                return TOKEN(TRETURN);
"int"                   SAVE_TOKEN; return TIDENTIFIER;
"float"                 SAVE_TOKEN; return TIDENTIFIER;
"string"                SAVE_TOKEN; return TIDENTIFIER;
"bool"                  SAVE_TOKEN; return TIDENTIFIER;
"true"                  SAVE_BOOL; return TBOOL_LIT;
"false"                 SAVE_BOOL; return TBOOL_LIT;
[a-zA-Z][a-zA-Z0-9_]*   SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]*          SAVE_FLOAT; return TDOUBLE;
[0-9]+                  SAVE_INT; return TINTEGER;
"\""[^\"]*"\""          SAVE_TOKEN; return TSTRING;
" "                     ;
.                       printf("line %d, len %d Unknown token <%s>\n", yylineno, yyleng, yytext); yyterminate();

%%
