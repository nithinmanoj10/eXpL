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
#define EXTENDS 298
#define CLASS 299
#define ENDCLASS 300
#define EQ 301
#define NEQ 302
#define LT 303
#define LTE 304
#define GT 305
#define GTE 306
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,   42,   42,   47,   47,   48,
   30,   36,   36,   35,   29,   29,   29,   43,   49,   49,
   34,   41,   40,   40,   51,   51,   52,   50,    1,    1,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    3,    4,    5,    5,    5,    5,   15,   14,    6,    6,
    9,   10,   11,   12,   13,   44,   44,   55,   55,   56,
   56,   31,   31,   31,   31,   57,   57,   58,   58,   58,
   58,   58,   20,   39,   38,   38,   37,   33,   33,   27,
   53,   53,   53,   59,   60,   60,   60,   60,   60,   19,
   19,   19,   18,   45,   45,    7,   61,   62,   64,   64,
   64,   64,   64,   17,   17,   63,   63,   63,   65,   65,
   66,   66,   32,   32,   32,   32,   67,   67,   68,   68,
   68,   46,   69,   16,   54,   54,   54,   54,   23,   24,
   22,   28,   25,   25,   25,   70,   21,   21,   21,   26,
   26,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,
};
static const YYINT yylen[] = {                            2,
    5,    4,    3,    4,    2,    3,    0,    2,    1,    4,
    1,    2,    1,    3,    1,    1,    1,    3,    2,    1,
    5,    4,    1,    3,    2,    1,    6,    1,    3,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    2,    3,    6,    4,    3,    1,    3,    7,    5,
    5,    5,    1,    1,    1,    3,    2,    2,    1,    3,
    4,    1,    1,    1,    2,    3,    1,    1,    4,    4,
    1,    4,    2,    3,    3,    1,    2,    1,    1,    1,
    3,    1,    0,    2,    1,    1,    2,    2,    1,    3,
    1,    0,    1,    2,    1,    1,    5,    5,    1,    1,
    2,    2,    1,    5,    4,    3,    2,    0,    2,    1,
    3,    4,    1,    1,    1,    2,    3,    1,    1,    4,
    2,    7,    2,    5,    1,    1,    1,    1,    4,    5,
    4,    5,    2,    5,    2,    4,    3,    3,    3,    1,
    4,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    3,    1,    1,    4,    4,
    2,    2,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   11,    0,    0,    9,    0,    0,    0,
    0,    0,    6,    8,   64,    0,   57,   62,   63,    0,
    0,   59,    0,   20,    0,    0,    0,  103,    0,    0,
    0,    3,   95,    0,    0,    0,   17,   15,   16,    0,
   13,    0,   65,    0,    0,    0,    0,    0,    0,   67,
   56,   58,    0,    0,   18,   19,    0,    2,  123,  101,
  102,    4,   94,    0,   96,    0,    0,    0,   10,   12,
    0,    0,   73,   78,   79,    0,   76,    0,    0,    0,
    0,   60,   24,    0,    0,    1,    0,    0,    0,    0,
   14,   89,    0,    0,    0,   82,    0,    0,   80,   77,
    0,   74,    0,   61,   66,    0,    0,    0,    0,  115,
    0,  107,  113,  114,    0,    0,  110,    0,    0,    0,
    0,   87,   88,    0,   70,   84,   69,   75,   72,    0,
    0,   26,   21,  116,    0,    0,    0,    0,  118,  106,
  109,    0,    0,    0,    0,   55,    0,    0,    0,   53,
   54,    0,    0,    0,    0,   31,   32,   33,   34,   35,
   36,   37,   38,   39,    0,    0,  127,  125,  126,    0,
    0,  128,   40,   97,   98,    0,   81,    0,   22,    0,
   25,    0,  121,    0,    0,  111,    0,    0,    0,  164,
  165,  166,    0,    0,    0,    0,    0,    0,  158,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   30,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  112,  117,    0,    0,    0,    0,  162,
  161,  155,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   48,  139,   29,    0,  105,    0,  137,    0,    0,
    0,    0,  138,    0,  122,    0,  120,    0,    0,   91,
    0,    0,  156,    0,    0,  144,  145,  146,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  104,  131,  129,    0,    0,    0,    0,    0,    0,
  159,    0,  136,    0,   50,   51,   52,  130,  132,    0,
   27,    0,   90,    0,  124,   49,
};
static const YYINT yydgoto[] = {                          2,
  154,  155,  156,  157,  158,  159,   66,  269,  160,  161,
  162,  163,  164,  165,  206,  220,  119,  270,  271,   47,
  198,  167,  168,  169,  170,  171,  100,  172,   40,    5,
   20,  115,   76,   24,   41,   42,   77,   78,   48,   25,
   85,    3,   10,   11,   31,   32,    6,    7,   26,  109,
  131,  132,   95,  173,   21,   22,   49,   50,   96,   97,
   33,   34,   88,   35,  116,  117,  138,  139,   36,  199,
};
static const YYINT yysindex[] = {                      -246,
 -220,    0, -260,    0,  -78, -236,    0, -185, -172, -180,
 -213, -195,    0,    0,    0, -136,    0,    0,    0,  -38,
 -133,    0, -194,    0,   27, -240, -213,    0, -120, -119,
 -213,    0,    0,   32, -100,  119,    0,    0,    0,  -93,
    0, -117,    0,  -21,  -87, -266,  128, -234,  -19,    0,
    0,    0,  -82, -104,    0,    0, -213,    0,    0,    0,
    0,    0,    0,  -98,    0,  156,  157,  143,    0,    0,
 -188,  -54,    0,    0,    0,  -48,    0,   52, -188,  -10,
 -234,    0,    0, -195, -166,    0, -121,  -47, -188,   99,
    0,    0,  -31,  -25,   89,    0,  -33,  159,    0,    0,
 -266,    0,  135,    0,    0, -195,   12, -166,  168,    0,
   44,    0,    0,    0,  -30,  109,    0, -221,  193,  145,
  -98,    0,    0, -188,    0,    0,    0,    0,    0,   64,
 -168,    0,    0,    0,  218,   66, -184,   42,    0,    0,
    0,  -26,  181,  181,   69,    0,  181,  181,  314,    0,
    0,  181,  287, -221,  275,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   73,   57,    0,    0,    0,  202,
  292,    0,    0,    0,    0,   81,    0,   38,    0,   98,
    0,   96,    0,   76, -184,    0,  181,  181,  -20,    0,
    0,    0,  103,  108,  181,  181,  460,  -13,    0,  460,
  295,  417,  454,  389,  460,  311,  129,  332,  126,    0,
  341,  181,  154,  372,  373,  382,  384,  166,  314,  300,
 -188,  394,  340,    0,    0,  460,  -89,  181,  181,    0,
    0,    0,  125,  181,  181,  181,  181,  181,  181,  181,
  181,  181,  181,  181,  181,  181,  181,  181,  314,  314,
  181,    0,    0,    0,  386,    0,  460,    0,  400,  401,
  181,  186,    0, -221,    0,  149,    0,  385,  460,    0,
  182,  209,    0,  -15,  -15,    0,    0,    0,  503,  497,
  508,  508,  187,  187,  187,  187,  212,  460,  -77,  220,
  411,    0,    0,    0,  146,  413,  189,  408,  181,  181,
    0,    0,    0,  314,    0,    0,    0,    0,    0,  409,
    0,  460,    0,  383,    0,    0,
};
static const YYINT yyrindex[] = {                      -148,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  471,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  352,    0,    0,    0,    0,    0,  -48,  219,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   79,    0,    0,   90,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  225,    0,    0,    0,    0,    0,    0,
  241,    0,    0,    0,    0,    0,    0,    0,  241,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  241,    0,
    0,    0,  227,  234,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -48,  376,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  225,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   97,    0,    0,    0,    0,    0,
    0,  457,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  233,    0,  -41,    0,
    0,    0,    0,    0,    0,    0,  450,    2,    0,  461,
    0,    0,    0,    0,  462,    0,    0,    0,    0,    0,
    0,  282,    0,    0,    0,    0,    0,    0,    0,    0,
  241,    0,    0,    0,    0,  465,    0,  245,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  245,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  466,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  470,  256,    0,
    0,    0,    0,    9,   46,    0,    0,    0,  278,  328,
  184,  237,   39,   72,   78,  104,    0,  469,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  288,    0,
    0,  -35,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  472,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
 -135, -147,    0,    0,    0,    0,    0,  393,    0,    0,
    0,    0,    0, -153,    0,    0,    0,  229,  272,    0,
  283,    0,    0,    0,    0,    0,    0,    0,  -52,    0,
    0,    0,    0,  504,  -29,  451,  433,    0,  436,    0,
    0,    0,    0,  543,  -11,   -1,    0,  548,    0,    0,
    0,  424,  -67,    0,    0,  535,  509,  477,  437,    0,
  -16,    0,  439,    0,    0,  446,  428,  381,    0,    0,
};
#define YYTABLESIZE 814
static const YYINT yytable[] = {                        163,
  209,   46,  163,  268,  140,  160,  208,   69,  160,   46,
  141,  103,   70,  204,   63,   57,   23,  163,   71,  228,
    4,  120,   44,  160,   81,   58,  247,   74,   75,   62,
    1,    8,  213,   81,  187,  142,    4,   45,    9,   82,
   63,   13,  157,   28,   12,  157,  143,  144,  104,  142,
  145,  163,  142,  130,  146,   86,  208,  160,  147,   55,
  157,   37,  148,  149,  188,  150,  151,  142,   92,   72,
  229,   15,  135,  108,  152,  153,   70,  221,  180,  149,
   29,   30,  149,  264,   23,  185,  143,  136,   37,  143,
   28,   63,  102,   16,  157,  101,   91,  149,   38,   39,
  186,  142,  213,   53,  143,   93,   94,   17,   18,   19,
  297,    8,  150,  289,  290,  150,  208,  212,  151,  185,
   43,  151,   68,   15,  179,   38,   39,  107,   30,  125,
  150,  149,  124,   71,  224,  110,  151,   68,  143,   37,
  119,  208,  208,    7,  152,   16,   59,  152,   71,   54,
    7,   60,   61,  266,   64,  119,   65,  111,   67,   51,
   18,   19,  152,   68,  150,  273,  208,   79,  314,   73,
  151,  112,  113,  114,   83,  129,   38,   39,  124,  142,
  234,  235,  236,  237,  238,  175,  308,   84,  124,  298,
  143,  144,  124,   87,  145,   89,  152,   90,  146,  239,
  240,   91,  147,   98,  304,  305,  148,  149,   99,  150,
  151,  241,  242,  243,  244,  245,  246,  118,   44,  153,
  196,  121,  301,  126,  147,  300,  135,  147,  163,  163,
  163,  163,  163,   45,  160,  160,  160,  160,  160,  163,
  122,  136,  147,  163,  163,  160,  123,  163,  163,  160,
  160,  127,  303,  160,  160,  300,  236,  237,  238,  163,
  163,  163,  163,  163,  163,  160,  160,  160,  160,  160,
  160,  157,  157,  157,  157,  157,  147,  148,  142,  142,
  148,   83,  157,   60,   83,   92,  157,  157,   92,  142,
  157,  157,  133,  142,  142,  148,   93,  142,  142,   93,
  134,  302,  157,  157,  157,  157,  157,  157,  182,  142,
  142,  142,  142,  142,  142,  143,  143,  174,  153,  149,
  178,  153,  183,  149,  149,  201,  143,  149,  149,  148,
  143,  143,  207,  210,  143,  143,  153,  218,  211,  149,
  149,  149,  149,  149,  149,  219,  143,  143,  143,  143,
  143,  143,  150,  223,  222,  248,  150,  150,  151,  230,
  150,  150,  151,  151,  231,  110,  151,  151,  154,  252,
  153,  154,  150,  150,  150,  150,  150,  150,  151,  151,
  151,  151,  151,  151,  152,  253,  154,  111,  152,  152,
  254,  255,  152,  152,  234,  235,  236,  237,  238,  256,
  166,  140,  113,  114,  152,  152,  152,  152,  152,  152,
  258,  259,  260,  239,  240,  234,  235,  236,  237,  238,
  154,  261,  263,  262,  265,  241,  242,  243,  244,  245,
  246,  166,  267,  221,  239,  240,  166,  189,  190,  191,
  293,  294,  296,  192,  292,  299,  241,  242,  243,  244,
  245,  246,  193,  309,  310,  194,  234,  235,  236,  237,
  238,  214,  215,  216,  147,  217,  311,  315,  147,  147,
    5,  195,  147,  147,   23,  100,  142,  153,  234,  235,
  236,  237,  238,   85,  147,  147,  166,  143,  144,  108,
   86,  145,  133,  133,  133,  146,  133,  239,  240,  147,
   28,  166,  140,  148,  149,  306,  150,  151,   41,  241,
  242,  243,  244,  245,  246,  141,  153,  148,  287,   42,
   47,  148,  148,   43,   46,  148,  148,   45,  313,   56,
   44,  166,  166,  128,  106,  197,  200,  148,  148,  202,
  203,  135,  135,  135,  205,  135,  166,  134,  134,  134,
  137,  134,   27,   14,  181,   52,   80,  105,  153,  176,
  177,  141,  153,  153,  184,  225,  153,  153,    0,    0,
  142,  166,  166,    0,    0,    0,    0,    0,    0,  226,
  227,  143,  144,    0,    0,  145,  166,  232,  233,  146,
    0,    0,    0,  147,    0,    0,  166,  148,  149,    0,
  150,  151,    0,    0,  257,    0,    0,    0,  154,    0,
  153,    0,  154,  154,    0,    0,    0,  154,    0,    0,
    0,  272,    0,    0,    0,    0,  274,  275,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  285,  286,  142,
  288,    0,    0,  291,    0,  142,    0,    0,    0,    0,
  143,  144,    0,  295,  145,    0,  143,  144,  146,    0,
  145,    0,  147,    0,  146,  316,  148,  149,  147,  150,
  151,    0,  251,  149,    0,  150,  151,    0,    0,  153,
  234,  235,  236,  237,  238,  153,  234,  235,  236,  237,
  238,  312,    0,    0,    0,  250,  307,  249,    0,  239,
  240,    0,    0,    0,    0,  239,  240,    0,    0,    0,
    0,  241,  242,  243,  244,  245,  246,  241,  242,  243,
  244,  245,  246,  234,  235,  236,  237,  238,    0,  234,
  235,  236,  237,  238,    0,    0,    0,    0,  250,    0,
    0,    0,  239,  240,    0,    0,    0,    0,  239,  240,
    0,    0,    0,    0,  241,  242,  243,  244,  245,  246,
  241,  242,  243,  244,  245,  246,  234,  235,  236,  237,
  238,    0,  234,  235,  236,  237,  238,  234,  235,  236,
  237,  238,    0,    0,    0,  239,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  241,  242,  243,
  244,  245,  246,  241,  242,  243,  244,  245,  246,    0,
  243,  244,  245,  246,
};
static const YYINT yycheck[] = {                         41,
  154,   40,   44,   93,   46,   41,  154,  125,   44,   40,
   46,   79,   42,  149,   31,   27,  257,   59,   40,   40,
  257,   89,  257,   59,   44,   27,   40,  294,  295,   31,
  277,  292,   46,   44,   61,  257,  257,  272,  299,   59,
   57,  278,   41,  257,  123,   44,  268,  269,   59,   41,
  272,   93,   44,  106,  276,   57,  204,   93,  280,  300,
   59,  257,  284,  285,   91,  287,  288,   59,  257,   91,
   91,  257,  257,   85,  296,  297,  106,   40,  131,   41,
  294,  295,   44,  219,  257,   44,   41,  272,  257,   44,
  257,  108,   41,  279,   93,   44,   59,   59,  294,  295,
   59,   93,   46,  298,   59,  294,  295,  293,  294,  295,
  264,  292,   41,  249,  250,   44,  264,   61,   41,   44,
  257,   44,   44,  257,  293,  294,  295,  294,  295,   41,
   59,   93,   44,   44,   59,  257,   59,   59,   93,  257,
   44,  289,  290,  292,   41,  279,  267,   44,   59,  123,
  299,  272,  272,  221,  123,   59,  257,  279,   40,  293,
  294,  295,   59,  257,   93,   41,  314,   40,  304,  257,
   93,  293,  294,  295,  257,   41,  294,  295,   44,  257,
  270,  271,  272,  273,  274,   41,   41,  292,   44,   41,
  268,  269,   44,  292,  272,   40,   93,   41,  276,  289,
  290,   59,  280,  258,  282,  283,  284,  285,  257,  287,
  288,  301,  302,  303,  304,  305,  306,  265,  257,  297,
   40,  123,   41,  257,   41,   44,  257,   44,  270,  271,
  272,  273,  274,  272,  270,  271,  272,  273,  274,  281,
  272,  272,   59,  285,  286,  281,  272,  289,  290,  285,
  286,   93,   41,  289,  290,   44,  272,  273,  274,  301,
  302,  303,  304,  305,  306,  301,  302,  303,  304,  305,
  306,  270,  271,  272,  273,  274,   93,   41,  270,  271,
   44,   41,  281,  272,   44,   41,  285,  286,   44,  281,
  289,  290,  125,  285,  286,   59,   41,  289,  290,   44,
  257,   93,  301,  302,  303,  304,  305,  306,   91,  301,
  302,  303,  304,  305,  306,  270,  271,  125,   41,  281,
  257,   44,  257,  285,  286,  257,  281,  289,  290,   93,
  285,  286,   46,   59,  289,  290,   59,   46,  266,  301,
  302,  303,  304,  305,  306,  265,  301,  302,  303,  304,
  305,  306,  281,  258,  257,   61,  285,  286,  281,  257,
  289,  290,  285,  286,  257,  257,  289,  290,   41,   59,
   93,   44,  301,  302,  303,  304,  305,  306,  301,  302,
  303,  304,  305,  306,  281,  257,   59,  279,  285,  286,
   59,  266,  289,  290,  270,  271,  272,  273,  274,   59,
  118,  293,  294,  295,  301,  302,  303,  304,  305,  306,
  257,   40,   40,  289,  290,  270,  271,  272,  273,  274,
   93,   40,  257,   40,  125,  301,  302,  303,  304,  305,
  306,  149,   93,   40,  289,  290,  154,  257,  258,  259,
   41,   41,  257,  263,   59,   61,  301,  302,  303,  304,
  305,  306,  272,   41,  266,  275,  270,  271,  272,  273,
  274,  260,  261,  262,  281,  264,   59,   59,  285,  286,
    0,  291,  289,  290,  123,  257,  257,  297,  270,  271,
  272,  273,  274,  257,  301,  302,  204,  268,  269,  265,
  257,  272,  260,  261,  262,  276,  264,  289,  290,  280,
  125,  219,   46,  284,  285,  286,  287,  288,   59,  301,
  302,  303,  304,  305,  306,   46,  297,  281,  247,   59,
   59,  285,  286,   59,   59,  289,  290,   59,  300,   26,
   59,  249,  250,  101,   84,  143,  144,  301,  302,  147,
  148,  260,  261,  262,  152,  264,  264,  260,  261,  262,
  115,  264,   10,    6,  131,   21,   48,   81,  281,  121,
  124,  116,  285,  286,  137,  185,  289,  290,   -1,   -1,
  257,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,  187,
  188,  268,  269,   -1,   -1,  272,  304,  195,  196,  276,
   -1,   -1,   -1,  280,   -1,   -1,  314,  284,  285,   -1,
  287,  288,   -1,   -1,  212,   -1,   -1,   -1,  281,   -1,
  297,   -1,  285,  286,   -1,   -1,   -1,  290,   -1,   -1,
   -1,  229,   -1,   -1,   -1,   -1,  234,  235,  236,  237,
  238,  239,  240,  241,  242,  243,  244,  245,  246,  257,
  248,   -1,   -1,  251,   -1,  257,   -1,   -1,   -1,   -1,
  268,  269,   -1,  261,  272,   -1,  268,  269,  276,   -1,
  272,   -1,  280,   -1,  276,  283,  284,  285,  280,  287,
  288,   -1,  284,  285,   -1,  287,  288,   -1,   -1,  297,
  270,  271,  272,  273,  274,  297,  270,  271,  272,  273,
  274,  299,   -1,   -1,   -1,  285,  286,  281,   -1,  289,
  290,   -1,   -1,   -1,   -1,  289,  290,   -1,   -1,   -1,
   -1,  301,  302,  303,  304,  305,  306,  301,  302,  303,
  304,  305,  306,  270,  271,  272,  273,  274,   -1,  270,
  271,  272,  273,  274,   -1,   -1,   -1,   -1,  285,   -1,
   -1,   -1,  289,  290,   -1,   -1,   -1,   -1,  289,  290,
   -1,   -1,   -1,   -1,  301,  302,  303,  304,  305,  306,
  301,  302,  303,  304,  305,  306,  270,  271,  272,  273,
  274,   -1,  270,  271,  272,  273,  274,  270,  271,  272,
  273,  274,   -1,   -1,   -1,  289,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  301,  302,  303,
  304,  305,  306,  301,  302,  303,  304,  305,  306,   -1,
  303,  304,  305,  306,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 306
#define YYUNDFTOKEN 379
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
"RETURN","SELF","EXTENDS","CLASS","ENDCLASS","EQ","NEQ","LT","LTE","GT","GTE",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"ClassName : ID EXTENDS ID",
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
"NewStmt : DynaMemID NEW '(' ID ')'",
"DynaMemID : ID '='",
"DynaMemID : ID '[' expr ']' '='",
"DynaMemID : Field '='",
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
#line 1139 "ast.y"

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
#line 741 "y.tab.c"

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

													FLPrint(yystack.l_mark[-3].TTNode->typeName, NULL); 
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
	{ 
														CTPrint(); 
														fprintf(filePtr, "L%d:\n", globalDeclStartLabel);	
														initVirtualFuncTable(filePtr);
													}
break;
case 19:
#line 165 "ast.y"
	{}
break;
case 20:
#line 166 "ast.y"
	{}
break;
case 21:
#line 172 "ast.y"
	{ 
														FLPrint(yystack.l_mark[-4].CTNode->className, currentClassTable->memberField);
														MFLPrint(yystack.l_mark[-4].CTNode->className);

														/* adding the class to the Type Table*/
														if (typeFieldCount > 8) {
															printf("\nError: Class %s has more than 8 fields\n", yystack.l_mark[-4].CTNode->className);
															exit(1);	
														}

														if (currentClassTable->methodCount > 8) {
															printf("\nError: Class %s has more than 8 member functions\n", yystack.l_mark[-4].CTNode->className);
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
														currentParentClassTable = NULL;
					 								}
break;
case 22:
#line 203 "ast.y"
	{

														/* if the class is not inheriting from any other function*/
														/* set the funcLabel for each member function*/
														if (currentClassTable->parentPtr == NULL) {
															struct MemberFuncList* traversalPtr = memFuncListHead;
															while (traversalPtr != NULL) {
																traversalPtr->funcLabel = getLabel();
																traversalPtr = traversalPtr->next;
															}
															currentClassTable->virtualFunctionPtr = memFuncListHead;
															/* currentClassTable->methodCount = memFuncListTail->funcPosition;*/
														}

														/* if the current class is inheriting from a parent class*/
														if (currentClassTable->parentPtr != NULL) {
															struct FieldList* fieldTraversalPtr = currentClassTable->memberField;
															while (fieldTraversalPtr->next != NULL)
																fieldTraversalPtr = fieldTraversalPtr->next;
															fieldTraversalPtr->next = yystack.l_mark[-2].FLNode;

															/* update fieldIndex for newly appended fields*/
															int fieldOffset = fieldTraversalPtr->fieldIndex + 1;
															fieldTraversalPtr = fieldTraversalPtr->next;	

															while (fieldTraversalPtr != NULL) {
																fieldTraversalPtr->fieldIndex += fieldOffset;
																fieldTraversalPtr = fieldTraversalPtr->next;
															}	
														}
														else
															currentClassTable->memberField = yystack.l_mark[-2].FLNode;

														/* setting member functions of child class if inheriting from */
														/* parent class*/
														if (currentClassTable->parentPtr != NULL) {

															copyParentFunctions(currentClassTable);
															addChildFunctions(currentClassTable);

															printf("\nWhyyyyy\n");

															struct MemberFuncList* parentMemberFuncList = currentClassTable->parentPtr->virtualFunctionPtr;
															
															/* while (parentMemberFuncList != NULL) {*/
																
															/* 	// the parent function doesn't exists in the child class*/
															/* 	if (MFLLookup(parentMemberFuncList->funcName) == NULL) {*/
															/* 		MFLInstall(parentMemberFuncList->funcName, parentMemberFuncList->funcType, parentMemberFuncList->paramList);*/
															/* 	}*/
															/* 	else {	// if parent function does exists in the child class*/

															/* 		// verifying if the function signatures are the same*/
															/* 		verifyChildParentFunction(parentMemberFuncList);*/
															/* 	}*/
															/* 	parentMemberFuncList = parentMemberFuncList->next;*/
															/* }*/

														}


														struct MemberFuncList* traversalPtr = currentClassTable->virtualFunctionPtr;
														while (traversalPtr != NULL) {
															++currentClassTable->methodCount;
															traversalPtr = traversalPtr->next;
														}


														currentClassTable->fieldCount = fieldListTail->fieldIndex + 1;
													}
break;
case 23:
#line 275 "ast.y"
	{ 
														yyval.CTNode = CTInstall(yystack.l_mark[0].node->nodeName, NULL);
														currentClassTable = yyval.CTNode;
													}
break;
case 24:
#line 279 "ast.y"
	{ 
														yyval.CTNode = CTInstall(yystack.l_mark[-2].node->nodeName, yystack.l_mark[0].node->nodeName);
														currentClassTable = yyval.CTNode;
														currentParentClassTable = CTLookUp(yystack.l_mark[0].node->nodeName);
					 								}
break;
case 25:
#line 286 "ast.y"
	{}
break;
case 26:
#line 287 "ast.y"
	{}
break;
case 27:
#line 290 "ast.y"
	{ 
														MFLInstall(yystack.l_mark[-4].node->nodeName, yystack.l_mark[-5].TTNode, paramListHead);
														/*  printParamList(paramListHead); */
														flushParamList();
														paramCount = 0;
													}
break;
case 28:
#line 298 "ast.y"
	{}
break;
case 29:
#line 303 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 30:
#line 304 "ast.y"
	{}
break;
case 40:
#line 311 "ast.y"
	{ ++statementCount; }
break;
case 41:
#line 314 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 42:
#line 317 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 43:
#line 320 "ast.y"
	{ 
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
												}
break;
case 44:
#line 324 "ast.y"
	{	 
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
												}
break;
case 45:
#line 329 "ast.y"
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
case 46:
#line 339 "ast.y"
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
case 47:
#line 360 "ast.y"
	{}
break;
case 48:
#line 363 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 49:
#line 368 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 50:
#line 369 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 51:
#line 372 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 52:
#line 375 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 53:
#line 378 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 54:
#line 381 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 55:
#line 384 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 56:
#line 389 "ast.y"
	{
												GSTPrint(); 
												printTypeTable();
																
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 57:
#line 396 "ast.y"
	{}
break;
case 58:
#line 399 "ast.y"
	{}
break;
case 59:
#line 400 "ast.y"
	{}
break;
case 60:
#line 403 "ast.y"
	{}
break;
case 61:
#line 404 "ast.y"
	{ 
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												FLPrint(yystack.l_mark[-3].TTNode->typeName, NULL);

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentGDeclType = NULL;
												currentCDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 62:
#line 419 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 63:
#line 420 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 64:
#line 421 "ast.y"
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
case 65:
#line 435 "ast.y"
	{ 
												if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
													printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}					
												currentGDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
												yyval.TTNode = currentGDeclType;
											}
break;
case 66:
#line 445 "ast.y"
	{}
break;
case 67:
#line 446 "ast.y"
	{}
break;
case 68:
#line 449 "ast.y"
	{ 
												int varSize;

												if (currentGDeclType != NULL)
													varSize = (currentGDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentGDeclType->size);
												if (currentCDeclType != NULL)
													varSize = 2;	/* class variable will only have size of 2 */

												GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, varSize, NULL); 
											}
break;
case 69:
#line 459 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 70:
#line 466 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 71:
#line 472 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 72:
#line 479 "ast.y"
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
case 73:
#line 492 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 74:
#line 497 "ast.y"
	{ 
																	yyval.FLNode = yystack.l_mark[-1].FLNode; 

																	if (currentGDeclType != NULL)
																		currentGDeclType->size = tupleFieldCount;
																	if (currentLDeclType != NULL)
																		currentLDeclType->size = tupleFieldCount;		
																}
break;
case 75:
#line 507 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[-2].FLNode;
																}
break;
case 76:
#line 513 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = 0;
																	fieldListHead = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[0].FLNode;
																}
