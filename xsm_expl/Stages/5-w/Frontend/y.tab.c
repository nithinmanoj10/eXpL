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
#line 30 "ast.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct ASTNode* node;
	struct LSTNode* lstnode;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 58 "y.tab.c"

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
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define BREAK 280
#define CONTINUE 281
#define AND 282
#define OR 283
#define NOT 284
#define DECL 285
#define ENDDECL 286
#define INT 287
#define STR 288
#define RETURN 289
#define SEMICOLON 290
#define COMMA 291
#define EQ 292
#define NEQ 293
#define LT 294
#define LTE 295
#define GT 296
#define GTE 297
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    3,    4,    5,    5,    5,   15,
   14,    6,    6,    9,   10,   11,   12,   13,   21,   21,
   24,   24,   25,   26,   26,   27,   27,   28,   28,   28,
   28,   28,   20,   29,   29,   29,   31,   31,   31,   31,
   30,   19,   19,   19,   18,   22,   22,    7,   32,   33,
   35,   35,   35,   35,   17,   34,   34,   36,   36,   37,
   38,   38,   39,   39,   40,   40,   23,   41,   16,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,
};
static const YYINT yylen[] = {                            2,
    3,    2,    1,    3,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    3,    6,    4,    1,
    3,    7,    5,    5,    5,    1,    1,    1,    3,    2,
    2,    1,    3,    1,    1,    3,    1,    1,    4,    4,
    1,    4,    2,    3,    1,    0,    1,    1,    2,    2,
    2,    3,    1,    0,    1,    2,    1,    1,    5,    5,
    1,    1,    2,    2,    5,    3,    2,    2,    1,    3,
    1,    1,    3,    1,    1,    2,    7,    2,    5,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    3,    4,    4,    2,    2,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   30,   34,   35,    0,   32,    0,    0,
    0,    0,    2,   57,    0,    0,    0,   29,   31,    0,
    0,    0,    0,   37,   78,   63,   64,    1,   56,    0,
   58,    0,    0,    0,    0,   43,    0,   33,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   45,    0,    0,
   36,   67,   71,   72,    0,   69,    0,    0,    0,    0,
    0,   39,   49,   50,    0,   40,   51,   42,   66,   68,
   75,    0,    0,   74,    0,    0,    0,    0,   28,    0,
    0,    0,   26,   27,    0,    0,    6,    7,    8,    9,
   10,   11,   12,   13,   14,   59,   60,    0,   44,   76,
   70,    0,    0,    0,    0,  100,  101,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    5,    0,    0,   73,    0,    0,    0,    0,   98,   97,
   93,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    4,    0,    0,   77,    0,    0,    0,   53,    0,
   94,    0,    0,   82,   83,   84,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   21,   65,
    0,    0,   96,    0,   95,    0,   23,   24,   25,    0,
    0,   52,    0,   79,   22,
};
static const YYINT yydgoto[] = {                          2,
   85,   86,   87,   88,   89,   90,   32,  158,   91,   92,
   93,   94,   95,  120,  151,  123,   59,  159,  160,   22,
    3,   12,   13,    7,    8,    9,   23,   24,   47,   48,
   49,   14,   15,   41,   16,   55,   56,   57,   73,   74,
   17,
};
static const YYINT yysindex[] = {                      -269,
 -239,    0, -267,    0,    0,    0, -225,    0, -256, -253,
 -243, -267,    0,    0,  -95, -221,   -2,    0,    0,  -36,
 -216,   10, -246,    0,    0,    0,    0,    0,    0, -229,
    0,   17,   -9, -199, -234,    0, -234,    0, -256, -211,
 -193, -234,  -53,  -20, -189, -178,  -29,    0, -150,  -28,
    0,    0,    0,    0, -200,    0, -249,  398,  -17,  -24,
 -229,    0,    0,    0, -234,    0,    0,    0,    0,    0,
    0, -148, -190,    0,  -88,  -38,  -38, -146,    0,  -38,
  -38,  398,    0,    0, -238, -173,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -144,    0,    0,
    0, -249,  -38,  -38,  -33,    0,    0, -138, -137,  -38,
  -38,  279,  279, -136,  240,  260,  410,  -38, -154, -122,
    0,  398,   15,    0,  279,  199,  -38,  -38,    0,    0,
    0,  140,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
  -38,  -38,  -38,  -38,  -38,  -38,  398,  398,  -38,  279,
 -149,    0, -147, -238,    0, -127,  207,  279,    0,  -19,
    0, -174, -174,    0,    0,    0,  316,  298,  331,  331,
 -185, -185, -185, -185,  279,  -78,  357, -119,    0,    0,
 -116,  -38,    0,  -38,    0,  398,    0,    0,    0, -139,
  279,    0,  376,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  152,    0,    0,    0,    0,    0,    0, -104,
 -103,    0,    0,    0,    0,    0,    0,    0,    0, -188,
    0, -186,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -18,    0,  -18,    0,    0,    0,
    0,  -18,    0,    0, -102, -101,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -41,    0,    0,    0,    0,    0,
    0, -133, -132,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -129,    0,    0,  -11,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -125,
    0,    0,    0,    0,    0,    0,    0,  -10,    0,    0,
    0,   -8,   25,    0,    0,    0,  166,  168,  -14,   19,
   49,   73,   97,  121, -123,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -121,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -76,  -80,    0,    0,    0,    0,    0,  -12,    0,    0,
    0,    0,    0,   14,    0,    0,    0,  -13,    0,    0,
    0,    0,  160,    0,  173,    0,    0,  143,  -27,  119,
    0,  175,    0,  127,    0,    0,  136,    0,    0,   90,
    0,
};
#define YYTABLESIZE 691
static const YYINT yytable[] = {                         99,
   20,  111,  104,   35,  119,  117,  128,   71,   25,   50,
   21,   66,   68,   26,   60,    1,   97,   72,   75,   10,
   11,  185,   46,   27,   76,   77,   85,   30,   78,   54,
   55,   43,   80,   79,   80,   31,  119,   33,   81,   82,
   36,   83,   84,   38,   39,  154,    4,    5,    6,   37,
  118,   99,   45,   46,   34,   40,   42,  127,   44,   86,
   18,    5,    6,  112,  113,   81,   58,  115,  116,   61,
  176,  177,   62,  119,   52,   53,   54,   63,   85,  133,
  134,  135,  136,  137,   80,   69,   53,   54,   64,   87,
  125,  126,  135,  136,  137,  119,  119,  131,  132,  101,
  102,   38,   38,   41,   41,  150,   67,   96,  100,  193,
  114,   86,  119,   88,  157,  122,  121,   81,  129,  130,
  162,  163,  164,  165,  166,  167,  168,  169,  170,  171,
  172,  173,  174,  175,  146,  152,  178,   89,  153,  155,
  179,   87,  180,  182,  190,  133,  134,  135,  136,  137,
  194,    3,   61,   62,   47,   48,   15,   16,  148,  189,
   17,   90,  138,  139,   20,   88,   19,  181,   18,  191,
  192,   28,  140,  141,  142,  143,  144,  145,   75,   19,
  161,   51,  103,   99,   76,   77,   29,   98,   78,   89,
   70,  124,    0,   79,   80,    0,  186,  187,   81,   82,
    0,   83,   84,    0,    0,    0,   91,    0,   92,    0,
    0,    0,    0,   90,    0,    0,    0,    0,  105,  106,
  107,    0,    0,   99,   99,   99,   99,   99,  108,    0,
    0,  109,   99,    0,    0,    0,   99,   99,    0,    0,
   99,   99,    0,    0,    0,  110,    0,    0,   99,   99,
   99,   99,   99,   99,   99,   99,   80,   80,   91,   85,
   92,   65,   65,   85,   85,   80,   65,   85,   85,   80,
   80,  184,   46,   80,   80,   85,   85,   85,   85,   54,
   55,   80,   80,   80,   80,   80,   80,   80,   80,   81,
   81,  156,   86,    0,    0,    0,   86,   86,   81,  183,
   86,   86,   81,   81,    0,    0,   81,   81,   86,   86,
   86,   86,    0,    0,   81,   81,   81,   81,   81,   81,
   81,   81,   87,    0,    0,    0,   87,   87,    0,    0,
   87,   87,    0,    0,    0,    0,    0,    0,   87,   87,
   87,   87,   87,   87,   87,   87,   88,    0,    0,    0,
   88,   88,    0,    0,   88,   88,    0,    0,    0,    0,
    0,    0,   88,   88,   88,   88,   88,   88,   88,   88,
   89,    0,    0,    0,   89,   89,    0,    0,   89,   89,
    0,    0,    0,    0,    0,    0,   89,   89,   89,   89,
   89,   89,   89,   89,   90,    0,    0,    0,   90,   90,
    0,    0,   90,   90,  133,  134,  135,  136,  137,    0,
   90,   90,   90,   90,   90,   90,   90,   90,    0,    0,
    0,  138,  139,    0,    0,    0,    0,    0,    0,    0,
    0,  140,  141,  142,  143,  144,  145,    0,    0,   91,
    0,   92,    0,   91,   91,   92,   92,   91,   91,    0,
   92,    0,    0,    0,    0,   91,   91,   92,   92,    0,
    0,    0,    0,  133,  134,  135,  136,  137,    0,    0,
    0,  133,  134,  135,  136,  137,    0,    0,    0,    0,
  138,  139,    0,    0,    0,    0,    0,    0,  138,  139,
  140,  141,  142,  143,  144,  145,    0,    0,  140,  141,
  142,  143,  144,  145,  133,  134,  135,  136,  137,    0,
    0,    0,    0,  147,    0,    0,    0,    0,    0,    0,
    0,  138,  139,    0,  133,  134,  135,  136,  137,    0,
    0,  140,  141,  142,  143,  144,  145,  148,    0,    0,
    0,  138,  139,  133,  134,  135,  136,  137,    0,    0,
    0,  140,  141,  142,  143,  144,  145,    0,    0,    0,
  138,  139,  133,  134,  135,  136,  137,    0,    0,    0,
  140,  141,  142,  143,  144,  145,    0,    0,    0,  138,
  133,  134,  135,  136,  137,    0,    0,    0,    0,  140,
  141,  142,  143,  144,  145,  133,  134,  135,  136,  137,
    0,    0,    0,    0,    0,    0,    0,  140,  141,  142,
  143,  144,  145,   75,    0,    0,    0,    0,    0,   76,
   77,    0,    0,   78,  142,  143,  144,  145,   79,   80,
    0,    0,   75,   81,   82,  188,   83,   84,   76,   77,
    0,    0,   78,    0,    0,    0,    0,   79,   80,    0,
    0,  195,   81,   82,   75,   83,   84,    0,    0,    0,
   76,   77,    0,    0,   78,    0,   75,    0,    0,   79,
   80,    0,   76,   77,   81,   82,   78,   83,   84,    0,
    0,   79,   80,    0,    0,    0,  149,   82,    0,   83,
   84,
};
static const YYINT yycheck[] = {                         41,
  257,   40,   91,   40,   85,   82,   40,  257,  262,   37,
  267,   41,   41,  267,   42,  285,   41,  267,  257,  287,
  288,   41,   41,  267,  263,  264,   41,  123,  267,   41,
   41,   41,   41,  272,  273,  257,  117,   40,  277,  278,
  257,  280,  281,  290,  291,  122,  286,  287,  288,   40,
  289,   93,  287,  288,   91,  285,   40,   91,  258,   41,
  286,  287,  288,   76,   77,   41,  260,   80,   81,  123,
  147,  148,   93,  154,  286,  287,  288,  267,   93,  265,
  266,  267,  268,  269,   93,  286,  287,  288,  267,   41,
  103,  104,  267,  268,  269,  176,  177,  110,  111,  290,
  291,  290,  291,  290,  291,  118,  257,  125,  257,  186,
  257,   93,  193,   41,  127,  260,  290,   93,  257,  257,
  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,
  143,  144,  145,  146,  271,  290,  149,   41,  261,  125,
  290,   93,  290,  271,  261,  265,  266,  267,  268,  269,
  290,    0,  257,  257,  257,  257,  290,  290,  278,  279,
  290,   41,  282,  283,  290,   93,  290,  154,  290,  182,
  184,   12,  292,  293,  294,  295,  296,  297,  257,    7,
   41,   39,  271,   65,  263,  264,   12,   61,  267,   93,
   55,  102,   -1,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,   -1,   -1,   -1,   41,   -1,   41,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,  257,  258,
  259,   -1,   -1,  265,  266,  267,  268,  269,  267,   -1,
   -1,  270,  274,   -1,   -1,   -1,  278,  279,   -1,   -1,
  282,  283,   -1,   -1,   -1,  284,   -1,   -1,  290,  291,
  292,  293,  294,  295,  296,  297,  265,  266,   93,  274,
   93,  291,  291,  278,  279,  274,  291,  282,  283,  278,
  279,  291,  291,  282,  283,  290,  291,  292,  293,  291,
  291,  290,  291,  292,  293,  294,  295,  296,  297,  265,
  266,   93,  274,   -1,   -1,   -1,  278,  279,  274,   93,
  282,  283,  278,  279,   -1,   -1,  282,  283,  290,  291,
  292,  293,   -1,   -1,  290,  291,  292,  293,  294,  295,
  296,  297,  274,   -1,   -1,   -1,  278,  279,   -1,   -1,
  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,  290,  291,
  292,  293,  294,  295,  296,  297,  274,   -1,   -1,   -1,
  278,  279,   -1,   -1,  282,  283,   -1,   -1,   -1,   -1,
   -1,   -1,  290,  291,  292,  293,  294,  295,  296,  297,
  274,   -1,   -1,   -1,  278,  279,   -1,   -1,  282,  283,
   -1,   -1,   -1,   -1,   -1,   -1,  290,  291,  292,  293,
  294,  295,  296,  297,  274,   -1,   -1,   -1,  278,  279,
   -1,   -1,  282,  283,  265,  266,  267,  268,  269,   -1,
  290,  291,  292,  293,  294,  295,  296,  297,   -1,   -1,
   -1,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  292,  293,  294,  295,  296,  297,   -1,   -1,  274,
   -1,  274,   -1,  278,  279,  278,  279,  282,  283,   -1,
  283,   -1,   -1,   -1,   -1,  290,  291,  290,  291,   -1,
   -1,   -1,   -1,  265,  266,  267,  268,  269,   -1,   -1,
   -1,  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,
  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
  292,  293,  294,  295,  296,  297,   -1,   -1,  292,  293,
  294,  295,  296,  297,  265,  266,  267,  268,  269,   -1,
   -1,   -1,   -1,  274,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  282,  283,   -1,  265,  266,  267,  268,  269,   -1,
   -1,  292,  293,  294,  295,  296,  297,  278,   -1,   -1,
   -1,  282,  283,  265,  266,  267,  268,  269,   -1,   -1,
   -1,  292,  293,  294,  295,  296,  297,   -1,   -1,   -1,
  282,  283,  265,  266,  267,  268,  269,   -1,   -1,   -1,
  292,  293,  294,  295,  296,  297,   -1,   -1,   -1,  282,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,  292,
  293,  294,  295,  296,  297,  265,  266,  267,  268,  269,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,  294,
  295,  296,  297,  257,   -1,   -1,   -1,   -1,   -1,  263,
  264,   -1,   -1,  267,  294,  295,  296,  297,  272,  273,
   -1,   -1,  257,  277,  278,  279,  280,  281,  263,  264,
   -1,   -1,  267,   -1,   -1,   -1,   -1,  272,  273,   -1,
   -1,  276,  277,  278,  257,  280,  281,   -1,   -1,   -1,
  263,  264,   -1,   -1,  267,   -1,  257,   -1,   -1,  272,
  273,   -1,  263,  264,  277,  278,  267,  280,  281,   -1,
   -1,  272,  273,   -1,   -1,   -1,  277,  278,   -1,  280,
  281,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 297
#define YYUNDFTOKEN 341
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID",
"NUM","STRING","BEGIN_","END","MAIN","READ","WRITE","PLUS","MINUS","MUL","DIV",
"MOD","AMPERSAND","EQUAL","BREAKPOINT","IF","THEN","ELSE","ENDIF","WHILE","DO",
"ENDWHILE","BREAK","CONTINUE","AND","OR","NOT","DECL","ENDDECL","INT","STR",
"RETURN","SEMICOLON","COMMA","EQ","NEQ","LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : GDeclBlock FDefBlock MainBlock",
"start : GDeclBlock MainBlock",
"start : GDeclBlock",
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
"LType : INT",
"LType : STR",
"LIDList : LIDList COMMA LID",
"LIDList : LID",
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
#line 408 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at statement %d\n", s, statementCount);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yydebug = 1;
		filePtr = fopen("../Target_Files/round1.xsm", "w");
		writeXexeHeader(filePtr);
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
#line 576 "y.tab.c"

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
#line 56 "ast.y"
	{}
break;
case 2:
#line 57 "ast.y"
	{}
break;
case 3:
#line 58 "ast.y"
	{	
												printf("\n⛔ No Code Provided\n");
												exit(1);
											}
break;
case 4:
#line 66 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 5:
#line 67 "ast.y"
	{}
break;
case 14:
#line 73 "ast.y"
	{ ++statementCount; }
break;
case 15:
#line 76 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 16:
#line 79 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 17:
#line 82 "ast.y"
	{ 
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
											}
break;
case 18:
#line 86 "ast.y"
	{	 
												yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
												yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 19:
#line 91 "ast.y"
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
case 20:
#line 105 "ast.y"
	{}
break;
case 21:
#line 108 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, RETURN_NODE, NULL, 0, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 22:
#line 113 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 23:
#line 114 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 24:
#line 117 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 25:
#line 120 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 26:
#line 123 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 27:
#line 126 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 28:
#line 129 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 29:
#line 133 "ast.y"
	{ 
											GSTPrint();

											int freeStackMem = getFreeStackMemoryValue();
											fprintf(filePtr, "MOV SP, %d\n", freeStackMem - 1);
											fprintf(filePtr, "MOV BP, %d\n", freeStackMem);
											fprintf(filePtr, "PUSH R0\n");
											fprintf(filePtr, "CALL F0\n");
											fprintf(filePtr, "INT 10\n");
										}
break;
case 30:
#line 143 "ast.y"
	{}
break;
case 31:
#line 146 "ast.y"
	{}
break;
case 32:
#line 147 "ast.y"
	{}
break;
case 33:
#line 150 "ast.y"
	{}
break;
case 34:
#line 153 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 35:
#line 154 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 36:
#line 157 "ast.y"
	{}
break;
case 37:
#line 158 "ast.y"
	{}
break;
case 38:
#line 161 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1, NULL); }
break;
case 39:
#line 162 "ast.y"
	{ 
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), yystack.l_mark[-1].node->intConstVal, NULL); 
										}
