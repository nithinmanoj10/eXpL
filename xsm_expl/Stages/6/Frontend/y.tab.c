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
#define EQUAL 275
#define BREAKPOINT 276
#define TYPE 277
#define ENDTYPE 278
#define TUPLE 279
#define IF 280
#define THEN 281
#define ELSE 282
#define ENDIF 283
#define WHILE 284
#define DO 285
#define ENDWHILE 286
#define BREAK 287
#define CONTINUE 288
#define AND 289
#define OR 290
#define NOT 291
#define DECL 292
#define ENDDECL 293
#define INT 294
#define STR 295
#define RETURN 296
#define EQ 297
#define NEQ 298
#define LT 299
#define LTE 300
#define GT 301
#define GTE 302
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,   37,   37,   41,   41,   42,   29,   33,
   33,   32,   28,   28,   28,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    3,    4,    5,
    5,    5,    5,   15,   14,    6,    6,    9,   10,   11,
   12,   13,   38,   38,   44,   44,   45,   45,   30,   30,
   30,   30,   46,   46,   47,   47,   47,   47,   47,   20,
   36,   35,   35,   34,   31,   31,   27,   48,   48,   48,
   49,   50,   50,   50,   50,   50,   19,   19,   19,   18,
   39,   39,    7,   51,   52,   54,   54,   54,   54,   54,
   17,   53,   53,   53,   55,   55,   56,   57,   57,   57,
   58,   58,   59,   59,   59,   40,   60,   16,   43,   43,
   43,   23,   24,   22,   25,   25,   21,   21,   26,   26,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,
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
    5,    3,    0,    2,    2,    1,    3,    1,    1,    1,
    3,    1,    1,    4,    2,    7,    2,    5,    1,    1,
    1,    4,    5,    4,    2,    5,    3,    3,    1,    4,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    3,    1,    4,    4,    2,    2,
    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    9,    0,    0,    7,    0,    0,    0,
    4,    6,   51,    0,   44,   49,   50,    0,    0,   46,
   90,    0,    0,    0,    2,   82,    0,    0,    0,   15,
   13,   14,    0,   11,    0,   52,    0,    0,    0,    0,
    0,    0,   54,   43,   45,  107,   88,   89,    1,   81,
    0,   83,    0,    0,    0,    8,   10,    0,    0,   60,
   65,   66,    0,   63,    0,    0,    0,   47,    0,    0,
    0,    0,    0,   12,    0,   76,    0,    0,    0,   69,
    0,   67,   64,    0,   61,    0,   48,   53,  100,   94,
   98,   99,    0,   96,    0,    0,    0,    0,    0,   56,
   74,   75,    0,   57,   71,   62,   59,   92,   95,    0,
    0,    0,  102,    0,    0,    0,    0,   42,    0,    0,
    0,   40,   41,    0,    0,   18,   19,   20,   21,   22,
   23,   24,   25,   26,    0,  111,  109,  110,    0,    0,
   27,   84,   85,    0,   68,    0,  105,   97,    0,    0,
    0,    0,  142,  143,  144,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  101,
    0,    0,    0,    0,  140,  139,  134,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   16,    0,    0,
  117,    0,    0,    0,  118,    0,  106,  104,    0,    0,
    0,   78,    0,  135,    0,    0,  123,  124,  125,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   35,   91,  114,  112,    0,    0,    0,    0,    0,
  137,    0,   37,   38,   39,  113,    0,    0,   77,    0,
  108,   36,
};
static const YYINT yydgoto[] = {                          2,
  124,  125,  126,  127,  128,  129,   53,  221,  130,  131,
  132,  133,  134,  169,  207,  178,   97,  222,  223,   40,
  161,  136,  137,  138,  139,  140,   83,   33,    5,   18,
   63,   34,   35,   64,   65,   41,    3,    9,   24,   25,
    6,    7,  141,   19,   20,   42,   43,   79,   80,   81,
   26,   27,   71,   28,   93,   94,   95,  112,  113,   29,
};
static const YYINT yysindex[] = {                      -254,
 -228,    0, -259,    0,  -84, -244,    0, -238, -230, -213,
    0,    0,    0, -207,    0,    0,    0,  -32, -203,    0,
    0, -164, -175, -230,    0,    0,  -14, -144,   79,    0,
    0,    0, -137,    0, -118,    0,  -30, -131, -216,   98,
 -243,  -27,    0,    0,    0,    0,    0,    0,    0,    0,
 -160,    0,  110,  114,   97,    0,    0,  -93, -210,    0,
    0,    0,  -91,    0,    5, -210,  -23,    0, -243, -226,
  -95, -210,   47,    0,   75,    0,  -97,  -90,   18,    0,
  -79,    0,    0, -216,    0,   31,    0,    0,    0,    0,
    0,    0, -183,    0, -241,  528,   57,   62, -160,    0,
    0,    0, -210,    0,    0,    0,    0,    0,    0,   96,
  -74,  -22,    0,  -89,  202,  202,  -67,    0,  202,  202,
  528,    0,    0,  -96,  134,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -42,    0,    0,    0, -113,  148,
    0,    0,    0,  -68,    0,  -61,    0,    0, -241,  202,
  202,  -28,    0,    0,    0,  -58,  -55,  202,  202,  424,
  157,  424,  -70,  380,  402,  543,  202,  147,  -57,    0,
  202,  -50,  169,  170,  171,  -45,  528,   89,  122,    0,
  424,  225,  202,  202,    0,    0,    0,  126,  202,  202,
  202,  202,  202,  202,  202,  202,  202,  202,  202,  202,
  202,  202,  528,  528,  202,  424,  158,    0,  159,  424,
    0,  175,  179,  202,    0,  -96,    0,    0,  -54,  231,
  424,    0,   74,    0, -119, -119,    0,    0,    0,  446,
  438,  210,  210, -129, -129, -129, -129,  424,  280,  484,
  357,    0,    0,    0,    0,  132,  -43,  202,    0,  202,
    0,  528,    0,    0,    0,    0,  164,  424,    0,  506,
    0,    0,
};
static const YYINT yyrindex[] = {                       -66,
    0,    0,    0,    0,    0,    0,    0,    0,  224,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -16,   -5,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -19,    0,    0,   45,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -37,    0,    0,    0,    0,    0,    0,    0,   80,    0,
    0,    0,    0,    0,    0,   80,    0,    0,    0,    0,
    0,   80,    0,    0,    0,    0,   11,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -37,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   55,
    0,    0,    0,  197,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -102,
    0,  -41,    0,    0,    0,    0,    0,    0,    0,  219,
    1,  222,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  226,    0,    0,   84,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  230,    0,    0,    0,  235,
    0,    0,    0,    0,    0,    0,    0,    0,  249,    0,
   90,    0,    0,    0,    7,   42,    0,    0,    0,   -6,
   29,  154,  160,   36,   64,   86,   92,  254,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -98,  -35,    0,
    0,    0,    0,    0,    0,    0,    0,  257,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
 -106, -123,    0,    0,    0,    0,    0,  420,    0,    0,
    0,    0,    0,  104,    0,    0,    0,  101,    0,    0,
  342,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  294,    0,  246,    0,    0,    0,    0,    0,  322,
    0,  341,    0,    0,  329,  311,  286,  -46,  253,    0,
  333,    0,  259,    0,    0,  266,    0,    0,  211,    0,
};
#define YYTABLESIZE 831
static const YYINT yytable[] = {                        141,
  168,  151,  141,  172,  119,  138,   56,   39,  138,   59,
  120,  184,    4,   37,  166,  110,   69,  141,   13,   86,
   69,  149,    1,  138,   55,   98,   21,   38,    4,  111,
   89,   68,    8,   11,  132,   87,  148,  132,   10,   55,
   14,  136,  168,   30,  136,   85,   76,  121,   84,   36,
  121,  141,  132,   13,   15,   16,   17,  138,  104,  136,
   58,  103,  183,   22,   23,  121,   90,   91,   92,  133,
  216,  107,  133,   89,  103,   14,  128,   61,   62,  128,
   31,   32,  122,   77,   78,  122,  132,  133,   58,   44,
   16,   17,  168,  136,  128,   48,  239,  240,  103,  121,
  122,   46,  143,   58,  129,  103,   47,  129,   51,  108,
   91,   92,   52,  103,  251,  168,  168,  250,   54,   55,
   70,  133,  129,   70,   79,   60,  130,   79,  128,  130,
   80,   70,  131,   80,  122,  131,  168,   66,   30,  189,
  190,  191,  192,  193,  130,  260,  173,  174,  175,   72,
  131,  191,  192,  193,   73,   74,  129,  115,  115,  115,
  114,  116,  116,  116,   75,   82,  224,  100,   96,   99,
  115,  116,  256,  101,  117,   31,   32,  105,  130,  118,
  102,  142,  147,  119,  131,  150,  146,  120,  121,  163,
  122,  123,  170,  176,  126,  177,  179,  126,  185,  167,
  127,  186,  172,  127,  202,  208,  211,  209,  212,  213,
  214,  215,  126,  217,  218,  244,  242,  243,  127,  245,
  248,  257,  261,    3,   37,    5,   93,  141,  141,  141,
  141,  141,  171,  138,  138,  138,  138,  138,   38,  141,
   86,  159,  119,  141,  141,  138,  126,  141,  141,  138,
  138,   87,  127,  138,  138,  141,  141,  141,  141,  141,
  141,  138,  138,  138,  138,  138,  138,   72,   73,  136,
  136,  136,  136,  136,  132,  121,  121,   28,  132,  132,
   29,  136,  132,  132,   30,  136,  136,  121,   34,  136,
  136,  121,  121,   33,  120,  121,  121,  136,  136,  136,
  136,  136,  136,  121,  121,  121,  121,  121,  121,  133,
  122,  122,   32,  133,  133,   31,  128,  219,  133,  247,
  128,  128,  122,  249,  128,  128,  122,  122,   57,  106,
  122,  122,  128,  128,  128,  128,  128,  128,  122,  122,
  122,  122,  122,  122,  129,   49,   12,   45,  129,  129,
  259,   67,  129,  129,   88,  145,   50,  144,  109,  180,
  129,  129,  129,  129,  129,  129,  130,    0,    0,    0,
  130,  130,  131,    0,  130,  130,  131,  131,    0,    0,
  131,  131,  130,  130,  130,  130,  130,  130,  131,  131,
  131,  131,  131,  131,  189,  190,  191,  192,  193,    0,
  189,  190,  191,  192,  193,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  194,  195,    0,    0,    0,    0,
  194,  195,  196,  197,  198,  199,  200,  201,  196,  197,
  198,  199,  200,  201,  126,    0,    0,  135,  126,  126,
  127,    0,  126,  126,  127,  127,    0,    0,  127,  127,
  126,  126,    0,    0,    0,    0,  127,  127,  152,  153,
  154,    0,  135,    0,  155,  135,    0,    0,    0,    0,
    0,    0,  156,    0,    0,  157,    0,    0,  189,  190,
  191,  192,  193,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  158,  189,  190,  191,  192,  193,    0,  189,
  190,  191,  192,  193,    0,    0,    0,  135,  198,  199,
  200,  201,    0,  194,  195,    0,    0,    0,  135,  194,
  195,  196,  197,  198,  199,  200,  201,  196,  197,  198,
  199,  200,  201,    0,  160,  162,  114,    0,  164,  165,
    0,    0,    0,    0,  135,  135,  115,  116,    0,    0,
  117,    0,    0,    0,    0,  118,    0,  135,    0,  119,
    0,  252,  253,  120,  121,    0,  122,  123,    0,  181,
  182,    0,    0,    0,    0,    0,    0,  187,  188,    0,
  135,  135,    0,    0,    0,    0,  206,    0,    0,    0,
  210,    0,    0,  135,    0,    0,    0,    0,    0,    0,
    0,  135,  220,    0,    0,    0,    0,    0,  225,  226,
  227,  228,  229,  230,  231,  232,  233,  234,  235,  236,
  237,  238,    0,    0,  241,  189,  190,  191,  192,  193,
    0,    0,    0,  246,    0,    0,    0,    0,    0,    0,
    0,  204,  255,    0,    0,  194,  195,    0,  189,  190,
  191,  192,  193,  196,  197,  198,  199,  200,  201,    0,
  203,    0,    0,    0,    0,    0,    0,  258,  194,  195,
  189,  190,  191,  192,  193,    0,  196,  197,  198,  199,
  200,  201,    0,    0,    0,    0,  204,    0,    0,    0,
  194,  195,  189,  190,  191,  192,  193,    0,  196,  197,
  198,  199,  200,  201,    0,    0,  189,  190,  191,  192,
  193,    0,  194,  195,  189,  190,  191,  192,  193,    0,
  196,  197,  198,  199,  200,  201,  194,    0,    0,    0,
    0,    0,    0,    0,  196,  197,  198,  199,  200,  201,
  114,    0,  196,  197,  198,  199,  200,  201,    0,    0,
  115,  116,    0,    0,  117,    0,    0,    0,    0,  118,
    0,    0,  114,  119,    0,    0,    0,  120,  121,  254,
  122,  123,  115,  116,    0,    0,  117,    0,    0,    0,
    0,  118,    0,    0,  114,  119,    0,    0,  262,  120,
  121,    0,  122,  123,  115,  116,    0,    0,  117,  114,
    0,    0,    0,  118,    0,    0,    0,  119,    0,  115,
  116,  120,  121,  117,  122,  123,    0,    0,  118,    0,
    0,    0,  119,    0,    0,    0,  205,  121,    0,  122,
  123,
};
static const YYINT yycheck[] = {                         41,
  124,   91,   44,   46,   46,   41,  125,   40,   44,   40,
   46,   40,  257,  257,  121,  257,   44,   59,  257,   66,
   44,   44,  277,   59,   44,   72,  257,  271,  257,  271,
  257,   59,  292,  278,   41,   59,   59,   44,  123,   59,
  279,   41,  166,  257,   44,   41,  257,   41,   44,  257,
   44,   93,   59,  257,  293,  294,  295,   93,   41,   59,
   91,   44,   91,  294,  295,   59,  293,  294,  295,   41,
  177,   41,   44,  257,   44,  279,   41,  294,  295,   44,
  294,  295,   41,  294,  295,   44,   93,   59,   44,  293,
  294,  295,  216,   93,   59,  271,  203,  204,   44,   93,
   59,  266,   41,   59,   41,   44,  271,   44,  123,  293,
  294,  295,  257,   59,   41,  239,  240,   44,   40,  257,
   41,   93,   59,   44,   41,  257,   41,   44,   93,   44,
   41,  292,   41,   44,   93,   44,  260,   40,  257,  269,
  270,  271,  272,  273,   59,  252,  260,  261,  262,   40,
   59,  271,  272,  273,   41,   59,   93,  260,  261,  262,
  257,  260,  261,  262,  258,  257,   41,   93,  264,  123,
  267,  268,   41,  271,  271,  294,  295,  257,   93,  276,
  271,  125,  257,  280,   93,  275,   91,  284,  285,  257,
  287,  288,   59,   46,   41,  264,  258,   44,  257,  296,
   41,  257,   46,   44,  275,   59,  257,  265,   40,   40,
   40,  257,   59,  125,   93,   41,   59,   59,   59,   41,
  275,  265,   59,    0,  257,  292,  264,  269,  270,  271,
  272,  273,  275,  269,  270,  271,  272,  273,  271,  281,
  257,   40,   46,  285,  286,  281,   93,  289,  290,  285,
  286,  257,   93,  289,  290,  297,  298,  299,  300,  301,
  302,  297,  298,  299,  300,  301,  302,  257,  257,  269,
  270,  271,  272,  273,  281,  269,  270,   59,  285,  286,
   59,  281,  289,  290,   59,  285,  286,  281,   59,  289,
  290,  285,  286,   59,   46,  289,  290,  297,  298,  299,
  300,  301,  302,  297,  298,  299,  300,  301,  302,  281,
  269,  270,   59,  285,  286,   59,  281,   93,  290,  216,
  285,  286,  281,   93,  289,  290,  285,  286,   35,   84,
  289,  290,  297,  298,  299,  300,  301,  302,  297,  298,
  299,  300,  301,  302,  281,   24,    6,   19,  285,  286,
  250,   41,  289,  290,   69,  103,   24,   99,   93,  149,
  297,  298,  299,  300,  301,  302,  281,   -1,   -1,   -1,
  285,  286,  281,   -1,  289,  290,  285,  286,   -1,   -1,
  289,  290,  297,  298,  299,  300,  301,  302,  297,  298,
  299,  300,  301,  302,  269,  270,  271,  272,  273,   -1,
  269,  270,  271,  272,  273,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  289,  290,   -1,   -1,   -1,   -1,
  289,  290,  297,  298,  299,  300,  301,  302,  297,  298,
  299,  300,  301,  302,  281,   -1,   -1,   96,  285,  286,
  281,   -1,  289,  290,  285,  286,   -1,   -1,  289,  290,
  297,  298,   -1,   -1,   -1,   -1,  297,  298,  257,  258,
  259,   -1,  121,   -1,  263,  124,   -1,   -1,   -1,   -1,
   -1,   -1,  271,   -1,   -1,  274,   -1,   -1,  269,  270,
  271,  272,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  291,  269,  270,  271,  272,  273,   -1,  269,
  270,  271,  272,  273,   -1,   -1,   -1,  166,  299,  300,
  301,  302,   -1,  289,  290,   -1,   -1,   -1,  177,  289,
  290,  297,  298,  299,  300,  301,  302,  297,  298,  299,
  300,  301,  302,   -1,  115,  116,  257,   -1,  119,  120,
   -1,   -1,   -1,   -1,  203,  204,  267,  268,   -1,   -1,
  271,   -1,   -1,   -1,   -1,  276,   -1,  216,   -1,  280,
   -1,  282,  283,  284,  285,   -1,  287,  288,   -1,  150,
  151,   -1,   -1,   -1,   -1,   -1,   -1,  158,  159,   -1,
  239,  240,   -1,   -1,   -1,   -1,  167,   -1,   -1,   -1,
  171,   -1,   -1,  252,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  260,  183,   -1,   -1,   -1,   -1,   -1,  189,  190,
  191,  192,  193,  194,  195,  196,  197,  198,  199,  200,
  201,  202,   -1,   -1,  205,  269,  270,  271,  272,  273,
   -1,   -1,   -1,  214,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  285,  286,   -1,   -1,  289,  290,   -1,  269,  270,
  271,  272,  273,  297,  298,  299,  300,  301,  302,   -1,
  281,   -1,   -1,   -1,   -1,   -1,   -1,  248,  289,  290,
  269,  270,  271,  272,  273,   -1,  297,  298,  299,  300,
  301,  302,   -1,   -1,   -1,   -1,  285,   -1,   -1,   -1,
  289,  290,  269,  270,  271,  272,  273,   -1,  297,  298,
  299,  300,  301,  302,   -1,   -1,  269,  270,  271,  272,
  273,   -1,  289,  290,  269,  270,  271,  272,  273,   -1,
  297,  298,  299,  300,  301,  302,  289,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  297,  298,  299,  300,  301,  302,
  257,   -1,  297,  298,  299,  300,  301,  302,   -1,   -1,
  267,  268,   -1,   -1,  271,   -1,   -1,   -1,   -1,  276,
   -1,   -1,  257,  280,   -1,   -1,   -1,  284,  285,  286,
  287,  288,  267,  268,   -1,   -1,  271,   -1,   -1,   -1,
   -1,  276,   -1,   -1,  257,  280,   -1,   -1,  283,  284,
  285,   -1,  287,  288,  267,  268,   -1,   -1,  271,  257,
   -1,   -1,   -1,  276,   -1,   -1,   -1,  280,   -1,  267,
  268,  284,  285,  271,  287,  288,   -1,   -1,  276,   -1,
   -1,   -1,  280,   -1,   -1,   -1,  284,  285,   -1,  287,
  288,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 302
#define YYUNDFTOKEN 365
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
"BREAKPOINT","TYPE","ENDTYPE","TUPLE","IF","THEN","ELSE","ENDIF","WHILE","DO",
"ENDWHILE","BREAK","CONTINUE","AND","OR","NOT","DECL","ENDDECL","INT","STR",
"RETURN","EQ","NEQ","LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"illegal-symbol",
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
#line 660 "ast.y"

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
#line 690 "y.tab.c"

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
												printTypeTable();					
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 44:
#line 206 "ast.y"
	{}
break;
case 45:
#line 209 "ast.y"
	{}
break;
case 46:
#line 210 "ast.y"
	{}
break;
case 47:
#line 213 "ast.y"
	{}
break;
case 48:
#line 214 "ast.y"
	{ 
												currentGDeclType->fields = yystack.l_mark[-2].FLNode; 
												currentGDeclType->size = tupleFieldCount;

												FLPrint(yystack.l_mark[-3].TTNode);

												fieldListTail = NULL;
												fieldListHead = NULL;
												tupleFieldCount = 0;
											}
break;
case 49:
#line 226 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 50:
#line 227 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 51:
#line 228 "ast.y"
	{ 
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {
													printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}
			 								}
break;
case 52:
#line 235 "ast.y"
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
#line 245 "ast.y"
	{}
break;
case 54:
#line 246 "ast.y"
	{}
break;
case 55:
#line 249 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, currentGDeclType->size, NULL); }
break;
case 56:
#line 250 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 57:
#line 257 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 58:
#line 263 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 59:
#line 270 "ast.y"
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
#line 283 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 288 "ast.y"
	{ 
																	yyval.FLNode = yystack.l_mark[-1].FLNode; 
																	currentGDeclType->size = tupleFieldCount;
																}
break;
case 62:
#line 294 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[-2].FLNode;
																}
