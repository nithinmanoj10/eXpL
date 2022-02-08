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
	#include <limits.h>
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
	int typeFieldCount = 0;
	char* fileName;
	FILE* filePtr;
#line 33 "ast.y"
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
#line 63 "y.tab.c"

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
#define INITIALIZE 260
#define ALLOC 261
#define FREE 262
#define NULL_ 263
#define BEGIN_ 264
#define END 265
#define MAIN 266
#define READ 267
#define WRITE 268
#define PLUS 269
#define MINUS 270
#define MUL 271
#define DIV 272
#define MOD 273
#define AMPERSAND 274
#define EQUAL 275
#define BREAKPOINT 276
#define TYPE 277
#define ENDTYPE 278
#define IF 279
#define THEN 280
#define ELSE 281
#define ENDIF 282
#define WHILE 283
#define DO 284
#define ENDWHILE 285
#define BREAK 286
#define CONTINUE 287
#define AND 288
#define OR 289
#define NOT 290
#define DECL 291
#define ENDDECL 292
#define INT 293
#define STR 294
#define RETURN 295
#define EQ 296
#define NEQ 297
#define LT 298
#define LTE 299
#define GT 300
#define GTE 301
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,   30,   30,   34,   34,   35,   26,   29,
   29,   28,   25,   25,   25,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    3,    4,    5,
    5,    5,    5,   15,   14,    6,    6,    9,   10,   11,
   12,   13,   31,   31,   37,   37,   38,   27,   27,   27,
   39,   39,   40,   40,   40,   40,   40,   20,   41,   41,
   41,   42,   43,   43,   43,   43,   43,   19,   19,   19,
   18,   32,   32,    7,   44,   45,   47,   47,   47,   47,
   47,   17,   46,   46,   46,   48,   48,   49,   50,   50,
   50,   51,   51,   52,   52,   33,   53,   16,   36,   36,
   36,   23,   24,   22,   21,   21,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
};
static const YYINT yylen[] = {                            2,
    4,    3,    2,    3,    0,    2,    1,    4,    1,    2,
    1,    3,    1,    1,    1,    3,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    2,    2,    3,
    6,    4,    3,    1,    3,    7,    5,    5,    5,    1,
    1,    1,    3,    2,    2,    1,    3,    1,    1,    1,
    3,    1,    1,    4,    4,    1,    4,    2,    3,    1,
    0,    2,    1,    1,    2,    2,    1,    3,    1,    0,
    1,    2,    1,    1,    5,    5,    1,    1,    2,    2,
    1,    5,    3,    0,    2,    2,    1,    3,    1,    1,
    1,    3,    1,    1,    2,    7,    2,    5,    1,    1,
    1,    5,    6,    5,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    3,    1,    4,    4,    2,    2,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    9,    0,    0,    7,    0,    0,    0,
    4,    6,   50,   44,   48,   49,    0,    0,   46,   81,
    0,    0,    0,    2,   73,    0,    0,    0,   15,   13,
   14,    0,   11,    0,    0,    0,    0,    0,   52,   43,
   45,   97,   79,   80,    1,   72,    0,   74,    0,    0,
    0,    8,   10,    0,    0,   58,    0,   47,    0,    0,
    0,    0,    0,   12,    0,   67,    0,    0,    0,   60,
    0,    0,   51,   91,   85,   89,   90,    0,   87,    0,
    0,    0,    0,    0,   54,   65,   66,    0,   55,   62,
   57,   83,   86,   94,    0,    0,   93,    0,    0,    0,
    0,   42,    0,    0,    0,   40,   41,    0,    0,   18,
   19,   20,   21,   22,   23,   24,   25,   26,    0,  101,
   99,  100,   27,   75,   76,    0,   59,   95,   88,    0,
    0,    0,    0,    0,  128,  129,  130,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   17,    0,    0,    0,    0,   92,    0,    0,    0,
    0,    0,  106,    0,    0,  126,  125,  120,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   16,    0,
    0,  105,    0,   96,    0,    0,    0,    0,    0,    0,
   69,    0,  121,    0,    0,  109,  110,  111,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   35,   82,    0,  104,  102,    0,    0,  124,    0,  123,
    0,   37,   38,   39,    0,  103,    0,   68,    0,   98,
   36,
};
static const YYINT yydgoto[] = {                          2,
  108,  109,  110,  111,  112,  113,   49,  200,  114,  115,
  116,  117,  118,  151,  188,  156,   82,  201,  202,   37,
  143,  120,  121,  122,   32,    5,   17,   33,   34,    3,
    9,   23,   24,    6,    7,  123,   18,   19,   38,   39,
   69,   70,   71,   25,   26,   61,   27,   78,   79,   80,
   96,   97,   28,
};
static const YYINT yysindex[] = {                      -244,
 -226,    0, -240,    0,  -70, -252,    0, -238, -228, -217,
    0,    0,    0,    0,    0,    0, -246, -219,    0,    0,
 -251, -200, -228,    0,    0,  -63, -169,   50,    0,    0,
    0, -149,    0, -123,  -32, -147,   83,  -37,    0,    0,
    0,    0,    0,    0,    0,    0, -177,    0,   84,   75,
   72,    0,    0, -125, -189,    0, -189,    0, -246, -214,
 -128, -189,   16,    0,   55,    0, -122, -121,  -14,    0,
 -106,    3,    0,    0,    0,    0,    0, -211,    0, -234,
  486,   40,   58, -177,    0,    0,    0, -189,    0,    0,
    0,    0,    0,    0,  -93,  -31,    0,  -29,  202,  202,
  -90,    0,  202,  202,  486,    0,    0,  -82,  107,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -34,    0,
    0,    0,    0,    0,    0,  -96,    0,    0,    0, -234,
  193,  202,  -85,  -30,    0,    0,    0,  -84,  -81,  202,
  202,  372,  132,  372,  -88, -143,  249,  507,  202,  120,
  -75,    0,  202,  -64,  486,   70,    0,  156,  158,  163,
  372,  -89,    0,  202,  202,    0,    0,    0,   97,  202,
  202,  202,  202,  202,  202,  202,  202,  202,  202,  202,
  202,  202,  202,  486,  486,  202,  372,  155,    0,  157,
  372,    0,  -82,    0,  174,  176,  202,  -57,  216,  372,
    0,   59,    0, -129, -129,    0,    0,    0,  199,  378,
  333,  333, -110, -110, -110, -110,  372,  423,  444,  339,
    0,    0,  -46,    0,    0,  111,  202,    0,  202,    0,
  486,    0,    0,    0,  161,    0,  372,    0,  465,    0,
    0,
};
static const YYINT yyrindex[] = {                       -69,
    0,    0,    0,    0,    0,    0,    0,    0,  221,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -33,   -6,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -23,    0,  -10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -39,    0,    0,    0,
    0,    0,    0,    0,   65,    0,   65,    0,    0,    0,
    0,   65,    0,    0,    0,    0,   -5,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -39,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -41,    0,    0,    0,    0,    0,    0,
    0,  164,  -35,  168,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  211,    0,    0,    0,   74,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  213,    0,    0,    0,
  218,    0,    0,    0,    0,    0,    0,    0,    0,   81,
    0,    0,    0,   -2,    4,    0,    0,    0,   -9,   28,
  133,  147,   26,   48,   54,   76,  222,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  226,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
  -91, -107,    0,    0,    0,    0,    0,  403,    0,    0,
    0,    0,    0,   98,    0,    0,    0,   61,    0,    0,
  376,    0,    0,    0,    0,    0,    0,  273,    0,    0,
    0,    0,  293,    0,  312,    0,    0,  301,    0,  261,
   39,  233,    0,  306,    0,  246,    0,    0,  253,    0,
    0,  205,    0,
};
#define YYTABLESIZE 794
static const YYINT yytable[] = {                        127,
  150,   52,  127,  198,    4,  122,   59,   55,  122,  165,
   35,  154,  130,  148,   42,  133,  133,  127,   13,   43,
   53,   58,   94,  122,   36,   11,   89,  129,   20,   88,
    4,  118,    1,   56,  118,   53,   95,   13,  107,   29,
  150,  107,   74,   91,  108,   74,   88,  108,   56,  118,
    8,  127,   10,   14,   15,   16,  107,  122,   54,   47,
  164,  132,  108,  193,   21,   22,  114,   66,  119,  114,
   44,  119,   40,   15,   16,   30,   31,   75,   76,   77,
   92,   76,   77,  118,  114,  150,  119,   48,  115,   50,
  107,  115,  218,  219,  116,   72,  108,  116,  125,  230,
   83,   88,  229,   67,   68,   61,  115,   51,   61,   56,
  150,  150,  116,   60,   70,   63,  117,   70,  114,  117,
  119,   71,   57,   62,   71,  170,  171,  172,  173,  174,
   64,  150,   65,   29,  117,   81,  184,  203,   84,  239,
  115,  172,  173,  174,  175,  176,  116,   85,   86,   87,
   90,  236,  177,  178,  179,  180,  181,  182,  170,  171,
  172,  173,  174,  128,  124,  152,  145,  155,  117,   30,
   31,  163,  166,  112,   98,  167,  112,  154,  189,  170,
  171,  172,  173,  174,   99,  100,  183,  113,  101,  190,
  113,  112,  192,  102,  194,  195,  103,  196,  175,  176,
  104,  105,  197,  106,  107,  113,  177,  178,  179,  180,
  181,  182,  149,  221,  224,  222,  225,  227,  235,  240,
    3,    5,   28,   77,   84,  112,   29,  127,  127,  127,
  127,  127,  141,  122,  122,  122,  122,  122,  127,  113,
  153,  141,  127,  127,  122,  131,  127,  127,  122,  122,
   78,   63,  122,  122,  127,  127,  127,  127,  127,  127,
  122,  122,  122,  122,  122,  122,  107,  107,   64,   30,
  118,   34,  108,  108,  118,  118,   33,  107,  118,  118,
   32,  107,  107,  108,   31,  107,  107,  108,  108,  238,
  223,  108,  108,  107,  107,  107,  107,  107,  107,  108,
  108,  108,  108,  108,  108,  114,   53,  119,  228,  114,
  114,  119,  119,  114,  114,   45,  119,   12,   41,   73,
  127,  114,  114,  114,  114,  114,  114,  115,   46,  126,
   93,  115,  115,  116,  157,  115,  115,  116,  116,    0,
    0,  116,  116,  115,  115,  115,  115,  115,  115,  116,
  116,  116,  116,  116,  116,  117,    0,    0,    0,  117,
  117,    0,    0,  117,  117,  170,  171,  172,  173,  174,
    0,  117,  117,  117,  117,  117,  117,    0,    0,  170,
  171,  172,  173,  174,  175,  176,    0,    0,    0,    0,
    0,    0,  177,  178,  179,  180,  181,  182,  175,  176,
    0,    0,    0,    0,    0,    0,  177,  178,  179,  180,
  181,  182,  112,    0,    0,    0,  112,  112,    0,    0,
  112,  112,    0,    0,    0,    0,  113,    0,  112,  112,
  113,  113,    0,    0,  113,  113,    0,    0,    0,    0,
    0,    0,  113,  113,    0,    0,    0,    0,    0,  134,
  135,  136,  158,  159,  160,  137,  119,    0,  134,  135,
  136,    0,    0,  138,  137,    0,  139,  170,  171,  172,
  173,  174,  138,    0,    0,  139,    0,    0,    0,    0,
  119,    0,  140,  119,  170,  171,  172,  173,  174,    0,
    0,  140,    0,    0,  177,  178,  179,  180,  181,  182,
    0,  142,  144,  175,  176,  146,  147,    0,    0,    0,
    0,  177,  178,  179,  180,  181,  182,  170,  171,  172,
  173,  174,    0,  119,    0,    0,    0,    0,    0,    0,
  119,    0,  185,  161,  162,    0,  175,  176,    0,    0,
    0,    0,  168,  169,  177,  178,  179,  180,  181,  182,
    0,  187,    0,    0,    0,  191,    0,    0,    0,  119,
  119,    0,    0,    0,    0,    0,  199,    0,  119,    0,
    0,    0,  204,  205,  206,  207,  208,  209,  210,  211,
  212,  213,  214,  215,  216,  217,    0,    0,  220,    0,
    0,    0,    0,  119,  119,    0,    0,    0,    0,  226,
    0,  170,  171,  172,  173,  174,  119,  170,  171,  172,
  173,  174,    0,    0,  119,    0,    0,    0,    0,    0,
    0,    0,  185,  234,    0,    0,  175,  176,    0,  237,
  179,  180,  181,  182,  177,  178,  179,  180,  181,  182,
  170,  171,  172,  173,  174,    0,  170,  171,  172,  173,
  174,    0,    0,    0,    0,    0,    0,    0,    0,  175,
  176,    0,    0,    0,    0,  175,    0,  177,  178,  179,
  180,  181,  182,  177,  178,  179,  180,  181,  182,   98,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   99,
  100,    0,    0,  101,    0,    0,    0,    0,  102,    0,
   98,  103,    0,  231,  232,  104,  105,    0,  106,  107,
   99,  100,    0,    0,  101,    0,    0,    0,    0,  102,
    0,   98,  103,    0,    0,    0,  104,  105,  233,  106,
  107,   99,  100,    0,    0,  101,    0,    0,    0,    0,
  102,    0,   98,  103,    0,    0,  241,  104,  105,    0,
  106,  107,   99,  100,    0,    0,  101,    0,    0,    0,
    0,  102,    0,   98,  103,    0,    0,    0,  104,  105,
    0,  106,  107,   99,  100,    0,    0,  101,    0,    0,
    0,    0,  102,    0,    0,  103,    0,    0,    0,  186,
  105,    0,  106,  107,
};
static const YYINT yycheck[] = {                         41,
  108,  125,   44,   93,  257,   41,   44,   40,   44,   40,
  257,   46,   44,  105,  266,   46,   46,   59,  257,  271,
   44,   59,  257,   59,  271,  278,   41,   59,  257,   44,
  257,   41,  277,   44,   44,   59,  271,  257,   41,  257,
  148,   44,  257,   41,   41,  257,   44,   44,   59,   59,
  291,   93,  123,  292,  293,  294,   59,   93,   91,  123,
   91,   91,   59,  155,  293,  294,   41,  257,   41,   44,
  271,   44,  292,  293,  294,  293,  294,  292,  293,  294,
  292,  293,  294,   93,   59,  193,   59,  257,   41,   40,
   93,   44,  184,  185,   41,   57,   93,   44,   41,   41,
   62,   44,   44,  293,  294,   41,   59,  257,   44,  257,
  218,  219,   59,  291,   41,   41,   41,   44,   93,   44,
   93,   41,   40,   40,   44,  269,  270,  271,  272,  273,
   59,  239,  258,  257,   59,  264,  280,   41,  123,  231,
   93,  271,  272,  273,  288,  289,   93,   93,  271,  271,
  257,   41,  296,  297,  298,  299,  300,  301,  269,  270,
  271,  272,  273,  257,  125,   59,  257,  264,   93,  293,
  294,  257,  257,   41,  257,  257,   44,   46,   59,  269,
  270,  271,  272,  273,  267,  268,  275,   41,  271,  265,
   44,   59,  257,  276,  125,   40,  279,   40,  288,  289,
  283,  284,   40,  286,  287,   59,  296,  297,  298,  299,
  300,  301,  295,   59,   41,   59,   41,  275,  265,   59,
    0,  291,   59,  257,  264,   93,   59,  269,  270,  271,
  272,  273,   40,  269,  270,  271,  272,  273,  280,   93,
  275,   40,  284,  285,  280,  275,  288,  289,  284,  285,
  257,  257,  288,  289,  296,  297,  298,  299,  300,  301,
  296,  297,  298,  299,  300,  301,  269,  270,  257,   59,
  280,   59,  269,  270,  284,  285,   59,  280,  288,  289,
   59,  284,  285,  280,   59,  288,  289,  284,  285,  229,
  193,  288,  289,  296,  297,  298,  299,  300,  301,  296,
  297,  298,  299,  300,  301,  280,   34,  280,   93,  284,
  285,  284,  285,  288,  289,   23,  289,    6,   18,   59,
   88,  296,  297,  298,  299,  300,  301,  280,   23,   84,
   78,  284,  285,  280,  130,  288,  289,  284,  285,   -1,
   -1,  288,  289,  296,  297,  298,  299,  300,  301,  296,
  297,  298,  299,  300,  301,  280,   -1,   -1,   -1,  284,
  285,   -1,   -1,  288,  289,  269,  270,  271,  272,  273,
   -1,  296,  297,  298,  299,  300,  301,   -1,   -1,  269,
  270,  271,  272,  273,  288,  289,   -1,   -1,   -1,   -1,
   -1,   -1,  296,  297,  298,  299,  300,  301,  288,  289,
   -1,   -1,   -1,   -1,   -1,   -1,  296,  297,  298,  299,
  300,  301,  280,   -1,   -1,   -1,  284,  285,   -1,   -1,
  288,  289,   -1,   -1,   -1,   -1,  280,   -1,  296,  297,
  284,  285,   -1,   -1,  288,  289,   -1,   -1,   -1,   -1,
   -1,   -1,  296,  297,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,   81,   -1,  257,  258,
  259,   -1,   -1,  271,  263,   -1,  274,  269,  270,  271,
  272,  273,  271,   -1,   -1,  274,   -1,   -1,   -1,   -1,
  105,   -1,  290,  108,  269,  270,  271,  272,  273,   -1,
   -1,  290,   -1,   -1,  296,  297,  298,  299,  300,  301,
   -1,   99,  100,  288,  289,  103,  104,   -1,   -1,   -1,
   -1,  296,  297,  298,  299,  300,  301,  269,  270,  271,
  272,  273,   -1,  148,   -1,   -1,   -1,   -1,   -1,   -1,
  155,   -1,  284,  131,  132,   -1,  288,  289,   -1,   -1,
   -1,   -1,  140,  141,  296,  297,  298,  299,  300,  301,
   -1,  149,   -1,   -1,   -1,  153,   -1,   -1,   -1,  184,
  185,   -1,   -1,   -1,   -1,   -1,  164,   -1,  193,   -1,
   -1,   -1,  170,  171,  172,  173,  174,  175,  176,  177,
  178,  179,  180,  181,  182,  183,   -1,   -1,  186,   -1,
   -1,   -1,   -1,  218,  219,   -1,   -1,   -1,   -1,  197,
   -1,  269,  270,  271,  272,  273,  231,  269,  270,  271,
  272,  273,   -1,   -1,  239,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  284,  285,   -1,   -1,  288,  289,   -1,  227,
  298,  299,  300,  301,  296,  297,  298,  299,  300,  301,
  269,  270,  271,  272,  273,   -1,  269,  270,  271,  272,
  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  288,
  289,   -1,   -1,   -1,   -1,  288,   -1,  296,  297,  298,
  299,  300,  301,  296,  297,  298,  299,  300,  301,  257,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
  268,   -1,   -1,  271,   -1,   -1,   -1,   -1,  276,   -1,
  257,  279,   -1,  281,  282,  283,  284,   -1,  286,  287,
  267,  268,   -1,   -1,  271,   -1,   -1,   -1,   -1,  276,
   -1,  257,  279,   -1,   -1,   -1,  283,  284,  285,  286,
  287,  267,  268,   -1,   -1,  271,   -1,   -1,   -1,   -1,
  276,   -1,  257,  279,   -1,   -1,  282,  283,  284,   -1,
  286,  287,  267,  268,   -1,   -1,  271,   -1,   -1,   -1,
   -1,  276,   -1,  257,  279,   -1,   -1,   -1,  283,  284,
   -1,  286,  287,  267,  268,   -1,   -1,  271,   -1,   -1,
   -1,   -1,  276,   -1,   -1,  279,   -1,   -1,   -1,  283,
  284,   -1,  286,  287,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 301
#define YYUNDFTOKEN 357
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
0,"ID","NUM","STRING","INITIALIZE","ALLOC","FREE","NULL_","BEGIN_","END","MAIN",
"READ","WRITE","PLUS","MINUS","MUL","DIV","MOD","AMPERSAND","EQUAL",
"BREAKPOINT","TYPE","ENDTYPE","IF","THEN","ELSE","ENDIF","WHILE","DO",
"ENDWHILE","BREAK","CONTINUE","AND","OR","NOT","DECL","ENDDECL","INT","STR",
"RETURN","EQ","NEQ","LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
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
"Stmt : DynamicMemStmt",
"inputStmt : READ expr",
"outputStmt : WRITE expr",
"assignStmt : ID EQUAL expr",
"assignStmt : ID '[' expr ']' EQUAL expr",
"assignStmt : MUL ID EQUAL expr",
"assignStmt : StructField EQUAL expr",
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
"FuncType : ID",
"FBody : BEGIN_ Slist retStmt END ';'",
"LDeclBlock : DECL LDeclList ENDDECL",
"LDeclBlock :",
"LDeclBlock : DECL ENDDECL",
"LDeclList : LDeclList LDecl",
"LDeclList : LDecl",
"LDecl : LType LIDList ';'",
"LType : INT",
"LType : STR",
"LType : ID",
"LIDList : LIDList ',' LID",
"LIDList : LID",
"LID : ID",
"LID : MUL ID",
"MainBlock : MainFunc '(' ')' '{' LDeclBlock MBody '}'",
"MainFunc : INT MAIN",
"MBody : BEGIN_ Slist retStmt END ';'",
"DynamicMemStmt : AllocStmt",
"DynamicMemStmt : FreeStmt",
"DynamicMemStmt : InitializeStmt",
"AllocStmt : ID EQUAL ALLOC '(' ')'",
"FreeStmt : ID EQUAL FREE '(' expr ')'",
"InitializeStmt : ID EQUAL INITIALIZE '(' ')'",
"StructField : StructField '.' ID",
"StructField : ID '.' ID",
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
"expr : StructField",
"expr : ID '(' ArgList ')'",
"expr : ID '[' expr ']'",
"expr : AMPERSAND ID",
"expr : MUL ID",
"expr : ID",
"expr : NUM",
"expr : STRING",
"expr : NULL_",

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
#line 584 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at statement %d\n", s, statementCount);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yydebug = 1;
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
#line 657 "y.tab.c"

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
#line 62 "ast.y"
	{}
break;
case 2:
#line 63 "ast.y"
	{}
break;
case 3:
#line 64 "ast.y"
	{	
												printf("\n⛔ No Code Provided\n");
												exit(1);
											}
break;
case 4:
#line 73 "ast.y"
	{ printTypeTable(); }
break;
case 6:
#line 77 "ast.y"
	{}
break;
case 7:
#line 78 "ast.y"
	{}
break;
case 8:
#line 82 "ast.y"
	{ 
													if (typeFieldCount > 8){
														printf("\nError: User defined type %s has more than 8 fields\n", yystack.l_mark[-3].TTNode->typeName);
														exit(1);
													}

													FLPrint(yystack.l_mark[-3].TTNode); 
													yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-1].FLNode;
													yystack.l_mark[-3].TTNode->size = typeFieldCount;

													fieldListTail = NULL;
													fieldListHead = NULL;
													typeFieldCount = 0;
												}
