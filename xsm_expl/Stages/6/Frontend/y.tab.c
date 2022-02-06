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
#define RETURN 291
#define EQ 292
#define NEQ 293
#define LT 294
#define LTE 295
#define GT 296
#define GTE 297
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,   27,   27,   31,   31,   32,   23,   26,
   26,   25,   22,   22,   22,    1,    1,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    3,    4,    5,    5,
    5,   15,   14,    6,    6,    9,   10,   11,   12,   13,
   28,   28,   33,   33,   34,   24,   24,   24,   35,   35,
   36,   36,   36,   36,   36,   20,   37,   37,   37,   38,
   39,   39,   39,   39,   39,   19,   19,   19,   18,   29,
   29,    7,   40,   41,   43,   43,   43,   43,   17,   42,
   42,   44,   44,   45,   46,   46,   46,   47,   47,   48,
   48,   30,   49,   16,   21,   21,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,
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
    2,    2,    1,    3,    1,    1,    1,    3,    1,    1,
    2,    7,    2,    5,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    3,    1,    4,    4,    2,    2,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    9,    0,    0,    7,    0,    0,    0,
    4,    6,   48,   42,   46,   47,    0,    0,   44,    0,
    0,    0,    2,   71,    0,    0,    0,   15,   13,   14,
    0,   11,    0,    0,    0,    0,    0,   50,   41,   43,
   93,   77,   78,    1,   70,    0,   72,    0,    0,    0,
    8,   10,    0,    0,   56,    0,   45,    0,    0,    0,
    0,    0,   12,    0,   65,    0,    0,    0,   58,    0,
    0,   49,   87,   81,   85,   86,    0,   83,    0,    0,
    0,    0,    0,   52,   63,   64,    0,   53,   60,   55,
   80,   82,   90,    0,    0,   89,    0,    0,    0,    0,
   40,    0,    0,    0,   38,   39,    0,    0,   18,   19,
   20,   21,   22,   23,   24,   25,   26,   73,   74,    0,
   57,   91,   84,    0,    0,    0,    0,  118,  119,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,    0,    0,   88,    0,    0,    0,
    0,    0,  116,  115,  110,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   16,    0,    0,   92,
    0,    0,    0,   67,    0,   96,  111,    0,    0,   99,
  100,  101,    0,    0,    0,    0,    0,    0,    0,    0,
   95,    0,    0,    0,    0,   33,   79,    0,    0,  114,
    0,  113,    0,   35,   36,   37,    0,    0,   66,    0,
   94,   34,
};
static const YYINT yydgoto[] = {                          2,
  107,  108,  109,  110,  111,  112,   48,  183,  113,  114,
  115,  116,  117,  143,  176,  146,   81,  184,  185,   36,
  135,   31,    5,   17,   32,   33,    3,    9,   22,   23,
    6,    7,   18,   19,   37,   38,   68,   69,   70,   24,
   25,   60,   26,   77,   78,   79,   95,   96,   27,
};
static const YYINT yysindex[] = {                      -259,
 -213,    0, -238,    0,  -72, -246,    0, -228, -165, -186,
    0,    0,    0,    0,    0,    0, -245, -224,    0, -242,
 -199, -165,    0,    0,    5, -169,   60,    0,    0,    0,
 -163,    0, -118,  -32, -128,   90,  -29,    0,    0,    0,
    0,    0,    0,    0,    0, -156,    0,   92,   95,   81,
    0,    0, -115, -184,    0, -184,    0, -245, -214, -116,
 -184,   23,    0,   58,    0, -119, -108,  -18,    0,  -93,
   -4,    0,    0,    0,    0,    0, -210,    0, -240,  418,
   41,   12, -156,    0,    0,    0, -184,    0,    0,    0,
    0,    0,    0,  -90,  -28,    0,  -89,  150,  150,  -87,
    0,  150,  150,  418,    0,    0, -130,  109,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -81,
    0,    0,    0, -240,  150,  150,  -36,    0,    0,  -76,
  -70,  150,  150,  294,  142,  294,  -82,  252,  273,  432,
  150,  132,  -67,    0,  418,   70,    0,  294,  -92,  150,
  150,  -61,    0,    0,    0,   97,  150,  150,  150,  150,
  150,  150,  150,  150,  150,  150,  150,  150,  150,  -60,
  150,  418,  418,  150,  294,  139,    0,  140, -130,    0,
  -65,  172,  294,    0,   42,    0,    0, -153, -153,    0,
    0,    0,  238,  308, -111, -111, -157, -157, -157, -157,
    0,  294,  349,  373,  230,    0,    0,  -54,  150,    0,
  150,    0,  418,    0,    0,    0,  149,  294,    0,  394,
    0,    0,
};
static const YYINT yyrindex[] = {                       -78,
    0,    0,    0,    0,    0,    0,    0,    0,  210,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -46,
  -44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -25,    0,  -23,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   49,    0,   49,    0,    0,    0,    0,
   49,    0,    0,    0,    0,  -42,  -40,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -41,    0,    0,    0,
    0,    0,    0,  157,  -35,  159,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  160,    0,    0,
   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  161,    0,    0,    0,    0,    0,
    0,    0,   82,    0,    0,    0,    0,   -2,    4,    0,
    0,    0,   -9,   28,  119,  121,   26,   48,   54,   76,
    0,  162,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  163,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -91, -102,    0,    0,    0,    0,    0,  320,    0,    0,
    0,    0,    0,   44,    0,    0,    0,   18,    0,    0,
    0,    0,    0,    0,  203,    0,    0,    0,    0,  215,
    0,  232,    0,  224,    0,  189,  -15,  179,    0,  226,
    0,  185,    0,    0,  196,    0,    0,  153,    0,
};
#define YYTABLESIZE 715
static const YYINT yytable[] = {                        117,
  181,  126,  117,  151,  142,  112,   51,   54,  112,  152,
    4,   34,  140,    1,   58,  124,   93,  117,   51,   41,
   54,   35,   88,  112,   42,   87,   94,   11,   13,   57,
  123,  108,   13,   51,  108,   54,   90,  142,   97,   87,
   71,   97,   73,    4,   98,   82,   73,   98,    8,  108,
   10,  117,  119,  179,  150,   87,   97,  112,   53,   14,
   15,   16,   98,   39,   15,   16,  104,   43,  109,  104,
   28,  109,   65,   74,   75,   76,  142,   91,   75,   76,
  203,  204,  212,  108,  104,  211,  109,   47,  105,   59,
   97,  105,   59,   50,  106,   68,   98,  106,   68,   49,
  142,  142,   29,   30,   66,   67,  105,  157,  158,  159,
  160,  161,  106,  159,  160,  161,  107,  142,  104,  107,
  109,  220,   69,   20,   21,   69,   97,   46,   55,   56,
   59,   61,   98,   99,  107,   62,  100,  187,   28,   63,
  105,  101,   64,   80,  102,   83,  106,   85,  103,  104,
   84,  105,  106,  157,  158,  159,  160,  161,   86,  102,
  141,  103,  102,   89,  103,  118,  122,  144,  107,  137,
   29,   30,  157,  158,  159,  160,  161,  102,  145,  103,
  153,  125,  166,  167,  168,  169,  154,  170,  171,  133,
  177,  162,  163,  178,  180,  186,  201,  206,  207,  164,
  165,  166,  167,  168,  169,  209,  217,  221,    5,    3,
   75,  102,   76,  103,   61,   27,   62,   28,   29,   32,
   31,   30,  208,  117,  117,  117,  117,  117,  219,  112,
  112,  112,  112,  112,  117,   52,   44,   12,  117,  117,
  112,   40,  117,  117,  112,  112,   72,   45,  112,  112,
  117,  117,  117,  117,  117,  117,  112,  112,  112,  112,
  112,  112,   97,   97,  210,  121,  108,  120,   98,   98,
  108,  108,   92,   97,  108,  108,  147,   97,   97,   98,
    0,   97,   97,   98,   98,    0,    0,   98,   98,   97,
   97,   97,   97,   97,   97,   98,   98,   98,   98,   98,
   98,  104,    0,  109,    0,  104,  104,  109,  109,  104,
  104,    0,  109,    0,    0,    0,    0,  104,  104,  104,
  104,  104,  104,  105,    0,    0,    0,  105,  105,  106,
    0,  105,  105,  106,  106,    0,    0,  106,  106,  105,
  105,  105,  105,  105,  105,  106,  106,  106,  106,  106,
  106,  107,    0,    0,    0,  107,  107,    0,    0,  107,
  107,  157,  158,  159,  160,  161,    0,  107,  107,  107,
  107,  107,  107,    0,    0,    0,    0,    0,    0,    0,
  162,  163,    0,    0,    0,    0,    0,    0,  164,  165,
  166,  167,  168,  169,  102,    0,  103,    0,  102,  102,
  103,  103,  102,  102,  103,  103,  127,  128,  129,    0,
  102,  102,  103,  103,    0,    0,  130,  134,  136,  131,
    0,  138,  139,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  132,  157,  158,  159,  160,
  161,    0,    0,    0,  148,  149,    0,    0,    0,    0,
    0,  155,  156,    0,    0,  162,  163,    0,    0,    0,
  175,    0,    0,  164,  165,  166,  167,  168,  169,  182,
    0,    0,    0,    0,    0,    0,  188,  189,  190,  191,
  192,  193,  194,  195,  196,  197,  198,  199,  200,    0,
  202,    0,    0,  205,  157,  158,  159,  160,  161,    0,
    0,    0,  157,  158,  159,  160,  161,    0,    0,  173,
  216,    0,    0,  162,  163,    0,  157,  158,  159,  160,
  161,  164,  165,  166,  167,  168,  169,  172,  218,  164,
  165,  166,  167,  168,  169,  162,  163,  157,  158,  159,
  160,  161,    0,  164,  165,  166,  167,  168,  169,    0,
    0,    0,  173,    0,    0,    0,  162,  163,  157,  158,
  159,  160,  161,    0,  164,  165,  166,  167,  168,  169,
    0,    0,  157,  158,  159,  160,  161,  162,  163,    0,
    0,    0,    0,    0,    0,  164,  165,  166,  167,  168,
  169,  162,    0,    0,    0,    0,    0,    0,    0,  164,
  165,  166,  167,  168,  169,   97,    0,    0,    0,    0,
    0,   98,   99,    0,    0,  100,    0,    0,    0,    0,
  101,    0,    0,  102,    0,  213,  214,  103,  104,   97,
  105,  106,    0,    0,    0,   98,   99,    0,    0,  100,
    0,    0,    0,    0,  101,    0,    0,  102,    0,    0,
   97,  103,  104,  215,  105,  106,   98,   99,    0,    0,
  100,    0,    0,    0,    0,  101,    0,    0,  102,    0,
    0,  222,  103,  104,   97,  105,  106,    0,    0,    0,
   98,   99,    0,    0,  100,    0,    0,    0,   97,  101,
    0,    0,  102,    0,   98,   99,  103,  104,  100,  105,
  106,    0,    0,  101,    0,    0,  102,    0,    0,    0,
  174,  104,    0,  105,  106,
};
static const YYINT yycheck[] = {                         41,
   93,   91,   44,   40,  107,   41,  125,   40,   44,   46,
  257,  257,  104,  273,   44,   44,  257,   59,   44,  262,
   44,  267,   41,   59,  267,   44,  267,  274,  257,   59,
   59,   41,  257,   59,   44,   59,   41,  140,   41,   44,
   56,   44,  257,  257,   41,   61,  257,   44,  287,   59,
  123,   93,   41,  145,   91,   44,   59,   93,   91,  288,
  289,  290,   59,  288,  289,  290,   41,  267,   41,   44,
  257,   44,  257,  288,  289,  290,  179,  288,  289,  290,
  172,  173,   41,   93,   59,   44,   59,  257,   41,   41,
   93,   44,   44,  257,   41,   41,   93,   44,   44,   40,
  203,  204,  289,  290,  289,  290,   59,  265,  266,  267,
  268,  269,   59,  267,  268,  269,   41,  220,   93,   44,
   93,  213,   41,  289,  290,   44,  257,  123,  257,   40,
  287,   40,  263,  264,   59,   41,  267,   41,  257,   59,
   93,  272,  258,  260,  275,  123,   93,  267,  279,  280,
   93,  282,  283,  265,  266,  267,  268,  269,  267,   41,
  291,   41,   44,  257,   44,  125,  257,   59,   93,  257,
  289,  290,  265,  266,  267,  268,  269,   59,  260,   59,
  257,  271,  294,  295,  296,  297,  257,   46,  271,   40,
   59,  284,  285,  261,  125,  257,  257,   59,   59,  292,
  293,  294,  295,  296,  297,  271,  261,   59,  287,    0,
  257,   93,  257,   93,  257,   59,  257,   59,   59,   59,
   59,   59,  179,  265,  266,  267,  268,  269,  211,  265,
  266,  267,  268,  269,  276,   33,   22,    6,  280,  281,
  276,   18,  284,  285,  280,  281,   58,   22,  284,  285,
  292,  293,  294,  295,  296,  297,  292,  293,  294,  295,
  296,  297,  265,  266,   93,   87,  276,   83,  265,  266,
  280,  281,   77,  276,  284,  285,  124,  280,  281,  276,
   -1,  284,  285,  280,  281,   -1,   -1,  284,  285,  292,
  293,  294,  295,  296,  297,  292,  293,  294,  295,  296,
  297,  276,   -1,  276,   -1,  280,  281,  280,  281,  284,
  285,   -1,  285,   -1,   -1,   -1,   -1,  292,  293,  294,
  295,  296,  297,  276,   -1,   -1,   -1,  280,  281,  276,
   -1,  284,  285,  280,  281,   -1,   -1,  284,  285,  292,
  293,  294,  295,  296,  297,  292,  293,  294,  295,  296,
  297,  276,   -1,   -1,   -1,  280,  281,   -1,   -1,  284,
  285,  265,  266,  267,  268,  269,   -1,  292,  293,  294,
  295,  296,  297,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  276,   -1,  276,   -1,  280,  281,
  280,  281,  284,  285,  284,  285,  257,  258,  259,   -1,
  292,  293,  292,  293,   -1,   -1,  267,   98,   99,  270,
   -1,  102,  103,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  265,  266,  267,  268,
  269,   -1,   -1,   -1,  125,  126,   -1,   -1,   -1,   -1,
   -1,  132,  133,   -1,   -1,  284,  285,   -1,   -1,   -1,
  141,   -1,   -1,  292,  293,  294,  295,  296,  297,  150,
   -1,   -1,   -1,   -1,   -1,   -1,  157,  158,  159,  160,
  161,  162,  163,  164,  165,  166,  167,  168,  169,   -1,
  171,   -1,   -1,  174,  265,  266,  267,  268,  269,   -1,
   -1,   -1,  265,  266,  267,  268,  269,   -1,   -1,  280,
  281,   -1,   -1,  284,  285,   -1,  265,  266,  267,  268,
  269,  292,  293,  294,  295,  296,  297,  276,  209,  292,
  293,  294,  295,  296,  297,  284,  285,  265,  266,  267,
  268,  269,   -1,  292,  293,  294,  295,  296,  297,   -1,
   -1,   -1,  280,   -1,   -1,   -1,  284,  285,  265,  266,
  267,  268,  269,   -1,  292,  293,  294,  295,  296,  297,
   -1,   -1,  265,  266,  267,  268,  269,  284,  285,   -1,
   -1,   -1,   -1,   -1,   -1,  292,  293,  294,  295,  296,
  297,  284,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  292,
  293,  294,  295,  296,  297,  257,   -1,   -1,   -1,   -1,
   -1,  263,  264,   -1,   -1,  267,   -1,   -1,   -1,   -1,
  272,   -1,   -1,  275,   -1,  277,  278,  279,  280,  257,
  282,  283,   -1,   -1,   -1,  263,  264,   -1,   -1,  267,
   -1,   -1,   -1,   -1,  272,   -1,   -1,  275,   -1,   -1,
  257,  279,  280,  281,  282,  283,  263,  264,   -1,   -1,
  267,   -1,   -1,   -1,   -1,  272,   -1,   -1,  275,   -1,
   -1,  278,  279,  280,  257,  282,  283,   -1,   -1,   -1,
  263,  264,   -1,   -1,  267,   -1,   -1,   -1,  257,  272,
   -1,   -1,  275,   -1,  263,  264,  279,  280,  267,  282,
  283,   -1,   -1,  272,   -1,   -1,  275,   -1,   -1,   -1,
  279,  280,   -1,  282,  283,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 297
#define YYUNDFTOKEN 349
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
"DECL","ENDDECL","INT","STR","RETURN","EQ","NEQ","LT","LTE","GT","GTE",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"illegal-symbol",
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
#line 535 "ast.y"

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
#line 614 "y.tab.c"

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
#line 60 "ast.y"
	{}
break;
case 2:
#line 61 "ast.y"
	{}
break;
case 3:
#line 62 "ast.y"
	{	
												printf("\n⛔ No Code Provided\n");
												exit(1);
											}
break;
case 4:
#line 71 "ast.y"
	{ printTypeTable(); }
break;
case 6:
#line 75 "ast.y"
	{}
break;
case 7:
#line 76 "ast.y"
	{}
break;
case 8:
#line 80 "ast.y"
	{ 
													FLPrint(yystack.l_mark[-3].TTNode); 
													yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-1].FLNode;
													fieldListTail = NULL;
													fieldListHead = NULL;
												}
