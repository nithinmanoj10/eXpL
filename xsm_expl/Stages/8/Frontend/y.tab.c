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
	#include "../Data_Structures/classTable.h"
	#include "../Data_Structures/memberFuncList.h"
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
	int isFuncDef = 0;
	int globalDeclStartLabel = 0;
	char* fileName;
	FILE* filePtr;
#line 37 "ast.y"
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
	struct ClassTable* CTNode;
	struct MemberFuncList* MFLNode;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 69 "y.tab.c"

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
#define NEW 264
#define BEGIN_ 265
#define END 266
#define MAIN 267
#define READ 268
#define WRITE 269
#define PLUS 270
#define MINUS 271
#define MUL 272
#define DIV 273
#define MOD 274
#define AMPERSAND 275
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
#define SELF 297
#define CLASS 298
#define ENDCLASS 299
#define EQ 300
#define NEQ 301
#define LT 302
#define LTE 303
#define GT 304
#define GTE 305
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,   42,   42,   47,   47,   48,
   30,   36,   36,   35,   29,   29,   29,   43,   49,   49,
   34,   41,   40,   51,   51,   52,   50,    1,    1,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    3,
    4,    5,    5,    5,    5,   15,   14,    6,    6,    9,
   10,   11,   12,   13,   44,   44,   55,   55,   56,   56,
   31,   31,   31,   31,   57,   57,   58,   58,   58,   58,
   58,   20,   39,   38,   38,   37,   33,   33,   27,   53,
   53,   53,   59,   60,   60,   60,   60,   60,   19,   19,
   19,   18,   45,   45,    7,   61,   62,   64,   64,   64,
   64,   64,   17,   17,   63,   63,   63,   65,   65,   66,
   66,   32,   32,   32,   32,   67,   67,   68,   68,   68,
   46,   69,   16,   54,   54,   54,   54,   23,   24,   22,
   28,   25,   25,   70,   21,   21,   21,   26,   26,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,
};
static const YYINT yylen[] = {                            2,
    5,    4,    3,    4,    2,    3,    0,    2,    1,    4,
    1,    2,    1,    3,    1,    1,    1,    3,    2,    1,
    5,    4,    1,    2,    1,    6,    1,    3,    2,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    2,
    2,    3,    6,    4,    3,    1,    3,    7,    5,    5,
    5,    1,    1,    1,    3,    2,    2,    1,    3,    4,
    1,    1,    1,    2,    3,    1,    1,    4,    4,    1,
    4,    2,    3,    3,    1,    2,    1,    1,    1,    3,
    1,    0,    2,    1,    1,    2,    2,    1,    3,    1,
    0,    1,    2,    1,    1,    5,    5,    1,    1,    2,
    2,    1,    5,    4,    3,    2,    0,    2,    1,    3,
    4,    1,    1,    1,    2,    3,    1,    1,    4,    2,
    7,    2,    5,    1,    1,    1,    1,    4,    5,    4,
    5,    2,    5,    4,    3,    3,    3,    1,    4,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    3,    1,    1,    4,    4,    2,    2,
    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   11,    0,    0,    9,    0,    0,    0,
    0,    0,    6,    8,   63,    0,   56,   61,   62,    0,
    0,   58,   23,   20,    0,    0,    0,  102,    0,    0,
    0,    3,   94,    0,    0,    0,   17,   15,   16,    0,
   13,    0,   64,    0,    0,    0,    0,    0,    0,   66,
   55,   57,    0,   18,   19,    0,    2,  122,  100,  101,
    4,   93,    0,   95,    0,    0,    0,   10,   12,    0,
    0,   72,   77,   78,    0,   75,    0,    0,    0,    0,
   59,    0,    0,    1,    0,    0,    0,    0,   14,   88,
    0,    0,    0,   81,    0,    0,   79,   76,    0,   73,
    0,   60,   65,    0,    0,    0,    0,  114,    0,  106,
  112,  113,    0,    0,  109,    0,    0,    0,    0,   86,
   87,    0,   69,   83,   68,   74,   71,    0,    0,   25,
   21,  115,    0,    0,    0,    0,  117,  105,  108,    0,
    0,    0,    0,   54,    0,    0,    0,   52,   53,    0,
    0,    0,    0,   30,   31,   32,   33,   34,   35,   36,
   37,   38,    0,    0,  126,  124,  125,    0,    0,  127,
   39,   96,   97,    0,   80,    0,   22,    0,   24,    0,
  120,    0,    0,  110,    0,    0,    0,  162,  163,  164,
    0,    0,    0,    0,    0,    0,  156,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  111,  116,    0,    0,    0,    0,  160,  159,  153,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   47,
  137,   28,    0,  104,    0,  135,    0,    0,    0,    0,
  136,    0,  121,    0,  119,    0,    0,   90,    0,    0,
  154,    0,    0,  142,  143,  144,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  103,
  130,  128,    0,    0,    0,    0,    0,    0,  157,    0,
  134,    0,   49,   50,   51,  129,  131,    0,   26,    0,
   89,    0,  123,   48,
};
static const YYINT yydgoto[] = {                          2,
  152,  153,  154,  155,  156,  157,   65,  267,  158,  159,
  160,  161,  162,  163,  204,  218,  117,  268,  269,   47,
  196,  165,  166,  167,  168,  169,   98,  170,   40,    5,
   20,  113,   75,   24,   41,   42,   76,   77,   48,   25,
   83,    3,   10,   11,   31,   32,    6,    7,   26,  107,
  129,  130,   93,  171,   21,   22,   49,   50,   94,   95,
   33,   34,   86,   35,  114,  115,  136,  137,   36,  197,
};
static const YYINT yysindex[] = {                      -221,
 -211,    0, -207,    0,  -37, -237,    0, -226, -154, -181,
 -231, -213,    0,    0,    0, -126,    0,    0,    0,  -38,
 -187,    0,    0,    0,   21, -234, -231,    0, -144, -108,
 -231,    0,    0,   48,  -68,  162,    0,    0,    0,  -51,
    0, -118,    0,  -19,  -50, -100,  174, -232,  -16,    0,
    0,    0,  -64,    0,    0, -231,    0,    0,    0,    0,
    0,    0,  -49,    0,  201,  206,  194,    0,    0, -198,
   -2,    0,    0,    0,   22,    0,   49, -198,   45, -232,
    0, -213, -196,    0, -141,   -8, -198,  135,    0,    0,
   11,   17,   91,    0,   37,  207,    0,    0, -100,    0,
  152,    0,    0, -213,   27, -196,  193,    0,   77,    0,
    0,    0,  -30, -120,    0,  353,  210,  180,  -49,    0,
    0, -198,    0,    0,    0,    0,    0,   85, -219,    0,
    0,    0,  240,  104, -225,   66,    0,    0,    0,  -34,
  212,  212,  105,    0,  212,  212,  439,    0,    0,  212,
  310,  353,  306,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  100,   73,    0,    0,    0, -227,  321,    0,
    0,    0,    0,  116,    0,  -10,    0,  125,    0,  128,
    0,   86, -225,    0,  212,  212,  -18,    0,    0,    0,
  126,  139,  212,  212,  551,  120,    0,  551,  336,  509,
  530,  465,  551,  339,  149,  348,  143,    0,  349,  212,
  160,  378,  379,  380,  388,  170,  439,  305, -198,  389,
  347,    0,    0,  551,  -92,  212,  212,    0,    0,    0,
  121,  212,  212,  212,  212,  212,  212,  212,  212,  212,
  212,  212,  212,  212,  212,  212,  439,  439,  212,    0,
    0,    0,  390,    0,  551,    0,  407,  409,  212,  212,
    0,  353,    0,  181,    0,  393,  551,    0,  182,  222,
    0,   78,   78,    0,    0,    0,  260,  572,  304,  304,
  -86,  -86,  -86,  -86,  254,  551,  271,  387,  484,    0,
    0,    0,  142,  163,  185,  398,  212,  212,    0,    0,
    0,  439,    0,    0,    0,    0,    0,  400,    0,  551,
    0,  433,    0,    0,
};
static const YYINT yyrindex[] = {                      -129,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  460,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  204,  205,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   97,    0,    0,   98,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  209,    0,    0,    0,    0,    0,    0,  275,
    0,    0,    0,    0,    0,    0,    0,  275,    0,    0,
    0,    0,    0,    0,    0,    0,  275,    0,    0,    0,
  215,  219,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  204,  352,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  209,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  111,    0,    0,    0,    0,    0,    0,  432,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -61,    0,  -41,    0,    0,    0,
    0,    0,    0,    0,  420,    1,    0,  421,    0,    0,
    0,    0,  422,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  275,    0,
    0,    0,    0,  423,    0,  279,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  279,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  424,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  440,  286,    0,    0,    0,
    0,    7,   43,    0,    0,    0,   -5,  414,  346,  397,
   36,   68,   74,   99,    0,  426,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -44,    0,    0,  -35,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  429,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
 -134, -140,    0,    0,    0,    0,    0,  356,    0,    0,
    0,    0,    0, -138,    0,    0,    0,  191,  246,    0,
  -97,    0,    0,    0,    0,    0,    0,    0,   -3,    0,
    0,    0,    0,  473,  -26,  418,  405,    0,  392,    0,
    0,    0,    0,  498,  -12,   90,    0,  504,    0,    0,
    0,  384,  -70,    0,    0,  493,  467,  436,  395,    0,
  -27,    0,  399,    0,    0,  406,  386,  354,    0,    0,
};
#define YYTABLESIZE 877
static const YYINT yytable[] = {                        161,
  266,   46,  161,   62,  138,  158,   68,  101,  158,   46,
  139,  206,  202,  207,   56,   69,  118,  161,  164,    4,
   70,  226,   23,  158,   44,   28,  185,   80,   62,  219,
   15,  133,  212,  213,  214,  151,  215,   37,  151,   45,
   13,  155,   81,   37,  155,    4,  134,  140,   89,  164,
  140,  161,   16,  151,  164,    1,  186,  158,   90,  155,
   28,  206,   29,   30,   54,  140,   17,   18,   19,   15,
  106,   71,  227,  177,   38,   39,  147,   69,   62,  147,
   38,   39,  262,  141,    8,   12,  141,  151,   80,  100,
    9,   16,   99,  155,  147,   91,   92,  105,   30,  140,
  128,  141,   23,  102,  164,   51,   18,   19,  148,  183,
    8,  148,  287,  288,  149,  108,   57,  149,  211,  164,
   61,  206,   58,  295,  184,  178,  148,   59,  147,  183,
   43,  123,  149,  210,  122,  141,  108,  109,   37,  150,
   67,   70,  150,   53,  222,   84,  206,  206,  264,  164,
  164,  110,  111,  112,  118,   67,   70,  150,  109,  245,
  148,  271,    7,   60,  164,  211,  149,  312,    7,  118,
   63,  206,  138,  111,  112,   38,   39,  232,  233,  234,
  235,  236,  306,  232,  233,  234,  235,  236,   64,  164,
  164,  150,  127,   73,   74,  122,  237,  238,  132,  132,
  132,   66,  132,  307,  164,   67,   72,  239,  240,  241,
  242,  243,  244,   78,  164,  133,  133,  133,   44,  133,
  173,  296,  299,  122,  122,  298,  133,   82,  161,  161,
  161,  161,  161,   45,  158,  158,  158,  158,  158,  161,
   87,  134,   85,  161,  161,  158,   88,  161,  161,  158,
  158,  194,   89,  158,  158,   96,  116,  119,  161,  161,
  161,  161,  161,  161,  158,  158,  158,  158,  158,  158,
  155,  155,  155,  155,  155,  151,  140,  140,   97,  151,
  151,  155,  120,  151,  151,  155,  155,  140,  121,  155,
  155,  140,  140,  124,  301,  140,  140,  298,   59,  125,
  155,  155,  155,  155,  155,  155,  140,  140,  140,  140,
  140,  140,  141,  141,  300,   82,  147,  131,   82,   91,
  147,  147,   91,  141,  147,  147,   92,  141,  141,   92,
  180,  141,  141,  132,  172,  147,  147,  147,  147,  147,
  147,  176,  141,  141,  141,  141,  141,  141,  148,  234,
  235,  236,  148,  148,  149,  205,  148,  148,  149,  149,
  181,  199,  149,  149,  208,  209,  216,  148,  148,  148,
  148,  148,  148,  149,  149,  149,  149,  149,  149,  150,
  217,  220,  228,  150,  150,  221,  145,  150,  150,  145,
  232,  233,  234,  235,  236,  229,  246,  250,  150,  150,
  150,  150,  150,  150,  145,  251,  252,  254,  253,  237,
  238,  232,  233,  234,  235,  236,  256,  257,  258,  259,
  239,  240,  241,  242,  243,  244,  261,  260,  219,  263,
  237,  238,  232,  233,  234,  235,  236,  146,  145,  265,
  146,  239,  240,  241,  242,  243,  244,  291,  290,  292,
  308,  237,  238,  297,  152,  146,  309,  152,  313,    5,
   98,   99,  239,  240,  241,  242,  243,  244,  187,  188,
  189,   84,  152,  107,  190,   85,   27,  138,   40,   41,
   46,   42,   45,  191,   44,  139,  192,   43,  311,  146,
  285,  232,  233,  234,  235,  236,  195,  198,   55,  104,
  200,  201,  193,  126,  135,  203,  152,   27,  151,   14,
  237,  238,  179,   52,   79,  103,  175,  174,    0,  139,
  182,  239,  240,  241,  242,  243,  244,  140,    0,  232,
  233,  234,  235,  236,    0,    0,  223,    0,  141,  142,
  224,  225,  143,    0,    0,    0,  144,    0,  230,  231,
  145,    0,  302,  303,  146,  147,    0,  148,  149,  239,
  240,  241,  242,  243,  244,  255,    0,  151,    0,    0,
    0,    0,    0,  232,  233,  234,  235,  236,    0,    0,
    0,    0,  270,    0,    0,    0,    0,  272,  273,  274,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
    0,  286,    0,    0,  289,  241,  242,  243,  244,  140,
    0,    0,    0,    0,  293,  294,    0,    0,    0,    0,
  141,  142,    0,    0,  143,    0,  145,    0,  144,    0,
  145,  145,  145,    0,  145,  145,  146,  147,    0,  148,
  149,    0,    0,  140,    0,  145,  145,    0,  150,  151,
    0,    0,  310,    0,  141,  142,    0,    0,  143,    0,
    0,    0,  144,    0,    0,    0,  145,    0,    0,    0,
  146,  147,  304,  148,  149,    0,    0,  146,    0,    0,
    0,  146,  146,  151,    0,  146,  146,    0,    0,  140,
    0,    0,    0,    0,  152,  140,  146,  146,  152,  152,
  141,  142,    0,  152,  143,    0,  141,  142,  144,    0,
  143,    0,  145,    0,  144,  314,  146,  147,  145,  148,
  149,  140,  146,  147,    0,  148,  149,    0,    0,  151,
    0,    0,  141,  142,    0,  151,  143,    0,    0,    0,
  144,    0,    0,    0,  145,    0,    0,    0,  249,  147,
    0,  148,  149,  232,  233,  234,  235,  236,    0,    0,
    0,  151,    0,    0,    0,    0,    0,    0,  248,  305,
    0,    0,  237,  238,    0,    0,    0,    0,  232,  233,
  234,  235,  236,  239,  240,  241,  242,  243,  244,  247,
    0,    0,    0,    0,    0,    0,    0,  237,  238,  232,
  233,  234,  235,  236,    0,    0,    0,    0,  239,  240,
  241,  242,  243,  244,  248,    0,    0,    0,  237,  238,
  232,  233,  234,  235,  236,    0,    0,    0,    0,  239,
  240,  241,  242,  243,  244,    0,    0,    0,    0,  237,
  238,  232,  233,  234,  235,  236,    0,    0,    0,    0,
  239,  240,  241,  242,  243,  244,    0,    0,    0,    0,
  237,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  239,  240,  241,  242,  243,  244,
};
static const YYINT yycheck[] = {                         41,
   93,   40,   44,   31,   46,   41,  125,   78,   44,   40,
   46,  152,  147,  152,   27,   42,   87,   59,  116,  257,
   40,   40,  257,   59,  257,  257,   61,   44,   56,   40,
  257,  257,  260,  261,  262,   41,  264,  257,   44,  272,
  278,   41,   59,  257,   44,  257,  272,   41,   59,  147,
   44,   93,  279,   59,  152,  277,   91,   93,  257,   59,
  257,  202,  294,  295,  299,   59,  293,  294,  295,  257,
   83,   91,   91,  293,  294,  295,   41,  104,  106,   44,
  294,  295,  217,   41,  292,  123,   44,   93,   44,   41,
  298,  279,   44,   93,   59,  294,  295,  294,  295,   93,
  104,   59,  257,   59,  202,  293,  294,  295,   41,   44,
  292,   44,  247,  248,   41,  257,   27,   44,   46,  217,
   31,  262,  267,  262,   59,  129,   59,  272,   93,   44,
  257,   41,   59,   61,   44,   93,  257,  279,  257,   41,
   44,   44,   44,  123,   59,   56,  287,  288,  219,  247,
  248,  293,  294,  295,   44,   59,   59,   59,  279,   40,
   93,   41,  292,  272,  262,   46,   93,  302,  298,   59,
  123,  312,  293,  294,  295,  294,  295,  270,  271,  272,
  273,  274,   41,  270,  271,  272,  273,  274,  257,  287,
  288,   93,   41,  294,  295,   44,  289,  290,  260,  261,
  262,   40,  264,   41,  302,  257,  257,  300,  301,  302,
  303,  304,  305,   40,  312,  260,  261,  262,  257,  264,
   41,   41,   41,   44,   44,   44,  257,  292,  270,  271,
  272,  273,  274,  272,  270,  271,  272,  273,  274,  281,
   40,  272,  292,  285,  286,  281,   41,  289,  290,  285,
  286,   40,   59,  289,  290,  258,  265,  123,  300,  301,
  302,  303,  304,  305,  300,  301,  302,  303,  304,  305,
  270,  271,  272,  273,  274,  281,  270,  271,  257,  285,
  286,  281,  272,  289,  290,  285,  286,  281,  272,  289,
  290,  285,  286,  257,   41,  289,  290,   44,  272,   93,
  300,  301,  302,  303,  304,  305,  300,  301,  302,  303,
  304,  305,  270,  271,   93,   41,  281,  125,   44,   41,
  285,  286,   44,  281,  289,  290,   41,  285,  286,   44,
   91,  289,  290,  257,  125,  300,  301,  302,  303,  304,
  305,  257,  300,  301,  302,  303,  304,  305,  281,  272,
  273,  274,  285,  286,  281,   46,  289,  290,  285,  286,
  257,  257,  289,  290,   59,  266,   46,  300,  301,  302,
  303,  304,  305,  300,  301,  302,  303,  304,  305,  281,
  265,  257,  257,  285,  286,  258,   41,  289,  290,   44,
  270,  271,  272,  273,  274,  257,   61,   59,  300,  301,
  302,  303,  304,  305,   59,  257,   59,   59,  266,  289,
  290,  270,  271,  272,  273,  274,  257,   40,   40,   40,
  300,  301,  302,  303,  304,  305,  257,   40,   40,  125,
  289,  290,  270,  271,  272,  273,  274,   41,   93,   93,
   44,  300,  301,  302,  303,  304,  305,   41,   59,   41,
  266,  289,  290,   61,   41,   59,   59,   44,   59,    0,
  257,  257,  300,  301,  302,  303,  304,  305,  257,  258,
  259,  257,   59,  265,  263,  257,  125,   46,   59,   59,
   59,   59,   59,  272,   59,   46,  275,   59,  298,   93,
  245,  270,  271,  272,  273,  274,  141,  142,   26,   82,
  145,  146,  291,   99,  113,  150,   93,   10,  297,    6,
  289,  290,  129,   21,   48,   80,  122,  119,   -1,  114,
  135,  300,  301,  302,  303,  304,  305,  257,   -1,  270,
  271,  272,  273,  274,   -1,   -1,  183,   -1,  268,  269,
  185,  186,  272,   -1,   -1,   -1,  276,   -1,  193,  194,
  280,   -1,  282,  283,  284,  285,   -1,  287,  288,  300,
  301,  302,  303,  304,  305,  210,   -1,  297,   -1,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,  274,   -1,   -1,
   -1,   -1,  227,   -1,   -1,   -1,   -1,  232,  233,  234,
  235,  236,  237,  238,  239,  240,  241,  242,  243,  244,
   -1,  246,   -1,   -1,  249,  302,  303,  304,  305,  257,
   -1,   -1,   -1,   -1,  259,  260,   -1,   -1,   -1,   -1,
  268,  269,   -1,   -1,  272,   -1,  281,   -1,  276,   -1,
  285,  286,  280,   -1,  289,  290,  284,  285,   -1,  287,
  288,   -1,   -1,  257,   -1,  300,  301,   -1,  296,  297,
   -1,   -1,  297,   -1,  268,  269,   -1,   -1,  272,   -1,
   -1,   -1,  276,   -1,   -1,   -1,  280,   -1,   -1,   -1,
  284,  285,  286,  287,  288,   -1,   -1,  281,   -1,   -1,
   -1,  285,  286,  297,   -1,  289,  290,   -1,   -1,  257,
   -1,   -1,   -1,   -1,  281,  257,  300,  301,  285,  286,
  268,  269,   -1,  290,  272,   -1,  268,  269,  276,   -1,
  272,   -1,  280,   -1,  276,  283,  284,  285,  280,  287,
  288,  257,  284,  285,   -1,  287,  288,   -1,   -1,  297,
   -1,   -1,  268,  269,   -1,  297,  272,   -1,   -1,   -1,
  276,   -1,   -1,   -1,  280,   -1,   -1,   -1,  284,  285,
   -1,  287,  288,  270,  271,  272,  273,  274,   -1,   -1,
   -1,  297,   -1,   -1,   -1,   -1,   -1,   -1,  285,  286,
   -1,   -1,  289,  290,   -1,   -1,   -1,   -1,  270,  271,
  272,  273,  274,  300,  301,  302,  303,  304,  305,  281,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  289,  290,  270,
  271,  272,  273,  274,   -1,   -1,   -1,   -1,  300,  301,
  302,  303,  304,  305,  285,   -1,   -1,   -1,  289,  290,
  270,  271,  272,  273,  274,   -1,   -1,   -1,   -1,  300,
  301,  302,  303,  304,  305,   -1,   -1,   -1,   -1,  289,
  290,  270,  271,  272,  273,  274,   -1,   -1,   -1,   -1,
  300,  301,  302,  303,  304,  305,   -1,   -1,   -1,   -1,
  289,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  300,  301,  302,  303,  304,  305,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 305
#define YYUNDFTOKEN 378
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
0,0,0,"ID","NUM","STRING","INITIALIZE","ALLOC","FREE","NULL_","NEW","BEGIN_",
"END","MAIN","READ","WRITE","PLUS","MINUS","MUL","DIV","MOD","AMPERSAND",
"BREAKPOINT","TYPE","ENDTYPE","TUPLE","IF","THEN","ELSE","ENDIF","WHILE","DO",
"ENDWHILE","BREAK","CONTINUE","AND","OR","NOT","DECL","ENDDECL","INT","STR",
"RETURN","SELF","CLASS","ENDCLASS","EQ","NEQ","LT","LTE","GT","GTE",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock",
"start : TypeDefBlock ClassDefBlock GDeclBlock MainBlock",
"start : TypeDefBlock GDeclBlock MainBlock",
"start : TypeDefBlock GDeclBlock FDefBlock MainBlock",
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
"ClassDefBlock : CLASS ClassDefList ENDCLASS",
"ClassDefList : ClassDefList ClassDef",
"ClassDefList : ClassDef",
"ClassDef : ClassName '{' ClassMembers MethodDefns '}'",
"ClassMembers : DECL FieldDeclList MethodDeclList ENDDECL",
"ClassName : ID",
"MethodDeclList : MethodDeclList MethodDecl",
"MethodDeclList : MethodDecl",
"MethodDecl : TypeName ID '(' ParamList ')' ';'",
"MethodDefns : FDefBlock",
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
"assignStmt : Field '=' expr",
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
"FBody : BEGIN_ retStmt END ';'",
"LDeclBlock : DECL LDeclList ENDDECL",
"LDeclBlock : DECL ENDDECL",
"LDeclBlock :",
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
"DynamicMemStmt : NewStmt",
"AllocStmt : DynaMemID ALLOC '(' ')'",
"FreeStmt : DynaMemID FREE '(' expr ')'",
"InitializeStmt : DynaMemID INITIALIZE '(' ')'",
"NewStmt : DynaMemID NEW '(' expr ')'",
"DynaMemID : ID '='",
"DynaMemID : ID '[' expr ']' '='",
"FieldFunction : Field '(' ArgList ')'",
"Field : Field '.' ID",
"Field : FieldID '.' ID",
"Field : SELF '.' ID",
"FieldID : ID",
"FieldID : ID '[' expr ']'",
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
"expr : Field",
"expr : FieldFunction",
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
#line 1045 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at statement %d\n", s, statementCount);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yydebug = 0;
		filePtr = fopen("../Target_Files/round1.xsm", "w");
		writeXexeHeader(filePtr);
		globalDeclStartLabel = getLabel();
		fprintf(filePtr, "JMP L%d\n", globalDeclStartLabel);
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
#line 750 "y.tab.c"

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
#line 74 "ast.y"
	{}
break;
case 2:
#line 75 "ast.y"
	{}
break;
case 3:
#line 76 "ast.y"
	{}
break;
case 4:
#line 77 "ast.y"
	{}
break;
case 5:
#line 78 "ast.y"
	{	
																		printf("\n⛔ No Code Provided\n");
																		exit(1);
																	}
break;
case 6:
#line 87 "ast.y"
	{ printTypeTable(); }
break;
case 8:
#line 91 "ast.y"
	{}
break;
case 9:
#line 92 "ast.y"
	{}
break;
case 10:
#line 96 "ast.y"
	{ 
													if (typeFieldCount > 8){
														printf("\nError: User defined type %s has more than 8 fields\n", yystack.l_mark[-3].TTNode->typeName);
														exit(1);
													}

													FLPrint(yystack.l_mark[-3].TTNode->typeName); 
													yystack.l_mark[-3].TTNode->typeCategory = TYPE_USER_DEFINED;
													yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-1].FLNode;
													yystack.l_mark[-3].TTNode->size = typeFieldCount;

													fieldListTail = NULL;
													fieldListHead = NULL;
													typeFieldCount = 0;
												}
