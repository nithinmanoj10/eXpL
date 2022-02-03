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
#define SEMICOLON 293
#define COMMA 294
#define DOT 295
#define EQ 296
#define NEQ 297
#define LT 298
#define LTE 299
#define GT 300
#define GTE 301
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,   27,   27,   31,   31,   32,   24,   26,
   26,   25,   23,   23,   23,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    3,    4,    5,    5,
    5,   17,   16,    6,    6,   11,   12,   13,   14,   15,
   28,   28,   33,   33,   34,   35,   35,   36,   36,   37,
   37,   37,   37,   37,   22,   38,   38,   38,   40,   40,
   40,   40,   39,   21,   21,   21,   20,   29,   29,    9,
   41,   42,   44,   44,   44,   44,   19,   43,   43,   45,
   45,   46,   46,   49,   49,   50,   51,   51,    8,   47,
   47,   47,   48,   48,    7,   52,   52,   30,   53,   18,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,
};
static const YYINT yylen[] = {                            2,
    4,    3,    2,    3,    0,    2,    1,    4,    1,    2,
    1,    3,    1,    1,    1,    3,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    2,    3,    6,
    4,    1,    3,    7,    5,    5,    5,    1,    1,    1,
    3,    2,    2,    1,    3,    1,    1,    3,    1,    1,
    4,    4,    1,    4,    2,    3,    1,    0,    1,    1,
    2,    2,    2,    3,    1,    0,    1,    2,    1,    1,
    5,    5,    1,    1,    2,    2,    5,    3,    2,    2,
    1,    3,    6,    3,    1,    2,    1,    1,    1,    1,
    1,    2,    3,    1,    1,    1,    2,    7,    2,    5,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    3,    3,    4,    4,    2,    2,
    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    9,    0,    0,    7,    0,    0,    0,
    4,    6,   42,   46,   47,    0,   44,    0,    0,    0,
    0,    2,   69,    0,    0,    0,   15,   13,   14,    0,
   11,    0,   41,   43,    0,    0,    0,    0,   49,   99,
   75,   76,    1,   68,    0,   70,    0,    0,    0,    8,
   10,    0,    0,   55,    0,   45,    0,    0,    0,    0,
    0,   12,    0,    0,    0,    0,   57,    0,    0,   48,
   79,   90,   91,    0,    0,   81,    0,    0,    0,    0,
    0,   51,   61,   62,    0,   52,   63,   54,   95,   92,
   78,   80,   96,    0,    0,    0,   94,    0,    0,    0,
    0,   40,    0,    0,    0,   38,   39,    0,    0,   18,
   19,   20,   21,   22,   23,   24,   25,   26,   71,   72,
    0,   56,   97,   87,   88,    0,   85,    0,   82,    0,
    0,    0,    0,  122,  123,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   17,    0,
    0,    0,    0,   89,   86,   93,    0,    0,    0,    0,
    0,  120,  119,  114,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   16,    0,    0,   98,   84,    0,
    0,    0,    0,   65,    0,  116,  115,    0,    0,  103,
  104,  105,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   33,   77,    0,   83,    0,  118,
    0,  117,    0,   35,   36,   37,    0,    0,   64,    0,
  100,   34,
};
static const YYINT yydgoto[] = {                          2,
  108,  109,  110,  111,  112,  113,   90,  155,   47,  193,
  114,  115,  116,  117,  118,  148,  184,  151,   79,  194,
  195,   37,   30,    5,   31,   32,    3,    9,   21,   22,
    6,    7,   16,   17,   18,   38,   39,   66,   67,   68,
   23,   24,   59,   25,   75,   76,   77,   96,  126,  127,
  128,   97,   26,
};
static const YYINT yysindex[] = {                      -257,
 -228,    0, -256,    0,  -90, -244,    0, -209, -265, -249,
    0,    0,    0,    0,    0, -192,    0, -240, -239, -224,
 -265,    0,    0,  -70, -202,   43,    0,    0,    0, -195,
    0, -119,    0,    0,  -37, -133,   88, -243,    0,    0,
    0,    0,    0,    0, -162,    0,   89,   90, -159,    0,
    0, -123, -225,    0, -225,    0, -240, -230, -121, -225,
   17,    0,   50, -122, -120,  -40,    0, -113,  -32,    0,
    0,    0,    0, -111, -196,    0,  -38,  452,   29,  -31,
 -162,    0,    0,    0, -225,    0,    0,    0,    0,    0,
    0,    0,    0, -102, -213, -208,    0,  -87,  235,  235,
 -101,    0,  235,  235,  452,    0,    0,  362, -136,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -100,    0,    0,    0,    0,  -30,    0,  -99,    0, -235,
  235,  235,  -25,    0,    0,  -98,  -96,  235,  235,  280,
  280, -109, -194,  -92,  466,  235, -130,  -97,    0,  452,
   40, -213, -235,    0,    0,    0,  280,  -86,  235,  235,
  -91,    0,    0,    0,  149,  235,  235,  235,  235,  235,
  235,  235,  235,  235,  235,  235,  235,  235,  235,  452,
  452,  235,  280, -126,    0, -108,  362,    0,    0, -182,
  -85,  211,  280,    0,  -27,    0,    0, -168, -168,    0,
    0,    0,  271,  317, -231, -231, -220, -220, -220, -220,
  280,  383,  407, -148,    0,    0,  -89,    0,  235,    0,
  235,    0,  452,    0,    0,    0, -106,  280,    0,  428,
    0,    0,
};
static const YYINT yyrindex[] = {                       -84,
    0,    0,    0,    0,    0,    0,    0,    0,  189,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -66,  -62,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -180,    0, -171,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -23,    0,  -23,    0,    0,    0,    0,  -23,
    0,    0,    0,  -61,  -60,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -41,    0,    0,    0,    0,    0,    0,  -76,
  -75,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -73,    0,    0,  -22,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -63,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -21,    0,    0,    0,    0,  -15,   22,    0,
    0,    0,  181,   85,   15,  175,   48,   75,  101,  128,
  -59,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -57,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -93, -103,    0,    0,    0,    0,    0,    0,    0,  384,
    0,    0,    0,    0,    0,   13,    0,    0,    0,  -20,
    0,    0,    0,    0,  170,    0,    0,    0,    0,  202,
    0,  225,    0,  216,    0,    0,  176,  -16,  152,    0,
  217,    0,  160,    0,    0,  167,    0,   92,    0,   94,
    0,  117,    0,
};
#define YYTABLESIZE 749
static const YYINT yytable[] = {                        121,
   86,   95,   53,  132,  147,   50,  191,   27,   88,  120,
  153,  145,    4,  222,  160,    1,   35,   58,   66,   67,
  161,   93,   40,   19,   20,  101,   36,   41,    4,   11,
    8,   94,   10,  166,  167,  168,  169,  170,   69,   28,
   29,  147,   42,   80,  166,  167,  168,  169,  170,   56,
   57,  121,   45,   52,   46,  106,  187,   71,   72,   73,
   74,   49,  102,   64,   65,  159,  175,  176,  177,  178,
  166,  167,  168,  169,  170,  124,  125,  101,   13,   14,
   15,  180,   48,  147,  129,  130,  212,  213,  108,  171,
  172,   91,   72,   73,   74,   33,   14,   15,  168,  169,
  170,  173,  174,  175,  176,  177,  178,  106,  147,  147,
  218,  130,   50,   50,  102,  109,  166,  167,  168,  169,
  170,   53,   53,   54,   58,  113,  147,   55,   60,  230,
   61,  181,  226,   62,   63,  171,  172,   27,   78,   81,
  108,  110,   82,   87,   83,   89,   84,  173,  174,  175,
  176,  177,  178,  119,  123,  142,  149,  154,  162,  150,
  163,  179,  185,  186,  188,  196,  215,  109,  111,   28,
   29,  227,  166,  167,  168,  169,  170,  113,  166,  167,
  168,  169,  170,  131,  216,  219,  231,  181,    3,  197,
   73,  171,  172,  110,   74,   59,   60,  171,  172,  217,
  229,   51,    5,  173,  174,  175,  176,  177,  178,  173,
  174,  175,  176,  177,  178,  107,   27,   28,   93,   29,
  111,  112,   43,  121,  121,  121,  121,  121,   94,   32,
   12,   34,   70,   31,  121,   30,  122,   44,  121,  121,
  121,   92,  121,  121,  190,  189,  156,    0,    0,  101,
  101,  121,  121,   85,  121,  121,  121,  121,  121,  121,
  101,   85,   85,  152,  101,  101,  221,  107,  101,  101,
   58,   66,   67,  112,  139,    0,    0,  101,  101,    0,
  101,  101,  101,  101,  101,  101,  102,  102,    0,    0,
  106,    0,    0,    0,  106,  106,    0,  102,  106,  106,
    0,  102,  102,  220,    0,  102,  102,  106,  106,    0,
  106,  106,    0,    0,  102,  102,    0,  102,  102,  102,
  102,  102,  102,  108,    0,    0,    0,  108,  108,    0,
    0,  108,  108,    0,    0,    0,    0,    0,    0,    0,
  108,  108,    0,  108,  108,  108,  108,  108,  108,    0,
  109,    0,    0,    0,  109,  109,    0,    0,  109,  109,
  113,    0,    0,    0,  113,  113,    0,  109,  109,  113,
  109,  109,  109,  109,  109,  109,  110,  113,  113,    0,
  110,  110,    0,    0,  110,  110,    0,    0,    0,    0,
    0,    0,    0,  110,  110,    0,  110,  110,  110,  110,
  110,  110,    0,  111,    0,    0,    0,  111,  111,    0,
    0,  111,  111,  166,  167,  168,  169,  170,    0,    0,
  111,  111,    0,  111,  111,  111,  111,  111,  111,    0,
    0,    0,  171,  172,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  173,  174,  175,  176,  177,  178,
  107,    0,    0,    0,  107,  107,  112,    0,  107,  107,
  112,  112,    0,    0,  112,  112,    0,  107,  107,    0,
  107,  107,    0,  112,  112,  166,  167,  168,  169,  170,
    0,    0,  140,  141,    0,    0,  143,  144,    0,    0,
    0,  133,  134,  135,  171,  172,    0,    0,    0,    0,
    0,  136,    0,    0,  137,    0,  173,  174,  175,  176,
  177,  178,    0,    0,  157,  158,    0,    0,    0,    0,
  138,  164,  165,    0,    0,    0,    0,    0,    0,  183,
    0,    0,    0,    0,    0,  166,  167,  168,  169,  170,
    0,    0,  192,    0,  166,  167,  168,  169,  170,  198,
  199,  200,  201,  202,  203,  204,  205,  206,  207,  208,
  209,  210,  211,  171,  172,  214,  173,  174,  175,  176,
  177,  178,    0,    0,    0,  173,  174,  175,  176,  177,
  178,  166,  167,  168,  169,  170,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  171,    0,  228,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  173,  174,  175,  176,  177,  178,   98,    0,
    0,    0,    0,    0,   99,  100,    0,    0,  101,    0,
    0,    0,    0,  102,    0,    0,  103,    0,    0,   98,
  104,  105,    0,  106,  107,   99,  100,    0,    0,  101,
    0,    0,    0,  146,  102,    0,    0,  103,    0,  223,
  224,  104,  105,   98,  106,  107,    0,    0,    0,   99,
  100,    0,    0,  101,    0,    0,    0,    0,  102,    0,
    0,  103,    0,    0,   98,  104,  105,  225,  106,  107,
   99,  100,    0,    0,  101,    0,    0,    0,    0,  102,
    0,    0,  103,    0,    0,  232,  104,  105,   98,  106,
  107,    0,    0,    0,   99,  100,    0,    0,  101,    0,
    0,    0,   98,  102,    0,    0,  103,    0,   99,  100,
  104,  105,  101,  106,  107,    0,    0,  102,    0,    0,
  103,    0,    0,    0,  182,  105,    0,  106,  107,
};
static const YYINT yycheck[] = {                         41,
   41,   40,   40,   91,  108,  125,   93,  257,   41,   41,
   41,  105,  257,   41,   40,  273,  257,   41,   41,   41,
   46,  257,  262,  289,  290,   41,  267,  267,  257,  274,
  287,  267,  123,  265,  266,  267,  268,  269,   55,  289,
  290,  145,  267,   60,  265,  266,  267,  268,  269,  293,
  294,   93,  123,   91,  257,   41,  150,  288,  289,  290,
  291,  257,   41,  289,  290,   91,  298,  299,  300,  301,
  265,  266,  267,  268,  269,  289,  290,   93,  288,  289,
  290,  276,   40,  187,  293,  294,  180,  181,   41,  284,
  285,  288,  289,  290,  291,  288,  289,  290,  267,  268,
  269,  296,  297,  298,  299,  300,  301,   93,  212,  213,
  293,  294,  293,  294,   93,   41,  265,  266,  267,  268,
  269,  293,  294,  257,  287,   41,  230,   40,   40,  223,
   41,  280,  281,  293,  258,  284,  285,  257,  260,  123,
   93,   41,   93,  257,  267,  257,  267,  296,  297,  298,
  299,  300,  301,  125,  257,  257,  293,  257,  257,  260,
  257,  271,  293,  261,  125,  257,  293,   93,   41,  289,
  290,  261,  265,  266,  267,  268,  269,   93,  265,  266,
  267,  268,  269,  271,  293,  271,  293,  280,    0,   41,
  257,  284,  285,   93,  257,  257,  257,  284,  285,  187,
  221,   32,  287,  296,  297,  298,  299,  300,  301,  296,
  297,  298,  299,  300,  301,   41,  293,  293,  257,  293,
   93,   41,   21,  265,  266,  267,  268,  269,  267,  293,
    6,   16,   57,  293,  276,  293,   85,   21,  280,  281,
   81,   75,  284,  285,  153,  152,  130,   -1,   -1,  265,
  266,  293,  294,  294,  296,  297,  298,  299,  300,  301,
  276,  294,  294,  294,  280,  281,  294,   93,  284,  285,
  294,  294,  294,   93,   40,   -1,   -1,  293,  294,   -1,
  296,  297,  298,  299,  300,  301,  265,  266,   -1,   -1,
  276,   -1,   -1,   -1,  280,  281,   -1,  276,  284,  285,
   -1,  280,  281,   93,   -1,  284,  285,  293,  294,   -1,
  296,  297,   -1,   -1,  293,  294,   -1,  296,  297,  298,
  299,  300,  301,  276,   -1,   -1,   -1,  280,  281,   -1,
   -1,  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  293,  294,   -1,  296,  297,  298,  299,  300,  301,   -1,
  276,   -1,   -1,   -1,  280,  281,   -1,   -1,  284,  285,
  276,   -1,   -1,   -1,  280,  281,   -1,  293,  294,  285,
  296,  297,  298,  299,  300,  301,  276,  293,  294,   -1,
  280,  281,   -1,   -1,  284,  285,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  293,  294,   -1,  296,  297,  298,  299,
  300,  301,   -1,  276,   -1,   -1,   -1,  280,  281,   -1,
   -1,  284,  285,  265,  266,  267,  268,  269,   -1,   -1,
  293,  294,   -1,  296,  297,  298,  299,  300,  301,   -1,
   -1,   -1,  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  296,  297,  298,  299,  300,  301,
  276,   -1,   -1,   -1,  280,  281,  276,   -1,  284,  285,
  280,  281,   -1,   -1,  284,  285,   -1,  293,  294,   -1,
  296,  297,   -1,  293,  294,  265,  266,  267,  268,  269,
   -1,   -1,   99,  100,   -1,   -1,  103,  104,   -1,   -1,
   -1,  257,  258,  259,  284,  285,   -1,   -1,   -1,   -1,
   -1,  267,   -1,   -1,  270,   -1,  296,  297,  298,  299,
  300,  301,   -1,   -1,  131,  132,   -1,   -1,   -1,   -1,
  286,  138,  139,   -1,   -1,   -1,   -1,   -1,   -1,  146,
   -1,   -1,   -1,   -1,   -1,  265,  266,  267,  268,  269,
   -1,   -1,  159,   -1,  265,  266,  267,  268,  269,  166,
  167,  168,  169,  170,  171,  172,  173,  174,  175,  176,
  177,  178,  179,  284,  285,  182,  296,  297,  298,  299,
  300,  301,   -1,   -1,   -1,  296,  297,  298,  299,  300,
  301,  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  284,   -1,  219,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  296,  297,  298,  299,  300,  301,  257,   -1,
   -1,   -1,   -1,   -1,  263,  264,   -1,   -1,  267,   -1,
   -1,   -1,   -1,  272,   -1,   -1,  275,   -1,   -1,  257,
  279,  280,   -1,  282,  283,  263,  264,   -1,   -1,  267,
   -1,   -1,   -1,  292,  272,   -1,   -1,  275,   -1,  277,
  278,  279,  280,  257,  282,  283,   -1,   -1,   -1,  263,
  264,   -1,   -1,  267,   -1,   -1,   -1,   -1,  272,   -1,
   -1,  275,   -1,   -1,  257,  279,  280,  281,  282,  283,
  263,  264,   -1,   -1,  267,   -1,   -1,   -1,   -1,  272,
   -1,   -1,  275,   -1,   -1,  278,  279,  280,  257,  282,
  283,   -1,   -1,   -1,  263,  264,   -1,   -1,  267,   -1,
   -1,   -1,  257,  272,   -1,   -1,  275,   -1,  263,  264,
  279,  280,  267,  282,  283,   -1,   -1,  272,   -1,   -1,
  275,   -1,   -1,   -1,  279,  280,   -1,  282,  283,
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
0,0,0,0,0,0,"'('","')'",0,0,0,0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID",
"NUM","STRING","BEGIN_","END","MAIN","READ","WRITE","PLUS","MINUS","MUL","DIV",
"MOD","AMPERSAND","EQUAL","BREAKPOINT","TYPE","ENDTYPE","IF","THEN","ELSE",
"ENDIF","WHILE","DO","ENDWHILE","BREAK","CONTINUE","AND","OR","NOT","DECL",
"ENDDECL","INT","STR","TUPLE","RETURN","SEMICOLON","COMMA","DOT","EQ","NEQ",
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
"FieldDecl : TypeName ID SEMICOLON",
"TypeName : INT",
"TypeName : STR",
"TypeName : ID",
"Slist : Slist Stmt SEMICOLON",
"Slist : Stmt SEMICOLON",
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
"retStmt : RETURN retVal SEMICOLON",
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
"GDecl : Type GIDList SEMICOLON",
"Type : INT",
"Type : STR",
"GIDList : GIDList COMMA GID",
"GIDList : GID",
"GID : ID",
"GID : ID '[' NUM ']'",
"GID : ID '(' ParamList ')'",
"GID : GPtrID",
"GID : GPtrID '(' ParamList ')'",
"GPtrID : MUL ID",
"ParamList : ParamList COMMA Param",
"ParamList : Param",
"ParamList :",
"ParamType : INT",
"ParamType : STR",
"ParamType : INT MUL",
"ParamType : STR MUL",
"Param : ParamType ID",
"ArgList : ArgList COMMA Arg",
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
"FBody : BEGIN_ Slist retStmt END SEMICOLON",
"LDeclBlock : DECL LDeclList ENDDECL",
"LDeclBlock : DECL ENDDECL",
"LDeclList : LDeclList LDecl",
"LDeclList : LDecl",
"LDecl : LType LIDList SEMICOLON",
"LDecl : LType '(' TupleFieldList ')' LIDList SEMICOLON",
"TupleFieldList : TupleFieldList COMMA TupleField",
"TupleFieldList : TupleField",
"TupleField : TupleFieldType TupleFieldID",
"TupleFieldType : INT",
"TupleFieldType : STR",
"TupleFieldID : ID",
"LType : INT",
"LType : STR",
"LType : TUPLE TupleID",
"LIDList : LIDList COMMA LID",
"LIDList : LID",
"TupleID : ID",
"LID : ID",
"LID : MUL ID",
"MainBlock : MainFunc '(' ')' '{' LDeclBlock MBody '}'",
"MainFunc : INT MAIN",
"MBody : BEGIN_ Slist retStmt END SEMICOLON",
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
#line 511 "ast.y"

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
#line 183 "ast.y"
	{ 
											/* GSTPrint();*/

											int freeStackMem = getFreeStackMemoryValue();
											fprintf(filePtr, "MOV SP, %d\n", freeStackMem - 1);
											fprintf(filePtr, "MOV BP, %d\n", freeStackMem);
											fprintf(filePtr, "PUSH R0\n");
											fprintf(filePtr, "CALL F0\n");
											fprintf(filePtr, "INT 10\n");
										}
break;
case 42:
#line 193 "ast.y"
	{}
break;
case 43:
#line 196 "ast.y"
	{}
break;
case 44:
#line 197 "ast.y"
	{}
break;
case 45:
#line 200 "ast.y"
	{}
break;
case 46:
#line 203 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 47:
#line 204 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 48:
#line 207 "ast.y"
	{}
break;
case 49:
#line 208 "ast.y"
	{}
break;
case 50:
#line 211 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1, NULL); }
break;
case 51:
#line 212 "ast.y"
	{ 
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), yystack.l_mark[-1].node->intConstVal, NULL); 
										}
