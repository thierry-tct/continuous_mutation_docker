/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         smt2parse
#define yylex           smt2lex
#define yyerror         smt2error
#define yydebug         smt2debug
#define yynerrs         smt2nerrs

#define yylval          smt2lval
#define yychar          smt2char

/* Copy the first part of user declarations.  */
#line 1 "smt2.y" /* yacc.c:339  */

  /********************************************************************
   * AUTHORS:  Trevor Hansen
   *
   * BEGIN DATE: May, 2010
   *
   * This file is modified version of the STP's smtlib.y file. Please
   * see CVCL license below
   ********************************************************************/

  /********************************************************************
   * AUTHORS: Vijay Ganesh, Trevor Hansen
   *
   * BEGIN DATE: July, 2006
   *
   * This file is modified version of the CVCL's smtlib.y file. Please
   * see CVCL license below
   ********************************************************************/

  
  /********************************************************************
   *
   * \file smtlib.y
   * 
   * Author: Sergey Berezin, Clark Barrett
   * 
   * Created: Apr 30 2005
   *
   * <hr>
   * Copyright (C) 2004 by the Board of Trustees of Leland Stanford
   * Junior University and by New York University. 
   *
   * License to use, copy, modify, sell and/or distribute this software
   * and its documentation for any purpose is hereby granted without
   * royalty, subject to the terms and conditions defined in the \ref
   * LICENSE file provided with this distribution.  In particular:
   *
   * - The above copyright notice and this permission notice must appear
   * in all copies of the software and related documentation.
   *
   * - THE SOFTWARE IS PROVIDED "AS-IS", WITHOUT ANY WARRANTIES,
   * EXPRESSED OR IMPLIED.  USE IT AT YOUR OWN RISK.
   * 
   * <hr>
   ********************************************************************/
  // -*- c++ -*-

#include "../cpp_interface/cpp_interface.h"

  using namespace std; 
  using namespace BEEV;

  // Suppress the bogus warning suppression in bison (it generates
  // compile error)
#undef __GNUC_MINOR__
  
  extern char* smt2text;
  extern int smt2lineno;
  extern int smt2lex(void);

  int yyerror(const char *s) {
    cout << "syntax error: line " << smt2lineno << "\n" << s << endl;
    cout << "  token: " << smt2text << endl;
    FatalError("");
    return 1;
  }

   
#define YYLTYPE_IS_TRIVIAL 1
#define YYMAXDEPTH 104857600
#define YYERROR_VERBOSE 1
#define YY_EXIT_FAILURE -1

  

#line 150 "parsesmt2.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parsesmt2.hpp".  */
#ifndef YY_SMT2_PARSESMT2_HPP_INCLUDED
# define YY_SMT2_PARSESMT2_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int smt2debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    NUMERAL_TOK = 258,
    BVCONST_DECIMAL_TOK = 259,
    BVCONST_BINARY_TOK = 260,
    BVCONST_HEXIDECIMAL_TOK = 261,
    DECIMAL_TOK = 262,
    FORMID_TOK = 263,
    TERMID_TOK = 264,
    STRING_TOK = 265,
    FUNCTIONID_TOK = 266,
    SOURCE_TOK = 267,
    CATEGORY_TOK = 268,
    DIFFICULTY_TOK = 269,
    VERSION_TOK = 270,
    STATUS_TOK = 271,
    PRINT_TOK = 272,
    UNDERSCORE_TOK = 273,
    LPAREN_TOK = 274,
    RPAREN_TOK = 275,
    BVLEFTSHIFT_1_TOK = 276,
    BVRIGHTSHIFT_1_TOK = 277,
    BVARITHRIGHTSHIFT_TOK = 278,
    BVPLUS_TOK = 279,
    BVSUB_TOK = 280,
    BVNOT_TOK = 281,
    BVMULT_TOK = 282,
    BVDIV_TOK = 283,
    SBVDIV_TOK = 284,
    BVMOD_TOK = 285,
    SBVREM_TOK = 286,
    SBVMOD_TOK = 287,
    BVNEG_TOK = 288,
    BVAND_TOK = 289,
    BVOR_TOK = 290,
    BVXOR_TOK = 291,
    BVNAND_TOK = 292,
    BVNOR_TOK = 293,
    BVXNOR_TOK = 294,
    BVCONCAT_TOK = 295,
    BVLT_TOK = 296,
    BVGT_TOK = 297,
    BVLE_TOK = 298,
    BVGE_TOK = 299,
    BVSLT_TOK = 300,
    BVSGT_TOK = 301,
    BVSLE_TOK = 302,
    BVSGE_TOK = 303,
    BVSX_TOK = 304,
    BVEXTRACT_TOK = 305,
    BVZX_TOK = 306,
    BVROTATE_RIGHT_TOK = 307,
    BVROTATE_LEFT_TOK = 308,
    BVREPEAT_TOK = 309,
    BVCOMP_TOK = 310,
    BITVEC_TOK = 311,
    ARRAY_TOK = 312,
    BOOL_TOK = 313,
    TRUE_TOK = 314,
    FALSE_TOK = 315,
    NOT_TOK = 316,
    AND_TOK = 317,
    OR_TOK = 318,
    XOR_TOK = 319,
    ITE_TOK = 320,
    EQ_TOK = 321,
    IMPLIES_TOK = 322,
    DISTINCT_TOK = 323,
    LET_TOK = 324,
    EXIT_TOK = 325,
    CHECK_SAT_TOK = 326,
    LOGIC_TOK = 327,
    NOTES_TOK = 328,
    OPTION_TOK = 329,
    DECLARE_FUNCTION_TOK = 330,
    DEFINE_FUNCTION_TOK = 331,
    FORMULA_TOK = 332,
    PUSH_TOK = 333,
    POP_TOK = 334,
    SELECT_TOK = 335,
    STORE_TOK = 336
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 76 "smt2.y" /* yacc.c:355  */
  
  unsigned uintval;                  /* for numerals in types. */
  //ASTNode,ASTVec
  BEEV::ASTNode *node;
  BEEV::ASTVec *vec;
  std::string *str;

#line 281 "parsesmt2.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE smt2lval;

int smt2parse (void);

