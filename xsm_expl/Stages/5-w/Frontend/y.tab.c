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
    2,    2,    2,    2,    3,    4,    5,    5,   15,   14,
    6,    6,    9,   10,   11,   12,   13,   20,   20,   23,
   23,   24,   25,   25,   26,   26,   27,   27,   27,   27,
   28,   28,   28,   30,   30,   29,   19,   19,   19,   18,
   21,   21,    7,   31,   32,   34,   34,   17,   33,   33,
   35,   35,   36,   37,   37,   38,   22,   39,   16,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,
};
static const YYINT yylen[] = {                            2,
    3,    2,    1,    3,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    3,    6,    1,    3,
    7,    5,    5,    5,    1,    1,    1,    3,    2,    2,
    1,    3,    1,    1,    3,    1,    1,    4,    4,    2,
    3,    1,    0,    1,    1,    2,    3,    1,    0,    1,
    2,    1,    1,    5,    5,    1,    1,    5,    3,    2,
    2,    1,    3,    3,    1,    1,    7,    2,    5,    3,
    3,    3,    3,    3,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    3,    4,    4,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   29,   33,   34,    0,   31,    0,    0,
   57,    0,    2,   52,    0,    0,    0,   28,   30,    0,
    0,    0,   36,   68,    1,   51,    0,   53,    0,    0,
    0,    0,   40,   32,    0,    0,    0,    0,    0,    0,
   44,   45,    0,   42,    0,   35,   60,    0,    0,   62,
    0,    0,    0,    0,   38,    0,   39,   46,   66,    0,
   65,   59,   61,    0,    0,    0,   27,    0,    0,    0,
   25,   26,    0,    0,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   54,   55,    0,   41,   63,    0,    0,
    0,    0,   90,   91,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    5,    0,    0,   64,
    0,    0,    0,    0,   76,   75,   85,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    4,    0,    0,   67,
    0,    0,    0,   48,    0,   86,    0,    0,   72,   73,
   74,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   20,   58,    0,    0,   88,    0,   87,    0,
   22,   23,   24,    0,    0,   47,    0,   69,   21,
};
static const YYINT yydgoto[] = {                          2,
   73,   74,   75,   76,   77,   78,   29,  143,   79,   80,
   81,   82,   83,  106,  136,  109,   52,  144,  145,    3,
   12,   13,    7,    8,    9,   22,   23,   43,   44,   45,
   14,   15,   37,   16,   49,   50,   60,   61,   17,
};
static const YYINT yysindex[] = {                      -278,
 -272,    0, -267,    0,    0,    0, -262,    0, -249, -253,
    0, -267,    0,    0, -112, -225,   -3,    0,    0,  -36,
 -217, -229,    0,    0,    0,    0, -232,    0,   14,   24,
 -182, -259,    0,    0, -249, -252, -180, -259,  -45,  -10,
    0,    0,  -29,    0, -173,    0,    0, -170, -237,    0,
  364,  -34,  -28, -232,    0, -259,    0,    0,    0, -216,
    0,    0,    0,  -88,  -38,  -38,    0,  -38,  -38,  364,
    0,    0,  266, -184,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -152,    0,    0, -170,  -38,
  -38,  -35,    0,    0,  -38,  -38,  -38,  -38,  -91,  -91,
 -139,  -98,  375,  -38, -181, -150,    0,  364,  -12,    0,
  -91,  199,  -38,  -38,    0,    0,    0,  140,  -38,  -38,
  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
  -38,  364,  364,  -38,  -91, -175,    0, -174,  266,    0,
 -154,  207,  -91,    0,  -24,    0, -210, -210,    0,    0,
    0,  218,  240,  283,  283, -222, -222, -222, -222,  309,
  331, -146,    0,    0, -137,  -38,    0,  -38,    0,  364,
    0,    0,    0, -165,  -91,    0,  342,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  131,    0,    0,    0,    0,    0,    0, -123,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -209,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -19,    0,    0,    0,    0,    0,  -19,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -41,    0,    0,    0,    0,    0,    0, -149, -145,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -138,    0,    0,  -18,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -131,    0,    0,    0,    0,    0,
    0,    0,  -11,    0,    0,    0,   -8,   25,    0,    0,
    0,  166,  168,  -14,   19,   49,   73,   97,  121,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -130,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -60,  -72,    0,    0,    0,    0,    0,  -27,    0,    0,
    0,    0,    0,    1,    0,    0,    0,   -7,    0,    0,
    0,  151,    0,  157,  -30,    0,  130,  134,  117,    0,
  167,    0,  128,    0,    0,  137,    0,   98,    0,
};
#define YYTABLESIZE 656
static const YYINT yytable[] = {                         89,
  105,   98,   91,   32,  114,   48,    1,   20,   24,  103,
   27,   57,   85,    4,    5,    6,  169,   21,   48,   10,
   11,   43,   49,   18,    5,    6,   77,   41,   42,   50,
  105,   28,   70,   47,    5,    6,   30,   99,  100,   33,
  101,  102,  119,  120,  121,  122,  123,  139,   62,    5,
    6,   89,   36,   38,   31,  113,  121,  122,  123,   78,
   34,   35,  111,  112,   39,   71,  105,  115,  116,  117,
  118,  160,  161,   88,   89,   40,  135,   54,   77,   51,
   37,   37,   55,   58,   70,  142,   59,  105,  105,   79,
   84,  147,  148,  149,  150,  151,  152,  153,  154,  155,
  156,  157,  158,  159,  105,  107,  162,  108,  137,  177,
  138,   78,  140,   80,  163,  164,  166,   71,  119,  120,
  121,  122,  123,  174,  178,  119,  120,  121,  122,  123,
    3,  133,  173,   56,  132,  124,  125,   81,  175,  165,
   15,   79,  124,  125,   16,  126,  127,  128,  129,  130,
  131,   17,  126,  127,  128,  129,  130,  131,   19,   18,
  176,   82,   25,   19,   46,   80,  119,  120,  121,  122,
  123,   53,   87,  119,  120,  121,  122,  123,   26,  133,
  146,   86,   90,  124,  125,   63,  110,    0,    0,   81,
  124,  125,    0,  126,  127,  128,  129,  130,  131,    0,
  126,  127,  128,  129,  130,  131,   83,    0,   84,    0,
    0,    0,    0,   82,    0,    0,    0,    0,   92,   93,
   94,    0,    0,   89,   89,   89,   89,   89,   95,    0,
    0,   96,   89,    0,    0,    0,   89,   89,    0,    0,
   89,   89,    0,    0,    0,   97,    0,    0,   89,   89,
   89,   89,   89,   89,   89,   89,   70,   70,   83,   77,
   84,   56,   56,   77,   77,   70,  168,   77,   77,   70,
   70,   43,   49,   70,   70,   77,   77,   77,   77,   50,
    0,   70,   70,   70,   70,   70,   70,   70,   70,   71,
   71,  141,   78,    0,    0,    0,   78,   78,   71,  167,
   78,   78,   71,   71,    0,    0,   71,   71,   78,   78,
   78,   78,    0,    0,   71,   71,   71,   71,   71,   71,
   71,   71,   79,    0,    0,    0,   79,   79,    0,    0,
   79,   79,    0,    0,    0,    0,    0,    0,   79,   79,
   79,   79,   79,   79,   79,   79,   80,    0,    0,    0,
   80,   80,    0,    0,   80,   80,    0,    0,    0,    0,
    0,    0,   80,   80,   80,   80,   80,   80,   80,   80,
   81,    0,    0,    0,   81,   81,    0,    0,   81,   81,
    0,    0,    0,    0,    0,    0,   81,   81,   81,   81,
   81,   81,   81,   81,   82,    0,    0,    0,   82,   82,
    0,    0,   82,   82,  119,  120,  121,  122,  123,    0,
   82,   82,   82,   82,   82,   82,   82,   82,    0,    0,
    0,  124,  125,    0,    0,    0,    0,    0,    0,    0,
    0,  126,  127,  128,  129,  130,  131,    0,    0,   83,
    0,   84,    0,   83,   83,   84,   84,   83,   83,    0,
   84,    0,    0,    0,    0,   83,   83,   84,   84,    0,
    0,    0,    0,  119,  120,  121,  122,  123,    0,    0,
    0,  119,  120,  121,  122,  123,    0,    0,    0,    0,
  124,  125,  119,  120,  121,  122,  123,    0,  124,  125,
  126,  127,  128,  129,  130,  131,    0,    0,  126,  127,
  128,  129,  130,  131,  119,  120,  121,  122,  123,  126,
  127,  128,  129,  130,  131,    0,    0,    0,    0,    0,
    0,  124,   64,    0,    0,    0,    0,    0,   65,   66,
    0,  126,  127,  128,  129,  130,  131,   67,   68,    0,
    0,    0,   69,   70,    0,   71,   72,  119,  120,  121,
  122,  123,    0,    0,  104,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   64,    0,    0,    0,    0,
    0,   65,   66,    0,    0,    0,  128,  129,  130,  131,
   67,   68,    0,  170,  171,   69,   70,   64,   71,   72,
    0,    0,    0,   65,   66,    0,    0,    0,   64,    0,
    0,    0,   67,   68,   65,   66,    0,   69,   70,  172,
   71,   72,    0,   67,   68,    0,    0,  179,   69,   70,
   64,   71,   72,    0,    0,    0,   65,   66,    0,    0,
    0,   64,    0,    0,    0,   67,   68,   65,   66,    0,
   69,   70,    0,   71,   72,    0,   67,   68,    0,    0,
    0,  134,   70,    0,   71,   72,
};
static const YYINT yycheck[] = {                         41,
   73,   40,   91,   40,   40,   36,  285,  257,  262,   70,
  123,   41,   41,  286,  287,  288,   41,  267,   49,  287,
  288,   41,   41,  286,  287,  288,   41,  287,  288,   41,
  103,  257,   41,  286,  287,  288,   40,   65,   66,  257,
   68,   69,  265,  266,  267,  268,  269,  108,  286,  287,
  288,   93,  285,   40,   91,   91,  267,  268,  269,   41,
  290,  291,   90,   91,   41,   41,  139,   95,   96,   97,
   98,  132,  133,  290,  291,  258,  104,  123,   93,  260,
  290,  291,   93,  257,   93,  113,  257,  160,  161,   41,
  125,  119,  120,  121,  122,  123,  124,  125,  126,  127,
  128,  129,  130,  131,  177,  290,  134,  260,  290,  170,
  261,   93,  125,   41,  290,  290,  271,   93,  265,  266,
  267,  268,  269,  261,  290,  265,  266,  267,  268,  269,
    0,  278,  279,  257,  274,  282,  283,   41,  166,  139,
  290,   93,  282,  283,  290,  292,  293,  294,  295,  296,
  297,  290,  292,  293,  294,  295,  296,  297,  290,  290,
  168,   41,   12,    7,   35,   93,  265,  266,  267,  268,
  269,   38,   56,  265,  266,  267,  268,  269,   12,  278,
   41,   54,  271,  282,  283,   49,   89,   -1,   -1,   93,
  282,  283,   -1,  292,  293,  294,  295,  296,  297,   -1,
  292,  293,  294,  295,  296,  297,   41,   -1,   41,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,  257,  258,
  259,   -1,   -1,  265,  266,  267,  268,  269,  267,   -1,
   -1,  270,  274,   -1,   -1,   -1,  278,  279,   -1,   -1,
  282,  283,   -1,   -1,   -1,  284,   -1,   -1,  290,  291,
  292,  293,  294,  295,  296,  297,  265,  266,   93,  274,
   93,  291,  291,  278,  279,  274,  291,  282,  283,  278,
  279,  291,  291,  282,  283,  290,  291,  292,  293,  291,
   -1,  290,  291,  292,  293,  294,  295,  296,  297,  265,
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
  282,  283,  265,  266,  267,  268,  269,   -1,  282,  283,
  292,  293,  294,  295,  296,  297,   -1,   -1,  292,  293,
  294,  295,  296,  297,  265,  266,  267,  268,  269,  292,
  293,  294,  295,  296,  297,   -1,   -1,   -1,   -1,   -1,
   -1,  282,  257,   -1,   -1,   -1,   -1,   -1,  263,  264,
   -1,  292,  293,  294,  295,  296,  297,  272,  273,   -1,
   -1,   -1,  277,  278,   -1,  280,  281,  265,  266,  267,
  268,  269,   -1,   -1,  289,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,   -1,
   -1,  263,  264,   -1,   -1,   -1,  294,  295,  296,  297,
  272,  273,   -1,  275,  276,  277,  278,  257,  280,  281,
   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,  257,   -1,
   -1,   -1,  272,  273,  263,  264,   -1,  277,  278,  279,
  280,  281,   -1,  272,  273,   -1,   -1,  276,  277,  278,
  257,  280,  281,   -1,   -1,   -1,  263,  264,   -1,   -1,
   -1,  257,   -1,   -1,   -1,  272,  273,  263,  264,   -1,
  277,  278,   -1,  280,  281,   -1,  272,  273,   -1,   -1,
   -1,  277,  278,   -1,  280,  281,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 297
#define YYUNDFTOKEN 339
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
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
"GID : MUL ID",
"ParamList : ParamList COMMA Param",
"ParamList : Param",
"ParamList :",
"ParamType : INT",
"ParamType : STR",
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
"FBody : BEGIN_ Slist retStmt END SEMICOLON",
"LDeclBlock : DECL LDeclList ENDDECL",
"LDeclBlock : DECL ENDDECL",
"LDeclList : LDeclList LDecl",
"LDeclList : LDecl",
"LDecl : Type LIDList SEMICOLON",
"LIDList : LIDList COMMA LID",
"LIDList : LID",
"LID : ID",
"MainBlock : MainFunc '(' ')' '{' LDeclBlock MBody '}'",
"MainFunc : INT MAIN",
"MBody : BEGIN_ Slist retStmt END SEMICOLON",
"expr : expr PLUS expr",
"expr : expr MINUS expr",
"expr : expr MUL expr",
"expr : expr DIV expr",
"expr : expr MOD expr",
"expr : AMPERSAND expr",
"expr : MUL expr",
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
#line 362 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at statement %d\n", s, statementCount);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yydebug = 0;
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
#line 548 "y.tab.c"

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
#line 95 "ast.y"
	{}
break;
case 20:
#line 98 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, RETURN_NODE, NULL, 0, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 21:
#line 103 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 22:
#line 104 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 23:
#line 107 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 24:
#line 110 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 25:
#line 113 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 26:
#line 116 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 27:
#line 119 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 28:
#line 123 "ast.y"
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
case 29:
#line 133 "ast.y"
	{}
break;
case 30:
#line 136 "ast.y"
	{}
break;
case 31:
#line 137 "ast.y"
	{}
break;
case 32:
#line 140 "ast.y"
	{}
break;
case 33:
#line 143 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 34:
#line 144 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 35:
#line 147 "ast.y"
	{}
break;
case 36:
#line 148 "ast.y"
	{}
break;
case 37:
#line 151 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1, NULL); }
break;
case 38:
#line 152 "ast.y"
	{ 
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), yystack.l_mark[-1].node->intConstVal, NULL); 
										}