break;
case 9:
#line 98 "ast.y"
	{ yyval.TTNode = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); }
break;
case 10:
#line 101 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[-1].FLNode;
												}
break;
case 11:
#line 107 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = 0;
													fieldListHead = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[0].FLNode;
				 								}
break;
case 12:
#line 115 "ast.y"
	{ 
													yyval.FLNode = FLCreateNode(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-2].TTNode); 
													++typeFieldCount;
												}
break;
case 13:
#line 121 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 14:
#line 122 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 15:
#line 123 "ast.y"
	{ yyval.TTNode = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 16:
#line 128 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 17:
#line 129 "ast.y"
	{}
break;
case 27:
#line 136 "ast.y"
	{ ++statementCount; }
break;
case 28:
#line 139 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 29:
#line 142 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 30:
#line 145 "ast.y"
	{ 
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
												yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
											}
break;
case 31:
#line 149 "ast.y"
	{	 
												yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
												yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
												yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 32:
#line 154 "ast.y"
	{
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);	
												struct ASTNode* mulNode;
												if (yystack.l_mark[-2].node->typeTablePtr == typeTableINTPtr)
													mulNode = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[-2].node, NULL);

												if (yystack.l_mark[-2].node->typeTablePtr == typeTableSTRPtr)
													mulNode = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[-2].node, NULL);
												yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, mulNode, NULL, yystack.l_mark[0].node);
											}