break;
case 11:
#line 113 "ast.y"
	{ yyval.TTNode = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); }
break;
case 12:
#line 116 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[-1].FLNode;
												}
break;
case 13:
#line 122 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = 0;
													fieldListHead = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[0].FLNode;
				 								}
break;
case 14:
#line 130 "ast.y"
	{ 
													yyval.FLNode = FLCreateNode(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-2].TTNode, currentFieldCType); 
													++typeFieldCount;
													currentFieldCType = NULL;
												}
break;
case 15:
#line 137 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 16:
#line 138 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 17:
#line 139 "ast.y"
	{ 
													yyval.TTNode = TTLookUp(yystack.l_mark[0].node->nodeName); 

													/* if it's a class type*/
													if (yyval.TTNode == NULL) {
														currentFieldCType = CTLookUp(yystack.l_mark[0].node->nodeName);

														if (currentFieldCType == NULL) {
															printf("\nType Error: Unknown type %s\n", yystack.l_mark[0].node->nodeName);
															exit(1);
														}
													}
												}
break;
case 18:
#line 158 "ast.y"
	{ CTPrint(); }
break;
case 19:
#line 161 "ast.y"
	{}
break;
case 20:
#line 162 "ast.y"
	{}
break;
case 21:
#line 168 "ast.y"
	{ 
														FLPrint(yystack.l_mark[-4].CTNode->className);
														MFLPrint(yystack.l_mark[-4].CTNode->className);

														/* adding the class to the Type Table*/
														if (typeFieldCount > 8) {
															printf("\nError: Class %s has more than 8 fields\n", yystack.l_mark[-4].CTNode->className);
															exit(1);	
														}
														/* $$ = TTInstall($1->className, typeFieldCount, $1->memberField);*/
														/* $$->typeCategory = TYPE_CLASS;*/

														fieldListTail = NULL;
														fieldListHead = NULL;
														typeFieldCount = 0;

														memFuncListHead = NULL;
														memFuncListTail = NULL;
														currentClassTable = NULL;
					 								}
