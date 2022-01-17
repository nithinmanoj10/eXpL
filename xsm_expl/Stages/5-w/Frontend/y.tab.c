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
    6,    6,    9,   10,   11,   12,   13,   16,   16,   19,
   19,   20,   21,   21,   22,   22,   23,   23,   23,   23,
   24,   24,   26,   26,   25,   17,   17,    7,   27,   28,
   28,   30,   29,   29,   31,   31,   32,   33,   33,   34,
   18,   35,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
};
static const YYINT yylen[] = {                            2,
    3,    2,    1,    3,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    3,    6,    1,    3,
    7,    5,    5,    5,    1,    1,    1,    3,    2,    2,
    1,    3,    1,    1,    3,    1,    1,    4,    4,    2,
    3,    1,    1,    1,    2,    2,    1,    1,    9,    1,
    1,    5,    3,    2,    2,    1,    3,    3,    1,    1,
    8,    5,    3,    3,    3,    3,    3,    2,    2,    3,
    3,    3,    3,    3,    3,    3,    4,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   29,   33,   34,    0,   31,    0,    0,
   51,    0,    2,   47,    0,   28,   30,    0,    0,    0,
   36,    0,    1,   46,   48,    0,    0,    0,   40,   32,
    0,    0,    0,    0,   43,   44,    0,   42,    0,   35,
    0,    0,   38,    0,   39,   45,    0,    0,   41,    0,
    0,    0,   54,    0,    0,   56,    0,    0,    0,   60,
    0,   59,   53,   55,    0,    0,    0,   27,    0,    0,
    0,   25,   26,    0,    0,    6,    7,    8,    9,   10,
   11,   12,   13,   14,   61,    0,    0,   57,    0,    0,
    0,    0,   79,   80,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    5,    0,   49,   58,    0,
    0,    0,   69,   68,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    4,    0,    0,    0,    0,   76,    0,    0,   65,
   66,   67,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   20,   62,    0,    0,   77,    0,   22,   23,   24,
   52,    0,    0,   21,
};
static const YYINT yydgoto[] = {                          2,
   74,   75,   76,   77,   78,   79,   26,   98,   80,   81,
   82,   83,   84,  105,  131,    3,   12,   13,    7,    8,
    9,   20,   21,   37,   38,   39,   14,   15,   51,   87,
   55,   56,   61,   62,   58,
};
static const YYINT yysindex[] = {                      -272,
 -249,    0, -270,    0,    0,    0, -244,    0, -250, -239,
    0, -270,    0,    0, -220,    0,    0,  -38, -198, -218,
    0,   11,    0,    0,    0,   39, -184, -213,    0,    0,
 -250,   45, -213,    7,    0,    0,  -32,    0, -156,    0,
  -21,  -30,    0, -213,    0,    0, -179,  -18,    0, -235,
 -154, -179,    0, -150, -229,    0,  242,  -16, -149,    0,
 -210,    0,    0,    0,  -88,  -36,  -36,    0,  -36,  -36,
  242,    0,    0, -112, -177,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  242,   -7,    0, -150,  -36,
  -36,   35,    0,    0,  -36,  -36,  -36, -152, -152, -201,
 -170,  253,  -36, -160, -133,    0, -112,    0,    0, -152,
  -87,  -36,    0,    0,   34,  -36,  -36,  -36,  -36,  -36,
  -36,  -36,  -36,  -36,  -36,  -36,  242,  242,  -36, -152,
 -158,    0, -157, -130, -139,  -81,    0, -206, -206,    0,
    0,    0,  -76,  -76, -240, -240, -240, -240,  168,  209,
 -247,    0,    0, -153,  -36,    0,  242,    0,    0,    0,
    0, -152,  220,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  133,    0,    0,    0,    0,    0,    0, -121,
    0,    0,    0,    0,    0,    0,    0, -203,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -41,    0,    0,    0,    0,    0, -144, -143,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -140,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -138,
    0,    0,    0,    0,    0,    0,    0,  -11,   19,    0,
    0,    0,  -17,  126,   42,   63,   84,  105,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -137,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -70,  -69,    0,    0,    0,    0,    0,  339,    0,    0,
    0,    0,    0,   41,    0,    0,    0,  141,    0,  147,
  -42,    0,  124,  125,  113,    0,  150,    0,  107,    0,
    0,  108,    0,   75,    0,
};
#define YYTABLESIZE 534
static const YYINT yytable[] = {                         78,
  102,   28,   91,   97,  104,  135,   18,   54,   45,    1,
   48,  156,   54,   10,   11,  107,   19,  116,  117,  118,
  119,  120,   22,   70,  116,  117,  118,  119,  120,   63,
  128,  160,  104,    4,    5,    6,   25,  104,   16,    5,
    6,  121,  122,  123,  124,  125,  126,   53,    5,    6,
   32,   78,   27,   63,    5,    6,  149,  150,   29,   64,
  118,  119,  120,  116,  117,  118,  119,  120,   30,   31,
   35,   36,  127,   34,  137,   70,   88,   89,   33,  104,
  104,   63,   72,   37,   37,   41,  163,  121,  122,  123,
  124,  125,  126,  104,  116,  117,  118,  119,  120,   43,
   46,   47,   50,   73,   52,   57,   60,  128,   85,  106,
   86,   64,  116,  117,  118,  119,  120,  108,  121,  122,
  123,  124,  125,  126,   74,  112,  132,  133,  152,  153,
  154,  155,    3,  161,   72,   50,  121,  122,  123,  124,
  125,  126,   15,   16,   65,   75,   17,  134,   19,   18,
   66,   67,   23,   17,   40,   73,   49,   42,   59,   68,
   69,   24,   64,  109,   70,   71,   71,   72,   73,    0,
    0,    0,    0,  103,    0,    0,   74,  116,  117,  118,
  119,  120,   90,  116,  117,  118,  119,  120,  116,  117,
  118,  119,  120,    0,    0,    0,    0,   75,    0,    0,
    0,  121,  122,  123,  124,  125,  126,  121,  122,  123,
  124,  125,  126,    0,  123,  124,  125,  126,   71,    0,
   92,   93,   94,   78,   78,   78,   78,   78,    0,    0,
   95,    0,   78,   96,    0,    0,   78,   78,    0,    0,
    0,    0,    0,    0,    0,   78,    0,   78,   78,   78,
   78,   78,   78,   63,   63,   44,   70,   44,    0,    0,
   70,   70,   63,    0,    0,    0,   63,   63,    0,   70,
    0,   70,   70,    0,    0,   63,    0,   63,   63,   63,
   63,   63,   63,   64,   64,    0,    0,    0,    0,    0,
    0,    0,   64,    0,    0,    0,   64,   64,  116,  117,
  118,  119,  120,    0,    0,   64,    0,   64,   64,   64,
   64,   64,   64,    0,    0,   72,    0,    0,    0,   72,
   72,    0,  121,  122,  123,  124,  125,  126,   72,    0,
   72,   72,   72,   72,   72,   72,   73,    0,    0,    0,
   73,   73,    0,    0,    0,    0,    0,    0,    0,   73,
    0,   73,   73,   73,   73,   73,   73,   74,    0,    0,
    0,   74,   74,    0,    0,    0,    0,    0,    0,    0,
   74,    0,   74,   74,   74,   74,   74,   74,   75,    0,
    0,    0,   75,   75,    0,    0,    0,    0,    0,    0,
    0,   75,    0,   75,   75,   75,   75,   75,   75,   71,
    0,    0,    0,   71,   71,   99,    0,  100,  101,    0,
    0,    0,   71,    0,   71,   71,    0,    0,    0,    0,
    0,    0,    0,    0,   65,    0,    0,    0,  110,  111,
   66,   67,    0,  113,  114,  115,    0,    0,    0,   68,
   69,  130,  157,  158,   70,   71,    0,   72,   73,    0,
  136,    0,    0,    0,  138,  139,  140,  141,  142,  143,
  144,  145,  146,  147,  148,   65,    0,  151,    0,    0,
    0,   66,   67,    0,    0,    0,   65,    0,    0,    0,
   68,   69,   66,   67,    0,   70,   71,  159,   72,   73,
    0,   68,   69,  162,    0,  164,   70,   71,   65,   72,
   73,    0,    0,    0,   66,   67,    0,    0,    0,   65,
    0,    0,    0,   68,   69,   66,   67,    0,   70,   71,
    0,   72,   73,    0,   68,   69,    0,    0,    0,  129,
   71,    0,   72,   73,
};
static const YYINT yycheck[] = {                         41,
   71,   40,   91,   40,   74,   93,  257,   50,   41,  282,
   41,   93,   55,  284,  285,   86,  267,  265,  266,  267,
  268,  269,  262,   41,  265,  266,  267,  268,  269,   41,
  278,  279,  102,  283,  284,  285,  257,  107,  283,  284,
  285,  289,  290,  291,  292,  293,  294,  283,  284,  285,
   40,   93,   91,  283,  284,  285,  127,  128,  257,   41,
  267,  268,  269,  265,  266,  267,  268,  269,  287,  288,
  284,  285,  274,  258,   41,   93,  287,  288,   40,  149,
  150,   93,   41,  287,  288,   41,  157,  289,  290,  291,
  292,  293,  294,  163,  265,  266,  267,  268,  269,   93,
  257,  123,  282,   41,  123,  260,  257,  278,  125,  287,
  260,   93,  265,  266,  267,  268,  269,  125,  289,  290,
  291,  292,  293,  294,   41,   91,  287,  261,  287,  287,
  261,  271,    0,  287,   93,  257,  289,  290,  291,  292,
  293,  294,  287,  287,  257,   41,  287,  107,  287,  287,
  263,  264,   12,    7,   31,   93,   44,   33,   52,  272,
  273,   12,   55,   89,  277,  278,   41,  280,  281,   -1,
   -1,   -1,   -1,  286,   -1,   -1,   93,  265,  266,  267,
  268,  269,  271,  265,  266,  267,  268,  269,  265,  266,
  267,  268,  269,   -1,   -1,   -1,   -1,   93,   -1,   -1,
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
   -1,   -1,   -1,  278,  279,   67,   -1,   69,   70,   -1,
   -1,   -1,  287,   -1,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,   90,   91,
  263,  264,   -1,   95,   96,   97,   -1,   -1,   -1,  272,
  273,  103,  275,  276,  277,  278,   -1,  280,  281,   -1,
  112,   -1,   -1,   -1,  116,  117,  118,  119,  120,  121,
  122,  123,  124,  125,  126,  257,   -1,  129,   -1,   -1,
   -1,  263,  264,   -1,   -1,   -1,  257,   -1,   -1,   -1,
  272,  273,  263,  264,   -1,  277,  278,  279,  280,  281,
   -1,  272,  273,  155,   -1,  276,  277,  278,  257,  280,
  281,   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,  257,
   -1,   -1,   -1,  272,  273,  263,  264,   -1,  277,  278,
   -1,  280,  281,   -1,  272,  273,   -1,   -1,   -1,  277,
  278,   -1,  280,  281,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 294
#define YYUNDFTOKEN 332
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"FDef : FuncType FID '(' ParamList ')' '{' LDeclBlock FBody '}'",
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
"MainBlock : INT MAIN '(' ')' '{' LDeclBlock MBody '}'",
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
#line 277 "ast.y"

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
#line 498 "y.tab.c"

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
	{ yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 18:
#line 79 "ast.y"
	{	 
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 19:
#line 87 "ast.y"
	{}
break;
case 20:
#line 90 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, RETURN_NODE, NULL, 0, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 21:
#line 95 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 22:
#line 96 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 23:
#line 99 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 24:
#line 102 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 25:
#line 105 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 26:
#line 108 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 27:
#line 111 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 28:
#line 115 "ast.y"
	{ GSTPrint(); }
break;
case 29:
#line 116 "ast.y"
	{}
break;
case 30:
#line 119 "ast.y"
	{}
break;
case 31:
#line 120 "ast.y"
	{}
break;
case 32:
#line 123 "ast.y"
	{}
break;
case 33:
#line 126 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 34:
#line 127 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 35:
#line 130 "ast.y"
	{}
break;
case 36:
#line 131 "ast.y"
	{}
break;
case 37:
#line 134 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1, NULL); }
break;
case 38:
#line 135 "ast.y"
	{ 
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), yystack.l_mark[-1].node->intConstVal, NULL); 
										}
break;
case 39:
#line 142 "ast.y"
	{ 
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), -1, getParamListHead());
											flushParamList();
											setParamType(TYPE_VOID);
										}
