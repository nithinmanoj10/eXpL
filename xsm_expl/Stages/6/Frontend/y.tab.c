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
	#include "../Functions/xsm_library.h"
	#include "../Functions/xsm_syscalls.h"
	#include "../Functions/stackMemory.h"
	#include "../Functions/stringMan.h"
	#include "../Functions/label.h"

	int yylex(void);
	void yyerror(char const *s);
	int statementCount = 0;
	int typeFieldCount = 0;
	int tupleFieldCount = 0;
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
#define BREAKPOINT 275
#define TYPE 276
#define ENDTYPE 277
#define TUPLE 278
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
    0,    0,    0,   38,   38,   42,   42,   43,   29,   34,
   34,   33,   28,   28,   28,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    3,    4,    5,
    5,    5,    5,   15,   14,    6,    6,    9,   10,   11,
   12,   13,   39,   39,   45,   45,   46,   46,   30,   30,
   30,   30,   47,   47,   48,   48,   48,   48,   48,   20,
   37,   36,   36,   35,   32,   32,   27,   49,   49,   49,
   50,   51,   51,   51,   51,   51,   19,   19,   19,   18,
   40,   40,    7,   52,   53,   55,   55,   55,   55,   55,
   17,   54,   54,   54,   56,   56,   57,   57,   31,   31,
   31,   31,   58,   58,   59,   59,   59,   41,   60,   16,
   44,   44,   44,   23,   24,   22,   25,   25,   21,   21,
   26,   26,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,
};
static const YYINT yylen[] = {                            2,
    4,    3,    2,    3,    0,    2,    1,    4,    1,    2,
    1,    3,    1,    1,    1,    3,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    2,    2,    3,
    6,    4,    3,    1,    3,    7,    5,    5,    5,    1,
    1,    1,    3,    2,    2,    1,    3,    4,    1,    1,
    1,    2,    3,    1,    1,    4,    4,    1,    4,    2,
    3,    3,    1,    2,    1,    1,    1,    3,    1,    0,
    2,    1,    1,    2,    2,    1,    3,    1,    0,    1,
    2,    1,    1,    5,    5,    1,    1,    2,    2,    1,
    5,    3,    0,    2,    2,    1,    3,    4,    1,    1,
    1,    2,    3,    1,    1,    4,    2,    7,    2,    5,
    1,    1,    1,    4,    5,    4,    2,    5,    3,    3,
    1,    4,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    3,    1,    4,    4,
    2,    2,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    9,    0,    0,    7,    0,    0,    0,
    4,    6,   51,    0,   44,   49,   50,    0,    0,   46,
   90,    0,    0,    0,    2,   82,    0,    0,    0,   15,
   13,   14,    0,   11,    0,   52,    0,    0,    0,    0,
    0,    0,   54,   43,   45,  109,   88,   89,    1,   81,
    0,   83,    0,    0,    0,    8,   10,    0,    0,   60,
   65,   66,    0,   63,    0,    0,    0,    0,   47,    0,
    0,    0,    0,   12,    0,   76,    0,    0,    0,   69,
    0,   67,   64,    0,   61,    0,   48,   53,  101,    0,
   94,   99,  100,    0,    0,   96,    0,    0,    0,    0,
   56,   74,   75,    0,   57,   71,   62,   59,  102,    0,
    0,    0,    0,  104,   92,   95,    0,    0,    0,    0,
   42,    0,    0,    0,   40,   41,    0,    0,   18,   19,
   20,   21,   22,   23,   24,   25,   26,    0,  113,  111,
  112,    0,    0,   27,   84,   85,    0,   68,    0,  107,
    0,    0,   97,    0,    0,    0,  144,  145,  146,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   98,  103,    0,    0,    0,    0,  142,
  141,  136,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   16,    0,    0,  119,    0,    0,    0,  120,
    0,  108,  106,    0,    0,    0,   78,    0,  137,    0,
    0,  125,  126,  127,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   35,   91,  116,  114,
    0,    0,    0,    0,    0,  139,    0,   37,   38,   39,
  115,    0,    0,   77,    0,  110,   36,
};
static const YYINT yydgoto[] = {                          2,
  127,  128,  129,  130,  131,  132,   53,  226,  133,  134,
  135,  136,  137,  173,  212,  182,   98,  227,  228,   40,
  165,  139,  140,  141,  142,  143,   83,   33,    5,   18,
   94,   63,   34,   35,   64,   65,   41,    3,    9,   24,
   25,    6,    7,  144,   19,   20,   42,   43,   79,   80,
   81,   26,   27,   71,   28,   95,   96,  113,  114,   29,
};
static const YYINT yysindex[] = {                      -251,
 -208,    0, -241,    0,  -56, -247,    0, -238, -250, -228,
    0,    0,    0, -188,    0,    0,    0,   52, -210,    0,
    0, -167, -192, -250,    0,    0,  -36, -151,   67,    0,
    0,    0, -142,    0, -124,    0,  -38, -140, -262,   98,
 -243,  -32,    0,    0,    0,    0,    0,    0,    0,    0,
 -170,    0,  124,   86,   99,    0,    0,  -93, -223,    0,
    0,    0,  -82,    0,   75, -223,  -24, -243,    0, -184,
  -96, -223,   68,    0,   97,    0,  -73,  -71,   82,    0,
  -39,    0,    0, -262,    0,   88,    0,    0,    0,  -31,
    0,    0,    0,   53, -180,    0,  471,   76,   95, -170,
    0,    0,    0, -223,    0,    0,    0,    0,    0,  114,
  -30, -195,  -22,    0,    0,    0,  -45,  193,  193,  -17,
    0,  193,  193,  471,    0,    0,  223,  147,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -23,    0,    0,
    0,  -89,  173,    0,    0,    0,  -12,    0,  -16,    0,
  -18, -195,    0,  193,  193,  -27,    0,    0,    0,  -11,
   18,  193,  193,  359,  233,  359,  224,  316,  337,  492,
  193,  231,   26,    0,  193,   55,  273,  274,  278,   83,
  471,  217,  256,    0,    0,  359,  -85,  193,  193,    0,
    0,    0,  120,  193,  193,  193,  193,  193,  193,  193,
  193,  193,  193,  193,  193,  193,  193,  471,  471,  193,
  359,  295,    0,  303,  359,    0,  322,  323,  193,    0,
  223,    0,    0,  307,  215,  359,    0,  112,    0,  -90,
  -90,    0,    0,    0,  -76,  373, -122, -122, -128, -128,
 -128, -128,  359,  408,  429,  254,    0,    0,    0,    0,
  126,  108,  193,    0,  193,    0,  471,    0,    0,    0,
    0,  315,  359,    0,  450,    0,    0,
};
static const YYINT yyrindex[] = {                       103,
    0,    0,    0,    0,    0,    0,    0,    0,  400,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  144,  145,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   15,    0,    0,   36,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  139,    0,    0,    0,    0,    0,    0,    0,  116,    0,
    0,    0,    0,    0,    0,  116,    0,    0,    0,    0,
    0,  116,    0,    0,    0,    0,  149,  150,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  139,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   42,
    0,    0,    0,    0,    0,    0,  358,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -52,    0,  -41,    0,    0,    0,    0,
    0,    0,    0,  346,   -2,  351,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  352,    0,    0,  118,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  353,    0,    0,    0,  354,    0,    0,    0,    0,    0,
    0,    0,    0,  383,    0,  122,    0,    0,    0,    4,
   37,    0,    0,    0,   -8,   61,  148,  158,   31,   59,
   81,   87,  371,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   91,  -35,    0,    0,    0,    0,    0,    0,
    0,    0,  372,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
 -120, -110,    0,    0,    0,    0,    0,  374,    0,    0,
    0,    0,    0,  213,    0,    0,    0,  184,    0,    0,
  338,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  405,    0,  357,    0,  355,    0,    0,    0,
  424,    0,  447,    0,    0,  438,  417,  391,  -51,  356,
    0,  437,    0,  363,    0,    0,  375,  360,  314,    0,
};
#define YYTABLESIZE 779
static const YYINT yytable[] = {                        143,
   56,   59,  143,  170,  121,  140,   21,  224,  140,    4,
  122,   68,  189,   37,   86,  154,  172,  143,   13,   68,
   99,  152,  176,  140,    1,  152,   69,   38,   30,   11,
   61,   62,  134,   76,   87,  134,  153,  175,  138,   14,
  184,  138,   22,   23,  123,  155,   13,  123,    4,    8,
  134,  143,   58,   15,   16,   17,  138,  140,   55,  172,
  221,  110,  123,  188,   31,   32,   10,   14,   36,   77,
   78,  130,   89,   55,  130,  111,   89,  124,   48,   58,
  124,   44,   16,   17,  134,  105,   51,  244,  245,  130,
  138,   39,   39,   90,   58,  124,  123,   90,   46,  131,
  105,  135,  131,   47,  135,   52,   54,   91,   92,   93,
  172,  115,   92,   93,   55,   85,   60,  131,   84,  135,
   70,  132,  105,  130,  132,  104,   73,  133,  108,  124,
  133,  104,   30,  172,  172,  146,  265,   66,  104,  132,
  194,  195,  196,  197,  198,  133,  194,  195,  196,  197,
  198,  131,  256,  135,  172,  255,   70,   74,   79,   70,
  229,   79,   80,   72,   75,   80,  261,   97,   31,   32,
  177,  178,  179,  132,   82,  203,  204,  205,  206,  133,
  196,  197,  198,  194,  195,  196,  197,  198,  128,  101,
  100,  128,  194,  195,  196,  197,  198,  102,  129,  103,
  145,  129,  199,  200,  149,  174,  128,  117,  117,  117,
  201,  202,  203,  204,  205,  206,  129,  106,  180,  201,
  202,  203,  204,  205,  206,  109,  150,  143,  143,  143,
  143,  143,  163,  140,  140,  140,  140,  140,  143,  167,
  128,  183,  143,  143,  140,  190,  143,  143,  140,  140,
  129,  181,  140,  140,  143,  143,  143,  143,  143,  143,
  140,  140,  140,  140,  140,  140,  138,  138,  138,  138,
  138,  134,  123,  123,  191,  134,  134,  138,  176,  134,
  134,  138,  138,  123,  207,  138,  138,  123,  123,  213,
  214,  123,  123,  138,  138,  138,  138,  138,  138,  123,
  123,  123,  123,  123,  123,  124,  124,  254,   37,  110,
  130,  216,  217,  218,  130,  130,  124,  219,  130,  130,
  124,  124,   38,  111,  124,  124,  130,  130,  130,  130,
  130,  130,  124,  124,  124,  124,  124,  124,  131,  220,
  135,  222,  131,  131,  135,  135,  131,  131,  223,  135,
  118,  118,  118,  247,  131,  131,  131,  131,  131,  131,
  132,  248,  249,  250,  132,  132,  133,  253,  132,  132,
  133,  133,  262,  266,  133,  133,  132,  132,  132,  132,
  132,  132,  133,  133,  133,  133,  133,  133,  194,  195,
  196,  197,  198,    5,  194,  195,  196,  197,  198,    3,
   86,   87,   93,  121,   28,   72,   73,  199,  200,   29,
   30,   34,   33,  199,  200,  201,  202,  203,  204,  205,
  206,  201,  202,  203,  204,  205,  206,  128,  122,   32,
   31,  128,  128,  252,  138,  128,  128,  129,  264,   57,
  107,  129,  129,  128,  128,  129,  129,   49,  112,  156,
  157,  158,   12,  129,  129,  159,   45,   67,   88,  148,
   50,  138,  147,  160,  138,  185,  161,    0,    0,  116,
    0,  151,    0,    0,    0,    0,    0,    0,    0,  117,
    0,    0,  162,  194,  195,  196,  197,  198,    0,  118,
  119,  164,  166,  120,    0,  168,  169,  121,    0,    0,
    0,  122,  199,  200,    0,  123,  124,  138,  125,  126,
  201,  202,  203,  204,  205,  206,    0,  171,  138,    0,
    0,    0,  194,  195,  196,  197,  198,  186,  187,    0,
    0,    0,    0,    0,    0,  192,  193,  209,  260,    0,
    0,  199,  200,    0,  211,  138,  138,    0,  215,  201,
  202,  203,  204,  205,  206,    0,    0,    0,  138,    0,
    0,  225,    0,    0,    0,    0,    0,  230,  231,  232,
  233,  234,  235,  236,  237,  238,  239,  240,  241,  242,
  243,  138,  138,  246,  194,  195,  196,  197,  198,    0,
    0,    0,  251,    0,  138,  208,    0,    0,    0,    0,
    0,    0,  138,  199,  200,  194,  195,  196,  197,  198,
    0,  201,  202,  203,  204,  205,  206,    0,    0,    0,
  209,    0,    0,    0,  199,  200,  263,  194,  195,  196,
  197,  198,  201,  202,  203,  204,  205,  206,    0,    0,
    0,  194,  195,  196,  197,  198,  199,  200,    0,    0,
    0,    0,    0,    0,  201,  202,  203,  204,  205,  206,
  199,    0,    0,    0,  117,    0,    0,    0,  201,  202,
  203,  204,  205,  206,  118,  119,    0,    0,  120,    0,
    0,    0,  121,    0,    0,  117,  122,    0,  257,  258,
  123,  124,    0,  125,  126,  118,  119,    0,    0,  120,
    0,    0,    0,  121,    0,    0,  117,  122,    0,    0,
    0,  123,  124,  259,  125,  126,  118,  119,    0,    0,
  120,    0,    0,    0,  121,    0,    0,  117,  122,    0,
    0,  267,  123,  124,    0,  125,  126,  118,  119,    0,
    0,  120,    0,    0,    0,  121,    0,    0,  117,  122,
    0,    0,    0,  123,  124,    0,  125,  126,  118,  119,
    0,    0,  120,    0,    0,    0,  121,    0,    0,    0,
  122,    0,    0,    0,  210,  124,    0,  125,  126,
};
static const YYINT yycheck[] = {                         41,
  125,   40,   44,  124,   46,   41,  257,   93,   44,  257,
   46,   44,   40,  257,   66,   61,  127,   59,  257,   44,
   72,   44,   46,   59,  276,   44,   59,  271,  257,  277,
  293,  294,   41,  257,   59,   44,   59,   61,   41,  278,
   59,   44,  293,  294,   41,   91,  257,   44,  257,  291,
   59,   93,   91,  292,  293,  294,   59,   93,   44,  170,
  181,  257,   59,   91,  293,  294,  123,  278,  257,  293,
  294,   41,  257,   59,   44,  271,  257,   41,  271,   44,
   44,  292,  293,  294,   93,   44,  123,  208,  209,   59,
   93,   40,   40,  278,   59,   59,   93,  278,  266,   41,
   59,   41,   44,  271,   44,  257,   40,  292,  293,  294,
  221,  292,  293,  294,  257,   41,  257,   59,   44,   59,
  291,   41,   41,   93,   44,   44,   41,   41,   41,   93,
   44,   44,  257,  244,  245,   41,  257,   40,   44,   59,
  269,  270,  271,  272,  273,   59,  269,  270,  271,  272,
  273,   93,   41,   93,  265,   44,   41,   59,   41,   44,
   41,   44,   41,   40,  258,   44,   41,  264,  293,  294,
  260,  261,  262,   93,  257,  298,  299,  300,  301,   93,
  271,  272,  273,  269,  270,  271,  272,  273,   41,   93,
  123,   44,  269,  270,  271,  272,  273,  271,   41,  271,
  125,   44,  288,  289,   91,   59,   59,  260,  261,  262,
  296,  297,  298,  299,  300,  301,   59,  257,   46,  296,
  297,  298,  299,  300,  301,  257,  257,  269,  270,  271,
  272,  273,   40,  269,  270,  271,  272,  273,  280,  257,
   93,  258,  284,  285,  280,  257,  288,  289,  284,  285,
   93,  264,  288,  289,  296,  297,  298,  299,  300,  301,
  296,  297,  298,  299,  300,  301,  269,  270,  271,  272,
  273,  280,  269,  270,  257,  284,  285,  280,   46,  288,
  289,  284,  285,  280,   61,  288,  289,  284,  285,   59,
  265,  288,  289,  296,  297,  298,  299,  300,  301,  296,
  297,  298,  299,  300,  301,  269,  270,   93,  257,  257,
  280,  257,   40,   40,  284,  285,  280,   40,  288,  289,
  284,  285,  271,  271,  288,  289,  296,  297,  298,  299,
  300,  301,  296,  297,  298,  299,  300,  301,  280,  257,
  280,  125,  284,  285,  284,  285,  288,  289,   93,  289,
  260,  261,  262,   59,  296,  297,  298,  299,  300,  301,
  280,   59,   41,   41,  284,  285,  280,   61,  288,  289,
  284,  285,  265,   59,  288,  289,  296,  297,  298,  299,
  300,  301,  296,  297,  298,  299,  300,  301,  269,  270,
  271,  272,  273,  291,  269,  270,  271,  272,  273,    0,
  257,  257,  264,   46,   59,  257,  257,  288,  289,   59,
   59,   59,   59,  288,  289,  296,  297,  298,  299,  300,
  301,  296,  297,  298,  299,  300,  301,  280,   46,   59,
   59,  284,  285,  221,   97,  288,  289,  280,  255,   35,
   84,  284,  285,  296,  297,  288,  289,   24,   94,  257,
  258,  259,    6,  296,  297,  263,   19,   41,   68,  104,
   24,  124,  100,  271,  127,  152,  274,   -1,   -1,   95,
   -1,  112,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
   -1,   -1,  290,  269,  270,  271,  272,  273,   -1,  267,
  268,  118,  119,  271,   -1,  122,  123,  275,   -1,   -1,
   -1,  279,  288,  289,   -1,  283,  284,  170,  286,  287,
  296,  297,  298,  299,  300,  301,   -1,  295,  181,   -1,
   -1,   -1,  269,  270,  271,  272,  273,  154,  155,   -1,
   -1,   -1,   -1,   -1,   -1,  162,  163,  284,  285,   -1,
   -1,  288,  289,   -1,  171,  208,  209,   -1,  175,  296,
  297,  298,  299,  300,  301,   -1,   -1,   -1,  221,   -1,
   -1,  188,   -1,   -1,   -1,   -1,   -1,  194,  195,  196,
  197,  198,  199,  200,  201,  202,  203,  204,  205,  206,
  207,  244,  245,  210,  269,  270,  271,  272,  273,   -1,
   -1,   -1,  219,   -1,  257,  280,   -1,   -1,   -1,   -1,
   -1,   -1,  265,  288,  289,  269,  270,  271,  272,  273,
   -1,  296,  297,  298,  299,  300,  301,   -1,   -1,   -1,
  284,   -1,   -1,   -1,  288,  289,  253,  269,  270,  271,
  272,  273,  296,  297,  298,  299,  300,  301,   -1,   -1,
   -1,  269,  270,  271,  272,  273,  288,  289,   -1,   -1,
   -1,   -1,   -1,   -1,  296,  297,  298,  299,  300,  301,
  288,   -1,   -1,   -1,  257,   -1,   -1,   -1,  296,  297,
  298,  299,  300,  301,  267,  268,   -1,   -1,  271,   -1,
   -1,   -1,  275,   -1,   -1,  257,  279,   -1,  281,  282,
  283,  284,   -1,  286,  287,  267,  268,   -1,   -1,  271,
   -1,   -1,   -1,  275,   -1,   -1,  257,  279,   -1,   -1,
   -1,  283,  284,  285,  286,  287,  267,  268,   -1,   -1,
  271,   -1,   -1,   -1,  275,   -1,   -1,  257,  279,   -1,
   -1,  282,  283,  284,   -1,  286,  287,  267,  268,   -1,
   -1,  271,   -1,   -1,   -1,  275,   -1,   -1,  257,  279,
   -1,   -1,   -1,  283,  284,   -1,  286,  287,  267,  268,
   -1,   -1,  271,   -1,   -1,   -1,  275,   -1,   -1,   -1,
  279,   -1,   -1,   -1,  283,  284,   -1,  286,  287,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 301
#define YYUNDFTOKEN 364
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,"'='",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"ID","NUM","STRING","INITIALIZE","ALLOC","FREE","NULL_","BEGIN_","END",
"MAIN","READ","WRITE","PLUS","MINUS","MUL","DIV","MOD","AMPERSAND","BREAKPOINT",
"TYPE","ENDTYPE","TUPLE","IF","THEN","ELSE","ENDIF","WHILE","DO","ENDWHILE",
"BREAK","CONTINUE","AND","OR","NOT","DECL","ENDDECL","INT","STR","RETURN","EQ",
"NEQ","LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
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
"assignStmt : ID '=' expr",
"assignStmt : ID '[' expr ']' '=' expr",
"assignStmt : MUL ID '=' expr",
"assignStmt : StructField '=' expr",
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
"GDecl : GType TupleDecl GIDList ';'",
"GType : INT",
"GType : STR",
"GType : ID",
"GType : TUPLE ID",
"GIDList : GIDList ',' GID",
"GIDList : GID",
"GID : ID",
"GID : ID '[' NUM ']'",
"GID : ID '(' ParamList ')'",
"GID : GPtrID",
"GID : GPtrID '(' ParamList ')'",
"GPtrID : MUL ID",
"TupleDecl : '(' TupleFieldDeclList ')'",
"TupleFieldDeclList : TupleFieldDeclList ',' TupleFieldDecl",
"TupleFieldDeclList : TupleFieldDecl",
"TupleFieldDecl : TupleFieldType TupleFieldName",
"TupleFieldType : INT",
"TupleFieldType : STR",
"TupleFieldName : ID",
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
"LDecl : LType TupleDecl LIDList ';'",
"LType : INT",
"LType : STR",
"LType : ID",
"LType : TUPLE ID",
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
"DynaMemID : ID '='",
"DynaMemID : ID '[' expr ']' '='",
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
#line 710 "ast.y"

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
#line 679 "y.tab.c"

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
#line 64 "ast.y"
	{}
break;
case 2:
#line 65 "ast.y"
	{}
break;
case 3:
#line 66 "ast.y"
	{	
												printf("\n⛔ No Code Provided\n");
												exit(1);
											}
break;
case 4:
#line 75 "ast.y"
	{ 
													/* printTypeTable(); */
												}
break;
case 6:
#line 81 "ast.y"
	{}
break;
case 7:
#line 82 "ast.y"
	{}
break;
case 8:
#line 86 "ast.y"
	{ 
													if (typeFieldCount > 8){
														printf("\nError: User defined type %s has more than 8 fields\n", yystack.l_mark[-3].TTNode->typeName);
														exit(1);
													}

													/* FLPrint($1); */
													yystack.l_mark[-3].TTNode->typeCategory = TYPE_USER_DEFINED;
													yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-1].FLNode;
													yystack.l_mark[-3].TTNode->size = typeFieldCount;

													fieldListTail = NULL;
													fieldListHead = NULL;
													typeFieldCount = 0;
												}
