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
    8,    8,    8,    8,    8,    8,    8,
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
    7,    2,    2,    1,    1,    1,    1,
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
   25,    0,  121,    0,    0,  111,    0,    0,    0,  165,
  166,  167,    0,    0,    0,    0,    0,    0,  158,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   30,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  112,  117,    0,    0,    0,    0,  163,
  162,  155,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   48,  139,   29,    0,  105,    0,  137,    0,    0,
    0,    0,  138,    0,  122,    0,  120,    0,    0,   91,
    0,    0,  156,    0,    0,  144,  145,  146,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  104,  131,  129,    0,    0,    0,    0,    0,    0,
  159,    0,  136,    0,   50,   51,   52,  130,  132,    0,
   27,    0,   90,    0,    0,  124,    0,   49,  161,
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
static const YYINT yysindex[] = {                      -237,
 -178,    0, -270,    0,   -2, -181,    0, -231, -129, -182,
 -229, -213,    0,    0,    0, -127,    0,    0,    0,  -38,
 -201,    0, -194,    0,   26, -240, -229,    0, -236, -114,
 -229,    0,    0,   49,  -71,  122,    0,    0,    0,  -59,
    0, -117,    0,  -24,  -46, -115,  178, -230,  -10,    0,
    0,    0,  -33,  -70,    0,    0, -229,    0,    0,    0,
    0,    0,    0,  -51,    0,  207,  211,  194,    0,    0,
 -210,    1,    0,    0,    0,   25,    0,   -9, -210,   42,
 -230,    0,    0, -213, -188,    0, -143,   19, -210,  162,
    0,    0,   17,   21,   47,    0,   29,  204,    0,    0,
 -115,    0,   55,    0,    0, -213,   28, -188,  176,    0,
   52,    0,    0,    0,  -30, -119,    0,  388,  193,  115,
  -51,    0,    0, -210,    0,    0,    0,    0,    0,   69,
 -220,    0,    0,    0,  242,   77, -157,   64,    0,    0,
    0,  -40,  181,  181,   81,    0,  181,  181,  426,    0,
    0,  181,  275,  388,  280,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   80,   66,    0,    0,    0,  -58,
  308,    0,    0,    0,    0,   90,    0,  -20,    0,   99,
    0,  108,    0,   76, -157,    0,  181,  181,  -21,    0,
    0,    0,  103,  113,  181,  181,  517,  107,    0,  517,
  304,  187,  480,  452,  517,  327,  131,  332,  126,    0,
  344,  181,  154,  372,  373,  382,  383,  167,  426,  300,
 -210,  392,  340,    0,    0,  517,  -89,  181,  181,    0,
    0,    0,  125,  181,  181,  181,  181,  181,  181,  181,
  181,  181,  181,  181,  181,  181,  181,  181,  426,  426,
  181,    0,    0,    0,  375,    0,  517,    0,  396,  400,
  181,  185,    0,  388,    0,  123,    0,  384,  517,    0,
  129,  209,    0,  -16,  -16,    0,    0,    0,  529,  523,
  349,  349,  -81,  -81,  -81,  -81,  155,  517,  315,  394,
  471,    0,    0,    0,  146,  402,  180,  395,  181,  181,
    0,  364,    0,  426,    0,    0,    0,    0,    0,  408,
    0,  517,    0,  181,  420,    0,  230,    0,    0,
};
static const YYINT yyrindex[] = {                      -174,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  475,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  348,    0,    0,    0,    0,    0,   25,  227,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   82,    0,    0,   85,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  222,    0,    0,    0,    0,    0,    0,
  164,    0,    0,    0,    0,    0,    0,    0,  164,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  164,    0,
    0,    0,  238,  239,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   25,  369,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  222,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  102,    0,    0,    0,    0,    0,
    0,  451,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  140,    0,  -41,    0,
    0,    0,    0,    0,    0,    0,  449,    2,    0,  457,
    0,    0,    0,    0,  458,    0,    0,    0,    0,    0,
    0,  202,    0,    0,    0,    0,    0,    0,    0,    0,
  164,    0,    0,    0,    0,  462,    0,  166,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  166,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  465,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  479,  182,    0,
    0,    0,    0,    9,   46,    0,    0,    0,  278,  328,
  184,  237,   39,   72,   78,  104,    0,  469,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  245,    0,
    0,  -35,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  470,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
 -116, -147,    0,    0,    0,    0,    0,  398,    0,    0,
    0,    0,    0, -153,    0,    0,    0,  240,  283,    0,
  -95,    0,    0,    0,    0,    0,    0,    0,  -76,    0,
    0,    0,    0,  511,  -29,  459,  443,    0,  432,    0,
    0,    0,    0,  538,  -13,   14,    0,  543,    0,    0,
    0,  421,  -64,    0,    0,  530,  505,  473,  431,    0,
  -19,    0,  435,    0,    0,  441,  423,  376,    0,    0,
};
#define YYTABLESIZE 835
static const YYINT yytable[] = {                        164,
  209,   46,  164,  268,  140,  160,  208,   69,  160,   46,
  141,   63,   70,   57,  103,   71,   23,  164,  228,  221,
  187,    8,  166,  160,  120,   15,   44,   28,    9,  130,
   59,  102,  204,   81,  101,   60,   37,   63,   91,    1,
   58,   45,  157,   37,   62,  157,   92,   16,   82,  142,
  188,  164,  142,  166,  180,   15,  208,  160,  166,   55,
  157,   17,   18,   19,   29,   30,   72,  142,   28,  229,
   86,  108,  179,   38,   39,    4,   70,   16,    4,  149,
   38,   39,  149,   93,   94,   81,  143,  125,   63,  143,
  124,   51,   18,   19,  157,  129,   13,  149,  124,  135,
  104,  142,  264,   53,  143,  107,   30,  185,  166,    8,
  297,  213,  150,  110,  136,  150,  208,    7,  151,  185,
   12,  151,  186,  166,    7,   68,  212,   23,   71,   43,
  150,  149,  289,  290,  224,  111,  151,  110,  143,   37,
   68,  208,  208,   71,  152,  119,  247,  152,   54,  112,
  113,  114,  213,  166,  166,  175,  266,   61,  124,  111,
  119,   67,  152,  298,  150,  273,  124,  208,  166,  301,
  151,   64,  300,  140,  113,  114,   38,   39,   74,   75,
  234,  235,  236,  237,  238,   65,  308,  315,  234,  235,
  236,  237,  238,  166,  166,  303,  152,   68,  300,  239,
  240,  214,  215,  216,   83,  217,   92,   83,  166,   92,
   73,  241,  242,  243,  244,  245,  246,   79,   44,  166,
  196,   84,   93,   83,  147,   93,  135,  147,  164,  164,
  164,  164,  164,   45,  160,  160,  160,  160,  160,  164,
   87,  136,  147,  164,  164,  160,   89,  164,  164,  160,
  160,   90,   91,  160,  160,  236,  237,  238,   98,  164,
  164,  164,  164,  164,  164,  160,  160,  160,  160,  160,
  160,  157,  157,  157,  157,  157,  147,  148,  142,  142,
  148,   99,  157,  118,  121,  126,  157,  157,  122,  142,
  157,  157,  123,  142,  142,  148,  127,  142,  142,   60,
  133,  302,  157,  157,  157,  157,  157,  157,  134,  142,
  142,  142,  142,  142,  142,  143,  143,  174,  153,  149,
  207,  153,  319,  149,  149,  178,  143,  149,  149,  148,
  143,  143,  182,  183,  143,  143,  153,  201,  210,  149,
  149,  149,  149,  149,  149,  211,  143,  143,  143,  143,
  143,  143,  150,  218,  219,  222,  150,  150,  151,  230,
  150,  150,  151,  151,  248,  223,  151,  151,  154,  231,
  153,  154,  150,  150,  150,  150,  150,  150,  151,  151,
  151,  151,  151,  151,  152,  252,  154,  253,  152,  152,
  254,  255,  152,  152,  234,  235,  236,  237,  238,  133,
  133,  133,  256,  133,  152,  152,  152,  152,  152,  152,
  258,  259,  260,  239,  240,  234,  235,  236,  237,  238,
  154,  261,  262,  263,  265,  241,  242,  243,  244,  245,
  246,  221,  267,  292,  239,  240,  293,  189,  190,  191,
  294,  296,  309,  192,  299,  310,  241,  242,  243,  244,
  245,  246,  193,  311,  314,  194,  234,  235,  236,  237,
  238,  135,  135,  135,  147,  135,  316,  249,  147,  147,
   23,  195,  147,  147,    5,  239,  240,  153,  234,  235,
  236,  237,  238,  100,  147,  147,  108,  241,  242,  243,
  244,  245,  246,   28,   85,   86,  140,  239,  240,  234,
  235,  236,  237,  238,  134,  134,  134,   41,  134,  241,
  242,  243,  244,  245,  246,   42,   47,  148,  239,  240,
   43,  148,  148,   46,  141,  148,  148,   45,   44,  287,
  241,  242,  243,  244,  245,  246,   56,  148,  148,  313,
  197,  200,  106,  128,  202,  203,  137,   27,   14,  205,
   52,  181,   80,  105,  177,  176,  141,    0,  153,  184,
  225,    0,  153,  153,    0,    0,  153,  153,    0,    0,
    0,  142,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  143,  144,  226,  227,  145,    0,    0,    0,
  146,    0,  232,  233,  147,    0,  304,  305,  148,  149,
    0,  150,  151,    0,    0,    0,    0,    0,  154,  257,
    0,  153,  154,  154,    0,    0,    0,  154,  234,  235,
  236,  237,  238,    0,    0,    0,  272,    0,    0,    0,
    0,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  286,  142,  288,    0,    0,  291,    0,
  142,  243,  244,  245,  246,  143,  144,    0,  295,  145,
    0,  143,  144,  146,    0,  145,    0,  147,    0,  146,
    0,  148,  149,  147,  150,  151,  142,  148,  149,  306,
  150,  151,  142,  152,  153,    0,    0,  143,  144,    0,
  153,  145,    0,  143,  144,  146,  312,  145,    0,  147,
    0,  146,  318,  148,  149,  147,  150,  151,  142,  148,
  149,  317,  150,  151,    0,    0,  153,    0,    0,  143,
  144,    0,  153,  145,    0,    0,    0,  146,    0,    0,
    0,  147,    0,    0,    0,  251,  149,    0,  150,  151,
  234,  235,  236,  237,  238,    0,    0,    0,  153,  234,
  235,  236,  237,  238,    0,  250,  307,    0,    0,  239,
  240,    0,    0,    0,  250,    0,    0,    0,  239,  240,
    0,  241,  242,  243,  244,  245,  246,    0,    0,    0,
  241,  242,  243,  244,  245,  246,  234,  235,  236,  237,
  238,    0,  234,  235,  236,  237,  238,    0,  234,  235,
  236,  237,  238,    0,    0,  239,  240,    0,    0,    0,
    0,  239,    0,    0,    0,    0,    0,  241,  242,  243,
  244,  245,  246,  241,  242,  243,  244,  245,  246,  241,
  242,  243,  244,  245,  246,
};
static const YYINT yycheck[] = {                         41,
  154,   40,   44,   93,   46,   41,  154,  125,   44,   40,
   46,   31,   42,   27,   79,   40,  257,   59,   40,   40,
   61,  292,  118,   59,   89,  257,  257,  257,  299,  106,
  267,   41,  149,   44,   44,  272,  257,   57,   59,  277,
   27,  272,   41,  257,   31,   44,  257,  279,   59,   41,
   91,   93,   44,  149,  131,  257,  204,   93,  154,  300,
   59,  293,  294,  295,  294,  295,   91,   59,  257,   91,
   57,   85,  293,  294,  295,  257,  106,  279,  257,   41,
  294,  295,   44,  294,  295,   44,   41,   41,  108,   44,
   44,  293,  294,  295,   93,   41,  278,   59,   44,  257,
   59,   93,  219,  298,   59,  294,  295,   44,  204,  292,
  264,   46,   41,  257,  272,   44,  264,  292,   41,   44,
  123,   44,   59,  219,  299,   44,   61,  257,   44,  257,
   59,   93,  249,  250,   59,  279,   59,  257,   93,  257,
   59,  289,  290,   59,   41,   44,   40,   44,  123,  293,
  294,  295,   46,  249,  250,   41,  221,  272,   44,  279,
   59,   40,   59,   41,   93,   41,   44,  315,  264,   41,
   93,  123,   44,  293,  294,  295,  294,  295,  294,  295,
  270,  271,  272,  273,  274,  257,   41,  304,  270,  271,
  272,  273,  274,  289,  290,   41,   93,  257,   44,  289,
  290,  260,  261,  262,   41,  264,   41,   44,  304,   44,
  257,  301,  302,  303,  304,  305,  306,   40,  257,  315,
   40,  292,   41,  257,   41,   44,  257,   44,  270,  271,
  272,  273,  274,  272,  270,  271,  272,  273,  274,  281,
  292,  272,   59,  285,  286,  281,   40,  289,  290,  285,
  286,   41,   59,  289,  290,  272,  273,  274,  258,  301,
  302,  303,  304,  305,  306,  301,  302,  303,  304,  305,
  306,  270,  271,  272,  273,  274,   93,   41,  270,  271,
   44,  257,  281,  265,  123,  257,  285,  286,  272,  281,
  289,  290,  272,  285,  286,   59,   93,  289,  290,  272,
  125,   93,  301,  302,  303,  304,  305,  306,  257,  301,
  302,  303,  304,  305,  306,  270,  271,  125,   41,  281,
   46,   44,   93,  285,  286,  257,  281,  289,  290,   93,
  285,  286,   91,  257,  289,  290,   59,  257,   59,  301,
  302,  303,  304,  305,  306,  266,  301,  302,  303,  304,
  305,  306,  281,   46,  265,  257,  285,  286,  281,  257,
  289,  290,  285,  286,   61,  258,  289,  290,   41,  257,
   93,   44,  301,  302,  303,  304,  305,  306,  301,  302,
  303,  304,  305,  306,  281,   59,   59,  257,  285,  286,
   59,  266,  289,  290,  270,  271,  272,  273,  274,  260,
  261,  262,   59,  264,  301,  302,  303,  304,  305,  306,
  257,   40,   40,  289,  290,  270,  271,  272,  273,  274,
   93,   40,   40,  257,  125,  301,  302,  303,  304,  305,
  306,   40,   93,   59,  289,  290,   41,  257,  258,  259,
   41,  257,   41,  263,   61,  266,  301,  302,  303,  304,
  305,  306,  272,   59,   91,  275,  270,  271,  272,  273,
  274,  260,  261,  262,  281,  264,   59,  281,  285,  286,
  123,  291,  289,  290,    0,  289,  290,  297,  270,  271,
  272,  273,  274,  257,  301,  302,  265,  301,  302,  303,
  304,  305,  306,  125,  257,  257,   46,  289,  290,  270,
  271,  272,  273,  274,  260,  261,  262,   59,  264,  301,
  302,  303,  304,  305,  306,   59,   59,  281,  289,  290,
   59,  285,  286,   59,   46,  289,  290,   59,   59,  247,
  301,  302,  303,  304,  305,  306,   26,  301,  302,  300,
  143,  144,   84,  101,  147,  148,  115,   10,    6,  152,
   21,  131,   48,   81,  124,  121,  116,   -1,  281,  137,
  185,   -1,  285,  286,   -1,   -1,  289,  290,   -1,   -1,
   -1,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  268,  269,  187,  188,  272,   -1,   -1,   -1,
  276,   -1,  195,  196,  280,   -1,  282,  283,  284,  285,
   -1,  287,  288,   -1,   -1,   -1,   -1,   -1,  281,  212,
   -1,  297,  285,  286,   -1,   -1,   -1,  290,  270,  271,
  272,  273,  274,   -1,   -1,   -1,  229,   -1,   -1,   -1,
   -1,  234,  235,  236,  237,  238,  239,  240,  241,  242,
  243,  244,  245,  246,  257,  248,   -1,   -1,  251,   -1,
  257,  303,  304,  305,  306,  268,  269,   -1,  261,  272,
   -1,  268,  269,  276,   -1,  272,   -1,  280,   -1,  276,
   -1,  284,  285,  280,  287,  288,  257,  284,  285,  286,
  287,  288,  257,  296,  297,   -1,   -1,  268,  269,   -1,
  297,  272,   -1,  268,  269,  276,  299,  272,   -1,  280,
   -1,  276,  283,  284,  285,  280,  287,  288,  257,  284,
  285,  314,  287,  288,   -1,   -1,  297,   -1,   -1,  268,
  269,   -1,  297,  272,   -1,   -1,   -1,  276,   -1,   -1,
   -1,  280,   -1,   -1,   -1,  284,  285,   -1,  287,  288,
  270,  271,  272,  273,  274,   -1,   -1,   -1,  297,  270,
  271,  272,  273,  274,   -1,  285,  286,   -1,   -1,  289,
  290,   -1,   -1,   -1,  285,   -1,   -1,   -1,  289,  290,
   -1,  301,  302,  303,  304,  305,  306,   -1,   -1,   -1,
  301,  302,  303,  304,  305,  306,  270,  271,  272,  273,
  274,   -1,  270,  271,  272,  273,  274,   -1,  270,  271,
  272,  273,  274,   -1,   -1,  289,  290,   -1,   -1,   -1,
   -1,  289,   -1,   -1,   -1,   -1,   -1,  301,  302,  303,
  304,  305,  306,  301,  302,  303,  304,  305,  306,  301,
  302,  303,  304,  305,  306,
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
"expr : ID '[' expr ']' '[' expr ']'",
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
#line 1153 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at line %d\n", s, sourceLineNumber / 2);
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
#line 746 "y.tab.c"

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

														/* printf("yoo bruhuhh\n");														*/

														/* struct ClassTable* traversalPtr = classTableHead;*/
														/* while(traversalPtr != NULL) {*/
														/* 	MFLPrint(traversalPtr->className);*/
														/* }*/

														CTPrint(); 
														fprintf(filePtr, "L%d:\n", globalDeclStartLabel);	
														initVirtualFuncTable(filePtr);
													}
