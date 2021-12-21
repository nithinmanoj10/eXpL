%{
	// Lex Program to list out all C-like comments (both single line and multi line comments) from a text file
	
	#include <stdio.h>
	#include <stdlib.h>
%}

%option noyywrap

singleComment [ \t]*\/\/.*
others (.)*

%%
	
{singleComment} {
	printf("\U00002705 %s", yytext);
}

{others} {
	printf("\U0001F539 %s", yytext);
}


%%

int main(){

	printf("\n\U0001F4C0 Stage 0 : LEX Tutorial\n");
	printf("\n\U0001F4D1 Lex Program to list out all C-like comments (both single line and multi line comments) from a text file\n\n");

	FILE* fp = fopen("input_4.txt", "r");
	if(fp)
		yyin = fp;

	yylex();
	return 1;
}
