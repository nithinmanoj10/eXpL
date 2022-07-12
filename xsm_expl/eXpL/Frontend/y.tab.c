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
	#include "../Functions/printError.h"

	int yylex(void);
	void yyerror(char const *s);
	int statementCount = 0;
	int typeFieldCount = 0;
	int tupleFieldCount = 0;
	int isFuncDef = 0;
	int globalDeclStartLabel = 0;
	char* fileName;
	FILE* filePtr;
#line 38 "ast.y"
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
#line 70 "y.tab.c"

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
#define PRINTF 270
#define PLUS 271
#define MINUS 272
#define MUL 273
#define DIV 274
#define MOD 275
#define AMPERSAND 276
#define BREAKPOINT 277
#define TYPE 278
#define ENDTYPE 279
#define TUPLE 280
#define IF 281
#define THEN 282
#define ELSE 283
#define ENDIF 284
#define WHILE 285
#define DO 286
#define ENDWHILE 287
#define BREAK 288
#define CONTINUE 289
#define AND 290
#define OR 291
#define NOT 292
#define FOR 293
#define DECL 294
#define ENDDECL 295
#define INT 296
#define STR 297
#define RETURN 298
#define SELF 299
#define EXTENDS 300
#define CLASS 301
#define ENDCLASS 302
#define EQ 303
#define NEQ 304
#define LT 305
#define LTE 306
#define GT 307
#define GTE 308
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,   43,   43,   48,   48,   49,
   31,   37,   37,   36,   30,   30,   30,   44,   50,   50,
   35,   42,   41,   41,   52,   52,   53,   51,    1,    1,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    3,    4,    4,    5,    5,    5,    5,    5,   16,
   15,    6,    6,    9,   10,   11,   12,   13,   14,   45,
   45,   45,   56,   56,   57,   57,   32,   32,   32,   32,
   58,   58,   59,   59,   59,   59,   59,   59,   21,   40,
   39,   39,   38,   34,   34,   28,   54,   54,   54,   60,
   61,   61,   61,   61,   61,   20,   20,   20,   19,   46,
   46,    7,   62,   63,   65,   65,   65,   65,   65,   18,
   18,   64,   64,   64,   66,   66,   67,   67,   33,   33,
   33,   33,   68,   68,   69,   69,   69,   47,   70,   17,
   55,   55,   55,   55,   24,   25,   23,   29,   26,   26,
   26,   71,   22,   22,   22,   27,   27,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,
};
static const YYINT yylen[] = {                            2,
    5,    4,    3,    4,    2,    3,    0,    2,    1,    4,
    1,    2,    1,    3,    1,    1,    1,    3,    2,    1,
    5,    4,    1,    3,    2,    1,    6,    1,    3,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    2,    2,    6,    3,    6,    9,    4,    3,    1,
    3,    7,    5,    5,    5,   11,    1,    1,    1,    3,
    2,    0,    2,    1,    3,    4,    1,    1,    1,    2,
    3,    1,    1,    4,    7,    4,    1,    4,    2,    3,
    3,    1,    2,    1,    1,    1,    3,    1,    0,    2,
    1,    1,    2,    2,    1,    3,    1,    0,    1,    2,
    1,    1,    5,    5,    1,    1,    2,    2,    1,    5,
    4,    3,    2,    0,    2,    1,    3,    4,    1,    1,
    1,    2,    3,    1,    1,    4,    2,    7,    2,    5,
    1,    1,    1,    1,    4,    5,    4,    5,    2,    5,
    2,    4,    3,    3,    3,    1,    4,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    3,    1,    1,    4,    4,    7,    2,    2,    1,
    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   11,    0,    0,    9,    0,    0,    0,
    0,    0,    6,    8,   69,    0,   61,   67,   68,    0,
    0,   64,    0,   20,    0,    0,    0,  109,    0,    0,
    0,    3,  101,    0,    0,    0,   17,   15,   16,    0,
   13,    0,   70,    0,    0,    0,    0,    0,    0,   72,
   60,   63,    0,    0,   18,   19,    0,    2,  129,  107,
  108,    4,  100,    0,  102,    0,    0,    0,   10,   12,
    0,    0,   79,   84,   85,    0,   82,    0,    0,    0,
    0,   65,   24,    0,    0,    1,    0,    0,    0,    0,
   14,   95,    0,    0,    0,   88,    0,    0,   86,   83,
    0,   80,    0,   66,   71,    0,    0,    0,    0,  121,
    0,  113,  119,  120,    0,    0,  116,    0,    0,    0,
    0,   93,   94,    0,   76,   90,    0,   81,   78,    0,
    0,   26,   21,  122,    0,    0,    0,    0,  124,  112,
  115,    0,    0,    0,    0,    0,   59,    0,    0,    0,
   57,   58,    0,    0,    0,    0,    0,   31,   32,   33,
   34,   35,   36,   37,   38,   39,   40,    0,    0,  133,
  131,  132,    0,    0,  134,   41,  103,  104,    0,   87,
    0,    0,   22,    0,   25,    0,  127,    0,    0,  117,
    0,    0,    0,  171,  172,  173,    0,    0,    0,    0,
    0,    0,  164,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  118,  123,    0,    0,    0,    0,  169,  168,  161,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   51,  145,   29,    0,  111,    0,  143,    0,
    0,    0,    0,  144,    0,  128,   75,    0,  126,    0,
    0,   97,    0,    0,  162,    0,    0,  150,  151,  152,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  110,  137,
  135,    0,    0,    0,    0,    0,    0,    0,  165,    0,
  142,    0,    0,   53,   54,   55,    0,    0,  136,  138,
    0,   27,    0,    0,   96,    0,   44,    0,    0,    0,
  130,    0,    0,   52,    0,    0,    0,  167,    0,    0,
    0,    0,   56,
};
static const YYINT yydgoto[] = {                          2,
  156,  157,  158,  159,  160,  161,   66,  281,  162,  163,
  164,  165,  166,  167,  168,  212,  226,  119,  282,  283,
   47,  202,  170,  171,  172,  173,  174,  100,  175,   40,
    5,   20,  115,   76,   24,   41,   42,   77,   78,   48,
   25,   85,    3,   10,   11,   31,   32,    6,    7,   26,
  109,  131,  132,   95,  176,   21,   22,   49,   50,   96,
   97,   33,   34,   88,   35,  116,  117,  138,  139,   36,
  203,
};
static const YYINT yysindex[] = {                      -242,
 -219,    0, -257,    0,  -78, -224,    0, -204, -175, -198,
 -230, -208,    0,    0,    0, -142,    0,    0,    0,  -36,
 -195,    0, -173,    0,   32, -239, -230,    0, -226,  -97,
 -230,    0,    0,   63,  -65,  170,    0,    0,    0,  -58,
    0, -117,    0,  -23,  -37, -165,  184, -154,   82,    0,
    0,    0,  -13,  -44,    0,    0, -230,    0,    0,    0,
    0,    0,    0,  -24,    0,  221,  222,  213,    0,    0,
 -174,   23,    0,    0,    0,   39,    0,   28, -174,  108,
 -154,    0,    0, -208, -159,    0, -186,   20, -174,  180,
    0,    0,   31,   43,  167,    0,   62,  228,    0,    0,
 -165,    0,  175,    0,    0, -208,   51, -159,  200,    0,
   72,    0,    0,    0,  -34, -183,    0,  589,  209,  181,
  -24,    0,    0, -174,    0,    0,  251,    0,    0,  100,
 -217,    0,    0,    0,  267,  103, -153,  110,    0,    0,
    0,  -35,  231,  231,  299,  104,    0,  231,  231,  688,
    0,    0,  301,  231,  316,  589,  306,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  107,  113,    0,
    0,    0,   18,  323,    0,    0,    0,    0,  111,    0,
  120,   -9,    0,  136,    0,  121,    0,  128, -153,    0,
  231,  231,  -21,    0,    0,    0,  138,  139,  231,  231,
  788,  122,    0,  788,  118,  325,  744,  782,  715, -234,
  788,  338,  143,  345,  142,    0,  348,  231,  154,  372,
  373,  374,  388,  178,  688,  307,  343, -174,  391,  351,
    0,    0,  788,  -77,  231,  231,    0,    0,    0,  168,
  231,  231,  231,  231,  231,  231,  231,  231,  231,  231,
  231,  231,  231,  231,  412,  231,  688,  688,  231,  -33,
  398,  129,    0,    0,    0,  401,    0,  788,    0,  420,
  421,  231,  206,    0,  589,    0,    0,  197,    0,  -32,
  788,    0,  201,  328,    0, -109, -109,    0,    0,    0,
  829,  809, -124, -124,  -18,  -18,  -18,  -18,  205,  230,
  788,  545,  628,  738,  231,  231,  231,  231,    0,    0,
    0,  174,  429,  219,  432,  231,  231,  231,    0,  402,
    0,  451,  688,    0,    0,    0,  337,  281,    0,    0,
  436,    0,  788,  375,    0,  231,    0,  655,  -31, -234,
    0,  441,  446,    0,  231,  462,  231,    0,  383,  788,
  688,  488,    0,
};
static const YYINT yyrindex[] = {                         1,
    0,    0,    3,    0,    0,    0,    0,    0,    0, -151,
  511,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  393,    0,    0,    0,    0,    0,  262,  263,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  141,    0,    0,  145,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  256,    0,    0,    0,    0,    0,    0,
  218,    0,    0,    0,    0,    0,    0,    0,  218,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  218,    0,
    0,    0,  265,  268,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  262,  406,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  256,    0,    0,    0,    0,    0,  158,    0,    0,    0,
    0,    0,    0,    0,  159,    0,    0,    0,    0,    0,
    0,  480,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  236,    0,  -39,    0,    0,    0,    0,    0,    0,    0,
  468,   40,    0,  475,    0,    0,    0,    0,    0,    0,
  477,    0,    0,    0,    0,    0,    0,  248,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  218,    0,    0,
    0,    0,  -17,    0,  246,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  246,    0,    0,    0,    0,    0,  480,
    0,    0,    0,    0,    0,    0,    0,   -7,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  491,
  250,    0,    0,    0,    0,   46,   84,    0,    0,    0,
  425,  442,  242,  279,   77,  112,  119,  147,    0,    0,
   75,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  253,    0,    0,    0,    2,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   76,    0,    0,    0,    0,    0,  491,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   83,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
 -150, -145,    0,    0, -196,    0,    0,  548,    0,    0,
    0,    0,    0,    0, -146,    0,    0,    0,  220,  286,
    0,  349,    0,    0,    0,    0,    0,    0,    0,  -74,
    0,    0,    0,    0,  515,  -29,  458,  443,    0,  428,
    0,    0,    0,    0,  537,  -12,   -6,    0,  542,    0,
    0,    0,  418,  -67,    0,    0,  529,  503,  476,  438,
    0,  -22,    0,  439,    0,    0,  447,  427,  378,    0,
    0,
};
#define YYTABLESIZE 1137
static const YYINT yytable[] = {                        209,
    7,  170,   62,   46,  170,   46,  146,   69,   63,  215,
  214,  103,   70,  261,   57,  280,   71,   23,  235,  170,
   58,  120,  260,   45,   62,  191,   28,  305,  316,  345,
  228,  130,    4,   49,   63,    1,    8,    4,  146,   37,
   59,   45,  166,    9,   12,  166,   60,  147,   37,   91,
   86,   49,   15,  170,   13,  192,  184,  306,  317,  317,
  166,   15,   55,  214,  155,   29,   30,   72,  102,  236,
  110,  101,  108,  110,  275,   16,   70,  183,   38,   39,
  163,   23,   92,  163,   16,   63,  148,   38,   39,  148,
   17,   18,   19,  111,  166,    8,  111,   28,  163,   51,
   18,   19,   44,  135,  148,   62,  302,  303,  112,  113,
  114,  140,  113,  114,   43,   48,   46,  155,   45,  136,
  155,   93,   94,   47,  149,   81,   53,  149,  314,  214,
   74,   75,  163,   48,   46,  155,  107,   30,  148,   37,
   82,   47,  149,  346,   62,   62,  241,  242,  243,  244,
  245,   81,  156,  189,   54,  156,  214,  214,  219,  157,
  278,  254,  157,  243,  244,  245,  104,  219,  190,  155,
  156,  189,  338,  218,  219,   61,  149,  157,   38,   39,
  250,  251,  252,  253,   73,   64,  231,  158,   77,  308,
  158,   65,  214,  241,  242,  243,  244,  245,   68,   73,
  352,   74,  125,   77,  156,  158,  214,  125,  285,   67,
  124,  157,  246,  247,  329,  129,   74,  125,  124,   73,
   44,  178,  135,   79,  124,  248,  249,  250,  251,  252,
  253,  170,  170,  170,  170,  170,   45,  315,  136,  158,
  124,  319,  170,   83,  318,  321,  170,  170,  318,   84,
  170,  170,  241,  242,  243,  244,  245,    7,   89,   62,
   89,   89,   90,  170,  170,  170,  170,  170,  170,   87,
  200,   91,  166,  166,  166,  166,  166,  220,  221,  222,
   98,  223,  153,  166,  118,  153,   98,  166,  166,   98,
   99,  166,  166,   99,    7,   99,    7,    7,   62,   62,
  153,    7,  121,  122,  166,  166,  166,  166,  166,  166,
  163,  163,  163,  163,  163,  123,  148,  148,  126,  154,
  127,  163,  154,   60,  133,  163,  163,  148,  134,  163,
  163,  148,  148,  177,  153,  148,  148,  154,  205,  340,
  210,  181,  163,  163,  163,  163,  163,  163,  148,  148,
  148,  148,  148,  148,  149,  149,  182,  186,  155,  187,
  206,  213,  155,  155,  216,  149,  155,  155,  224,  149,
  149,  154,  217,  149,  149,  225,  255,  227,  230,  155,
  155,  155,  155,  155,  155,  256,  149,  149,  149,  149,
  149,  149,  229,  156,  237,  238,  263,  156,  156,  264,
  157,  156,  156,  265,  157,  157,  267,  266,  157,  157,
  269,  270,  271,  272,  156,  156,  156,  156,  156,  156,
  320,  157,  157,  157,  157,  157,  157,  273,  158,  339,
  228,  276,  158,  158,  274,  277,  158,  158,  241,  242,
  243,  244,  245,  279,  241,  242,  243,  244,  245,  158,
  158,  158,  158,  158,  158,  300,  307,  246,  247,  309,
  310,  311,  313,  246,  247,  159,  169,  342,  159,  330,
  248,  249,  250,  251,  252,  253,  248,  249,  250,  251,
  252,  253,  160,  159,  331,  160,  322,  193,  194,  195,
  332,  337,  336,  196,  341,  139,  139,  139,  169,  139,
  160,  347,  349,  197,  169,  351,  198,  141,  141,  141,
    5,  141,  140,  140,  140,   23,  140,  159,  105,  106,
  114,   91,  199,  153,   92,  146,   42,  153,  153,  155,
   28,  153,  153,   43,  160,   50,  147,  335,  348,  299,
   56,  106,  137,  128,  153,  153,   27,   14,  185,   52,
   80,  241,  242,  243,  244,  245,  105,  169,  262,  179,
  154,  180,  141,  188,  154,  154,  232,    0,  154,  154,
  246,  247,    0,  169,    0,    0,    0,    0,    0,    0,
    0,  154,  154,  248,  249,  250,  251,  252,  253,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  241,  242,
  243,  244,  245,    0,    0,  169,  169,  241,  242,  243,
  244,  245,  353,    0,    0,    0,    0,  246,  247,    0,
    0,    0,    0,  169,    0,    0,  246,  247,    0,    0,
  248,  249,  250,  251,  252,  253,    0,    0,    0,  248,
  249,  250,  251,  252,  253,  241,  242,  243,  244,  245,
  169,  169,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  246,  247,    0,    0,    0,    0,
    0,  169,    0,    0,    0,    0,    0,  248,  249,  250,
  251,  252,  253,    0,    0,    0,  169,    0,  262,    0,
  201,  204,    0,    0,    0,  207,  208,    0,    0,  169,
  169,  211,    0,    0,    0,    0,  159,    0,    0,    0,
  159,  159,    0,    0,  159,  159,  241,  242,  243,  244,
  245,    0,    0,  160,    0,    0,    0,  160,  160,    0,
    0,    0,  160,    0,    0,  246,  247,    0,  233,  234,
    0,    0,    0,    0,  142,    0,  239,  240,  248,  249,
  250,  251,  252,  253,    0,  143,  144,  145,    0,    0,
  146,    0,    0,    0,  147,  268,    0,    0,  148,    0,
    0,    0,  149,  150,    0,  151,  152,    0,    0,    0,
  153,    0,    0,  284,    0,    0,  155,    0,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,
  298,  142,    0,  301,    0,    0,  304,    0,    0,    0,
    0,    0,  143,  144,  145,    0,    0,  146,    0,  312,
    0,  147,    0,    0,    0,  148,    0,  323,  324,  149,
  150,    0,  151,  152,    0,    0,    0,  153,    0,    0,
    0,    0,    0,  155,    0,  142,    0,    0,    0,    0,
    0,    0,  233,  327,  328,  268,  143,  144,  145,    0,
    0,  146,    0,  333,  334,  147,    0,    0,    0,  148,
    0,    0,    0,  149,  150,    0,  151,  152,    0,    0,
    0,  153,    0,  343,  142,    0,  154,  155,    0,    0,
    0,    0,  333,    0,  350,  143,  144,  145,    0,    0,
  146,    0,    0,    0,  147,    0,    0,    0,  148,    0,
    0,  142,  149,  150,  325,  151,  152,    0,    0,    0,
  153,    0,  143,  144,  145,    0,  155,  146,    0,    0,
    0,  147,    0,    0,    0,  148,    0,    0,  344,  149,
  150,    0,  151,  152,  142,    0,    0,  153,    0,    0,
    0,    0,    0,  155,    0,  143,  144,  145,    0,    0,
  146,    0,    0,    0,  147,    0,    0,    0,  148,    0,
    0,  142,  149,  150,    0,  151,  152,    0,    0,    0,
  153,    0,  143,  144,  145,    0,  155,  146,    0,    0,
    0,  147,    0,    0,    0,  148,    0,    0,    0,  259,
  150,    0,  151,  152,    0,    0,    0,  153,  241,  242,
  243,  244,  245,  155,  241,  242,  243,  244,  245,    0,
    0,    0,    0,  258,  326,  257,    0,  246,  247,    0,
    0,    0,    0,  246,  247,    0,    0,    0,    0,    0,
  248,  249,  250,  251,  252,  253,  248,  249,  250,  251,
  252,  253,  241,  242,  243,  244,  245,    0,  241,  242,
  243,  244,  245,    0,    0,    0,    0,  258,    0,    0,
    0,  246,  247,    0,    0,    0,    0,  246,  247,  241,
  242,  243,  244,  245,  248,  249,  250,  251,  252,  253,
  248,  249,  250,  251,  252,  253,    0,    0,  246,  241,
  242,  243,  244,  245,    0,    0,    0,    0,    0,    0,
    0,  248,  249,  250,  251,  252,  253,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  248,  249,  250,  251,  252,  253,
};
static const YYINT yycheck[] = {                        150,
    0,   41,    0,   40,   44,   40,   46,  125,   31,  156,
  156,   79,   42,  210,   27,   93,   40,  257,   40,   59,
   27,   89,  257,   41,   31,   61,  257,   61,   61,   61,
   40,  106,  257,   41,   57,  278,  294,  257,  273,  257,
  267,   59,   41,  301,  123,   44,  273,   46,  257,   59,
   57,   59,  257,   93,  279,   91,  131,   91,   91,   91,
   59,  257,  302,  209,  299,  296,  297,   91,   41,   91,
  257,   44,   85,  257,  225,  280,  106,  295,  296,  297,
   41,  257,  257,   44,  280,  108,   41,  296,  297,   44,
  295,  296,  297,  280,   93,  294,  280,  257,   59,  295,
  296,  297,  257,  257,   59,  257,  257,  258,  295,  296,
  297,  295,  296,  297,  257,   41,   41,   41,  273,  273,
   44,  296,  297,   41,   41,   44,  300,   44,  275,  275,
  296,  297,   93,   59,   59,   59,  296,  297,   93,  257,
   59,   59,   59,  340,  296,  297,  271,  272,  273,  274,
  275,   44,   41,   44,  123,   44,  302,  303,   46,   41,
  228,   40,   44,  273,  274,  275,   59,   46,   59,   93,
   59,   44,  323,   61,   46,  273,   93,   59,  296,  297,
  305,  306,  307,  308,   44,  123,   59,   41,   44,   61,
   44,  257,  338,  271,  272,  273,  274,  275,  257,   59,
  351,   44,   44,   59,   93,   59,  352,   41,   41,   40,
   44,   93,  290,  291,   41,   41,   59,   59,   44,  257,
  257,   41,  257,   40,   44,  303,  304,  305,  306,  307,
  308,  271,  272,  273,  274,  275,  273,   41,  273,   93,
   44,   41,  282,  257,   44,   41,  286,  287,   44,  294,
  290,  291,  271,  272,  273,  274,  275,  257,   41,  257,
   40,   44,   41,  303,  304,  305,  306,  307,  308,  294,
   40,   59,  271,  272,  273,  274,  275,  260,  261,  262,
  258,  264,   41,  282,  265,   44,   41,  286,  287,   44,
   41,  290,  291,   44,  294,  257,  296,  297,  296,  297,
   59,  301,  123,  273,  303,  304,  305,  306,  307,  308,
  271,  272,  273,  274,  275,  273,  271,  272,  257,   41,
   93,  282,   44,  273,  125,  286,  287,  282,  257,  290,
  291,  286,  287,  125,   93,  290,  291,   59,   40,   59,
   40,   91,  303,  304,  305,  306,  307,  308,  303,  304,
  305,  306,  307,  308,  271,  272,  257,   91,  282,  257,
  257,   46,  286,  287,   59,  282,  290,  291,   46,  286,
  287,   93,  266,  290,  291,  265,  259,  258,  258,  303,
  304,  305,  306,  307,  308,   61,  303,  304,  305,  306,
  307,  308,  257,  282,  257,  257,   59,  286,  287,  257,
  282,  290,  291,   59,  286,  287,   59,  266,  290,  291,
  257,   40,   40,   40,  303,  304,  305,  306,  307,  308,
   93,  303,  304,  305,  306,  307,  308,   40,  282,   93,
   40,  125,  286,  287,  257,   93,  290,  291,  271,  272,
  273,  274,  275,   93,  271,  272,  273,  274,  275,  303,
  304,  305,  306,  307,  308,   44,   59,  290,  291,   59,
   41,   41,  257,  290,  291,   41,  118,   93,   44,   41,
  303,  304,  305,  306,  307,  308,  303,  304,  305,  306,
  307,  308,   41,   59,  266,   44,  257,  257,  258,  259,
   59,   41,   91,  263,   59,  260,  261,  262,  150,  264,
   59,   61,   41,  273,  156,  123,  276,  260,  261,  262,
    0,  264,  260,  261,  262,  123,  264,   93,  257,  257,
  265,  257,  292,  282,  257,   46,   59,  286,  287,  299,
  125,  290,  291,   59,   93,   59,   46,  318,   93,  254,
   26,   84,  115,  101,  303,  304,   10,    6,  131,   21,
   48,  271,  272,  273,  274,  275,   81,  209,  210,  121,
  282,  124,  116,  137,  286,  287,  189,   -1,  290,  291,
  290,  291,   -1,  225,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  303,  304,  303,  304,  305,  306,  307,  308,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  271,  272,
  273,  274,  275,   -1,   -1,  257,  258,  271,  272,  273,
  274,  275,  125,   -1,   -1,   -1,   -1,  290,  291,   -1,
   -1,   -1,   -1,  275,   -1,   -1,  290,  291,   -1,   -1,
  303,  304,  305,  306,  307,  308,   -1,   -1,   -1,  303,
  304,  305,  306,  307,  308,  271,  272,  273,  274,  275,
  302,  303,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  290,  291,   -1,   -1,   -1,   -1,
   -1,  323,   -1,   -1,   -1,   -1,   -1,  303,  304,  305,
  306,  307,  308,   -1,   -1,   -1,  338,   -1,  340,   -1,
  143,  144,   -1,   -1,   -1,  148,  149,   -1,   -1,  351,
  352,  154,   -1,   -1,   -1,   -1,  282,   -1,   -1,   -1,
  286,  287,   -1,   -1,  290,  291,  271,  272,  273,  274,
  275,   -1,   -1,  282,   -1,   -1,   -1,  286,  287,   -1,
   -1,   -1,  291,   -1,   -1,  290,  291,   -1,  191,  192,
   -1,   -1,   -1,   -1,  257,   -1,  199,  200,  303,  304,
  305,  306,  307,  308,   -1,  268,  269,  270,   -1,   -1,
  273,   -1,   -1,   -1,  277,  218,   -1,   -1,  281,   -1,
   -1,   -1,  285,  286,   -1,  288,  289,   -1,   -1,   -1,
  293,   -1,   -1,  236,   -1,   -1,  299,   -1,  241,  242,
  243,  244,  245,  246,  247,  248,  249,  250,  251,  252,
  253,  257,   -1,  256,   -1,   -1,  259,   -1,   -1,   -1,
   -1,   -1,  268,  269,  270,   -1,   -1,  273,   -1,  272,
   -1,  277,   -1,   -1,   -1,  281,   -1,  283,  284,  285,
  286,   -1,  288,  289,   -1,   -1,   -1,  293,   -1,   -1,
   -1,   -1,   -1,  299,   -1,  257,   -1,   -1,   -1,   -1,
   -1,   -1,  305,  306,  307,  308,  268,  269,  270,   -1,
   -1,  273,   -1,  316,  317,  277,   -1,   -1,   -1,  281,
   -1,   -1,   -1,  285,  286,   -1,  288,  289,   -1,   -1,
   -1,  293,   -1,  336,  257,   -1,  298,  299,   -1,   -1,
   -1,   -1,  345,   -1,  347,  268,  269,  270,   -1,   -1,
  273,   -1,   -1,   -1,  277,   -1,   -1,   -1,  281,   -1,
   -1,  257,  285,  286,  287,  288,  289,   -1,   -1,   -1,
  293,   -1,  268,  269,  270,   -1,  299,  273,   -1,   -1,
   -1,  277,   -1,   -1,   -1,  281,   -1,   -1,  284,  285,
  286,   -1,  288,  289,  257,   -1,   -1,  293,   -1,   -1,
   -1,   -1,   -1,  299,   -1,  268,  269,  270,   -1,   -1,
  273,   -1,   -1,   -1,  277,   -1,   -1,   -1,  281,   -1,
   -1,  257,  285,  286,   -1,  288,  289,   -1,   -1,   -1,
  293,   -1,  268,  269,  270,   -1,  299,  273,   -1,   -1,
   -1,  277,   -1,   -1,   -1,  281,   -1,   -1,   -1,  285,
  286,   -1,  288,  289,   -1,   -1,   -1,  293,  271,  272,
  273,  274,  275,  299,  271,  272,  273,  274,  275,   -1,
   -1,   -1,   -1,  286,  287,  282,   -1,  290,  291,   -1,
   -1,   -1,   -1,  290,  291,   -1,   -1,   -1,   -1,   -1,
  303,  304,  305,  306,  307,  308,  303,  304,  305,  306,
  307,  308,  271,  272,  273,  274,  275,   -1,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,  286,   -1,   -1,
   -1,  290,  291,   -1,   -1,   -1,   -1,  290,  291,  271,
  272,  273,  274,  275,  303,  304,  305,  306,  307,  308,
  303,  304,  305,  306,  307,  308,   -1,   -1,  290,  271,
  272,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  303,  304,  305,  306,  307,  308,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  303,  304,  305,  306,  307,  308,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 308
#define YYUNDFTOKEN 382
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
"END","MAIN","READ","WRITE","PRINTF","PLUS","MINUS","MUL","DIV","MOD",
"AMPERSAND","BREAKPOINT","TYPE","ENDTYPE","TUPLE","IF","THEN","ELSE","ENDIF",
"WHILE","DO","ENDWHILE","BREAK","CONTINUE","AND","OR","NOT","FOR","DECL",
"ENDDECL","INT","STR","RETURN","SELF","EXTENDS","CLASS","ENDCLASS","EQ","NEQ",
"LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
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
"Stmt : forStmt",
"Stmt : breakStmt",
"Stmt : continueStmt",
"Stmt : breakPointStmt",
"Stmt : DynamicMemStmt",
"inputStmt : READ expr",
"outputStmt : WRITE expr",
"outputStmt : PRINTF '(' STRING ',' ID ')'",
"assignStmt : ID '=' expr",
"assignStmt : ID '[' expr ']' '=' expr",
"assignStmt : ID '[' expr ']' '[' expr ']' '=' expr",
"assignStmt : MUL ID '=' expr",
"assignStmt : Field '=' expr",
"retVal : expr",
"retStmt : RETURN retVal ';'",
"ifStmt : IF expr THEN Slist ELSE Slist ENDIF",
"ifStmt : IF expr THEN Slist ENDIF",
"whileStmt : WHILE expr DO Slist ENDWHILE",
"doWhileStmt : DO Slist WHILE expr ENDWHILE",
"forStmt : FOR '(' assignStmt ';' expr ';' assignStmt ')' '{' Slist '}'",
"breakStmt : BREAK",
"continueStmt : CONTINUE",
"breakPointStmt : BREAKPOINT",
"GDeclBlock : DECL GDeclList ENDDECL",
"GDeclBlock : DECL ENDDECL",
"GDeclBlock :",
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
"GID : ID '[' NUM ']' '[' NUM ']'",
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
#line 1176 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at statement %d\n", s, statementCount);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){

		errorInputFileName = (char*)malloc(sizeof(argv[1]));
		strcpy(errorInputFileName, argv[1]);		

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
#line 836 "y.tab.c"

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
#line 75 "ast.y"
	{}
break;
case 2:
#line 76 "ast.y"
	{}
break;
case 3:
#line 77 "ast.y"
	{}
break;
case 4:
#line 78 "ast.y"
	{}
break;
case 5:
#line 79 "ast.y"
	{	
																		printf("\n⛔ No Code Provided\n");
																		exit(1);
																	}
break;
case 6:
#line 88 "ast.y"
	{ 
													/* printTypeTable(); */
												}
break;
case 8:
#line 94 "ast.y"
	{}
break;
case 9:
#line 95 "ast.y"
	{}
break;
case 10:
#line 99 "ast.y"
	{ 
													if (typeFieldCount > 8){
														printf("\nError: User defined type %s has more than 8 fields\n", yystack.l_mark[-3].TTNode->typeName);
														exit(1);
													}

													/* FLPrint($1->typeName, NULL); */
													yystack.l_mark[-3].TTNode->typeCategory = TYPE_USER_DEFINED;
													yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-1].FLNode;
													yystack.l_mark[-3].TTNode->size = typeFieldCount;

													fieldListTail = NULL;
													fieldListHead = NULL;
													typeFieldCount = 0;
												}