break;
case 39:
#line 159 "ast.y"
	{ 
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), -1, getParamListHead());
											flushParamList();
											paramCount = 0;
											setParamType(TYPE_VOID);
										}
break;
case 40:
#line 165 "ast.y"
	{
											if (getDeclarationType() == TYPE_INT)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1, NULL);

											if (getDeclarationType() == TYPE_STR)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1, NULL);
										}
break;
case 41:
#line 177 "ast.y"
	{}
break;
case 42:
#line 178 "ast.y"
	{}
break;
case 43:
#line 179 "ast.y"
	{}
break;
case 44:
#line 182 "ast.y"
	{ setParamType(TYPE_INT); }
break;
case 45:
#line 183 "ast.y"
	{ setParamType(TYPE_STR); }
break;
case 46:
#line 186 "ast.y"
	{ 
											paramListInstall(getParamType(), yystack.l_mark[0].node->nodeName); 
											++paramCount;
										}
break;
case 47:
#line 195 "ast.y"
	{ 
											yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node);
										}
break;
case 48:
#line 198 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 49:
#line 199 "ast.y"
	{}
break;
case 50:
#line 202 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node; 
											/* ++argCount;*/
										}
break;
case 51:
#line 211 "ast.y"
	{}
break;
case 52:
#line 212 "ast.y"
	{}
