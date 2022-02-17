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
	char* fileName;
	FILE* filePtr;
#line 35 "ast.y"
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
#line 67 "y.tab.c"

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
#define CLASS 296
#define ENDCLASS 297
#define EQ 298
#define NEQ 299
#define LT 300
#define LTE 301
#define GT 302
#define GTE 303
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,   40,   40,   45,   45,   46,
   29,   34,   34,   33,   28,   28,   28,   41,   47,   47,
   48,   39,   38,   50,   50,   51,   49,    1,    1,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    3,
    4,    5,    5,    5,    5,   15,   14,    6,    6,    9,
   10,   11,   12,   13,   42,   42,   54,   54,   55,   55,
   30,   30,   30,   30,   56,   56,   57,   57,   57,   57,
   57,   20,   37,   36,   36,   35,   32,   32,   27,   52,
   52,   52,   58,   59,   59,   59,   59,   59,   19,   19,
   19,   18,   43,   43,    7,   60,   61,   63,   63,   63,
   63,   63,   17,   62,   62,   62,   64,   64,   65,   65,
   31,   31,   31,   31,   66,   66,   67,   67,   67,   44,
   68,   16,   53,   53,   53,   23,   24,   22,   25,   25,
   21,   21,   26,   26,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,
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
    2,    1,    5,    3,    0,    2,    2,    1,    3,    4,
    1,    1,    1,    2,    3,    1,    1,    4,    2,    7,
    2,    5,    1,    1,    1,    4,    5,    4,    2,    5,
    3,    3,    1,    4,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    3,    1,
    4,    4,    2,    2,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   11,    0,    0,    9,    0,    0,    0,
    0,    0,    6,    8,   63,    0,   56,   61,   62,    0,
    0,   58,   23,    0,    0,   20,    0,  102,    0,    0,
    0,    3,   94,    0,    0,    0,   17,   15,   16,    0,
   13,    0,   64,    0,    0,    0,    0,    0,    0,   66,
   55,   57,    0,   18,   19,    0,    2,  121,  100,  101,
    4,   93,    0,   95,    0,    0,    0,   10,   12,    0,
    0,   72,   77,   78,    0,   75,    0,    0,    0,    0,
   59,    0,    0,    1,    0,    0,    0,    0,   14,   88,
    0,    0,    0,   81,    0,    0,   79,   76,    0,   73,
    0,   60,   65,    0,    0,    0,    0,  113,    0,  106,
  111,  112,    0,    0,  108,    0,    0,    0,    0,   86,
   87,    0,   69,   83,   68,   74,   71,    0,    0,   25,
   21,  114,    0,    0,    0,    0,  116,  104,  107,    0,
    0,    0,    0,   54,    0,    0,    0,   52,   53,    0,
    0,   30,   31,   32,   33,   34,   35,   36,   37,   38,
    0,  125,  123,  124,    0,    0,   39,   96,   97,    0,
   80,    0,   22,    0,   24,    0,  119,    0,    0,  109,
    0,    0,    0,  156,  157,  158,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   29,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  110,  115,    0,    0,    0,    0,  154,  153,
  148,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   28,    0,    0,  131,    0,    0,    0,  132,    0,
  120,    0,  118,    0,    0,   90,    0,    0,  149,    0,
    0,  137,  138,  139,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   47,  103,  128,  126,
    0,    0,    0,    0,    0,  151,    0,    0,   49,   50,
   51,  127,    0,   26,    0,   89,    0,  122,   48,
};
static const YYINT yydgoto[] = {                          2,
  150,  151,  152,  153,  154,  155,   65,  255,  156,  157,
  158,  159,  160,  200,  241,  209,  117,  256,  257,   47,
  192,  162,  163,  164,  165,  166,   98,   40,    5,   20,
  113,   75,   41,   42,   76,   77,   48,   24,   83,    3,
   10,   11,   31,   32,    6,    7,   25,   26,  107,  129,
  130,   93,  167,   21,   22,   49,   50,   94,   95,   33,
   34,   86,   35,  114,  115,  136,  137,   36,
};
static const YYINT yysindex[] = {                      -242,
 -195,    0, -264,    0,  -44, -234,    0, -229, -165, -189,
 -238, -170,    0,    0,    0, -127,    0,    0,    0,  -38,
 -175,    0,    0,   11, -240,    0, -238,    0, -104, -128,
 -238,    0,    0,   24, -103,  120,    0,    0,    0,  -93,
    0, -124,    0,  -24,  -71, -116,  128, -145,  -18,    0,
    0,    0,  -95,    0,    0, -238,    0,    0,    0,    0,
    0,    0,  -94,    0,  168,  175,  158,    0,    0, -152,
  -12,    0,    0,    0,  -37,    0,  -11, -152,  -13, -145,
    0, -170, -148,    0, -172,  -22, -152,  103,    0,    0,
  -19,   -2,   67,    0,   -6,  185,    0,    0, -116,    0,
  112,    0,    0, -170,   26, -148,  173,    0,   -1,    0,
    0,    0,  -30, -142,    0,  534,  188,  144,  -94,    0,
    0, -152,    0,    0,    0,    0,    0,   25, -220,    0,
    0,    0,  224,   60, -108,   -9,    0,    0,    0,  -32,
  200,  200,   71,    0,  200,  200,  534,    0,    0,  249,
  270,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   -8,    0,    0,    0,   87,  286,    0,    0,    0,   69,
    0,  -15,    0,  102,    0,   95,    0,   32, -108,    0,
  200,  200,  -20,    0,    0,    0,  105,  125,  200,  200,
  412,  312,  412,  302,  377,  353,  555,  200,  324,  139,
    0,  200,  155,  373,  374,  381,  165,  534,  298, -152,
  389,  331,    0,    0,  412,  -89,  200,  200,    0,    0,
    0,  117,  200,  200,  200,  200,  200,  200,  200,  200,
  200,  200,  200,  200,  200,  200,  534,  534,  200,  412,
  371,    0,  376,  412,    0,  391,  392,  200,    0,  249,
    0,  146,    0,  383,  412,    0,  157,  195,    0,  106,
  106,    0,    0,    0,  424,  418,  -78,  -78,  -97,  -97,
  -97,  -97,  412,  471,  492,  330,    0,    0,    0,    0,
  138,  180,  390,  200,  200,    0,    0,  534,    0,    0,
    0,    0,  393,    0,  412,    0,  513,    0,    0,
};
static const YYINT yyrindex[] = {                      -125,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  448,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  196,  197,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   37,    0,    0,   40,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  191,    0,    0,    0,    0,    0,    0,  161,
    0,    0,    0,    0,    0,    0,    0,  161,    0,    0,
    0,    0,    0,    0,    0,    0,  161,    0,    0,    0,
  199,  205,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  196,  344,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  191,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   45,    0,    0,    0,    0,    0,    0,  426,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  131,    0,  -41,    0,    0,    0,    0,    0,    0,    0,
  411,    1,  414,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  161,
    0,    0,    0,    0,  416,    0,  163,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  417,
    0,    0,    0,  419,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  433,  174,    0,    0,    0,    0,    7,
   42,    0,    0,    0,  384,   34,   -5,  162,   36,   66,
   72,   96,  421,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  141,    0,    0,  -35,    0,    0,    0,
    0,    0,    0,    0,  423,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
 -140, -136,    0,    0,    0,    0,    0,  359,    0,    0,
    0,    0,    0,  235,    0,    0,    0,  201,    0,    0,
  284,    0,    0,    0,    0,    0,    0,  -82,    0,    0,
    0,    0,  -34,  405,  400,    0,  375,    0,    0,    0,
    0,  479,  -14,  101,    0,  485,    0,  477,    0,    0,
  378,  -66,    0,    0,  482,  460,  429,  388,    0,  -16,
    0,  394,    0,    0,  397,  379,  333,    0,
};
#define YYTABLESIZE 842
static const YYINT yytable[] = {                        155,
   68,   46,  155,  254,  133,  152,  197,   69,  152,   46,
  134,  101,   56,  199,   62,   70,   23,  155,   28,  217,
  118,  128,    4,  152,  210,   80,    8,   15,  181,  100,
   80,    9,   99,    1,  179,  140,   37,  203,  140,   62,
   81,  150,   13,   89,  150,  102,  174,  135,   16,  180,
  135,  155,  202,  140,   29,   30,   54,  152,  182,  150,
  199,    4,   17,   18,   19,  135,   71,  250,  106,   69,
  218,  173,   38,   39,  147,  179,  142,  147,   12,  142,
   67,   15,  136,   70,  108,  136,   37,  140,  117,   62,
  213,   23,  147,  150,  142,   67,  274,  275,   70,  135,
  136,    8,   16,  117,   90,  109,  143,  123,   28,  143,
  122,   44,  144,  199,  108,  144,   51,   18,   19,  110,
  111,  112,   38,   39,  143,   45,  147,   57,  142,   43,
  144,   61,   37,   53,  136,  109,  145,  199,  199,  145,
   91,   92,   60,  252,  105,   30,   63,  297,  133,  138,
  111,  112,  127,   64,  145,  122,   84,  259,  143,   66,
  199,   58,  134,   67,  144,    7,   59,   78,   38,   39,
    7,  223,  224,  225,  226,  227,   73,   74,  292,  223,
  224,  225,  226,  227,  169,   72,  283,  122,  145,  122,
  223,  224,  225,  226,  227,   82,   85,  286,  228,  229,
  285,   82,  141,   91,   82,  141,   91,   87,  230,  231,
  232,  233,  234,  235,   92,   88,   89,   92,   44,   97,
  141,  232,  233,  234,  235,  119,  133,  155,  155,  155,
  155,  155,   45,  152,  152,  152,  152,  152,  155,  190,
  134,  116,  155,  155,  152,   96,  155,  155,  152,  152,
  124,  120,  152,  152,  141,  132,  155,  155,  155,  155,
  155,  155,  152,  152,  152,  152,  152,  152,  121,  150,
  150,  150,  150,  150,  140,  135,  135,  125,  140,  140,
  150,  172,  140,  140,  150,  150,  135,  287,  150,  150,
  135,  135,  140,  140,  135,  135,   59,  131,  150,  150,
  150,  150,  150,  150,  135,  135,  135,  135,  135,  135,
  136,  136,  168,  147,  176,  142,  177,  147,  147,  142,
  142,  136,  147,  142,  142,  136,  136,  194,  201,  136,
  136,  207,  208,  142,  142,  142,  142,  142,  142,  136,
  136,  136,  136,  136,  136,  143,  204,  205,  206,  143,
  143,  144,  212,  143,  143,  144,  144,  203,  211,  144,
  144,  219,  236,  143,  143,  143,  143,  143,  143,  144,
  144,  144,  144,  144,  144,  145,  225,  226,  227,  145,
  145,  220,  242,  145,  145,  223,  224,  225,  226,  227,
  129,  129,  129,  145,  145,  145,  145,  145,  145,  161,
  130,  130,  130,  243,  228,  229,  223,  224,  225,  226,
  227,  245,  246,  247,  230,  231,  232,  233,  234,  235,
  248,  249,  251,  253,  146,  228,  229,  146,  210,  277,
  161,  279,  280,  161,  278,  230,  231,  232,  233,  234,
  235,  141,  146,  284,  293,  141,  141,    5,  294,  141,
  141,  298,   98,   99,  105,   84,  183,  184,  185,  141,
  141,   85,  186,  223,  224,  225,  226,  227,   27,   40,
  187,  133,   41,  188,   42,   46,  146,   45,  134,   44,
  161,   43,  228,  229,  282,  296,  104,  135,   27,  189,
   14,  161,  230,  231,  232,  233,  234,  235,  126,  191,
  193,   55,   52,  195,  196,  140,  175,   79,  103,  171,
  139,  214,  170,  178,    0,  141,  142,    0,    0,  143,
  161,  161,    0,  144,    0,    0,    0,  145,    0,    0,
    0,  146,  147,  161,  148,  149,    0,    0,    0,  215,
  216,    0,    0,  198,    0,    0,    0,  221,  222,    0,
    0,    0,    0,    0,    0,    0,  240,  161,  161,    0,
  244,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  161,    0,    0,    0,    0,  258,    0,    0,    0,
  161,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,    0,    0,  276,  223,  224,
  225,  226,  227,    0,    0,    0,  281,    0,    0,    0,
    0,    0,    0,  238,  291,    0,    0,  228,  229,    0,
    0,  223,  224,  225,  226,  227,    0,  230,  231,  232,
  233,  234,  235,    0,    0,    0,  238,    0,    0,    0,
  228,  229,  295,    0,    0,  223,  224,  225,  226,  227,
  230,  231,  232,  233,  234,  235,  237,    0,    0,    0,
    0,    0,    0,  146,  228,  229,    0,  146,  146,    0,
    0,  146,  146,    0,  230,  231,  232,  233,  234,  235,
  223,  224,  225,  226,  227,    0,  223,  224,  225,  226,
  227,    0,  223,  224,  225,  226,  227,    0,    0,  228,
  229,    0,    0,    0,    0,  228,    0,    0,    0,  230,
  231,  232,  233,  234,  235,  230,  231,  232,  233,  234,
  235,  230,  231,  232,  233,  234,  235,  140,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  141,  142,    0,
    0,  143,    0,    0,    0,  144,    0,    0,  140,  145,
    0,  288,  289,  146,  147,    0,  148,  149,  141,  142,
    0,    0,  143,    0,    0,    0,  144,    0,    0,  140,
  145,    0,    0,    0,  146,  147,  290,  148,  149,  141,
  142,    0,    0,  143,    0,    0,    0,  144,    0,    0,
  140,  145,    0,    0,  299,  146,  147,    0,  148,  149,
  141,  142,    0,    0,  143,    0,    0,    0,  144,    0,
    0,  140,  145,    0,    0,    0,  146,  147,    0,  148,
  149,  141,  142,    0,    0,  143,    0,    0,    0,  144,
    0,    0,    0,  145,    0,    0,    0,  239,  147,    0,
  148,  149,
};
static const YYINT yycheck[] = {                         41,
  125,   40,   44,   93,   46,   41,  147,   42,   44,   40,
   46,   78,   27,  150,   31,   40,  257,   59,  257,   40,
   87,  104,  257,   59,   40,   44,  291,  257,   61,   41,
   44,  296,   44,  276,   44,   41,  257,   46,   44,   56,
   59,   41,  277,   59,   44,   59,  129,   41,  278,   59,
   44,   93,   61,   59,  293,  294,  297,   93,   91,   59,
  197,  257,  292,  293,  294,   59,   91,  208,   83,  104,
   91,  292,  293,  294,   41,   44,   41,   44,  123,   44,
   44,  257,   41,   44,  257,   44,  257,   93,   44,  106,
   59,  257,   59,   93,   59,   59,  237,  238,   59,   93,
   59,  291,  278,   59,  257,  278,   41,   41,  257,   44,
   44,  257,   41,  250,  257,   44,  292,  293,  294,  292,
  293,  294,  293,  294,   59,  271,   93,   27,   93,  257,
   59,   31,  257,  123,   93,  278,   41,  274,  275,   44,
  293,  294,  271,  210,  293,  294,  123,  288,  257,  292,
  293,  294,   41,  257,   59,   44,   56,   41,   93,   40,
  297,  266,  271,  257,   93,  291,  271,   40,  293,  294,
  296,  269,  270,  271,  272,  273,  293,  294,   41,  269,
  270,  271,  272,  273,   41,  257,   41,   44,   93,   44,
  269,  270,  271,  272,  273,  291,  291,   41,  288,  289,
   44,   41,   41,   41,   44,   44,   44,   40,  298,  299,
  300,  301,  302,  303,   41,   41,   59,   44,  257,  257,
   59,  300,  301,  302,  303,  123,  257,  269,  270,  271,
  272,  273,  271,  269,  270,  271,  272,  273,  280,   40,
  271,  264,  284,  285,  280,  258,  288,  289,  284,  285,
  257,  271,  288,  289,   93,  257,  298,  299,  300,  301,
  302,  303,  298,  299,  300,  301,  302,  303,  271,  269,
  270,  271,  272,  273,  280,  269,  270,   93,  284,  285,
  280,  257,  288,  289,  284,  285,  280,   93,  288,  289,
  284,  285,  298,  299,  288,  289,  271,  125,  298,  299,
  300,  301,  302,  303,  298,  299,  300,  301,  302,  303,
  269,  270,  125,  280,   91,  280,  257,  284,  285,  284,
  285,  280,  289,  288,  289,  284,  285,  257,   59,  288,
  289,   46,  264,  298,  299,  300,  301,  302,  303,  298,
  299,  300,  301,  302,  303,  280,  260,  261,  262,  284,
  285,  280,  258,  288,  289,  284,  285,   46,  257,  288,
  289,  257,   61,  298,  299,  300,  301,  302,  303,  298,
  299,  300,  301,  302,  303,  280,  271,  272,  273,  284,
  285,  257,   59,  288,  289,  269,  270,  271,  272,  273,
  260,  261,  262,  298,  299,  300,  301,  302,  303,  116,
  260,  261,  262,  265,  288,  289,  269,  270,  271,  272,
  273,  257,   40,   40,  298,  299,  300,  301,  302,  303,
   40,  257,  125,   93,   41,  288,  289,   44,   40,   59,
  147,   41,   41,  150,   59,  298,  299,  300,  301,  302,
  303,  280,   59,   61,  265,  284,  285,    0,   59,  288,
  289,   59,  257,  257,  264,  257,  257,  258,  259,  298,
  299,  257,  263,  269,  270,  271,  272,  273,  125,   59,
  271,   46,   59,  274,   59,   59,   93,   59,   46,   59,
  197,   59,  288,  289,  250,  285,   82,  113,   10,  290,
    6,  208,  298,  299,  300,  301,  302,  303,   99,  141,
  142,   25,   21,  145,  146,  257,  129,   48,   80,  122,
  114,  179,  119,  135,   -1,  267,  268,   -1,   -1,  271,
  237,  238,   -1,  275,   -1,   -1,   -1,  279,   -1,   -1,
   -1,  283,  284,  250,  286,  287,   -1,   -1,   -1,  181,
  182,   -1,   -1,  295,   -1,   -1,   -1,  189,  190,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  198,  274,  275,   -1,
  202,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  288,   -1,   -1,   -1,   -1,  218,   -1,   -1,   -1,
  297,  223,  224,  225,  226,  227,  228,  229,  230,  231,
  232,  233,  234,  235,  236,   -1,   -1,  239,  269,  270,
  271,  272,  273,   -1,   -1,   -1,  248,   -1,   -1,   -1,
   -1,   -1,   -1,  284,  285,   -1,   -1,  288,  289,   -1,
   -1,  269,  270,  271,  272,  273,   -1,  298,  299,  300,
  301,  302,  303,   -1,   -1,   -1,  284,   -1,   -1,   -1,
  288,  289,  284,   -1,   -1,  269,  270,  271,  272,  273,
  298,  299,  300,  301,  302,  303,  280,   -1,   -1,   -1,
   -1,   -1,   -1,  280,  288,  289,   -1,  284,  285,   -1,
   -1,  288,  289,   -1,  298,  299,  300,  301,  302,  303,
  269,  270,  271,  272,  273,   -1,  269,  270,  271,  272,
  273,   -1,  269,  270,  271,  272,  273,   -1,   -1,  288,
  289,   -1,   -1,   -1,   -1,  288,   -1,   -1,   -1,  298,
  299,  300,  301,  302,  303,  298,  299,  300,  301,  302,
  303,  298,  299,  300,  301,  302,  303,  257,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,   -1,
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
#define YYMAXTOKEN 303
#define YYUNDFTOKEN 374
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
"BREAK","CONTINUE","AND","OR","NOT","DECL","ENDDECL","INT","STR","RETURN",
"CLASS","ENDCLASS","EQ","NEQ","LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
#line 782 "ast.y"

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
#line 724 "y.tab.c"

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
#line 70 "ast.y"
	{}
break;
case 2:
#line 71 "ast.y"
	{}
break;
case 3:
#line 72 "ast.y"
	{}
break;
case 4:
#line 73 "ast.y"
	{}
break;
case 5:
#line 74 "ast.y"
	{	
																		printf("\n⛔ No Code Provided\n");
																		exit(1);
																	}
break;
case 6:
#line 83 "ast.y"
	{ printTypeTable(); }
break;
case 8:
#line 87 "ast.y"
	{}
break;
case 9:
#line 88 "ast.y"
	{}
break;
case 10:
#line 92 "ast.y"
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
#line 109 "ast.y"
	{ yyval.TTNode = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); }
