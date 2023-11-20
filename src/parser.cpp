/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "parser.y"

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

#line 118 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TIDENTIFIER = 3,                /* TIDENTIFIER  */
  YYSYMBOL_TSTRING = 4,                    /* TSTRING  */
  YYSYMBOL_TINTEGER = 5,                   /* TINTEGER  */
  YYSYMBOL_TDOUBLE = 6,                    /* TDOUBLE  */
  YYSYMBOL_TBOOL_LIT = 7,                  /* TBOOL_LIT  */
  YYSYMBOL_INDENT = 8,                     /* INDENT  */
  YYSYMBOL_DEDENT = 9,                     /* DEDENT  */
  YYSYMBOL_TNEWLINE = 10,                  /* TNEWLINE  */
  YYSYMBOL_TCEQ = 11,                      /* TCEQ  */
  YYSYMBOL_TCNE = 12,                      /* TCNE  */
  YYSYMBOL_TCLT = 13,                      /* TCLT  */
  YYSYMBOL_TCLE = 14,                      /* TCLE  */
  YYSYMBOL_TCGT = 15,                      /* TCGT  */
  YYSYMBOL_TCGE = 16,                      /* TCGE  */
  YYSYMBOL_TEQUAL = 17,                    /* TEQUAL  */
  YYSYMBOL_TLPAREN = 18,                   /* TLPAREN  */
  YYSYMBOL_TRPAREN = 19,                   /* TRPAREN  */
  YYSYMBOL_TCOMMA = 20,                    /* TCOMMA  */
  YYSYMBOL_TDOT = 21,                      /* TDOT  */
  YYSYMBOL_TLBRACE = 22,                   /* TLBRACE  */
  YYSYMBOL_TRBRACE = 23,                   /* TRBRACE  */
  YYSYMBOL_TPLUS = 24,                     /* TPLUS  */
  YYSYMBOL_TMINUS = 25,                    /* TMINUS  */
  YYSYMBOL_TMUL = 26,                      /* TMUL  */
  YYSYMBOL_TDIV = 27,                      /* TDIV  */
  YYSYMBOL_TINC = 28,                      /* TINC  */
  YYSYMBOL_TDEC = 29,                      /* TDEC  */
  YYSYMBOL_TNOT = 30,                      /* TNOT  */
  YYSYMBOL_TAND = 31,                      /* TAND  */
  YYSYMBOL_TOR = 32,                       /* TOR  */
  YYSYMBOL_TFUNC = 33,                     /* TFUNC  */
  YYSYMBOL_TFUNC_RETURN_TYPE = 34,         /* TFUNC_RETURN_TYPE  */
  YYSYMBOL_TCOLON = 35,                    /* TCOLON  */
  YYSYMBOL_TMOD = 36,                      /* TMOD  */
  YYSYMBOL_TIF = 37,                       /* TIF  */
  YYSYMBOL_TFOR = 38,                      /* TFOR  */
  YYSYMBOL_TWHILE = 39,                    /* TWHILE  */
  YYSYMBOL_TELIF = 40,                     /* TELIF  */
  YYSYMBOL_TELSE = 41,                     /* TELSE  */
  YYSYMBOL_TRETURN = 42,                   /* TRETURN  */
  YYSYMBOL_TSEMICOLON = 43,                /* TSEMICOLON  */
  YYSYMBOL_TVAR = 44,                      /* TVAR  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_stmts = 47,                     /* stmts  */
  YYSYMBOL_stmt = 48,                      /* stmt  */
  YYSYMBOL_end_of_stmt = 49,               /* end_of_stmt  */
  YYSYMBOL_ident = 50,                     /* ident  */
  YYSYMBOL_block = 51,                     /* block  */
  YYSYMBOL_conditional = 52,               /* conditional  */
  YYSYMBOL_while = 53,                     /* while  */
  YYSYMBOL_var_assign = 54,                /* var_assign  */
  YYSYMBOL_var_decl = 55,                  /* var_decl  */
  YYSYMBOL_for = 56,                       /* for  */
  YYSYMBOL_func_decl = 57,                 /* func_decl  */
  YYSYMBOL_func_decl_args = 58,            /* func_decl_args  */
  YYSYMBOL_return = 59,                    /* return  */
  YYSYMBOL_expr = 60,                      /* expr  */
  YYSYMBOL_term = 61,                      /* term  */
  YYSYMBOL_factor = 62,                    /* factor  */
  YYSYMBOL_literals = 63,                  /* literals  */
  YYSYMBOL_boolean_expr = 64,              /* boolean_expr  */
  YYSYMBOL_comparison = 65,                /* comparison  */
  YYSYMBOL_call_args = 66                  /* call_args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   106,   106,   107,   110,   111,   114,   115,   116,   117,
     118,   119,   120,   121,   124,   127,   130,   131,   134,   135,
     138,   141,   142,   143,   144,   145,   146,   147,   150,   151,
     152,   156,   157,   160,   163,   164,   165,   168,   171,   172,
     173,   176,   177,   178,   179,   182,   183,   184,   185,   186,
     187,   190,   191,   192,   193,   196,   197,   198,   199,   202,
     203,   204,   205,   206,   207,   208,   211,   212,   213
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TIDENTIFIER",
  "TSTRING", "TINTEGER", "TDOUBLE", "TBOOL_LIT", "INDENT", "DEDENT",
  "TNEWLINE", "TCEQ", "TCNE", "TCLT", "TCLE", "TCGT", "TCGE", "TEQUAL",
  "TLPAREN", "TRPAREN", "TCOMMA", "TDOT", "TLBRACE", "TRBRACE", "TPLUS",
  "TMINUS", "TMUL", "TDIV", "TINC", "TDEC", "TNOT", "TAND", "TOR", "TFUNC",
  "TFUNC_RETURN_TYPE", "TCOLON", "TMOD", "TIF", "TFOR", "TWHILE", "TELIF",
  "TELSE", "TRETURN", "TSEMICOLON", "TVAR", "$accept", "program", "stmts",
  "stmt", "end_of_stmt", "ident", "block", "conditional", "while",
  "var_assign", "var_decl", "for", "func_decl", "func_decl_args", "return",
  "expr", "term", "factor", "literals", "boolean_expr", "comparison",
  "call_args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      63,   -64,    34,   124,    -2,   124,   124,    34,    38,    63,
     -64,   133,   -64,   -64,    33,    33,   -64,   -64,    33,    26,
     -64,   -64,   -64,   -64,   124,   124,   124,    27,   168,    -3,
     -11,   -64,     6,   149,     3,    12,    14,   -64,    30,   -64,
     -64,   124,   124,    40,    41,    42,    46,   -64,   -64,    54,
     -64,   -64,   -64,   -64,    34,    53,   -64,   -64,   124,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   124,   124,   124,   124,
     124,   124,   124,   124,    64,   124,   124,    70,   124,   -64,
     -64,     8,   124,   124,   124,   124,   124,    15,    10,   -64,
      16,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,    73,
      43,    44,    73,   -64,    33,   124,   -64,   -64,   -64,   -64,
     -64,    34,    50,    34,   -64,    23,    47,    34,    34,   -64,
     -64,   -64,   -64,    34,    59,   -64,    31,    60,   169,    62,
      69,    71,    34,   -64,    88,    89,    98,    99,   -64,    73,
      73,    73,    73,   -64,   -64,   -64,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    15,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     0,    10,    12,     0,     0,    13,    11,     0,     0,
      53,    51,    52,    54,     0,     0,     0,    50,    55,    38,
      41,    45,     0,     0,     0,     0,     0,    37,     0,     1,
       5,     0,    66,     0,     0,     0,     0,    22,    23,    29,
      14,     7,     6,     8,    34,     0,    47,    48,    66,    65,
      64,    60,    61,    62,    63,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      67,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    57,    58,    56,    39,    40,    42,    43,    44,     0,
       0,     0,     0,    30,     0,     0,    24,    25,    26,    27,
      28,     0,     0,     0,    49,     0,    19,     0,     0,    20,
       9,    68,    35,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,    36,     0,
       0,     0,     0,    18,    31,    32,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,    -5,    -6,    -1,     0,   -63,   -64,   -64,     4,
     110,   -64,   -64,   -64,   -64,   -48,   -46,   -20,   -64,     7,
     -64,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    51,    27,   116,    12,    13,    14,
      15,    16,    17,    88,    18,    28,    29,    30,    31,    80,
      68,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,     1,    19,    40,    33,    56,    57,    38,    34,    11,
      32,    49,    36,    37,    52,    71,    72,    53,    91,    92,
      93,    69,    70,    94,    95,    73,     1,   104,   105,   112,
     113,    55,   125,    49,     1,   114,   105,     1,    39,   119,
     133,    74,     7,    50,    54,    58,    75,    78,    79,    77,
     111,    96,    97,    98,    87,    76,     2,    82,    83,    84,
       3,     4,     5,    85,     2,     6,     1,     7,     3,     4,
       5,    86,    89,     6,    99,     7,   143,   144,   145,   146,
     102,   115,   100,   101,   123,   103,   117,   118,   127,   106,
     107,   108,   109,   110,   132,   134,     2,   135,   139,   140,
       3,     4,     5,   120,   136,     6,   137,     7,   141,   142,
     126,   122,   121,   124,    35,    11,    90,   128,   128,     0,
      40,   129,   130,   131,     0,     0,    11,     1,    20,    21,
      22,    23,   138,     0,     0,     0,     1,     0,     0,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,    25,
      41,    42,     1,     0,    26,     0,     0,    43,    44,    45,
      46,    47,    48,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    59,
      60,    61,    62,    63,    64,    65,    41,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    66,
      67
};

static const yytype_int16 yycheck[] =
{
       0,     3,     2,     9,     4,    25,    26,     7,     4,     9,
       3,    11,     5,     6,    15,    26,    27,    18,    66,    67,
      68,    24,    25,    69,    70,    36,     3,    19,    20,    19,
      20,    24,     9,    33,     3,    19,    20,     3,     0,   102,
       9,    35,    44,    10,    18,    18,    43,    17,    41,    35,
      35,    71,    72,    73,    54,    43,    33,    17,    17,    17,
      37,    38,    39,    17,    33,    42,     3,    44,    37,    38,
      39,    17,    19,    42,    10,    44,   139,   140,   141,   142,
      10,     8,    75,    76,    34,    78,    43,    43,    41,    82,
      83,    84,    85,    86,    35,    35,    33,    35,    10,    10,
      37,    38,    39,   104,    35,    42,    35,    44,    10,    10,
     115,   111,   105,   113,     4,   115,    58,   117,   118,    -1,
     126,   117,   118,   123,    -1,    -1,   126,     3,     4,     5,
       6,     7,   132,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      17,    18,     3,    -1,    30,    -1,    -1,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    11,
      12,    13,    14,    15,    16,    17,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    31,
      32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    33,    37,    38,    39,    42,    44,    46,    47,
      48,    50,    52,    53,    54,    55,    56,    57,    59,    50,
       4,     5,     6,     7,    18,    25,    30,    50,    60,    61,
      62,    63,    64,    50,    54,    55,    64,    64,    50,     0,
      48,    17,    18,    24,    25,    26,    27,    28,    29,    50,
      10,    49,    49,    49,    18,    64,    62,    62,    18,    11,
      12,    13,    14,    15,    16,    17,    31,    32,    65,    24,
      25,    26,    27,    36,    35,    43,    43,    35,    17,    64,
      64,    66,    17,    17,    17,    17,    17,    50,    58,    19,
      66,    60,    60,    60,    61,    61,    62,    62,    62,    10,
      64,    64,    10,    64,    19,    20,    64,    64,    64,    64,
      64,    35,    19,    20,    19,     8,    51,    43,    43,    51,
      49,    64,    50,    34,    50,     9,    47,    41,    50,    54,
      54,    50,    35,     9,    35,    35,    35,    35,    50,    10,
      10,    10,    10,    51,    51,    51,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    50,    51,    51,    52,    52,
      53,    54,    54,    54,    54,    54,    54,    54,    55,    55,
      55,    56,    56,    57,    58,    58,    58,    59,    60,    60,
      60,    61,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     2,     2,     5,
       1,     1,     1,     1,     1,     1,     3,     2,     9,     5,
       5,     3,     2,     2,     4,     4,     4,     4,     4,     2,
       4,     9,     9,    10,     0,     3,     5,     2,     1,     3,
       3,     1,     3,     3,     3,     1,     3,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: %empty  */
