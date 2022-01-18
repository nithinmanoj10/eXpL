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

	int yylex(void);
	void yyerror(char const *s);
	int statementCount = 0;
	char* fileName;
#line 28 "ast.y"
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
#line 56 "y.tab.c"

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
#define DECL 282
#define ENDDECL 283
#define INT 284
#define STR 285
#define RETURN 286
#define SEMICOLON 287
#define COMMA 288
#define EQ 289
#define NEQ 290
#define LT 291
#define LTE 292
#define GT 293
#define GTE 294
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    3,    4,    5,    5,   15,   14,
    6,    6,    9,   10,   11,   12,   13,   18,   18,   21,
   21,   22,   23,   23,   24,   24,   25,   25,   25,   25,
   26,   26,   28,   28,   27,   19,   19,    7,   29,   30,
   32,   32,   17,   31,   31,   33,   33,   34,   35,   35,
   36,   20,   37,   16,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,
};
static const YYINT yylen[] = {                            2,
    3,    2,    1,    3,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    3,    6,    1,    3,
    7,    5,    5,    5,    1,    1,    1,    3,    2,    2,
    1,    3,    1,    1,    3,    1,    1,    4,    4,    2,
    3,    1,    1,    1,    2,    2,    1,    1,    5,    5,
    1,    1,    5,    3,    2,    2,    1,    3,    3,    1,
    1,    7,    2,    5,    3,    3,    3,    3,    3,    2,
    2,    3,    3,    3,    3,    3,    3,    3,    4,    1,
    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   29,   33,   34,    0,   31,    0,    0,
   52,    0,    2,   47,    0,    0,    0,   28,   30,    0,
    0,    0,   36,   63,    1,   46,    0,   48,    0,    0,
    0,    0,   40,   32,    0,    0,    0,    0,    0,    0,
   43,   44,    0,   42,    0,   35,   55,    0,    0,   57,
    0,    0,    0,    0,   38,    0,   39,   45,   61,    0,
   60,   54,   56,    0,    0,    0,   27,    0,    0,    0,
   25,   26,    0,    0,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   49,   50,    0,   41,   58,    0,    0,
    0,    0,   81,   82,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    5,    0,    0,   59,    0,
    0,    0,   71,   70,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    4,    0,    0,   62,    0,    0,   78,    0,    0,
   67,   68,   69,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   20,   53,    0,    0,   79,    0,   22,   23,
   24,    0,    0,    0,   64,   21,
};
static const YYINT yydgoto[] = {                          2,
   73,   74,   75,   76,   77,   78,   29,   98,   79,   80,
   81,   82,   83,  105,  131,  108,   52,    3,   12,   13,
    7,    8,    9,   22,   23,   43,   44,   45,   14,   15,
   37,   16,   49,   50,   60,   61,   17,
};
static const YYINT yysindex[] = {                      -274,
 -258,    0, -263,    0,    0,    0, -219,    0, -244, -252,
    0, -263,    0,    0, -109, -204,   -3,    0,    0,  -35,
 -202, -237,    0,    0,    0,    0, -225,    0,   27,   40,
 -190, -223,    0,    0, -244, -197, -176, -223,  -33,    6,
    0,    0,  -32,    0, -147,    0,    0, -146, -157,    0,
 -172,   -1,  -30, -225,    0, -223,    0,    0,    0, -210,
    0,    0,    0,  -88,  -36,  -36,    0,  -36,  -36, -172,
    0,    0, -112, -155,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -127,    0,    0, -146,  -36,
  -36,   43,    0,    0,  -36,  -36,  -36, -152, -152, -220,
 -171,  243,  -36, -151, -118,    0, -172,   22,    0, -152,
  -87,  -36,    0,    0,   34,  -36,  -36,  -36,  -36,  -36,
  -36,  -36,  -36,  -36,  -36,  -36, -172, -172,  -36, -152,
 -143,    0, -139, -112,    0, -122,  -81,    0, -138, -138,
    0,    0,    0,  -76,  -76, -233, -233, -233, -233,  169,
  210, -250,    0,    0, -111,  -36,    0, -172,    0,    0,
    0, -134, -152,  221,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  154,    0,    0,    0,    0,    0,    0, -102,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -185,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -41,    0,    0,    0,    0,    0, -130, -129,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -128,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -125,
    0,    0,    0,    0,    0,    0,    0,    0,  -11,   19,
    0,    0,    0,  -17,  126,   42,   63,   84,  105,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -124,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -69,  -71,    0,    0,    0,    0,    0,  340,    0,    0,
    0,    0,    0,   30,    0,    0,    0,    0,    0,  158,
    0,  164,  -29,    0,  137,  135,  119,    0,  182,    0,
  122,    0,    0,  146,    0,  107,    0,
};
#define YYTABLESIZE 524
static const YYINT yytable[] = {                         80,
  102,  104,   91,   97,   32,  136,   48,    1,   57,   24,
   85,  157,   20,   27,  116,  117,  118,  119,  120,   48,
   10,   11,   21,   72,    4,    5,    6,  128,  161,   65,
  104,  116,  117,  118,  119,  120,   30,  134,  121,  122,
  123,  124,  125,  126,  116,  117,  118,  119,  120,   34,
   35,   80,   28,  127,   33,   31,   36,  150,  151,   66,
   41,   42,  104,   18,    5,    6,   38,   40,  121,  122,
  123,  124,  125,  126,  138,   72,   88,   89,  104,  104,
   39,   65,   74,   51,   64,   47,    5,    6,  164,   54,
   65,   66,  104,  116,  117,  118,  119,  120,   55,   67,
   68,   37,   37,   75,   69,   70,  128,   71,   72,   58,
   59,   66,  116,  117,  118,  119,  120,  121,  122,  123,
  124,  125,  126,   84,   76,   62,    5,    6,  118,  119,
  120,  106,  107,  112,   74,  132,  121,  122,  123,  124,
  125,  126,  133,  153,   64,   77,  135,  154,  156,  162,
   65,   66,  165,    3,   51,   75,   15,   16,   17,   67,
   68,   19,   18,  155,   69,   70,   73,   71,   72,   25,
   19,   46,   53,  103,   87,   86,   76,  116,  117,  118,
  119,  120,   90,  116,  117,  118,  119,  120,  116,  117,
  118,  119,  120,   26,   63,  109,    0,   77,    0,    0,
    0,  121,  122,  123,  124,  125,  126,  121,  122,  123,
  124,  125,  126,    0,  123,  124,  125,  126,   73,    0,
   92,   93,   94,   80,   80,   80,   80,   80,    0,    0,
   95,    0,   80,   96,    0,    0,   80,   80,    0,    0,
    0,    0,    0,    0,    0,   80,    0,   80,   80,   80,
   80,   80,   80,   65,   65,   56,   72,   56,    0,    0,
   72,   72,   65,    0,    0,    0,   65,   65,    0,   72,
    0,   72,   72,    0,    0,   65,    0,   65,   65,   65,
   65,   65,   65,   66,   66,    0,    0,    0,    0,    0,
    0,    0,   66,    0,    0,    0,   66,   66,  116,  117,
  118,  119,  120,    0,    0,   66,    0,   66,   66,   66,
   66,   66,   66,    0,    0,   74,    0,    0,    0,   74,
   74,    0,  121,  122,  123,  124,  125,  126,   74,    0,
   74,   74,   74,   74,   74,   74,   75,    0,    0,    0,
   75,   75,    0,    0,    0,    0,    0,    0,    0,   75,
    0,   75,   75,   75,   75,   75,   75,   76,    0,    0,
    0,   76,   76,    0,    0,    0,    0,    0,    0,    0,
   76,    0,   76,   76,   76,   76,   76,   76,   77,    0,
    0,    0,   77,   77,    0,    0,    0,    0,    0,    0,
    0,   77,    0,   77,   77,   77,   77,   77,   77,   73,
    0,    0,    0,   73,   73,   99,    0,  100,  101,    0,
    0,    0,   73,    0,   73,   73,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   64,    0,    0,    0,  110,
  111,   65,   66,    0,  113,  114,  115,    0,    0,    0,
   67,   68,  130,  158,  159,   69,   70,    0,   71,   72,
    0,  137,    0,    0,    0,  139,  140,  141,  142,  143,
  144,  145,  146,  147,  148,  149,   64,    0,  152,    0,
    0,    0,   65,   66,    0,    0,    0,   64,    0,    0,
    0,   67,   68,   65,   66,    0,   69,   70,  160,   71,
   72,    0,   67,   68,    0,  163,  166,   69,   70,   64,
   71,   72,    0,    0,    0,   65,   66,    0,    0,    0,
    0,    0,    0,    0,   67,   68,    0,    0,    0,  129,
   70,    0,   71,   72,
};
static const YYINT yycheck[] = {                         41,
   70,   73,   91,   40,   40,   93,   36,  282,   41,  262,
   41,   93,  257,  123,  265,  266,  267,  268,  269,   49,
  284,  285,  267,   41,  283,  284,  285,  278,  279,   41,
  102,  265,  266,  267,  268,  269,   40,  107,  289,  290,
  291,  292,  293,  294,  265,  266,  267,  268,  269,  287,
  288,   93,  257,  274,  257,   91,  282,  127,  128,   41,
  284,  285,  134,  283,  284,  285,   40,  258,  289,  290,
  291,  292,  293,  294,   41,   93,  287,  288,  150,  151,
   41,   93,   41,  260,  257,  283,  284,  285,  158,  123,
  263,  264,  164,  265,  266,  267,  268,  269,   93,  272,
  273,  287,  288,   41,  277,  278,  278,  280,  281,  257,
  257,   93,  265,  266,  267,  268,  269,  289,  290,  291,
  292,  293,  294,  125,   41,  283,  284,  285,  267,  268,
  269,  287,  260,   91,   93,  287,  289,  290,  291,  292,
  293,  294,  261,  287,  257,   41,  125,  287,  271,  261,
  263,  264,  287,    0,  257,   93,  287,  287,  287,  272,
  273,  287,  287,  134,  277,  278,   41,  280,  281,   12,
    7,   35,   38,  286,   56,   54,   93,  265,  266,  267,
  268,  269,  271,  265,  266,  267,  268,  269,  265,  266,
  267,  268,  269,   12,   49,   89,   -1,   93,   -1,   -1,
   -1,  289,  290,  291,  292,  293,  294,  289,  290,  291,
  292,  293,  294,   -1,  291,  292,  293,  294,   93,   -1,
  257,  258,  259,  265,  266,  267,  268,  269,   -1,   -1,
  267,   -1,  274,  270,   -1,   -1,  278,  279,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  287,   -1,  289,  290,  291,
  292,  293,  294,  265,  266,  288,  274,  288,   -1,   -1,
  278,  279,  274,   -1,   -1,   -1,  278,  279,   -1,  287,
   -1,  289,  290,   -1,   -1,  287,   -1,  289,  290,  291,
  292,  293,  294,  265,  266,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,   -1,   -1,   -1,  278,  279,  265,  266,
  267,  268,  269,   -1,   -1,  287,   -1,  289,  290,  291,
  292,  293,  294,   -1,   -1,  274,   -1,   -1,   -1,  278,
  279,   -1,  289,  290,  291,  292,  293,  294,  287,   -1,
  289,  290,  291,  292,  293,  294,  274,   -1,   -1,   -1,
  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  287,
   -1,  289,  290,  291,  292,  293,  294,  274,   -1,   -1,
   -1,  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  287,   -1,  289,  290,  291,  292,  293,  294,  274,   -1,
   -1,   -1,  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  287,   -1,  289,  290,  291,  292,  293,  294,  274,
   -1,   -1,   -1,  278,  279,   66,   -1,   68,   69,   -1,
   -1,   -1,  287,   -1,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,   90,
   91,  263,  264,   -1,   95,   96,   97,   -1,   -1,   -1,
  272,  273,  103,  275,  276,  277,  278,   -1,  280,  281,
   -1,  112,   -1,   -1,   -1,  116,  117,  118,  119,  120,
  121,  122,  123,  124,  125,  126,  257,   -1,  129,   -1,
   -1,   -1,  263,  264,   -1,   -1,   -1,  257,   -1,   -1,
   -1,  272,  273,  263,  264,   -1,  277,  278,  279,  280,
  281,   -1,  272,  273,   -1,  156,  276,  277,  278,  257,
  280,  281,   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  272,  273,   -1,   -1,   -1,  277,
  278,   -1,  280,  281,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 294
#define YYUNDFTOKEN 334
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
"ENDWHILE","BREAK","CONTINUE","DECL","ENDDECL","INT","STR","RETURN","SEMICOLON",
"COMMA","EQ","NEQ","LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"ParamType : INT",
"ParamType : STR",
"Param : ParamType ID",
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
"expr : '(' expr ')'",
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
#line 303 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at statement %d\n", s, statementCount);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yydebug = 0;
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
#line 500 "y.tab.c"

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
#line 52 "ast.y"
	{}
break;
case 2:
#line 53 "ast.y"
	{}
break;
case 3:
#line 54 "ast.y"
	{	
												printf("\n⛔ No Code Provided\n");
												exit(1);
											}
break;
case 4:
#line 62 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 5:
#line 63 "ast.y"
	{}
break;
case 14:
#line 69 "ast.y"
	{ ++statementCount; }
break;
case 15:
#line 72 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 16:
#line 75 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 17:
#line 78 "ast.y"
	{ 
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
											}
break;
case 18:
#line 82 "ast.y"
	{	 
												yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
												yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 19:
#line 91 "ast.y"
	{}
break;
case 20:
#line 94 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, RETURN_NODE, NULL, 0, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 21:
#line 99 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 22:
#line 100 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 23:
#line 103 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 24:
#line 106 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 25:
#line 109 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 26:
#line 112 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 27:
#line 115 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 28:
#line 119 "ast.y"
	{ GSTPrint(); }
break;
case 29:
#line 120 "ast.y"
	{}
break;
case 30:
#line 123 "ast.y"
	{}
break;
case 31:
#line 124 "ast.y"
	{}
break;
case 32:
#line 127 "ast.y"
	{}
break;
case 33:
#line 130 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 34:
#line 131 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 35:
#line 134 "ast.y"
	{}
break;
case 36:
#line 135 "ast.y"
	{}
break;
case 37:
#line 138 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1, NULL); }
break;
case 38:
#line 139 "ast.y"
	{ 
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), yystack.l_mark[-1].node->intConstVal, NULL); 
										}