break;
case 12:
#line 112 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[-1].FLNode;
												}
break;
case 13:
#line 118 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = 0;
													fieldListHead = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[0].FLNode;
				 								}
break;
case 14:
#line 126 "ast.y"
	{ 
													yyval.FLNode = FLCreateNode(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-2].TTNode); 
													++typeFieldCount;
												}
break;
case 15:
#line 132 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 16:
#line 133 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 17:
#line 134 "ast.y"
	{ yyval.TTNode = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 18:
#line 141 "ast.y"
	{ CTPrint(); }
break;
case 19:
#line 144 "ast.y"
	{}
break;
case 20:
#line 145 "ast.y"
	{}
break;
case 21:
#line 151 "ast.y"
	{ 
														FLPrint(yystack.l_mark[-4].CTNode->className);
														MFLPrint(yystack.l_mark[-4].CTNode->className);

														memFuncListHead = NULL;
														memFuncListTail = NULL;
														currentClassTable = NULL;
					 								}
break;
case 22:
#line 164 "ast.y"
	{
														currentClassTable->memberField = yystack.l_mark[-2].FLNode;
														currentClassTable->virtualFunctionPtr = memFuncListHead;
														currentClassTable->fieldCount = fieldListTail->fieldIndex + 1;
														currentClassTable->methodCount = memFuncListTail->funcPosition;
													}
break;
case 23:
#line 172 "ast.y"
	{ 
														yyval.CTNode = CTInstall(yystack.l_mark[0].node->nodeName, NULL); 
														currentClassTable = yyval.CTNode;
													}
break;
case 24:
#line 178 "ast.y"
	{}
break;
case 25:
#line 179 "ast.y"
	{}
break;
case 26:
#line 182 "ast.y"
	{ 
														MFLInstall(yystack.l_mark[-4].node->nodeName, yystack.l_mark[-5].TTNode, paramListHead);
														/*  printParamList(paramListHead); */
														flushParamList();
													}
break;
case 27:
#line 189 "ast.y"
	{}
break;
case 28:
#line 194 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 29:
#line 195 "ast.y"
	{}
break;
case 39:
#line 202 "ast.y"
	{ ++statementCount; }
break;
case 40:
#line 205 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 41:
#line 208 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 42:
#line 211 "ast.y"
	{ 
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
												}
break;
case 43:
#line 215 "ast.y"
	{	 
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
												}
break;
case 44:
#line 220 "ast.y"
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
#line 230 "ast.y"
	{
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);
												}