break;
case 52:
#line 219 "ast.y"
	{ 
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), -1, getParamListHead());
											flushParamList();
											paramCount = 0;
											setParamType(TYPE_VOID);
										}
break;
case 53:
#line 225 "ast.y"
	{
											if (getDeclarationType() == TYPE_INT)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1, NULL);

											if (getDeclarationType() == TYPE_STR)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1, NULL);
										}
break;
case 54:
#line 232 "ast.y"
	{
												if (getDeclarationType() == TYPE_INT)
												GSTInstall(yystack.l_mark[-3].node->nodeName, TYPE_INT_PTR, -1, getParamListHead());

												if (getDeclarationType() == TYPE_STR)
													GSTInstall(yystack.l_mark[-3].node->nodeName, TYPE_STR_PTR, -1, getParamListHead());

												flushParamList();
												paramCount = 0;
												setParamType(TYPE_VOID);
											}
break;
case 55:
#line 244 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 56:
#line 250 "ast.y"
	{}
break;
case 57:
#line 251 "ast.y"
	{}
break;
case 58:
#line 252 "ast.y"
	{}
break;
case 59:
#line 255 "ast.y"
	{ setParamType(TYPE_INT); }
break;
case 60:
#line 256 "ast.y"
	{ setParamType(TYPE_STR); }
