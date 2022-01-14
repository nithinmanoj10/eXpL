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
#line 26 "ast.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct ASTNode* node;
	/* struct declarationsTree* DTNode;*/
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
#define SEMICOLON 280
#define EQ 281
#define NEQ 282
#define LT 283
#define LTE 284
#define GT 285
#define GTE 286
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    3,    4,    5,    5,    6,    6,    8,
    9,   10,   11,   12,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
};
static const YYINT yylen[] = {                            2,
    4,    3,    3,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    2,    3,    6,    7,    5,    5,
    5,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    4,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,   24,    0,    0,    0,
   22,   23,    0,    0,    5,    6,    7,    8,    9,   10,
   11,   12,   13,    0,    0,    2,    0,   39,   40,    0,
    0,    0,    0,    0,    0,    0,    0,    4,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,    3,    0,    0,
   36,    0,    0,   27,   28,   29,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   37,    0,   19,   20,
   21,    0,    0,   18,
};
static const YYINT yydgoto[] = {                          2,
   13,   14,   15,   16,   17,   18,   31,   19,   20,   21,
   22,   23,
};
static const YYINT yysindex[] = {                      -256,
  158,    0,  -81, -261,  -39,  -39,    0,  -39,  -39,  219,
    0,    0,  169, -258,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -39,  -39,    0,  -60,    0,    0,  -39,
  128,  128, -144,  122,  229, -248, -247,    0,  128,  -91,
  -39,   28,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
  -39,  -39,  -39,  219,  219,  -39,    0,    0, -234,  -82,
    0, -238, -238,    0,    0,    0, -259, -259, -251, -251,
 -251, -251, -114,  189, -175,  -39,    0,  219,    0,    0,
    0,  128,  199,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -41,    0,    0,    0,
 -242, -241,    0,    0,    0,    0,    0,    0, -240,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -18,    5,    0,    0,    0,   25,  103,   43,   58,
   73,   88,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -239,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -7,   -1,    0,    0,    0,    0,   12,    0,    0,    0,
    0,    0,
};
#define YYTABLESIZE 508
static const YYINT yytable[] = {                         38,
   30,   59,   35,    1,   43,   44,   45,   46,   47,   25,
   77,   37,   43,   44,   45,   46,   47,   32,   26,   33,
   34,   38,   25,   50,   51,   52,   53,   45,   46,   47,
   41,   57,   58,   37,   76,   39,   40,   14,   15,   16,
   17,   42,    0,    0,    0,   26,   73,   74,    0,    0,
    0,   38,   60,    0,   62,   63,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   30,    0,   75,   61,    0,
   83,   37,   37,    0,   25,    0,    0,    0,    0,    0,
    0,   37,    0,   32,    0,    0,    0,   82,   43,   44,
   45,   46,   47,    0,    0,    0,    0,   26,   33,    0,
   55,   81,    0,    0,    0,   48,   49,   50,   51,   52,
   53,    0,    0,   34,    0,    0,    0,   30,    0,   43,
   44,   45,   46,   47,    0,    0,    0,   54,   35,    0,
    0,    0,    0,    0,    0,   32,   48,   49,   50,   51,
   52,   53,    3,   31,    0,    0,    0,    5,    6,    0,
   33,    0,    0,    0,    0,    7,    8,    0,   78,   79,
    9,   10,    0,   11,   12,   34,    0,    0,    0,    0,
    0,    0,   43,   44,   45,   46,   47,    0,    0,    0,
   35,   43,   44,   45,   46,   47,    0,   24,    0,   48,
   49,   50,   51,   52,   53,   31,    0,    0,   48,   49,
   50,   51,   52,   53,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   27,   28,   29,
    0,    0,   38,   38,   38,   38,   38,    0,    0,    0,
   38,    0,    0,    0,   38,   38,    0,    0,   38,   38,
   38,   38,   38,   38,   38,   25,   25,    0,    0,    0,
    0,    0,    0,   25,    0,    0,    0,   25,   25,    0,
    0,   25,   25,   25,   25,   25,   25,   25,   26,   26,
    0,    0,    0,    0,    0,    0,   26,    0,    0,    0,
   26,   26,    0,    0,   26,   26,   26,   26,   26,   26,
   26,   43,   44,   45,   46,   47,   30,    0,    0,    0,
   30,   30,    0,    0,   30,   30,   30,    0,   48,   49,
   50,   51,   52,   53,   32,    0,    0,    0,   32,   32,
    0,    0,   32,   32,   32,   32,   32,   32,   32,   33,
    0,    0,    0,   33,   33,    0,    0,   33,   33,   33,
   33,   33,   33,   33,   34,    0,    0,    0,   34,   34,
    0,    0,   34,   34,   34,   34,   34,   34,   34,   35,
    0,    0,    0,   35,   35,    0,    0,   35,   35,   35,
   35,   35,   35,   35,   31,    0,    0,    0,   31,   31,
    0,    0,   31,   31,   31,   43,   44,   45,   46,   47,
    0,   43,   44,   45,   46,   47,    0,   55,    0,    0,
    0,    0,   48,   49,   50,   51,   52,   53,   48,   49,
   50,   51,   52,   53,    3,    0,    0,    0,    4,    5,
    6,    0,    0,    0,    0,    3,    0,    7,    8,   36,
    5,    6,    9,   10,    0,   11,   12,    0,    7,    8,
    0,    0,    0,    9,   10,    3,   11,   12,    0,    0,
    5,    6,    0,    0,    0,    3,    0,    0,    7,    8,
    5,    6,    0,    9,   10,   80,   11,   12,    7,    8,
    0,    0,   84,    9,   10,    3,   11,   12,    0,    0,
    5,    6,    0,    0,    0,    3,    0,    0,    7,    8,
    5,    6,    0,    9,   10,    0,   11,   12,    7,    8,
    0,    0,    0,   56,   10,    0,   11,   12,
};
static const YYINT yycheck[] = {                         41,
   40,   93,   10,  260,  264,  265,  266,  267,  268,   91,
   93,   13,  264,  265,  266,  267,  268,    6,  280,    8,
    9,  280,   41,  283,  284,  285,  286,  266,  267,  268,
   91,  280,  280,   35,  269,   24,   25,  280,  280,  280,
  280,   30,   -1,   -1,   -1,   41,   54,   55,   -1,   -1,
   -1,   93,   41,   -1,   43,   44,   45,   46,   47,   48,
   49,   50,   51,   52,   53,   41,   -1,   56,   41,   -1,
   78,   73,   74,   -1,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   83,   -1,   41,   -1,   -1,   -1,   76,  264,  265,
  266,  267,  268,   -1,   -1,   -1,   -1,   93,   41,   -1,
  276,  277,   -1,   -1,   -1,  281,  282,  283,  284,  285,
  286,   -1,   -1,   41,   -1,   -1,   -1,   93,   -1,  264,
  265,  266,  267,  268,   -1,   -1,   -1,  272,   41,   -1,
   -1,   -1,   -1,   -1,   -1,   93,  281,  282,  283,  284,
  285,  286,  257,   41,   -1,   -1,   -1,  262,  263,   -1,
   93,   -1,   -1,   -1,   -1,  270,  271,   -1,  273,  274,
  275,  276,   -1,  278,  279,   93,   -1,   -1,   -1,   -1,
   -1,   -1,  264,  265,  266,  267,  268,   -1,   -1,   -1,
   93,  264,  265,  266,  267,  268,   -1,  269,   -1,  281,
  282,  283,  284,  285,  286,   93,   -1,   -1,  281,  282,
  283,  284,  285,  286,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
   -1,   -1,  264,  265,  266,  267,  268,   -1,   -1,   -1,
  272,   -1,   -1,   -1,  276,  277,   -1,   -1,  280,  281,
  282,  283,  284,  285,  286,  264,  265,   -1,   -1,   -1,
   -1,   -1,   -1,  272,   -1,   -1,   -1,  276,  277,   -1,
   -1,  280,  281,  282,  283,  284,  285,  286,  264,  265,
   -1,   -1,   -1,   -1,   -1,   -1,  272,   -1,   -1,   -1,
  276,  277,   -1,   -1,  280,  281,  282,  283,  284,  285,
  286,  264,  265,  266,  267,  268,  272,   -1,   -1,   -1,
  276,  277,   -1,   -1,  280,  281,  282,   -1,  281,  282,
  283,  284,  285,  286,  272,   -1,   -1,   -1,  276,  277,
   -1,   -1,  280,  281,  282,  283,  284,  285,  286,  272,
   -1,   -1,   -1,  276,  277,   -1,   -1,  280,  281,  282,
  283,  284,  285,  286,  272,   -1,   -1,   -1,  276,  277,
   -1,   -1,  280,  281,  282,  283,  284,  285,  286,  272,
   -1,   -1,   -1,  276,  277,   -1,   -1,  280,  281,  282,
  283,  284,  285,  286,  272,   -1,   -1,   -1,  276,  277,
   -1,   -1,  280,  281,  282,  264,  265,  266,  267,  268,
   -1,  264,  265,  266,  267,  268,   -1,  276,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,  285,  286,  281,  282,
  283,  284,  285,  286,  257,   -1,   -1,   -1,  261,  262,
  263,   -1,   -1,   -1,   -1,  257,   -1,  270,  271,  261,
  262,  263,  275,  276,   -1,  278,  279,   -1,  270,  271,
   -1,   -1,   -1,  275,  276,  257,  278,  279,   -1,   -1,
  262,  263,   -1,   -1,   -1,  257,   -1,   -1,  270,  271,
  262,  263,   -1,  275,  276,  277,  278,  279,  270,  271,
   -1,   -1,  274,  275,  276,  257,  278,  279,   -1,   -1,
  262,  263,   -1,   -1,   -1,  257,   -1,   -1,  270,  271,
  262,  263,   -1,  275,  276,   -1,  278,  279,  270,  271,
   -1,   -1,   -1,  275,  276,   -1,  278,  279,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 286
#define YYUNDFTOKEN 301
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
"CONTINUE","SEMICOLON","EQ","NEQ","LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : BEGIN_ Slist END SEMICOLON",
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
#line 225 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at line %d\n", s, lineCount+1);
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
#line 405 "y.tab.c"

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
#line 49 "ast.y"
	{
														/* printAST($2);*/
														FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");
														/* // printAST($3);	*/
														/* // printGST();*/
														writeXexeHeader(filePtr);
														initVariables(filePtr);
														codeGen(yystack.l_mark[-2].node, filePtr);							
														INT_10(filePtr);
													}
break;
case 2:
#line 60 "ast.y"
	{	
										printf("\n⛔ No Code Provided\n");
										exit(1);
									}
break;
case 3:
#line 65 "ast.y"
	{   /* $$ = createASTNode(0, 1, 6, "C", -1, $1, NULL, $2);*/
									yyval.node = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node);
								}
