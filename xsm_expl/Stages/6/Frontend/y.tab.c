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
	char* fileName;
	FILE* filePtr;
#line 32 "ast.y"
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
#line 62 "y.tab.c"

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
#define BEGIN_ 263
#define END 264
#define MAIN 265
#define READ 266
#define WRITE 267
#define PLUS 268
#define MINUS 269
#define MUL 270
#define DIV 271
#define MOD 272
#define AMPERSAND 273
#define EQUAL 274
#define BREAKPOINT 275
#define TYPE 276
#define ENDTYPE 277
#define IF 278
#define THEN 279
#define ELSE 280
#define ENDIF 281
#define WHILE 282
#define DO 283
#define ENDWHILE 284
#define BREAK 285
#define CONTINUE 286
#define AND 287
#define OR 288
#define NOT 289
#define DECL 290
#define ENDDECL 291
#define INT 292
#define STR 293
#define RETURN 294
#define EQ 295
#define NEQ 296
#define LT 297
#define LTE 298
#define GT 299
#define GTE 300
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
   17,   46,   46,   48,   48,   49,   50,   50,   50,   51,
   51,   52,   52,   33,   53,   16,   36,   36,   36,   23,
   24,   22,   21,   21,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,
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
    5,    3,    2,    2,    1,    3,    1,    1,    1,    3,
    1,    1,    2,    7,    2,    5,    1,    1,    1,    5,
    6,    5,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    3,    1,
    4,    4,    2,    2,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    9,    0,    0,    7,    0,    0,    0,
    4,    6,   50,   44,   48,   49,    0,    0,   46,    0,
    0,    0,    2,   73,    0,    0,    0,   15,   13,   14,
    0,   11,    0,    0,    0,    0,    0,   52,   43,   45,
   95,   79,   80,    1,   72,    0,   74,    0,    0,    0,
    8,   10,    0,    0,   58,    0,   47,    0,    0,    0,
    0,    0,   12,    0,   67,    0,    0,    0,   60,    0,
    0,   51,   89,   83,   87,   88,    0,   85,    0,    0,
    0,    0,    0,   54,   65,   66,    0,   55,   62,   57,
   82,   84,   92,    0,    0,   91,    0,    0,    0,    0,
   42,    0,    0,    0,   40,   41,    0,    0,   18,   19,
   20,   21,   22,   23,   24,   25,   26,    0,   99,   97,
   98,   27,   75,   76,    0,   59,   93,   86,    0,    0,
    0,    0,    0,  126,  127,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
    0,    0,    0,    0,   90,    0,    0,    0,    0,    0,
  104,    0,    0,  124,  123,  118,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   16,    0,    0,  103,
    0,   94,    0,    0,    0,    0,    0,    0,   69,    0,
  119,    0,    0,  107,  108,  109,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   35,   81,
    0,  102,  100,    0,    0,  122,    0,  121,    0,   37,
   38,   39,    0,  101,    0,   68,    0,   96,   36,
};
static const YYINT yydgoto[] = {                          2,
  107,  108,  109,  110,  111,  112,   48,  198,  113,  114,
  115,  116,  117,  149,  186,  154,   81,  199,  200,   36,
  141,  119,  120,  121,   31,    5,   17,   32,   33,    3,
    9,   22,   23,    6,    7,  122,   18,   19,   37,   38,
   68,   69,   70,   24,   25,   60,   26,   77,   78,   79,
   95,   96,   27,
};
static const YYINT yysindex[] = {                      -271,
 -235,    0, -262,    0,  -67, -244,    0, -238, -143, -256,
    0,    0,    0,    0,    0,    0, -133, -217,    0, -249,
 -182, -143,    0,    0,  -27, -167,   66,    0,    0,    0,
 -153,    0, -121,  -20, -134,  113,  -33,    0,    0,    0,
    0,    0,    0,    0,    0, -136,    0,  115,  121,  104,
    0,    0,  -93, -232,    0, -232,    0, -133, -214,  -97,
 -232,   44,    0,   75,    0,  -95,  -94,  -14,    0,  -84,
    5,    0,    0,    0,    0,    0, -210,    0, -124,  425,
   53,   24, -136,    0,    0,    0, -232,    0,    0,    0,
    0,    0,    0,  -78,  -21,    0,  -29,  130,  130,  -75,
    0,  130,  130,  425,    0,    0,  -76,  125,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -34,    0,    0,
    0,    0,    0,    0,  -70,    0,    0,    0, -124,  179,
  130,  -62,  -32,    0,    0,  -61,  -60,  130,  130,  312,
  154,  312,  -71,  269,  291,  439,  130,  142,  -56,    0,
  130,  -46,  425,   95,    0,  181,  182,  183,  312,  -83,
    0,  130,  130,    0,    0,    0,   97,  130,  130,  130,
  130,  130,  130,  130,  130,  130,  130,  130,  130,  130,
  130,  425,  425,  130,  312,  165,    0,  166,  312,    0,
  -76,    0,  198,  200,  130,  -24,  175,  312,    0,   64,
    0, -156, -156,    0,    0,    0, -169,  189,  324,  324,
 -111, -111, -111, -111,  312,  359,  381,  209,    0,    0,
  -13,    0,    0,  111,  130,    0,  130,    0,  425,    0,
    0,    0,  210,    0,  312,    0,  403,    0,    0,
};
static const YYINT yyrindex[] = {                       -19,
    0,    0,    0,    0,    0,    0,    0,    0,  276,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   23,
   27,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -15,    0,    7,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   81,    0,   81,    0,    0,    0,    0,
   81,    0,    0,    0,    0,   32,   33,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -41,    0,    0,    0,    0,    0,    0,  247,
  -35,  249,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  256,    0,
    0,    0,  101,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  258,    0,    0,    0,  259,    0,
    0,    0,    0,    0,    0,    0,    0,  107,    0,    0,
    0,   -2,    4,    0,    0,    0,   -9,   28,  133,  139,
   26,   48,   54,   76,  260,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  261,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -89, -105,    0,    0,    0,    0,    0,  352,    0,    0,
    0,    0,    0,  137,    0,    0,    0,  102,    0,    0,
  -73,    0,    0,    0,    0,    0,    0,  297,    0,    0,
    0,    0,  317,    0,  328,    0,    0,  322,    0,  298,
   78,  270,    0,  336,    0,  278,    0,    0,  285,    0,
    0,  241,    0,
};
#define YYTABLESIZE 725
static const YYINT yytable[] = {                        125,
   28,  148,  125,   51,    1,  120,  118,  163,  120,  196,
   58,  152,    4,  132,  146,   41,  132,  125,   13,   54,
   42,    4,  129,  120,   65,   57,   88,    8,   53,   87,
  118,  116,   11,  118,  116,   29,   30,  128,  105,   13,
  148,  105,   73,   53,  106,   90,   73,  106,   87,  116,
   56,  125,   14,   15,   16,   10,  105,  120,  162,   66,
   67,  131,  106,  191,  124,   56,  112,   87,  117,  112,
   53,  117,  118,   39,   15,   16,   74,   75,   76,  118,
   91,   75,   76,  116,  112,  148,  117,   43,  113,   47,
  105,  113,  216,  217,  114,   46,  106,  114,  168,  169,
  170,  171,  172,   50,  228,   49,  113,  227,  118,  118,
  148,  148,  114,  170,  171,  172,  115,  118,  112,  115,
  117,   61,   55,   34,   61,  175,  176,  177,  178,  179,
  180,  148,   93,   71,  115,   28,   35,  201,   82,  237,
  113,   70,  118,  118,   70,   94,  114,   71,   20,   21,
   71,  234,   56,   59,   61,  118,  168,  169,  170,  171,
  172,   62,   63,  118,   64,   80,   83,   84,  115,  139,
   29,   30,   89,  110,   85,   86,  110,  123,  127,  111,
   97,  143,  111,  150,  168,  169,  170,  171,  172,   98,
   99,  110,  153,  100,  161,  164,  165,  111,  101,  152,
  187,  102,  181,  173,  174,  103,  104,  188,  105,  106,
  190,  175,  176,  177,  178,  179,  180,  147,  139,  192,
  193,  194,  195,  219,  220,  110,  125,  125,  125,  125,
  125,  111,  120,  120,  120,  120,  120,  125,  222,  151,
  223,  125,  125,  120,  130,  125,  125,  120,  120,  225,
  233,  120,  120,  125,  125,  125,  125,  125,  125,  120,
  120,  120,  120,  120,  120,  105,  105,  226,  238,  116,
    5,  106,  106,  116,  116,    3,  105,  116,  116,   77,
  105,  105,  106,   78,  105,  105,  106,  106,   63,   64,
  106,  106,  105,  105,  105,  105,  105,  105,  106,  106,
  106,  106,  106,  106,  112,   28,  117,   29,  112,  112,
  117,  117,  112,  112,   30,  117,   34,   33,   32,   31,
  112,  112,  112,  112,  112,  112,  113,  221,  236,   52,
  113,  113,  114,   12,  113,  113,  114,  114,   44,   40,
  114,  114,  113,  113,  113,  113,  113,  113,  114,  114,
  114,  114,  114,  114,  115,   72,  126,   45,  115,  115,
  125,   92,  115,  115,  168,  169,  170,  171,  172,  155,
  115,  115,  115,  115,  115,  115,    0,    0,  168,  169,
  170,  171,  172,  173,  174,    0,  133,  134,  135,    0,
    0,  175,  176,  177,  178,  179,  180,  173,  174,  136,
    0,    0,  137,    0,    0,  175,  176,  177,  178,  179,
  180,  110,    0,    0,    0,  110,  110,  111,  138,  110,
  110,  111,  111,    0,    0,  111,  111,  110,  110,    0,
    0,    0,    0,  111,  111,  133,  134,  135,  156,  157,
  158,    0,  168,  169,  170,  171,  172,    0,  136,  140,
  142,  137,    0,  144,  145,    0,  168,  169,  170,  171,
  172,  173,  174,    0,    0,    0,    0,  138,    0,  175,
  176,  177,  178,  179,  180,  173,  168,  169,  170,  171,
  172,  159,  160,  175,  176,  177,  178,  179,  180,  166,
  167,  183,  232,    0,    0,  173,  174,    0,  185,    0,
    0,    0,  189,  175,  176,  177,  178,  179,  180,    0,
    0,    0,    0,  197,    0,    0,    0,    0,    0,  202,
  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,
  213,  214,  215,    0,    0,  218,  168,  169,  170,  171,
  172,    0,    0,    0,    0,    0,  224,  182,    0,    0,
    0,    0,    0,    0,    0,  173,  174,    0,  168,  169,
  170,  171,  172,  175,  176,  177,  178,  179,  180,    0,
    0,    0,    0,  183,    0,    0,  235,  173,  174,  168,
  169,  170,  171,  172,    0,  175,  176,  177,  178,  179,
  180,  168,  169,  170,  171,  172,    0,    0,  173,  174,
    0,    0,    0,    0,    0,    0,  175,  176,  177,  178,
  179,  180,    0,    0,    0,   97,    0,    0,    0,    0,
  177,  178,  179,  180,   98,   99,    0,    0,  100,    0,
    0,    0,    0,  101,    0,    0,  102,   97,  229,  230,
  103,  104,    0,  105,  106,    0,   98,   99,    0,    0,
  100,    0,    0,    0,    0,  101,    0,    0,  102,   97,
    0,    0,  103,  104,  231,  105,  106,    0,   98,   99,
    0,    0,  100,    0,    0,    0,    0,  101,    0,    0,
  102,   97,    0,  239,  103,  104,    0,  105,  106,    0,
   98,   99,    0,    0,  100,   97,    0,    0,    0,  101,
    0,    0,  102,    0,   98,   99,  103,  104,  100,  105,
  106,    0,    0,  101,    0,    0,  102,    0,    0,    0,
  184,  104,    0,  105,  106,
};
static const YYINT yycheck[] = {                         41,
  257,  107,   44,  125,  276,   41,   80,   40,   44,   93,
   44,   46,  257,   46,  104,  265,   46,   59,  257,   40,
  270,  257,   44,   59,  257,   59,   41,  290,   44,   44,
  104,   41,  277,  107,   44,  292,  293,   59,   41,  257,
  146,   44,  257,   59,   41,   41,  257,   44,   44,   59,
   44,   93,  291,  292,  293,  123,   59,   93,   91,  292,
  293,   91,   59,  153,   41,   59,   41,   44,   41,   44,
   91,   44,  146,  291,  292,  293,  291,  292,  293,  153,
  291,  292,  293,   93,   59,  191,   59,  270,   41,  257,
   93,   44,  182,  183,   41,  123,   93,   44,  268,  269,
  270,  271,  272,  257,   41,   40,   59,   44,  182,  183,
  216,  217,   59,  270,  271,  272,   41,  191,   93,   44,
   93,   41,  257,  257,   44,  295,  296,  297,  298,  299,
  300,  237,  257,   56,   59,  257,  270,   41,   61,  229,
   93,   41,  216,  217,   44,  270,   93,   41,  292,  293,
   44,   41,   40,  290,   40,  229,  268,  269,  270,  271,
  272,   41,   59,  237,  258,  263,  123,   93,   93,   40,
  292,  293,  257,   41,  270,  270,   44,  125,  257,   41,
  257,  257,   44,   59,  268,  269,  270,  271,  272,  266,
  267,   59,  263,  270,  257,  257,  257,   59,  275,   46,
   59,  278,  274,  287,  288,  282,  283,  264,  285,  286,
  257,  295,  296,  297,  298,  299,  300,  294,   40,  125,
   40,   40,   40,   59,   59,   93,  268,  269,  270,  271,
  272,   93,  268,  269,  270,  271,  272,  279,   41,  274,
   41,  283,  284,  279,  274,  287,  288,  283,  284,  274,
  264,  287,  288,  295,  296,  297,  298,  299,  300,  295,
  296,  297,  298,  299,  300,  268,  269,   93,   59,  279,
  290,  268,  269,  283,  284,    0,  279,  287,  288,  257,
  283,  284,  279,  257,  287,  288,  283,  284,  257,  257,
  287,  288,  295,  296,  297,  298,  299,  300,  295,  296,
  297,  298,  299,  300,  279,   59,  279,   59,  283,  284,
  283,  284,  287,  288,   59,  288,   59,   59,   59,   59,
  295,  296,  297,  298,  299,  300,  279,  191,  227,   33,
  283,  284,  279,    6,  287,  288,  283,  284,   22,   18,
  287,  288,  295,  296,  297,  298,  299,  300,  295,  296,
  297,  298,  299,  300,  279,   58,   87,   22,  283,  284,
   83,   77,  287,  288,  268,  269,  270,  271,  272,  129,
  295,  296,  297,  298,  299,  300,   -1,   -1,  268,  269,
  270,  271,  272,  287,  288,   -1,  257,  258,  259,   -1,
   -1,  295,  296,  297,  298,  299,  300,  287,  288,  270,
   -1,   -1,  273,   -1,   -1,  295,  296,  297,  298,  299,
  300,  279,   -1,   -1,   -1,  283,  284,  279,  289,  287,
  288,  283,  284,   -1,   -1,  287,  288,  295,  296,   -1,
   -1,   -1,   -1,  295,  296,  257,  258,  259,  260,  261,
  262,   -1,  268,  269,  270,  271,  272,   -1,  270,   98,
   99,  273,   -1,  102,  103,   -1,  268,  269,  270,  271,
  272,  287,  288,   -1,   -1,   -1,   -1,  289,   -1,  295,
  296,  297,  298,  299,  300,  287,  268,  269,  270,  271,
  272,  130,  131,  295,  296,  297,  298,  299,  300,  138,
  139,  283,  284,   -1,   -1,  287,  288,   -1,  147,   -1,
   -1,   -1,  151,  295,  296,  297,  298,  299,  300,   -1,
   -1,   -1,   -1,  162,   -1,   -1,   -1,   -1,   -1,  168,
  169,  170,  171,  172,  173,  174,  175,  176,  177,  178,
  179,  180,  181,   -1,   -1,  184,  268,  269,  270,  271,
  272,   -1,   -1,   -1,   -1,   -1,  195,  279,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  287,  288,   -1,  268,  269,
  270,  271,  272,  295,  296,  297,  298,  299,  300,   -1,
   -1,   -1,   -1,  283,   -1,   -1,  225,  287,  288,  268,
  269,  270,  271,  272,   -1,  295,  296,  297,  298,  299,
  300,  268,  269,  270,  271,  272,   -1,   -1,  287,  288,
   -1,   -1,   -1,   -1,   -1,   -1,  295,  296,  297,  298,
  299,  300,   -1,   -1,   -1,  257,   -1,   -1,   -1,   -1,
  297,  298,  299,  300,  266,  267,   -1,   -1,  270,   -1,
   -1,   -1,   -1,  275,   -1,   -1,  278,  257,  280,  281,
  282,  283,   -1,  285,  286,   -1,  266,  267,   -1,   -1,
  270,   -1,   -1,   -1,   -1,  275,   -1,   -1,  278,  257,
   -1,   -1,  282,  283,  284,  285,  286,   -1,  266,  267,
   -1,   -1,  270,   -1,   -1,   -1,   -1,  275,   -1,   -1,
  278,  257,   -1,  281,  282,  283,   -1,  285,  286,   -1,
  266,  267,   -1,   -1,  270,  257,   -1,   -1,   -1,  275,
   -1,   -1,  278,   -1,  266,  267,  282,  283,  270,  285,
  286,   -1,   -1,  275,   -1,   -1,  278,   -1,   -1,   -1,
  282,  283,   -1,  285,  286,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 300
#define YYUNDFTOKEN 356
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
0,"ID","NUM","STRING","INITIALIZE","ALLOC","FREE","BEGIN_","END","MAIN","READ",
"WRITE","PLUS","MINUS","MUL","DIV","MOD","AMPERSAND","EQUAL","BREAKPOINT",
"TYPE","ENDTYPE","IF","THEN","ELSE","ENDIF","WHILE","DO","ENDWHILE","BREAK",
"CONTINUE","AND","OR","NOT","DECL","ENDDECL","INT","STR","RETURN","EQ","NEQ",
"LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"FBody : BEGIN_ Slist retStmt END ';'",
"LDeclBlock : DECL LDeclList ENDDECL",
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
#line 634 "y.tab.c"

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
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 17:
#line 117 "ast.y"
	{}
break;
case 27:
#line 124 "ast.y"
	{ ++statementCount; }
break;
case 28:
#line 127 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 29:
#line 130 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 30:
#line 133 "ast.y"
	{ 
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
												yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
											}
break;
case 31:
#line 137 "ast.y"
	{	 
												yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
												yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
												yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 32:
#line 142 "ast.y"
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
#line 152 "ast.y"
	{
												yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);
											}
break;
case 34:
#line 159 "ast.y"
	{}
break;
case 35:
#line 162 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 36:
#line 167 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 37:
#line 168 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 38:
#line 171 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 39:
#line 174 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 40:
#line 177 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 41:
#line 180 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 42:
#line 183 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 43:
#line 188 "ast.y"
	{
												GSTPrint(); 					
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 44:
#line 193 "ast.y"
	{}
break;
case 45:
#line 196 "ast.y"
	{}
break;
case 46:
#line 197 "ast.y"
	{}
break;
case 47:
#line 200 "ast.y"
	{}
break;
case 48:
#line 203 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 49:
#line 204 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 50:
#line 205 "ast.y"
	{ 
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {
													printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}
			 								}
break;
case 51:
#line 214 "ast.y"
	{}
break;
case 52:
#line 215 "ast.y"
	{}
break;
case 53:
#line 218 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, currentGDeclType->size, NULL); }
break;
case 54:
#line 219 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 55:
#line 226 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 56:
#line 232 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 57:
#line 239 "ast.y"
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
#line 252 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 257 "ast.y"
	{}
break;
case 60:
#line 258 "ast.y"
	{}
break;
case 61:
#line 259 "ast.y"
	{}
break;
case 62:
#line 262 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 63:
#line 268 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 64:
#line 269 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 65:
#line 270 "ast.y"
	{  }
break;
case 66:
#line 271 "ast.y"
	{  }
break;
case 67:
#line 272 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 68:
#line 280 "ast.y"
	{ 
											yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node);
										}
break;
case 69:
#line 283 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 70:
#line 284 "ast.y"
	{}
break;
case 71:
#line 287 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node; 
											/* ++argCount;*/
										}