break;
case 19:
#line 173 "ast.y"
	{}
break;
case 20:
#line 174 "ast.y"
	{}
break;
case 21:
#line 180 "ast.y"
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
#line 211 "ast.y"
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
#line 282 "ast.y"
	{ 
														yyval.CTNode = CTInstall(yystack.l_mark[0].node->nodeName, NULL);
														currentClassTable = yyval.CTNode;
													}
break;
case 24:
#line 286 "ast.y"
	{ 
														yyval.CTNode = CTInstall(yystack.l_mark[-2].node->nodeName, yystack.l_mark[0].node->nodeName);
														currentClassTable = yyval.CTNode;
														currentParentClassTable = CTLookUp(yystack.l_mark[0].node->nodeName);
					 								}
break;
case 25:
#line 293 "ast.y"
	{}
break;
case 26:
#line 294 "ast.y"
	{}
break;
case 27:
#line 297 "ast.y"
	{ 
														MFLInstall(yystack.l_mark[-4].node->nodeName, yystack.l_mark[-5].TTNode, paramListHead);
														/*  printParamList(paramListHead); */
														flushParamList();
														paramCount = 0;
													}
break;
case 28:
#line 305 "ast.y"
	{}
break;
case 29:
#line 310 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 30:
#line 311 "ast.y"
	{}
