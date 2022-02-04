/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "ast.y"
	extern char yytext[];
	#define YYDEBUG_LEXER_TEXT yytext

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "ast.h"
	#include "../Backend/codegen.h"
	#include "../Data_Structures/loopStack.h"
	#include "../Data_Structures/GSTable.h"
	#include "../Data_Structures/LSTable.h"
	#include "../Data_Structures/typeTable.h"
	#include "../Data_Structures/paramStruct.h"
	#include "../Data_Structures/TupleListTable.h"
	#include "../Functions/xsm_library.h"
	#include "../Functions/xsm_syscalls.h"
	#include "../Functions/stackMemory.h"
	#include "../Functions/stringMan.h"
	#include "../Functions/label.h"

	int yylex(void);
	void yyerror(char const *s);
	int statementCount = 0;
	char* fileName;
	FILE* filePtr;
#line 31 "ast.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct ASTNode* node;
	struct LSTNode* lstnode;
	struct TypeTable* TTNode;
	struct FieldList* FLNode;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 61 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ID 257
#define NUM 258
#define STRING 259
#define BEGIN_ 260
#define END 261
#define MAIN 262
#define READ 263
#define WRITE 264
#define PLUS 265
#define MINUS 266
#define MUL 267
#define DIV 268
#define MOD 269
#define AMPERSAND 270
#define EQUAL 271
#define BREAKPOINT 272
#define TYPE 273
#define ENDTYPE 274
#define IF 275
#define THEN 276
#define ELSE 277
#define ENDIF 278
#define WHILE 279
#define DO 280
#define ENDWHILE 281
#define BREAK 282
#define CONTINUE 283
#define AND 284
#define OR 285
#define NOT 286
#define DECL 287
#define ENDDECL 288
#define INT 289
#define STR 290
#define TUPLE 291
#define RETURN 292
#define DOT 293
#define EQ 294
#define NEQ 295
#define LT 296
#define LTE 297
#define GT 298
#define GTE 299
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,   28,   28,   32,   32,   33,   24,   27,
   27,   26,   23,   23,   23,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    3,    4,    5,    5,
    5,   17,   16,    6,    6,   11,   12,   13,   14,   15,
   29,   29,   34,   34,   35,   25,   25,   25,   36,   36,
   37,   37,   37,   37,   37,   22,   38,   38,   38,   39,
   40,   40,   40,   40,   40,   21,   21,   21,   20,   30,
   30,    9,   41,   42,   44,   44,   44,   44,   19,   43,
   43,   45,   45,   46,   46,   49,   49,   50,   51,   51,
    8,   47,   47,   47,   48,   48,    7,   52,   52,   31,
   53,   18,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,
};
static const YYINT yylen[] = {                            2,
    4,    3,    2,    3,    0,    2,    1,    4,    1,    2,
    1,    3,    1,    1,    1,    3,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    2,    3,    6,
    4,    1,    3,    7,    5,    5,    5,    1,    1,    1,
    3,    2,    2,    1,    3,    1,    1,    1,    3,    1,
    1,    4,    4,    1,    4,    2,    3,    1,    0,    2,
    1,    1,    2,    2,    1,    3,    1,    0,    1,    2,
    1,    1,    5,    5,    1,    1,    2,    2,    5,    3,
    2,    2,    1,    3,    6,    3,    1,    2,    1,    1,
    1,    1,    1,    2,    3,    1,    1,    1,    2,    7,
    2,    5,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    3,    3,    4,    4,
    2,    2,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    9,    0,    0,    7,    0,    0,    0,
    4,    6,   48,   42,   46,   47,    0,    0,   44,    0,
    0,    0,    2,   71,    0,    0,    0,   15,   13,   14,
    0,   11,    0,    0,    0,    0,    0,   50,   41,   43,
  101,   77,   78,    1,   70,    0,   72,    0,    0,    0,
    8,   10,    0,    0,   56,    0,   45,    0,    0,    0,
    0,    0,   12,    0,   65,    0,    0,    0,   58,    0,
    0,   49,   81,   92,   93,    0,    0,   83,    0,    0,
    0,    0,    0,   52,   63,   64,    0,   53,   60,   55,
   97,   94,   80,   82,   98,    0,    0,    0,   96,    0,
    0,    0,    0,   40,    0,    0,    0,   38,   39,    0,
    0,   18,   19,   20,   21,   22,   23,   24,   25,   26,
   73,   74,    0,   57,   99,   89,   90,    0,   87,    0,
   84,    0,    0,    0,    0,  124,  125,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   17,    0,    0,    0,    0,   91,   88,   95,    0,    0,
    0,    0,    0,  122,  121,  116,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   16,    0,    0,  100,
   86,    0,    0,    0,    0,   67,    0,  118,  117,    0,
    0,  105,  106,  107,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   33,   79,    0,   85,
    0,  120,    0,  119,    0,   35,   36,   37,    0,    0,
   66,    0,  102,   34,
};
static const YYINT yydgoto[] = {                          2,
  110,  111,  112,  113,  114,  115,   92,  157,   48,  195,
  116,  117,  118,  119,  120,  150,  186,  153,   81,  196,
  197,   36,   31,    5,   17,   32,   33,    3,    9,   22,
   23,    6,    7,   18,   19,   37,   38,   68,   69,   70,
   24,   25,   60,   26,   77,   78,   79,   98,  128,  129,
  130,   99,   27,
};
static const YYINT yysindex[] = {                      -257,
 -228,    0, -254,    0,  -46, -252,    0, -240, -219, -225,
    0,    0,    0,    0,    0,    0, -244, -169,    0, -167,
 -164, -219,    0,    0,   -8, -130,  100,    0,    0,    0,
 -113,    0, -124,  -28, -112,  116,  -33,    0,    0,    0,
    0,    0,    0,    0,    0, -128,    0,  117,  119,  103,
    0,    0,  -95, -216,    0, -216,    0, -244, -120,  -96,
 -216,   49,    0,   83,    0,  -93,  -90,   -4,    0,  -79,
   10,    0,    0,    0,    0,  -68, -103,    0,  -20,  390,
   65,   61, -128,    0,    0,    0, -216,    0,    0,    0,
    0,    0,    0,    0,    0,  -66, -158,  -29,    0,  -87,
  -38,  -38,  -65,    0,  -38,  -38,  390,    0,    0, -236,
  134,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -64,    0,    0,    0,    0,   72,    0,  -63,
    0, -200,  -38,  -38,  -32,    0,    0,  -60,  -57,  -38,
  -38,  272,  272,  -69, -187,  237,  404,  -38,  144,  -56,
    0,  390,   79, -158, -200,    0,    0,    0,  272,  -86,
  -38,  -38,  -51,    0,    0,    0,   76,  -38,  -38,  -38,
  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
  -38,  390,  390,  -38,  272,  155,    0,  156, -236,    0,
    0,  -25,  -55,  140,  272,    0,   81,    0,    0, -176,
 -176,    0,    0,    0,  278,  164,  283,  283, -131, -131,
 -131, -131,  272,  321,  345,  229,    0,    0,  -44,    0,
  -38,    0,  -38,    0,  390,    0,    0,    0,  159,  272,
    0,  366,    0,    0,
};
static const YYINT yyrindex[] = {                       -53,
    0,    0,    0,    0,    0,    0,    0,    0,  222,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -34,
  -21,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,    0,   24,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   98,    0,   98,    0,    0,    0,    0,
   98,    0,    0,    0,    0,  -19,  -15,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -41,    0,    0,    0,    0,    0,
    0,  192,  193,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  206,    0,
    0,  109,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  209,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  110,    0,    0,    0,    0,  -35,
    1,    0,    0,    0,  108,  114,   82,  102,   -6,   25,
   31,   55,  210,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  212,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -97,  -85,    0,    0,    0,    0,    0,    0,    0,  309,
    0,    0,    0,    0,    0,   84,    0,    0,    0,   53,
    0,    0,    0,    0,    0,  239,    0,    0,    0,    0,
  258,    0,  277,    0,  266,    0,  236,   45,  200,    0,
  280,    0,  220,    0,    0,  227,    0,  153,    0,  160,
    0,  181,    0,
};
#define YYTABLESIZE 687
static const YYINT yytable[] = {                        123,
   51,  141,  123,  134,    4,  103,  193,  162,  103,  147,
   58,   54,   34,  163,  132,    1,   13,  123,  132,   97,
  100,   11,   35,  103,  149,   57,  101,  102,    4,  131,
  103,   28,    8,  220,  110,  104,   88,  110,  105,   87,
   65,  104,  106,  107,  104,  108,  109,   14,   15,   16,
   90,  123,  110,   87,  189,  148,   95,  103,  161,  104,
   51,  149,   53,   29,   30,  111,   96,   54,  111,   20,
   21,  112,   66,   67,  112,   51,   10,  168,  169,  170,
  171,  172,   54,  111,  214,  215,  110,   13,  182,  112,
  170,  171,  172,  104,   41,  113,  173,  174,  113,   42,
   71,  122,   43,  149,   87,   82,  175,  176,  177,  178,
  179,  180,  155,  113,   46,  154,  199,  111,   39,   15,
   16,  224,  108,  112,  223,  108,   47,  232,  149,  149,
  126,  127,   28,  168,  169,  170,  171,  172,   59,   49,
  108,   59,  109,   50,   55,  109,  149,  113,  114,   68,
   69,  114,   68,   69,  115,   56,   61,  115,   59,   62,
  109,   63,   64,   80,   29,   30,  114,   73,   74,   75,
   76,   83,  115,   85,  108,   84,   86,   89,  168,  169,
  170,  171,  172,  133,   93,   74,   75,   76,   91,  121,
  125,  144,  151,  156,  109,  152,  164,  173,  174,  165,
  114,  181,  187,  190,  188,  198,  115,  175,  176,  177,
  178,  179,  180,  217,  218,  221,  229,  233,  135,  136,
  137,    3,   75,  123,  123,  123,  123,  123,  138,  103,
  103,  139,  222,    5,  123,   76,   95,   61,  123,  123,
  103,   62,  123,  123,  103,  103,   96,  140,  103,  103,
   27,   28,  123,  123,  123,  123,  123,  123,  103,  103,
  103,  103,  103,  103,   29,  104,  104,   32,   31,  110,
   30,   52,  219,  110,  110,  231,  104,  110,  110,   44,
  104,  104,   12,   40,  104,  104,  124,  110,  110,  110,
  110,  110,  110,   72,  104,  104,  104,  104,  104,  104,
  111,   45,  123,   94,  111,  111,  112,  192,  111,  111,
  112,  112,  158,  191,  112,  112,    0,    0,  111,  111,
  111,  111,  111,  111,  112,  112,  112,  112,  112,  112,
  113,    0,    0,    0,  113,  113,    0,    0,  113,  113,
  168,  169,  170,  171,  172,    0,    0,    0,  113,  113,
  113,  113,  113,  113,    0,    0,    0,  108,    0,  173,
  174,  108,  108,    0,    0,  108,  108,    0,    0,  175,
  176,  177,  178,  179,  180,  108,  108,  109,    0,    0,
    0,  109,  109,  114,    0,  109,  109,  114,  114,  115,
    0,  114,  114,  115,  115,  109,  109,    0,  115,    0,
    0,    0,    0,    0,  168,  169,  170,  171,  172,  142,
  143,    0,    0,  145,  146,    0,    0,    0,    0,    0,
    0,    0,    0,  173,  174,    0,    0,    0,  168,  169,
  170,  171,  172,  175,  176,  177,  178,  179,  180,    0,
    0,  159,  160,    0,    0,    0,    0,  173,  166,  167,
    0,    0,    0,    0,    0,    0,  185,  175,  176,  177,
  178,  179,  180,    0,    0,    0,    0,    0,    0,  194,
    0,    0,    0,    0,    0,    0,  200,  201,  202,  203,
  204,  205,  206,  207,  208,  209,  210,  211,  212,  213,
    0,    0,  216,  168,  169,  170,  171,  172,    0,    0,
    0,  168,  169,  170,  171,  172,    0,    0,  183,  228,
    0,    0,  173,  174,    0,    0,  183,    0,    0,    0,
  173,  174,  175,  176,  177,  178,  179,  180,    0,  230,
  175,  176,  177,  178,  179,  180,  168,  169,  170,  171,
  172,    0,  168,  169,  170,  171,  172,  168,  169,  170,
  171,  172,    0,    0,    0,  173,  174,    0,    0,    0,
    0,    0,    0,    0,    0,  175,  176,  177,  178,  179,
  180,  175,  176,  177,  178,  179,  180,  100,  177,  178,
  179,  180,    0,  101,  102,    0,    0,  103,    0,    0,
    0,    0,  104,    0,    0,  105,    0,  225,  226,  106,
  107,  100,  108,  109,    0,    0,    0,  101,  102,    0,
    0,  103,    0,    0,    0,    0,  104,    0,    0,  105,
    0,    0,  100,  106,  107,  227,  108,  109,  101,  102,
    0,    0,  103,    0,    0,    0,    0,  104,    0,    0,
  105,    0,    0,  234,  106,  107,  100,  108,  109,    0,
    0,    0,  101,  102,    0,    0,  103,    0,    0,    0,
  100,  104,    0,    0,  105,    0,  101,  102,  106,  107,
  103,  108,  109,    0,    0,  104,    0,    0,  105,    0,
    0,    0,  184,  107,    0,  108,  109,
};
static const YYINT yycheck[] = {                         41,
  125,   40,   44,   91,  257,   41,   93,   40,   44,  107,
   44,   40,  257,   46,   44,  273,  257,   59,   44,   40,
  257,  274,  267,   59,  110,   59,  263,  264,  257,   59,
  267,  257,  287,   59,   41,  272,   41,   44,  275,   44,
  257,   41,  279,  280,   44,  282,  283,  288,  289,  290,
   41,   93,   59,   44,  152,  292,  257,   93,   91,   59,
   44,  147,   91,  289,  290,   41,  267,   44,   44,  289,
  290,   41,  289,  290,   44,   59,  123,  265,  266,  267,
  268,  269,   59,   59,  182,  183,   93,  257,  276,   59,
  267,  268,  269,   93,  262,   41,  284,  285,   44,  267,
   56,   41,  267,  189,   44,   61,  294,  295,  296,  297,
  298,  299,   41,   59,  123,   44,   41,   93,  288,  289,
  290,   41,   41,   93,   44,   44,  257,  225,  214,  215,
  289,  290,  257,  265,  266,  267,  268,  269,   41,   40,
   59,   44,   41,  257,  257,   44,  232,   93,   41,   41,
   41,   44,   44,   44,   41,   40,   40,   44,  287,   41,
   59,   59,  258,  260,  289,  290,   59,  288,  289,  290,
  291,  123,   59,  267,   93,   93,  267,  257,  265,  266,
  267,  268,  269,  271,  288,  289,  290,  291,  257,  125,
  257,  257,   59,  257,   93,  260,  257,  284,  285,  257,
   93,  271,   59,  125,  261,  257,   93,  294,  295,  296,
  297,  298,  299,   59,   59,  271,  261,   59,  257,  258,
  259,    0,  257,  265,  266,  267,  268,  269,  267,  265,
  266,  270,   93,  287,  276,  257,  257,  257,  280,  281,
  276,  257,  284,  285,  280,  281,  267,  286,  284,  285,
   59,   59,  294,  295,  296,  297,  298,  299,  294,  295,
  296,  297,  298,  299,   59,  265,  266,   59,   59,  276,
   59,   33,  189,  280,  281,  223,  276,  284,  285,   22,
  280,  281,    6,   18,  284,  285,   87,  294,  295,  296,
  297,  298,  299,   58,  294,  295,  296,  297,  298,  299,
  276,   22,   83,   77,  280,  281,  276,  155,  284,  285,
  280,  281,  132,  154,  284,  285,   -1,   -1,  294,  295,
  296,  297,  298,  299,  294,  295,  296,  297,  298,  299,
  276,   -1,   -1,   -1,  280,  281,   -1,   -1,  284,  285,
  265,  266,  267,  268,  269,   -1,   -1,   -1,  294,  295,
  296,  297,  298,  299,   -1,   -1,   -1,  276,   -1,  284,
  285,  280,  281,   -1,   -1,  284,  285,   -1,   -1,  294,
  295,  296,  297,  298,  299,  294,  295,  276,   -1,   -1,
   -1,  280,  281,  276,   -1,  284,  285,  280,  281,  276,
   -1,  284,  285,  280,  281,  294,  295,   -1,  285,   -1,
   -1,   -1,   -1,   -1,  265,  266,  267,  268,  269,  101,
  102,   -1,   -1,  105,  106,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  284,  285,   -1,   -1,   -1,  265,  266,
  267,  268,  269,  294,  295,  296,  297,  298,  299,   -1,
   -1,  133,  134,   -1,   -1,   -1,   -1,  284,  140,  141,
   -1,   -1,   -1,   -1,   -1,   -1,  148,  294,  295,  296,
  297,  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,  161,
   -1,   -1,   -1,   -1,   -1,   -1,  168,  169,  170,  171,
  172,  173,  174,  175,  176,  177,  178,  179,  180,  181,
   -1,   -1,  184,  265,  266,  267,  268,  269,   -1,   -1,
   -1,  265,  266,  267,  268,  269,   -1,   -1,  280,  281,
   -1,   -1,  284,  285,   -1,   -1,  280,   -1,   -1,   -1,
  284,  285,  294,  295,  296,  297,  298,  299,   -1,  221,
  294,  295,  296,  297,  298,  299,  265,  266,  267,  268,
  269,   -1,  265,  266,  267,  268,  269,  265,  266,  267,
  268,  269,   -1,   -1,   -1,  284,  285,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  294,  295,  296,  297,  298,
  299,  294,  295,  296,  297,  298,  299,  257,  296,  297,
  298,  299,   -1,  263,  264,   -1,   -1,  267,   -1,   -1,
   -1,   -1,  272,   -1,   -1,  275,   -1,  277,  278,  279,
  280,  257,  282,  283,   -1,   -1,   -1,  263,  264,   -1,
   -1,  267,   -1,   -1,   -1,   -1,  272,   -1,   -1,  275,
   -1,   -1,  257,  279,  280,  281,  282,  283,  263,  264,
   -1,   -1,  267,   -1,   -1,   -1,   -1,  272,   -1,   -1,
  275,   -1,   -1,  278,  279,  280,  257,  282,  283,   -1,
   -1,   -1,  263,  264,   -1,   -1,  267,   -1,   -1,   -1,
  257,  272,   -1,   -1,  275,   -1,  263,  264,  279,  280,
  267,  282,  283,   -1,   -1,  272,   -1,   -1,  275,   -1,
   -1,   -1,  279,  280,   -1,  282,  283,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 299
#define YYUNDFTOKEN 355
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"ID","NUM","STRING","BEGIN_","END","MAIN","READ","WRITE","PLUS","MINUS","MUL",
"DIV","MOD","AMPERSAND","EQUAL","BREAKPOINT","TYPE","ENDTYPE","IF","THEN",
"ELSE","ENDIF","WHILE","DO","ENDWHILE","BREAK","CONTINUE","AND","OR","NOT",
"DECL","ENDDECL","INT","STR","TUPLE","RETURN","DOT","EQ","NEQ","LT","LTE","GT",
"GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : TypeDefBlock GDeclBlock FDefBlock MainBlock",
"start : TypeDefBlock GDeclBlock MainBlock",
"start : TypeDefBlock GDeclBlock",
"TypeDefBlock : TYPE TypeDefList ENDTYPE",
"TypeDefBlock :",
"TypeDefList : TypeDefList TypeDef",
"TypeDefList : TypeDef",
"TypeDef : TypeID '{' FieldDeclList '}'",
"TypeID : ID",
"FieldDeclList : FieldDeclList FieldDecl",
"FieldDeclList : FieldDecl",
"FieldDecl : TypeName ID ';'",
"TypeName : INT",
"TypeName : STR",
"TypeName : ID",
"Slist : Slist Stmt ';'",
"Slist : Stmt ';'",
"Stmt : inputStmt",
"Stmt : outputStmt",
"Stmt : assignStmt",
"Stmt : ifStmt",
"Stmt : whileStmt",
"Stmt : doWhileStmt",
"Stmt : breakStmt",
"Stmt : continueStmt",
"Stmt : breakPointStmt",
"inputStmt : READ expr",
"outputStmt : WRITE expr",
"assignStmt : ID EQUAL expr",
"assignStmt : ID '[' expr ']' EQUAL expr",
"assignStmt : MUL ID EQUAL expr",
"retVal : expr",
"retStmt : RETURN retVal ';'",
"ifStmt : IF expr THEN Slist ELSE Slist ENDIF",
"ifStmt : IF expr THEN Slist ENDIF",
"whileStmt : WHILE expr DO Slist ENDWHILE",
"doWhileStmt : DO Slist WHILE expr ENDWHILE",
"breakStmt : BREAK",
"continueStmt : CONTINUE",
"breakPointStmt : BREAKPOINT",
"GDeclBlock : DECL GDeclList ENDDECL",
"GDeclBlock : DECL ENDDECL",
"GDeclList : GDeclList GDecl",
"GDeclList : GDecl",
"GDecl : GType GIDList ';'",
"GType : INT",
"GType : STR",
"GType : ID",
"GIDList : GIDList ',' GID",
"GIDList : GID",
"GID : ID",
"GID : ID '[' NUM ']'",
"GID : ID '(' ParamList ')'",
"GID : GPtrID",
"GID : GPtrID '(' ParamList ')'",
"GPtrID : MUL ID",
"ParamList : ParamList ',' Param",
"ParamList : Param",
"ParamList :",
"Param : ParamType ID",
"ParamType : INT",
"ParamType : STR",
"ParamType : INT MUL",
"ParamType : STR MUL",
"ParamType : ID",
"ArgList : ArgList ',' Arg",
"ArgList : Arg",
"ArgList :",
"Arg : expr",
"FDefBlock : FDefBlock FDef",
"FDefBlock : FDef",
"FID : ID",
"FDef : FuncSign '{' LDeclBlock FBody '}'",
"FuncSign : FuncType FID '(' ParamList ')'",
"FuncType : INT",
"FuncType : STR",
"FuncType : INT MUL",
"FuncType : STR MUL",
"FBody : BEGIN_ Slist retStmt END ';'",
"LDeclBlock : DECL LDeclList ENDDECL",
"LDeclBlock : DECL ENDDECL",
"LDeclList : LDeclList LDecl",
"LDeclList : LDecl",
"LDecl : LType LIDList ';'",
"LDecl : LType '(' TupleFieldList ')' LIDList ';'",
"TupleFieldList : TupleFieldList ',' TupleField",
"TupleFieldList : TupleField",
"TupleField : TupleFieldType TupleFieldID",
"TupleFieldType : INT",
"TupleFieldType : STR",
"TupleFieldID : ID",
"LType : INT",
"LType : STR",
"LType : TUPLE TupleID",
"LIDList : LIDList ',' LID",
"LIDList : LID",
"TupleID : ID",
"LID : ID",
"LID : MUL ID",
"MainBlock : MainFunc '(' ')' '{' LDeclBlock MBody '}'",
"MainFunc : INT MAIN",
"MBody : BEGIN_ Slist retStmt END ';'",
"expr : expr PLUS expr",
"expr : expr MINUS expr",
"expr : expr MUL expr",
"expr : expr DIV expr",
"expr : expr MOD expr",
"expr : expr EQ expr",
"expr : expr NEQ expr",
"expr : expr LT expr",
"expr : expr LTE expr",
"expr : expr GT expr",
"expr : expr GTE expr",
"expr : expr AND expr",
"expr : expr OR expr",
"expr : NOT expr",
"expr : '(' expr ')'",
"expr : ID '.' ID",
"expr : ID '(' ArgList ')'",
"expr : ID '[' expr ']'",
"expr : AMPERSAND ID",
"expr : MUL ID",
"expr : ID",
"expr : NUM",
"expr : STRING",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 581 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at statement %d\n", s, statementCount);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yydebug = 0;
		filePtr = fopen("../Target_Files/round1.xsm", "w");
		writeXexeHeader(filePtr);
		TypeTableCreate();
		yyparse();
	}
	else{
		printf("\nEnter Filename\n");
		exit(1);
	}

	printf("\n✅ Successfully Compiled: Target code saved in target.xsm\n");
	
	char targetFile[50];
	sprintf(targetFile, "%s.xsm", argv[1]);

	return 0;
}
#line 622 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 61 "ast.y"
	{}
