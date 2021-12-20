%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>

	int lineCount = 0, wordCount = 0, charCount = 0;
%}

Word [a-zA-Z0-9]+
NewLine "\n"

%%

{Word} {++wordCount; charCount += yyleng;}
{NewLine} {++lineCount;}

%%

int main(int argc, char* argv[]){
	if(argc > 1){
		FILE* fp = fopen("input_1.txt", "r");
		if(fp)
			yyin = fp;
	}
	
	yylex();
	printf("\nNumber of Lines: %d\n", lineCount);
	printf("Number of Words: %d\n", wordCount);
	printf("Number of Characters: %d\n", charCount);
	return 1;
}
