%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	#include "ast.h"

	int yywrap();
%}

%%

"begin" {return BEGIN_;}		/* Keywords */
"end" 	{return END;}

"read" 	{return READ;}		/* Functions */
"write" {return WRITE;}

[a-z]	{			/* Variables and Numbers */
		yylval.node = createASTNode(0, 2, yytext, NULL, NULL);
		return VARIABLE;
	}
[0-9]+	{
		yylval.node = createASTNode(atoi(yytext), 1, "N", NULL, NULL);
		return NUM;
	}

"+"	{return PLUS;}		/* Operators */
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"="	{return EQUAL;}

[()]	{return *yytext;}	/* Others */
[ \t]	{}
[\n]	{}
";"	{}
.	{
		printf("Unknown Character\n");
		exit(1);
	}

%%

int yywrap(){
	return 1;
}