break;
case 2:
#line 62 "ast.y"
	{}
break;
case 3:
#line 63 "ast.y"
	{	
												printf("\n⛔ No Code Provided\n");
												exit(1);
											}
break;
case 4:
#line 72 "ast.y"
	{ printTypeTable(); }
break;
case 6:
#line 76 "ast.y"
	{}
break;
case 7:
#line 77 "ast.y"
	{}
break;
case 8:
#line 81 "ast.y"
	{ 
													FLPrint(yystack.l_mark[-3].TTNode); 
													yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-1].FLNode;
													fieldListTail = NULL;
													fieldListHead = NULL;
												}
break;
case 9:
#line 89 "ast.y"
	{ yyval.TTNode = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); }
break;
case 10:
#line 92 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[-1].FLNode;
												}
break;
case 11:
#line 98 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = 0;
													fieldListHead = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[0].FLNode;
				 								}
break;
case 12:
#line 106 "ast.y"
	{ yyval.FLNode = FLCreateNode(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-2].TTNode); }
break;
case 13:
#line 109 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 14:
#line 110 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 15:
#line 111 "ast.y"
	{ yyval.TTNode = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 16:
#line 116 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 17:
#line 117 "ast.y"
	{}
break;
case 26:
#line 123 "ast.y"
	{ ++statementCount; }
break;
case 27:
#line 126 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 28:
#line 129 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 29:
#line 132 "ast.y"
	{ 
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
											}
break;
case 30:
#line 136 "ast.y"
	{	 
												yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
												yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 31:
#line 141 "ast.y"
	{
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);	
												struct ASTNode* mulNode;
												if (yystack.l_mark[-2].node->dataType == TYPE_INT_PTR)
													mulNode = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[-2].node, NULL);

												if (yystack.l_mark[-2].node->dataType == TYPE_STR_PTR)
													mulNode = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[-2].node, NULL);
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, mulNode, NULL, yystack.l_mark[0].node);
											}