break;
case 22:
#line 193 "ast.y"
	{
														currentClassTable->memberField = yystack.l_mark[-2].FLNode;
														currentClassTable->virtualFunctionPtr = memFuncListHead;
														currentClassTable->fieldCount = fieldListTail->fieldIndex + 1;
														currentClassTable->methodCount = memFuncListTail->funcPosition;
													}
break;
case 23:
#line 201 "ast.y"
	{ 
														yyval.CTNode = CTInstall(yystack.l_mark[0].node->nodeName, NULL);
														currentClassTable = yyval.CTNode;
													}
break;
case 24:
#line 207 "ast.y"
	{}
break;
case 25:
#line 208 "ast.y"
	{}
break;
case 26:
#line 211 "ast.y"
	{ 
														MFLInstall(yystack.l_mark[-4].node->nodeName, yystack.l_mark[-5].TTNode, paramListHead);
														/*  printParamList(paramListHead); */
														flushParamList();
														paramCount = 0;
													}
break;
case 27:
#line 219 "ast.y"
	{}
break;
case 28:
#line 224 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 29:
#line 225 "ast.y"
	{}
break;
case 39:
#line 232 "ast.y"
	{ ++statementCount; }
break;
case 40:
#line 235 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 41:
#line 238 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 42:
#line 241 "ast.y"
	{ 
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
												}
