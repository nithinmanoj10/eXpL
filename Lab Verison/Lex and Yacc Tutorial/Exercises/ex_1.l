%{
	#include <stdio.h>
	#include "y.tab.h"
%}

operand [a-z]
operators "+"|"-"|"*"|"/"
brackets [()]
newline [\n]
whitespace [ \t]

%%

{operand} {
	yylval.character = *yytext;
	return CHAR;
}

{newline} {
	return NEWLINE;
}

{operators} {
	return *yytext;
}

{brackets} {
	return *yytext;
}

{whitespace} {}

. {}

%%

int yywrap(){
	return 1;
}