break;
case 39:
#line 146 "ast.y"
	{ 
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), -1, getParamListHead());
											flushParamList();
											setParamType(TYPE_VOID);
										}
break;
case 40:
#line 151 "ast.y"
	{
											if (getDeclarationType() == TYPE_INT)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1, NULL);

											if (getDeclarationType() == TYPE_STR)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1, NULL);
										}
break;
case 41:
#line 163 "ast.y"
	{}
break;
case 42:
#line 164 "ast.y"
	{}
break;
case 43:
#line 167 "ast.y"
	{ setParamType(TYPE_INT); }
break;
case 44:
#line 168 "ast.y"
	{ setParamType(TYPE_STR); }
break;
case 45:
#line 171 "ast.y"
	{ paramListInstall(getParamType(), yystack.l_mark[0].node->nodeName); }
break;
case 46:
#line 177 "ast.y"
	{}
break;
case 47:
#line 178 "ast.y"
	{}
break;
case 48:
#line 181 "ast.y"
	{ 
															if(GSTLookup(yystack.l_mark[0].node->nodeName) == NULL){
																printf("\nFunction %s is not declared\n", yystack.l_mark[0].node->nodeName);
																exit(1);
															}
															yyval.node = yystack.l_mark[0].node; 
															setCurrentFuncName(yystack.l_mark[0].node->nodeName);
														}
