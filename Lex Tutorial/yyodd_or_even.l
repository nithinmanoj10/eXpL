/* LEX Program to check if a number is odd or even */

%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	int num;
%}

number [0-9]+

%%

{number} {

	num = atoi(yytext);
	if(num % 2 == 0)
		printf("Number %d is even", num);
	else
		printf("Number %d is odd", num);

}

%%

int main(int argc, char* argv[]){

	if(argc > 1){
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	else{
		printf("Please provide an input file\n");
		printf("<./a.out> <input file>\n");
		exit(0);
	}

	yylex();
	return 1;
}
