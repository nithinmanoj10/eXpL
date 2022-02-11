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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 66 "y.tab.c"

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
    0,    0,    0,    0,    0,   39,   39,   44,   44,   45,
   29,   34,   34,   33,   28,   28,   28,   40,   46,   46,
   47,   38,   48,   48,   50,   49,    1,    1,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    3,    4,
    5,    5,    5,    5,   15,   14,    6,    6,    9,   10,
   11,   12,   13,   41,   41,   53,   53,   54,   54,   30,
   30,   30,   30,   55,   55,   56,   56,   56,   56,   56,
   20,   37,   36,   36,   35,   32,   32,   27,   51,   51,
   51,   57,   58,   58,   58,   58,   58,   19,   19,   19,
   18,   42,   42,    7,   59,   60,   62,   62,   62,   62,
   62,   17,   61,   61,   61,   63,   63,   64,   64,   31,
   31,   31,   31,   65,   65,   66,   66,   66,   43,   67,
   16,   52,   52,   52,   23,   24,   22,   25,   25,   21,
   21,   26,   26,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,
};
static const YYINT yylen[] = {                            2,
    5,    4,    3,    4,    2,    3,    0,    2,    1,    4,
    1,    2,    1,    3,    1,    1,    1,    3,    2,    1,
    8,    1,    2,    1,    6,    1,    3,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    3,    6,    4,    3,    1,    3,    7,    5,    5,    5,
    1,    1,    1,    3,    2,    2,    1,    3,    4,    1,
    1,    1,    2,    3,    1,    1,    4,    4,    1,    4,
    2,    3,    3,    1,    2,    1,    1,    1,    3,    1,
    0,    2,    1,    1,    2,    2,    1,    3,    1,    0,
    1,    2,    1,    1,    5,    5,    1,    1,    2,    2,
    1,    5,    3,    0,    2,    2,    1,    3,    4,    1,
    1,    1,    2,    3,    1,    1,    4,    2,    7,    2,
    5,    1,    1,    1,    4,    5,    4,    2,    5,    3,
    3,    1,    4,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    3,    1,    4,
    4,    2,    2,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   11,    0,    0,    9,    0,    0,    0,
    0,    0,    6,    8,   62,    0,   55,   60,   61,    0,
    0,   57,   22,    0,    0,   20,    0,  101,    0,    0,
    0,    3,   93,    0,    0,    0,   17,   15,   16,    0,
   13,    0,   63,    0,    0,    0,    0,    0,    0,   65,
   54,   56,    0,   18,   19,    0,    2,  120,   99,  100,
    4,   92,    0,   94,    0,    0,    0,   10,   12,    0,
    0,   71,   76,   77,    0,   74,    0,    0,    0,    0,
   58,    0,    1,    0,    0,    0,    0,   14,   87,    0,
    0,    0,   80,    0,    0,   78,   75,    0,   72,    0,
   59,   64,    0,  112,    0,  105,  110,  111,    0,    0,
  107,    0,    0,    0,    0,   85,   86,    0,   68,   82,
   67,   73,   70,    0,    0,   24,  113,    0,    0,    0,
    0,  115,  103,  106,    0,    0,    0,    0,   53,    0,
    0,    0,   51,   52,    0,    0,   29,   30,   31,   32,
   33,   34,   35,   36,   37,    0,  124,  122,  123,    0,
    0,   38,   95,   96,    0,   79,    0,    0,    0,   23,
    0,  118,    0,    0,  108,    0,    0,    0,  155,  156,
  157,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  109,  114,    0,    0,    0,    0,  153,  152,  147,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   27,
    0,    0,  130,    0,    0,    0,  131,    0,  119,    0,
   21,  117,    0,    0,   89,    0,    0,  148,    0,    0,
  136,  137,  138,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   46,  102,  127,  125,    0,
    0,    0,    0,    0,  150,    0,    0,   48,   49,   50,
  126,    0,   25,    0,   88,    0,  121,   47,
};
static const YYINT yydgoto[] = {                          2,
  145,  146,  147,  148,  149,  150,   65,  254,  151,  152,
  153,  154,  155,  195,  239,  204,  113,  255,  256,   47,
  187,  157,  158,  159,  160,  161,   97,   40,    5,   20,
  109,   75,   41,   42,   76,   77,   48,   24,    3,   10,
   11,   31,   32,    6,    7,   25,   26,  125,  208,  126,
   92,  162,   21,   22,   49,   50,   93,   94,   33,   34,
   85,   35,  110,  111,  131,  132,   36,
};
static const YYINT yysindex[] = {                      -242,
 -216,    0, -144,    0,  -60, -237,    0, -222, -184, -210,
 -172, -155,    0,    0,    0, -151,    0,    0,    0,  -38,
 -202,    0,    0,    9, -240,    0, -172,    0,  -99, -147,
 -172,    0,    0,   11, -127,  145,    0,    0,    0, -121,
    0, -124,    0,  -27,  -71, -137,  156, -192,  -21,    0,
    0,    0,  -94,    0,    0, -172,    0,    0,    0,    0,
    0,    0,  -84,    0,  168,  175,  164,    0,    0, -148,
  -32,    0,    0,    0,  -33,    0,  -11, -148,  -16, -192,
    0, -155,    0, -196,  -22, -148,  123,    0,    0,   -2,
   26,   71,    0,   -1,  158,    0,    0, -137,    0,  146,
    0,    0, -155,    0,   21,    0,    0,    0,  -30, -189,
    0,  506,  127,  154,  -84,    0,    0, -148,    0,    0,
    0,    0,    0,   25, -143,    0,    0,  207,   56, -129,
  -15,    0,    0,    0,  -42,  200,  200,   58,    0,  200,
  200,  506,    0,    0,  242,  258,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -14,    0,    0,    0,   87,
  282,    0,    0,    0,   65,    0,  -13, -140,   75,    0,
   95,    0,   15, -129,    0,  200,  200,  -24,    0,    0,
    0,   76,  101,  200,  200,  405,  313,  405,  301,  359,
  382,  527,  200,  304,  118,    0,  200,  125,  364,  372,
  373,  157,  506,  296, -148,  151, -140,  298,  389,  331,
    0,    0,  405,  -89,  200,  200,    0,    0,    0,  117,
  200,  200,  200,  200,  200,  200,  200,  200,  200,  200,
  200,  200,  200,  200,  506,  506,  200,  405,  375,    0,
  376,  405,    0,  390,  391,  200,    0,  242,    0,  160,
    0,    0,  383,  405,    0,  161,  195,    0,  106,  106,
    0,    0,    0,  417,  426, -109, -109,  -95,  -95,  -95,
  -95,  405,  464,  281,  335,    0,    0,    0,    0,  138,
  180,  393,  200,  200,    0,    0,  506,    0,    0,    0,
    0,  394,    0,  405,    0,  485,    0,    0,
};
static const YYINT yyrindex[] = {                      -123,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  448,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  192,  197,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   40,    0,    0,   64,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  191,    0,    0,    0,    0,    0,    0,  174,
    0,    0,    0,    0,    0,    0,    0,  174,    0,    0,
    0,    0,    0,    0,    0,  174,    0,    0,    0,  199,
  205,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  191,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   67,    0,    0,
    0,    0,    0,    0,  423,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  131,    0,  -41,    0,    0,
    0,    0,    0,    0,    0,  411,    1,  413,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  174,  192,  348,    0,    0,    0,
    0,    0,  416,    0,  176,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  419,    0,    0,
    0,  420,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  430,  181,    0,    0,    0,    0,    7,   42,
    0,    0,    0,  384,   34,   -5,  162,   36,   66,   72,
   96,  422,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  141,    0,    0,  -35,    0,    0,    0,    0,
    0,    0,    0,  427,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
 -116, -130,    0,    0,    0,    0,    0,  366,    0,    0,
    0,    0,    0,  234,    0,    0,    0,  201,    0,    0,
  288,    0,    0,    0,    0,    0,    0,  -72,    0,    0,
    0,    0,  -34,  406,  402,    0,  378,    0,    0,    0,
  479,  -20,   -6,    0,  486,    0,  476,    0,    0,  379,
  -64,    0,    0,  484,  460,  431,  396,    0,  -19,    0,
  397,    0,    0,  408,  385,  342,    0,
};
#define YYTABLESIZE 814
static const YYINT yytable[] = {                        154,
   68,   46,  154,  253,  132,  151,   56,   69,  151,   46,
  133,   62,   70,  100,  194,  215,   23,  154,  176,    4,
   57,  114,   80,  151,   61,  192,  205,   80,  174,   99,
  124,  198,   98,    1,   15,  139,   62,   81,  139,   13,
    4,  149,  101,  175,  149,   88,  197,  134,  177,   83,
  134,  154,  169,  139,   15,   16,   54,  151,  174,  149,
  104,  194,   12,   71,   44,  134,  216,  104,   69,   17,
   18,   19,   23,  211,  146,   16,  141,  146,   45,  141,
    8,  105,  135,   66,   28,  135,  248,  139,  105,   51,
   18,   19,  146,  149,  141,  106,  107,  108,   66,  134,
  135,   37,  133,  107,  108,   43,  142,   69,   89,  142,
  116,  119,  143,   37,  118,  143,   28,  194,  273,  274,
   29,   30,   69,   60,  142,  116,  146,  128,  141,   64,
  143,   53,   37,   63,  135,   67,  144,   38,   39,  144,
  250,  129,  194,  194,   90,   91,    8,  207,  168,   38,
   39,    9,  206,   30,  144,   73,   74,  258,  142,  221,
  222,  223,  224,  225,  143,  194,   58,    7,   38,   39,
  296,   59,    7,  221,  222,  223,  224,  225,  291,  221,
  222,  223,  224,  225,   66,   72,  123,   62,  144,  118,
  230,  231,  232,  233,  164,   78,   82,  118,  226,  227,
  282,  285,  140,  118,  284,  140,   84,   86,  228,  229,
  230,  231,  232,  233,   81,   87,   90,   81,   44,   90,
  140,   91,   88,   96,   91,   95,  128,  154,  154,  154,
  154,  154,   45,  151,  151,  151,  151,  151,  154,  185,
  129,  112,  154,  154,  151,  115,  154,  154,  151,  151,
  121,  163,  151,  151,  140,  120,  154,  154,  154,  154,
  154,  154,  151,  151,  151,  151,  151,  151,  116,  149,
  149,  149,  149,  149,  139,  134,  134,  127,  139,  139,
  149,  167,  139,  139,  149,  149,  134,  286,  149,  149,
  134,  134,  139,  139,  134,  134,  117,  171,  149,  149,
  149,  149,  149,  149,  134,  134,  134,  134,  134,  134,
  135,  135,  172,  146,  189,  141,  196,  146,  146,  141,
  141,  135,  146,  141,  141,  135,  135,  202,  203,  135,
  135,  209,  217,  141,  141,  141,  141,  141,  141,  135,
  135,  135,  135,  135,  135,  142,  199,  200,  201,  142,
  142,  143,  210,  142,  142,  143,  143,  218,  198,  143,
  143,  234,  240,  142,  142,  142,  142,  142,  142,  143,
  143,  143,  143,  143,  143,  144,  223,  224,  225,  144,
  144,  243,  241,  144,  144,  221,  222,  223,  224,  225,
  128,  128,  128,  144,  144,  144,  144,  144,  144,  156,
  129,  129,  129,  244,  226,  227,  221,  222,  223,  224,
  225,  245,  246,  247,  228,  229,  230,  231,  232,  233,
  249,   59,  251,  252,  145,  226,  227,  145,  205,  156,
  278,  279,  156,  276,  277,  228,  229,  230,  231,  232,
  233,  140,  145,  283,  292,  140,  140,    5,   97,  140,
  140,  293,  297,   98,  104,   83,  178,  179,  180,  140,
  140,   84,  181,  221,  222,  223,  224,  225,  132,   39,
  182,   40,   26,  183,   41,  133,  145,   45,   44,  156,
   43,  281,  226,  227,  295,   42,  130,  103,   27,  184,
  156,   14,  228,  229,  230,  231,  232,  233,  135,  122,
   55,  186,  188,  170,   52,  190,  191,   79,  136,  137,
  102,  165,  138,  166,  173,  212,  139,  134,    0,    0,
  140,    0,  156,  156,  141,  142,    0,  143,  144,    0,
    0,    0,    0,    0,    0,  156,  193,  135,    0,    0,
    0,  213,  214,    0,    0,    0,    0,  136,  137,  219,
  220,  138,    0,    0,    0,  139,    0,    0,  238,  140,
  156,  156,  242,  141,  142,  289,  143,  144,    0,    0,
    0,    0,    0,    0,  156,    0,    0,    0,    0,    0,
    0,  257,    0,  156,    0,    0,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
    0,    0,  275,  221,  222,  223,  224,  225,    0,    0,
    0,  280,    0,    0,    0,    0,    0,    0,  236,  290,
    0,    0,  226,  227,    0,    0,    0,  221,  222,  223,
  224,  225,  228,  229,  230,  231,  232,  233,  235,    0,
    0,    0,    0,    0,    0,    0,  226,  227,  294,    0,
  221,  222,  223,  224,  225,    0,  228,  229,  230,  231,
  232,  233,    0,  145,    0,  236,    0,  145,  145,  226,
  227,  145,  145,  221,  222,  223,  224,  225,    0,  228,
  229,  230,  231,  232,  233,  221,  222,  223,  224,  225,
    0,    0,  226,  227,  221,  222,  223,  224,  225,    0,
    0,    0,  228,  229,  230,  231,  232,  233,    0,    0,
    0,    0,    0,  226,  228,  229,  230,  231,  232,  233,
  135,    0,    0,  228,  229,  230,  231,  232,  233,    0,
  136,  137,    0,    0,  138,    0,    0,    0,  139,    0,
    0,  135,  140,    0,  287,  288,  141,  142,    0,  143,
  144,  136,  137,    0,    0,  138,    0,    0,    0,  139,
    0,    0,  135,  140,    0,    0,  298,  141,  142,    0,
  143,  144,  136,  137,    0,    0,  138,    0,    0,    0,
  139,    0,    0,  135,  140,    0,    0,    0,  141,  142,
    0,  143,  144,  136,  137,    0,    0,  138,    0,    0,
    0,  139,    0,    0,    0,  140,    0,    0,    0,  237,
  142,    0,  143,  144,
};
static const YYINT yycheck[] = {                         41,
  125,   40,   44,   93,   46,   41,   27,   42,   44,   40,
   46,   31,   40,   78,  145,   40,  257,   59,   61,  257,
   27,   86,   44,   59,   31,  142,   40,   44,   44,   41,
  103,   46,   44,  276,  257,   41,   56,   59,   44,  277,
  257,   41,   59,   59,   44,   59,   61,   41,   91,   56,
   44,   93,  125,   59,  257,  278,  297,   93,   44,   59,
  257,  192,  123,   91,  257,   59,   91,  257,  103,  292,
  293,  294,  257,   59,   41,  278,   41,   44,  271,   44,
  291,  278,   41,   44,  257,   44,  203,   93,  278,  292,
  293,  294,   59,   93,   59,  292,  293,  294,   59,   93,
   59,  257,  292,  293,  294,  257,   41,   44,  257,   44,
   44,   41,   41,  257,   44,   44,  257,  248,  235,  236,
  293,  294,   59,  271,   59,   59,   93,  257,   93,  257,
   59,  123,  257,  123,   93,  257,   41,  293,  294,   44,
  205,  271,  273,  274,  293,  294,  291,  168,  292,  293,
  294,  296,  293,  294,   59,  293,  294,   41,   93,  269,
  270,  271,  272,  273,   93,  296,  266,  291,  293,  294,
  287,  271,  296,  269,  270,  271,  272,  273,   41,  269,
  270,  271,  272,  273,   40,  257,   41,  207,   93,   44,
  300,  301,  302,  303,   41,   40,  291,   44,  288,  289,
   41,   41,   41,   44,   44,   44,  291,   40,  298,  299,
  300,  301,  302,  303,   41,   41,   41,   44,  257,   44,
   59,   41,   59,  257,   44,  258,  257,  269,  270,  271,
  272,  273,  271,  269,  270,  271,  272,  273,  280,   40,
  271,  264,  284,  285,  280,  123,  288,  289,  284,  285,
   93,  125,  288,  289,   93,  257,  298,  299,  300,  301,
  302,  303,  298,  299,  300,  301,  302,  303,  271,  269,
  270,  271,  272,  273,  280,  269,  270,  257,  284,  285,
  280,  257,  288,  289,  284,  285,  280,   93,  288,  289,
  284,  285,  298,  299,  288,  289,  271,   91,  298,  299,
  300,  301,  302,  303,  298,  299,  300,  301,  302,  303,
  269,  270,  257,  280,  257,  280,   59,  284,  285,  284,
  285,  280,  289,  288,  289,  284,  285,   46,  264,  288,
  289,  257,  257,  298,  299,  300,  301,  302,  303,  298,
  299,  300,  301,  302,  303,  280,  260,  261,  262,  284,
  285,  280,  258,  288,  289,  284,  285,  257,   46,  288,
  289,   61,   59,  298,  299,  300,  301,  302,  303,  298,
  299,  300,  301,  302,  303,  280,  271,  272,  273,  284,
  285,  257,  265,  288,  289,  269,  270,  271,  272,  273,
  260,  261,  262,  298,  299,  300,  301,  302,  303,  112,
  260,  261,  262,   40,  288,  289,  269,  270,  271,  272,
  273,   40,   40,  257,  298,  299,  300,  301,  302,  303,
  125,  271,  125,   93,   41,  288,  289,   44,   40,  142,
   41,   41,  145,   59,   59,  298,  299,  300,  301,  302,
  303,  280,   59,   61,  265,  284,  285,    0,  257,  288,
  289,   59,   59,  257,  264,  257,  257,  258,  259,  298,
  299,  257,  263,  269,  270,  271,  272,  273,   46,   59,
  271,   59,  125,  274,   59,   46,   93,   59,   59,  192,
   59,  248,  288,  289,  284,   59,  109,   82,   10,  290,
  203,    6,  298,  299,  300,  301,  302,  303,  257,   98,
   25,  136,  137,  125,   21,  140,  141,   48,  267,  268,
   80,  115,  271,  118,  130,  174,  275,  110,   -1,   -1,
  279,   -1,  235,  236,  283,  284,   -1,  286,  287,   -1,
   -1,   -1,   -1,   -1,   -1,  248,  295,  257,   -1,   -1,
   -1,  176,  177,   -1,   -1,   -1,   -1,  267,  268,  184,
  185,  271,   -1,   -1,   -1,  275,   -1,   -1,  193,  279,
  273,  274,  197,  283,  284,  285,  286,  287,   -1,   -1,
   -1,   -1,   -1,   -1,  287,   -1,   -1,   -1,   -1,   -1,
   -1,  216,   -1,  296,   -1,   -1,  221,  222,  223,  224,
  225,  226,  227,  228,  229,  230,  231,  232,  233,  234,
   -1,   -1,  237,  269,  270,  271,  272,  273,   -1,   -1,
   -1,  246,   -1,   -1,   -1,   -1,   -1,   -1,  284,  285,
   -1,   -1,  288,  289,   -1,   -1,   -1,  269,  270,  271,
  272,  273,  298,  299,  300,  301,  302,  303,  280,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  288,  289,  283,   -1,
  269,  270,  271,  272,  273,   -1,  298,  299,  300,  301,
  302,  303,   -1,  280,   -1,  284,   -1,  284,  285,  288,
  289,  288,  289,  269,  270,  271,  272,  273,   -1,  298,
  299,  300,  301,  302,  303,  269,  270,  271,  272,  273,
   -1,   -1,  288,  289,  269,  270,  271,  272,  273,   -1,
   -1,   -1,  298,  299,  300,  301,  302,  303,   -1,   -1,
   -1,   -1,   -1,  288,  298,  299,  300,  301,  302,  303,
  257,   -1,   -1,  298,  299,  300,  301,  302,  303,   -1,
  267,  268,   -1,   -1,  271,   -1,   -1,   -1,  275,   -1,
   -1,  257,  279,   -1,  281,  282,  283,  284,   -1,  286,
  287,  267,  268,   -1,   -1,  271,   -1,   -1,   -1,  275,
   -1,   -1,  257,  279,   -1,   -1,  282,  283,  284,   -1,
  286,  287,  267,  268,   -1,   -1,  271,   -1,   -1,   -1,
  275,   -1,   -1,  257,  279,   -1,   -1,   -1,  283,  284,
   -1,  286,  287,  267,  268,   -1,   -1,  271,   -1,   -1,
   -1,  275,   -1,   -1,   -1,  279,   -1,   -1,   -1,  283,
  284,   -1,  286,  287,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 303
#define YYUNDFTOKEN 373
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"ClassDef : ClassName '{' DECL FieldDeclList MethodDeclList ENDDECL MethodDefns '}'",
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
#line 763 "ast.y"

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
#line 716 "y.tab.c"

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
#line 69 "ast.y"
	{}
break;
case 2:
#line 70 "ast.y"
	{}
break;
case 3:
#line 71 "ast.y"
	{}
break;
case 4:
#line 72 "ast.y"
	{}
break;
case 5:
#line 73 "ast.y"
	{	
																		printf("\n⛔ No Code Provided\n");
																		exit(1);
																	}
break;
case 6:
#line 82 "ast.y"
	{ printTypeTable(); }
break;
case 8:
#line 86 "ast.y"
	{}
break;
case 9:
#line 87 "ast.y"
	{}
break;
case 10:
#line 91 "ast.y"
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
#line 108 "ast.y"
	{ yyval.TTNode = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); }