break;
case 11:
#line 116 "ast.y"
	{ yyval.TTNode = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); }
break;
case 12:
#line 119 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[-1].FLNode;
												}
break;
case 13:
#line 125 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = 0;
													fieldListHead = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[0].FLNode;
				 								}
break;
case 14:
#line 133 "ast.y"
	{ 
													yyval.FLNode = FLCreateNode(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-2].TTNode, currentFieldCType); 
													++typeFieldCount;
													currentFieldCType = NULL;
												}
break;
case 15:
#line 140 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 16:
#line 141 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 17:
#line 142 "ast.y"
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
#line 161 "ast.y"
	{ 
														/* CTPrint(); */
														fprintf(filePtr, "L%d:\n", globalDeclStartLabel);	
														initVirtualFuncTable(filePtr);
													}
break;
case 19:
#line 168 "ast.y"
	{}
break;
case 20:
#line 169 "ast.y"
	{}
break;
case 21:
#line 175 "ast.y"
	{ 
														/* FLPrint($1->className, currentClassTable->memberField);*/
														/* MFLPrint($1->className);*/

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
#line 206 "ast.y"
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

															/* printf("\nWhyyyyy\n");*/

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
#line 278 "ast.y"
	{ 
														yyval.CTNode = CTInstall(yystack.l_mark[0].node->nodeName, NULL);
														currentClassTable = yyval.CTNode;
													}
break;
case 24:
#line 282 "ast.y"
	{ 
														yyval.CTNode = CTInstall(yystack.l_mark[-2].node->nodeName, yystack.l_mark[0].node->nodeName);
														currentClassTable = yyval.CTNode;
														currentParentClassTable = CTLookUp(yystack.l_mark[0].node->nodeName);
					 								}
break;
case 25:
#line 289 "ast.y"
	{}
break;
case 26:
#line 290 "ast.y"
	{}
break;
case 27:
#line 293 "ast.y"
	{ 
														MFLInstall(yystack.l_mark[-4].node->nodeName, yystack.l_mark[-5].TTNode, paramListHead);
														/*  printParamList(paramListHead); */
														flushParamList();
														paramCount = 0;
													}
break;
case 28:
#line 301 "ast.y"
	{}
break;
case 29:
#line 306 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node, NULL); }
break;
case 30:
#line 307 "ast.y"
	{}
break;
case 41:
#line 314 "ast.y"
	{ ++statementCount; }
break;
case 42:
#line 317 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL, NULL); }
break;
case 43:
#line 320 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL, NULL); }
break;
case 44:
#line 321 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, PRINTF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node, NULL); 
													char* temp = replaceStringLiteral(yystack.l_mark[-3].node->strConstVal, 23, NULL);
													printf("%s\n", temp);			
												}
