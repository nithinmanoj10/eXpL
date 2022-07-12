/* Declarations */

%option noyywrap
%{
	#include <stdio.h>
	#include <stdlib.h>
%}

number [0-9]+

%%

{number} {return atoi(yytext);}

%%

int main()
{
	int num = yylex();
	printf("Found: %d",num);
	return 1;
}