break;
case 40:
#line 147 "ast.y"
	{
											if (getDeclarationType() == TYPE_INT)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1, NULL);

											if (getDeclarationType() == TYPE_STR)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1, NULL);
										}
break;
case 41:
#line 159 "ast.y"
	{}
break;
case 42:
#line 160 "ast.y"
	{}
break;
case 43:
#line 163 "ast.y"
	{ setParamType(TYPE_INT); }
break;
case 44:
#line 164 "ast.y"
	{ setParamType(TYPE_STR); }
break;
case 45:
#line 167 "ast.y"
	{ paramListInstall(getParamType(), yystack.l_mark[0].node->nodeName); }
break;
case 46:
#line 173 "ast.y"
	{}
break;
case 47:
#line 174 "ast.y"
	{}
break;
case 48:
#line 177 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 49:
#line 181 "ast.y"
	{
															LSTAddParams();
															printf("\nFunction %s: \n", yystack.l_mark[-7].node->nodeName);
															printf("Parameters: ");
															printParamList(getParamListHead());
															LSTPrint();
															printf("\n");
														}
break;
case 50:
#line 191 "ast.y"
	{}
break;
case 51:
#line 192 "ast.y"
	{}
break;
case 52:
#line 195 "ast.y"
	{}
break;
case 53:
#line 201 "ast.y"
	{}