break;
case 45:
#line 327 "ast.y"
	{ 
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); 
												}
break;
case 46:
#line 331 "ast.y"
	{	 
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node, NULL);
												}
break;
case 47:
#line 336 "ast.y"
	{	 
																yystack.l_mark[-8].node = lookupID(yystack.l_mark[-8].node);	
																yystack.l_mark[-8].node->left = yystack.l_mark[-6].node;
																yystack.l_mark[-8].node->middle = yystack.l_mark[-3].node;
																yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-8].node, NULL, yystack.l_mark[0].node, NULL);
															}
break;
case 48:
#line 342 "ast.y"
	{
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);	
													struct ASTNode* mulNode;
													if (yystack.l_mark[-2].node->typeTablePtr == typeTableINTPtr)
														mulNode = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[-2].node, NULL, NULL);

													if (yystack.l_mark[-2].node->typeTablePtr == typeTableSTRPtr)
														mulNode = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[-2].node, NULL, NULL);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, mulNode, NULL, yystack.l_mark[0].node, NULL);
												}
break;
case 49:
#line 352 "ast.y"
	{
													if (currentClassTable == NULL && GSTLookup(yystack.l_mark[-2].node->nodeName) != NULL) {

														struct ClassTable* classType = GSTLookup(yystack.l_mark[-2].node->nodeName)->classTablePtr;
														struct ASTNode* fieldNode = yystack.l_mark[-2].node;

														while (fieldNode->right != NULL)
															fieldNode = fieldNode->right;	

														if (isFuncDef && verifyClassField(classType, fieldNode->nodeName)) {
															printf("Class Error: Can't access class field '%s' outside of class '%s'\n", fieldNode->nodeName, classType->className);
															exit(1);
														}	
													}

													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL);
												}