#endif /* !YY_SMT2_PARSESMT2_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 296 "parsesmt2.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   803

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   336

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   196,   196,   204,   205,   210,   215,   220,   230,   234,
     237,   239,   241,   249,   255,   259,   263,   273,   284,   290,
     299,   319,   336,   354,   356,   358,   360,   362,   364,   369,
     378,   388,   396,   420,   429,   438,   447,   459,   468,   479,
     485,   491,   496,   503,   529,   553,   560,   567,   574,   581,
     588,   595,   602,   609,   613,   618,   624,   631,   636,   641,
     647,   653,   659,   669,   670,   673,   687,   705,   715,   726,
     731,   735,   748,   762,   778,   791,   800,   808,   816,   824,
     832,   840,   848,   856,   872,   883,   891,   900,   908,   917,
     926,   935,   943,   951,   959,   967,   976,   985,   994,  1020,
    1044,  1060,  1066,  1073,  1080
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "NUMERAL_TOK",
  "BVCONST_DECIMAL_TOK", "BVCONST_BINARY_TOK", "BVCONST_HEXIDECIMAL_TOK",
  "DECIMAL_TOK", "FORMID_TOK", "TERMID_TOK", "STRING_TOK",
  "FUNCTIONID_TOK", "SOURCE_TOK", "CATEGORY_TOK", "DIFFICULTY_TOK",
  "VERSION_TOK", "STATUS_TOK", "PRINT_TOK", "UNDERSCORE_TOK", "LPAREN_TOK",
  "RPAREN_TOK", "BVLEFTSHIFT_1_TOK", "BVRIGHTSHIFT_1_TOK",
  "BVARITHRIGHTSHIFT_TOK", "BVPLUS_TOK", "BVSUB_TOK", "BVNOT_TOK",
  "BVMULT_TOK", "BVDIV_TOK", "SBVDIV_TOK", "BVMOD_TOK", "SBVREM_TOK",
  "SBVMOD_TOK", "BVNEG_TOK", "BVAND_TOK", "BVOR_TOK", "BVXOR_TOK",
  "BVNAND_TOK", "BVNOR_TOK", "BVXNOR_TOK", "BVCONCAT_TOK", "BVLT_TOK",
  "BVGT_TOK", "BVLE_TOK", "BVGE_TOK", "BVSLT_TOK", "BVSGT_TOK",
  "BVSLE_TOK", "BVSGE_TOK", "BVSX_TOK", "BVEXTRACT_TOK", "BVZX_TOK",
  "BVROTATE_RIGHT_TOK", "BVROTATE_LEFT_TOK", "BVREPEAT_TOK", "BVCOMP_TOK",
  "BITVEC_TOK", "ARRAY_TOK", "BOOL_TOK", "TRUE_TOK", "FALSE_TOK",
  "NOT_TOK", "AND_TOK", "OR_TOK", "XOR_TOK", "ITE_TOK", "EQ_TOK",
  "IMPLIES_TOK", "DISTINCT_TOK", "LET_TOK", "EXIT_TOK", "CHECK_SAT_TOK",
  "LOGIC_TOK", "NOTES_TOK", "OPTION_TOK", "DECLARE_FUNCTION_TOK",
  "DEFINE_FUNCTION_TOK", "FORMULA_TOK", "PUSH_TOK", "POP_TOK",
  "SELECT_TOK", "STORE_TOK", "$accept", "cmd", "commands", "cmdi",
  "function_param", "function_params", "function_decl", "status",
  "attribute", "var_decl", "an_mixed", "an_formulas", "an_formula", "lets",
  "let", "an_terms", "an_term", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336
};
# endif