break;
case 12:
#line 111 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[-1].FLNode;
												}
break;
case 13:
#line 117 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = 0;
													fieldListHead = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[0].FLNode;
				 								}
break;
case 14:
#line 125 "ast.y"
	{ 
													yyval.FLNode = FLCreateNode(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-2].TTNode); 
													++typeFieldCount;
												}
break;
case 15:
#line 131 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 16:
#line 132 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 17:
#line 133 "ast.y"
	{ yyval.TTNode = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 18:
#line 140 "ast.y"
	{ CTPrint(); }
break;
case 19:
#line 143 "ast.y"
	{}
break;
case 20:
#line 144 "ast.y"
	{}
break;
case 21:
#line 153 "ast.y"
	{ 
														yystack.l_mark[-7].CTNode->memberField = yystack.l_mark[-4].FLNode;
														yystack.l_mark[-7].CTNode->virtualFunctionPtr = memFuncListHead;
														yystack.l_mark[-7].CTNode->fieldCount = fieldListTail->fieldIndex + 1;
														yystack.l_mark[-7].CTNode->methodCount = memFuncListTail->funcPosition;

														FLPrint(yystack.l_mark[-7].CTNode->className);
														MFLPrint(yystack.l_mark[-7].CTNode->className);

														memFuncListHead = NULL;
														memFuncListTail = NULL;
					 								}
break;
case 22:
#line 167 "ast.y"
	{ yyval.CTNode = CTInstall(yystack.l_mark[0].node->nodeName, NULL); }
break;
case 23:
#line 170 "ast.y"
	{}
break;
case 24:
#line 171 "ast.y"
	{}
break;
case 25:
#line 174 "ast.y"
	{ 
														MFLInstall(yystack.l_mark[-4].node->nodeName, yystack.l_mark[-5].TTNode, paramListHead);
														printParamList(paramListHead); 
														flushParamList();
													}
break;
case 26:
#line 181 "ast.y"
	{}
break;
case 27:
#line 186 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 28:
#line 187 "ast.y"
	{}
break;
case 38:
#line 194 "ast.y"
	{ ++statementCount; }
break;
case 39:
#line 197 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 40:
#line 200 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 41:
#line 203 "ast.y"
	{ 
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
												}
break;
case 42:
#line 207 "ast.y"
	{	 
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
												}
break;
case 43:
#line 212 "ast.y"
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
case 44:
#line 222 "ast.y"
	{
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);
												}
