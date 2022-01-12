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
	#include "../Data_Structures/declarationsTree.h"
	#include "../Data_Structures/globalSymbolTable.h"
	#include "../Functions/xsm_library.h"
	#include "../Functions/xsm_syscalls.h"
	#include "../Functions/stackMemory.h"
	#include "../Functions/stringMan.h"

	int yylex(void);
	void yyerror(char const *s);
	int lineCount = 0;
	char* fileName;
#line 24 "ast.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct ASTNode* node;
	struct declarationsTree* DTNode;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 54 "y.tab.c"

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

#define VARIABLE 257
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
   16,   17,   17,   17,   17,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,
};
static const YYINT yylen[] = {                            2,
    5,    3,    3,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    2,    3,    6,    7,    5,    5,
    5,    1,    1,    1,    3,    2,    2,    1,    3,    1,
    1,    3,    1,    6,    4,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    4,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,   26,   30,   31,    0,   28,
    0,    0,    2,   25,   27,    0,    0,    0,    0,    0,
   24,    0,    0,    0,   22,   23,    0,    0,    5,    6,
    7,    8,    9,   10,   11,   12,   13,    0,   29,    0,
    0,    0,    0,   50,   51,    0,    0,    0,    0,    0,
    0,    0,    0,    4,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    3,   35,    0,    0,    0,
   47,    0,    0,   38,   39,   40,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   48,    0,   19,
   20,   21,   34,    0,    0,   18,
};
static const YYINT yydgoto[] = {                          3,
   27,   28,   29,   30,   31,   32,   47,   33,   34,   35,
   36,   37,    4,    9,   10,   11,   17,
};
static const YYINT yysindex[] = {                      -257,
 -248, -273,    0, -249, -260,    0,    0,    0, -262,    0,
 -200,  165,    0,    0,    0,  -32, -222,  -89,  -39,  -39,
    0,  -39,  -39,  165,    0,    0,  -67, -216,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -189,    0, -184,
  -39, -183,  -17,    0,    0,  -39, -145, -145, -176, -160,
  175, -208, -207,    0,  -14,  -11, -145,   -9, -173,   29,
  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
  -39,  165,  165,  -39,    0,    0,    0, -172, -187,    1,
    0, -224, -224,    0,    0,    0, -117, -117, -233, -233,
 -233, -233,  -87,  135, -250,    2,  -39,    0,  165,    0,
    0,    0,    0, -145,  145,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -220,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -41,    0,    0,    0, -191, -185,    0,    0,
    0,    0,    0,    0,    0, -218, -182,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -13,   15,    0,    0,    0,  -19,  117,   37,   57,
   77,   97,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -181,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -12,  -22,    0,    0,    0,    0,  -16,    0,    0,    0,
    0,    0,    0,    0,   88,    0,    0,
};
#define YYTABLESIZE 454
static const YYINT yytable[] = {                         49,
   46,   42,    1,   48,   53,   49,   50,    6,    7,    8,
   12,   51,    5,   61,   62,   63,   64,   65,   14,    7,
    8,   41,    2,   13,   57,   73,  102,   36,   53,   60,
   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,
   71,   63,   64,   65,   82,   83,   84,   85,   86,   87,
   88,   89,   90,   91,   92,   37,   16,   95,   38,   93,
   94,   39,   40,   33,   33,   32,   32,   54,   55,   81,
   53,   53,   56,   59,   58,   75,   76,   43,   77,   78,
  104,   97,   53,   79,   80,   96,  105,   61,   62,   63,
   64,   65,   14,   98,  103,   72,   15,   44,   15,    0,
    0,   16,   17,   61,   62,   63,   64,   65,    0,   66,
   67,   68,   69,   70,   71,   73,    0,   45,   61,   62,
   63,   64,   65,    0,    0,   66,   67,   68,   69,   70,
   71,    0,    0,    0,    0,    0,    0,   46,    0,    0,
   66,   67,   68,   69,   70,   71,   61,   62,   63,   64,
   65,    0,    0,    0,    0,    0,    0,   42,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   18,
   68,   69,   70,   71,   19,   20,    0,    0,    0,   41,
    0,    0,   21,   22,    0,   99,  100,   23,   24,   18,
   25,   26,    0,   52,   19,   20,    0,    0,    0,    0,
    0,    0,   21,   22,    0,    0,    0,   23,   24,    0,
   25,   26,    0,    0,    0,    0,    0,   43,   44,   45,
    0,    0,   49,   49,   49,   49,   49,    0,    0,    0,
   49,    0,    0,    0,   49,   49,    0,    0,    0,    0,
    0,    0,   49,    0,   49,   49,   49,   49,   49,   49,
   36,   36,   41,    0,    0,    0,   41,   41,   36,    0,
    0,    0,   36,   36,   41,    0,   41,   41,    0,    0,
   36,    0,   36,   36,   36,   36,   36,   36,   37,   37,
    0,    0,    0,    0,    0,    0,   37,    0,    0,    0,
   37,   37,   61,   62,   63,   64,   65,    0,   37,    0,
   37,   37,   37,   37,   37,   37,    0,    0,   43,    0,
    0,    0,   43,   43,   66,   67,   68,   69,   70,   71,
   43,    0,   43,   43,   43,   43,   43,   43,   44,    0,
    0,    0,   44,   44,    0,    0,    0,    0,    0,    0,
   44,    0,   44,   44,   44,   44,   44,   44,   45,    0,
    0,    0,   45,   45,    0,    0,    0,    0,    0,    0,
   45,    0,   45,   45,   45,   45,   45,   45,   46,    0,
    0,    0,   46,   46,    0,    0,    0,    0,    0,    0,
   46,    0,   46,   46,   46,   46,   46,   46,   42,    0,
    0,   18,   42,   42,    0,    0,   19,   20,    0,    0,
   42,   18,   42,   42,   21,   22,   19,   20,    0,   23,
   24,  101,   25,   26,   21,   22,    0,    0,  106,   23,
   24,   18,   25,   26,    0,    0,   19,   20,    0,    0,
    0,   18,    0,    0,   21,   22,   19,   20,    0,   23,
   24,    0,   25,   26,   21,   22,    0,    0,    0,   74,
   24,    0,   25,   26,
};
static const YYINT yycheck[] = {                         41,
   40,   91,  260,   20,   27,   22,   23,  281,  282,  283,
  260,   24,  261,  264,  265,  266,  267,  268,  281,  282,
  283,   41,  280,  284,   41,  276,  277,   41,   51,   46,
  264,  265,  266,  267,  268,  286,  287,  288,  289,  290,
  291,  266,  267,  268,   61,   62,   63,   64,   65,   66,
   67,   68,   69,   70,   71,   41,  257,   74,   91,   72,
   73,  284,  285,  284,  285,  284,  285,  284,  258,   41,
   93,   94,  257,   91,  258,  284,  284,   41,   93,   91,
   97,  269,  105,   93,  258,  258,   99,  264,  265,  266,
  267,  268,  284,   93,   93,  272,    9,   41,  284,   -1,
   -1,  284,  284,  264,  265,  266,  267,  268,   -1,  286,
  287,  288,  289,  290,  291,  276,   -1,   41,  264,  265,
  266,  267,  268,   -1,   -1,  286,  287,  288,  289,  290,
  291,   -1,   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,
  286,  287,  288,  289,  290,  291,  264,  265,  266,  267,
  268,   -1,   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  288,  289,  290,  291,  262,  263,   -1,   -1,   -1,  269,
   -1,   -1,  270,  271,   -1,  273,  274,  275,  276,  257,
  278,  279,   -1,  261,  262,  263,   -1,   -1,   -1,   -1,
   -1,   -1,  270,  271,   -1,   -1,   -1,  275,  276,   -1,
  278,  279,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
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
   -1,  257,  276,  277,   -1,   -1,  262,  263,   -1,   -1,
  284,  257,  286,  287,  270,  271,  262,  263,   -1,  275,
  276,  277,  278,  279,  270,  271,   -1,   -1,  274,  275,
  276,  257,  278,  279,   -1,   -1,  262,  263,   -1,   -1,
   -1,  257,   -1,   -1,  270,  271,  262,  263,   -1,  275,
  276,   -1,  278,  279,  270,  271,   -1,   -1,   -1,  275,
  276,   -1,  278,  279,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 291
#define YYUNDFTOKEN 311
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"VARIABLE","NUM",
"STRING","BEGIN_","END","READ","WRITE","PLUS","MINUS","MUL","DIV","MOD","EQUAL",
"BREAKPOINT","IF","THEN","ELSE","ENDIF","WHILE","DO","ENDWHILE","BREAK",
"CONTINUE","DECL","ENDDECL","INT","STR","SEMICOLON","COMMA","EQ","NEQ","LT",
"LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : Declarations BEGIN_ Slist END SEMICOLON",
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
"assignStmt : VARIABLE EQUAL expr",
"assignStmt : VARIABLE '[' NUM ']' EQUAL expr",
"ifStmt : IF expr THEN Slist ELSE Slist ENDIF",
"ifStmt : IF expr THEN Slist ENDIF",
"whileStmt : WHILE expr DO Slist ENDWHILE",
"doWhileStmt : DO Slist WHILE expr ENDWHILE",
"breakStmt : BREAK",
"continueStmt : CONTINUE",
"breakPointStmt : BREAKPOINT",
"Declarations : DECL DeclList ENDDECL",
"Declarations : DECL ENDDECL",
"DeclList : DeclList Decl",
"DeclList : Decl",
"Decl : Type VarList SEMICOLON",
"Type : INT",
"Type : STR",
"VarList : VarList COMMA VARIABLE",
"VarList : VARIABLE",
"VarList : VarList COMMA VARIABLE '[' NUM ']'",
"VarList : VARIABLE '[' NUM ']'",
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
"expr : VARIABLE '[' NUM ']'",
"expr : VARIABLE",
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
#line 173 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at line %d\n", s, lineCount+1);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yydebug = 1;
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
#line 421 "y.tab.c"

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
#line 48 "ast.y"
	{

							FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");
							printAST(yystack.l_mark[-2].node);	
							
							printGST();
							
							struct ASTNode* root = yystack.l_mark[-2].node;	
							/* printf("\nGSTHead: %p\n", GSTHead);*/
							writeXexeHeader(filePtr);
							initVariables(filePtr);
							codeGen(yystack.l_mark[-2].node, filePtr);							
							INT_10(filePtr);
	
				}
break;
case 2:
#line 64 "ast.y"
	{	
																		printf("\n⛔ No Code Provided\n");
																		exit(1);
																	}
break;
case 3:
#line 69 "ast.y"
	{yyval.node = createASTNode(0, 1, 6, "C", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node);}
break;
case 4:
#line 70 "ast.y"
	{}
break;
case 13:
#line 75 "ast.y"
	{}
break;
case 14:
#line 78 "ast.y"
	{yyval.node = createASTNode(0, 1, 4, "R", -1, yystack.l_mark[0].node, NULL, NULL); ++lineCount;}
break;
case 15:
#line 81 "ast.y"
	{yyval.node = createASTNode(0, 1, 5, "W", -1, yystack.l_mark[0].node, NULL, NULL); ++lineCount;}
break;
case 16:
#line 84 "ast.y"
	{	yyval.node = createASTNode(0, 1, 3, "=", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); ++lineCount;}
break;
case 17:
#line 85 "ast.y"
	{	 
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yystack.l_mark[-5].node->arrayOffset = yystack.l_mark[-3].node->val;
													yyval.node = createASTNode(0, 1, 3, "=", -1, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
													++lineCount;
			 									}
break;
case 18:
#line 94 "ast.y"
	{
		yyval.node = createASTNode(0, 2, 7, "I", -1, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node);  
		++lineCount;	
	}
break;
case 19:
#line 98 "ast.y"
	{yyval.node = createASTNode(0, 2, 7, "I", -1, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); ++lineCount;}
break;
case 20:
#line 101 "ast.y"
	{yyval.node = createASTNode(0, 2, 7, "W", -1, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); ++lineCount;}
break;
case 21:
#line 104 "ast.y"
	{ yyval.node = createASTNode(0, 2, 7, "DW", -1, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); ++lineCount;}
break;
case 22:
#line 107 "ast.y"
	{ yyval.node = createASTNode(0, 0, 7, "B", -1, NULL, NULL, NULL);}
break;
case 23:
#line 110 "ast.y"
	{ yyval.node = createASTNode(0, 0, 7, "CN", -1, NULL, NULL, NULL);}
break;
case 24:
#line 113 "ast.y"
	{ yyval.node = createASTNode(0, 0, 8, "BR", -1, NULL, NULL, NULL); }
break;
case 25:
#line 116 "ast.y"
	{ 
						 														struct declarationsTree* root = yystack.l_mark[-1].DTNode;
																				createGST(yystack.l_mark[-1].DTNode, 0);				
																				declarationComplete();
																				/* printDeclarationsTree($2);*/
																				/* printGST();*/
																			}
break;
case 26:
#line 123 "ast.y"
	{ declarationComplete(); }
break;
case 27:
#line 126 "ast.y"
	{ 
														yyval.DTNode = createDTNode(3, 0, "c", 0, yystack.l_mark[-1].DTNode, yystack.l_mark[0].DTNode);
				 									}
break;
case 28:
#line 129 "ast.y"
	{ yyval.DTNode = yystack.l_mark[0].DTNode; }
break;
case 29:
#line 132 "ast.y"
	{
																	yystack.l_mark[-2].DTNode->left = yystack.l_mark[-1].DTNode;
																	yyval.DTNode = yystack.l_mark[-2].DTNode;
																}
break;
case 30:
#line 138 "ast.y"
	{ yyval.DTNode = createDTNode(1, 1, "int", 0, NULL, NULL); }
break;
case 31:
#line 139 "ast.y"
	{ yyval.DTNode = createDTNode(1, 2, "str", 0, NULL, NULL); }
break;
case 32:
#line 142 "ast.y"
	{ yyval.DTNode = createDTNode(2, 0, yystack.l_mark[0].node->varname, 1, yystack.l_mark[-2].DTNode, NULL); }
break;
case 33:
#line 143 "ast.y"
	{ yyval.DTNode = createDTNode(2, 0, yystack.l_mark[0].node->varname, 1, NULL, NULL); }
break;
case 34:
#line 144 "ast.y"
	{ yyval.DTNode = createDTNode(2, 0, yystack.l_mark[-3].node->varname, yystack.l_mark[-1].node->val, yystack.l_mark[-5].DTNode, NULL); }
break;
case 35:
#line 145 "ast.y"
	{ yyval.DTNode = createDTNode(2, 0, yystack.l_mark[-3].node->varname, yystack.l_mark[-1].node->val, NULL, NULL); }
break;
case 36:
#line 149 "ast.y"
	{yyval.node = createASTNode(0, 1, 3, "+", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 37:
#line 150 "ast.y"
	{yyval.node = createASTNode(0, 1, 3, "-", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 38:
#line 151 "ast.y"
	{yyval.node = createASTNode(0, 1, 3, "*", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 39:
#line 152 "ast.y"
	{yyval.node = createASTNode(0, 1, 3, "/", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 40:
#line 153 "ast.y"
	{yyval.node = createASTNode(0, 1, 3, "%", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 41:
#line 154 "ast.y"
	{yyval.node = createASTNode(0, 2, 3, "==", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 42:
#line 155 "ast.y"
	{yyval.node = createASTNode(0, 2, 3, "!=", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 43:
#line 156 "ast.y"
	{yyval.node = createASTNode(0, 2, 3, "<", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 44:
#line 157 "ast.y"
	{yyval.node = createASTNode(0, 2, 3, "<=", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 45:
#line 158 "ast.y"
	{yyval.node = createASTNode(0, 2, 3, ">", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 46:
#line 159 "ast.y"
	{yyval.node = createASTNode(0, 2, 3, ">=", -1, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);}
break;
case 47:
#line 160 "ast.y"
	{yyval.node = yystack.l_mark[-1].node;}
break;
case 48:
#line 161 "ast.y"
	{	
										yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;	
										yystack.l_mark[-3].node->arrayOffset = yystack.l_mark[-1].node->val;
										yyval.node = yystack.l_mark[-3].node;
										/* $$ = createASTNode(0, 1, 2, $1->varname, 1, $3, NULL, NULL);*/
									}
break;
case 49:
#line 167 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 50:
#line 168 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 51:
#line 169 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 836 "y.tab.c"
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
