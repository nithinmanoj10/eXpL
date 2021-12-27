%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	char result[100] = "";
	char buffer[10];

	#define KRED  "\x1B[31m"
	#define KMAG  "\x1B[35m"
	#define KYEL  "\x1B[33m"
	#define KNRM  "\x1B[0m"
%}

%token DIGIT NEWLINE
%left '+' '-'
%left '*' '/'

%%

start	: expr NEWLINE {
			printf("❱ Postfix Expression: %s\n", result);
			printf("❱ Expression Value: %d", $1);
			printf("\n\n%s✓ Successfully Completed\n", KMAG);
			exit(1);
};

expr	: expr '+' expr {
			 strcat(result, "+ ");
			 $$ = $1 + $3;}

	| expr '-' expr {
			 strcat(result, "- ");
			 $$ = $1 - $3;}

	| expr '*' expr {
			 strcat(result, "* ");
			 $$ = $1 * $3;}

	| expr '/' expr {
			 strcat(result, "/ ");
			 $$ = $1 / $3;}

	| '(' expr ')' {}

	| DIGIT	{
		sprintf(buffer, "%d ", $1);
		strcat(result, buffer);
		$$ = $1;
}
	;

%%

int main(){

	system("clear");
	printf("%s· Infix to Postfix Calculator%s\n\n", KYEL, KNRM); 

	printf("❱ Enter Infix Expression: ");

	yyparse();
	return 1;
}

void yyerror(char const *s){
	printf("\n%s✘ yyerror: %s\n", KRED, s);
	return;
}