break;
case 9:
#line 103 "ast.y"
	{ yyval.TTNode = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); }
break;
case 10:
#line 106 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[-1].FLNode;
												}
break;
case 11:
#line 112 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = 0;
													fieldListHead = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[0].FLNode;
				 								}
break;
case 12:
#line 120 "ast.y"
	{ 
													yyval.FLNode = FLCreateNode(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-2].TTNode); 
													++typeFieldCount;
												}
break;
case 13:
#line 126 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 14:
#line 127 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 15:
#line 128 "ast.y"
	{ yyval.TTNode = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 16:
#line 133 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 17:
#line 134 "ast.y"
	{}
break;
case 27:
#line 141 "ast.y"
	{ ++statementCount; }
break;
case 28:
#line 144 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 29:
#line 147 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 30:
#line 150 "ast.y"
	{ 
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
												}
break;
case 31:
#line 154 "ast.y"
	{	 
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
												}
break;
case 32:
#line 159 "ast.y"
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
#line 169 "ast.y"
	{
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);
												}
break;
case 34:
#line 176 "ast.y"
	{}
break;
case 35:
#line 179 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 36:
#line 184 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 37:
#line 185 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 38:
#line 188 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 39:
#line 191 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 40:
#line 194 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 41:
#line 197 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 42:
#line 200 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 43:
#line 205 "ast.y"
	{
												/* GSTPrint(); */
												/* printTypeTable();					*/
												initStackBP(filePtr);
												/* printGlobalParamList();*/
											}