break;
case 32:
#line 155 "ast.y"
	{}
break;
case 33:
#line 158 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, RETURN_NODE, NULL, 0, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 34:
#line 163 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 35:
#line 164 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 36:
#line 167 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 37:
#line 170 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 38:
#line 173 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 39:
#line 176 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 40:
#line 179 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 41:
#line 248 "ast.y"
	{
												GSTPrint(); 					
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 42:
#line 253 "ast.y"
	{}
break;
case 43:
#line 256 "ast.y"
	{}
break;
case 44:
#line 257 "ast.y"
	{}
break;
case 45:
#line 260 "ast.y"
	{}
break;
case 46:
#line 263 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 47:
#line 264 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 48:
#line 265 "ast.y"
	{ 
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {
													printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}
			 								}
break;
case 49:
#line 274 "ast.y"
	{}
break;
case 50:
#line 275 "ast.y"
	{}
break;
case 51:
#line 278 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, currentGDeclType->size, NULL); }
break;
case 52:
#line 279 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 53:
#line 286 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 54:
#line 292 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 55:
#line 299 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[-3].node->nodeName, TTLookUp("int*"), -1, getParamListHead());	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[-3].node->nodeName, TTLookUp("str*"), -1, getParamListHead());

												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 56:
#line 312 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 57:
#line 317 "ast.y"
	{}
break;
case 58:
#line 318 "ast.y"
	{}
break;
case 59:
#line 319 "ast.y"
	{}
break;
case 60:
#line 322 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 61:
#line 328 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 62:
#line 329 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 63:
#line 330 "ast.y"
	{  }
break;
case 64:
#line 331 "ast.y"
	{  }
break;
case 65:
#line 332 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 66:
#line 340 "ast.y"
	{ 
											yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node);
										}