break;
case 63:
#line 300 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = 0;
																	fieldListHead = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[0].FLNode;
																}
break;
case 64:
#line 308 "ast.y"
	{
																	yyval.FLNode = FLCreateNode(yystack.l_mark[0].node->nodeName, yystack.l_mark[-1].TTNode);
																	++tupleFieldCount;
																}
break;
case 65:
#line 314 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 66:
#line 315 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 67:
#line 318 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 325 "ast.y"
	{}
break;
case 69:
#line 326 "ast.y"
	{}
break;
case 70:
#line 327 "ast.y"
	{}
break;
case 71:
#line 330 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 72:
#line 336 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 73:
#line 337 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 74:
#line 338 "ast.y"
	{  }
break;
case 75:
#line 339 "ast.y"
	{  }
break;
case 76:
#line 340 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 77:
#line 348 "ast.y"
	{ 
											yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node);
										}
break;
case 78:
#line 351 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 79:
#line 352 "ast.y"
	{}
break;
case 80:
#line 355 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node; 
											/* ++argCount;*/
										}
break;
case 81:
#line 364 "ast.y"
	{}
break;
case 82:
#line 365 "ast.y"
	{}
break;
case 83:
#line 368 "ast.y"
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
#line 379 "ast.y"
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
case 85:
#line 397 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 86:
#line 403 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 87:
#line 404 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 88:
#line 405 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 89:
#line 406 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 90:
#line 407 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 91:
#line 410 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 93:
#line 420 "ast.y"
	{  
											/* printTupleList();*/
										}
