%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
%}
	
number [0-9]+
 
%%
 
{number} {
	if(atoi(yytext) % 2 == 0)
		printf("Even Number: %d", atoi(yytext));
	else
		printf("Odd Number: %d", atoi(yytext));
}
 
%%

int main(int argc, char* argv[])
{

	if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}

	yylex();
	return 1;
}
