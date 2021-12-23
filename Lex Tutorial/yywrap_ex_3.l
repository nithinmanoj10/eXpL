%{
	#include <stdio.h>
	#include <stdlib.h>
	int consoleInputIsOver = 0;
%}

number [0-9]+

%%

{number} {printf("Number: %d", atoi(yytext));}

%%

int yywrap(){

	if(!consoleInputIsOver){
		consoleInputIsOver = 1;
		yyin = stdin;
		return 0;
	}

	return 1;

}

int main(){
	yylex();
	return 1;
}
