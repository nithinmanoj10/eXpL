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
	#include "../Data_Structures/TupleListTable.h"
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
#line 31 "ast.y"
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
#line 59 "y.tab.c"

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
#define TUPLE 289
#define RETURN 290
#define SEMICOLON 291
#define COMMA 292
#define DOT 293
#define EQ 294
#define NEQ 295
#define LT 296
#define LTE 297
#define GT 298
#define GTE 299
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    3,    4,    5,    5,    5,   17,
   16,    6,    6,   11,   12,   13,   14,   15,   23,   23,
   26,   26,   27,   28,   28,   29,   29,   30,   30,   30,
   30,   30,   22,   31,   31,   31,   33,   33,   33,   33,
   32,   21,   21,   21,   20,   24,   24,    9,   34,   35,
   37,   37,   37,   37,   19,   36,   36,   38,   38,   39,
   39,   42,   42,   43,   44,   44,    8,   40,   40,   40,
   41,   41,    7,   45,   45,   25,   46,   18,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,
};
static const YYINT yylen[] = {                            2,
    3,    2,    1,    3,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    3,    6,    4,    1,
    3,    7,    5,    5,    5,    1,    1,    1,    3,    2,
    2,    1,    3,    1,    1,    3,    1,    1,    4,    4,
    1,    4,    2,    3,    1,    0,    1,    1,    2,    2,
    2,    3,    1,    0,    1,    2,    1,    1,    5,    5,
    1,    1,    2,    2,    5,    3,    2,    2,    1,    3,
    6,    3,    1,    2,    1,    1,    1,    1,    1,    2,
    3,    1,    1,    1,    2,    7,    2,    5,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    3,    3,    4,    4,    2,    2,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   30,   34,   35,    0,   32,    0,    0,
    0,    0,    2,   57,    0,    0,    0,   29,   31,    0,
    0,    0,    0,   37,   87,   63,   64,    1,   56,    0,
   58,    0,    0,    0,    0,   43,    0,   33,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   45,    0,    0,
   36,   67,   78,   79,    0,    0,   69,    0,    0,    0,
    0,    0,   39,   49,   50,    0,   40,   51,   42,   83,
   80,   66,   68,   84,    0,    0,    0,   82,    0,    0,
    0,    0,   28,    0,    0,    0,   26,   27,    0,    0,
    6,    7,    8,    9,   10,   11,   12,   13,   14,   59,
   60,    0,   44,   85,   75,   76,    0,   73,    0,   70,
    0,    0,    0,    0,  110,  111,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,
    0,    0,    0,    0,   77,   74,   81,    0,    0,    0,
    0,    0,  108,  107,  102,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    4,    0,    0,   86,   72,
    0,    0,    0,    0,   53,    0,  104,  103,    0,    0,
   91,   92,   93,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   21,   65,    0,   71,    0,
  106,    0,  105,    0,   23,   24,   25,    0,    0,   52,
    0,   88,   22,
};
static const YYINT yydgoto[] = {                          2,
   89,   90,   91,   92,   93,   94,   71,  136,   32,  174,
   95,   96,   97,   98,   99,  129,  165,  132,   60,  175,
  176,   22,    3,   12,   13,    7,    8,    9,   23,   24,
   47,   48,   49,   14,   15,   41,   16,   56,   57,   58,
   77,  107,  108,  109,   78,   17,
};
static const YYINT yysindex[] = {                      -279,
 -250,    0, -266,    0,    0,    0, -237,    0, -242, -248,
 -241, -266,    0,    0,  -70, -178,   46,    0,    0,  -35,
 -162,   64, -232,    0,    0,    0,    0,    0,    0, -180,
    0,   74,   75, -140, -219,    0, -219,    0, -242, -246,
 -141, -219,   -3,   28, -135, -133,  -40,    0, -122,  -30,
    0,    0,    0,    0, -121, -222,    0,  -37,  394,   18,
  -29, -180,    0,    0,    0, -219,    0,    0,    0,    0,
    0,    0,    0,    0, -113, -216, -209,    0,  -84,   73,
   73, -112,    0,   73,   73,  394,    0,    0,  312, -145,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -110,    0,    0,    0,    0,  -28,    0, -106,    0,
 -240,   73,   73,  -36,    0,    0, -105, -103,   73,   73,
  233,  233, -124, -157, -104,  406,   73, -138, -102,    0,
  394,   30, -216, -240,    0,    0,    0,  233,  -85,   73,
   73, -101,    0,    0,    0,  155,   73,   73,   73,   73,
   73,   73,   73,   73,   73,   73,   73,   73,   73,   73,
  394,  394,   73,  233, -134,    0, -131,  312,    0,    0,
 -200, -100,  209,  233,    0,  -25,    0,    0, -179, -179,
    0,    0,    0,  269,  -50, -168, -168, -235, -235, -235,
 -235,  233,  331,  353, -221,    0,    0,  -95,    0,   73,
    0,   73,    0,  394,    0,    0,    0, -123,  233,    0,
  372,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  158,    0,    0,    0,    0,    0,    0,  -90,
  -88,    0,    0,    0,    0,    0,    0,    0,    0, -198,
    0, -189,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -21,    0,  -21,    0,    0,    0,
    0,  -21,    0,    0,  -81,  -71,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -41,    0,    0,    0,    0,    0,    0,
 -119, -118,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -92,    0,    0,
  -17,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -91,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -12,    0,    0,    0,    0,   -6,   29,
    0,    0,    0,  181,   92,  -13,   22,   55,   82,  108,
  136,  -89,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -86,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -77,  -87,    0,    0,    0,    0,    0,    0,    0,  399,
    0,    0,    0,    0,    0,    2,    0,    0,    0,  -14,
    0,    0,    0,    0,  177,    0,  196,    0,    0,  165,
  -19,  140,    0,  195,    0,  146,    0,    0,  167,    0,
   87,    0,   98,    0,  123,    0,
};
#define YYTABLESIZE 687
static const YYINT yytable[] = {                        109,
   67,  128,   76,  141,   35,    1,  113,  172,  126,  142,
   69,  101,  134,   25,   20,  203,   74,   50,   26,   46,
   10,   11,   61,   54,   21,   27,   75,   94,   55,  147,
  148,  149,  150,  151,   89,    4,    5,    6,  128,   52,
   53,   54,   55,  147,  148,  149,  150,  151,   18,    5,
    6,  109,   30,  168,  140,   34,  162,  207,   38,   39,
  152,  153,   95,   72,   53,   54,   55,   45,   46,   90,
  105,  106,  154,  155,  156,  157,  158,  159,   31,   94,
  128,  110,  111,  193,  194,   33,   89,  149,  150,  151,
  199,  111,   38,   38,   36,   96,  147,  148,  149,  150,
  151,   41,   41,   37,   40,  128,  128,  147,  148,  149,
  150,  151,  120,   42,   95,   43,  161,   44,   59,   62,
   63,   90,   97,  128,  152,  153,  211,  156,  157,  158,
  159,   64,  101,   65,   68,   70,  154,  155,  156,  157,
  158,  159,  100,  104,  123,  130,  160,   96,   98,  131,
  135,  143,  166,  144,  169,  177,  196,    3,  167,  197,
  147,  148,  149,  150,  151,  208,   61,  212,   62,  198,
  200,   15,   16,  162,   97,   47,   99,  152,  153,  147,
  148,  149,  150,  151,  101,   48,  112,  210,   28,  154,
  155,  156,  157,  158,  159,  178,  152,  153,   17,   20,
   98,   19,   19,   51,   18,  103,   29,  102,  154,  155,
  156,  157,  158,  159,  147,  148,  149,  150,  151,   74,
  171,  100,   73,  109,  109,  109,  109,  109,   99,   75,
  170,  152,  109,  137,    0,    0,  109,  109,    0,    0,
  109,  109,    0,  154,  155,  156,  157,  158,  159,  109,
  109,   66,  109,  109,  109,  109,  109,  109,   89,   89,
   94,   66,   66,  133,   94,   94,  202,   89,   94,   94,
   46,   89,   89,  100,   54,   89,   89,   94,   94,   55,
   94,   94,    0,    0,   89,   89,    0,   89,   89,   89,
   89,   89,   89,   90,   90,   95,    0,    0,    0,   95,
   95,  201,   90,   95,   95,    0,   90,   90,    0,    0,
   90,   90,   95,   95,    0,   95,   95,    0,    0,   90,
   90,    0,   90,   90,   90,   90,   90,   90,   96,  114,
  115,  116,   96,   96,    0,    0,   96,   96,    0,  117,
    0,    0,  118,    0,    0,   96,   96,    0,   96,   96,
   96,   96,   96,   96,    0,   97,  119,    0,    0,   97,
   97,    0,    0,   97,   97,  101,    0,    0,    0,  101,
  101,    0,   97,   97,  101,   97,   97,   97,   97,   97,
   97,   98,  101,  101,    0,   98,   98,    0,    0,   98,
   98,    0,    0,    0,    0,    0,    0,    0,   98,   98,
    0,   98,   98,   98,   98,   98,   98,    0,    0,   99,
    0,    0,    0,   99,   99,    0,    0,   99,   99,  147,
  148,  149,  150,  151,    0,    0,   99,   99,    0,   99,
   99,   99,   99,   99,   99,    0,  152,  153,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  154,  155,
  156,  157,  158,  159,  100,    0,    0,    0,  100,  100,
    0,    0,  100,  100,    0,    0,    0,    0,    0,    0,
    0,  100,  100,  147,  148,  149,  150,  151,  121,  122,
    0,    0,  124,  125,    0,    0,    0,    0,    0,    0,
  152,  153,    0,    0,    0,    0,    0,  147,  148,  149,
  150,  151,  154,  155,  156,  157,  158,  159,    0,    0,
  138,  139,    0,    0,  152,  153,    0,  145,  146,    0,
    0,    0,    0,    0,    0,  164,  154,  155,  156,  157,
  158,  159,    0,  147,  148,  149,  150,  151,  173,    0,
    0,    0,    0,    0,    0,  179,  180,  181,  182,  183,
  184,  185,  186,  187,  188,  189,  190,  191,  192,    0,
    0,  195,  154,  155,  156,  157,  158,  159,   79,    0,
    0,    0,    0,    0,   80,   81,    0,    0,   82,    0,
    0,    0,    0,   83,   84,    0,    0,   79,   85,   86,
    0,   87,   88,   80,   81,    0,    0,   82,  209,    0,
    0,  127,   83,   84,    0,  204,  205,   85,   86,   79,
   87,   88,    0,    0,    0,   80,   81,    0,    0,   82,
    0,    0,    0,    0,   83,   84,    0,    0,   79,   85,
   86,  206,   87,   88,   80,   81,    0,    0,   82,    0,
    0,    0,    0,   83,   84,    0,    0,  213,   85,   86,
   79,   87,   88,    0,    0,    0,   80,   81,    0,    0,
   82,    0,   79,    0,    0,   83,   84,    0,   80,   81,
   85,   86,   82,   87,   88,    0,    0,   83,   84,    0,
    0,    0,  163,   86,    0,   87,   88,
};
static const YYINT yycheck[] = {                         41,
   41,   89,   40,   40,   40,  285,   91,   93,   86,   46,
   41,   41,   41,  262,  257,   41,  257,   37,  267,   41,
  287,  288,   42,   41,  267,  267,  267,   41,   41,  265,
  266,  267,  268,  269,   41,  286,  287,  288,  126,  286,
  287,  288,  289,  265,  266,  267,  268,  269,  286,  287,
  288,   93,  123,  131,   91,   91,  278,  279,  291,  292,
  282,  283,   41,  286,  287,  288,  289,  287,  288,   41,
  287,  288,  294,  295,  296,  297,  298,  299,  257,   93,
  168,  291,  292,  161,  162,   40,   93,  267,  268,  269,
  291,  292,  291,  292,  257,   41,  265,  266,  267,  268,
  269,  291,  292,   40,  285,  193,  194,  265,  266,  267,
  268,  269,   40,   40,   93,   41,  274,  258,  260,  123,
   93,   93,   41,  211,  282,  283,  204,  296,  297,  298,
  299,  267,   41,  267,  257,  257,  294,  295,  296,  297,
  298,  299,  125,  257,  257,  291,  271,   93,   41,  260,
  257,  257,  291,  257,  125,  257,  291,    0,  261,  291,
  265,  266,  267,  268,  269,  261,  257,  291,  257,  168,
  271,  291,  291,  278,   93,  257,   41,  282,  283,  265,
  266,  267,  268,  269,   93,  257,  271,  202,   12,  294,
  295,  296,  297,  298,  299,   41,  282,  283,  291,  291,
   93,  291,    7,   39,  291,   66,   12,   62,  294,  295,
  296,  297,  298,  299,  265,  266,  267,  268,  269,  257,
  134,   41,   56,  265,  266,  267,  268,  269,   93,  267,
  133,  282,  274,  111,   -1,   -1,  278,  279,   -1,   -1,
  282,  283,   -1,  294,  295,  296,  297,  298,  299,  291,
  292,  292,  294,  295,  296,  297,  298,  299,  265,  266,
  274,  292,  292,  292,  278,  279,  292,  274,  282,  283,
  292,  278,  279,   93,  292,  282,  283,  291,  292,  292,
  294,  295,   -1,   -1,  291,  292,   -1,  294,  295,  296,
  297,  298,  299,  265,  266,  274,   -1,   -1,   -1,  278,
  279,   93,  274,  282,  283,   -1,  278,  279,   -1,   -1,
  282,  283,  291,  292,   -1,  294,  295,   -1,   -1,  291,
  292,   -1,  294,  295,  296,  297,  298,  299,  274,  257,
  258,  259,  278,  279,   -1,   -1,  282,  283,   -1,  267,
   -1,   -1,  270,   -1,   -1,  291,  292,   -1,  294,  295,
  296,  297,  298,  299,   -1,  274,  284,   -1,   -1,  278,
  279,   -1,   -1,  282,  283,  274,   -1,   -1,   -1,  278,
  279,   -1,  291,  292,  283,  294,  295,  296,  297,  298,
  299,  274,  291,  292,   -1,  278,  279,   -1,   -1,  282,
  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  291,  292,
   -1,  294,  295,  296,  297,  298,  299,   -1,   -1,  274,
   -1,   -1,   -1,  278,  279,   -1,   -1,  282,  283,  265,
  266,  267,  268,  269,   -1,   -1,  291,  292,   -1,  294,
  295,  296,  297,  298,  299,   -1,  282,  283,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  294,  295,
  296,  297,  298,  299,  274,   -1,   -1,   -1,  278,  279,
   -1,   -1,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  291,  292,  265,  266,  267,  268,  269,   80,   81,
   -1,   -1,   84,   85,   -1,   -1,   -1,   -1,   -1,   -1,
  282,  283,   -1,   -1,   -1,   -1,   -1,  265,  266,  267,
  268,  269,  294,  295,  296,  297,  298,  299,   -1,   -1,
  112,  113,   -1,   -1,  282,  283,   -1,  119,  120,   -1,
   -1,   -1,   -1,   -1,   -1,  127,  294,  295,  296,  297,
  298,  299,   -1,  265,  266,  267,  268,  269,  140,   -1,
   -1,   -1,   -1,   -1,   -1,  147,  148,  149,  150,  151,
  152,  153,  154,  155,  156,  157,  158,  159,  160,   -1,
   -1,  163,  294,  295,  296,  297,  298,  299,  257,   -1,
   -1,   -1,   -1,   -1,  263,  264,   -1,   -1,  267,   -1,
   -1,   -1,   -1,  272,  273,   -1,   -1,  257,  277,  278,
   -1,  280,  281,  263,  264,   -1,   -1,  267,  200,   -1,
   -1,  290,  272,  273,   -1,  275,  276,  277,  278,  257,
  280,  281,   -1,   -1,   -1,  263,  264,   -1,   -1,  267,
   -1,   -1,   -1,   -1,  272,  273,   -1,   -1,  257,  277,
  278,  279,  280,  281,  263,  264,   -1,   -1,  267,   -1,
   -1,   -1,   -1,  272,  273,   -1,   -1,  276,  277,  278,
  257,  280,  281,   -1,   -1,   -1,  263,  264,   -1,   -1,
  267,   -1,  257,   -1,   -1,  272,  273,   -1,  263,  264,
  277,  278,  267,  280,  281,   -1,   -1,  272,  273,   -1,
   -1,   -1,  277,  278,   -1,  280,  281,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 299
#define YYUNDFTOKEN 348
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,0,0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID",
"NUM","STRING","BEGIN_","END","MAIN","READ","WRITE","PLUS","MINUS","MUL","DIV",
"MOD","AMPERSAND","EQUAL","BREAKPOINT","IF","THEN","ELSE","ENDIF","WHILE","DO",
"ENDWHILE","BREAK","CONTINUE","AND","OR","NOT","DECL","ENDDECL","INT","STR",
"TUPLE","RETURN","SEMICOLON","COMMA","DOT","EQ","NEQ","LT","LTE","GT","GTE",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"illegal-symbol",
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
"LDecl : LType '(' TupleFieldList ')' LIDList SEMICOLON",
"TupleFieldList : TupleFieldList COMMA TupleField",
"TupleFieldList : TupleField",
"TupleField : TupleFieldType TupleFieldID",
"TupleFieldType : INT",
"TupleFieldType : STR",
"TupleFieldID : ID",
"LType : INT",
"LType : STR",
"LType : TUPLE TupleID",
"LIDList : LIDList COMMA LID",
"LIDList : LID",
"TupleID : ID",
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
"expr : ID '.' ID",
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
#line 463 "ast.y"

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
#line 595 "y.tab.c"

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
#line 58 "ast.y"
	{}
break;
case 2:
#line 59 "ast.y"
	{}
break;
case 3:
#line 60 "ast.y"
	{	
												printf("\n⛔ No Code Provided\n");
												exit(1);
											}
break;
case 4:
#line 68 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 5:
#line 69 "ast.y"
	{}
break;
case 14:
#line 75 "ast.y"
	{ ++statementCount; }
break;
case 15:
#line 78 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 16:
#line 81 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 17:
#line 84 "ast.y"
	{ 
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
											}
break;
case 18:
#line 88 "ast.y"
	{	 
												yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
												yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
												yyval.node = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
			 								}
break;
case 19:
#line 93 "ast.y"
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
#line 107 "ast.y"
	{}
break;
case 21:
#line 110 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, RETURN_NODE, NULL, 0, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 22:
#line 115 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 23:
#line 116 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 24:
#line 119 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 25:
#line 122 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 26:
#line 125 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 27:
#line 128 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 28:
#line 131 "ast.y"
	{ yyval.node = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
break;
case 29:
#line 135 "ast.y"
	{ 
											/* GSTPrint();*/

											int freeStackMem = getFreeStackMemoryValue();
											fprintf(filePtr, "MOV SP, %d\n", freeStackMem - 1);
											fprintf(filePtr, "MOV BP, %d\n", freeStackMem);
											fprintf(filePtr, "PUSH R0\n");
											fprintf(filePtr, "CALL F0\n");
											fprintf(filePtr, "INT 10\n");
										}
break;
case 30:
#line 145 "ast.y"
	{}
break;
case 31:
#line 148 "ast.y"
	{}
break;
case 32:
#line 149 "ast.y"
	{}
break;
case 33:
#line 152 "ast.y"
	{}
break;
case 34:
#line 155 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 35:
#line 156 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 36:
#line 159 "ast.y"
	{}
break;
case 37:
#line 160 "ast.y"
	{}
break;
case 38:
#line 163 "ast.y"
	{ GSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1, NULL); }
break;
case 39:
#line 164 "ast.y"
	{ 
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), yystack.l_mark[-1].node->intConstVal, NULL); 
										}
