%{
	#include <stdio.h>
	#include <stdlib.h>
	char *file1;
%}

%%

[0-9]+ 	printf("number: %d", atoi(yytext));

%%

int yywrap()
{
  	FILE *newfile_pointer;
  	char *file2="input_2.txt";
  	newfile_pointer = fopen("input_2.txt","r");
  	if(strcmp(file1,file2)!=0)
  	{
  		file1=file2;  
  		yyin = newfile_pointer;
    		return 0;
  	}
  	else
  		return 1;
}

int main()
{
	file1="input_1.txt";
  	yyin = fopen("input_1.txt","r");
  	yylex();
  	return 1;
}