break;
case 50:
#line 373 "ast.y"
	{}
break;
case 51:
#line 376 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL, NULL); }
break;
case 52:
#line 381 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 53:
#line 382 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 54:
#line 385 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node, NULL); }
break;
case 55:
#line 388 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node, NULL); }
break;
case 56:
#line 394 "ast.y"
	{ 
												yyval.node = TreeCreate(typeTableVOID, FOR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-8].node, yystack.l_mark[-6].node, yystack.l_mark[-4].node, yystack.l_mark[-1].node);
					 						}
break;
case 57:
#line 398 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL, NULL); }
break;
case 58:
#line 401 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL, NULL); }
break;
case 59:
#line 404 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL, NULL); }
break;
case 60:
#line 409 "ast.y"
	{
												/* GSTPrint(); */
												/* printTypeTable();*/
																
												initStackBP(filePtr);
												/* printGlobalParamList();*/
											}
break;
case 61:
#line 416 "ast.y"
	{
												initStackBP(filePtr);
											}
break;
case 62:
#line 419 "ast.y"
	{
												initStackBP(filePtr);
											}
break;
case 63:
#line 424 "ast.y"
	{}
break;
case 64:
#line 425 "ast.y"
	{}
break;
case 65:
#line 428 "ast.y"
	{}
