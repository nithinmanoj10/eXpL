%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "ast.h"
	#include "../Backend/codegen.h"
	#include "../Data_Structures/loopStack.h"
	#include "../Data_Structures/declarationsTree.h"
	#include "../Data_Structures/globalSymbolTable.h"
	#include "../Functions/xsm_library.h"
	#include "../Functions/xsm_syscalls.h"
	#include "../Functions/stackMemory.h"

	int yylex(void);
	void yyerror(char const *s);
	int lineCount = 0;
	char* fileName;
%}

%union {
	struct ASTNode* node;
	struct declarationsTree* DTNode;
}

/* TODO: Add rest of the nodes */
%type <node> start Slist Stmt inputStmt outputStmt assignStmt ifStmt VARIABLE expr NUM STRING whileStmt doWhileStmt breakStmt continueStmt breakPointStmt

%type <DTNode> Declarations DeclList Decl Type VarList

%token BEGIN_ END READ WRITE VARIABLE NUM STRING PLUS MINUS MUL DIV MOD EQUAL BREAKPOINT
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE
%token DECL ENDDECL INT STR 
%token SEMICOLON COMMA

%left EQUAL
%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MUL DIV MOD

%%

start 	: Declarations BEGIN_ Slist END SEMICOLON	{

							FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");
							printAST($3);	
							struct ASTNode* root = $3;	
							// printf("\nGSTHead: %p\n", GSTHead);
							writeXexeHeader(filePtr);
							initVariables(filePtr);
							codeGen($3, filePtr);							
							INT_10(filePtr);
	
				}

				| BEGIN_ END SEMICOLON		{	
																		printf("\n⛔ No Code Provided\n");
																		exit(1);
																	};

Slist	: Slist Stmt SEMICOLON 	{$$ = createASTNode(0, 1, 6, "C", $1, NULL, $2);}
			| Stmt SEMICOLON	{}				;

Stmt	: inputStmt | outputStmt | assignStmt 
			| ifStmt | whileStmt | doWhileStmt
      | breakStmt | continueStmt	
			|	breakPointStmt	{}
			;

inputStmt : READ expr	 		{$$ = createASTNode(0, 1, 4, "R", $2, NULL, NULL); ++lineCount;}
	  			;

outputStmt : WRITE expr 		{$$ = createASTNode(0, 1, 5, "W", $2, NULL, NULL); ++lineCount;}
	   			 ;

assignStmt : VARIABLE EQUAL expr	{$$ = createASTNode(0, 1, 3, "=", $1, NULL, $3); ++lineCount;}
	   			 ;

ifStmt	: IF expr THEN Slist ELSE Slist ENDIF
	{
		$$ = createASTNode(0, 2, 7, "I", $2, $4, $6);  
		++lineCount;	
	}
	| IF expr THEN Slist ENDIF {$$ = createASTNode(0, 2, 7, "I", $2, $4, NULL); ++lineCount;}
	;

whileStmt : WHILE expr DO Slist ENDWHILE {$$ = createASTNode(0, 2, 7, "W", $2, NULL, $4); ++lineCount;}
	  ;

doWhileStmt : DO Slist WHILE expr ENDWHILE  { $$ = createASTNode(0, 2, 7, "DW", $2, NULL, $4); ++lineCount;}
 	    ;			

breakStmt : BREAK		{ $$ = createASTNode(0, 0, 7, "B", NULL, NULL, NULL);}
	  ;

continueStmt : CONTINUE		{ $$ = createASTNode(0, 0, 7, "CN", NULL, NULL, NULL);}	 
	     				;

breakPointStmt	:	BREAKPOINT { $$ = createASTNode(0, 0, 8, "BR", NULL, NULL, NULL); }
							 	;

Declarations	:	DECL DeclList ENDDECL	{ 
						 														struct declarationsTree* root = $2;
																				createGST($2, 0);				
																				declarationComplete();
																			}
						 	|	DECL ENDDECL	{ declarationComplete(); }
							;

DeclList	:	DeclList Decl	{ 
														$$ = createDTNode(3, 0, "c", $1, $2);
				 									}
				 	|	Decl	{ $$ = $1; }
					;

Decl	:	Type VarList SEMICOLON	{
																	$1->left = $2;
																	$$ = $1;
																}
		 	;

Type	:	INT	{ $$ = createDTNode(1, 1, "int", NULL, NULL); }	
		 	|	STR	{ $$ = createDTNode(1, 2, "str", NULL, NULL); }
		 	;

VarList	:	VarList COMMA expr { $$ = createDTNode(2, 0, $3->varname, $1, NULL); }
				|	expr 	{ $$ = createDTNode(2, 0, $1->varname, NULL, NULL); }
				;
		

expr	: expr PLUS expr	{$$ = createASTNode(0, 1, 3, "+", $1, NULL, $3);}
			| expr MINUS expr {$$ = createASTNode(0, 1, 3, "-", $1, NULL, $3);}
			| expr MUL expr 	{$$ = createASTNode(0, 1, 3, "*", $1, NULL, $3);}
			| expr DIV expr		{$$ = createASTNode(0, 1, 3, "/", $1, NULL, $3);}
			| expr MOD expr		{$$ = createASTNode(0, 1, 3, "%", $1, NULL, $3);}
			| expr EQ expr		{$$ = createASTNode(0, 2, 3, "==", $1, NULL, $3);}
			| expr NEQ expr		{$$ = createASTNode(0, 2, 3, "!=", $1, NULL, $3);}
			| expr LT expr		{$$ = createASTNode(0, 2, 3, "<", $1, NULL, $3);}
			| expr LTE expr		{$$ = createASTNode(0, 2, 3, "<=", $1, NULL, $3);}
			| expr GT expr		{$$ = createASTNode(0, 2, 3, ">", $1, NULL, $3);}
			| expr GTE expr		{$$ = createASTNode(0, 2, 3, ">=", $1, NULL, $3);}
			| '(' expr ')'		{$$ = $2;}
			| VARIABLE				{$$ = $1;}
			| NUM							{$$ = $1;}
			| STRING					{$$ = $1;}
			;

%%

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at line %d\n", s, lineCount+1);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yyparse();
	}
	else{
		printf("\nEnter Filename\n");
		exit(1);
	}

	printf("\n✅ Successfully Compiled: Target code saved in target.xsm\n");
	
	char targetFile[50];
	sprintf(targetFile, "%s.xsm", argv[1]);

	return 0;
}