break;
case 45:
#line 229 "ast.y"
	{}
break;
case 46:
#line 232 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 47:
#line 237 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 48:
#line 238 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 49:
#line 241 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 50:
#line 244 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 51:
#line 247 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 52:
#line 250 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 53:
#line 253 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 54:
#line 258 "ast.y"
	{
												GSTPrint(); 
												printTypeTable();					
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 55:
#line 264 "ast.y"
	{}
break;
case 56:
#line 267 "ast.y"
	{}
break;
case 57:
#line 268 "ast.y"
	{}
break;
case 58:
#line 271 "ast.y"
	{}
break;
case 59:
#line 272 "ast.y"
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
case 60:
#line 286 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 61:
#line 287 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 62:
#line 288 "ast.y"
	{ 
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {
													printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}
			 								}
break;
case 63:
#line 295 "ast.y"
	{ 
												if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
													printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}					
												currentGDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
												yyval.TTNode = currentGDeclType;
											}
break;
case 64:
#line 305 "ast.y"
	{}
break;
case 65:
#line 306 "ast.y"
	{}
break;
case 66:
#line 309 "ast.y"
	{ 
												int varSize = (currentGDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentGDeclType->size);
												GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, varSize, NULL); 
											}
break;
case 67:
#line 313 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 68:
#line 320 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 69:
#line 326 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 70:
#line 333 "ast.y"
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
case 71:
#line 346 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 72:
#line 351 "ast.y"
	{ 
																	yyval.FLNode = yystack.l_mark[-1].FLNode; 

																	if (currentGDeclType != NULL)
																		currentGDeclType->size = tupleFieldCount;
																	if (currentLDeclType != NULL)
																		currentLDeclType->size = tupleFieldCount;		
																}
