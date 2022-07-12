/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BEGIN_ = 258,
    END = 259,
    READ = 260,
    WRITE = 261,
    ID = 262,
    NUM = 263,
    STRING = 264,
    PLUS = 265,
    MINUS = 266,
    MUL = 267,
    DIV = 268,
    MOD = 269,
    AMPERSAND = 270,
    EQUAL = 271,
    BREAKPOINT = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    ENDIF = 276,
    WHILE = 277,
    DO = 278,
    ENDWHILE = 279,
    BREAK = 280,
    CONTINUE = 281,
    DECL = 282,
    ENDDECL = 283,
    INT = 284,
    STR = 285,
    RETURN = 286,
    SEMICOLON = 287,
    COMMA = 288,
    EQ = 289,
    NEQ = 290,
    LT = 291,
    LTE = 292,
    GT = 293,
    GTE = 294
  };
#endif
/* Tokens.  */
#define BEGIN_ 258
#define END 259
#define READ 260
#define WRITE 261
#define ID 262
#define NUM 263
#define STRING 264
#define PLUS 265
#define MINUS 266
#define MUL 267
#define DIV 268
#define MOD 269
#define AMPERSAND 270
#define EQUAL 271
#define BREAKPOINT 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define BREAK 280
#define CONTINUE 281
#define DECL 282
#define ENDDECL 283
#define INT 284
#define STR 285
#define RETURN 286
#define SEMICOLON 287
#define COMMA 288
#define EQ 289
#define NEQ 290
#define LT 291
#define LTE 292
#define GT 293
#define GTE 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "ast.y"

	struct ASTNode* node;

#line 139 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
