/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 76 "smt2.y" /* yacc.c:1909  */
  
  unsigned uintval;                  /* for numerals in types. */
  //ASTNode,ASTVec
  BEEV::ASTNode *node;
  BEEV::ASTVec *vec;
  std::string *str;

#line 145 "parsesmt2.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE smt2lval;

int smt2parse (void);

#endif /* !YY_SMT2_PARSESMT2_HPP_INCLUDED  */
