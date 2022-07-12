%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char const *s);

	char result[100];
	char buffer[10];

	#define KRED  "\x1B[31m"
	#define KMAG  "\x1B[35m"
	#define KYEL  "\x1B[33m"
	#define KNRM  "\x1B[0m"
%}

/* Defining the Tokens */

%union
{
	char character;
}

%token CHAR NEWLINE
%left '+' '-'
%left '*' '/'

%type <character> CHAR

%%

start	: expr NEWLINE {
			printf("❱ Postfix Expression: %s\n", result);
			printf("\n\n%s✓ Successfully Completed\n", KMAG);
			exit(1);
};

expr	: expr '+' expr {strcat(result, "+ ");}

	| expr '-' expr {strcat(result, "- ");}

	| expr '*' expr {strcat(result, "* ");}

	| expr '/' expr {strcat(result, "/ ");}

	| '(' expr ')' {}

	| CHAR	{
		sprintf(buffer, "%c ", $1);
		strcat(result, buffer);
}
	;

%%

int main(){

	system("clear");
	printf("%s· Ex.1 Infix to Postfix Calculator%s\n\n", KYEL, KNRM); 

	printf("❱ Enter Infix Expression: ");

	yyparse();
	return 1;
}

void yyerror(char const *s){
	printf("\n%s✘ yyerror: %s\n", KRED, s);
	return;
}