#line 106 "parser.y"
                 { programBlock = new statpy::Block(); }
#line 1390 "parser.cpp"
    break;

  case 3: /* program: stmts  */
#line 107 "parser.y"
                { programBlock = (yyvsp[0].block); }
#line 1396 "parser.cpp"
    break;

  case 4: /* stmts: stmt  */
#line 110 "parser.y"
             { (yyval.block) = new statpy::Block(); (yyval.block)->statements.push_back((yyvsp[0].stmt)); }
#line 1402 "parser.cpp"
    break;

  case 5: /* stmts: stmts stmt  */
#line 111 "parser.y"
                   { (yyvsp[-1].block)->statements.push_back((yyvsp[0].stmt));}
#line 1408 "parser.cpp"
    break;

  case 9: /* stmt: ident TLPAREN call_args TRPAREN end_of_stmt  */
#line 117 "parser.y"
                                                   { (yyval.stmt) = new statpy::MethodCall((yyvsp[-4].ident), (yyvsp[-2].exprvec), (yyloc)); }
#line 1414 "parser.cpp"
    break;

  case 15: /* ident: TIDENTIFIER  */
#line 127 "parser.y"
                    { (yyval.ident) = new statpy::Identifier(*(yyvsp[0].string), (yylsp[0])); delete (yyvsp[0].string); }