break;
case 33:
#line 164 "ast.y"
	{
												yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);
											}
break;
case 34:
#line 171 "ast.y"
	{}
break;
case 35:
#line 174 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 36:
#line 179 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 37:
#line 180 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 38:
#line 183 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 39:
#line 186 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 40:
#line 189 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 41:
#line 192 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 42:
#line 195 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 43:
#line 200 "ast.y"
	{
												GSTPrint(); 					
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 44:
#line 205 "ast.y"
	{}
break;
case 45:
#line 208 "ast.y"
	{}
break;
case 46:
#line 209 "ast.y"
	{}
break;
case 47:
#line 212 "ast.y"
	{}
break;
case 48:
#line 215 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 49:
#line 216 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 50:
#line 217 "ast.y"
	{ 
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {
													printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}
			 								}
break;
case 51:
#line 226 "ast.y"
	{}
break;
case 52:
#line 227 "ast.y"
	{}
break;
case 53:
#line 230 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, currentGDeclType->size, NULL); }
break;
case 54:
#line 231 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 55:
#line 238 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 56:
#line 244 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 57:
#line 251 "ast.y"
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
case 58:
#line 264 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 269 "ast.y"
	{}
break;
case 60:
#line 270 "ast.y"
	{}
break;
case 61:
#line 271 "ast.y"
	{}
break;
case 62:
#line 274 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 63:
#line 280 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 64:
#line 281 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 65:
#line 282 "ast.y"
	{  }
break;
case 66:
#line 283 "ast.y"
	{  }
break;
case 67:
#line 284 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 68:
#line 292 "ast.y"
	{ 
											yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node);
										}
