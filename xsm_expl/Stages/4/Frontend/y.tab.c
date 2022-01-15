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
#define EQUAL 269
#define BREAKPOINT 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ENDIF 274
#define WHILE 275
#define DO 276
#define ENDWHILE 277
#define BREAK 278
#define CONTINUE 279
#define DECL 280
#define ENDDECL 281
#define INT 282
#define STR 283
#define SEMICOLON 284
#define COMMA 285
#define EQ 286
#define NEQ 287
#define LT 288
#define LTE 289
#define GT 290
#define GTE 291
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    3,    4,    5,    5,    6,    6,    8,
    9,   10,   11,   12,   13,   13,   14,   14,   15,   16,
   16,   17,   17,   18,   18,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,
};
static const YYINT yylen[] = {                            2,
    5,    3,    3,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    2,    3,    6,    7,    5,    5,
    5,    1,    1,    1,    3,    2,    2,    1,    3,    1,
    1,    3,    1,    1,    4,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    4,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,   26,   30,   31,    0,   28,
    0,    0,    2,   25,   27,    0,    0,   33,    0,    0,
    0,   24,    0,    0,    0,   22,   23,    0,    0,    5,
    6,    7,    8,    9,   10,   11,   12,   13,    0,   29,
    0,    0,    0,    0,   50,   51,    0,    0,    0,    0,
    0,    0,    0,    0,    4,    0,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    3,   35,    0,    0,
   47,    0,    0,   38,   39,   40,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   48,    0,   19,   20,
   21,    0,    0,   18,
};
static const YYINT yydgoto[] = {                          3,
   28,   29,   30,   31,   32,   33,   48,   34,   35,   36,
   37,   38,    4,    9,   10,   11,   17,   18,
};
static const YYINT yysindex[] = {                      -251,
 -255, -278,    0, -209, -265,    0,    0,    0, -240,    0,
 -204,  203,    0,    0,    0,  -37, -268,    0,  -84,  -39,
  -39,    0,  -39,  -39,  203,    0,    0,  153, -229,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -200,    0,
 -204,  -39,  -39,  -20,    0,    0,  -39,  131,  131, -177,
 -145,  213, -211, -207,    0,  -14,    0,  131,  -91,  -39,
   29,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
  -39,  -39,  203,  203,  -39,    0,    0,    0, -186,  -85,
    0, -236, -236,    0,    0,    0, -164, -164, -253, -253,
 -253, -253, -110,  173, -241,  -39,    0,  203,    0,    0,
    0,  131,  183,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -247,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -41,    0,    0,    0, -198, -192,    0,
    0,    0,    0,    0,    0,    0,    0, -190,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -13,   15,    0,    0,    0,  -19,  117,   37,   57,
   77,   97,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -188,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    8,  -18,    0,    0,    0,    0,   -3,    0,    0,    0,
    0,    0,    0,    0,   75,    0,    0,   56,
};
#define YYTABLESIZE 492
static const YYINT yytable[] = {                         49,
   47,   79,    6,    7,    8,    5,   43,   97,    1,   54,
   62,   63,   64,   65,   66,   40,   41,   49,   13,   50,
   51,   41,   62,   63,   64,   65,   66,   36,    2,   64,
   65,   66,   52,   54,   74,  101,   34,   34,   58,   59,
   14,    7,    8,   61,   67,   68,   69,   70,   71,   72,
   12,   49,   16,   39,   55,   37,   80,   56,   82,   83,
   84,   85,   86,   87,   88,   89,   90,   91,   92,   81,
   60,   95,   76,   41,   54,   54,   77,   43,   78,   36,
   93,   94,   96,   15,   54,   14,   62,   63,   64,   65,
   66,   15,  102,   16,   73,   17,   57,   44,    0,   62,
   63,   64,   65,   66,    0,  103,    0,   37,   67,   68,
   69,   70,   71,   72,    0,    0,    0,   45,   62,   63,
   64,   65,   66,   69,   70,   71,   72,    0,    0,   43,
   74,    0,    0,    0,    0,    0,    0,   46,    0,    0,
   67,   68,   69,   70,   71,   72,   19,    0,    0,   44,
    0,   20,   21,    0,    0,    0,    0,   42,    0,   22,
   23,    0,   98,   99,   24,   25,    0,   26,   27,   45,
    0,    0,   62,   63,   64,   65,   66,    0,   62,   63,
   64,   65,   66,    0,   42,    0,    0,    0,    0,   46,
    0,    0,    0,    0,   67,   68,   69,   70,   71,   72,
   67,   68,   69,   70,   71,   72,    0,    0,    0,   42,
    0,    0,    0,    0,    0,    0,    0,   44,   45,   46,
    0,    0,   49,   49,   49,   49,   49,    0,    0,    0,
   49,    0,    0,    0,   49,   49,    0,    0,    0,    0,
    0,    0,   49,    0,   49,   49,   49,   49,   49,   49,
   36,   36,   41,    0,    0,    0,   41,   41,   36,    0,
    0,    0,   36,   36,   41,    0,   41,   41,    0,    0,
   36,    0,   36,   36,   36,   36,   36,   36,   37,   37,
    0,    0,    0,    0,    0,    0,   37,    0,    0,    0,
   37,   37,   62,   63,   64,   65,   66,    0,   37,    0,
   37,   37,   37,   37,   37,   37,    0,    0,   43,    0,
    0,    0,   43,   43,   67,   68,   69,   70,   71,   72,
   43,    0,   43,   43,   43,   43,   43,   43,   44,    0,
    0,    0,   44,   44,    0,    0,    0,    0,    0,    0,
   44,    0,   44,   44,   44,   44,   44,   44,   45,    0,
    0,    0,   45,   45,    0,    0,    0,    0,    0,    0,
   45,    0,   45,   45,   45,   45,   45,   45,   46,    0,
    0,    0,   46,   46,    0,    0,    0,    0,    0,    0,
   46,    0,   46,   46,   46,   46,   46,   46,   42,    0,
    0,    0,   42,   42,   62,   63,   64,   65,   66,    0,
   42,    0,   42,   42,    0,    0,    0,    0,    0,   19,
    0,    0,    0,   53,   20,   21,   67,   68,   69,   70,
   71,   72,   22,   23,    0,    0,    0,   24,   25,   19,
   26,   27,    0,    0,   20,   21,    0,    0,    0,   19,
    0,    0,   22,   23,   20,   21,    0,   24,   25,  100,
   26,   27,   22,   23,    0,    0,  104,   24,   25,   19,
   26,   27,    0,    0,   20,   21,    0,    0,    0,   19,
    0,    0,   22,   23,   20,   21,    0,   24,   25,    0,
   26,   27,   22,   23,    0,    0,    0,   75,   25,    0,
   26,   27,
};
static const YYINT yycheck[] = {                         41,
   40,   93,  281,  282,  283,  261,   91,   93,  260,   28,
  264,  265,  266,  267,  268,  284,  285,   21,  284,   23,
   24,   41,  264,  265,  266,  267,  268,   41,  280,  266,
  267,  268,   25,   52,  276,  277,  284,  285,   42,   43,
  281,  282,  283,   47,  286,  287,  288,  289,  290,  291,
  260,   93,  257,   91,  284,   41,   60,  258,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   41,
   91,   75,  284,   93,   93,   94,  284,   41,   93,   93,
   73,   74,  269,    9,  103,  284,  264,  265,  266,  267,
  268,  284,   96,  284,  272,  284,   41,   41,   -1,  264,
  265,  266,  267,  268,   -1,   98,   -1,   93,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   41,  264,  265,
  266,  267,  268,  288,  289,  290,  291,   -1,   -1,   93,
  276,   -1,   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,
  286,  287,  288,  289,  290,  291,  257,   -1,   -1,   93,
   -1,  262,  263,   -1,   -1,   -1,   -1,   41,   -1,  270,
  271,   -1,  273,  274,  275,  276,   -1,  278,  279,   93,
   -1,   -1,  264,  265,  266,  267,  268,   -1,  264,  265,
  266,  267,  268,   -1,  269,   -1,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,  286,  287,  288,  289,  290,  291,
  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
   -1,   -1,  264,  265,  266,  267,  268,   -1,   -1,   -1,
  272,   -1,   -1,   -1,  276,  277,   -1,   -1,   -1,   -1,
   -1,   -1,  284,   -1,  286,  287,  288,  289,  290,  291,
  264,  265,  272,   -1,   -1,   -1,  276,  277,  272,   -1,
   -1,   -1,  276,  277,  284,   -1,  286,  287,   -1,   -1,
  284,   -1,  286,  287,  288,  289,  290,  291,  264,  265,
   -1,   -1,   -1,   -1,   -1,   -1,  272,   -1,   -1,   -1,
  276,  277,  264,  265,  266,  267,  268,   -1,  284,   -1,
  286,  287,  288,  289,  290,  291,   -1,   -1,  272,   -1,
   -1,   -1,  276,  277,  286,  287,  288,  289,  290,  291,
  284,   -1,  286,  287,  288,  289,  290,  291,  272,   -1,
   -1,   -1,  276,  277,   -1,   -1,   -1,   -1,   -1,   -1,
  284,   -1,  286,  287,  288,  289,  290,  291,  272,   -1,
   -1,   -1,  276,  277,   -1,   -1,   -1,   -1,   -1,   -1,
  284,   -1,  286,  287,  288,  289,  290,  291,  272,   -1,
   -1,   -1,  276,  277,   -1,   -1,   -1,   -1,   -1,   -1,
  284,   -1,  286,  287,  288,  289,  290,  291,  272,   -1,
   -1,   -1,  276,  277,  264,  265,  266,  267,  268,   -1,
  284,   -1,  286,  287,   -1,   -1,   -1,   -1,   -1,  257,
   -1,   -1,   -1,  261,  262,  263,  286,  287,  288,  289,
  290,  291,  270,  271,   -1,   -1,   -1,  275,  276,  257,
  278,  279,   -1,   -1,  262,  263,   -1,   -1,   -1,  257,
   -1,   -1,  270,  271,  262,  263,   -1,  275,  276,  277,
  278,  279,  270,  271,   -1,   -1,  274,  275,  276,  257,
  278,  279,   -1,   -1,  262,  263,   -1,   -1,   -1,  257,
   -1,   -1,  270,  271,  262,  263,   -1,  275,  276,   -1,
  278,  279,  270,  271,   -1,   -1,   -1,  275,  276,   -1,
  278,  279,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 291
#define YYUNDFTOKEN 312
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
"STRING","BEGIN_","END","READ","WRITE","PLUS","MINUS","MUL","DIV","MOD","EQUAL",
"BREAKPOINT","IF","THEN","ELSE","ENDIF","WHILE","DO","ENDWHILE","BREAK",
"CONTINUE","DECL","ENDDECL","INT","STR","SEMICOLON","COMMA","EQ","NEQ","LT",
"LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
#line 152 "ast.y"

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
#line 428 "y.tab.c"

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
#line 45 "ast.y"
	{
											FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");
											writeXexeHeader(filePtr);
											initVariables(filePtr);
											codeGen(yystack.l_mark[-2].node, filePtr);							
											INT_10(filePtr);
											/*printf("\n");*/
											/* printAST($3);*/
										}
break;
case 2:
#line 55 "ast.y"
	{	
										printf("\n⛔ No Code Provided\n");
										exit(1);
									}
break;
case 3:
#line 60 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 4:
#line 61 "ast.y"
	{}
break;
case 13:
#line 67 "ast.y"
	{ ++statementCount; }
break;
case 14:
#line 70 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 15:
#line 73 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 16:
#line 76 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 17:
#line 77 "ast.y"
	{	 
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 18:
#line 83 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 19:
#line 84 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 20:
#line 87 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 21:
#line 90 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 22:
#line 93 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 23:
#line 96 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 24:
#line 99 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 25:
#line 102 "ast.y"
	{ /* GSTPrint(); */}
break;
case 26:
#line 103 "ast.y"
	{}
break;
case 27:
#line 106 "ast.y"
	{}
break;
case 28:
#line 107 "ast.y"
	{}
break;
case 29:
#line 110 "ast.y"
	{}
break;
case 30:
#line 113 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 31:
#line 114 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 32:
#line 117 "ast.y"
	{}
break;
case 33:
#line 118 "ast.y"
	{}
break;
case 34:
#line 121 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1); }
break;
case 35:
#line 122 "ast.y"
	{ GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), yystack.l_mark[-1].node->intConstVal); }
break;
case 36:
#line 126 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 37:
#line 127 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 38:
#line 128 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 39:
#line 129 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 40:
#line 130 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 41:
#line 131 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 42:
#line 132 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 43:
#line 133 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 44:
#line 134 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 45:
#line 135 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 46:
#line 136 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 47:
#line 137 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 48:
#line 138 "ast.y"
	{	
										if (yystack.l_mark[-1].node->dataType != TYPE_INT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;	
										yyval.node = yystack.l_mark[-3].node;
									}
break;
case 49:
#line 146 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 50:
#line 147 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 51:
#line 148 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 823 "y.tab.c"
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
