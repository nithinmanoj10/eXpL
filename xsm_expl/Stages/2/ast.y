%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "ast.h"
	#include "ast.c"
	#include "codegen.c"
	#include "../Functions/xsm_library.h"
	#include "../Functions/xsm_library.c"
	#include "../Functions/xsm_syscalls.c"
	#include "../Functions/xsm_syscalls.h"

	int yylex(void);
	void yyerror(char const *s);
%}

%union {
	struct ASTNode* node;
}

%type <node> start Slist Stmt inputStmt outputStmt assignStmt VARIABLE expr NUM

%token BEGIN_ END READ WRITE VARIABLE NUM PLUS MINUS MUL DIV EQUAL 

%left EQUAL
%left PLUS MINUS
%left MUL DIV

%%

start 	: BEGIN_ Slist END	{

					FILE* filePtr = fopen("target.xsm", "w");
						
					writeXexeHeader(filePtr);		
					initVariables(filePtr);	
					codeGen($2, filePtr);
					INT_10(filePtr);

					printf("\nFinished\n");
					exit(1);
				}

	| BEGIN_ END		{	exit(1);}
	;

Slist	: Slist Stmt	{$$ = createASTNode(0, 6, "C", $1, $2);}
	| Stmt		{}				
	;

Stmt	: inputStmt | outputStmt | assignStmt	{}
	;

inputStmt : READ '(' VARIABLE ')'	{$$ = createASTNode(0, 4, "R", $3, NULL);}
	  ;

outputStmt : WRITE expr 		{$$ = createASTNode(0, 5, "W", $2, NULL);}
	   ;

assignStmt : VARIABLE EQUAL expr	{$$ = createASTNode(0, 3, "=", $1, $3);}
	   ;


expr	: expr PLUS expr	{$$ = createASTNode(0, 3, "+", $1, $3);}
	| expr MINUS expr 	{$$ = createASTNode(0, 3, "-", $1, $3);}
	| expr MUL expr 	{$$ = createASTNode(0, 3, "*", $1, $3);}
	| expr DIV expr		{$$ = createASTNode(0, 3, "/", $1, $3);}
	| '(' expr ')'		{$$ = $2;}
	| VARIABLE		{$$ = $1;}
	| NUM			{$$ = $1;}
	;

%%

void yyerror(char const *s){
	printf("\nError: %s\n", s);
}

int main(){
	yyparse();
	return 1;
}