break;
case 61:
#line 257 "ast.y"
	{ setParamType(TYPE_INT_PTR); }
break;
case 62:
#line 258 "ast.y"
	{ setParamType(TYPE_STR_PTR); }
break;
case 63:
#line 261 "ast.y"
	{ 
											paramListInstall(getParamType(), yystack.l_mark[0].node->nodeName); 
											++paramCount;
										}
break;
case 64:
#line 270 "ast.y"
	{ 
											yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node);
										}
break;
case 65:
#line 273 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 66:
#line 274 "ast.y"
	{}
break;
case 67:
#line 277 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node; 
											/* ++argCount;*/
										}
break;
case 68:
#line 286 "ast.y"
	{}
break;
case 69:
#line 287 "ast.y"
	{}
break;
case 70:
#line 290 "ast.y"
	{ 
															if(GSTLookup(yystack.l_mark[0].node->nodeName) == NULL){
																printf("\nFunction %s is not declared\n", yystack.l_mark[0].node->nodeName);
																exit(1);
															}
															yyval.node = yystack.l_mark[0].node; 
															setCurrentFuncName(yystack.l_mark[0].node->nodeName);
														}
break;
case 71:
#line 301 "ast.y"
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
case 72:
#line 317 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 73:
#line 323 "ast.y"
	{ setFuncType(TYPE_INT); }