#line 1420 "parser.cpp"
    break;

  case 16: /* block: INDENT stmts DEDENT  */
#line 130 "parser.y"
                            { (yyval.block) = (yyvsp[-1].block); }
#line 1426 "parser.cpp"
    break;

  case 17: /* block: INDENT DEDENT  */
#line 131 "parser.y"
                      { (yyval.block) = new statpy::Block(); }
#line 1432 "parser.cpp"
    break;

  case 18: /* conditional: TIF boolean_expr TCOLON TNEWLINE block TELSE TCOLON TNEWLINE block  */
#line 134 "parser.y"
                                                                                 { (yyval.stmt) = new statpy::Conditional((yyvsp[-7].expr), (yyvsp[-4].block), (yyvsp[0].block)); }
#line 1438 "parser.cpp"
    break;

  case 19: /* conditional: TIF boolean_expr TCOLON TNEWLINE block  */
#line 135 "parser.y"
                                                     { (yyval.stmt) = new statpy::Conditional((yyvsp[-3].expr), (yyvsp[0].block)); }
#line 1444 "parser.cpp"
    break;

  case 20: /* while: TWHILE boolean_expr TCOLON TNEWLINE block  */
#line 138 "parser.y"
                                                  { (yyval.stmt) = new statpy::WhileLoop((yyvsp[-3].expr), (yyvsp[0].block)); }