#define YYPACT_NINF -70

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-70)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,   209,    21,     8,   -70,     5,     6,    20,   128,   128,
      61,    67,    66,    73,    76,   -70,   -70,   -70,   -70,   -70,
      60,   -70,   -70,   -70,   -70,    77,   -40,     2,    68,    70,
      71,    97,    98,   -70,   140,   -70,   -70,    99,   100,   107,
     -70,   -70,   -70,   -70,   -70,   108,   109,   -70,   -70,   110,
     -70,   118,   -70,   530,   722,   722,   722,   722,   722,   722,
     722,   722,    66,    66,    66,    66,    66,   530,    66,   530,
     119,   126,   -70,   -70,   -70,   -70,   -70,    -5,    80,   -70,
       4,   -70,   -70,   -70,   143,   337,   722,   722,   722,   722,
     722,   722,   722,   722,   722,   722,   722,   722,   722,   722,
     722,   722,   722,   722,   722,   722,   722,    66,   722,   722,
     238,   -70,   -70,   594,   722,   722,   722,   722,   722,   722,
     722,   722,   130,     9,   -70,    62,    66,    66,    66,   722,
      66,    64,   658,   -70,   133,   -70,     0,   -70,   134,    39,
     -70,   151,   530,    82,    66,   135,   722,   722,   722,   722,
     722,   -70,   722,   722,   722,   722,   722,   722,   -70,   722,
     722,   722,   722,   722,   722,   722,   722,   722,   722,   722,
     -70,   -70,   -70,   530,   137,   138,   141,   142,   144,   145,
     146,   155,   -70,   -70,   -70,   -70,   156,    66,   158,   169,
     171,   -70,   -70,   -70,   150,   172,   133,   139,   174,   178,
     179,    66,   -70,   402,   160,   195,   207,   208,   210,   211,
     530,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   722,   -70,   722,   466,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   196,   -70,   -70,   -70,   530,    66,
     -70,   214,   200,   163,   165,   -70,   -70,   206,   224,   217,
     218,   219,   220,   -70,   -70,   -70,   -70,   221,   222,   228,
     230,   173,   248,   249,   722,   233,   722,   722,   722,   722,
     -70,   -70,   -70,   -70,   251,   235,   269,   -70,   722,   -70,
     -70,   -70,   -70,   270,   271,   275,   -70,   276,   -70,   722,
     278,   279,   244,   -70,   298,   282,   284,   -70
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     5,     6,
       0,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,    39,    40,     0,     0,     0,
       7,    22,    27,    28,    29,     0,     0,    11,     9,     0,
      14,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    12,    13,    10,     8,     0,     0,    18,
       0,   103,   102,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    53,     0,    31,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,    35,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    57,    38,    58,     0,     0,     0,     0,
       0,    44,    43,    68,     0,     0,    64,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    95,    96,    97,    86,    85,    87,    88,    90,
      89,    91,    92,    80,    81,    82,    93,    94,    83,    77,
      84,     0,    71,     0,     0,    49,    51,    50,    52,    45,
      47,    46,    48,    59,     0,    60,    42,    55,     0,     0,
      63,     0,     0,     0,     0,    21,    62,     0,     0,     0,
       0,     0,     0,    76,    72,   104,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    61,    30,     0,     0,     0,    75,     0,    74,
      99,    98,   100,     0,     0,     0,    73,     0,    17,     0,
       0,     0,     0,    20,     0,     0,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   302,   227,   -70,   -70,   -70,   300,   -70,
     -69,   -53,   105,   114,   -70,   -70,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    79,    80,    32,    42,    27,    30,
     110,   123,   111,   195,   196,   132,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     114,   115,   116,   117,   118,   119,   120,   121,    16,    45,
       1,   125,    46,   129,   136,   133,   131,    33,   197,    43,
      44,    15,    47,    78,   139,    18,    19,     1,    34,   183,
      20,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   137,   168,   169,   172,   198,   200,   145,
     174,   175,   176,   177,   178,   179,   180,   181,    35,    36,
      33,    29,    33,   203,    33,   189,    38,    31,   193,    39,
      40,    34,   185,    34,   191,    34,   141,    41,    48,    49,
     138,    50,   212,   213,   214,   215,   216,   201,   217,   218,
     219,   220,   221,   222,   234,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    51,    37,    52,    72,
      73,    35,    36,    35,    36,    35,    36,    74,    75,    76,
      77,   204,   205,   206,   207,   208,   209,    78,   134,    71,
      21,    22,    23,    24,    25,    26,   135,   141,    33,   172,
     182,    53,   194,   199,   202,   211,   231,   235,   236,    34,
     248,   237,   238,   257,   239,   240,   241,   122,   124,   124,
     126,   127,   128,   130,   124,   242,   243,   263,   245,   264,
     172,    54,    55,    56,    57,    58,    59,    60,    61,   246,
      71,   247,   249,   252,   268,   251,   253,   254,   258,    35,
      36,    62,    63,    64,    65,    66,    67,    68,    69,    70,
     259,   260,   167,   261,   262,   171,   266,   270,   271,   272,
     287,   273,   289,   290,   291,   292,   274,   275,   184,   284,
     184,   186,   187,   188,   296,   190,   184,   276,   277,   278,
     279,   280,   281,    81,    82,   301,    33,    83,   282,   210,
     283,   285,   286,   288,   293,   294,    84,    85,   170,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   295,
     297,   298,   244,   106,   299,   300,   302,    35,    36,   303,
     304,   305,   306,   107,   307,    17,   255,   140,   171,    28,
     250,     0,     0,     0,     0,   187,     0,     0,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
       0,     0,    81,    82,     0,    33,    83,     0,   142,     0,
       0,     0,     0,   267,   269,   143,    85,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,     0,
       0,     0,   106,     0,     0,     0,    35,    36,    62,    63,
      64,    65,   144,    67,    68,    69,    70,    81,    82,     0,
      33,    83,     0,     0,     0,     0,     0,   108,   109,     0,
      84,    85,   256,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,     0,
       0,    35,    36,     0,     0,     0,     0,   107,     0,     0,
       0,    81,    82,     0,    33,    83,     0,     0,     0,     0,
       0,     0,   108,   109,    84,    85,   265,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,     0,    35,    36,     0,     0,     0,
       0,   107,     0,     0,     0,    81,    82,     0,    33,    83,
       0,     0,     0,     0,     0,     0,   108,   109,    84,    85,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,     0,    35,
      36,     0,     0,     0,     0,   107,     0,     0,     0,    81,
      82,     0,     0,    83,     0,   173,     0,     0,     0,     0,
     108,   109,   143,   113,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,    81,    82,     0,     0,    83,     0,     0,
       0,     0,     0,     0,   108,   109,    84,   113,   192,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,    81,    82,     0,
       0,    83,     0,     0,     0,     0,     0,     0,   108,   109,
      84,   113,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,   109
};

