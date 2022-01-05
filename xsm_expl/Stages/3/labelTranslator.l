%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "../Functions/label.h"

	int yywrap();
	int getLabelNumber(char* label);

	int lineNumber = 0;
	int labelNumber = 0;
	int lexPassRound = 1;
	FILE* filePtrRound1;
	FILE* filePtrRound2;
	FILE* filePtrTarget;
%}


%%

[L][0-9]+[\n]		{
				++lineNumber;
				if(lexPassRound == 2){
					int labelNum = getLabelNumber(yytext);
					int labelAddress = getLabelAddress(labelNum);
					fprintf(filePtrTarget, "%d\n", labelAddress);
				}
				else{	
					fprintf(filePtrRound2, "%s", yytext); 
				}

			}

[L][0-9]+[:][\n]	{
				++lineNumber;	
				if(lexPassRound == 1){
	
					int labelNum = getLabelNumber(yytext);
					int labelAddress = calcLabelAddress(lineNumber);
					struct labelAddressNode* newNode = createLabelAddressNode(labelNum, labelAddress);

					insertLabelAddressNode(newNode);
					lineNumber -= 1;
				}
				else{
					fprintf(filePtrTarget, "%s", yytext);
				}
			}
[\n]			{
				++lineNumber; 
				if(lexPassRound == 1)
					fprintf(filePtrRound2, "\n");

				if(lexPassRound == 2)
					fprintf(filePtrTarget, "\n");
			} 

.			{ 	
				if(lexPassRound == 1)
					fprintf(filePtrRound2, "%s", yytext);

				if(lexPassRound == 2)
					fprintf(filePtrTarget, "%s", yytext);
			}

%%

int yywrap(){

	if (lexPassRound == 1){
		lexPassRound = 2; 

		fclose(filePtrRound1);
		fclose(filePtrRound2);

		filePtrRound2 = fopen("round2.xsm", "r");
		filePtrTarget = fopen("target.xsm", "w");	

		yyin = filePtrRound2;
		return 0;
	}

	fclose(filePtrRound2);
	fclose(filePtrTarget);
	
	return 1;
}

int main(){
	
	filePtrRound1 = fopen("round1.xsm", "r");
	filePtrRound2 = fopen("round2.xsm", "w");	

	if(filePtrRound1)
		yyin = filePtrRound1;

	yylex();
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