break;
case 43:
#line 245 "ast.y"
	{	 
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
												}
break;
case 44:
#line 250 "ast.y"
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
case 45:
#line 260 "ast.y"
	{
													if (currentClassTable == NULL) {

														struct ClassTable* classType = GSTLookup(yystack.l_mark[-2].node->nodeName)->classTablePtr;
														struct ASTNode* fieldNode = yystack.l_mark[-2].node;

														while (fieldNode->right != NULL)
															fieldNode = fieldNode->right;	

														if (isFuncDef && verifyClassField(classType, fieldNode->nodeName)) {
															printf("Class Error: Can't access class field '%s' outside of class '%s'\n", fieldNode->nodeName, classType->className);
															exit(1);
														}	
													}

													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);
												}
break;
case 46:
#line 281 "ast.y"
	{}
break;
case 47:
#line 284 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 48:
#line 289 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 49:
#line 290 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 50:
#line 293 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 51:
#line 296 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 52:
#line 299 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 53:
#line 302 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 54:
#line 305 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 55:
#line 310 "ast.y"
	{
												GSTPrint(); 
												printTypeTable();
												fprintf(filePtr, "L%d:\n", globalDeclStartLabel);					
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 56:
#line 317 "ast.y"
	{}
break;
case 57:
#line 320 "ast.y"
	{}
break;
case 58:
#line 321 "ast.y"
	{}
break;
case 59:
#line 324 "ast.y"
	{}
break;
case 60:
#line 325 "ast.y"
	{ 
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												FLPrint(yystack.l_mark[-3].TTNode->typeName);

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentGDeclType = NULL;
												currentCDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 61:
#line 340 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 62:
#line 341 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 63:
#line 342 "ast.y"
	{ 
												/* for user-defined types						*/
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {

													/* for class types*/
													currentCDeclType = CTLookUp(yystack.l_mark[0].node->nodeName);

													if (currentCDeclType == NULL) {
														printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
														exit(1);
													}
												}
			 								}
break;
case 64:
#line 356 "ast.y"
	{ 
												if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
													printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}					
												currentGDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
												yyval.TTNode = currentGDeclType;
											}
break;
case 65:
#line 366 "ast.y"
	{}
break;
case 66:
#line 367 "ast.y"
	{}
break;
case 67:
#line 370 "ast.y"
	{ 
												int varSize;

												if (currentGDeclType != NULL)
													varSize = (currentGDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentGDeclType->size);
												if (currentCDeclType != NULL)
													varSize = currentCDeclType->fieldCount;	

												GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, varSize, NULL); 
											}
