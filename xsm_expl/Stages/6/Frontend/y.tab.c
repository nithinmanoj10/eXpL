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
   65,   66,    0,   63,    0,    0,    0,    0,   47,    0,
    0,    0,    0,   12,    0,   76,    0,    0,    0,   69,
    0,   67,   64,    0,   61,    0,   48,   53,  100,   94,
   98,   99,    0,   96,    0,    0,    0,    0,    0,   56,
   74,   75,    0,   57,   71,   62,   59,   92,   95,    0,
    0,    0,  102,    0,    0,    0,    0,   42,    0,    0,
    0,   40,   41,    0,    0,   18,   19,   20,   21,   22,
   23,   24,   25,   26,    0,  111,  109,  110,    0,    0,
   27,   84,   85,    0,   68,    0,  105,    0,   97,    0,
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
static const YYINT yysindex[] = {                      -238,
 -213,    0, -237,    0,  -67, -236,    0, -228, -234, -220,
    0,    0,    0, -190,    0,    0,    0,   52, -136,    0,
    0, -249, -184, -234,    0,    0,  -24, -151,   72,    0,
    0,    0, -140,    0, -124,    0,  -38, -125, -134,  109,
 -195,  -31,    0,    0,    0,    0,    0,    0,    0,    0,
 -154,    0,  113,  121,  114,    0,    0,  -90, -214,    0,
    0,    0,  -66,    0,    5, -214,  -29, -195,    0, -223,
  -92, -214,   67,    0,  105,    0,  -71,  -70,   66,    0,
  -49,    0,    0, -134,    0,   75,    0,    0,    0,    0,
    0,    0, -210,    0, -148,  494,   80,   85, -154,    0,
    0,    0, -214,    0,    0,    0,    0,    0,    0,  115,
  -48,  -28,    0,  -51,  193,  193,  -47,    0,  193,  193,
  494,    0,    0,  299,  159,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   40,    0,    0,    0, -235,  173,
    0,    0,    0,  -37,    0,  -32,    0, -148,    0,  193,
  193,  -36,    0,    0,    0,  -17,  -15,  193,  193,  382,
  200,  382,  191,  340,  361,  515,  193,  216,   14,    0,
  193,   28,  250,  251,  270,   55,  494,  188,  221,    0,
  382,  -85,  193,  193,    0,    0,    0,  120,  193,  193,
  193,  193,  193,  193,  193,  193,  193,  193,  193,  193,
  193,  193,  494,  494,  193,  382,  259,    0,  265,  382,
    0,  301,  308,  193,    0,  299,    0,    0,  279,  215,
  382,    0,   95,    0, -107, -107,    0,    0,    0,  -76,
  396,  224,  224,  -94,  -94,  -94,  -94,  382,  431,  452,
  318,    0,    0,    0,    0,  126,   89,  193,    0,  193,
    0,  494,    0,    0,    0,    0,  303,  382,    0,  473,
    0,    0,
};
static const YYINT yyrindex[] = {                        73,
    0,    0,    0,    0,    0,    0,    0,    0,  363,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  111,  116,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   45,    0,    0,   49,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  110,    0,    0,    0,    0,    0,    0,    0,   97,    0,
    0,    0,    0,    0,    0,   97,    0,    0,    0,    0,
    0,   97,    0,    0,    0,    0,  137,  143,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  110,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   54,
    0,    0,    0,  355,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -79,
    0,  -41,    0,    0,    0,    0,    0,    0,    0,  343,
   -2,  344,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  345,    0,    0,  103,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  346,    0,    0,    0,  347,
    0,    0,    0,    0,    0,    0,    0,    0,  364,    0,
  104,    0,    0,    0,    4,   37,    0,    0,    0,   -8,
   61,  148,  158,   31,   59,   81,   87,  348,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   91,  -35,    0,
    0,    0,    0,    0,    0,    0,    0,  352,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
 -109, -105,    0,    0,    0,    0,    0,  350,    0,    0,
    0,    0,    0,  196,    0,    0,    0,  163,    0,    0,
  -89,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  394,    0,  351,    0,    0,    0,    0,    0,  406,
    0,  425,    0,    0,  415,  398,  372,  -52,  338,    0,
  424,    0,  354,    0,    0,  356,    0,    0,  309,    0,
};
#define YYTABLESIZE 802
static const YYINT yytable[] = {                        141,
   56,   59,  141,  184,  119,  138,  135,  219,  138,  150,
  120,  166,   68,   86,   68,  148,   46,  141,  168,   98,
    4,   47,   21,  138,  173,  174,  175,   69,   13,   87,
  149,  135,  132,   89,  135,  132,   30,    1,  136,  151,
   11,  136,   76,    4,  121,   85,   89,  121,   84,   14,
  132,  141,   58,    8,  183,   10,  136,  138,   22,   23,
  168,   37,  121,   15,   16,   17,   36,  216,   90,   91,
   92,  128,   31,   32,  128,   38,  135,  122,   77,   78,
  122,  108,   91,   92,  132,  172,   48,  135,   55,  128,
  136,   39,   58,  239,  240,  122,  121,  103,   51,  129,
  171,  133,  129,   55,  133,   52,  104,   58,  110,  103,
  168,   54,  103,  135,  135,  107,   55,  129,  103,  133,
   13,  130,  111,  128,  130,  143,  135,  131,  103,  122,
  131,   60,   30,  168,  168,  251,   70,   70,  250,  130,
   70,   14,  260,   79,   80,  131,   79,   80,   66,  135,
  135,  129,   72,  133,  168,   44,   16,   17,   61,   62,
  224,   73,  135,  191,  192,  193,  256,   75,   31,   32,
  135,   96,   74,  130,  189,  190,  191,  192,  193,  131,
  115,  115,  115,  189,  190,  191,  192,  193,  126,   99,
   82,  126,  189,  190,  191,  192,  193,  100,  127,  101,
  102,  127,  194,  195,  142,  146,  126,  105,  147,  163,
  196,  197,  198,  199,  200,  201,  127,  170,  176,  196,
  197,  198,  199,  200,  201,  179,  177,  141,  141,  141,
  141,  141,  159,  138,  138,  138,  138,  138,  141,  185,
  126,  186,  141,  141,  138,  172,  141,  141,  138,  138,
  127,  202,  138,  138,  141,  141,  141,  141,  141,  141,
  138,  138,  138,  138,  138,  138,  136,  136,  136,  136,
  136,  132,  121,  121,  208,  132,  132,  136,  209,  132,
  132,  136,  136,  121,  211,  136,  136,  121,  121,  212,
  213,  121,  121,  136,  136,  136,  136,  136,  136,  121,
  121,  121,  121,  121,  121,  122,  122,  249,   37,  214,
  128,  215,  217,  218,  128,  128,  122,  242,  128,  128,
  122,  122,   38,  243,  122,  122,  128,  128,  128,  128,
  128,  128,  122,  122,  122,  122,  122,  122,  129,  248,
  133,  244,  129,  129,  133,  133,  129,  129,  245,  133,
  116,  116,  116,  257,  129,  129,  129,  129,  129,  129,
  130,  261,    3,    5,  130,  130,  131,   86,  130,  130,
  131,  131,   87,   93,  131,  131,  130,  130,  130,  130,
  130,  130,  131,  131,  131,  131,  131,  131,  189,  190,
  191,  192,  193,   72,  189,  190,  191,  192,  193,   73,
  119,   28,   29,   30,   34,   33,   32,  194,  195,  120,
   31,  247,  259,  194,  195,  196,  197,  198,  199,  200,
  201,  196,  197,  198,  199,  200,  201,  126,   57,   49,
   12,  126,  126,   45,  106,  126,  126,  127,   67,   88,
  145,  127,  127,  126,  126,  127,  127,   50,  109,  152,
  153,  154,  144,  127,  127,  155,  180,    0,    0,    0,
    0,    0,    0,  156,  160,  162,  157,    0,  164,  165,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  158,  189,  190,  191,  192,  193,    0,    0,
    0,    0,  189,  190,  191,  192,  193,    0,    0,  181,
  182,    0,  194,  195,    0,    0,    0,  187,  188,    0,
  196,  197,  198,  199,  200,  201,  206,    0,    0,    0,
  210,  198,  199,  200,  201,    0,    0,    0,    0,    0,
    0,    0,  220,    0,    0,    0,    0,    0,  225,  226,
  227,  228,  229,  230,  231,  232,  233,  234,  235,  236,
  237,  238,    0,    0,  241,  114,    0,    0,    0,    0,
    0,    0,    0,  246,    0,  115,  116,    0,    0,  117,
    0,    0,    0,  118,    0,    0,    0,  119,    0,    0,
    0,  120,  121,    0,  122,  123,  189,  190,  191,  192,
  193,    0,    0,  167,    0,    0,    0,  258,    0,    0,
    0,  204,  255,    0,    0,  194,  195,    0,  189,  190,
  191,  192,  193,  196,  197,  198,  199,  200,  201,  203,
    0,    0,    0,    0,    0,    0,    0,  194,  195,  189,
  190,  191,  192,  193,    0,  196,  197,  198,  199,  200,
  201,    0,    0,    0,  204,    0,    0,    0,  194,  195,
  189,  190,  191,  192,  193,    0,  196,  197,  198,  199,
  200,  201,    0,    0,  189,  190,  191,  192,  193,  194,
  195,    0,    0,    0,    0,    0,    0,  196,  197,  198,
  199,  200,  201,  194,    0,    0,    0,  114,    0,    0,
    0,  196,  197,  198,  199,  200,  201,  115,  116,    0,
    0,  117,    0,    0,    0,  118,    0,    0,  114,  119,
    0,  252,  253,  120,  121,    0,  122,  123,  115,  116,
    0,    0,  117,    0,    0,    0,  118,    0,    0,  114,
  119,    0,    0,    0,  120,  121,  254,  122,  123,  115,
  116,    0,    0,  117,    0,    0,    0,  118,    0,    0,
  114,  119,    0,    0,  262,  120,  121,    0,  122,  123,
  115,  116,    0,    0,  117,    0,    0,    0,  118,    0,
    0,  114,  119,    0,    0,    0,  120,  121,    0,  122,
  123,  115,  116,    0,    0,  117,    0,    0,    0,  118,
    0,    0,    0,  119,    0,    0,    0,  205,  121,    0,
  122,  123,
};
static const YYINT yycheck[] = {                         41,
  125,   40,   44,   40,   46,   41,   96,   93,   44,   61,
   46,  121,   44,   66,   44,   44,  266,   59,  124,   72,
  257,  271,  257,   59,  260,  261,  262,   59,  257,   59,
   59,  121,   41,  257,  124,   44,  257,  276,   41,   91,
  277,   44,  257,  257,   41,   41,  257,   44,   44,  278,
   59,   93,   91,  291,   91,  123,   59,   93,  293,  294,
  166,  257,   59,  292,  293,  294,  257,  177,  292,  293,
  294,   41,  293,  294,   44,  271,  166,   41,  293,  294,
   44,  292,  293,  294,   93,   46,  271,  177,   44,   59,
   93,   40,   44,  203,  204,   59,   93,   44,  123,   41,
   61,   41,   44,   59,   44,  257,   41,   59,  257,   44,
  216,   40,   59,  203,  204,   41,  257,   59,   44,   59,
  257,   41,  271,   93,   44,   41,  216,   41,   44,   93,
   44,  257,  257,  239,  240,   41,  291,   41,   44,   59,
   44,  278,  252,   41,   41,   59,   44,   44,   40,  239,
  240,   93,   40,   93,  260,  292,  293,  294,  293,  294,
   41,   41,  252,  271,  272,  273,   41,  258,  293,  294,
  260,  264,   59,   93,  269,  270,  271,  272,  273,   93,
  260,  261,  262,  269,  270,  271,  272,  273,   41,  123,
  257,   44,  269,  270,  271,  272,  273,   93,   41,  271,
  271,   44,  288,  289,  125,   91,   59,  257,  257,  257,
  296,  297,  298,  299,  300,  301,   59,   59,   46,  296,
  297,  298,  299,  300,  301,  258,  264,  269,  270,  271,
  272,  273,   40,  269,  270,  271,  272,  273,  280,  257,
   93,  257,  284,  285,  280,   46,  288,  289,  284,  285,
   93,   61,  288,  289,  296,  297,  298,  299,  300,  301,
  296,  297,  298,  299,  300,  301,  269,  270,  271,  272,
  273,  280,  269,  270,   59,  284,  285,  280,  265,  288,
  289,  284,  285,  280,  257,  288,  289,  284,  285,   40,
   40,  288,  289,  296,  297,  298,  299,  300,  301,  296,
  297,  298,  299,  300,  301,  269,  270,   93,  257,   40,
  280,  257,  125,   93,  284,  285,  280,   59,  288,  289,
  284,  285,  271,   59,  288,  289,  296,  297,  298,  299,
  300,  301,  296,  297,  298,  299,  300,  301,  280,   61,
  280,   41,  284,  285,  284,  285,  288,  289,   41,  289,
  260,  261,  262,  265,  296,  297,  298,  299,  300,  301,
  280,   59,    0,  291,  284,  285,  280,  257,  288,  289,
  284,  285,  257,  264,  288,  289,  296,  297,  298,  299,
  300,  301,  296,  297,  298,  299,  300,  301,  269,  270,
  271,  272,  273,  257,  269,  270,  271,  272,  273,  257,
   46,   59,   59,   59,   59,   59,   59,  288,  289,   46,
   59,  216,  250,  288,  289,  296,  297,  298,  299,  300,
  301,  296,  297,  298,  299,  300,  301,  280,   35,   24,
    6,  284,  285,   19,   84,  288,  289,  280,   41,   68,
  103,  284,  285,  296,  297,  288,  289,   24,   93,  257,
  258,  259,   99,  296,  297,  263,  148,   -1,   -1,   -1,
   -1,   -1,   -1,  271,  115,  116,  274,   -1,  119,  120,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  290,  269,  270,  271,  272,  273,   -1,   -1,
   -1,   -1,  269,  270,  271,  272,  273,   -1,   -1,  150,
  151,   -1,  288,  289,   -1,   -1,   -1,  158,  159,   -1,
  296,  297,  298,  299,  300,  301,  167,   -1,   -1,   -1,
  171,  298,  299,  300,  301,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  183,   -1,   -1,   -1,   -1,   -1,  189,  190,
  191,  192,  193,  194,  195,  196,  197,  198,  199,  200,
  201,  202,   -1,   -1,  205,  257,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  214,   -1,  267,  268,   -1,   -1,  271,
   -1,   -1,   -1,  275,   -1,   -1,   -1,  279,   -1,   -1,
   -1,  283,  284,   -1,  286,  287,  269,  270,  271,  272,
  273,   -1,   -1,  295,   -1,   -1,   -1,  248,   -1,   -1,
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
   -1,  271,   -1,   -1,   -1,  275,   -1,   -1,  257,  279,
   -1,  281,  282,  283,  284,   -1,  286,  287,  267,  268,
   -1,   -1,  271,   -1,   -1,   -1,  275,   -1,   -1,  257,
  279,   -1,   -1,   -1,  283,  284,  285,  286,  287,  267,
  268,   -1,   -1,  271,   -1,   -1,   -1,  275,   -1,   -1,
  257,  279,   -1,   -1,  282,  283,  284,   -1,  286,  287,
  267,  268,   -1,   -1,  271,   -1,   -1,   -1,  275,   -1,
   -1,  257,  279,   -1,   -1,   -1,  283,  284,   -1,  286,
  287,  267,  268,   -1,   -1,  271,   -1,   -1,   -1,  275,
   -1,   -1,   -1,  279,   -1,   -1,   -1,  283,  284,   -1,
  286,  287,
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
#line 692 "ast.y"

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
#line 683 "y.tab.c"

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
	{ printTypeTable(); }
break;
case 6:
#line 79 "ast.y"
	{}
break;
case 7:
#line 80 "ast.y"
	{}
break;
case 8:
#line 84 "ast.y"
	{ 
													if (typeFieldCount > 8){
														printf("\nError: User defined type %s has more than 8 fields\n", yystack.l_mark[-3].TTNode->typeName);
														exit(1);
													}

													FLPrint(yystack.l_mark[-3].TTNode); 
													yystack.l_mark[-3].TTNode->typeCategory = TYPE_USER_DEFINED;
													yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-1].FLNode;
													yystack.l_mark[-3].TTNode->size = typeFieldCount;

													fieldListTail = NULL;
													fieldListHead = NULL;
													typeFieldCount = 0;
												}
