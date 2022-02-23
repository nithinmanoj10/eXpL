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
   64,   64,   17,   63,   63,   63,   65,   65,   66,   66,
   32,   32,   32,   32,   67,   67,   68,   68,   68,   46,
   69,   16,   54,   54,   54,   54,   23,   24,   22,   28,
   25,   25,   70,   21,   21,   21,   26,   26,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,
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
    2,    1,    5,    3,    2,    0,    2,    1,    3,    4,
    1,    1,    1,    2,    3,    1,    1,    4,    2,    7,
    2,    5,    1,    1,    1,    1,    4,    5,    4,    5,
    2,    5,    4,    3,    3,    3,    1,    4,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    3,    1,    1,    4,    4,    2,    2,    1,
    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   11,    0,    0,    9,    0,    0,    0,
    0,    0,    6,    8,   63,    0,   56,   61,   62,    0,
    0,   58,   23,   20,    0,    0,    0,  102,    0,    0,
    0,    3,   94,    0,    0,    0,   17,   15,   16,    0,
   13,    0,   64,    0,    0,    0,    0,    0,    0,   66,
   55,   57,    0,   18,   19,    0,    2,  121,  100,  101,
    4,   93,    0,   95,    0,    0,    0,   10,   12,    0,
    0,   72,   77,   78,    0,   75,    0,    0,    0,    0,
   59,    0,    0,    1,    0,    0,    0,    0,   14,   88,
    0,    0,    0,   81,    0,    0,   79,   76,    0,   73,
    0,   60,   65,    0,    0,    0,    0,  113,    0,  105,
  111,  112,    0,    0,  108,    0,    0,    0,    0,   86,
   87,    0,   69,   83,   68,   74,   71,    0,    0,   25,
   21,  114,    0,    0,    0,    0,  116,  104,  107,    0,
    0,    0,    0,   54,    0,    0,    0,   52,   53,    0,
    0,    0,   30,   31,   32,   33,   34,   35,   36,   37,
   38,    0,  125,  123,  124,    0,    0,  126,   39,   96,
   97,    0,   80,    0,   22,    0,   24,    0,  119,    0,
    0,  109,    0,    0,    0,  161,  162,  163,    0,    0,
    0,    0,    0,    0,  155,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   29,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  110,  115,    0,
    0,    0,    0,  159,  158,  152,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  136,    0,    0,   28,    0,
    0,  134,    0,    0,    0,    0,  135,    0,  120,    0,
  118,    0,    0,   90,    0,    0,  153,    0,    0,  141,
  142,  143,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   47,  103,  129,  127,    0,
    0,    0,    0,    0,    0,  156,    0,  133,    0,   49,
   50,   51,  128,  130,    0,   26,    0,   89,    0,  122,
   48,
};
static const YYINT yydgoto[] = {                          2,
  151,  152,  153,  154,  155,  156,   65,  263,  157,  158,
  159,  160,  161,  204,  248,  214,  117,  264,  265,   47,
  194,  163,  164,  165,  166,  167,   98,  168,   40,    5,
   20,  113,   75,   24,   41,   42,   76,   77,   48,   25,
   83,    3,   10,   11,   31,   32,    6,    7,   26,  107,
  129,  130,   93,  169,   21,   22,   49,   50,   94,   95,
   33,   34,   86,   35,  114,  115,  136,  137,   36,  195,
};
static const YYINT yysindex[] = {                      -245,
 -223,    0, -168,    0,  -54, -231,    0, -230, -167, -189,
 -222, -219,    0,    0,    0, -143,    0,    0,    0,  -38,
 -196,    0,    0,    0,   12, -240, -222,    0, -102, -117,
 -222,    0,    0,   33,  -91,  128,    0,    0,    0,  -62,
    0, -118,    0,  -21,  -55, -121,  166, -229,  -13,    0,
    0,    0,  -85,    0,    0, -222,    0,    0,    0,    0,
    0,    0,  -78,    0,  184,  185,  169,    0,    0, -213,
  -17,    0,    0,    0,  -14,    0,  -11, -213,   -3, -229,
    0, -219, -147,    0, -172,  -18, -213,  130,    0,    0,
   11,   17,   93,    0,   22,  201,    0,    0, -121,    0,
  131,    0,    0, -219,   27, -147,  175,    0,   61,    0,
    0,    0,  -30, -141,    0,  437,  210,  150,  -78,    0,
    0, -213,    0,    0,    0,    0,    0,   94, -202,    0,
    0,    0,  251,   95, -171,   52,    0,    0,    0,  -24,
  212,  212,  104,    0,  212,  212,  437,    0,    0,  304,
  357,  297,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   67,    0,    0,    0,  -61,  316,    0,    0,    0,
    0,  101,    0,   49,    0,  108,    0,  109,    0,   73,
 -171,    0,  212,  212,  -20,    0,    0,    0,  124,  125,
  212,  212,  537,   85,    0,  537,  322,  495,  516,  451,
  129,  212,  337,  132,    0,  212,  140,  366,  367,  368,
  369,  160,  437,  293, -213,  379,  327,    0,    0,  537,
  -92,  212,  212,    0,    0,    0,  121,  212,  212,  212,
  212,  212,  212,  212,  212,  212,  212,  212,  212,  212,
  212,  212,  437,  437,  212,    0,  537,  370,    0,  371,
  537,    0,  386,  387,  212,  212,    0,  357,    0,  152,
    0,  388,  537,    0,  254,  222,    0,  -16,  -16,    0,
    0,    0,  558,  271,  573,  573,  -86,  -86,  -86,  -86,
  275,  537,  281,  383,  470,    0,    0,    0,    0,  142,
  163,  174,  389,  212,  212,    0,    0,    0,  437,    0,
    0,    0,    0,    0,  391,    0,  537,    0,  405,    0,
    0,
};
static const YYINT yyrindex[] = {                      -129,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  454,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  194,  200,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   82,    0,    0,   98,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  195,    0,    0,    0,    0,    0,    0,  279,
    0,    0,    0,    0,    0,    0,    0,  279,    0,    0,
    0,    0,    0,    0,    0,    0,  279,    0,    0,    0,
  202,  204,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  194,  347,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  195,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  100,    0,    0,    0,    0,    0,    0,  416,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -44,    0,  -41,    0,    0,    0,    0,    0,
    0,    0,  415,    1,    0,  417,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  279,    0,    0,    0,    0,  418,
    0,  286,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  286,    0,    0,    0,    0,    0,  419,    0,    0,    0,
  420,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  434,  290,    0,    0,    0,    0,    7,   43,    0,
    0,    0,   -5,  414,  346,  397,   36,   68,   74,   99,
    0,  422,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -39,    0,    0,  -35,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  423,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
 -139, -138,    0,    0,    0,    0,    0,  356,    0,    0,
    0,    0,    0,  225,    0,    0,    0,  190,  245,    0,
  -94,    0,    0,    0,    0,    0,    0,    0,  -89,    0,
    0,    0,    0,  462,  -26,  407,  392,    0,  393,    0,
    0,    0,    0,  489,  -15,   -6,    0,  494,    0,    0,
    0,  375,  -64,    0,    0,  484,  460,  430,  394,    0,
  -27,    0,  395,    0,    0,  399,  380,  336,    0,    0,
};
#define YYTABLESIZE 878
static const YYINT yytable[] = {                        160,
  262,   46,  160,   62,  137,  157,   68,  200,  157,   46,
  138,   56,  203,  101,  128,   69,   23,  160,   70,  222,
   57,  162,  118,  157,   61,    4,   15,   44,   62,  100,
   80,    1,   99,    4,   28,  150,  183,   37,  150,  176,
   80,  154,   45,   90,  154,   81,   13,  139,   16,   84,
  139,  160,  162,  150,   37,  102,  162,  157,   54,  154,
   15,  203,   17,   18,   19,  139,  184,  106,   12,   71,
  223,   29,   30,  258,   38,   39,  146,   69,   62,  146,
   91,   92,   16,  140,  108,  133,  140,  150,  215,   23,
  175,   38,   39,  154,  146,  181,   51,   18,   19,  139,
  134,  140,    8,  283,  284,  162,  109,   89,  147,   28,
  182,  147,  207,   43,  148,  108,  181,  148,  162,  203,
  110,  111,  112,    8,  241,   67,  147,  206,  146,    9,
  207,  218,  148,  123,   53,  140,  122,  109,   37,  149,
   67,   70,  149,  117,  203,  203,  105,   30,  162,  162,
  260,  138,  111,  112,   60,   63,   70,  149,  117,  309,
  147,  267,    7,  162,   58,   64,  148,   66,    7,   59,
  203,  127,   73,   74,  122,   38,   39,  228,  229,  230,
  231,  232,  303,  228,  229,  230,  231,  232,  162,  162,
  171,  149,  293,  122,   67,  122,  233,  234,  208,  209,
  210,   72,  211,  304,  162,   78,   82,  235,  236,  237,
  238,  239,  240,   85,  162,  131,  131,  131,   44,  131,
  132,  132,  132,   87,  132,   88,  133,   89,  160,  160,
  160,  160,  160,   45,  157,  157,  157,  157,  157,  160,
   96,  134,   97,  160,  160,  157,  116,  160,  160,  157,
  157,  192,  119,  157,  157,  230,  231,  232,  160,  160,
  160,  160,  160,  160,  157,  157,  157,  157,  157,  157,
  154,  154,  154,  154,  154,  150,  139,  139,  124,  150,
  150,  154,  120,  150,  150,  154,  154,  139,  121,  154,
  154,  139,  139,  125,  296,  139,  139,  295,   59,  131,
  154,  154,  154,  154,  154,  154,  139,  139,  139,  139,
  139,  139,  140,  140,  297,  298,  146,  132,  295,   82,
  146,  146,   82,  140,  146,  146,   91,  140,  140,   91,
   92,  140,  140,   92,  170,  146,  146,  146,  146,  146,
  146,  178,  140,  140,  140,  140,  140,  140,  147,  201,
  174,  179,  147,  147,  148,  205,  147,  147,  148,  148,
  197,  212,  148,  148,  216,  213,  217,  147,  147,  147,
  147,  147,  147,  148,  148,  148,  148,  148,  148,  149,
  224,  225,  242,  149,  149,  246,  144,  149,  149,  144,
  228,  229,  230,  231,  232,  249,  252,  250,  149,  149,
  149,  149,  149,  149,  144,  253,  254,  255,  256,  233,
  234,  228,  229,  230,  231,  232,  257,  259,  215,  261,
  235,  236,  237,  238,  239,  240,  288,  289,  286,  287,
  233,  234,  228,  229,  230,  231,  232,  145,  144,  305,
  145,  235,  236,  237,  238,  239,  240,  306,  294,  310,
   98,  233,  234,    5,  151,  145,   99,  151,   84,  106,
   85,  137,  235,  236,  237,  238,  239,  240,  185,  186,
  187,   27,  151,   40,  188,   41,   42,   46,   45,  138,
   44,   43,  292,  189,  308,  281,  190,   55,  104,  145,
  126,  228,  229,  230,  231,  232,  193,  196,   27,   14,
  198,  199,  191,  177,   52,  135,  151,   79,  150,  103,
  233,  234,  139,  172,  180,  173,  219,    0,    0,    0,
    0,  235,  236,  237,  238,  239,  240,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  140,  220,  221,
  228,  229,  230,  231,  232,    0,  226,  227,  141,  142,
    0,    0,  143,    0,    0,    0,  144,  247,    0,  233,
  145,  251,  299,  300,  146,  147,    0,  148,  149,    0,
  235,  236,  237,  238,  239,  240,    0,  150,  266,    0,
    0,    0,    0,  268,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,    0,  282,    0,    0,
  285,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  290,  291,    0,  140,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  141,  142,  144,    0,  143,    0,
  144,  144,  144,    0,  144,  144,  145,    0,    0,  140,
  146,  147,    0,  148,  149,  144,  144,    0,    0,  307,
  141,  142,  202,  150,  143,    0,    0,    0,  144,    0,
    0,  140,  145,    0,    0,    0,  146,  147,  301,  148,
  149,    0,  141,  142,    0,    0,  143,  145,    0,  150,
  144,  145,  145,    0,  145,  145,  145,  311,  146,  147,
    0,  148,  149,  140,  151,    0,  145,  145,  151,  151,
    0,  150,    0,  151,  141,  142,    0,  140,  143,    0,
    0,    0,  144,    0,    0,    0,  145,    0,  141,  142,
  146,  147,  143,  148,  149,    0,  144,    0,    0,    0,
  145,    0,    0,  150,  245,  147,    0,  148,  149,  228,
  229,  230,  231,  232,    0,    0,    0,  150,    0,    0,
    0,    0,    0,    0,  244,  302,    0,    0,  233,  234,
    0,    0,    0,    0,  228,  229,  230,  231,  232,  235,
  236,  237,  238,  239,  240,  243,    0,    0,    0,    0,
    0,    0,    0,  233,  234,  228,  229,  230,  231,  232,
    0,    0,    0,    0,  235,  236,  237,  238,  239,  240,
  244,    0,    0,    0,  233,  234,  228,  229,  230,  231,
  232,    0,    0,    0,    0,  235,  236,  237,  238,  239,
  240,    0,    0,    0,    0,  233,  234,  228,  229,  230,
  231,  232,    0,    0,    0,    0,  235,  236,  237,  238,
  239,  240,  228,  229,  230,  231,  232,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  235,  236,  237,
  238,  239,  240,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  237,  238,  239,  240,
};
static const YYINT yycheck[] = {                         41,
   93,   40,   44,   31,   46,   41,  125,  147,   44,   40,
   46,   27,  151,   78,  104,   42,  257,   59,   40,   40,
   27,  116,   87,   59,   31,  257,  257,  257,   56,   41,
   44,  277,   44,  257,  257,   41,   61,  257,   44,  129,
   44,   41,  272,  257,   44,   59,  278,   41,  279,   56,
   44,   93,  147,   59,  257,   59,  151,   93,  299,   59,
  257,  200,  293,  294,  295,   59,   91,   83,  123,   91,
   91,  294,  295,  213,  294,  295,   41,  104,  106,   44,
  294,  295,  279,   41,  257,  257,   44,   93,   40,  257,
  293,  294,  295,   93,   59,   44,  293,  294,  295,   93,
  272,   59,  292,  243,  244,  200,  279,   59,   41,  257,
   59,   44,   46,  257,   41,  257,   44,   44,  213,  258,
  293,  294,  295,  292,   40,   44,   59,   61,   93,  298,
   46,   59,   59,   41,  123,   93,   44,  279,  257,   41,
   59,   44,   44,   44,  283,  284,  294,  295,  243,  244,
  215,  293,  294,  295,  272,  123,   59,   59,   59,  299,
   93,   41,  292,  258,  267,  257,   93,   40,  298,  272,
  309,   41,  294,  295,   44,  294,  295,  270,  271,  272,
  273,  274,   41,  270,  271,  272,  273,  274,  283,  284,
   41,   93,   41,   44,  257,   44,  289,  290,  260,  261,
  262,  257,  264,   41,  299,   40,  292,  300,  301,  302,
  303,  304,  305,  292,  309,  260,  261,  262,  257,  264,
  260,  261,  262,   40,  264,   41,  257,   59,  270,  271,
  272,  273,  274,  272,  270,  271,  272,  273,  274,  281,
  258,  272,  257,  285,  286,  281,  265,  289,  290,  285,
  286,   40,  123,  289,  290,  272,  273,  274,  300,  301,
  302,  303,  304,  305,  300,  301,  302,  303,  304,  305,
  270,  271,  272,  273,  274,  281,  270,  271,  257,  285,
  286,  281,  272,  289,  290,  285,  286,  281,  272,  289,
  290,  285,  286,   93,   41,  289,  290,   44,  272,  125,
  300,  301,  302,  303,  304,  305,  300,  301,  302,  303,
  304,  305,  270,  271,   93,   41,  281,  257,   44,   41,
  285,  286,   44,  281,  289,  290,   41,  285,  286,   44,
   41,  289,  290,   44,  125,  300,  301,  302,  303,  304,
  305,   91,  300,  301,  302,  303,  304,  305,  281,   46,
  257,  257,  285,  286,  281,   59,  289,  290,  285,  286,
  257,   46,  289,  290,  257,  265,  258,  300,  301,  302,
  303,  304,  305,  300,  301,  302,  303,  304,  305,  281,
  257,  257,   61,  285,  286,  257,   41,  289,  290,   44,
  270,  271,  272,  273,  274,   59,  257,  266,  300,  301,
  302,  303,  304,  305,   59,   40,   40,   40,   40,  289,
  290,  270,  271,  272,  273,  274,  257,  125,   40,   93,
  300,  301,  302,  303,  304,  305,   41,   41,   59,   59,
  289,  290,  270,  271,  272,  273,  274,   41,   93,  266,
   44,  300,  301,  302,  303,  304,  305,   59,   61,   59,
  257,  289,  290,    0,   41,   59,  257,   44,  257,  265,
  257,   46,  300,  301,  302,  303,  304,  305,  257,  258,
  259,  125,   59,   59,  263,   59,   59,   59,   59,   46,
   59,   59,  258,  272,  295,  241,  275,   26,   82,   93,
   99,  270,  271,  272,  273,  274,  141,  142,   10,    6,
  145,  146,  291,  129,   21,  113,   93,   48,  297,   80,
  289,  290,  114,  119,  135,  122,  181,   -1,   -1,   -1,
   -1,  300,  301,  302,  303,  304,  305,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  183,  184,
  270,  271,  272,  273,  274,   -1,  191,  192,  268,  269,
   -1,   -1,  272,   -1,   -1,   -1,  276,  202,   -1,  289,
  280,  206,  282,  283,  284,  285,   -1,  287,  288,   -1,
  300,  301,  302,  303,  304,  305,   -1,  297,  223,   -1,
   -1,   -1,   -1,  228,  229,  230,  231,  232,  233,  234,
  235,  236,  237,  238,  239,  240,   -1,  242,   -1,   -1,
  245,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  255,  256,   -1,  257,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  268,  269,  281,   -1,  272,   -1,
  285,  286,  276,   -1,  289,  290,  280,   -1,   -1,  257,
  284,  285,   -1,  287,  288,  300,  301,   -1,   -1,  294,
  268,  269,  296,  297,  272,   -1,   -1,   -1,  276,   -1,
   -1,  257,  280,   -1,   -1,   -1,  284,  285,  286,  287,
  288,   -1,  268,  269,   -1,   -1,  272,  281,   -1,  297,
  276,  285,  286,   -1,  280,  289,  290,  283,  284,  285,
   -1,  287,  288,  257,  281,   -1,  300,  301,  285,  286,
   -1,  297,   -1,  290,  268,  269,   -1,  257,  272,   -1,
   -1,   -1,  276,   -1,   -1,   -1,  280,   -1,  268,  269,
  284,  285,  272,  287,  288,   -1,  276,   -1,   -1,   -1,
  280,   -1,   -1,  297,  284,  285,   -1,  287,  288,  270,
  271,  272,  273,  274,   -1,   -1,   -1,  297,   -1,   -1,
   -1,   -1,   -1,   -1,  285,  286,   -1,   -1,  289,  290,
   -1,   -1,   -1,   -1,  270,  271,  272,  273,  274,  300,
  301,  302,  303,  304,  305,  281,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  289,  290,  270,  271,  272,  273,  274,
   -1,   -1,   -1,   -1,  300,  301,  302,  303,  304,  305,
  285,   -1,   -1,   -1,  289,  290,  270,  271,  272,  273,
  274,   -1,   -1,   -1,   -1,  300,  301,  302,  303,  304,
  305,   -1,   -1,   -1,   -1,  289,  290,  270,  271,  272,
  273,  274,   -1,   -1,   -1,   -1,  300,  301,  302,  303,
  304,  305,  270,  271,  272,  273,  274,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  300,  301,  302,
  303,  304,  305,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  302,  303,  304,  305,
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
#line 1040 "ast.y"

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
#line 749 "y.tab.c"

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
#line 565 "ast.y"
	{  
											/* printTupleList();*/
											isFuncDef = 1;	
										}
break;
case 105:
#line 569 "ast.y"
	{ isFuncDef = 1; }
break;
case 106:
#line 570 "ast.y"
	{ isFuncDef = 1; }
break;
case 107:
#line 573 "ast.y"
	{}
break;
case 108:
#line 574 "ast.y"
	{}
break;
case 109:
#line 577 "ast.y"
	{}
break;
case 110:
#line 578 "ast.y"
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
#line 592 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 112:
#line 593 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 113:
#line 594 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 114:
#line 601 "ast.y"
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
#line 611 "ast.y"
	{}
break;
case 116:
#line 612 "ast.y"
	{}
break;
case 117:
#line 615 "ast.y"
	{ 
											int varSize = (currentLDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentLDeclType->size);							
											LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, varSize); 
										}
