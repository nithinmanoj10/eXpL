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

	FILE *fp = fopen("input_1.txt", "r");
	if(fp)
		yyin = fp;
	else{
		printf("File to be opened doesn't exists\n");
		exit(0);
	}

	yylex();
	return 1;
}