break;
case 72:
#line 296 "ast.y"
	{}
break;
case 73:
#line 297 "ast.y"
	{}
break;
case 74:
#line 300 "ast.y"
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
#line 311 "ast.y"
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
#line 329 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 77:
#line 335 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 78:
#line 336 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 79:
#line 337 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 80:
#line 338 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 81:
#line 341 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 82:
#line 350 "ast.y"
	{  
											/* printTupleList();*/
										}
break;
case 83:
#line 353 "ast.y"
	{}
break;
case 84:
#line 356 "ast.y"
	{}
break;
case 85:
#line 357 "ast.y"
	{}
break;
case 86:
#line 360 "ast.y"
	{}
break;
case 87:
#line 363 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 88:
#line 364 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 89:
#line 365 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 90:
#line 374 "ast.y"
	{}
break;
case 91:
#line 375 "ast.y"
	{}
break;
case 92:
#line 378 "ast.y"
	{ LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, currentLDeclType->size); }
break;
case 93:
#line 379 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 94:
#line 395 "ast.y"
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
case 95:
#line 414 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 96:
#line 417 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 100:
#line 432 "ast.y"
	{
													yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
													if(yystack.l_mark[-4].node->typeTablePtr != typeTableINT) {
														printf("\nAlloc() returns int, %s is not of data type int\n", yystack.l_mark[-4].node->nodeName);
														exit(1);
													}
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-2].node);
												}