break;
case 40:
#line 169 "ast.y"
	{ 
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), -1, getParamListHead());
											flushParamList();
											paramCount = 0;
											setParamType(TYPE_VOID);
										}
break;
case 41:
#line 175 "ast.y"
	{
											if (getDeclarationType() == TYPE_INT)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1, NULL);

											if (getDeclarationType() == TYPE_STR)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1, NULL);
										}
break;
case 42:
#line 182 "ast.y"
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
case 43:
#line 194 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 44:
#line 200 "ast.y"
	{}
break;
case 45:
#line 201 "ast.y"
	{}
break;
case 46:
#line 202 "ast.y"
	{}
break;
case 47:
#line 205 "ast.y"
	{ setParamType(TYPE_INT); }
break;
case 48:
#line 206 "ast.y"
	{ setParamType(TYPE_STR); }
break;
case 49:
#line 207 "ast.y"
	{ setParamType(TYPE_INT_PTR); }
break;
case 50:
#line 208 "ast.y"
	{ setParamType(TYPE_STR_PTR); }
break;
case 51:
#line 211 "ast.y"
	{ 
											paramListInstall(getParamType(), yystack.l_mark[0].node->nodeName); 
											++paramCount;
										}
break;
case 52:
#line 220 "ast.y"
	{ 
											yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node);
										}