break;
case 9:
#line 88 "ast.y"
	{ yyval.TTNode = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); }
break;
case 10:
#line 91 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[-1].FLNode;
												}
break;
case 11:
#line 97 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = 0;
													fieldListHead = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[0].FLNode;
				 								}
break;
case 12:
#line 105 "ast.y"
	{ yyval.FLNode = FLCreateNode(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-2].TTNode); }
break;
case 13:
#line 108 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 14:
#line 109 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 15:
#line 110 "ast.y"
	{ yyval.TTNode = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 16:
#line 115 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 17:
#line 116 "ast.y"
	{}
break;
case 26:
#line 122 "ast.y"
	{ ++statementCount; }
break;
case 27:
#line 125 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 28:
#line 128 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 29:
#line 131 "ast.y"
	{ 
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
												yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
											}
break;
case 30:
#line 135 "ast.y"
	{	 
												yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
												yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
												yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 31:
#line 140 "ast.y"
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
case 32:
#line 154 "ast.y"
	{}
break;
case 33:
#line 157 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 34:
#line 162 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 35:
#line 163 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 36:
#line 166 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 37:
#line 169 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 38:
#line 172 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 39:
#line 175 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 40:
#line 178 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 41:
#line 183 "ast.y"
	{
												GSTPrint(); 					
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 42:
#line 188 "ast.y"
	{}
break;
case 43:
#line 191 "ast.y"
	{}
break;
case 44:
#line 192 "ast.y"
	{}
break;
case 45:
#line 195 "ast.y"
	{}
break;
case 46:
#line 198 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 47:
#line 199 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 48:
#line 200 "ast.y"
	{ 
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {
													printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}
			 								}
break;
case 49:
#line 209 "ast.y"
	{}
break;
case 50:
#line 210 "ast.y"
	{}
break;
case 51:
#line 213 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, currentGDeclType->size, NULL); }
break;
case 52:
#line 214 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 53:
#line 221 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 54:
#line 227 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 55:
#line 234 "ast.y"
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
#line 247 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 57:
#line 252 "ast.y"
	{}
break;
case 58:
#line 253 "ast.y"
	{}
break;
case 59:
#line 254 "ast.y"
	{}
break;
case 60:
#line 257 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 61:
#line 263 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 62:
#line 264 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 63:
#line 265 "ast.y"
	{  }
break;
case 64:
#line 266 "ast.y"
	{  }
break;
case 65:
#line 267 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 66:
#line 275 "ast.y"
	{ 
											yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node);
										}
break;
case 67:
#line 278 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 279 "ast.y"
	{}
break;
case 69:
#line 282 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node; 
											/* ++argCount;*/
										}
break;
case 70:
#line 291 "ast.y"
	{}
break;
case 71:
#line 292 "ast.y"
	{}
break;
case 72:
#line 295 "ast.y"
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
#line 306 "ast.y"
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
case 74:
#line 324 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 75:
#line 330 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 76:
#line 331 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 77:
#line 332 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 78:
#line 333 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 79:
#line 336 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 80:
#line 345 "ast.y"
	{  
											/* printTupleList();*/
										}
break;
case 81:
#line 348 "ast.y"
	{}
break;
case 82:
#line 351 "ast.y"
	{}
break;
case 83:
#line 352 "ast.y"
	{}
break;
case 84:
#line 355 "ast.y"
	{}
break;
case 85:
#line 358 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 86:
#line 359 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 87:
#line 360 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 88:
#line 369 "ast.y"
	{}
break;
case 89:
#line 370 "ast.y"
	{}
break;
case 90:
#line 373 "ast.y"
	{ LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, currentLDeclType->size); }
break;
case 91:
#line 374 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 92:
#line 390 "ast.y"
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
case 93:
#line 409 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 94:
#line 412 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 95:
#line 422 "ast.y"
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
case 96:
#line 448 "ast.y"
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
case 97:
#line 478 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 98:
#line 479 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 99:
#line 480 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 100:
#line 481 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 101:
#line 482 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 102:
#line 483 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 103:
#line 484 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 104:
#line 485 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 105:
#line 486 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 106:
#line 487 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 107:
#line 488 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 108:
#line 489 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 109:
#line 490 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 110:
#line 491 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 111:
#line 492 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 112:
#line 493 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 113:
#line 494 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL); 
										yyval.node->argListHead = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 114:
#line 501 "ast.y"
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
case 115:
#line 510 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 116:
#line 518 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 117:
#line 526 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 118:
#line 530 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 119:
#line 531 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1477 "y.tab.c"
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