break;
case 101:
#line 442 "ast.y"
	{
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);
													if(yystack.l_mark[-5].node->typeTablePtr != typeTableINT) {
														printf("\nFree() returns int, %s is not of data type int\n", yystack.l_mark[-5].node->nodeName);
														exit(1);
													}
													if(yystack.l_mark[-1].node->typeTablePtr != typeTableINT){
														printf("\nFree() expects argument of type int\n");
														exit(1);
													}
													yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[-3].node);
												}
break;
case 102:
#line 457 "ast.y"
	{
													yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);					
													if(yystack.l_mark[-4].node->typeTablePtr != typeTableINT) {
														printf("\nInitialize() returns int, %s is not of data type int\n", yystack.l_mark[-4].node->nodeName);
														exit(1);
													}
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-2].node);
												}
break;
case 103:
#line 471 "ast.y"
	{
												struct ASTNode* traversalPtr = yystack.l_mark[-2].node;
												while (traversalPtr->right != NULL){
													traversalPtr = traversalPtr->right;
												}

												struct TypeTable* lastFieldType = traversalPtr->typeTablePtr;

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
case 104:
#line 497 "ast.y"
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
case 105:
#line 527 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 106:
#line 528 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 107:
#line 529 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 108:
#line 530 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 109:
#line 531 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 110:
#line 532 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 111:
#line 533 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 112:
#line 534 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 113:
#line 535 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 114:
#line 536 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 115:
#line 537 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 116:
#line 538 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 117:
#line 539 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 118:
#line 540 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 119:
#line 541 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 120:
#line 542 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 121:
#line 543 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL); 
										yyval.node->argListHead = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 122:
#line 550 "ast.y"
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
case 123:
#line 559 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 124:
#line 567 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 125:
#line 575 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 126:
#line 579 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 127:
#line 580 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1541 "y.tab.c"
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
