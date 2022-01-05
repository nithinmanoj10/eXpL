%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "../Functions/label.h"

	int yywrap();
	int getLabelNumber(char* label);

	int lineNumber = 0;
	int labelNumber = 0;
%}


%%

[L][0-9]+[:][\n]	{
				++lineNumber;

				int labelNum = getLabelNumber(yytext);
				int labelAddress = calcLabelAddress(lineNumber);
				struct labelAddressNode* newNode = createLabelAddressNode(labelNum, labelAddress);

				insertLabelAddressNode(newNode);

				--lineNumber;
			}
[\n]			{++lineNumber; printf("\n");}

%%

int yywrap(){
	return 1;
}

int main(){
	yylex();
 	printLabelAddressTable();	
	return 1;
}

int getLabelNumber(char* label){

	char* labelPtr = label;
	char* labelNumber = malloc(sizeof(char));
	char* temp = labelNumber;

	++labelPtr;

	while (*labelPtr != ':' && *labelPtr != '\n'){
		*labelNumber = *labelPtr;
		++labelNumber;
		++labelPtr;
	}

	return atoi(temp);
}