break;
case 53:
#line 215 "ast.y"
	{ 
															if(GSTLookup(yystack.l_mark[0].node->nodeName) == NULL){
																printf("\nFunction %s is not declared\n", yystack.l_mark[0].node->nodeName);
																exit(1);
															}
															yyval.node = yystack.l_mark[0].node; 
															setCurrentFuncName(yystack.l_mark[0].node->nodeName);
														}
break;
case 54:
#line 226 "ast.y"
	{
															char* currentFuncName = getCurrentFuncName();
															addFunctionLST(currentFuncName, LSTHead);	
															
															fprintf(filePtr, "F%d:\n", GSTLookup(currentFuncName)->fLabel);
															initFuncCalle(filePtr, paramCount);

															printAST(yystack.l_mark[-1].node);
															codeGen(yystack.l_mark[-1].node, filePtr);

															LSTPrint();
															flushLST();
															paramCount = 0;
														}
break;
case 55:
#line 242 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 56:
#line 248 "ast.y"
	{ setFuncType(TYPE_INT); }
break;
case 57:
#line 249 "ast.y"
	{ setFuncType(TYPE_STR); }
break;
case 58:
#line 252 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 59:
#line 261 "ast.y"
	{}
break;
case 60:
#line 262 "ast.y"
	{}