break;
case 118:
#line 619 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 119:
#line 626 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 120:
#line 642 "ast.y"
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
#line 661 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 122:
#line 664 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 127:
#line 680 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 128:
#line 686 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 129:
#line 693 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 130:
#line 699 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
													}
break;
case 131:
#line 706 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 132:
#line 707 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 133:
#line 717 "ast.y"
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

														if (classVariablePtr->nodeType == SELF_NODE)
															classVariablePtr->nodeType = SELF_FUNC_NODE;
														else
															classVariablePtr->nodeType = MEM_FUNC_NODE;
													}
break;
case 134:
#line 743 "ast.y"
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
case 135:
#line 809 "ast.y"
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
case 136:
#line 890 "ast.y"
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
case 137:
#line 922 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 138:
#line 923 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 139:
#line 933 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 140:
#line 934 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 141:
#line 935 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 142:
#line 936 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 143:
#line 937 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 144:
#line 938 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 145:
#line 939 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 146:
#line 940 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 147:
#line 941 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 148:
#line 942 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 149:
#line 943 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 150:
#line 944 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 151:
#line 945 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 152:
#line 946 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 153:
#line 947 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 154:
#line 948 "ast.y"
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
case 155:
#line 967 "ast.y"
	{  }
break;
case 156:
#line 968 "ast.y"
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
case 157:
#line 988 "ast.y"
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
case 158:
#line 997 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 159:
#line 1005 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 160:
#line 1013 "ast.y"
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
case 161:
#line 1034 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 162:
#line 1035 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 163:
#line 1036 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 2149 "y.tab.c"
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