break;
case 66:
#line 429 "ast.y"
	{ 
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												/* FLPrint($1->typeName, NULL);*/

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentGDeclType = NULL;
												currentCDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 67:
#line 444 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 68:
#line 445 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 69:
#line 446 "ast.y"
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
case 70:
#line 460 "ast.y"
	{ 
												if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
													printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}					
												currentGDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
												yyval.TTNode = currentGDeclType;
											}
break;
case 71:
#line 470 "ast.y"
	{}
break;
case 72:
#line 471 "ast.y"
	{}
break;
case 73:
#line 474 "ast.y"
	{ 
												int varSize;

												if (currentGDeclType != NULL)
													varSize = (currentGDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentGDeclType->size);
												if (currentCDeclType != NULL)
													varSize = 2;	/* class variable will only have size of 2 */

												GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, varSize, 0, NULL); 
											}
break;
case 74:
#line 484 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, 0,NULL); 
											}
break;
case 75:
#line 491 "ast.y"
	{
												if (yystack.l_mark[-4].node->intConstVal < 1 || yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-6].node->nodeName, currentGDeclType, yystack.l_mark[-4].node->intConstVal * yystack.l_mark[-1].node->intConstVal, yystack.l_mark[-1].node->intConstVal ,NULL); 
											}
break;
case 76:
#line 498 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, 0,getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 77:
#line 504 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, 0, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, 0, NULL);	
											}
