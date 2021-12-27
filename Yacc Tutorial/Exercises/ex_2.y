%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	int yylex(void);
	void yyerror(char const* s);
%}


%token LETTER NUMBER NEWLINE

%%

start 	: LETTER s NEWLINE	{printf("It is a valid variable\n");exit(1);}
	;

s	: LETTER s		{}
	| NUMBER s		{}
	|			{}
	;

%%

int main(){
	yyparse();
	return 1;
}

void yyerror(char const* s){
	printf("Error: %s\n", s);
	exit(1);
}