break;
case 69:
#line 295 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 70:
#line 296 "ast.y"
	{}
break;
case 71:
#line 299 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node; 
											/* ++argCount;*/
										}
break;
case 72:
#line 308 "ast.y"
	{}
break;
case 73:
#line 309 "ast.y"
	{}
break;
case 74:
#line 312 "ast.y"
	{ 
															if(GSTLookup(yystack.l_mark[0].node->nodeName) == NULL){
																printf("\nFunction %s is not declared\n", yystack.l_mark[0].node->nodeName);
																exit(1);
															}
															yyval.node = yystack.l_mark[0].node; 
															setCurrentFuncName(yystack.l_mark[0].node->nodeName);
														}
break;
case 75:
#line 323 "ast.y"
	{
															char* currentFuncName = getCurrentFuncName();

															/* TODO: Pls check!!!*/
															/* addFunctionLST(currentFuncName, LSTHead);	*/
															
															fprintf(filePtr, "F%d:\n", GSTLookup(currentFuncName)->fLabel);
															initFuncCalle(filePtr, paramCount);

															printASTTable(yystack.l_mark[-1].node, 0);
															codeGen(yystack.l_mark[-1].node, filePtr);

															LSTPrint();
															flushLST();
															paramCount = 0;
														}
break;
case 76:
#line 341 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 77:
#line 347 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 78:
#line 348 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 79:
#line 349 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 80:
#line 350 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 81:
#line 351 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 82:
#line 354 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 84:
#line 364 "ast.y"
	{  
											/* printTupleList();*/
										}