break;
case 49:
#line 192 "ast.y"
	{
															printf("\nFor function %s: \n", getCurrentFuncName());
															printAST(yystack.l_mark[-1].node);
															flushLST();
														}
break;
case 50:
#line 199 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 51:
#line 205 "ast.y"
	{ setFuncType(TYPE_INT); }
break;
case 52:
#line 206 "ast.y"
	{ setFuncType(TYPE_STR); }
break;
case 53:
#line 209 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 54:
#line 218 "ast.y"
	{ LSTPrint(); }
break;
case 55:
#line 219 "ast.y"
	{}
break;
case 56:
#line 222 "ast.y"
	{}
break;
case 57:
#line 223 "ast.y"
	{}
break;
case 58:
#line 226 "ast.y"
	{}
break;
case 59:
#line 229 "ast.y"
	{}
break;
case 60:
#line 230 "ast.y"
	{}
break;
case 61:
#line 233 "ast.y"
	{ LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType()); }
break;
case 62:
#line 243 "ast.y"
	{
														printf("\nFor function %s: \n", getCurrentFuncName());
														printAST(yystack.l_mark[-1].node);	
														/* FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");*/
														/* writeXexeHeader(filePtr);*/
														/* initVariables(filePtr);*/
														/* codeGen($6, filePtr);							*/
														/* INT_10(filePtr);*/
														/* printf("\n");*/
													}
break;
case 63:
#line 255 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 64:
#line 258 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 65:
#line 266 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 66:
#line 267 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 67:
#line 268 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 68:
#line 269 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 69:
#line 270 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 70:
#line 271 "ast.y"
	{ yyval.node = 	TreeCreate(TYPE_INT, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 71:
#line 272 "ast.y"
	{ 
										if (yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);	
			 						}
break;
case 72:
#line 279 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 73:
#line 280 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 74:
#line 281 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 75:
#line 282 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 76:
#line 283 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 77:
#line 284 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 78:
#line 285 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 79:
#line 286 "ast.y"
	{	
										if (yystack.l_mark[-1].node->dataType != TYPE_INT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;	
										yyval.node = yystack.l_mark[-3].node;
									}
break;
case 80:
#line 294 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 81:
#line 298 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 82:
#line 299 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1070 "y.tab.c"
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