break;
case 44:
#line 211 "ast.y"
	{}
break;
case 45:
#line 214 "ast.y"
	{}
break;
case 46:
#line 215 "ast.y"
	{}
break;
case 47:
#line 218 "ast.y"
	{}
break;
case 48:
#line 219 "ast.y"
	{ 
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												/* FLPrint($1);*/

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentGDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 49:
#line 233 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 50:
#line 234 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 51:
#line 235 "ast.y"
	{ 
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {
													printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}
			 								}
break;
case 52:
#line 242 "ast.y"
	{ 
												if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
													printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}					
												currentGDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
												yyval.TTNode = currentGDeclType;
											}
break;
case 53:
#line 252 "ast.y"
	{}
break;
case 54:
#line 253 "ast.y"
	{}
break;
case 55:
#line 256 "ast.y"
	{ 
												int varSize = (currentGDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentGDeclType->size);
												GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, varSize, NULL); 
											}
break;
case 56:
#line 260 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 57:
#line 267 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 58:
#line 273 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 59:
#line 280 "ast.y"
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
case 60:
#line 293 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 298 "ast.y"
	{ 
																	yyval.FLNode = yystack.l_mark[-1].FLNode; 

																	if (currentGDeclType != NULL)
																		currentGDeclType->size = tupleFieldCount;
																	if (currentLDeclType != NULL)
																		currentLDeclType->size = tupleFieldCount;		
																}
