%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exprtree.h"
	#include "exprtree.c"

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