break;
case 73:
#line 361 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[-2].FLNode;
																}
break;
case 74:
#line 367 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = 0;
																	fieldListHead = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[0].FLNode;
																}
break;
case 75:
#line 375 "ast.y"
	{
																	yyval.FLNode = FLCreateNode(yystack.l_mark[0].node->nodeName, yystack.l_mark[-1].TTNode);
																	++tupleFieldCount;
																}
break;
case 76:
#line 381 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 77:
#line 382 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 78:
#line 385 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 79:
#line 393 "ast.y"
	{}
break;
case 80:
#line 394 "ast.y"
	{}
break;
case 81:
#line 395 "ast.y"
	{}
break;
case 82:
#line 398 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 83:
#line 404 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 84:
#line 405 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 85:
#line 406 "ast.y"
	{  }
break;
case 86:
#line 407 "ast.y"
	{  }
break;
case 87:
#line 408 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 88:
#line 417 "ast.y"
	{ yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 89:
#line 418 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 90:
#line 419 "ast.y"
	{}
break;
case 91:
#line 422 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 428 "ast.y"
	{}
break;
case 93:
#line 429 "ast.y"
	{}
break;
case 94:
#line 432 "ast.y"
	{ 
															/* if(GSTLookup($1->nodeName) == NULL){*/
															/* 	printf("\nFunction %s is not declared\n", $1->nodeName);*/
															/* 	exit(1);*/
															/* }*/
															/* $$ = $1; */
															/* setCurrentFuncName($1->nodeName);*/
														}
break;
case 95:
#line 443 "ast.y"
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
case 96:
#line 461 "ast.y"
	{
															/* verifyFunctionSignature($2->nodeName);*/
															/* LSTAddParams();*/
															flushParamList();
														}
break;
case 97:
#line 467 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 98:
#line 468 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 99:
#line 469 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 100:
#line 470 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 101:
#line 471 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 102:
#line 474 "ast.y"
	{
															/* struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, $2, NULL, $3);*/
															/* $$ = funcBodyStmt;*/
														}
break;
case 104:
#line 484 "ast.y"
	{  
											/* printTupleList();*/
										}
break;
case 105:
#line 487 "ast.y"
	{}
break;
case 106:
#line 490 "ast.y"
	{}
break;
case 107:
#line 491 "ast.y"
	{}
break;
case 108:
#line 494 "ast.y"
	{}
break;
case 109:
#line 495 "ast.y"
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
case 110:
#line 509 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 111:
#line 510 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 112:
#line 511 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 113:
#line 518 "ast.y"
	{
											if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
												printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}					
											currentLDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
											yyval.TTNode = currentLDeclType;
										}
