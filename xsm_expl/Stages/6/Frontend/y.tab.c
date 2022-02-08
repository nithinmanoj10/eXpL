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
    0,    0,    0,   32,   32,   36,   36,   37,   28,   31,
   31,   30,   27,   27,   27,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    3,    4,    5,
    5,    5,    5,   15,   14,    6,    6,    9,   10,   11,
   12,   13,   33,   33,   39,   39,   40,   29,   29,   29,
   41,   41,   42,   42,   42,   42,   42,   20,   43,   43,
   43,   44,   45,   45,   45,   45,   45,   19,   19,   19,
   18,   34,   34,    7,   46,   47,   49,   49,   49,   49,
   49,   17,   48,   48,   48,   50,   50,   51,   52,   52,
   52,   53,   53,   54,   54,   54,   35,   55,   16,   38,
   38,   38,   23,   24,   22,   25,   25,   21,   21,   26,
   26,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,
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
    1,    3,    1,    1,    4,    2,    7,    2,    5,    1,
    1,    1,    4,    5,    4,    2,    5,    3,    3,    1,
    4,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    3,    1,    4,    4,    2,
    2,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    9,    0,    0,    7,    0,    0,    0,
    4,    6,   50,   44,   48,   49,    0,    0,   46,   81,
    0,    0,    0,    2,   73,    0,    0,    0,   15,   13,
   14,    0,   11,    0,    0,    0,    0,    0,   52,   43,
   45,   98,   79,   80,    1,   72,    0,   74,    0,    0,
    0,    8,   10,    0,    0,   58,    0,   47,    0,    0,
    0,    0,    0,   12,    0,   67,    0,    0,    0,   60,
    0,    0,   51,   91,   85,   89,   90,    0,   87,    0,
    0,    0,    0,    0,   54,   65,   66,    0,   55,   62,
   57,   83,   86,    0,    0,    0,   93,    0,    0,    0,
    0,   42,    0,    0,    0,   40,   41,    0,    0,   18,
   19,   20,   21,   22,   23,   24,   25,   26,    0,  102,
  100,  101,    0,    0,   27,   75,   76,    0,   59,    0,
   96,   88,    0,    0,    0,    0,  133,  134,  135,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   92,    0,    0,    0,    0,  131,  130,
  125,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   16,    0,    0,  108,    0,    0,    0,  109,    0,
   97,   95,    0,    0,    0,   69,    0,  126,    0,    0,
  114,  115,  116,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   35,   82,  105,  103,    0,
    0,    0,    0,    0,  128,    0,   37,   38,   39,  104,
    0,    0,   68,    0,   99,   36,
};
static const YYINT yydgoto[] = {                          2,
  108,  109,  110,  111,  112,  113,   49,  205,  114,  115,
  116,  117,  118,  153,  191,  162,   82,  206,  207,   37,
  145,  120,  121,  122,  123,  124,   32,    5,   17,   33,
   34,    3,    9,   23,   24,    6,    7,  125,   18,   19,
   38,   39,   69,   70,   71,   25,   26,   61,   27,   78,
   79,   80,   96,   97,   28,
};
static const YYINT yysindex[] = {                      -255,
 -223,    0, -253,    0,  -77, -237,    0, -225, -240, -234,
    0,    0,    0,    0,    0,    0, -236, -180,    0,    0,
 -222, -224, -240,    0,    0,  -67, -195,   30,    0,    0,
    0, -181,    0, -124,  -36, -163,   66,  -32,    0,    0,
    0,    0,    0,    0,    0,    0, -192,    0,   70,   78,
   68,    0,    0, -115, -220,    0, -220,    0, -236, -177,
  -96, -220,   43,    0,   79,    0, -100,  -90,   42,    0,
  -82,   54,    0,    0,    0,    0,    0, -156,    0, -207,
  473,   48,   63, -192,    0,    0,    0, -220,    0,    0,
    0,    0,    0,   91,  -74,  -29,    0,  -84,  193,  193,
  -59,    0,  193,  193,  473,    0,    0,  299,  141,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -33,    0,
    0,    0, -173,  144,    0,    0,    0,  -63,    0,  -53,
    0,    0, -207,  193,  193,  -26,    0,    0,    0,  -51,
  -39,  193,  193,  382,  173,  382,  -49,  340,  361,  494,
  193,  168,  -25,    0,  193,  -11,  212,  235,  239,   28,
  473,  165,  198,    0,  382,  -85,  193,  193,    0,    0,
    0,  120,  193,  193,  193,  193,  193,  193,  193,  193,
  193,  193,  193,  193,  193,  193,  473,  473,  193,  382,
  250,    0,  251,  382,    0,  271,  272,  193,    0,  299,
    0,    0,   39,  215,  382,    0,   82,    0, -113, -113,
    0,    0,    0,  -76,  396, -122, -122,  131,  131,  131,
  131,  382,  192,  431,  318,    0,    0,    0,    0,  126,
   53,  193,    0,  193,    0,  473,    0,    0,    0,    0,
  264,  382,    0,  452,    0,    0,
};
static const YYINT yyrindex[] = {                        33,
    0,    0,    0,    0,    0,    0,    0,    0,  342,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   83,   92,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -28,    0,  -19,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   89,    0,    0,    0,
    0,    0,    0,    0,   88,    0,   88,    0,    0,    0,
    0,   88,    0,    0,    0,    0,   94,   95,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   89,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -16,    0,    0,    0,  308,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -98,    0,  -41,    0,    0,    0,    0,
    0,    0,    0,  303,   -2,  304,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  305,    0,    0,   98,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  309,
    0,    0,    0,  314,    0,    0,    0,    0,    0,    0,
    0,    0,  328,    0,  112,    0,    0,    0,    4,   37,
    0,    0,    0,   -8,   61,  148,  158,   31,   59,   81,
   87,  335,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -52,  -35,    0,    0,    0,    0,    0,    0,    0,
    0,  346,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -95,  -89,    0,    0,    0,    0,    0,  366,    0,    0,
    0,    0,    0,  206,    0,    0,    0,  176,    0,    0,
  -79,    0,    0,    0,    0,    0,    0,    0,    0,  373,
    0,    0,    0,    0,  388,    0,  406,    0,    0,  395,
    0,  370,   22,  343,    0,  407,    0,  350,    0,    0,
  357,    0,    0,  306,    0,
};
#define YYTABLESIZE 781
static const YYINT yytable[] = {                        132,
   52,  119,  132,   55,  110,  129,  135,  203,  129,  150,
  111,   59,  156,  168,  133,   53,   20,  132,  152,    4,
   35,    1,   29,  129,   56,  119,   58,   94,  119,  132,
   53,   13,  123,    4,   36,  123,   66,    8,  127,   56,
   11,  127,   94,   42,  112,   10,   44,  112,   43,   94,
  123,  132,   21,   22,   54,   47,  127,  129,   30,   31,
  152,   48,  112,   95,  167,  200,   14,   15,   16,   50,
  119,  119,   67,   68,  119,   51,   13,  113,   72,   74,
  113,  119,   89,   83,  123,   88,  157,  158,  159,  119,
  127,  223,  224,   56,   91,  113,  112,   88,   60,  120,
   74,  124,  120,  127,  124,   57,   88,  119,  119,   62,
  152,   40,   15,   16,   75,   76,   77,  120,   63,  124,
  119,  121,  235,  119,  121,  234,   64,  122,   61,  113,
  122,   61,   29,  152,  152,   92,   76,   77,   70,  121,
  244,   70,   65,  119,  119,  122,  173,  174,  175,  176,
  177,  120,   71,  124,  152,   71,  119,  175,  176,  177,
  208,  106,  106,  106,  119,   84,  240,   81,   30,   31,
   86,   85,  126,  121,   90,  182,  183,  184,  185,  122,
   87,  130,  131,  173,  174,  175,  176,  177,  117,  160,
  134,  117,  173,  174,  175,  176,  177,  147,  118,  154,
  161,  118,  178,  179,  163,  169,  117,  107,  107,  107,
  180,  181,  182,  183,  184,  185,  118,  170,  156,  180,
  181,  182,  183,  184,  185,  186,  192,  132,  132,  132,
  132,  132,  143,  129,  129,  129,  129,  129,  132,  193,
  117,  155,  132,  132,  129,  195,  132,  132,  129,  129,
  118,  196,  129,  129,  132,  132,  132,  132,  132,  132,
  129,  129,  129,  129,  129,  129,  127,  127,  127,  127,
  127,  123,  112,  112,  197,  123,  123,  127,  198,  123,
  123,  127,  127,  112,  199,  127,  127,  112,  112,  201,
  202,  112,  112,  127,  127,  127,  127,  127,  127,  112,
  112,  112,  112,  112,  112,  113,  113,  233,  226,  227,
  119,  228,  229,  232,  119,  119,  113,  241,  119,  119,
  113,  113,  245,    5,  113,  113,  119,  119,  119,  119,
  119,  119,  113,  113,  113,  113,  113,  113,  120,   77,
  124,    3,  120,  120,  124,  124,  120,  120,   78,  124,
   63,   64,   84,  110,  120,  120,  120,  120,  120,  120,
  121,   28,   29,   30,  121,  121,  122,   34,  121,  121,
  122,  122,   33,  111,  122,  122,  121,  121,  121,  121,
  121,  121,  122,  122,  122,  122,  122,  122,  173,  174,
  175,  176,  177,   32,  173,  174,  175,  176,  177,  173,
  174,  175,  176,  177,   31,  231,   53,  178,  179,  243,
   45,   12,   41,  178,  179,  180,  181,  182,  183,  184,
  185,  180,  181,  182,  183,  184,  185,  117,   73,   46,
  129,  117,  117,  128,   93,  117,  117,  118,  164,    0,
    0,  118,  118,  117,  117,  118,  118,    0,   98,  136,
  137,  138,    0,  118,  118,  139,    0,    0,   99,  100,
    0,    0,  101,  140,  144,  146,  141,  102,  148,  149,
  103,    0,  236,  237,  104,  105,    0,  106,  107,    0,
    0,    0,  142,  173,  174,  175,  176,  177,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  165,
  166,    0,  178,  179,    0,    0,    0,  171,  172,    0,
  180,  181,  182,  183,  184,  185,  190,    0,    0,    0,
  194,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  204,    0,    0,    0,    0,    0,  209,  210,
  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,
  221,  222,    0,    0,  225,   98,    0,    0,    0,    0,
    0,    0,    0,  230,    0,   99,  100,    0,    0,  101,
    0,    0,    0,    0,  102,    0,    0,  103,    0,    0,
    0,  104,  105,    0,  106,  107,  173,  174,  175,  176,
  177,    0,    0,  151,    0,    0,    0,  242,    0,    0,
    0,  188,  239,    0,    0,  178,  179,    0,  173,  174,
  175,  176,  177,  180,  181,  182,  183,  184,  185,  187,
    0,    0,    0,    0,    0,    0,    0,  178,  179,  173,
  174,  175,  176,  177,    0,  180,  181,  182,  183,  184,
  185,    0,    0,    0,  188,    0,    0,    0,  178,  179,
  173,  174,  175,  176,  177,    0,  180,  181,  182,  183,
  184,  185,    0,    0,  173,  174,  175,  176,  177,  178,
  179,    0,    0,    0,    0,    0,    0,  180,  181,  182,
  183,  184,  185,  178,    0,    0,    0,   98,    0,    0,
    0,  180,  181,  182,  183,  184,  185,   99,  100,    0,
    0,  101,    0,    0,    0,    0,  102,    0,   98,  103,
    0,    0,    0,  104,  105,  238,  106,  107,   99,  100,
    0,    0,  101,    0,    0,    0,    0,  102,    0,   98,
  103,    0,    0,  246,  104,  105,    0,  106,  107,   99,
  100,    0,    0,  101,    0,    0,    0,    0,  102,    0,
   98,  103,    0,    0,    0,  104,  105,    0,  106,  107,
   99,  100,    0,    0,  101,    0,    0,    0,    0,  102,
    0,    0,  103,    0,    0,    0,  189,  105,    0,  106,
  107,
};
static const YYINT yycheck[] = {                         41,
  125,   81,   44,   40,   46,   41,   91,   93,   44,  105,
   46,   44,   46,   40,   44,   44,  257,   59,  108,  257,
  257,  277,  257,   59,   44,  105,   59,   44,  108,   59,
   59,  257,   41,  257,  271,   44,  257,  291,   41,   59,
  278,   44,   59,  266,   41,  123,  271,   44,  271,  257,
   59,   93,  293,  294,   91,  123,   59,   93,  293,  294,
  150,  257,   59,  271,   91,  161,  292,  293,  294,   40,
  150,   41,  293,  294,   44,  257,  257,   41,   57,  257,
   44,  161,   41,   62,   93,   44,  260,  261,  262,   59,
   93,  187,  188,  257,   41,   59,   93,   44,  291,   41,
  257,   41,   44,   41,   44,   40,   44,  187,  188,   40,
  200,  292,  293,  294,  292,  293,  294,   59,   41,   59,
  200,   41,   41,   93,   44,   44,   59,   41,   41,   93,
   44,   44,  257,  223,  224,  292,  293,  294,   41,   59,
  236,   44,  258,  223,  224,   59,  269,  270,  271,  272,
  273,   93,   41,   93,  244,   44,  236,  271,  272,  273,
   41,  260,  261,  262,  244,  123,   41,  264,  293,  294,
  271,   93,  125,   93,  257,  298,  299,  300,  301,   93,
  271,   91,  257,  269,  270,  271,  272,  273,   41,   46,
  275,   44,  269,  270,  271,  272,  273,  257,   41,   59,
  264,   44,  288,  289,  258,  257,   59,  260,  261,  262,
  296,  297,  298,  299,  300,  301,   59,  257,   46,  296,
  297,  298,  299,  300,  301,  275,   59,  269,  270,  271,
  272,  273,   40,  269,  270,  271,  272,  273,  280,  265,
   93,  275,  284,  285,  280,  257,  288,  289,  284,  285,
   93,   40,  288,  289,  296,  297,  298,  299,  300,  301,
  296,  297,  298,  299,  300,  301,  269,  270,  271,  272,
  273,  280,  269,  270,   40,  284,  285,  280,   40,  288,
  289,  284,  285,  280,  257,  288,  289,  284,  285,  125,
   93,  288,  289,  296,  297,  298,  299,  300,  301,  296,
  297,  298,  299,  300,  301,  269,  270,   93,   59,   59,
  280,   41,   41,  275,  284,  285,  280,  265,  288,  289,
  284,  285,   59,  291,  288,  289,  296,  297,  298,  299,
  300,  301,  296,  297,  298,  299,  300,  301,  280,  257,
  280,    0,  284,  285,  284,  285,  288,  289,  257,  289,
  257,  257,  264,   46,  296,  297,  298,  299,  300,  301,
  280,   59,   59,   59,  284,  285,  280,   59,  288,  289,
  284,  285,   59,   46,  288,  289,  296,  297,  298,  299,
  300,  301,  296,  297,  298,  299,  300,  301,  269,  270,
  271,  272,  273,   59,  269,  270,  271,  272,  273,  269,
  270,  271,  272,  273,   59,  200,   34,  288,  289,  234,
   23,    6,   18,  288,  289,  296,  297,  298,  299,  300,
  301,  296,  297,  298,  299,  300,  301,  280,   59,   23,
   88,  284,  285,   84,   78,  288,  289,  280,  133,   -1,
   -1,  284,  285,  296,  297,  288,  289,   -1,  257,  257,
  258,  259,   -1,  296,  297,  263,   -1,   -1,  267,  268,
   -1,   -1,  271,  271,   99,  100,  274,  276,  103,  104,
  279,   -1,  281,  282,  283,  284,   -1,  286,  287,   -1,
   -1,   -1,  290,  269,  270,  271,  272,  273,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  134,
  135,   -1,  288,  289,   -1,   -1,   -1,  142,  143,   -1,
  296,  297,  298,  299,  300,  301,  151,   -1,   -1,   -1,
  155,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  167,   -1,   -1,   -1,   -1,   -1,  173,  174,
  175,  176,  177,  178,  179,  180,  181,  182,  183,  184,
  185,  186,   -1,   -1,  189,  257,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  198,   -1,  267,  268,   -1,   -1,  271,
   -1,   -1,   -1,   -1,  276,   -1,   -1,  279,   -1,   -1,
   -1,  283,  284,   -1,  286,  287,  269,  270,  271,  272,
  273,   -1,   -1,  295,   -1,   -1,   -1,  232,   -1,   -1,
   -1,  284,  285,   -1,   -1,  288,  289,   -1,  269,  270,
  271,  272,  273,  296,  297,  298,  299,  300,  301,  280,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  288,  289,  269,
  270,  271,  272,  273,   -1,  296,  297,  298,  299,  300,
  301,   -1,   -1,   -1,  284,   -1,   -1,   -1,  288,  289,
  269,  270,  271,  272,  273,   -1,  296,  297,  298,  299,
  300,  301,   -1,   -1,  269,  270,  271,  272,  273,  288,
  289,   -1,   -1,   -1,   -1,   -1,   -1,  296,  297,  298,
  299,  300,  301,  288,   -1,   -1,   -1,  257,   -1,   -1,
   -1,  296,  297,  298,  299,  300,  301,  267,  268,   -1,
   -1,  271,   -1,   -1,   -1,   -1,  276,   -1,  257,  279,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  267,  268,
   -1,   -1,  271,   -1,   -1,   -1,   -1,  276,   -1,  257,
  279,   -1,   -1,  282,  283,  284,   -1,  286,  287,  267,
  268,   -1,   -1,  271,   -1,   -1,   -1,   -1,  276,   -1,
  257,  279,   -1,   -1,   -1,  283,  284,   -1,  286,  287,
  267,  268,   -1,   -1,  271,   -1,   -1,   -1,   -1,  276,
   -1,   -1,  279,   -1,   -1,   -1,  283,  284,   -1,  286,
  287,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 301
#define YYUNDFTOKEN 359
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
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
"LID : ID '[' NUM ']'",
"LID : MUL ID",
"MainBlock : MainFunc '(' ')' '{' LDeclBlock MBody '}'",
"MainFunc : INT MAIN",
"MBody : BEGIN_ Slist retStmt END ';'",
"DynamicMemStmt : AllocStmt",
"DynamicMemStmt : FreeStmt",
"DynamicMemStmt : InitializeStmt",
"AllocStmt : DynaMemID ALLOC '(' ')'",
"FreeStmt : DynaMemID FREE '(' expr ')'",
"InitializeStmt : DynaMemID INITIALIZE '(' ')'",
"DynaMemID : ID EQUAL",
"DynaMemID : ID '[' expr ']' EQUAL",
"StructField : StructField '.' ID",
"StructField : StructID '.' ID",
"StructID : ID",
"StructID : ID '[' expr ']'",
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
#line 604 "ast.y"

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
#line 662 "y.tab.c"

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
	{ GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, 1, NULL); }
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
	{ LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, 1); }
break;
case 95:
#line 393 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 96:
#line 400 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 97:
#line 416 "ast.y"
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
case 98:
#line 435 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 99:
#line 438 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 103:
#line 453 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 104:
#line 459 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 105:
#line 466 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 106:
#line 472 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 107:
#line 473 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 108:
#line 483 "ast.y"
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
case 109:
#line 510 "ast.y"
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
case 110:
#line 537 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 111:
#line 538 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 112:
#line 546 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 113:
#line 547 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 114:
#line 548 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 115:
#line 549 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 116:
#line 550 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 117:
#line 551 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 118:
#line 552 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 119:
#line 553 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 120:
#line 554 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 121:
#line 555 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 122:
#line 556 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 123:
#line 557 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 124:
#line 558 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 125:
#line 559 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 126:
#line 560 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 127:
#line 561 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 128:
#line 562 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL); 
										yyval.node->argListHead = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 129:
#line 569 "ast.y"
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
case 130:
#line 578 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 131:
#line 586 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 132:
#line 594 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 133:
#line 598 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 134:
#line 599 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 135:
#line 600 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1605 "y.tab.c"
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
