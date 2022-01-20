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
    6,    6,    9,   10,   11,   12,   13,   20,   20,   23,
   23,   24,   25,   25,   26,   26,   27,   27,   27,   27,
   28,   28,   30,   30,   29,   19,   19,   18,   21,   21,
    7,   31,   32,   34,   34,   17,   33,   33,   35,   35,
   36,   37,   37,   38,   22,   39,   16,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,
};
static const YYINT yylen[] = {                            2,
    3,    2,    1,    3,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    3,    6,    1,    3,
    7,    5,    5,    5,    1,    1,    1,    3,    2,    2,
    1,    3,    1,    1,    3,    1,    1,    4,    4,    2,
    3,    1,    1,    1,    2,    3,    1,    1,    2,    1,
    1,    5,    5,    1,    1,    5,    3,    2,    2,    1,
    3,    3,    1,    1,    7,    2,    5,    3,    3,    3,
    3,    3,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    4,    4,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   29,   33,   34,    0,   31,    0,    0,
   55,    0,    2,   50,    0,    0,    0,   28,   30,    0,
    0,    0,   36,   66,    1,   49,    0,   51,    0,    0,
    0,    0,   40,   32,    0,    0,    0,    0,    0,    0,
   43,   44,    0,   42,    0,   35,   58,    0,    0,   60,
    0,    0,    0,    0,   38,    0,   39,   45,   64,    0,
   63,   57,   59,    0,    0,    0,   27,    0,    0,    0,
   25,   26,    0,    0,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   52,   53,    0,   41,   61,    0,    0,
    0,    0,   85,   86,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    5,    0,    0,   62,    0,
    0,    0,    0,   74,   73,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    4,    0,    0,   65,    0,    0,    0,   47,
    0,   81,    0,    0,   70,   71,   72,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   20,   56,    0,    0,
   83,    0,   82,    0,   22,   23,   24,    0,    0,   46,
    0,   67,   21,
};
static const YYINT yydgoto[] = {                          2,
   73,   74,   75,   76,   77,   78,   29,  139,   79,   80,
   81,   82,   83,  105,  132,  108,   52,  140,  141,    3,
   12,   13,    7,    8,    9,   22,   23,   43,   44,   45,
   14,   15,   37,   16,   49,   50,   60,   61,   17,
};
static const YYINT yysindex[] = {                      -268,
 -267,    0, -260,    0,    0,    0, -246,    0, -248, -240,
    0, -260,    0,    0,  -92, -209,   10,    0,    0,  -34,
 -206, -259,    0,    0,    0,    0, -223,    0,   34,   37,
 -175, -251,    0,    0, -248, -238, -174, -251,  -36,   -5,
    0,    0,  -31,    0, -168,    0,    0, -161, -229,    0,
  259,  -27,  -30, -223,    0, -251,    0,    0,    0, -226,
    0,    0,    0,  -90,  -38,  -38,    0,  -38,  -38,  259,
    0,    0, -237, -190,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -160,    0,    0, -161,  -38,
  -38,  -33,    0,    0,  -38,  -38,  -38,  148,  148, -152,
 -120,  270,  -38, -184, -157,    0,  259,  -14,    0,  148,
  -89,  -38,  -38,    0,    0,  118,  -38,  -38,  -38,  -38,
  -38,  -38,  -38,  -38,  -38,  -38,  -38,  259,  259,  -38,
  148, -169,    0, -167, -237,    0, -150,  -80,  148,    0,
  -29,    0, -196, -196,    0,    0,    0, -141, -141, -159,
 -159, -159, -159,  204,  226, -199,    0,    0, -142,  -38,
    0,  -38,    0,  259,    0,    0,    0, -158,  148,    0,
  237,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  130,    0,    0,    0,    0,    0,    0, -126,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -211,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -41,    0,    0,    0,    0,    0, -155, -153,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -151,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -144,    0,    0,    0,    0,    0,    0,    0,  -26,    0,
    0,    0,  -11,   19,    0,    0,    0,  -18,   12,   40,
   61,   82,  103,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -132,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -65,  -70,    0,    0,    0,    0,    0,  333,    0,    0,
    0,    0,    0,   21,    0,    0,    0,   -2,    0,    0,
    0,  123,    0,  150,  -28,    0,  126,  124,  107,    0,
  152,    0,  111,    0,    0,  117,    0,   78,    0,
};
#define YYTABLESIZE 551
static const YYINT yytable[] = {                         84,
   91,   97,  104,  137,  102,   32,  113,   48,   20,   57,
   85,  163,  161,    1,   48,    4,    5,    6,   21,   64,
   48,   24,   75,   10,   11,   65,   66,   34,   35,   68,
   27,  104,   41,   42,   67,   68,   18,    5,    6,   69,
   70,  135,   71,   72,   47,    5,    6,   28,  103,   30,
   33,   84,   76,   62,    5,    6,   31,  112,   36,   69,
   88,   89,  154,  155,  104,  117,  118,  119,  120,  121,
  119,  120,  121,   38,   75,   37,   37,   39,  129,  167,
   77,   68,   40,  104,  104,   51,   54,   55,   58,  122,
  123,  124,  125,  126,  127,   59,  106,   84,  171,  107,
  104,   78,  133,  134,   76,  117,  118,  119,  120,  121,
  136,   69,  117,  118,  119,  120,  121,  157,  168,  158,
  160,  128,   79,  117,  118,  119,  120,  121,  172,    3,
   54,   15,   77,   16,   25,   17,  122,  123,  124,  125,
  126,  127,   19,   80,  117,  118,  119,  120,  121,  124,
  125,  126,  127,   78,   18,  159,   19,  129,  142,  170,
   46,   53,   87,   26,   86,   63,  109,    0,  122,  123,
  124,  125,  126,  127,   79,  117,  118,  119,  120,  121,
   90,    0,    0,    0,  117,  118,  119,  120,  121,    0,
    0,    0,    0,    0,    0,   80,    0,    0,    0,  122,
  123,  124,  125,  126,  127,    0,    0,    0,  122,  123,
  124,  125,  126,  127,    0,    0,    0,    0,   92,   93,
   94,    0,    0,   84,   84,   84,   84,   84,   95,    0,
    0,   96,   84,    0,    0,    0,   84,   84,    0,    0,
    0,    0,    0,    0,    0,   84,   84,   84,   84,   84,
   84,   84,   84,   68,   68,   75,   56,   56,  162,   75,
   75,   48,   68,    0,    0,    0,   68,   68,   75,   75,
   75,   75,    0,    0,    0,   68,   68,   68,   68,   68,
   68,   68,   68,   69,   69,   76,    0,    0,    0,   76,
   76,    0,   69,    0,    0,    0,   69,   69,   76,   76,
   76,   76,    0,    0,    0,   69,   69,   69,   69,   69,
   69,   69,   69,   77,    0,    0,    0,   77,   77,    0,
    0,    0,    0,    0,    0,    0,   77,   77,   77,   77,
   77,   77,   77,   77,   78,    0,    0,    0,   78,   78,
    0,    0,    0,    0,    0,    0,    0,   78,   78,   78,
   78,   78,   78,   78,   78,   79,    0,    0,    0,   79,
   79,    0,    0,    0,    0,    0,    0,    0,   79,   79,
   79,   79,   79,   79,   79,   79,   80,    0,    0,    0,
   80,   80,  117,  118,  119,  120,  121,    0,    0,   80,
   80,   80,   80,   80,   80,   80,   80,   98,   99,    0,
  100,  101,    0,    0,    0,    0,  122,  123,  124,  125,
  126,  127,  117,  118,  119,  120,  121,    0,    0,    0,
    0,    0,  110,  111,    0,    0,    0,  114,  115,  116,
    0,    0,    0,    0,    0,  131,  122,  123,  124,  125,
  126,  127,    0,    0,  138,    0,    0,    0,    0,  143,
  144,  145,  146,  147,  148,  149,  150,  151,  152,  153,
   64,    0,  156,    0,    0,    0,   65,   66,    0,    0,
    0,    0,    0,    0,    0,   67,   68,    0,  164,  165,
   69,   70,   64,   71,   72,    0,    0,    0,   65,   66,
    0,    0,  169,   64,    0,    0,    0,   67,   68,   65,
   66,    0,   69,   70,  166,   71,   72,    0,   67,   68,
    0,    0,  173,   69,   70,   64,   71,   72,    0,    0,
    0,   65,   66,    0,    0,    0,   64,    0,    0,    0,
   67,   68,   65,   66,    0,   69,   70,    0,   71,   72,
    0,   67,   68,    0,    0,    0,  130,   70,    0,   71,
   72,
};
static const YYINT yycheck[] = {                         41,
   91,   40,   73,   93,   70,   40,   40,   36,  257,   41,
   41,   41,   93,  282,   41,  283,  284,  285,  267,  257,
   49,  262,   41,  284,  285,  263,  264,  287,  288,   41,
  123,  102,  284,  285,  272,  273,  283,  284,  285,  277,
  278,  107,  280,  281,  283,  284,  285,  257,  286,   40,
  257,   93,   41,  283,  284,  285,   91,   91,  282,   41,
  287,  288,  128,  129,  135,  265,  266,  267,  268,  269,
  267,  268,  269,   40,   93,  287,  288,   41,  278,  279,
   41,   93,  258,  154,  155,  260,  123,   93,  257,  289,
  290,  291,  292,  293,  294,  257,  287,  125,  164,  260,
  171,   41,  287,  261,   93,  265,  266,  267,  268,  269,
  125,   93,  265,  266,  267,  268,  269,  287,  261,  287,
  271,  274,   41,  265,  266,  267,  268,  269,  287,    0,
  257,  287,   93,  287,   12,  287,  289,  290,  291,  292,
  293,  294,  287,   41,  265,  266,  267,  268,  269,  291,
  292,  293,  294,   93,  287,  135,    7,  278,   41,  162,
   35,   38,   56,   12,   54,   49,   89,   -1,  289,  290,
  291,  292,  293,  294,   93,  265,  266,  267,  268,  269,
  271,   -1,   -1,   -1,  265,  266,  267,  268,  269,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,  289,
  290,  291,  292,  293,  294,   -1,   -1,   -1,  289,  290,
  291,  292,  293,  294,   -1,   -1,   -1,   -1,  257,  258,
  259,   -1,   -1,  265,  266,  267,  268,  269,  267,   -1,
   -1,  270,  274,   -1,   -1,   -1,  278,  279,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  287,  288,  289,  290,  291,
  292,  293,  294,  265,  266,  274,  288,  288,  288,  278,
  279,  288,  274,   -1,   -1,   -1,  278,  279,  287,  288,
  289,  290,   -1,   -1,   -1,  287,  288,  289,  290,  291,
  292,  293,  294,  265,  266,  274,   -1,   -1,   -1,  278,
  279,   -1,  274,   -1,   -1,   -1,  278,  279,  287,  288,
  289,  290,   -1,   -1,   -1,  287,  288,  289,  290,  291,
  292,  293,  294,  274,   -1,   -1,   -1,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  287,  288,  289,  290,
  291,  292,  293,  294,  274,   -1,   -1,   -1,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  287,  288,  289,
  290,  291,  292,  293,  294,  274,   -1,   -1,   -1,  278,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  287,  288,
  289,  290,  291,  292,  293,  294,  274,   -1,   -1,   -1,
  278,  279,  265,  266,  267,  268,  269,   -1,   -1,  287,
  288,  289,  290,  291,  292,  293,  294,   65,   66,   -1,
   68,   69,   -1,   -1,   -1,   -1,  289,  290,  291,  292,
  293,  294,  265,  266,  267,  268,  269,   -1,   -1,   -1,
   -1,   -1,   90,   91,   -1,   -1,   -1,   95,   96,   97,
   -1,   -1,   -1,   -1,   -1,  103,  289,  290,  291,  292,
  293,  294,   -1,   -1,  112,   -1,   -1,   -1,   -1,  117,
  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
  257,   -1,  130,   -1,   -1,   -1,  263,  264,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  272,  273,   -1,  275,  276,
  277,  278,  257,  280,  281,   -1,   -1,   -1,  263,  264,
   -1,   -1,  160,  257,   -1,   -1,   -1,  272,  273,  263,
  264,   -1,  277,  278,  279,  280,  281,   -1,  272,  273,
   -1,   -1,  276,  277,  278,  257,  280,  281,   -1,   -1,
   -1,  263,  264,   -1,   -1,   -1,  257,   -1,   -1,   -1,
  272,  273,  263,  264,   -1,  277,  278,   -1,  280,  281,
   -1,  272,  273,   -1,   -1,   -1,  277,  278,   -1,  280,
  281,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 294
#define YYUNDFTOKEN 336
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"ArgList : ArgList COMMA Arg",
"ArgList : Arg",
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
#line 349 "ast.y"

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
#line 517 "y.tab.c"

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
#line 53 "ast.y"
	{}
break;
case 2:
#line 54 "ast.y"
	{}
break;
case 3:
#line 55 "ast.y"
	{	
												printf("\n⛔ No Code Provided\n");
												exit(1);
											}
break;
case 4:
#line 63 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 5:
#line 64 "ast.y"
	{}
break;
case 14:
#line 70 "ast.y"
	{ ++statementCount; }
break;
case 15:
#line 73 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 16:
#line 76 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 17:
#line 79 "ast.y"
	{ 
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
											}
break;
case 18:
#line 83 "ast.y"
	{	 
												yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
												yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 19:
#line 92 "ast.y"
	{}
break;
case 20:
#line 95 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, RETURN_NODE, NULL, 0, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 21:
#line 100 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 22:
#line 101 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 23:
#line 104 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 24:
#line 107 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 25:
#line 110 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 26:
#line 113 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 27:
#line 116 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 28:
#line 120 "ast.y"
	{ 
											GSTPrint();

											int freeStackMem = getFreeStackMemoryValue();
											fprintf(filePtr, "MOV SP, %d\n", freeStackMem - 1);
											fprintf(filePtr, "MOV BP, %d\n", freeStackMem);
											fprintf(filePtr, "PUSH R0\n");
											fprintf(filePtr, "CALL FIM\n");
											fprintf(filePtr, "INT 10\n");
										}
break;
case 29:
#line 130 "ast.y"
	{}
break;
case 30:
#line 133 "ast.y"
	{}
break;
case 31:
#line 134 "ast.y"
	{}
break;
case 32:
#line 137 "ast.y"
	{}
break;
case 33:
#line 140 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 34:
#line 141 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 35:
#line 144 "ast.y"
	{}
break;
case 36:
#line 145 "ast.y"
	{}
break;
case 37:
#line 148 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1, NULL); }
break;
case 38:
#line 149 "ast.y"
	{ 
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), yystack.l_mark[-1].node->intConstVal, NULL); 
										}