break;
case 114:
#line 528 "ast.y"
	{}
break;
case 115:
#line 529 "ast.y"
	{}
break;
case 116:
#line 532 "ast.y"
	{ 
											int varSize = (currentLDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentLDeclType->size);							
											LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, varSize); 
										}
break;
case 117:
#line 536 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 118:
#line 543 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 119:
#line 559 "ast.y"
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
case 120:
#line 578 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 121:
#line 581 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 125:
#line 596 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 126:
#line 602 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 127:
#line 609 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 128:
#line 615 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 129:
#line 616 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 130:
#line 626 "ast.y"
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
case 131:
#line 653 "ast.y"
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
case 132:
#line 683 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 133:
#line 684 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 134:
#line 692 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 135:
#line 693 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 136:
#line 694 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 137:
#line 695 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 138:
#line 696 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 139:
#line 697 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 140:
#line 698 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 141:
#line 699 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 142:
#line 700 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 143:
#line 701 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 144:
#line 702 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 145:
#line 703 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 146:
#line 704 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 147:
#line 705 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 148:
#line 706 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 149:
#line 707 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 150:
#line 708 "ast.y"
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
case 151:
#line 728 "ast.y"
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
case 152:
#line 737 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 153:
#line 745 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 154:
#line 753 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 155:
#line 757 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 156:
#line 758 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 157:
#line 759 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1837 "y.tab.c"
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