break;
case 40:
#line 318 "ast.y"
	{ ++statementCount; }
break;
case 41:
#line 321 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 42:
#line 324 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 43:
#line 327 "ast.y"
	{ 
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
												}
break;
case 44:
#line 331 "ast.y"
	{	 
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
												}
break;
case 45:
#line 336 "ast.y"
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
#line 346 "ast.y"
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
#line 367 "ast.y"
	{}
break;
case 48:
#line 370 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 49:
#line 375 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 50:
#line 376 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 51:
#line 379 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 52:
#line 382 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 53:
#line 385 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 54:
#line 388 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 55:
#line 391 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 56:
#line 396 "ast.y"
	{
												GSTPrint(); 
												printTypeTable();
																
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 57:
#line 403 "ast.y"
	{}
break;
case 58:
#line 406 "ast.y"
	{}
break;
case 59:
#line 407 "ast.y"
	{}
break;
case 60:
#line 410 "ast.y"
	{}
break;
case 61:
#line 411 "ast.y"
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
#line 426 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 63:
#line 427 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 64:
#line 428 "ast.y"
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
#line 442 "ast.y"
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
#line 452 "ast.y"
	{}
break;
case 67:
#line 453 "ast.y"
	{}
break;
case 68:
#line 456 "ast.y"
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
#line 466 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 70:
#line 473 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 71:
#line 479 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 72:
#line 486 "ast.y"
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
#line 499 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 74:
#line 504 "ast.y"
	{ 
																	yyval.FLNode = yystack.l_mark[-1].FLNode; 

																	if (currentGDeclType != NULL)
																		currentGDeclType->size = tupleFieldCount;
																	if (currentLDeclType != NULL)
																		currentLDeclType->size = tupleFieldCount;		
																}
break;
case 75:
#line 514 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[-2].FLNode;
																}