break;
case 85:
#line 367 "ast.y"
	{}
break;
case 86:
#line 370 "ast.y"
	{}
break;
case 87:
#line 371 "ast.y"
	{}
break;
case 88:
#line 374 "ast.y"
	{}
break;
case 89:
#line 377 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 90:
#line 378 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 91:
#line 379 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 92:
#line 388 "ast.y"
	{}
break;
case 93:
#line 389 "ast.y"
	{}
break;
case 94:
#line 392 "ast.y"
	{ LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, currentLDeclType->size); }
break;
case 95:
#line 393 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 96:
#line 409 "ast.y"
	{
														char* currentFuncName = getCurrentFuncName();

														/* TODO: Check!!!*/
														/* addFunctionLST(currentFuncName, LSTHead);	*/

														fprintf(filePtr, "F0:\n");
														initFuncCalle(filePtr, paramCount);

														printASTTable(yystack.l_mark[-1].node, 0);
														codeGen(yystack.l_mark[-1].node, filePtr);
														LSTPrint();
														flushLST();
														paramCount = 0;
												
														/* printFLT();*/
													}
break;
case 97:
#line 428 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 98:
#line 431 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 102:
#line 446 "ast.y"
	{
													yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-2].node);
												}
break;
case 103:
#line 452 "ast.y"
	{
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);
													yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[-3].node);
												}
