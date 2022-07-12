%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
%}

minus "-"
decrement "--"

%%

{minus} {printf("minus ");}
{decrement} {printf("decrement ");}

%%

int main(){
	yylex();
	return 1;
}