break;
case 39:
#line 156 "ast.y"
	{ 
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), -1, getParamListHead());
											flushParamList();
											paramCount = 0;
											setParamType(TYPE_VOID);
										}
break;
case 40:
#line 162 "ast.y"
	{
											if (getDeclarationType() == TYPE_INT)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1, NULL);

											if (getDeclarationType() == TYPE_STR)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1, NULL);
										}
break;
case 41:
#line 174 "ast.y"
	{}
break;
case 42:
#line 175 "ast.y"
	{}
break;
case 43:
#line 178 "ast.y"
	{ setParamType(TYPE_INT); }
break;
case 44:
#line 179 "ast.y"
	{ setParamType(TYPE_STR); }
break;
case 45:
#line 182 "ast.y"
	{ 
											paramListInstall(getParamType(), yystack.l_mark[0].node->nodeName); 
											++paramCount;
										}
break;
case 46:
#line 191 "ast.y"
	{ 
											yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node);
										}
break;
case 47:
#line 194 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 48:
#line 197 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 49:
#line 203 "ast.y"
	{}
break;
case 50:
#line 204 "ast.y"
	{}
break;
case 51:
#line 207 "ast.y"
	{ 
															if(GSTLookup(yystack.l_mark[0].node->nodeName) == NULL){
																printf("\nFunction %s is not declared\n", yystack.l_mark[0].node->nodeName);
																exit(1);
															}
															yyval.node = yystack.l_mark[0].node; 
															setCurrentFuncName(yystack.l_mark[0].node->nodeName);
														}