static const yytype_int16 yycheck[] =
{
      54,    55,    56,    57,    58,    59,    60,    61,     0,     7,
      19,    64,    10,    67,    19,    69,    69,     8,    18,    59,
      60,     0,    20,    19,    20,    20,    20,    19,    19,    20,
      10,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    58,   108,   109,   110,    57,    19,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    59,    60,
       8,    10,     8,   142,     8,   129,     3,    10,   132,     3,
      20,    19,    20,    19,    20,    19,     4,    10,    20,    19,
      10,    20,   146,   147,   148,   149,   150,    58,   152,   153,
     154,   155,   156,   157,   173,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    19,    12,    20,    20,
      20,    59,    60,    59,    60,    59,    60,    20,    20,    20,
      20,    49,    50,    51,    52,    53,    54,    19,    19,    34,
      12,    13,    14,    15,    16,    17,    20,     4,     8,   203,
      20,    11,    19,    19,     3,    20,   210,    20,    20,    19,
      10,    20,    20,     3,    20,    20,    20,    62,    63,    64,
      65,    66,    67,    68,    69,    20,    20,   231,    20,   233,
     234,    41,    42,    43,    44,    45,    46,    47,    48,    20,
      85,    20,    20,    19,   248,    56,    18,    18,     3,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       3,     3,   107,     3,     3,   110,    20,     3,    18,    56,
     274,    56,   276,   277,   278,   279,    20,     3,   123,    56,
     125,   126,   127,   128,   288,   130,   131,    20,    20,    20,
      20,    20,    20,     5,     6,   299,     8,     9,    20,   144,
      20,     3,     3,    20,     3,    20,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    20,
      20,    20,   187,    55,    19,    19,    18,    59,    60,    20,
      56,     3,    20,    65,    20,     3,   201,    80,   203,     9,
     196,    -1,    -1,    -1,    -1,   210,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,
      -1,    -1,     5,     6,    -1,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,   248,   249,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,     5,
       6,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      80,    81,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,     5,     6,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,     5,     6,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    83,    84,    85,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    85,    20,    20,
      10,    12,    13,    14,    15,    16,    17,    90,    90,    10,
      91,    10,    88,     8,    19,    59,    60,    94,     3,     3,
      20,    10,    89,    59,    60,     7,    10,    20,    20,    19,
      20,    19,    20,    11,    41,    42,    43,    44,    45,    46,
      47,    48,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    94,    20,    20,    20,    20,    20,    20,    19,    86,
      87,     5,     6,     9,    18,    19,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    55,    65,    80,    81,
      92,    94,    98,    19,    98,    98,    98,    98,    98,    98,
      98,    98,    94,    93,    94,    93,    94,    94,    94,    98,
      94,    93,    97,    98,    19,    20,    19,    58,    10,    20,
      86,     4,    11,    18,    65,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    94,    98,    98,
      20,    94,    98,    11,    98,    98,    98,    98,    98,    98,
      98,    98,    20,    20,    94,    20,    94,    94,    94,    98,
      94,    20,    20,    98,    19,    95,    96,    18,    57,    19,
      19,    58,     3,    92,    49,    50,    51,    52,    53,    54,
      94,    20,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    92,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    94,    20,    20,    20,    10,    20,
      95,    56,    19,    18,    18,    94,    20,     3,     3,     3,
       3,     3,     3,    98,    98,    20,    20,    94,    98,    94,
       3,    18,    56,    56,    20,     3,    20,    20,    20,    20,
      20,    20,    20,    20,    56,     3,     3,    98,    20,    98,
      98,    98,    98,     3,    20,    20,    98,    20,    20,    19,
      19,    98,    18,    20,    56,     3,    20,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    87,    87,
      88,    88,    89,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    92,    92,    92,    92,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    96,    96,    97,    97,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     3,     3,     4,     5,     4,
       5,     4,     4,     4,     4,     4,     4,     8,     1,     2,
      12,     6,     1,     1,     1,     1,     1,     2,     2,     2,
       8,     4,    16,     1,     1,     2,     2,     1,     2,     1,
       1,     1,     5,     4,     4,     5,     5,     5,     5,     5,
       5,     5,     5,     3,     4,     5,     6,     4,     4,     5,
       5,     7,     4,     2,     1,     4,     4,     1,     2,     1,
       3,     3,     4,     7,     6,     6,     4,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     6,     6,
       6,     3,     1,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 197 "smt2.y" /* yacc.c:1646  */
    {
       parserInterface->cleanUp();
       YYACCEPT;
}
#line 1682 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 206 "smt2.y" /* yacc.c:1646  */
    {}
#line 1688 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 211 "smt2.y" /* yacc.c:1646  */
    {
       parserInterface->cleanUp();
       YYACCEPT;
	}
#line 1697 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 216 "smt2.y" /* yacc.c:1646  */
    {
		parserInterface->checkSat(parserInterface->getAssertVector());
	}
#line 1705 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 221 "smt2.y" /* yacc.c:1646  */
    {
	  if (!(0 == strcmp((yyvsp[-1].str)->c_str(),"QF_BV") ||
	        0 == strcmp((yyvsp[-1].str)->c_str(),"QF_ABV") ||
	        0 == strcmp((yyvsp[-1].str)->c_str(),"QF_AUFBV"))) {
	    yyerror("Wrong input logic:");
	  }
	  parserInterface->success();
	  delete (yyvsp[-1].str);
	}
#line 1719 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 231 "smt2.y" /* yacc.c:1646  */
    {
	delete (yyvsp[-1].str);
	}
#line 1727 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 235 "smt2.y" /* yacc.c:1646  */
    {
	}
#line 1734 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 238 "smt2.y" /* yacc.c:1646  */
    {}
#line 1740 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 240 "smt2.y" /* yacc.c:1646  */
    {}
#line 1746 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 242 "smt2.y" /* yacc.c:1646  */
    {
		for (int i=0; i < (yyvsp[-1].uintval);i++)
		{
			parserInterface->push();
		}
		parserInterface->success();
	}
#line 1758 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 250 "smt2.y" /* yacc.c:1646  */
    {
		for (int i=0; i < (yyvsp[-1].uintval);i++)
			parserInterface->pop();
		parserInterface->success();
	}
#line 1768 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 256 "smt2.y" /* yacc.c:1646  */
    {
    parserInterface->success();
    }
#line 1776 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 260 "smt2.y" /* yacc.c:1646  */
    {
    parserInterface->success();
    }
#line 1784 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 264 "smt2.y" /* yacc.c:1646  */
    {
	parserInterface->AddAssert(*(yyvsp[-1].node));
	parserInterface->deleteNode((yyvsp[-1].node));
	parserInterface->success();
	}
#line 1794 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 274 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = new ASTNode(BEEV::parserInterface->LookupOrCreateSymbol((yyvsp[-6].str)->c_str())); 
  parserInterface->addSymbol(*(yyval.node));
  (yyval.node)->SetIndexWidth(0);
  (yyval.node)->SetValueWidth((yyvsp[-2].uintval));
  delete (yyvsp[-6].str);
}
#line 1806 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 285 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.vec) = new ASTVec;
  (yyval.vec)->push_back(*(yyvsp[0].node));
  delete (yyvsp[0].node);
}
#line 1816 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 291 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.vec) = (yyvsp[-1].vec);
  (yyval.vec)->push_back(*(yyvsp[0].node));
  delete (yyvsp[0].node);
}
#line 1826 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 300 "smt2.y" /* yacc.c:1646  */
    {
	if ((yyvsp[-1].node)->GetValueWidth() != (yyvsp[-4].uintval))
		{
			char msg [100];
			sprintf(msg, "Different bit-widths specified: %d %d", (yyvsp[-1].node)->GetValueWidth(), (yyvsp[-4].uintval));
			yyerror(msg);
		}
	
	BEEV::parserInterface->storeFunction(*(yyvsp[-11].str), *(yyvsp[-9].vec), *(yyvsp[-1].node));

	// Next time the variable is used, we want it to be fresh.
    for (int i = 0; i < (yyvsp[-9].vec)->size(); i++)
     BEEV::parserInterface->removeSymbol((*(yyvsp[-9].vec))[i]);
	
	delete (yyvsp[-11].str);
	delete (yyvsp[-9].vec);
	delete (yyvsp[-1].node);
}
#line 1849 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 320 "smt2.y" /* yacc.c:1646  */
    {
	// Check the bitwidth defined/ and actually are the same.
	BEEV::parserInterface->storeFunction(*(yyvsp[-5].str), *(yyvsp[-3].vec), *(yyvsp[0].node));

	// Next time the variable is used, we want it to be fresh.
    for (int i = 0; i < (yyvsp[-3].vec)->size(); i++)
     BEEV::parserInterface->removeSymbol((*(yyvsp[-3].vec))[i]);

	delete (yyvsp[-5].str);
	delete (yyvsp[-3].vec);
	delete (yyvsp[0].node);
}
#line 1866 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 336 "smt2.y" /* yacc.c:1646  */
    { 
 
 std::transform((yyvsp[0].str)->begin(), (yyvsp[0].str)->end(), (yyvsp[0].str)->begin(), ::tolower);
  
  if (0 == strcmp((yyvsp[0].str)->c_str(), "sat"))
  	input_status = TO_BE_SATISFIABLE;
  else if (0 == strcmp((yyvsp[0].str)->c_str(), "unsat"))
    input_status = TO_BE_UNSATISFIABLE;
  else if (0 == strcmp((yyvsp[0].str)->c_str(), "unknown"))
  	input_status = TO_BE_UNKNOWN; 
  else 
  	yyerror((yyvsp[0].str)->c_str());
  delete (yyvsp[0].str);
  (yyval.node) = NULL; 
}
#line 1886 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 355 "smt2.y" /* yacc.c:1646  */
    {}