break;
case 68:
#line 380 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 69:
#line 387 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 70:
#line 393 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 71:
#line 400 "ast.y"
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
case 72:
#line 413 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 73:
#line 418 "ast.y"
	{ 
																	yyval.FLNode = yystack.l_mark[-1].FLNode; 

																	if (currentGDeclType != NULL)
																		currentGDeclType->size = tupleFieldCount;
																	if (currentLDeclType != NULL)
																		currentLDeclType->size = tupleFieldCount;		
																}
break;
case 74:
#line 428 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[-2].FLNode;
																}
break;
case 75:
#line 434 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = 0;
																	fieldListHead = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[0].FLNode;
																}
break;
case 76:
#line 442 "ast.y"
	{
																	yyval.FLNode = FLCreateNode(yystack.l_mark[0].node->nodeName, yystack.l_mark[-1].TTNode, NULL);
																	++tupleFieldCount;
																}
break;
case 77:
#line 448 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 78:
#line 449 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 79:
#line 452 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 460 "ast.y"
	{}
break;
case 81:
#line 461 "ast.y"
	{}
break;
case 82:
#line 462 "ast.y"
	{}
break;
case 83:
#line 465 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 84:
#line 471 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 85:
#line 472 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 86:
#line 473 "ast.y"
	{  }
