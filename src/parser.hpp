/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

      # define YYLTYPE_IS_DECLARED 1 /* alert the parser that we have our own definition */

#line 53 "parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TIDENTIFIER = 258,             /* TIDENTIFIER  */
    TSTRING = 259,                 /* TSTRING  */
    TINTEGER = 260,                /* TINTEGER  */
    TDOUBLE = 261,                 /* TDOUBLE  */
    TBOOL_LIT = 262,               /* TBOOL_LIT  */
    INDENT = 263,                  /* INDENT  */
    DEDENT = 264,                  /* DEDENT  */
    TNEWLINE = 265,                /* TNEWLINE  */
    TCEQ = 266,                    /* TCEQ  */
    TCNE = 267,                    /* TCNE  */
    TCLT = 268,                    /* TCLT  */
    TCLE = 269,                    /* TCLE  */
    TCGT = 270,                    /* TCGT  */
    TCGE = 271,                    /* TCGE  */
    TEQUAL = 272,                  /* TEQUAL  */
    TLPAREN = 273,                 /* TLPAREN  */
    TRPAREN = 274,                 /* TRPAREN  */
    TCOMMA = 275,                  /* TCOMMA  */
    TDOT = 276,                    /* TDOT  */
    TLBRACE = 277,                 /* TLBRACE  */
    TRBRACE = 278,                 /* TRBRACE  */
    TPLUS = 279,                   /* TPLUS  */
    TMINUS = 280,                  /* TMINUS  */
    TMUL = 281,                    /* TMUL  */
    TDIV = 282,                    /* TDIV  */
    TINC = 283,                    /* TINC  */
    TDEC = 284,                    /* TDEC  */
    TNOT = 285,                    /* TNOT  */
    TAND = 286,                    /* TAND  */
    TOR = 287,                     /* TOR  */
    TFUNC = 288,                   /* TFUNC  */
    TFUNC_RETURN_TYPE = 289,       /* TFUNC_RETURN_TYPE  */
    TCOLON = 290,                  /* TCOLON  */
    TMOD = 291,                    /* TMOD  */
    TIF = 292,                     /* TIF  */
    TFOR = 293,                    /* TFOR  */
    TWHILE = 294,                  /* TWHILE  */
    TELIF = 295,                   /* TELIF  */
    TELSE = 296,                   /* TELSE  */
    TRETURN = 297,                 /* TRETURN  */
    TSEMICOLON = 298,              /* TSEMICOLON  */
    TVAR = 299                     /* TVAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "parser.y"

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

#line 130 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