break;
case 77:
#line 521 "ast.y"
	{
																	yyval.FLNode = FLCreateNode(yystack.l_mark[0].node->nodeName, yystack.l_mark[-1].TTNode, NULL);
																	++tupleFieldCount;
																}
break;
case 78:
#line 527 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 79:
#line 528 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 80:
#line 531 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 539 "ast.y"
	{}
break;
case 82:
#line 540 "ast.y"
	{}
break;
case 83:
#line 541 "ast.y"
	{}
break;
case 84:
#line 544 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 85:
#line 550 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 86:
#line 551 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 87:
#line 552 "ast.y"
	{  }
break;
case 88:
#line 553 "ast.y"
	{  }
break;
case 89:
#line 554 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 90:
#line 563 "ast.y"
	{ yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 91:
#line 564 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 565 "ast.y"
	{}
break;
case 93:
#line 568 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 94:
#line 574 "ast.y"
	{}
break;
case 95:
#line 575 "ast.y"
	{}
break;
case 96:
#line 578 "ast.y"
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
case 97:
#line 600 "ast.y"
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
case 98:
#line 621 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 99:
#line 627 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 100:
#line 628 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 101:
#line 629 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 102:
#line 630 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 103:
#line 631 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 104:
#line 634 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
															isFuncDef = 0;
														}