break;
case 52:
#line 218 "ast.y"
	{
															char* currentFuncName = getCurrentFuncName();
															addFunctionLST(currentFuncName, LSTHead);	
															
															fprintf(filePtr, "F%d:\n", GSTLookup(currentFuncName)->fLabel);
															initFuncCalle(filePtr, paramCount);

															/* TODO: Generate Code for the function		*/
															printAST(yystack.l_mark[-1].node);
															codeGen(yystack.l_mark[-1].node, filePtr);


															LSTPrint();
															flushLST();
															paramCount = 0;
														}
break;
case 53:
#line 236 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 54:
#line 242 "ast.y"
	{ setFuncType(TYPE_INT); }
break;
case 55:
#line 243 "ast.y"
	{ setFuncType(TYPE_STR); }
break;
case 56:
#line 246 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 57:
#line 255 "ast.y"
	{}
break;
case 58:
#line 256 "ast.y"
	{}
break;
case 59:
#line 259 "ast.y"
	{}
break;
case 60:
#line 260 "ast.y"
	{}
break;
case 61:
#line 263 "ast.y"
	{}
break;
case 62:
#line 266 "ast.y"
	{}
break;
case 63:
#line 267 "ast.y"
	{}
break;
case 64:
#line 270 "ast.y"
	{ LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType()); }