break;
case 40:
#line 171 "ast.y"
	{ 
											GSTInstall(yystack.l_mark[-3].node->nodeName, getDeclarationType(), -1, getParamListHead());
											flushParamList();
											paramCount = 0;
											setParamType(TYPE_VOID);
										}
break;
case 41:
#line 177 "ast.y"
	{
											if (getDeclarationType() == TYPE_INT)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1, NULL);

											if (getDeclarationType() == TYPE_STR)
												GSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1, NULL);
										}
break;
case 42:
#line 184 "ast.y"
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
#line 196 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 44:
#line 202 "ast.y"
	{}
break;
case 45:
#line 203 "ast.y"
	{}
break;
case 46:
#line 204 "ast.y"
	{}
break;
case 47:
#line 207 "ast.y"
	{ setParamType(TYPE_INT); }
break;
case 48:
#line 208 "ast.y"
	{ setParamType(TYPE_STR); }
break;
case 49:
#line 209 "ast.y"
	{ setParamType(TYPE_INT_PTR); }
break;
case 50:
#line 210 "ast.y"
	{ setParamType(TYPE_STR_PTR); }
break;
case 51:
#line 213 "ast.y"
	{ 
											paramListInstall(getParamType(), yystack.l_mark[0].node->nodeName); 
											++paramCount;
										}