break;
case 46:
#line 237 "ast.y"
	{}
break;
case 47:
#line 240 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 48:
#line 245 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 49:
#line 246 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 50:
#line 249 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 51:
#line 252 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 52:
#line 255 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 53:
#line 258 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 54:
#line 261 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 55:
#line 266 "ast.y"
	{
												GSTPrint(); 
												printTypeTable();					
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 56:
#line 272 "ast.y"
	{}
break;
case 57:
#line 275 "ast.y"
	{}
break;
case 58:
#line 276 "ast.y"
	{}
break;
case 59:
#line 279 "ast.y"
	{}
break;
case 60:
#line 280 "ast.y"
	{ 
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												FLPrint(yystack.l_mark[-3].TTNode->typeName);

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentGDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 61:
#line 294 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 62:
#line 295 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 63:
#line 296 "ast.y"
	{ 
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {
													printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}
			 								}
break;
case 64:
#line 303 "ast.y"
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
#line 313 "ast.y"
	{}
break;
case 66:
#line 314 "ast.y"
	{}
break;
case 67:
#line 317 "ast.y"
	{ 
												int varSize = (currentGDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentGDeclType->size);
												GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, varSize, NULL); 
											}
break;
case 68:
#line 321 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 69:
#line 328 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 70:
#line 334 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 71:
#line 341 "ast.y"
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
#line 354 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 73:
#line 359 "ast.y"
	{ 
																	yyval.FLNode = yystack.l_mark[-1].FLNode; 

																	if (currentGDeclType != NULL)
																		currentGDeclType->size = tupleFieldCount;
																	if (currentLDeclType != NULL)
																		currentLDeclType->size = tupleFieldCount;		
																}
break;
case 74:
#line 369 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[-2].FLNode;
																}