break;
case 78:
#line 511 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[-3].node->nodeName, TTLookUp("int*"), -1, 0, getParamListHead());	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[-3].node->nodeName, TTLookUp("str*"), -1, 0, getParamListHead());

												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 79:
#line 524 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 529 "ast.y"
	{ 
																	yyval.FLNode = yystack.l_mark[-1].FLNode; 

																	if (currentGDeclType != NULL)
																		currentGDeclType->size = tupleFieldCount;
																	if (currentLDeclType != NULL)
																		currentLDeclType->size = tupleFieldCount;		
																}
break;
case 81:
#line 539 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[-2].FLNode;
																}
break;
case 82:
#line 545 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = 0;
																	fieldListHead = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[0].FLNode;
																}
break;
case 83:
#line 553 "ast.y"
	{
																	yyval.FLNode = FLCreateNode(yystack.l_mark[0].node->nodeName, yystack.l_mark[-1].TTNode, NULL);
																	++tupleFieldCount;
																}
break;
case 84:
#line 559 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 85:
#line 560 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 86:
#line 563 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 87:
#line 571 "ast.y"
	{}
break;
case 88:
#line 572 "ast.y"
	{}
break;
case 89:
#line 573 "ast.y"
	{}
break;
case 90:
#line 576 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 91:
#line 582 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 92:
#line 583 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 93:
#line 584 "ast.y"
	{  }