break;
case 74:
#line 324 "ast.y"
	{ setFuncType(TYPE_STR); }
break;
case 75:
#line 325 "ast.y"
	{ setFuncType(TYPE_INT_PTR); }
break;
case 76:
#line 326 "ast.y"
	{ setFuncType(TYPE_STR_PTR); }
break;
case 77:
#line 329 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 78:
#line 338 "ast.y"
	{ 
											/* LSTPrint(); */
											/* printTupleList();*/
										}
break;
case 79:
#line 342 "ast.y"
	{}
break;
case 80:
#line 345 "ast.y"
	{}
break;
case 81:
#line 346 "ast.y"
	{}
break;
case 82:
#line 349 "ast.y"
	{}
break;
case 83:
#line 350 "ast.y"
	{ 
																	struct TupleList* currentTupleList = getTuple(getCurrentTupleID());
																	currentTupleList->tupleFieldListHead = tupleFieldListHead;
																	/* printTupleFieldList();*/
																	flushTupleFieldList();
																	/* printTupleTypeTable();*/
																	flushTupleFieldCount();		
																}
break;
case 84:
#line 360 "ast.y"
	{}
break;
case 85:
#line 361 "ast.y"
	{}
break;
case 86:
#line 364 "ast.y"
	{ 
													incTupleFieldCount(); 
													insertTupleField(yystack.l_mark[0].node->nodeName, getTupleFieldType());
												}