break;
case 4:
#line 68 "ast.y"
	{}
break;
case 13:
#line 73 "ast.y"
	{}
break;
case 14:
#line 76 "ast.y"
	{	/* 	$$ = createASTNode(0, 1, 4, "R", -1, $2, NULL, NULL); */
									yyval.node = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL);
									++lineCount;
								}
break;
case 15:
#line 82 "ast.y"
	{
									/* $$ = createASTNode(0, 1, 5, "W", -1, $2, NULL, NULL); */
									yyval.node = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL);
									++lineCount;
								}
break;
case 16:
#line 89 "ast.y"
	{
											/* $$ = createASTNode(0, 1, 3, "=", -1, $1, NULL, $3);*/
											yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);
											++lineCount;
										}
break;
case 17:
#line 94 "ast.y"
	{	 
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													/* $$ = createASTNode(0, 1, 3, "=", -1, $1, NULL, $6);*/
													++lineCount;
			 									}
break;
case 18:
#line 102 "ast.y"
	{
		/* $$ = createASTNode(0, 2, 7, "I", -1, $2, $4, $6);  */
		yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node);
		++lineCount;	
	}
break;
case 19:
#line 107 "ast.y"
	{
									/* $$ = createASTNode(0, 2, 7, "I", -1, $2, $4, NULL);*/
									yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL);
									++lineCount;
								}