break;
case 52:
#line 222 "ast.y"
	{ 
											yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node);
										}
break;
case 53:
#line 225 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 54:
#line 226 "ast.y"
	{}
break;
case 55:
#line 229 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node; 
											/* ++argCount;*/
										}
break;
case 56:
#line 238 "ast.y"
	{}
break;
case 57:
#line 239 "ast.y"
	{}
break;
case 58:
#line 242 "ast.y"
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
#line 253 "ast.y"
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
#line 269 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															LSTAddParams();
															flushParamList();
														}
break;
case 61:
#line 275 "ast.y"
	{ setFuncType(TYPE_INT); }
break;
case 62:
#line 276 "ast.y"
	{ setFuncType(TYPE_STR); }
break;
case 63:
#line 277 "ast.y"
	{ setFuncType(TYPE_INT_PTR); }
break;
case 64:
#line 278 "ast.y"
	{ setFuncType(TYPE_STR_PTR); }
break;
case 65:
#line 281 "ast.y"
	{
															struct ASTNode* funcBodyStmt = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
															yyval.node = funcBodyStmt;
														}
break;
case 66:
#line 290 "ast.y"
	{ 
											/* LSTPrint(); */
											/* printTupleList();*/
										}
break;
case 67:
#line 294 "ast.y"
	{}