break;
case 105:
#line 639 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, NULL, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
															isFuncDef = 0;
														}
break;
case 106:
#line 649 "ast.y"
	{  
											/* printTupleList();*/
											isFuncDef = 1;	
										}
break;
case 107:
#line 653 "ast.y"
	{ isFuncDef = 1; }
break;
case 108:
#line 654 "ast.y"
	{ isFuncDef = 1; }
break;
case 109:
#line 657 "ast.y"
	{}
break;
case 110:
#line 658 "ast.y"
	{}
break;
case 111:
#line 661 "ast.y"
	{}
break;
case 112:
#line 662 "ast.y"
	{
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												FLPrint(yystack.l_mark[-3].TTNode->typeName, NULL);

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentLDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 113:
#line 676 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 114:
#line 677 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 115:
#line 678 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 116:
#line 685 "ast.y"
	{
											if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
												printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}					
											currentLDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
											yyval.TTNode = currentLDeclType;
										}
break;
case 117:
#line 695 "ast.y"
	{}
break;
case 118:
#line 696 "ast.y"
	{}
break;
case 119:
#line 699 "ast.y"
	{ 
											int varSize = (currentLDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentLDeclType->size);							
											LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, varSize); 
										}
break;
case 120:
#line 703 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 121:
#line 710 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 122:
#line 726 "ast.y"
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
case 123:
#line 745 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 124:
#line 748 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 129:
#line 764 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 130:
#line 770 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 131:
#line 777 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 132:
#line 783 "ast.y"
	{
															if (CTLookUp(yystack.l_mark[-1].node->nodeName) == NULL) {
																printf("\nError: Undefined class type %s used in new() function\n", yystack.l_mark[-1].node->nodeName);
																exit(1);
															}

															if (yystack.l_mark[-4].node->nodeType != SELF_NODE)
																yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);

																struct ASTNode* debugTemp = yystack.l_mark[-4].node;
															if (yystack.l_mark[-4].node->classTablePtr != CTLookUp(yystack.l_mark[-1].node->nodeName) && !isDescentedClass(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-4].node->classTablePtr->className)) {
																printf("\nError: Class type '%s' expected in new() function\n", yystack.l_mark[-4].node->classTablePtr->className);
																exit(1);
															}


															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
													}
break;
case 133:
#line 804 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 134:
#line 805 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 135:
#line 809 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 136:
#line 816 "ast.y"
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
case 137:
#line 842 "ast.y"
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
case 138:
#line 908 "ast.y"
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
case 139:
#line 989 "ast.y"
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
case 140:
#line 1021 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 141:
#line 1022 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 142:
#line 1032 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 143:
#line 1033 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 144:
#line 1034 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 145:
#line 1035 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 146:
#line 1036 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 147:
#line 1037 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 148:
#line 1038 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 149:
#line 1039 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 150:
#line 1040 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 151:
#line 1041 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 152:
#line 1042 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 153:
#line 1043 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 154:
#line 1044 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 155:
#line 1045 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 156:
#line 1046 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 157:
#line 1047 "ast.y"
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
case 158:
#line 1066 "ast.y"
	{  }
break;
case 159:
#line 1067 "ast.y"
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
case 160:
#line 1087 "ast.y"
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
case 161:
#line 1096 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 162:
#line 1104 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 163:
#line 1112 "ast.y"
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
case 164:
#line 1133 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 165:
#line 1134 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 166:
#line 1135 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 2249 "y.tab.c"
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