break;
case 20:
#line 114 "ast.y"
	{
											/* $$ = createASTNode(0, 2, 7, "W", -1, $2, NULL, $4);*/
											yyval.node = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node);	
											++lineCount;
											}
break;
case 21:
#line 121 "ast.y"
	{ 
											 	/* $$ = createASTNode(0, 2, 7, "DW", -1, $2, NULL, $4);*/
												yyval.node = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node);
												++lineCount;
											}
break;
case 22:
#line 128 "ast.y"
	{ 
							/* $$ = createASTNode(0, 0, 7, "B", -1, NULL, NULL, NULL);*/
							yyval.node = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL);
						}
break;
case 23:
#line 134 "ast.y"
	{ 
								/* $$ = createASTNode(0, 0, 7, "CN", -1, NULL, NULL, NULL);*/
								yyval.node = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL);
							}
break;
case 24:
#line 140 "ast.y"
	{ 
									/* $$ = createASTNode(0, 0, 8, "BR", -1, NULL, NULL, NULL);*/
									yyval.node = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL);
								}
break;
case 25:
#line 180 "ast.y"
	{/* $$ = createASTNode(0, 1, 3, "+", -1, $1, NULL, $3);*/
										yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);
									}
break;
case 26:
#line 183 "ast.y"
	{/* $$ = createASTNode(0, 1, 3, "-", -1, $1, NULL, $3);*/
										yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);			
												}