break;
case 67:
#line 343 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 344 "ast.y"
	{}
break;
case 69:
#line 347 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node; 
											/* ++argCount;*/
										}
break;
case 70:
#line 356 "ast.y"
	{}
break;
case 71:
#line 357 "ast.y"
	{}
break;
case 72:
#line 360 "ast.y"
	{ 
															if(GSTLookup(yystack.l_mark[0].node->nodeName) == NULL){
																printf("\nFunction %s is not declared\n", yystack.l_mark[0].node->nodeName);
																exit(1);
															}
															yyval.node = yystack.l_mark[0].node; 
															setCurrentFuncName(yystack.l_mark[0].node->nodeName);
														}
break;
case 73:
#line 371 "ast.y"
	{
															char* currentFuncName = getCurrentFuncName();
															addFunctionLST(currentFuncName, LSTHead);	
															
															fprintf(filePtr, "F%d:\n", GSTLookup(currentFuncName)->fLabel);
															initFuncCalle(filePtr, paramCount);

															/* printAST($4);*/
															codeGen(yystack.l_mark[-1].node, filePtr);

															/* LSTPrint();*/
															flushLST();
															paramCount = 0;
														}
break;
case 74:
#line 387 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 75:
#line 393 "ast.y"
	{ setFuncType(TYPE_INT); }