break;
case 68:
#line 297 "ast.y"
	{}
break;
case 69:
#line 298 "ast.y"
	{}
break;
case 70:
#line 301 "ast.y"
	{}
break;
case 71:
#line 302 "ast.y"
	{ 
																	struct TupleList* currentTupleList = getTuple(getCurrentTupleID());
																	currentTupleList->tupleFieldListHead = tupleFieldListHead;
																	/* printTupleFieldList();*/
																	flushTupleFieldList();
																	/* printTupleTypeTable();*/
																	flushTupleFieldCount();		
																}
break;
case 72:
#line 312 "ast.y"
	{}
break;
case 73:
#line 313 "ast.y"
	{}
break;
case 74:
#line 316 "ast.y"
	{ 
													incTupleFieldCount(); 
													insertTupleField(yystack.l_mark[0].node->nodeName, getTupleFieldType());
												}
break;
case 75:
#line 322 "ast.y"
	{ setTupleFieldType(TYPE_INT); }
break;
case 76:
#line 323 "ast.y"
	{ setTupleFieldType(TYPE_STR); }
break;
case 77:
#line 326 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 78:
#line 329 "ast.y"
	{ setDeclarationType(TYPE_INT); }
break;
case 79:
#line 330 "ast.y"
	{ setDeclarationType(TYPE_STR); }