break;
case 62:
#line 308 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[-2].FLNode;
																}
break;
case 63:
#line 314 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = 0;
																	fieldListHead = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[0].FLNode;
																}
break;
case 64:
#line 322 "ast.y"
	{
																	yyval.FLNode = FLCreateNode(yystack.l_mark[0].node->nodeName, yystack.l_mark[-1].TTNode);
																	++tupleFieldCount;
																}
break;
case 65:
#line 328 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 66:
#line 329 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 67:
#line 332 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 340 "ast.y"
	{}
break;
case 69:
#line 341 "ast.y"
	{}
break;
case 70:
#line 342 "ast.y"
	{}
break;
case 71:
#line 345 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 72:
#line 351 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 73:
#line 352 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 74:
#line 353 "ast.y"
	{  }
break;
case 75:
#line 354 "ast.y"
	{  }
break;
case 76:
#line 355 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 77:
#line 364 "ast.y"
	{ yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 78:
#line 365 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 79:
#line 366 "ast.y"
	{}
break;
case 80:
#line 369 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 375 "ast.y"
	{}
break;
case 82:
#line 376 "ast.y"
	{}
break;
case 83:
#line 379 "ast.y"
	{ 
															if(GSTLookup(yystack.l_mark[0].node->nodeName) == NULL){
																printf("\nFunction %s is not declared\n", yystack.l_mark[0].node->nodeName);
																exit(1);
															}
															yyval.node = yystack.l_mark[0].node; 
															setCurrentFuncName(yystack.l_mark[0].node->nodeName);
														}
break;
case 84:
#line 390 "ast.y"
	{
															char* currentFuncName = getCurrentFuncName();

															/* TODO: Pls check!!!*/
															/* addFunctionLST(currentFuncName, LSTHead);	*/
															
															fprintf(filePtr, "F%d:\n", GSTLookup(currentFuncName)->fLabel);
															initFuncCalle(filePtr, paramCount);

															/* printASTTable($4, 0);*/
															codeGen(yystack.l_mark[-1].node, filePtr);

															/* LSTPrint();*/
															flushLST();
															paramCount = 0;
														}
break;
case 85:
#line 408 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 86:
#line 414 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 87:
#line 415 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 88:
#line 416 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 89:
#line 417 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 90:
#line 418 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 91:
#line 421 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 93:
#line 431 "ast.y"
	{  
											/* printTupleList();*/
										}
break;
case 94:
#line 434 "ast.y"
	{}
break;
case 95:
#line 437 "ast.y"
	{}
break;
case 96:
#line 438 "ast.y"
	{}
break;
case 97:
#line 441 "ast.y"
	{}
break;
case 98:
#line 442 "ast.y"
	{
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												/* FLPrint($1);*/

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentLDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 99:
#line 456 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 100:
#line 457 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 101:
#line 458 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 102:
#line 465 "ast.y"
	{
											if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
												printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}					
											currentLDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
											yyval.TTNode = currentLDeclType;
										}
break;
case 103:
#line 475 "ast.y"
	{}
break;
case 104:
#line 476 "ast.y"
	{}
break;
case 105:
#line 479 "ast.y"
	{ 
											int varSize = (currentLDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentLDeclType->size);							
											LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, varSize); 
										}