break;
case 76:
#line 394 "ast.y"
	{ setFuncType(TYPE_STR); }
break;
case 77:
#line 395 "ast.y"
	{ setFuncType(TYPE_INT_PTR); }
break;
case 78:
#line 396 "ast.y"
	{ setFuncType(TYPE_STR_PTR); }
break;
case 79:
#line 399 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 80:
#line 408 "ast.y"
	{ 
											/* LSTPrint(); */
											/* printTupleList();*/
										}
break;
case 81:
#line 412 "ast.y"
	{}
break;
case 82:
#line 415 "ast.y"
	{}
break;
case 83:
#line 416 "ast.y"
	{}
break;
case 84:
#line 419 "ast.y"
	{}
break;
case 85:
#line 420 "ast.y"
	{ 
																	struct TupleList* currentTupleList = getTuple(getCurrentTupleID());
																	currentTupleList->tupleFieldListHead = tupleFieldListHead;
																	/* printTupleFieldList();*/
																	flushTupleFieldList();
																	/* printTupleTypeTable();*/
																	flushTupleFieldCount();		
																}
break;
case 86:
#line 430 "ast.y"
	{}
break;
case 87:
#line 431 "ast.y"
	{}
break;
case 88:
#line 434 "ast.y"
	{ 
													incTupleFieldCount(); 
													insertTupleField(yystack.l_mark[0].node->nodeName, getTupleFieldType());
												}