break;
case 87:
#line 370 "ast.y"
	{ setTupleFieldType(TYPE_INT); }
break;
case 88:
#line 371 "ast.y"
	{ setTupleFieldType(TYPE_STR); }
break;
case 89:
#line 374 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 90:
#line 377 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 91:
#line 378 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 92:
#line 379 "ast.y"
	{ 
											setCurrentTupleID(yystack.l_mark[0].node->nodeName);	
											insertTuple(yystack.l_mark[0].node->nodeName);			
											struct TupleTypeTable* newTTTNode = insertTupleType(yystack.l_mark[0].node->nodeName);
											setDeclarationType(newTTTNode->tupleTypeNum);
							 			}
break;
case 93:
#line 387 "ast.y"
	{}
break;
case 94:
#line 388 "ast.y"
	{}
break;
case 95:
#line 391 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node;
										}
break;
case 96:
#line 396 "ast.y"
	{ 
											if (getTupleFieldCount() == 0)		/* For non-tuples*/
												LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1); 
											else 								/* For Tuples*/
												LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), getTupleFieldCount()); 
										}
break;
case 97:
#line 402 "ast.y"
	{
											if(getDeclarationType() == TYPE_INT)
												LSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1);	

											if(getDeclarationType() == TYPE_STR)
												LSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1);	
										}
break;
case 98:
#line 418 "ast.y"
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
case 99:
#line 435 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 100:
#line 438 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 101:
#line 446 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 102:
#line 447 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 103:
#line 448 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 104:
#line 449 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 105:
#line 450 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 106:
#line 451 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 107:
#line 452 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 108:
#line 453 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 109:
#line 454 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 110:
#line 455 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 111:
#line 456 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 112:
#line 457 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, AND_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 113:
#line 458 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, OR_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 114:
#line 459 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NOT_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 115:
#line 460 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 116:
#line 461 "ast.y"
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
case 117:
#line 470 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, 0, NULL, NULL, NULL, NULL); 
										yyval.node->argListHead = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 118:
#line 477 "ast.y"
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
case 119:
#line 486 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->dataType == TYPE_INT || yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT_PTR, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR || yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR_PTR, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 120:
#line 494 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 121:
#line 502 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 122:
#line 506 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 123:
#line 507 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1484 "y.tab.c"
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