break;
case 104:
#line 459 "ast.y"
	{
													yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-2].node);
												}
break;
case 105:
#line 469 "ast.y"
	{
												struct ASTNode* traversalPtr = yystack.l_mark[-2].node;
												while (traversalPtr->right != NULL){
													traversalPtr = traversalPtr->right;
												}

												struct TypeTable* lastFieldType = traversalPtr->typeTablePtr;
												traversalPtr->nodeType = FIELD_NODE;

												if(lastFieldType == typeTableINTPtr || lastFieldType == typeTableSTRPtr){
													printf("\n. operator cannot be used for non User Defined variable\n");
													exit(1);
												}
												
												struct FieldList* fieldListEntry = FLLookUp(lastFieldType, yystack.l_mark[0].node->nodeName);

												/* if field is not present in the field list*/
												if(fieldListEntry == NULL){
													printf("\nUndeclared field \"%s\" used in variable %s\n", yystack.l_mark[0].node->nodeName, traversalPtr->nodeName);
													exit(1);
												}

												yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
												traversalPtr->right = yystack.l_mark[0].node;
												yyval.node = yystack.l_mark[-2].node;
												yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
											}
break;
case 106:
#line 496 "ast.y"
	{
												yystack.l_mark[-2].node->nodeType = FIELD_NODE;

												/* Checking if ID($1) exists in LST or GST*/
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);

												/* Check if ID($1) is user-defined*/
												if(yystack.l_mark[-2].node->typeTablePtr == typeTableINT || yystack.l_mark[-2].node->typeTablePtr == typeTableSTR){
													printf("\n. operator cannot be used for non User Defined variable\n");
													exit(1);
												}

												struct FieldList* fieldListEntry = FLLookUp(yystack.l_mark[-2].node->typeTablePtr, yystack.l_mark[0].node->nodeName);

												/* if field is not present in the field list*/
												if(fieldListEntry == NULL){
													printf("\nUndeclared field \"%s\" used in variable %s\n", yystack.l_mark[0].node->nodeName, yystack.l_mark[-2].node->nodeName);
													exit(1);
												}

												yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
												yystack.l_mark[-2].node->right = yystack.l_mark[0].node;
												yyval.node = yystack.l_mark[-2].node;
												yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
											}
break;
case 107:
#line 526 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 108:
#line 527 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 109:
#line 528 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 110:
#line 529 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 111:
#line 530 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 112:
#line 531 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 113:
#line 532 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 114:
#line 533 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 115:
#line 534 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 116:
#line 535 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 117:
#line 536 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 118:
#line 537 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 119:
#line 538 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 120:
#line 539 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 121:
#line 540 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 122:
#line 541 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 123:
#line 542 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL); 
										yyval.node->argListHead = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 124:
#line 549 "ast.y"
	{	
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
										if (yystack.l_mark[-1].node->typeTablePtr != typeTableINT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;	
										yyval.node = yystack.l_mark[-3].node;
									}
break;
case 125:
#line 558 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 126:
#line 566 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 127:
#line 574 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 128:
#line 578 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 129:
#line 579 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 130:
#line 580 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1568 "y.tab.c"
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