#line 1892 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 357 "smt2.y" /* yacc.c:1646  */
    {}
#line 1898 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 359 "smt2.y" /* yacc.c:1646  */
    {}
#line 1904 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 361 "smt2.y" /* yacc.c:1646  */
    {}
#line 1910 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 363 "smt2.y" /* yacc.c:1646  */
    {}
#line 1916 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 365 "smt2.y" /* yacc.c:1646  */
    {
	parserInterface->setPrintSuccess(true);
	parserInterface->success();
}
#line 1925 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 370 "smt2.y" /* yacc.c:1646  */
    {
	parserInterface->setPrintSuccess(false);
}
#line 1933 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 379 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode s = BEEV::parserInterface->LookupOrCreateSymbol((yyvsp[-7].str)->c_str()); 
  parserInterface->addSymbol(s);
  //Sort_symbs has the indexwidth/valuewidth. Set those fields in
  //var
  s.SetIndexWidth(0);
  s.SetValueWidth((yyvsp[-1].uintval));
  delete (yyvsp[-7].str);
}
#line 1947 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 389 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode s = BEEV::parserInterface->LookupOrCreateSymbol((yyvsp[-3].str)->c_str());
  s.SetIndexWidth(0);
  s.SetValueWidth(0);
  parserInterface->addSymbol(s);
  delete (yyvsp[-3].str);
}
#line 1959 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 397 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode s = BEEV::parserInterface->LookupOrCreateSymbol((yyvsp[-15].str)->c_str());
  parserInterface->addSymbol(s);
  unsigned int index_len = (yyvsp[-7].uintval);
  unsigned int value_len = (yyvsp[-2].uintval);
  if(index_len > 0) {
    s.SetIndexWidth((yyvsp[-7].uintval));
  }
  else {
    FatalError("Fatal Error: parsing: BITVECTORS must be of positive length: \n");
  }

  if(value_len > 0) {
    s.SetValueWidth((yyvsp[-2].uintval));
  }
  else {
    FatalError("Fatal Error: parsing: BITVECTORS must be of positive length: \n");
  }
  delete (yyvsp[-15].str);
}
#line 1984 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 421 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.vec) = new ASTVec;
  if ((yyvsp[0].node) != NULL) {
    (yyval.vec)->push_back(*(yyvsp[0].node));
    parserInterface->deleteNode((yyvsp[0].node));
  }
}
#line 1996 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 430 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.vec) = new ASTVec;
  if ((yyvsp[0].node) != NULL) {
    (yyval.vec)->push_back(*(yyvsp[0].node));
    parserInterface->deleteNode((yyvsp[0].node));
  }
}
#line 2008 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 439 "smt2.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-1].vec) != NULL && (yyvsp[0].node) != NULL) {
    (yyvsp[-1].vec)->push_back(*(yyvsp[0].node));
    (yyval.vec) = (yyvsp[-1].vec);
    parserInterface->deleteNode((yyvsp[0].node));
  }
}
#line 2020 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 448 "smt2.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-1].vec) != NULL && (yyvsp[0].node) != NULL) {
    (yyvsp[-1].vec)->push_back(*(yyvsp[0].node));
    (yyval.vec) = (yyvsp[-1].vec);
    parserInterface->deleteNode((yyvsp[0].node));
  }
}
#line 2032 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 460 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.vec) = new ASTVec;
  if ((yyvsp[0].node) != NULL) {
    (yyval.vec)->push_back(*(yyvsp[0].node));
    parserInterface->deleteNode((yyvsp[0].node));
  }
}
#line 2044 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 469 "smt2.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-1].vec) != NULL && (yyvsp[0].node) != NULL) {
    (yyvsp[-1].vec)->push_back(*(yyvsp[0].node));
    (yyval.vec) = (yyvsp[-1].vec);
    parserInterface->deleteNode((yyvsp[0].node));
  }
}
#line 2056 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 480 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode(parserInterface->CreateNode(TRUE)); 
  assert(0 == (yyval.node)->GetIndexWidth()); 
  assert(0 == (yyval.node)->GetValueWidth());
}
#line 2066 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 486 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode(parserInterface->CreateNode(FALSE)); 
  assert(0 == (yyval.node)->GetIndexWidth()); 
  assert(0 == (yyval.node)->GetValueWidth());
}
#line 2076 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 492 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode(*(yyvsp[0].node)); 
  parserInterface->deleteNode((yyvsp[0].node));      
}
#line 2085 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 497 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode * n = parserInterface->newNode(EQ,*(yyvsp[-2].node), *(yyvsp[-1].node));
  (yyval.node) = n;
  parserInterface->deleteNode((yyvsp[-2].node));
  parserInterface->deleteNode((yyvsp[-1].node));      
}
#line 2096 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 504 "smt2.y" /* yacc.c:1646  */
    {
  using namespace BEEV;

  ASTVec terms = *(yyvsp[-1].vec);
  ASTVec forms;

  for(ASTVec::const_iterator it=terms.begin(),itend=terms.end();
      it!=itend; it++) {
    for(ASTVec::const_iterator it2=it+1; it2!=itend; it2++) {
      ASTNode n = (parserInterface->nf->CreateNode(NOT, parserInterface->CreateNode(EQ, *it, *it2)));

          
      forms.push_back(n); 
    }
  }

  if(forms.size() == 0) 
    FatalError("empty distinct");
 
  (yyval.node) = (forms.size() == 1) ?
    parserInterface->newNode(forms[0]) :
    parserInterface->newNode(parserInterface->CreateNode(AND, forms));

  delete (yyvsp[-1].vec);
}
#line 2126 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 530 "smt2.y" /* yacc.c:1646  */
    {
  using namespace BEEV;

  ASTVec terms = *(yyvsp[-1].vec);
  ASTVec forms;

  for(ASTVec::const_iterator it=terms.begin(),itend=terms.end();
      it!=itend; it++) {
    for(ASTVec::const_iterator it2=it+1; it2!=itend; it2++) {
      ASTNode n = (parserInterface->nf->CreateNode(NOT, parserInterface->CreateNode(IFF, *it, *it2)));
      forms.push_back(n); 
    }
  }

  if(forms.size() == 0) 
    FatalError("empty distinct");
 
  (yyval.node) = (forms.size() == 1) ?
    parserInterface->newNode(forms[0]) :
    parserInterface->newNode(parserInterface->CreateNode(AND, forms));

  delete (yyvsp[-1].vec);
}
#line 2154 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 554 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode * n = parserInterface->newNode(BVSLT, *(yyvsp[-2].node), *(yyvsp[-1].node));
  (yyval.node) = n;
  parserInterface->deleteNode((yyvsp[-2].node));
  parserInterface->deleteNode((yyvsp[-1].node));      
}
#line 2165 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 561 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode * n = parserInterface->newNode(BVSLE, *(yyvsp[-2].node), *(yyvsp[-1].node));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));      
}
#line 2176 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 568 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode * n = parserInterface->newNode(BVSGT, *(yyvsp[-2].node), *(yyvsp[-1].node));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));      
}
#line 2187 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 575 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode * n = parserInterface->newNode(BVSGE, *(yyvsp[-2].node), *(yyvsp[-1].node));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));      
}
#line 2198 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 582 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode * n = parserInterface->newNode(BVLT, *(yyvsp[-2].node), *(yyvsp[-1].node));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));      
}
#line 2209 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 589 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode * n = parserInterface->newNode(BVLE, *(yyvsp[-2].node), *(yyvsp[-1].node));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));      
}
#line 2220 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 596 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode * n = parserInterface->newNode(BVGT, *(yyvsp[-2].node), *(yyvsp[-1].node));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));      
}
#line 2231 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 603 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode * n = parserInterface->newNode(BVGE, *(yyvsp[-2].node), *(yyvsp[-1].node));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));      
}
#line 2242 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 610 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2250 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 614 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode(parserInterface->nf->CreateNode(NOT, *(yyvsp[-1].node)));
    parserInterface->deleteNode( (yyvsp[-1].node));
}
#line 2259 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 619 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode(IMPLIES, *(yyvsp[-2].node), *(yyvsp[-1].node));
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));      
}
#line 2269 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 625 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode(parserInterface->nf->CreateNode(ITE, *(yyvsp[-3].node), *(yyvsp[-2].node), *(yyvsp[-1].node)));
  parserInterface->deleteNode( (yyvsp[-3].node));
  parserInterface->deleteNode( (yyvsp[-2].node));      
  parserInterface->deleteNode( (yyvsp[-1].node));
}
#line 2280 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 632 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode(parserInterface->CreateNode(AND, *(yyvsp[-1].vec)));
  delete (yyvsp[-1].vec);
}
#line 2289 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 637 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode(parserInterface->CreateNode(OR, *(yyvsp[-1].vec)));
  delete (yyvsp[-1].vec);
}
#line 2298 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 642 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode(XOR, *(yyvsp[-2].node), *(yyvsp[-1].node));
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));
}
#line 2308 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 648 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode(IFF, *(yyvsp[-2].node), *(yyvsp[-1].node));
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));
}
#line 2318 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 654 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
  //Cleanup the LetIDToExprMap
  parserInterface->letMgr.CleanupLetIDMap();                      
}
#line 2328 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 660 "smt2.y" /* yacc.c:1646  */
    {	
  (yyval.node) = parserInterface->newNode(parserInterface->applyFunction(*(yyvsp[-2].str),*(yyvsp[-1].vec)));
  if ((yyval.node)->GetType() != BOOLEAN_TYPE)
  	yyerror("Must be boolean type");
  delete (yyvsp[-2].str);
  delete (yyvsp[-1].vec);
}
#line 2340 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 671 "smt2.y" /* yacc.c:1646  */
    {}