break;
case 65:
#line 280 "ast.y"
	{
														addFunctionLST(getCurrentFuncName(), LSTHead);	
														/* printf("\nFor function %s: \n", getCurrentFuncName());*/
														/* printAST($6);	*/
														/* FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");*/
														/* writeXexeHeader(filePtr);*/
														/* initVariables(filePtr);*/
														/* codeGen($6, filePtr);							*/
														/* INT_10(filePtr);*/
														/* printf("\n");*/
														printFLT();
													}
break;
case 66:
#line 294 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 67:
#line 297 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 68:
#line 305 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 69:
#line 306 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 70:
#line 307 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 71:
#line 308 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 72:
#line 309 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 73:
#line 310 "ast.y"
	{ yyval.node = 	TreeCreate(TYPE_INT, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 74:
#line 311 "ast.y"
	{ 
										if (yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);	
			 						}
break;
case 75:
#line 318 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 76:
#line 319 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 77:
#line 320 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 78:
#line 321 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 79:
#line 322 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 80:
#line 323 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 81:
#line 324 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 82:
#line 325 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, 0, NULL, NULL, NULL, NULL); 
										yyval.node->argList = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 83:
#line 332 "ast.y"
	{	
										if (yystack.l_mark[-1].node->dataType != TYPE_INT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;	
										yyval.node = yystack.l_mark[-3].node;
									}
break;
case 84:
#line 340 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 85:
#line 344 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 86:
#line 345 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1137 "y.tab.c"
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