#line 1450 "parser.cpp"
    break;

  case 21: /* var_assign: ident TEQUAL boolean_expr  */
#line 141 "parser.y"
                                       { (yyval.stmt) = new statpy::Assignment((yyvsp[-2].ident), (yyvsp[0].expr), (yyloc)); }
#line 1456 "parser.cpp"
    break;

  case 22: /* var_assign: ident TINC  */
#line 142 "parser.y"
                   { (yyval.stmt) = new statpy::Assignment((yyvsp[-1].ident), new statpy::BinaryOp((yyvsp[-1].expr), TPLUS, new statpy::Integer(1), (yyloc)), (yyloc)); }
#line 1462 "parser.cpp"
    break;

  case 23: /* var_assign: ident TDEC  */
#line 143 "parser.y"
                   { (yyval.stmt) = new statpy::Assignment((yyvsp[-1].ident), new statpy::BinaryOp((yyvsp[-1].expr), TMINUS, new statpy::Integer(1), (yyloc)), (yyloc)); }
#line 1468 "parser.cpp"
    break;

  case 24: /* var_assign: ident TPLUS TEQUAL boolean_expr  */
#line 144 "parser.y"
                                        { (yyval.stmt) = new statpy::Assignment((yyvsp[-3].ident), new statpy::BinaryOp((yyvsp[-3].expr), TPLUS, (yyvsp[0].expr), (yyloc)), (yyloc)); }
#line 1474 "parser.cpp"
    break;

  case 25: /* var_assign: ident TMINUS TEQUAL boolean_expr  */
#line 145 "parser.y"
                                         { (yyval.stmt) = new statpy::Assignment((yyvsp[-3].ident), new statpy::BinaryOp((yyvsp[-3].expr), TMINUS, (yyvsp[0].expr), (yyloc)), (yyloc)); }
#line 1480 "parser.cpp"
    break;

  case 26: /* var_assign: ident TMUL TEQUAL boolean_expr  */