break;
case 87:
#line 474 "ast.y"
	{  }
break;
case 88:
#line 475 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 89:
#line 484 "ast.y"
	{ yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 90:
#line 485 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 91:
#line 486 "ast.y"
	{}
break;
case 92:
#line 489 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 93:
#line 495 "ast.y"
	{}
break;
case 94:
#line 496 "ast.y"
	{}
break;
case 95:
#line 499 "ast.y"
	{ 
															/* Check for function in GST		*/
															if(GSTLookup(yystack.l_mark[0].node->nodeName) == NULL){

																if (currentClassTable == NULL) {
																	printf("\nFunction %s() not declared globally\n", yystack.l_mark[0].node->nodeName);
																	exit(1);
																}
															
																/* if not in GST, search in current Class Table*/
																if (MemberFuncLookUp(currentClassTable, yystack.l_mark[0].node->nodeName) == NULL) {
																	printf("\nFunction %s() not declared in class %s\n", yystack.l_mark[0].node->nodeName, currentClassTable->className);
																	exit(1);
																}

															}
															yyval.node = yystack.l_mark[0].node; 
															setCurrentFuncName(yystack.l_mark[0].node->nodeName);
														}
break;
case 96:
#line 521 "ast.y"
	{
															char* currentFuncName = getCurrentFuncName();

															struct GSTNode* funcGSTEntry = GSTLookup(currentFuncName);
															struct MemberFuncList* MFLEntry = MemberFuncLookUp(currentClassTable, currentFuncName);

															int funcLabel = (funcGSTEntry == NULL) ? (MFLEntry->funcLabel) : (funcGSTEntry->fLabel);

															fprintf(filePtr, "F%d:\n", funcLabel);
															initFuncCalle(filePtr, paramCount);

															printASTTable(yystack.l_mark[-1].node, 0);
															codeGen(yystack.l_mark[-1].node, filePtr);

															LSTPrint();
															flushLST();
															paramCount = 0;
															
														}
break;
case 97:
#line 542 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 98:
#line 548 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 99:
#line 549 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 100:
#line 550 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 101:
#line 551 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 102:
#line 552 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 103:
#line 555 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
															isFuncDef = 0;
														}
break;
case 104:
#line 560 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, NULL, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
															isFuncDef = 0;
														}
break;
case 105:
#line 570 "ast.y"
	{  
											/* printTupleList();*/
											isFuncDef = 1;	
										}
