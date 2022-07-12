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
	#include "../Data_Structures/typeTable.h"
	#include "../Functions/xsm_library.h"
	#include "../Functions/xsm_syscalls.h"
	#include "../Functions/stackMemory.h"
	#include "../Functions/stringMan.h"

	int yylex(void);
	void yyerror(char const *s);
	int statementCount = 0;
	char* fileName;
#line 26 "ast.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct ASTNode* node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 53 "y.tab.c"

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
#define READ 262
#define WRITE 263
#define PLUS 264
#define MINUS 265
#define MUL 266
#define DIV 267
#define MOD 268
#define AMPERSAND 269
#define EQUAL 270
#define BREAKPOINT 271
#define IF 272
#define THEN 273
#define ELSE 274
#define ENDIF 275
#define WHILE 276
#define DO 277
#define ENDWHILE 278
#define BREAK 279
#define CONTINUE 280
#define DECL 281
#define ENDDECL 282
#define INT 283
#define STR 284
#define SEMICOLON 285
#define COMMA 286
#define EQ 287
#define NEQ 288
#define LT 289
#define LTE 290
#define GT 291
#define GTE 292
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    3,    4,    5,    5,    6,    6,    8,
    9,   10,   11,   12,   13,   13,   14,   14,   15,   16,
   16,   17,   17,   18,   18,   18,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,
};
static const YYINT yylen[] = {                            2,
    5,    3,    3,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    2,    3,    6,    7,    5,    5,
    5,    1,    1,    1,    3,    2,    2,    1,    3,    1,
    1,    3,    1,    1,    4,    2,    3,    3,    3,    3,
    3,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    4,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,   26,   30,   31,    0,   28,
    0,    0,    2,   25,   27,    0,    0,    0,   33,    0,
    0,    0,   24,    0,    0,    0,   22,   23,    0,    0,
    5,    6,    7,    8,    9,   10,   11,   12,   13,    0,
   36,   29,    0,    0,    0,    0,   53,   54,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    4,    0,
   32,    0,    0,    0,   43,   42,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    3,   35,    0,    0,   50,    0,    0,   39,
   40,   41,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   51,    0,   19,   20,   21,    0,    0,   18,
};
static const YYINT yydgoto[] = {                          3,
   29,   30,   31,   32,   33,   34,   52,   35,   36,   37,
   38,   39,    4,    9,   10,   11,   18,   19,
};
static const YYINT yysindex[] = {                      -257,
 -250, -275,    0, -255, -271,    0,    0,    0, -256,    0,
 -253,  239,    0,    0,    0,  -81, -235, -251,    0,  -90,
  -28,  -28,    0,  -28,  -28,  239,    0,    0,   55, -260,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -211,
    0,    0, -253,  -28,  -28,  -43,    0,    0,  -28,  -28,
  -28,  164,  164, -130,  150,  250, -234, -232,    0,  -39,
    0,  164,  -78,  -28,    0,    0,   32,  -28,  -28,  -28,
  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  239,  239,
  -28,    0,    0,    0, -213,  -72,    0, -236, -236,    0,
    0,    0, -248, -248, -165, -165, -165, -165,  186,  207,
 -228,  -28,    0,  239,    0,    0,    0,  164,  218,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -240,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -41,    0,    0,    0,    0,
    0, -220, -219,    0,    0,    0,    0,    0,    0,    0,
    0, -218,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -12,   17,    0,
    0,    0,  -18,  135,   52,   72,   92,  112,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -217,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -24,  -23,    0,    0,    0,    0,   47,    0,    0,    0,
    0,    0,    0,    0,   61,    0,    0,   31,
};
#define YYTABLESIZE 530
static const YYINT yytable[] = {                         52,
   45,   56,    1,   16,   12,   58,    6,    7,    8,   40,
    5,   51,   17,   13,   85,   68,   69,   70,   71,   72,
  103,   41,   44,    2,   59,   14,    7,    8,   37,   70,
   71,   72,   58,   42,   43,   68,   69,   70,   71,   72,
   75,   76,   77,   78,   34,   34,   60,   64,   80,  107,
   82,   52,   83,   84,   99,  100,  102,   38,   73,   74,
   75,   76,   77,   78,   14,   15,   16,   17,   53,   15,
   54,   55,   87,   61,   44,   58,   58,    0,    0,  109,
   37,    0,    0,    0,    0,   58,    0,    0,    0,    0,
   62,   63,   46,    0,    0,   65,   66,   67,   68,   69,
   70,   71,   72,    0,    0,    0,    0,    0,    0,   38,
   86,    0,   47,    0,   88,   89,   90,   91,   92,   93,
   94,   95,   96,   97,   98,    0,    0,  101,    0,    0,
    0,    0,   48,   68,   69,   70,   71,   72,    0,    0,
    0,    0,   79,    0,   46,    0,    0,    0,  108,    0,
    0,    0,   49,    0,    0,    0,   73,   74,   75,   76,
   77,   78,    0,    0,   47,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   45,    0,    0,    0,   44,
    0,    0,    0,    0,   48,   68,   69,   70,   71,   72,
    0,   68,   69,   70,   71,   72,    0,    0,    0,    0,
    0,    0,    0,    0,   49,    0,    0,    0,   73,   74,
   75,   76,   77,   78,   73,   74,   75,   76,   77,   78,
    0,    0,   52,   52,   52,   52,   52,   45,   46,   47,
   48,   52,    0,    0,    0,   52,   52,   49,    0,    0,
   50,    0,    0,   52,    0,   52,   52,   52,   52,   52,
   52,   37,   37,    0,   44,    0,    0,    0,   44,   44,
   37,    0,    0,    0,   37,   37,   44,    0,   44,   44,
    0,    0,   37,    0,   37,   37,   37,   37,   37,   37,
   38,   38,    0,    0,    0,    0,    0,    0,    0,   38,
    0,    0,    0,   38,   38,   68,   69,   70,   71,   72,
    0,   38,    0,   38,   38,   38,   38,   38,   38,    0,
    0,   20,    0,    0,    0,   57,   21,   22,   73,   74,
   75,   76,   77,   78,   46,   23,   24,    0,   46,   46,
   25,   26,    0,   27,   28,    0,   46,    0,   46,   46,
   46,   46,   46,   46,   47,    0,    0,    0,   47,   47,
    0,    0,    0,    0,    0,    0,   47,    0,   47,   47,
   47,   47,   47,   47,   48,    0,    0,    0,   48,   48,
    0,    0,    0,    0,    0,    0,   48,    0,   48,   48,
   48,   48,   48,   48,   49,    0,    0,    0,   49,   49,
    0,    0,    0,    0,    0,    0,   49,    0,   49,   49,
   49,   49,   49,   49,    0,    0,    0,   45,    0,    0,
    0,   45,   45,   68,   69,   70,   71,   72,    0,   45,
    0,   45,   45,    0,    0,    0,   80,   68,   69,   70,
   71,   72,    0,    0,    0,    0,   73,   74,   75,   76,
   77,   78,   20,    0,    0,    0,    0,   21,   22,    0,
   73,   74,   75,   76,   77,   78,   23,   24,    0,  104,
  105,   25,   26,   20,   27,   28,    0,    0,   21,   22,
    0,    0,    0,    0,   20,    0,    0,   23,   24,   21,
   22,    0,   25,   26,  106,   27,   28,    0,   23,   24,
    0,    0,  110,   25,   26,   20,   27,   28,    0,    0,
   21,   22,    0,    0,    0,    0,   20,    0,    0,   23,
   24,   21,   22,    0,   25,   26,    0,   27,   28,    0,
   23,   24,    0,    0,    0,   81,   26,    0,   27,   28,
};
static const YYINT yycheck[] = {                         41,
   91,   26,  260,  257,  260,   29,  282,  283,  284,   91,
  261,   40,  266,  285,   93,  264,  265,  266,  267,  268,
   93,  257,   41,  281,  285,  282,  283,  284,   41,  266,
  267,  268,   56,  285,  286,  264,  265,  266,  267,  268,
  289,  290,  291,  292,  285,  286,  258,   91,  277,  278,
  285,   93,  285,   93,   79,   80,  270,   41,  287,  288,
  289,  290,  291,  292,  285,  285,  285,  285,   22,    9,
   24,   25,   41,   43,   93,   99,  100,   -1,   -1,  104,
   93,   -1,   -1,   -1,   -1,  109,   -1,   -1,   -1,   -1,
   44,   45,   41,   -1,   -1,   49,   50,   51,  264,  265,
  266,  267,  268,   -1,   -1,   -1,   -1,   -1,   -1,   93,
   64,   -1,   41,   -1,   68,   69,   70,   71,   72,   73,
   74,   75,   76,   77,   78,   -1,   -1,   81,   -1,   -1,
   -1,   -1,   41,  264,  265,  266,  267,  268,   -1,   -1,
   -1,   -1,  273,   -1,   93,   -1,   -1,   -1,  102,   -1,
   -1,   -1,   41,   -1,   -1,   -1,  287,  288,  289,  290,
  291,  292,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,   -1,  270,
   -1,   -1,   -1,   -1,   93,  264,  265,  266,  267,  268,
   -1,  264,  265,  266,  267,  268,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,  287,  288,
  289,  290,  291,  292,  287,  288,  289,  290,  291,  292,
   -1,   -1,  264,  265,  266,  267,  268,   93,  257,  258,
  259,  273,   -1,   -1,   -1,  277,  278,  266,   -1,   -1,
  269,   -1,   -1,  285,   -1,  287,  288,  289,  290,  291,
  292,  264,  265,   -1,  273,   -1,   -1,   -1,  277,  278,
  273,   -1,   -1,   -1,  277,  278,  285,   -1,  287,  288,
   -1,   -1,  285,   -1,  287,  288,  289,  290,  291,  292,
  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  273,
   -1,   -1,   -1,  277,  278,  264,  265,  266,  267,  268,
   -1,  285,   -1,  287,  288,  289,  290,  291,  292,   -1,
   -1,  257,   -1,   -1,   -1,  261,  262,  263,  287,  288,
  289,  290,  291,  292,  273,  271,  272,   -1,  277,  278,
  276,  277,   -1,  279,  280,   -1,  285,   -1,  287,  288,
  289,  290,  291,  292,  273,   -1,   -1,   -1,  277,  278,
   -1,   -1,   -1,   -1,   -1,   -1,  285,   -1,  287,  288,
  289,  290,  291,  292,  273,   -1,   -1,   -1,  277,  278,
   -1,   -1,   -1,   -1,   -1,   -1,  285,   -1,  287,  288,
  289,  290,  291,  292,  273,   -1,   -1,   -1,  277,  278,
   -1,   -1,   -1,   -1,   -1,   -1,  285,   -1,  287,  288,
  289,  290,  291,  292,   -1,   -1,   -1,  273,   -1,   -1,
   -1,  277,  278,  264,  265,  266,  267,  268,   -1,  285,
   -1,  287,  288,   -1,   -1,   -1,  277,  264,  265,  266,
  267,  268,   -1,   -1,   -1,   -1,  287,  288,  289,  290,
  291,  292,  257,   -1,   -1,   -1,   -1,  262,  263,   -1,
  287,  288,  289,  290,  291,  292,  271,  272,   -1,  274,
  275,  276,  277,  257,  279,  280,   -1,   -1,  262,  263,
   -1,   -1,   -1,   -1,  257,   -1,   -1,  271,  272,  262,
  263,   -1,  276,  277,  278,  279,  280,   -1,  271,  272,
   -1,   -1,  275,  276,  277,  257,  279,  280,   -1,   -1,
  262,  263,   -1,   -1,   -1,   -1,  257,   -1,   -1,  271,
  272,  262,  263,   -1,  276,  277,   -1,  279,  280,   -1,
  271,  272,   -1,   -1,   -1,  276,  277,   -1,  279,  280,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 292
#define YYUNDFTOKEN 313
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","NUM",
"STRING","BEGIN_","END","READ","WRITE","PLUS","MINUS","MUL","DIV","MOD",
"AMPERSAND","EQUAL","BREAKPOINT","IF","THEN","ELSE","ENDIF","WHILE","DO",
"ENDWHILE","BREAK","CONTINUE","DECL","ENDDECL","INT","STR","SEMICOLON","COMMA",
"EQ","NEQ","LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : GDeclBlock BEGIN_ Slist END SEMICOLON",
"start : BEGIN_ END SEMICOLON",
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
"GID : MUL ID",
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
#line 174 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at line %d\n", s, statementCount);
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
#line 439 "y.tab.c"

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
#line 46 "ast.y"
	{
											/* printAST($3);*/
											FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");
											writeXexeHeader(filePtr);
											initVariables(filePtr);
											codeGen(yystack.l_mark[-2].node, filePtr);							
											INT_10(filePtr);
											printf("\n");
										}
break;
case 2:
#line 56 "ast.y"
	{	
										printf("\n⛔ No Code Provided\n");
										exit(1);
									}
break;
case 3:
#line 61 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 4:
#line 62 "ast.y"
	{}
break;
case 13:
#line 68 "ast.y"
	{ ++statementCount; }
break;
case 14:
#line 71 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 15:
#line 74 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 16:
#line 77 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 17:
#line 78 "ast.y"
	{	 
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 18:
#line 84 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 19:
#line 85 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 20:
#line 88 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 21:
#line 91 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 22:
#line 94 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 23:
#line 97 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 24:
#line 100 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 25:
#line 103 "ast.y"
	{ /* GSTPrint(); */ }
break;
case 26:
#line 104 "ast.y"
	{}
break;
case 27:
#line 107 "ast.y"
	{}
break;
case 28:
#line 108 "ast.y"
	{}
break;
case 29:
#line 111 "ast.y"
	{}
break;
case 30:
#line 114 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 31:
#line 115 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 32:
#line 118 "ast.y"
	{}
break;
case 33:
#line 119 "ast.y"
	{}
break;
case 34:
#line 122 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1); }
break;
case 35:
#line 123 "ast.y"
	{ 
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 36:
#line 130 "ast.y"
	{
											if (getDeclarationType() == TYPE_INT)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1);

											if (getDeclarationType() == TYPE_STR)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1);
										}
break;
case 37:
#line 140 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 38:
#line 141 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 39:
#line 142 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 40:
#line 143 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 41:
#line 144 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 42:
#line 145 "ast.y"
	{ yyval.node = 	TreeCreate(TYPE_INT, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 43:
#line 146 "ast.y"
	{ 
										if (yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);	
			 						}
break;
case 44:
#line 153 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 45:
#line 154 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 46:
#line 155 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 47:
#line 156 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 48:
#line 157 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 49:
#line 158 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 50:
#line 159 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 51:
#line 160 "ast.y"
	{	
										if (yystack.l_mark[-1].node->dataType != TYPE_INT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;	
										yyval.node = yystack.l_mark[-3].node;
									}
break;
case 52:
#line 168 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 53:
#line 169 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 54:
#line 170 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 864 "y.tab.c"
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