break;
case 76:
#line 520 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = 0;
																	fieldListHead = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[0].FLNode;
																}
break;
case 77:
#line 528 "ast.y"
	{
																	yyval.FLNode = FLCreateNode(yystack.l_mark[0].node->nodeName, yystack.l_mark[-1].TTNode, NULL);
																	++tupleFieldCount;
																}
break;
case 78:
#line 534 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 79:
#line 535 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 80:
#line 538 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 546 "ast.y"
	{}
break;
case 82:
#line 547 "ast.y"
	{}
break;
case 83:
#line 548 "ast.y"
	{}
break;
case 84:
#line 551 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 85:
#line 557 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 86:
#line 558 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 87:
#line 559 "ast.y"
	{  }
break;
case 88:
#line 560 "ast.y"
	{  }
break;
case 89:
#line 561 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 90:
#line 570 "ast.y"
	{ yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 91:
#line 571 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 572 "ast.y"
	{}
break;
case 93:
#line 575 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 94:
#line 581 "ast.y"
	{}
break;
case 95:
#line 582 "ast.y"
	{}
break;
case 96:
#line 585 "ast.y"
	{ 
															yyval.node = yystack.l_mark[0].node; 
														}
break;
case 97:
#line 591 "ast.y"
	{
															char* currentFuncName = getCurrentFuncName();

															struct GSTNode* funcGSTEntry = GSTLookup(currentFuncName);
															struct MemberFuncList* MFLEntry = MemberFuncLookUp(currentClassTable, currentFuncName, NULL);

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
#line 612 "ast.y"
	{

															/* Check for function in GST		*/
															if(GSTLookup(yystack.l_mark[-3].node->nodeName) == NULL){

																if (currentClassTable == NULL) {
																	printf("\nFunction %s() not declared globally\n", yystack.l_mark[-3].node->nodeName);
																	exit(1);
																}
															
																/* TODO:*/


																/* if not in GST, search in current Class Table*/
																if (MemberFuncLookUp(currentClassTable, yystack.l_mark[-3].node->nodeName, NULL) == NULL) {
																	printf("\nFunction %s() not declared in class %s\n", yystack.l_mark[-3].node->nodeName, currentClassTable->className);
																	exit(1);
																}

															}

															setCurrentFuncName(yystack.l_mark[-3].node->nodeName);

															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 99:
#line 640 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 100:
#line 641 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 101:
#line 642 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 102:
#line 643 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 103:
#line 644 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 104:
#line 647 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
															isFuncDef = 0;
														}
break;
case 105:
#line 652 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, NULL, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
															isFuncDef = 0;
														}
break;
case 106:
#line 662 "ast.y"
	{  
											/* printTupleList();*/
											isFuncDef = 1;	
										}
break;
case 107:
#line 666 "ast.y"
	{ isFuncDef = 1; }
break;
case 108:
#line 667 "ast.y"
	{ isFuncDef = 1; }
break;
case 109:
#line 670 "ast.y"
	{}
break;
case 110:
#line 671 "ast.y"
	{}
break;
case 111:
#line 674 "ast.y"
	{}
break;
case 112:
#line 675 "ast.y"
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
#line 689 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 114:
#line 690 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 115:
#line 691 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 116:
#line 698 "ast.y"
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
#line 708 "ast.y"
	{}
break;
case 118:
#line 709 "ast.y"
	{}
break;
case 119:
#line 712 "ast.y"
	{ 
											int varSize = (currentLDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentLDeclType->size);							
											LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, varSize); 
										}