break;
case 106:
#line 574 "ast.y"
	{ isFuncDef = 1; }
break;
case 107:
#line 575 "ast.y"
	{ isFuncDef = 1; }
break;
case 108:
#line 578 "ast.y"
	{}
break;
case 109:
#line 579 "ast.y"
	{}
break;
case 110:
#line 582 "ast.y"
	{}
break;
case 111:
#line 583 "ast.y"
	{
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												FLPrint(yystack.l_mark[-3].TTNode->typeName);

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentLDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 112:
#line 597 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 113:
#line 598 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 114:
#line 599 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 115:
#line 606 "ast.y"
	{
											if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
												printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}					
											currentLDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
											yyval.TTNode = currentLDeclType;
										}
break;
case 116:
#line 616 "ast.y"
	{}
break;
case 117:
#line 617 "ast.y"
	{}
break;
case 118:
#line 620 "ast.y"
	{ 
											int varSize = (currentLDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentLDeclType->size);							
											LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, varSize); 
										}
break;
case 119:
#line 624 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 120:
#line 631 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 121:
#line 647 "ast.y"
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
case 122:
#line 666 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 123:
#line 669 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 128:
#line 685 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 129:
#line 691 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 130:
#line 698 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 131:
#line 704 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
													}
break;
case 132:
#line 711 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 133:
#line 712 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 134:
#line 722 "ast.y"
	{
														/* verify whether the user passed the right arguments for */
														/* a class member function*/
														struct ASTNode* classVariablePtr = yystack.l_mark[-3].node;
														struct ASTNode* classFunctionPtr = yystack.l_mark[-3].node->right;
														/* classVariablePtr->nodeType = MEM_FUNC_NODE;*/

														while (classFunctionPtr->right != NULL) {
															classVariablePtr = classVariablePtr->right;
															classFunctionPtr = classFunctionPtr->right;
														}

														verifyClassFuncArgs(classVariablePtr, yystack.l_mark[-1].node);

														classFunctionPtr->argListHead = yystack.l_mark[-1].node;

														if (yystack.l_mark[-3].node->nodeType == SELF_NODE)
															yystack.l_mark[-3].node->nodeType = SELF_FUNC_NODE;
														else
															classVariablePtr->nodeType = MEM_FUNC_NODE;
													}
break;
case 135:
#line 748 "ast.y"
	{
												struct ASTNode* traversalPtr = yystack.l_mark[-2].node;
												while (traversalPtr->right != NULL){
													traversalPtr = traversalPtr->right;
												}

												printf("\nLast field: %s\n", traversalPtr->nodeName);

												struct TypeTable* lastFieldType = traversalPtr->typeTablePtr;
												struct ClassTable* lastFieldClassType = traversalPtr->classTablePtr;

												traversalPtr->nodeType = FIELD_NODE;

												if(lastFieldType == typeTableINTPtr || lastFieldType == typeTableSTRPtr){
													printf("\n. operator cannot be used for non User Defined variable\n");
													exit(1);
												}
												
												/* for non-Class fields*/
												if (lastFieldClassType == NULL) {

													struct FieldList* fieldListEntry = FLLookUp(lastFieldType, NULL,yystack.l_mark[0].node->nodeName);

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
												else if (lastFieldClassType != NULL) {

													/* check if the field belongs to the class*/
													struct FieldList* fieldListEntry = FLLookUp(NULL, lastFieldClassType, yystack.l_mark[0].node->nodeName);
													struct MemberFuncList* funcListEntry = MemberFuncLookUp(lastFieldClassType, yystack.l_mark[0].node->nodeName); 

													if (fieldListEntry != NULL){
														printf("\nIt is a class field member\n");

														yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
														yystack.l_mark[0].node->classTablePtr = fieldListEntry->classType;
														traversalPtr->right = yystack.l_mark[0].node;
														yyval.node = yystack.l_mark[-2].node;
														yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
														yyval.node->classTablePtr = yystack.l_mark[0].node->classTablePtr;
													}
													else if (funcListEntry != NULL){
														printf("\nIt is a class function member\n");

														yystack.l_mark[0].node->typeTablePtr = funcListEntry->funcType;
														yystack.l_mark[0].node->classTablePtr = NULL;
														traversalPtr->right = yystack.l_mark[0].node;
														yyval.node = yystack.l_mark[-2].node;
														yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
														yyval.node->classTablePtr = yystack.l_mark[0].node->classTablePtr;
													}
													else {
														printf("\nClass Error: Unknown class member %s in %s.%s\n", yystack.l_mark[0].node->nodeName, yystack.l_mark[-2].node->nodeName, yystack.l_mark[0].node->nodeName);
														exit(1);
													}
												}
											}
break;
case 136:
#line 814 "ast.y"
	{
												/* Checking if ID($1) exists in LST or GST*/
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);

												int isClassVariable = (yystack.l_mark[-2].node->classTablePtr == NULL) ? (0) : (1);

												/* for non-class variables*/
												if (yystack.l_mark[-2].node->typeTablePtr != NULL) {
													if (yystack.l_mark[-2].node->typeTablePtr->typeCategory == TYPE_USER_DEFINED)
														yystack.l_mark[-2].node->nodeType = FIELD_NODE;

													else if (yystack.l_mark[-2].node->typeTablePtr->typeCategory == TYPE_TUPLE)
														yystack.l_mark[-2].node->nodeType = TUPLE_NODE;
													
													else {
														printf("\n. operator can only be used for User-Defined and class variables\n");
														exit(1);
													}
												}

												/* // if it is not a class variable*/
												/* if ($1->classTablePtr == NULL || ) {*/
												/* 	printf("\n. operator can only be used for User-Defined and class variables 1\n");*/
												/* 	exit(1);*/
												/* }*/
												/* else {*/
												/* 	$1->nodeType = FIELD_NODE;*/
												/* }*/

												/* for non-class variables i.e tuples and user-defined*/
												if (!isClassVariable){
													struct FieldList* fieldListEntry = FLLookUp(yystack.l_mark[-2].node->typeTablePtr, NULL,yystack.l_mark[0].node->nodeName);

													/* if field is not present in the field list*/
													if(fieldListEntry == NULL){
														printf("\nUndeclared field \"%s\" used in variable %s\n", yystack.l_mark[0].node->nodeName, yystack.l_mark[-2].node->nodeName);
														exit(1);
													}

													yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
													yystack.l_mark[0].node->classTablePtr = NULL;
													yystack.l_mark[-2].node->right = yystack.l_mark[0].node;
													yyval.node = yystack.l_mark[-2].node;
													yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
													yyval.node->classTablePtr = NULL;
												}								

												/* for class variable*/
												if (isClassVariable) {

													/* check if the field belongs to the class*/
													struct FieldList* fieldListEntry = FLLookUp(NULL, yystack.l_mark[-2].node->classTablePtr, yystack.l_mark[0].node->nodeName);
													struct MemberFuncList* funcListEntry = MemberFuncLookUp(yystack.l_mark[-2].node->classTablePtr, yystack.l_mark[0].node->nodeName); 
													yystack.l_mark[-2].node->nodeType = FIELD_NODE;

													if (fieldListEntry != NULL){
														printf("\nIt is a class field member\n");

														yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
														yystack.l_mark[0].node->classTablePtr = fieldListEntry->classType;
														yystack.l_mark[-2].node->right = yystack.l_mark[0].node;
														yyval.node = yystack.l_mark[-2].node;
														yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
														yyval.node->classTablePtr = yystack.l_mark[0].node->classTablePtr;
													}
													else if (funcListEntry != NULL){
														printf("\nIt is a class function member\n");

														yystack.l_mark[0].node->typeTablePtr = funcListEntry->funcType;
														yystack.l_mark[0].node->classTablePtr = NULL;
														yystack.l_mark[-2].node->right = yystack.l_mark[0].node;
														yyval.node = yystack.l_mark[-2].node;
														yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
														yyval.node->classTablePtr = yystack.l_mark[0].node->classTablePtr;
													}
													else {
														printf("\nClass Error: Unknown class member %s in %s.%s\n", yystack.l_mark[0].node->nodeName, yystack.l_mark[-2].node->nodeName, yystack.l_mark[0].node->nodeName);
														exit(1);
													}
												}
											}
