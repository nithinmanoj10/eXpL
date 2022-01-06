%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	#include "ast.h"

	int yywrap();
	int line = 0;
%}

%%

"begin" {return BEGIN_;}	/* Keywords */
"end" 	{return END;}

"read" 	{return READ;}		/* Functions */
"write" {return WRITE;}

"if"		{return IF;}		/* Control Flow */
"then"		{return THEN;}
"else"		{return ELSE;}
"endif"		{return ENDIF;}
"while"		{return WHILE;}
"do"		{return DO;}
"endwhile"	{return ENDWHILE;}
"break"		{return BREAK;}
"continue"	{return CONTINUE;}

[a-z]	{			/* Variables and Numbers */
		yylval.node = createASTNode(0, 1, 2, yytext, NULL, NULL, NULL);
		return VARIABLE;
	}
[0-9]+	{
		yylval.node = createASTNode(atoi(yytext), 1, 1, "N", NULL, NULL, NULL);
		return NUM;
	}

"+"	{return PLUS;}		/* Operators */
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"="	{return EQUAL;}
"%"	{return MOD;}

"=="	{return EQ;}		/* Conditional Operators */
"!="	{return NEQ;}
"<"	{return LT;}
">"	{return GT;}
"<="	{return LTE;}
">="	{return GTE;}

[()]	{return *yytext;}	/* Others */
[ \t]	{}
[\n]	{++line;}
":"	{return COLON;}
";"	{return SEMICOLON;}
.	{
		printf("\n❓ Unidentified Token, at line %d\n", line+1);
		exit(1);
	}

[ \t]*\/\/.* {}			/* Comments */

%%

int yywrap(){
	return 1;
}