break;
case 80:
#line 331 "ast.y"
	{ 
											setCurrentTupleID(yystack.l_mark[0].node->nodeName);	
											insertTuple(yystack.l_mark[0].node->nodeName);			
											struct TupleTypeTable* newTTTNode = insertTupleType(yystack.l_mark[0].node->nodeName);
											setDeclarationType(newTTTNode->tupleTypeNum);
							 			}
break;
case 81:
#line 339 "ast.y"
	{}
break;
case 82:
#line 340 "ast.y"
	{}
break;
case 83:
#line 343 "ast.y"
	{ 
											yyval.node = yystack.l_mark[0].node;
										}
break;
case 84:
#line 348 "ast.y"
	{ 
											if (getTupleFieldCount() == 0)		/* For non-tuples*/
												LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), 1); 
											else 								/* For Tuples*/
												LSTInstall(yystack.l_mark[0].node->nodeName, getDeclarationType(), getTupleFieldCount()); 
										}
break;
case 85:
#line 354 "ast.y"
	{
											if(getDeclarationType() == TYPE_INT)
												LSTInstall(yystack.l_mark[0].node->nodeName, TYPE_INT_PTR, 1);	

											if(getDeclarationType() == TYPE_STR)
												LSTInstall(yystack.l_mark[0].node->nodeName, TYPE_STR_PTR, 1);	
										}