break;
case 94:
#line 423 "ast.y"
	{}
break;
case 95:
#line 426 "ast.y"
	{}
break;
case 96:
#line 427 "ast.y"
	{}
break;
case 97:
#line 430 "ast.y"
	{}
break;
case 98:
#line 433 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 99:
#line 434 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 100:
#line 435 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 101:
#line 444 "ast.y"
	{}
break;
case 102:
#line 445 "ast.y"
	{}
break;
case 103:
#line 448 "ast.y"
	{ LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, 1); }
break;
case 104:
#line 449 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 105:
#line 456 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 106:
#line 472 "ast.y"
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
case 107:
#line 491 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 108:
#line 494 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 112:
#line 509 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 113:
#line 515 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 114:
#line 522 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 115:
#line 528 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 116:
#line 529 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 117:
#line 539 "ast.y"
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
case 118:
#line 566 "ast.y"
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
case 119:
#line 593 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 120:
#line 594 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 121:
#line 602 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 122:
#line 603 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 123:
#line 604 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 124:
#line 605 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 125:
#line 606 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 126:
#line 607 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 127:
#line 608 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 128:
#line 609 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 129:
#line 610 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 130:
#line 611 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 131:
#line 612 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 132:
#line 613 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 133:
#line 614 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 134:
#line 615 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 135:
#line 616 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 136:
#line 617 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 137:
#line 618 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL); 
										yyval.node->argListHead = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 138:
#line 625 "ast.y"
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
case 139:
#line 634 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 140:
#line 642 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 141:
#line 650 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 142:
#line 654 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 143:
#line 655 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 144:
#line 656 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1702 "y.tab.c"
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