break;
case 53:
#line 223 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 54:
#line 224 "ast.y"
	{}
break;
case 55:
#line 227 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node; 
											/* ++argCount;*/
										}
break;
case 56:
#line 236 "ast.y"
	{}
break;
case 57:
#line 237 "ast.y"
	{}
break;
case 58:
#line 240 "ast.y"
	{ 
															if(GSTLookup(yystack.l_mark[0].node->nodeName) == NULL){
																printf("\nFunction %s is not declared\n", yystack.l_mark[0].node->nodeName);
																exit(1);
															}
															yyval.node = yystack.l_mark[0].node; 
															setCurrentFuncName(yystack.l_mark[0].node->nodeName);
														}
break;
case 59:
#line 251 "ast.y"
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
case 60:
#line 267 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 61:
#line 273 "ast.y"
	{ setFuncType(TYPE_INT); }
break;
case 62:
#line 274 "ast.y"
	{ setFuncType(TYPE_STR); }
break;
case 63:
#line 275 "ast.y"
	{ setFuncType(TYPE_INT_PTR); }
break;
case 64:
#line 276 "ast.y"
	{ setFuncType(TYPE_STR_PTR); }
break;
case 65:
#line 279 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 66:
#line 288 "ast.y"
	{}
break;
case 67:
#line 289 "ast.y"
	{}