break;
case 75:
#line 375 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = 0;
																	fieldListHead = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[0].FLNode;
																}
break;
case 76:
#line 383 "ast.y"
	{
																	yyval.FLNode = FLCreateNode(yystack.l_mark[0].node->nodeName, yystack.l_mark[-1].TTNode);
																	++tupleFieldCount;
																}
break;
case 77:
#line 389 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 78:
#line 390 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 79:
#line 393 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 401 "ast.y"
	{}
break;
case 81:
#line 402 "ast.y"
	{}
break;
case 82:
#line 403 "ast.y"
	{}
break;
case 83:
#line 406 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 84:
#line 412 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 85:
#line 413 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 86:
#line 414 "ast.y"
	{  }
break;
case 87:
#line 415 "ast.y"
	{  }
break;
case 88:
#line 416 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 89:
#line 425 "ast.y"
	{ yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 90:
#line 426 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 91:
#line 427 "ast.y"
	{}
break;
case 92:
#line 430 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 93:
#line 436 "ast.y"
	{}
break;
case 94:
#line 437 "ast.y"
	{}
break;
case 95:
#line 440 "ast.y"
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
#line 462 "ast.y"
	{
															/* char* currentFuncName = getCurrentFuncName();*/

															/* // TODO: Pls check!!!*/
															/* // addFunctionLST(currentFuncName, LSTHead);	*/
															
															/* fprintf(filePtr, "F%d:\n", GSTLookup(currentFuncName)->fLabel);*/
															/* initFuncCalle(filePtr, paramCount);*/

															/* printASTTable($4, 0);*/
															/* codeGen($4, filePtr);*/

															/* LSTPrint();*/
															/* flushLST();*/
															/* paramCount = 0;*/
														}
break;
case 97:
#line 480 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															/* LSTAddParams();*/
															flushParamList();
														}