#line 2346 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 674 "smt2.y" /* yacc.c:1646  */
    {
  //populate the hashtable from LET-var -->
  //LET-exprs and then process them:
  //
  //1. ensure that LET variables do not clash
  //1. with declared variables.
  //
  //2. Ensure that LET variables are not
  //2. defined more than once
  parserInterface->letMgr.LetExprMgr(*(yyvsp[-2].str),*(yyvsp[-1].node));
  delete (yyvsp[-2].str);
  parserInterface->deleteNode( (yyvsp[-1].node));
}
#line 2364 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 688 "smt2.y" /* yacc.c:1646  */
    {
  //populate the hashtable from LET-var -->
  //LET-exprs and then process them:
  //
  //1. ensure that LET variables do not clash
  //1. with declared variables.
  //
  //2. Ensure that LET variables are not
  //2. defined more than once
  parserInterface->letMgr.LetExprMgr(*(yyvsp[-2].str),*(yyvsp[-1].node));
  delete (yyvsp[-2].str);
  parserInterface->deleteNode( (yyvsp[-1].node));

}
#line 2383 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 706 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.vec) = new ASTVec;
  if ((yyvsp[0].node) != NULL) {
    (yyval.vec)->push_back(*(yyvsp[0].node));
    parserInterface->deleteNode( (yyvsp[0].node));
  
  }
}
#line 2396 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 716 "smt2.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-1].vec) != NULL && (yyvsp[0].node) != NULL) {
    (yyvsp[-1].vec)->push_back(*(yyvsp[0].node));
    (yyval.vec) = (yyvsp[-1].vec);
    parserInterface->deleteNode( (yyvsp[0].node));
  }
}
#line 2408 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 727 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = parserInterface->newNode((*(yyvsp[0].node)));
  parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2417 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 732 "smt2.y" /* yacc.c:1646  */
    {
  (yyval.node) = (yyvsp[-1].node);
}
#line 2425 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 736 "smt2.y" /* yacc.c:1646  */
    {
  //ARRAY READ
  // valuewidth is same as array, indexwidth is 0.
  ASTNode array = *(yyvsp[-1].node);
  ASTNode index = *(yyvsp[0].node);
  unsigned int width = array.GetValueWidth();
  ASTNode * n = 
    parserInterface->newNode(parserInterface->nf->CreateTerm(READ, width, array, index));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[-1].node));
  parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2442 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 749 "smt2.y" /* yacc.c:1646  */
    {
  //ARRAY WRITE
  unsigned int width = (yyvsp[0].node)->GetValueWidth();
  ASTNode array = *(yyvsp[-2].node);
  ASTNode index = *(yyvsp[-1].node);
  ASTNode writeval = *(yyvsp[0].node);
  ASTNode write_term = parserInterface->nf->CreateArrayTerm(WRITE,(yyvsp[-2].node)->GetIndexWidth(),width,array,index,writeval);
  ASTNode * n = parserInterface->newNode(write_term);
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));
  parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2460 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 763 "smt2.y" /* yacc.c:1646  */
    {
  int width = (yyvsp[-3].uintval) - (yyvsp[-2].uintval) + 1;
  if (width < 0)
    yyerror("Negative width in extract");
      
  if((unsigned)(yyvsp[-3].uintval) >= (yyvsp[0].node)->GetValueWidth())
    yyerror("Parsing: Wrong width in BVEXTRACT\n");                      
      
  ASTNode hi  =  parserInterface->CreateBVConst(32, (yyvsp[-3].uintval));
  ASTNode low =  parserInterface->CreateBVConst(32, (yyvsp[-2].uintval));
  ASTNode output = parserInterface->nf->CreateTerm(BVEXTRACT, width, *(yyvsp[0].node),hi,low);
  ASTNode * n = parserInterface->newNode(output);
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2480 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 779 "smt2.y" /* yacc.c:1646  */
    {
  if (0 != (yyvsp[-2].uintval))
    {
      unsigned w = (yyvsp[0].node)->GetValueWidth() + (yyvsp[-2].uintval);
      ASTNode leading_zeroes = parserInterface->CreateZeroConst((yyvsp[-2].uintval));
      ASTNode *n =  parserInterface->newNode(parserInterface->nf->CreateTerm(BVCONCAT,w,leading_zeroes,*(yyvsp[0].node)));
      (yyval.node) = n;
      parserInterface->deleteNode( (yyvsp[0].node));
    }
  else
    (yyval.node) = (yyvsp[0].node);
}
#line 2497 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 792 "smt2.y" /* yacc.c:1646  */
    {
  unsigned w = (yyvsp[0].node)->GetValueWidth() + (yyvsp[-2].uintval);
  ASTNode width = parserInterface->CreateBVConst(32,w);
  ASTNode *n =  parserInterface->newNode(parserInterface->nf->CreateTerm(BVSX,w,*(yyvsp[0].node),width));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2509 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 801 "smt2.y" /* yacc.c:1646  */
    {
  const unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  (yyval.node) = parserInterface->newNode(parserInterface->nf->CreateArrayTerm(ITE,(yyvsp[0].node)->GetIndexWidth(), width,*(yyvsp[-2].node), *(yyvsp[-1].node), *(yyvsp[0].node)));      
  parserInterface->deleteNode( (yyvsp[-2].node));
  parserInterface->deleteNode( (yyvsp[-1].node));
  parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2521 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 809 "smt2.y" /* yacc.c:1646  */
    {
  const unsigned int width = (yyvsp[-1].node)->GetValueWidth() + (yyvsp[0].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(parserInterface->nf->CreateTerm(BVCONCAT, width, *(yyvsp[-1].node), *(yyvsp[0].node)));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[-1].node));
  parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2533 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 817 "smt2.y" /* yacc.c:1646  */
    {
  //this is the BVNEG (term) in the CVCL language
  unsigned int width = (yyvsp[0].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(parserInterface->nf->CreateTerm(BVNEG, width, *(yyvsp[0].node)));
  (yyval.node) = n;
  parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2545 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 825 "smt2.y" /* yacc.c:1646  */
    {
  //this is the BVUMINUS term in CVCL langauge
  unsigned width = (yyvsp[0].node)->GetValueWidth();
  ASTNode * n =  parserInterface->newNode(parserInterface->nf->CreateTerm(BVUMINUS,width,*(yyvsp[0].node)));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2557 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 833 "smt2.y" /* yacc.c:1646  */
    {
  unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(BVAND, width, *(yyvsp[-1].node), *(yyvsp[0].node));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2569 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 841 "smt2.y" /* yacc.c:1646  */
    {
  unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(BVOR, width, *(yyvsp[-1].node), *(yyvsp[0].node)); 
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2581 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 849 "smt2.y" /* yacc.c:1646  */
    {
  unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(BVXOR, width, *(yyvsp[-1].node), *(yyvsp[0].node));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2593 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 857 "smt2.y" /* yacc.c:1646  */
    {
//   (bvxnor s t) abbreviates (bvor (bvand s t) (bvand (bvnot s) (bvnot t)))
      unsigned int width = (yyvsp[-1].node)->GetValueWidth();
      ASTNode * n = parserInterface->newNode(
      parserInterface->nf->CreateTerm( BVOR, width,
     parserInterface->nf->CreateTerm(BVAND, width, *(yyvsp[-1].node), *(yyvsp[0].node)),
     parserInterface->nf->CreateTerm(BVAND, width,
	     parserInterface->nf->CreateTerm(BVNEG, width, *(yyvsp[-1].node)),
     	 parserInterface->nf->CreateTerm(BVNEG, width, *(yyvsp[0].node))
     )));

      (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2613 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 873 "smt2.y" /* yacc.c:1646  */
    {
  	ASTNode * n = parserInterface->newNode(parserInterface->nf->CreateTerm(ITE, 1, 
  	parserInterface->nf->CreateNode(EQ, *(yyvsp[-1].node), *(yyvsp[0].node)),
  	parserInterface->CreateOneConst(1),
  	parserInterface->CreateZeroConst(1)));
  	
      (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2628 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 884 "smt2.y" /* yacc.c:1646  */
    {
  const unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(BVSUB, width, *(yyvsp[-1].node), *(yyvsp[0].node));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2640 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 892 "smt2.y" /* yacc.c:1646  */
    {
  const unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(BVPLUS, width, *(yyvsp[-1].node), *(yyvsp[0].node));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));

}
#line 2653 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 901 "smt2.y" /* yacc.c:1646  */
    {
  const unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(parserInterface->nf->CreateTerm(BVMULT, width, *(yyvsp[-1].node), *(yyvsp[0].node)));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2665 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 909 "smt2.y" /* yacc.c:1646  */
    {
  unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(BVDIV, width, *(yyvsp[-1].node), *(yyvsp[0].node));
  (yyval.node) = n;

    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2678 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 918 "smt2.y" /* yacc.c:1646  */
    {
  unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(BVMOD, width, *(yyvsp[-1].node), *(yyvsp[0].node));
  (yyval.node) = n;

    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2691 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 927 "smt2.y" /* yacc.c:1646  */
    {
  unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(SBVDIV, width, *(yyvsp[-1].node), *(yyvsp[0].node));
  (yyval.node) = n;

    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2704 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 936 "smt2.y" /* yacc.c:1646  */
    {
  unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(SBVREM, width, *(yyvsp[-1].node), *(yyvsp[0].node));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2716 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 944 "smt2.y" /* yacc.c:1646  */
    {
  unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(SBVMOD, width, *(yyvsp[-1].node), *(yyvsp[0].node));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2728 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 952 "smt2.y" /* yacc.c:1646  */
    {
  unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(parserInterface->nf->CreateTerm(BVNEG, width, parserInterface->nf->CreateTerm(BVAND, width, *(yyvsp[-1].node), *(yyvsp[0].node))));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2740 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 960 "smt2.y" /* yacc.c:1646  */
    {
  unsigned int width = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(parserInterface->nf->CreateTerm(BVNEG, width, parserInterface->nf->CreateTerm(BVOR, width, *(yyvsp[-1].node), *(yyvsp[0].node)))); 
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2752 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 968 "smt2.y" /* yacc.c:1646  */
    {
  // shifting left by who know how much?
  unsigned int w = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(BVLEFTSHIFT,w,*(yyvsp[-1].node),*(yyvsp[0].node));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2765 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 977 "smt2.y" /* yacc.c:1646  */
    {
  // shifting right by who know how much?
  unsigned int w = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(BVRIGHTSHIFT,w,*(yyvsp[-1].node),*(yyvsp[0].node));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2778 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 986 "smt2.y" /* yacc.c:1646  */
    {
  // shifting arithmetic right by who know how much?
  unsigned int w = (yyvsp[-1].node)->GetValueWidth();
  ASTNode * n = parserInterface->newNode(BVSRSHIFT,w,*(yyvsp[-1].node),*(yyvsp[0].node));
  (yyval.node) = n;
    parserInterface->deleteNode( (yyvsp[-1].node));
    parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2791 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 995 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode *n;
  unsigned width = (yyvsp[0].node)->GetValueWidth();
  unsigned rotate = (yyvsp[-2].uintval) % width;
  if (0 == rotate)
    {
      n = (yyvsp[0].node);
    }
  else 
    {
      ASTNode high = parserInterface->CreateBVConst(32,width-1);
      ASTNode zero = parserInterface->CreateBVConst(32,0);
      ASTNode cut = parserInterface->CreateBVConst(32,width-rotate);
      ASTNode cutMinusOne = parserInterface->CreateBVConst(32,width-rotate-1);

      ASTNode top =  parserInterface->nf->CreateTerm(BVEXTRACT,rotate,*(yyvsp[0].node),high, cut);
      ASTNode bottom =  parserInterface->nf->CreateTerm(BVEXTRACT,width-rotate,*(yyvsp[0].node),cutMinusOne,zero);
      n =  parserInterface->newNode(parserInterface->nf->CreateTerm(BVCONCAT,width,bottom,top));
          parserInterface->deleteNode( (yyvsp[0].node));


    }
      
  (yyval.node) = n;
}
#line 2821 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1021 "smt2.y" /* yacc.c:1646  */
    {
  ASTNode *n;
  unsigned width = (yyvsp[0].node)->GetValueWidth();
  unsigned rotate = (yyvsp[-2].uintval) % width;
  if (0 == rotate)
    {
      n = (yyvsp[0].node);
    }
  else 
    {
      ASTNode high = parserInterface->CreateBVConst(32,width-1);
      ASTNode zero = parserInterface->CreateBVConst(32,0);
      ASTNode cut = parserInterface->CreateBVConst(32,rotate); 
      ASTNode cutMinusOne = parserInterface->CreateBVConst(32,rotate-1);

      ASTNode bottom =  parserInterface->nf->CreateTerm(BVEXTRACT,rotate,*(yyvsp[0].node),cutMinusOne, zero);
      ASTNode top =  parserInterface->nf->CreateTerm(BVEXTRACT,width-rotate,*(yyvsp[0].node),high,cut);
      n =  parserInterface->newNode(parserInterface->nf->CreateTerm(BVCONCAT,width,bottom,top));
      parserInterface->deleteNode( (yyvsp[0].node));
    }
      
  (yyval.node) = n;
}
#line 2849 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1045 "smt2.y" /* yacc.c:1646  */
    {
	  unsigned count = (yyvsp[-2].uintval);
	  if (count < 1)
	  	FatalError("One or more repeats please");

	  unsigned w = (yyvsp[0].node)->GetValueWidth();  
      ASTNode n =  *(yyvsp[0].node);
      
      for (unsigned i =1; i < count; i++)
      {
      	  n = parserInterface->nf->CreateTerm(BVCONCAT,w*(i+1),n,*(yyvsp[0].node));
      }
      (yyval.node) = parserInterface->newNode(n);
      parserInterface->deleteNode( (yyvsp[0].node));
}
#line 2869 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1061 "smt2.y" /* yacc.c:1646  */
    {
	(yyval.node) = parserInterface->newNode(parserInterface->CreateBVConst(*(yyvsp[-1].str), 10, (yyvsp[0].uintval)));
    (yyval.node)->SetValueWidth((yyvsp[0].uintval));
    delete (yyvsp[-1].str);
}
#line 2879 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1067 "smt2.y" /* yacc.c:1646  */
    {
	unsigned width = (yyvsp[0].str)->length()*4;
	(yyval.node) = parserInterface->newNode(parserInterface->CreateBVConst(*(yyvsp[0].str), 16, width));
    (yyval.node)->SetValueWidth(width);
    delete (yyvsp[0].str);
}
#line 2890 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1074 "smt2.y" /* yacc.c:1646  */
    {
	unsigned width = (yyvsp[0].str)->length();
	(yyval.node) = parserInterface->newNode(parserInterface->CreateBVConst(*(yyvsp[0].str), 2, width));
    (yyval.node)->SetValueWidth(width);
    delete (yyvsp[0].str);
}
#line 2901 "parsesmt2.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1081 "smt2.y" /* yacc.c:1646  */
    {	
  (yyval.node) = parserInterface->newNode(parserInterface->applyFunction(*(yyvsp[-2].str),*(yyvsp[-1].vec)));
  
  if ((yyval.node)->GetType() != BITVECTOR_TYPE)
  	yyerror("Must be bitvector type");
  
  delete (yyvsp[-2].str);
  delete (yyvsp[-1].vec);
}
#line 2915 "parsesmt2.cpp" /* yacc.c:1646  */
    break;


#line 2919 "parsesmt2.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1093 "smt2.y" /* yacc.c:1906  */