break;
case 68:
#line 292 "ast.y"
	{}
break;
case 69:
#line 293 "ast.y"
	{}
break;
case 70:
#line 296 "ast.y"
	{}
break;
case 71:
#line 299 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 72:
#line 300 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 73:
#line 303 "ast.y"
	{}
break;
case 74:
#line 304 "ast.y"
	{}
break;
case 75:
#line 307 "ast.y"
	{ LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType()); }
break;
case 76:
#line 308 "ast.y"
	{
											if(getDeclarationType() == TYPE_INT)
												LSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR);	

											if(getDeclarationType() == TYPE_STR)
												LSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR);	
										}
break;
case 77:
#line 324 "ast.y"
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
case 78:
#line 341 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 79:
#line 344 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 80:
#line 352 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 81:
#line 353 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 82:
#line 354 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 83:
#line 355 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 84:
#line 356 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 85:
#line 357 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 86:
#line 358 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 87:
#line 359 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 88:
#line 360 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 89:
#line 361 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 90:
#line 362 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 91:
#line 363 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, AND_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 92:
#line 364 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, OR_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 93:
#line 365 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NOT_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 94:
#line 366 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 95:
#line 367 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, 0, NULL, NULL, NULL, NULL); 
										yyval.node->argListHead = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 96:
#line 374 "ast.y"
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
case 97:
#line 383 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->dataType == TYPE_INT || yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT_PTR, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR || yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR_PTR, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 98:
#line 391 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 99:
#line 399 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 100:
#line 403 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 101:
#line 404 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1294 "y.tab.c"
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