break;
case 27:
#line 186 "ast.y"
	{/* $$ = createASTNode(0, 1, 3, "*", -1, $1, NULL, $3);*/
										yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);			
												}
break;
case 28:
#line 189 "ast.y"
	{/* $$ = createASTNode(0, 1, 3, "/", -1, $1, NULL, $3);*/
										yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);			
												}
break;
case 29:
#line 192 "ast.y"
	{/* $$ = createASTNode(0, 1, 3, "%", -1, $1, NULL, $3);*/
										yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);			
												}
break;
case 30:
#line 195 "ast.y"
	{/* $$ = createASTNode(0, 2, 3, "==", -1, $1, NULL, $3)*/
										yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);			
												;}
break;
case 31:
#line 198 "ast.y"
	{/* $$ = createASTNode(0, 2, 3, "!=", -1, $1, NULL, $3)*/
										yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);			
												;}
break;
case 32:
#line 201 "ast.y"
	{/* $$ = createASTNode(0, 2, 3, "<", -1, $1, NULL, $3);*/
										yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);			
												}
break;
case 33:
#line 204 "ast.y"
	{/* $$ = createASTNode(0, 2, 3, "<=", -1, $1, NULL, $3)*/
										yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);			
												;}
break;
case 34:
#line 207 "ast.y"
	{/* $$ = createASTNode(0, 2, 3, ">", -1, $1, NULL, $3);*/
										yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);			
												}
break;
case 35:
#line 210 "ast.y"
	{/* $$ = createASTNode(0, 2, 3, ">=", -1, $1, NULL, $3)*/
										yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);			
												;}
break;
case 36:
#line 213 "ast.y"
	{yyval.node = yystack.l_mark[-1].node;}
break;
case 37:
#line 214 "ast.y"
	{	
										yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;	
										yyval.node = yystack.l_mark[-3].node;
										/* $$ = createASTNode(0, 1, 2, $1->varname, 1, $3, NULL, NULL);*/
									}
break;
case 38:
#line 219 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 39:
#line 220 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 40:
#line 221 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 815 "y.tab.c"
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
