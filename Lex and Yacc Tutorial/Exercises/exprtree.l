%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exprtree.h"
	#include "y.tab.h"

	int number;
%}

%%

[0-9]+	{
		number = atoi(yytext);
		yylval.node = makeLeafNode(number);
		return NUM;
	}

"+"	{	return PLUS;}
"-"	{	return MINUS;}
"*"	{	return MUL;}
"/"	{	return DIV;}

[()]	{	return *yytext;}

[\n]	{	return END;}
[ \t]	{}

.	{
		printf("\nError: Unknown Character\n");
		exit(1);
	}

%%

int yywrap(void){
	return 1;
}