break;
case 61:
#line 265 "ast.y"
	{}
break;
case 62:
#line 266 "ast.y"
	{}
break;
case 63:
#line 269 "ast.y"
	{}
break;
case 64:
#line 272 "ast.y"
	{}
break;
case 65:
#line 273 "ast.y"
	{}
break;
case 66:
#line 276 "ast.y"
	{ LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType()); }
break;
case 67:
#line 286 "ast.y"
	{
														char* currentFuncName = getCurrentFuncName();
														addFunctionLST(currentFuncName, LSTHead);	

														fprintf(filePtr, "F0:\n");
														initFuncCalle(filePtr, paramCount);

														printAST(yystack.l_mark[-1].node);
														codeGen(yystack.l_mark[-1].node, filePtr);
														LSTPrint();
														flushLST();
														paramCount = 0;
												
														printFLT();
													}
break;
case 68:
#line 303 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 69:
#line 306 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 70:
#line 314 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 71:
#line 315 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 72:
#line 316 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 73:
#line 317 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 74:
#line 318 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 75:
#line 319 "ast.y"
	{ yyval.node = 	TreeCreate(TYPE_INT, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 76:
#line 320 "ast.y"
	{ 
										if (yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);	
			 						}
break;
case 77:
#line 327 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 78:
#line 328 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 79:
#line 329 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 80:
#line 330 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 81:
#line 331 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 82:
#line 332 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 83:
#line 333 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, AND_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 84:
#line 334 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, OR_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 85:
#line 335 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NOT_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 86:
#line 336 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 87:
#line 337 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, 0, NULL, NULL, NULL, NULL); 
										yyval.node->argListHead = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 88:
#line 344 "ast.y"
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
case 89:
#line 353 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 90:
#line 357 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 91:
#line 358 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1193 "y.tab.c"
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