break;
case 137:
#line 895 "ast.y"
	{
												/* can only be used inside a class method definiton*/
												if (currentClassTable == NULL || isFuncDef == 0) {
													printf("\nClass Error: 'self.%s'. Keyword 'self' can only be used in a class function definition\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}	

												yyval.node = TreeCreate(typeTableVOID, SELF_NODE, NULL, INT_MAX, NULL, NULL, NULL, yystack.l_mark[0].node);

												/* check if the class field or class method exists*/
												struct FieldList* fieldListEntry = FLLookUp(NULL, currentClassTable, yystack.l_mark[0].node->nodeName);
												struct MemberFuncList* funcListEntry = MemberFuncLookUp(currentClassTable, yystack.l_mark[0].node->nodeName);

												if (fieldListEntry != NULL) {
													yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
													yystack.l_mark[0].node->classTablePtr = fieldListEntry->classType;
													yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
													yyval.node->classTablePtr = yystack.l_mark[0].node->classTablePtr;
												}
												else if (funcListEntry != NULL) {
													yystack.l_mark[0].node->typeTablePtr = funcListEntry->funcType;
													yystack.l_mark[0].node->classTablePtr = NULL;
													yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
													yyval.node->classTablePtr = yystack.l_mark[0].node->classTablePtr;
												}
												else {
													printf("\nClass Error: Unknown class member %s in self.%s\n", yystack.l_mark[0].node->nodeName, yystack.l_mark[0].node->nodeName);
													exit(1);
												}
											}
break;
case 138:
#line 927 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 139:
#line 928 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 140:
#line 938 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 141:
#line 939 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 142:
#line 940 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 143:
#line 941 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 144:
#line 942 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 145:
#line 943 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 146:
#line 944 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 147:
#line 945 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 148:
#line 946 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 149:
#line 947 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 150:
#line 948 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 151:
#line 949 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 152:
#line 950 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 153:
#line 951 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 154:
#line 952 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 155:
#line 953 "ast.y"
	{ 
										/* struct ASTNode* fieldHead = lookupID($1);*/

										if (currentClassTable == NULL && yystack.l_mark[0].node->classTablePtr != NULL) {

											struct ClassTable* classType = GSTLookup(yystack.l_mark[0].node->nodeName)->classTablePtr;
											struct ASTNode* fieldNode = yystack.l_mark[0].node;

											while (fieldNode->right != NULL)
												fieldNode = fieldNode->right;	

											if (isFuncDef && verifyClassField(classType, fieldNode->nodeName)) {
												printf("Class Error: Can't access class field '%s' outside of class '%s'\n", fieldNode->nodeName, classType->className);
												exit(1);
											}	
										}

										yyval.node = yystack.l_mark[0].node; 
									}
break;
case 156:
#line 972 "ast.y"
	{  }
break;
case 157:
#line 973 "ast.y"
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
case 158:
#line 993 "ast.y"
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
case 159:
#line 1002 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 160:
#line 1010 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 161:
#line 1018 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);

										/* checking if the identifier called is a class field called*/
										/* inside a class function definition*/
										/* if (currentClassTable != NULL && isFuncDef == 1) {*/
										/* 	struct FieldList* classField = FLLookUp(NULL, currentClassTable, $1->nodeName);*/
										/* 	struct MemberFuncList* classMemFunc = MemberFuncLookUp(currentClassTable, $1->nodeName);*/

										/* 	if (classField != NULL) {*/
										/* 		printf("\nClass Error: Class member field %s can only be accessed using the self keyword\n", $1->nodeName);*/
										/* 		exit(1);*/
										/* 	}*/
										/* 	else if (classMemFunc != NULL) {*/
										/* 		printf("\nClass Error: Class member function %s() can only be accessed using the self keyword\n", $1->nodeName);*/
										/* 		exit(1);*/
										/* 	}*/
										/* }*/

										yyval.node = yystack.l_mark[0].node;
									}
break;
case 162:
#line 1039 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 163:
#line 1040 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 164:
#line 1041 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 2158 "y.tab.c"
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