break;
case 89:
#line 440 "ast.y"
	{ setTupleFieldType(TYPE_INT); }
break;
case 90:
#line 441 "ast.y"
	{ setTupleFieldType(TYPE_STR); }
break;
case 91:
#line 444 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 447 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 93:
#line 448 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 94:
#line 449 "ast.y"
	{ 
											setCurrentTupleID(yystack.l_mark[0].node->nodeName);	
											insertTuple(yystack.l_mark[0].node->nodeName);			
											struct TupleTypeTable* newTTTNode = insertTupleType(yystack.l_mark[0].node->nodeName);
											setDeclarationType(newTTTNode->tupleTypeNum);
							 			}
break;
case 95:
#line 457 "ast.y"
	{}
break;
case 96:
#line 458 "ast.y"
	{}
break;
case 97:
#line 461 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node;
										}
break;
case 98:
#line 466 "ast.y"
	{ 
											if (getTupleFieldCount() == 0)		/* For non-tuples*/
												LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1); 
											else 								/* For Tuples*/
												LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), getTupleFieldCount()); 
										}
break;
case 99:
#line 472 "ast.y"
	{
											if(getDeclarationType() == TYPE_INT)
												LSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1);	

											if(getDeclarationType() == TYPE_STR)
												LSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1);	
										}