break;
case 9:
#line 101 "ast.y"
	{ yyval.TTNode = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); }
break;
case 10:
#line 104 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[-1].FLNode;
												}
break;
case 11:
#line 110 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = 0;
													fieldListHead = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[0].FLNode;
				 								}
break;
case 12:
#line 118 "ast.y"
	{ 
													yyval.FLNode = FLCreateNode(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-2].TTNode); 
													++typeFieldCount;
												}
break;
case 13:
#line 124 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 14:
#line 125 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 15:
#line 126 "ast.y"
	{ yyval.TTNode = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 16:
#line 131 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 17:
#line 132 "ast.y"
	{}
break;
case 27:
#line 139 "ast.y"
	{ ++statementCount; }
break;
case 28:
#line 142 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 29:
#line 145 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 30:
#line 148 "ast.y"
	{ 
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
												}
break;
case 31:
#line 152 "ast.y"
	{	 
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
												}
break;
case 32:
#line 157 "ast.y"
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
#line 167 "ast.y"
	{
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);
												}
break;
case 34:
#line 179 "ast.y"
	{}
break;
case 35:
#line 182 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 36:
#line 187 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 37:
#line 188 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 38:
#line 191 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 39:
#line 194 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 40:
#line 197 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 41:
#line 200 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 42:
#line 203 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 43:
#line 208 "ast.y"
	{
												GSTPrint(); 
												printTypeTable();					
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 44:
#line 214 "ast.y"
	{}
break;
case 45:
#line 217 "ast.y"
	{}
break;
case 46:
#line 218 "ast.y"
	{}
break;
case 47:
#line 221 "ast.y"
	{}
break;
case 48:
#line 222 "ast.y"
	{ 
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												FLPrint(yystack.l_mark[-3].TTNode);

												fieldListTail = NULL;
												fieldListHead = NULL;
												tupleFieldCount = 0;
											}
break;
case 49:
#line 235 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 50:
#line 236 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 51:
#line 237 "ast.y"
	{ 
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {
													printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}
			 								}
break;
case 52:
#line 244 "ast.y"
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
#line 254 "ast.y"
	{}
break;
case 54:
#line 255 "ast.y"
	{}
break;
case 55:
#line 258 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, currentGDeclType->size, NULL); }
break;
case 56:
#line 259 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 57:
#line 266 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 58:
#line 272 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 59:
#line 279 "ast.y"
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
#line 292 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 297 "ast.y"
	{ 
																	yyval.FLNode = yystack.l_mark[-1].FLNode; 
																	currentGDeclType->size = tupleFieldCount;
																}
break;
case 62:
#line 303 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[-2].FLNode;
																}