break;
case 120:
#line 716 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 121:
#line 723 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 122:
#line 739 "ast.y"
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
#line 758 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 124:
#line 761 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 129:
#line 777 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 130:
#line 783 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 131:
#line 790 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 132:
#line 796 "ast.y"
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
#line 817 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 134:
#line 818 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 135:
#line 822 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 136:
#line 829 "ast.y"
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
#line 855 "ast.y"
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
													struct MemberFuncList* funcListEntry = MemberFuncLookUp(lastFieldClassType, yystack.l_mark[0].node->nodeName, yystack.l_mark[0].node->argListHead); 

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
#line 921 "ast.y"
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
													struct MemberFuncList* funcListEntry = MemberFuncLookUp(yystack.l_mark[-2].node->classTablePtr, yystack.l_mark[0].node->nodeName, yystack.l_mark[0].node->argListHead); 
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
#line 1002 "ast.y"
	{
												/* can only be used inside a class method definiton*/
												if (currentClassTable == NULL || isFuncDef == 0) {
													printf("\nClass Error: 'self.%s'. Keyword 'self' can only be used in a class function definition\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}	

												yyval.node = TreeCreate(typeTableVOID, SELF_NODE, NULL, INT_MAX, NULL, NULL, NULL, yystack.l_mark[0].node);

												/* check if the class field or class method exists*/
												struct FieldList* fieldListEntry = FLLookUp(NULL, currentClassTable, yystack.l_mark[0].node->nodeName);
												struct MemberFuncList* funcListEntry = MemberFuncLookUp(currentClassTable, yystack.l_mark[0].node->nodeName, yystack.l_mark[0].node->argListHead);

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
#line 1034 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 141:
#line 1035 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 142:
#line 1045 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 143:
#line 1046 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 144:
#line 1047 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 145:
#line 1048 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 146:
#line 1049 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 147:
#line 1050 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 148:
#line 1051 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 149:
#line 1052 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 150:
#line 1053 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 151:
#line 1054 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 152:
#line 1055 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 153:
#line 1056 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 154:
#line 1057 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 155:
#line 1058 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 156:
#line 1059 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 157:
#line 1060 "ast.y"
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
#line 1079 "ast.y"
	{  }
break;
case 159:
#line 1080 "ast.y"
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
#line 1100 "ast.y"
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
#line 1109 "ast.y"
	{}
break;
case 162:
#line 1110 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 163:
#line 1118 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 164:
#line 1126 "ast.y"
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
case 165:
#line 1147 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 166:
#line 1148 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 167:
#line 1149 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 2271 "y.tab.c"
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