break;
case 100:
#line 488 "ast.y"
	{
														char* currentFuncName = getCurrentFuncName();
														addFunctionLST(currentFuncName, LSTHead);	

														fprintf(filePtr, "F0:\n");
														initFuncCalle(filePtr, paramCount);

														/* printAST($6);*/
														codeGen(yystack.l_mark[-1].node, filePtr);
														/* LSTPrint();*/
														flushLST();
														paramCount = 0;
												
														/* printFLT();*/
													}
break;
case 101:
#line 505 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 102:
#line 508 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 103:
#line 516 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 104:
#line 517 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 105:
#line 518 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 106:
#line 519 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 107:
#line 520 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 108:
#line 521 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 109:
#line 522 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 110:
#line 523 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 111:
#line 524 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 112:
#line 525 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 113:
#line 526 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 114:
#line 527 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, AND_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 115:
#line 528 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, OR_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 116:
#line 529 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NOT_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 117:
#line 530 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 118:
#line 531 "ast.y"
	{ 
										yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
										struct TupleList* TLNode = getTuple(getTupleTypeName(yystack.l_mark[-2].node->dataType));
										struct TupleFieldList* TFLNode = searchTupleField(TLNode->tupleFieldListHead, yystack.l_mark[0].node->nodeName);
										yystack.l_mark[0].node->dataType = TFLNode->tupleFieldType;
										yystack.l_mark[-2].node->left = yystack.l_mark[0].node;
										yystack.l_mark[-2].node->dataType = TFLNode->tupleFieldType;
										yystack.l_mark[-2].node->nodeType = TUPLE_FIELD_NODE;
			 						}
break;
case 119:
#line 540 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, 0, NULL, NULL, NULL, NULL); 
										yyval.node->argListHead = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 120:
#line 547 "ast.y"
	{	
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
										if (yystack.l_mark[-1].node->dataType != TYPE_INT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;	
										yyval.node = yystack.l_mark[-3].node;
									}
break;
case 121:
#line 556 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->dataType == TYPE_INT || yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT_PTR, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR || yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR_PTR, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 122:
#line 564 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 123:
#line 572 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 124:
#line 576 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 125:
#line 577 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1481 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
