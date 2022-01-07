%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "ast.h"
	#include "intepreter.h"
	int yylex(void);
	void yyerror(char const *s);
	int lineCount = 0;
	char* fileName;
%}

%union {
	struct ASTNode* node;
}

%type <node> start Slist Stmt inputStmt outputStmt assignStmt VARIABLE expr NUM

%token BEGIN_ END READ WRITE VARIABLE NUM PLUS MINUS MUL DIV EQUAL SEMICOLON

%left EQUAL
%left PLUS MINUS
%left MUL DIV

%%

start 	: BEGIN_ Slist END SEMICOLON	{
						
						printf("\n🔰 Starting Intepreter\n\n");
					
						initVariableStorage();
						codeIntepreter($2);
						return 0;
					}

	| BEGIN_ END SEMICOLON		{	
						printf("\n⛔ No Code Provided\n");
						exit(1);
					}
	;

Slist	: Slist Stmt SEMICOLON 	{$$ = createASTNode(0, 6, "C", $1, $2);}
	| Stmt SEMICOLON	{}				
	;

Stmt	: inputStmt | outputStmt | assignStmt	{}
	;

inputStmt : READ '(' VARIABLE ')'	{$$ = createASTNode(0, 4, "R", $3, NULL); ++lineCount;}
	  ;

outputStmt : WRITE expr 		{$$ = createASTNode(0, 5, "W", $2, NULL); ++lineCount;}
	   ;

assignStmt : VARIABLE EQUAL expr	{$$ = createASTNode(0, 3, "=", $1, $3); ++lineCount;}
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
	printf("\n❌ Error: %s, at line %d\n", s, lineCount+1);
	exit(1);
}

int main(){

	yyparse();
	return 0;
}