break;
case 63:
#line 309 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = 0;
																	fieldListHead = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[0].FLNode;
																}
break;
case 64:
#line 317 "ast.y"
	{
																	yyval.FLNode = FLCreateNode(yystack.l_mark[0].node->nodeName, yystack.l_mark[-1].TTNode);
																	++tupleFieldCount;
																}
break;
case 65:
#line 323 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 66:
#line 324 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 67:
#line 327 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 345 "ast.y"
	{}
break;
case 69:
#line 346 "ast.y"
	{}
break;
case 70:
#line 347 "ast.y"
	{}
break;
case 71:
#line 350 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 72:
#line 356 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 73:
#line 357 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 74:
#line 358 "ast.y"
	{  }
break;
case 75:
#line 359 "ast.y"
	{  }
break;
case 76:
#line 360 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 77:
#line 369 "ast.y"
	{ yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 78:
#line 370 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 79:
#line 371 "ast.y"
	{}
break;
case 80:
#line 374 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 380 "ast.y"
	{}
break;
case 82:
#line 381 "ast.y"
	{}
break;
case 83:
#line 384 "ast.y"
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
#line 395 "ast.y"
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
#line 413 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 86:
#line 419 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 87:
#line 420 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 88:
#line 421 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 89:
#line 422 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 90:
#line 423 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 91:
#line 426 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 93:
#line 436 "ast.y"
	{  
											/* printTupleList();*/
										}
break;
case 94:
#line 439 "ast.y"
	{}
break;
case 95:
#line 442 "ast.y"
	{}
break;
case 96:
#line 443 "ast.y"
	{}
break;
case 97:
#line 446 "ast.y"
	{}
break;
case 98:
#line 449 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 99:
#line 450 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 100:
#line 451 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 101:
#line 460 "ast.y"
	{}
break;
case 102:
#line 461 "ast.y"
	{}
break;
case 103:
#line 464 "ast.y"
	{ LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, 1); }
break;
case 104:
#line 465 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 105:
#line 472 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 106:
#line 488 "ast.y"
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
#line 507 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 108:
#line 510 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 112:
#line 525 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 113:
#line 531 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 114:
#line 538 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 115:
#line 544 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 116:
#line 545 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 117:
#line 555 "ast.y"
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
#line 582 "ast.y"
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
case 119:
#line 612 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 120:
#line 613 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 121:
#line 621 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 122:
#line 622 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 123:
#line 623 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 124:
#line 624 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 125:
#line 625 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 126:
#line 626 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 127:
#line 627 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 128:
#line 628 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 129:
#line 629 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 130:
#line 630 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 131:
#line 631 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 132:
#line 632 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 133:
#line 633 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 134:
#line 634 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 135:
#line 635 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 136:
#line 636 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 137:
#line 637 "ast.y"
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
case 138:
#line 657 "ast.y"
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
#line 666 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 140:
#line 674 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 141:
#line 682 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 142:
#line 686 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 143:
#line 687 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 144:
#line 688 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1708 "y.tab.c"
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
