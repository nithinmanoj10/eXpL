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

			// storing the result in memory address 4096
			fprintf(filePtr, "MOV [4096], R%d\n", resultRegNo);
			fprintf(filePtr, "MOV R2, [4096]\n");
 
			// for time being, value to be printed is stored in
			// register R2
			Write(filePtr, -2, "null", 0); 
			INT_10(filePtr);		

			printf("Answer: %d\n", evaluateTree($1));

			exit(1);
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
}

int main(void){
	yyparse();
	return 0;
}
