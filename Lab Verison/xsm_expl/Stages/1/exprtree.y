%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exprtree.h"
	#include "exprtree.c"
	#include "codegen.h"
	#include "codegen.c"
	#include "xsm_library.h"
	#include "xsm_library.c"
	#include "xsm_syscalls.h"
	#include "xsm_syscalls.c"
	#include "reg.h"

	int yylex(void);
	void yyerror(char const *s);
%}

%union {
	struct treeNode* node;
}

%type <node> expr NUM start END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

start	: expr END {

			struct treeNode* root = $1;		
			FILE* filePtr = fopen("target.xsm", "w");
			int resultRegNo;
			
			writeXexeHeader(filePtr);
			resultRegNo = codeGen(root, filePtr);

			// storing the result in memory address 5000
			fprintf(filePtr, "MOV [5000], R%d\n", resultRegNo);
			
			freeReg();
 
			// for time being, value to be printed is stored in
			// memory address 5000
			INT_7(filePtr, -2, NULL); 
			INT_10(filePtr);		

			printf("Answer: %d\n", evaluateTree($1));

			exit(0);
		   }
	;

expr	: expr PLUS expr 	{$$ = makeInternalNode('+', $1, $3);}
	| expr MINUS expr 	{$$ = makeInternalNode('-', $1, $3);}
	| expr MUL expr 	{$$ = makeInternalNode('*', $1, $3);}
	| expr DIV expr 	{$$ = makeInternalNode('/', $1, $3);}
	| '(' expr ')' 		{$$ = $2;}
	| NUM			{$$ = $1;}
	;

%%

void yyerror(char const *s){
	printf("\nyerror: %s\n", s);
	exit(1);
}

int main(void){
	yyparse();
	return 0;
}