#line 146 "parser.y"
                                       { (yyval.stmt) = new statpy::Assignment((yyvsp[-3].ident), new statpy::BinaryOp((yyvsp[-3].expr), TMUL, (yyvsp[0].expr), (yyloc)), (yyloc)); }
#line 1486 "parser.cpp"
    break;

  case 27: /* var_assign: ident TDIV TEQUAL boolean_expr  */
#line 147 "parser.y"
                                       { (yyval.stmt) = new statpy::Assignment((yyvsp[-3].ident), new statpy::BinaryOp((yyvsp[-3].expr), TDIV, (yyvsp[0].expr), (yyloc)), (yyloc)); }
#line 1492 "parser.cpp"
    break;

  case 28: /* var_decl: ident ident TEQUAL boolean_expr  */
#line 150 "parser.y"
                                           { (yyval.stmt) = new statpy::VariableDeclaration((yyvsp[-3].ident), (yyvsp[-2].ident), (yyvsp[0].expr), (yyloc)); }
#line 1498 "parser.cpp"
    break;

  case 29: /* var_decl: ident ident  */
#line 151 "parser.y"
                       { (yyval.stmt) = new statpy::VariableDeclaration((yyvsp[-1].ident), (yyvsp[0].ident), (yyloc));}
#line 1504 "parser.cpp"
    break;

  case 30: /* var_decl: TVAR ident TEQUAL boolean_expr  */
#line 152 "parser.y"
                                          { (yyval.stmt) = new statpy::VariableDeclaration((yyvsp[-2].ident), (yyvsp[0].expr), (yyloc)); }
#line 1510 "parser.cpp"
    break;

  case 31: /* for: TFOR var_assign TSEMICOLON boolean_expr TSEMICOLON var_assign TCOLON TNEWLINE block  */
#line 156 "parser.y"
                                                                                          { (yyval.stmt) = new statpy::ForLoop((yyvsp[-7].stmt), (yyvsp[-5].expr), (yyvsp[-3].stmt), (yyvsp[0].block)); }
#line 1516 "parser.cpp"
    break;

  case 32: /* for: TFOR var_decl TSEMICOLON boolean_expr TSEMICOLON var_assign TCOLON TNEWLINE block  */
#line 157 "parser.y"
                                                                                         { (yyval.stmt) = new statpy::ForLoop((yyvsp[-7].stmt), (yyvsp[-5].expr), (yyvsp[-3].stmt), (yyvsp[0].block)); }
#line 1522 "parser.cpp"
    break;

  case 33: /* func_decl: TFUNC ident TLPAREN func_decl_args TRPAREN TFUNC_RETURN_TYPE ident TCOLON TNEWLINE block  */
#line 160 "parser.y"
                                                                                                     { (yyval.stmt) = new statpy::FunctionDeclaration((yyvsp[-3].ident), (yyvsp[-8].ident), (yyvsp[-6].varvec), (yyvsp[0].block), (yyloc)); }
#line 1528 "parser.cpp"
    break;

  case 34: /* func_decl_args: %empty  */
#line 163 "parser.y"
                        { (yyval.varvec) = new statpy::VariableList(); }
#line 1534 "parser.cpp"
    break;

  case 35: /* func_decl_args: ident TCOLON ident  */
#line 164 "parser.y"
                                 { (yyval.varvec) = new statpy::VariableList(); (yyval.varvec)->push_back(new statpy::VariableDeclaration((yyvsp[0].ident), (yyvsp[-2].ident), (yyloc)));}
#line 1540 "parser.cpp"
    break;

  case 36: /* func_decl_args: func_decl_args TCOMMA ident TCOLON ident  */
#line 165 "parser.y"
                                                       { (yyvsp[-4].varvec)->push_back(new statpy::VariableDeclaration((yyvsp[0].ident), (yyvsp[-2].ident), (yyloc))); }
#line 1546 "parser.cpp"
    break;

  case 37: /* return: TRETURN boolean_expr  */
#line 168 "parser.y"
                              { (yyval.stmt) = new statpy::Return((yyloc), (yyvsp[0].expr)); }
#line 1552 "parser.cpp"
    break;

  case 39: /* expr: term TPLUS term  */
#line 172 "parser.y"
                           { (yyval.expr) = new statpy::BinaryOp((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr), (yyloc)); }