break;
case 106:
#line 483 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 107:
#line 490 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 108:
#line 506 "ast.y"
	{
														char* currentFuncName = getCurrentFuncName();

														/* TODO: Check!!!*/
														/* addFunctionLST(currentFuncName, LSTHead);	*/

														fprintf(filePtr, "F0:\n");
														initFuncCalle(filePtr, paramCount);

														/* printASTTable($6, 0);*/
														codeGen(yystack.l_mark[-1].node, filePtr);
														/* LSTPrint();*/
														flushLST();
														paramCount = 0;
												
														/* printFLT();*/
													}
break;
case 109:
#line 525 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 110:
#line 528 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 114:
#line 543 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 115:
#line 549 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 116:
#line 556 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 117:
#line 562 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 118:
#line 563 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 119:
#line 573 "ast.y"
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
case 120:
#line 600 "ast.y"
	{
												/* Checking if ID($1) exists in LST or GST*/
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);

												if (yystack.l_mark[-2].node->typeTablePtr->typeCategory == TYPE_USER_DEFINED)
													yystack.l_mark[-2].node->nodeType = FIELD_NODE;

												else if (yystack.l_mark[-2].node->typeTablePtr->typeCategory == TYPE_TUPLE)
													yystack.l_mark[-2].node->nodeType = TUPLE_NODE;
												
												else {
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
case 121:
#line 630 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 122:
#line 631 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 123:
#line 639 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 124:
#line 640 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 125:
#line 641 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 126:
#line 642 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 127:
#line 643 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 128:
#line 644 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 129:
#line 645 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 130:
#line 646 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 131:
#line 647 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 132:
#line 648 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 133:
#line 649 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 134:
#line 650 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 135:
#line 651 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 136:
#line 652 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 137:
#line 653 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 138:
#line 654 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 139:
#line 655 "ast.y"
	{ 
										/* check if ID is a type constructor*/
										struct TypeTable* idTTEntry = TTLookUp(yystack.l_mark[-3].node->nodeName);

										/* if its a Tuple Constructor		*/
										if (idTTEntry != NULL && idTTEntry->typeCategory == TYPE_TUPLE){
											verifyTupleFields(idTTEntry, yystack.l_mark[-1].node);
											yyval.node = TreeCreate(idTTEntry, TUPLE_CONSTRUCTOR_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL);
											yyval.node->argListHead = yystack.l_mark[-1].node;
										}

										/* if its a function*/
										if(idTTEntry == NULL){
											yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
											verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
											yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL); 
											yyval.node->argListHead = yystack.l_mark[-1].node;
											yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
										}
									}
break;
case 140:
#line 675 "ast.y"
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
case 141:
#line 684 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 142:
#line 692 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 143:
#line 700 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 144:
#line 704 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 145:
#line 705 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 146:
#line 706 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1743 "y.tab.c"
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
