%{
	#include <stdio.h>
	#include <stdlib.h>
	int fileIsOpen = 0;
%}

number [0-9]+

%%

{number} {printf("Number: %d", atoi(yytext));}

%%

int yywrap(){
	
	if(!fileIsOpen){
		FILE *fp = fopen("input_1.txt", "r");
		fileIsOpen = 1;
		if(fp){
			yyin = fp;
		}
		else{
			printf("File to be opened doesn't exists\n");
		}
		return 0;
	}
	
	return 1;

}

int main(){
	yylex();
	return 1;
}
