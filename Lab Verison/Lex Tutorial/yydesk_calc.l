/* Simple Calculator */

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"

	enum yytokentype{
		NUMBER = 258,
		ADD = 259,
		SUB = 260,
		MUL = 261,
		DIV = 262,
		ABS = 263,
		EOL = 264		
	};

	int yylval;
%}

%option noyywrap

plusOperator "+"
minusOperator "-"
multiplyOperator "*"
divideOperator "/"
absoluteOperator "|"
number [0-9]+
newline \n
whitespace [ \t]
others .

%%

{plusOperator} {return ADD;}
{minusOperator} {return SUB;}
{multiplyOperator} {return MUL;}
{divideOperator} {return DIV;}
{absoluteOperator} {return ABS;}
	
{number} {
	yylval = atoi(yytext);
	return NUMBER;
}	
	
{newline} {return EOL;}
{whitespace} {}
{others} {printf("Other Char: %c\n", *yytext);}

%%