break;
case 54:
#line 202 "ast.y"
	{}
break;
case 55:
#line 205 "ast.y"
	{}
break;
case 56:
#line 206 "ast.y"
	{}
break;
case 57:
#line 209 "ast.y"
	{}
break;
case 58:
#line 212 "ast.y"
	{}
break;
case 59:
#line 213 "ast.y"
	{}
break;
case 60:
#line 216 "ast.y"
	{ LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType()); }
break;
case 61:
#line 226 "ast.y"
	{}
break;
case 62:
#line 229 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														printAST(statementList);
														FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");
														writeXexeHeader(filePtr);
														initVariables(filePtr);
														codeGen(statementList, filePtr);							
														INT_10(filePtr);
														printf("\n");
													}
break;
case 63:
#line 243 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 64:
#line 244 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 65:
#line 245 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 66:
#line 246 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 67:
#line 247 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 68:
#line 248 "ast.y"
	{ yyval.node = 	TreeCreate(TYPE_INT, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 69:
#line 249 "ast.y"
	{ 
										if (yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);	
			 						}
break;
case 70:
#line 256 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 71:
#line 257 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 72:
#line 258 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 73:
#line 259 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 74:
#line 260 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 75:
#line 261 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 76:
#line 262 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 77:
#line 263 "ast.y"
	{	
										if (yystack.l_mark[-1].node->dataType != TYPE_INT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;	
										yyval.node = yystack.l_mark[-3].node;
									}
break;
case 78:
#line 271 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 79:
#line 272 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 80:
#line 273 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1039 "y.tab.c"
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