break;
case 94:
#line 585 "ast.y"
	{  }
break;
case 95:
#line 586 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 96:
#line 595 "ast.y"
	{ yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 97:
#line 596 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 98:
#line 597 "ast.y"
	{}
break;
case 99:
#line 600 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 100:
#line 606 "ast.y"
	{}
break;
case 101:
#line 607 "ast.y"
	{}
break;
case 102:
#line 610 "ast.y"
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
case 103:
#line 632 "ast.y"
	{
															char* currentFuncName = getCurrentFuncName();

															struct GSTNode* funcGSTEntry = GSTLookup(currentFuncName);
															struct MemberFuncList* MFLEntry = MemberFuncLookUp(currentClassTable, currentFuncName);

															int funcLabel = (funcGSTEntry == NULL) ? (MFLEntry->funcLabel) : (funcGSTEntry->fLabel);

															fprintf(filePtr, "F%d:\n", funcLabel);
															initFuncCalle(filePtr, paramCount);

															/* printASTTable($4, 0);*/
															codeGen(yystack.l_mark[-1].node, filePtr);

															/* LSTPrint();*/
															flushLST();
															paramCount = 0;
															
														}
break;
case 104:
#line 653 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 105:
#line 659 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 106:
#line 660 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 107:
#line 661 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 108:
#line 662 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 109:
#line 663 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 110:
#line 666 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node, NULL);
															yyval.node = funcBodyStmt;
															isFuncDef = 0;
														}
break;
case 111:
#line 671 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, NULL, NULL, yystack.l_mark[-2].node, NULL);
															yyval.node = funcBodyStmt;
															isFuncDef = 0;
														}