break;
case 86:
#line 370 "ast.y"
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
case 87:
#line 387 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 88:
#line 390 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 89:
#line 398 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 90:
#line 399 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 91:
#line 400 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 92:
#line 401 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 93:
#line 402 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 94:
#line 403 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 95:
#line 404 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 96:
#line 405 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 97:
#line 406 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 98:
#line 407 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 99:
#line 408 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 100:
#line 409 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, AND_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 101:
#line 410 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, OR_NODE, NULL, 0, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 102:
#line 411 "ast.y"
	{ yyval.node =  TreeCreate(TYPE_BOOL, NOT_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 103:
#line 412 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 104:
#line 413 "ast.y"
	{ 
										yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
										struct TupleList* TLNode = getTuple(getTupleTypeName(yystack.l_mark[-2].node->dataType));
										struct TupleFieldList* TFLNode = searchTupleField(TLNode->tupleFieldListHead, yystack.l_mark[0].node->nodeName);
										yystack.l_mark[0].node->dataType = TFLNode->tupleFieldType;
										yystack.l_mark[-2].node->left = yystack.l_mark[0].node;
										yystack.l_mark[-2].node->dataType = TFLNode->tupleFieldType;
										yystack.l_mark[-2].node->nodeType = TUPLE_FIELD_NODE;
			 						}
break;
case 105:
#line 422 "ast.y"
	{ 
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
										verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
										yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, 0, NULL, NULL, NULL, NULL); 
										yyval.node->argListHead = yystack.l_mark[-1].node;
										yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
									}
break;
case 106:
#line 429 "ast.y"
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
case 107:
#line 438 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->dataType == TYPE_INT || yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT_PTR, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR || yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR_PTR, AMP_NODE, NULL, 0, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 108:
#line 446 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->dataType == TYPE_INT_PTR)
											yyval.node = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->dataType == TYPE_STR_PTR)
											yyval.node = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 109:
#line 454 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 110:
#line 458 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 111:
#line 459 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1386 "y.tab.c"
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