break;
case 98:
#line 486 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 99:
#line 487 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 100:
#line 488 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 101:
#line 489 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 102:
#line 490 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 103:
#line 493 "ast.y"
	{
															/* struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, $2, NULL, $3);*/
															/* $$ = funcBodyStmt;*/
														}
break;
case 105:
#line 503 "ast.y"
	{  
											/* printTupleList();*/
										}
break;
case 106:
#line 506 "ast.y"
	{}
break;
case 107:
#line 509 "ast.y"
	{}
break;
case 108:
#line 510 "ast.y"
	{}
break;
case 109:
#line 513 "ast.y"
	{}
break;
case 110:
#line 514 "ast.y"
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
case 111:
#line 528 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 112:
#line 529 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 113:
#line 530 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 114:
#line 537 "ast.y"
	{
											if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
												printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}					
											currentLDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
											yyval.TTNode = currentLDeclType;
										}
break;
case 115:
#line 547 "ast.y"
	{}
break;
case 116:
#line 548 "ast.y"
	{}
break;
case 117:
#line 551 "ast.y"
	{ 
											int varSize = (currentLDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentLDeclType->size);							
											LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, varSize); 
										}
break;
case 118:
#line 555 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 119:
#line 562 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 120:
#line 578 "ast.y"
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
case 121:
#line 597 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 122:
#line 600 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 126:
#line 615 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 127:
#line 621 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 128:
#line 628 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 129:
#line 634 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 130:
#line 635 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 131:
#line 645 "ast.y"
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
case 132:
#line 672 "ast.y"
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
case 133:
#line 702 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 134:
#line 703 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 135:
#line 711 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 136:
#line 712 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 137:
#line 713 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 138:
#line 714 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 139:
#line 715 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 140:
#line 716 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 141:
#line 717 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 142:
#line 718 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 143:
#line 719 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 144:
#line 720 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 145:
#line 721 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 146:
#line 722 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 147:
#line 723 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 148:
#line 724 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 149:
#line 725 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 150:
#line 726 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 151:
#line 727 "ast.y"
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
case 152:
#line 747 "ast.y"
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
case 153:
#line 756 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 154:
#line 764 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 155:
#line 772 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 156:
#line 776 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 157:
#line 777 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 158:
#line 778 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1864 "y.tab.c"
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