#line 1558 "parser.cpp"
    break;

  case 40: /* expr: term TMINUS term  */
#line 173 "parser.y"
                           { (yyval.expr) = new statpy::BinaryOp((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr), (yyloc)); }
#line 1564 "parser.cpp"
    break;

  case 42: /* term: factor TMUL factor  */
#line 177 "parser.y"
                           { (yyval.expr) = new statpy::BinaryOp((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr), (yyloc)); }
#line 1570 "parser.cpp"
    break;

  case 43: /* term: factor TDIV factor  */
#line 178 "parser.y"
                           { (yyval.expr) = new statpy::BinaryOp((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr), (yyloc)); }
#line 1576 "parser.cpp"
    break;

  case 44: /* term: factor TMOD factor  */
#line 179 "parser.y"
                           { (yyval.expr) = new statpy::BinaryOp((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr), (yyloc)); }
#line 1582 "parser.cpp"
    break;

  case 46: /* factor: TLPAREN boolean_expr TRPAREN  */
#line 183 "parser.y"
                                     { (yyval.expr) = (yyvsp[-1].expr); }
#line 1588 "parser.cpp"
    break;

  case 47: /* factor: TMINUS factor  */
#line 184 "parser.y"
                      { (yyval.expr) = new statpy::UnaryOp((yyvsp[-1].token), (yyvsp[0].expr));}
#line 1594 "parser.cpp"
    break;

  case 48: /* factor: TNOT factor  */
#line 185 "parser.y"
                    { (yyval.expr) = new statpy::UnaryOp((yyvsp[-1].token), (yyvsp[0].expr));}
#line 1600 "parser.cpp"
    break;

  case 49: /* factor: ident TLPAREN call_args TRPAREN  */
#line 186 "parser.y"
                                        { (yyval.expr) = new statpy::MethodCall((yyvsp[-3].ident), (yyvsp[-1].exprvec), (yyloc)); }
#line 1606 "parser.cpp"
    break;

  case 50: /* factor: ident  */
#line 187 "parser.y"
              { (yyval.ident) = (yyvsp[0].ident); }
#line 1612 "parser.cpp"
    break;

  case 51: /* literals: TINTEGER  */
#line 190 "parser.y"
                    { (yyval.expr) = new statpy::Integer((yyvsp[0].integer)); }
#line 1618 "parser.cpp"
    break;

  case 52: /* literals: TDOUBLE  */
#line 191 "parser.y"
                   { (yyval.expr) = new statpy::Double((yyvsp[0].number));}
#line 1624 "parser.cpp"
    break;

  case 53: /* literals: TSTRING  */
#line 192 "parser.y"
                   { (yyval.expr) = new statpy::String(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1630 "parser.cpp"
    break;

  case 54: /* literals: TBOOL_LIT  */
#line 193 "parser.y"
                     { (yyval.expr) = new statpy::Boolean((yyvsp[0].boolean)); }
#line 1636 "parser.cpp"
    break;

  case 56: /* boolean_expr: expr comparison expr  */
#line 197 "parser.y"
                                   { (yyval.expr) = new statpy::CompOperator((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr)); }
#line 1642 "parser.cpp"
    break;

  case 57: /* boolean_expr: expr TAND expr  */
#line 198 "parser.y"
                             { (yyval.expr) = new statpy::BinaryOp((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr), (yyloc)); }
#line 1648 "parser.cpp"
    break;

  case 58: /* boolean_expr: expr TOR expr  */
#line 199 "parser.y"
                             { (yyval.expr) = new statpy::BinaryOp((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr), (yyloc)); }
#line 1654 "parser.cpp"
    break;

  case 66: /* call_args: %empty  */
#line 211 "parser.y"
                   { (yyval.exprvec) = new statpy::ExpressionList(); }
#line 1660 "parser.cpp"
    break;

  case 67: /* call_args: boolean_expr  */
#line 212 "parser.y"
                         { (yyval.exprvec) = new statpy::ExpressionList(); (yyval.exprvec)->push_back((yyvsp[0].expr));}
#line 1666 "parser.cpp"
    break;

  case 68: /* call_args: call_args TCOMMA boolean_expr  */
#line 213 "parser.y"
                                          { (yyvsp[-2].exprvec)->push_back((yyvsp[0].expr)); }
#line 1672 "parser.cpp"
    break;


#line 1676 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 215 "parser.y"