break;
case 112:
#line 681 "ast.y"
	{  
											/* printTupleList();*/
											isFuncDef = 1;	
										}
break;
case 113:
#line 685 "ast.y"
	{ isFuncDef = 1; }
break;
case 114:
#line 686 "ast.y"
	{ isFuncDef = 1; }
break;
case 115:
#line 689 "ast.y"
	{}
break;
case 116:
#line 690 "ast.y"
	{}
break;
case 117:
#line 693 "ast.y"
	{}
break;
case 118:
#line 694 "ast.y"
	{
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												/* FLPrint($1->typeName, NULL);*/

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentLDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 119:
#line 708 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 120:
#line 709 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 121:
#line 710 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 122:
#line 717 "ast.y"
	{
											if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
												printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}					
											currentLDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
											yyval.TTNode = currentLDeclType;
										}
break;
case 123:
#line 727 "ast.y"
	{}
break;
case 124:
#line 728 "ast.y"
	{}
break;
case 125:
#line 731 "ast.y"
	{ 
											int varSize = (currentLDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentLDeclType->size);							
											LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, varSize); 
										}
break;
case 126:
#line 735 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 127:
#line 742 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 128:
#line 758 "ast.y"
	{
														char* currentFuncName = getCurrentFuncName();

														/* TODO: Check!!!*/
														/* addFunctionLST(currentFuncName, LSTHead);	*/

														fprintf(filePtr, "F0:\n");
														initFuncCalle(filePtr, paramCount);

														/* printASTTable($6, 0);*/
														codeGen(yystack.l_mark[-1].node, filePtr);
														/* LSTPrint();*/
														flushLST();
														paramCount = 0;
												
														/* printFLT();*/
													}
break;
case 129:
#line 777 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 130:
#line 780 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node, NULL);
														yyval.node = statementList;
													}
break;
case 135:
#line 796 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node, NULL);
														}
break;
case 136:
#line 802 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node, NULL);
														}
break;
case 137:
#line 809 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node, NULL);
														}
break;
case 138:
#line 815 "ast.y"
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
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node, NULL);
													}
break;
case 139:
#line 836 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 140:
#line 837 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 141:
#line 841 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 142:
#line 848 "ast.y"
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
case 143:
#line 874 "ast.y"
	{
												struct ASTNode* traversalPtr = yystack.l_mark[-2].node;
												while (traversalPtr->right != NULL){
													traversalPtr = traversalPtr->right;
												}


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

														yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
														yystack.l_mark[0].node->classTablePtr = fieldListEntry->classType;
														traversalPtr->right = yystack.l_mark[0].node;
														yyval.node = yystack.l_mark[-2].node;
														yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
														yyval.node->classTablePtr = yystack.l_mark[0].node->classTablePtr;
													}
													else if (funcListEntry != NULL){

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
case 144:
#line 937 "ast.y"
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

														yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
														yystack.l_mark[0].node->classTablePtr = fieldListEntry->classType;
														yystack.l_mark[-2].node->right = yystack.l_mark[0].node;
														yyval.node = yystack.l_mark[-2].node;
														yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
														yyval.node->classTablePtr = yystack.l_mark[0].node->classTablePtr;
													}
													else if (funcListEntry != NULL){

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
case 145:
#line 1016 "ast.y"
	{
												/* can only be used inside a class method definiton*/
												if (currentClassTable == NULL || isFuncDef == 0) {
													printf("\nClass Error: 'self.%s'. Keyword 'self' can only be used in a class function definition\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}	

												yyval.node = TreeCreate(typeTableVOID, SELF_NODE, NULL, INT_MAX, NULL, NULL, NULL, yystack.l_mark[0].node, NULL);

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
case 146:
#line 1048 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 147:
#line 1049 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 148:
#line 1059 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 149:
#line 1060 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 150:
#line 1061 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 151:
#line 1062 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 152:
#line 1063 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 153:
#line 1064 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 154:
#line 1065 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 155:
#line 1066 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 156:
#line 1067 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 157:
#line 1068 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 158:
#line 1069 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 159:
#line 1070 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 160:
#line 1071 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node, NULL); }
break;
case 161:
#line 1072 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL, NULL); }
break;
case 162:
#line 1073 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 163:
#line 1074 "ast.y"
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
case 164:
#line 1093 "ast.y"
	{  }
break;
case 165:
#line 1094 "ast.y"
	{ 
										/* check if ID is a type constructor*/
										struct TypeTable* idTTEntry = TTLookUp(yystack.l_mark[-3].node->nodeName);

										/* if its a Tuple Constructor		*/
										if (idTTEntry != NULL && idTTEntry->typeCategory == TYPE_TUPLE){
											verifyTupleFields(idTTEntry, yystack.l_mark[-1].node);
											yyval.node = TreeCreate(idTTEntry, TUPLE_CONSTRUCTOR_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL, NULL);
											yyval.node->argListHead = yystack.l_mark[-1].node;
										}

										/* if its a function*/
										if(idTTEntry == NULL){
											yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
											verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
											yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL, NULL); 
											yyval.node->argListHead = yystack.l_mark[-1].node;
											yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
										}
									}
break;
case 166:
#line 1114 "ast.y"
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
case 167:
#line 1123 "ast.y"
	{
												yystack.l_mark[-6].node = lookupID(yystack.l_mark[-6].node);
												if (yystack.l_mark[-4].node->typeTablePtr != typeTableINT || yystack.l_mark[-1].node->typeTablePtr != typeTableINT){
													printf("\nArray Indexing expects INT Data Type\n");
													exit(1);
												}
												yystack.l_mark[-6].node->left = yystack.l_mark[-4].node;	
												yystack.l_mark[-6].node->middle = yystack.l_mark[-1].node;
												yyval.node = yystack.l_mark[-6].node;
											}
break;
case 168:
#line 1133 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL, NULL);	
									}
break;
case 169:
#line 1141 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 170:
#line 1149 "ast.y"
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
case 171:
#line 1170 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 172:
#line 1171 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 173:
#line 1172 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 2394 "y.tab.c"
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
