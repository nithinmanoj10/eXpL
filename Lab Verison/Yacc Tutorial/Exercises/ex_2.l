%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
%}

letter [a-zA-Z]
number [0-9]+
newline [\n]

%%

{letter} 	{
			return LETTER;
		}

{number} 	{
			return NUMBER;
		}

{newline}	{	return NEWLINE;}

.	 	{	printf("Others: %c\n", *yytext);}

%%

int yywrap(){
	return 1;
}
