%{
	extern char yytext[];
	#define YYDEBUG_LEXER_TEXT yytext

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
	#include "../Functions/stringMan.h"

	int yylex(void);
	void yyerror(char const *s);
	int lineCount = 0;
	char* fileName;
%}

%start start

%union {
	struct ASTNode* node;
	// struct declarationsTree* DTNode;
}

%type <node> start Slist Stmt inputStmt outputStmt assignStmt ifStmt ID expr NUM STRING whileStmt doWhileStmt breakStmt continueStmt breakPointStmt

/* %type <DTNode> Declarations DeclList Decl Type VarList */

%token BEGIN_ END READ WRITE ID NUM STRING PLUS MINUS MUL DIV MOD EQUAL BREAKPOINT
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE
	/* %token DECL ENDDECL INT STR */
%token SEMICOLON

%left EQUAL
%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MUL DIV MOD
%left '['

%%

start 	: BEGIN_ Slist END SEMICOLON	{
														// printAST($2);
														FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");
														// // printAST($3);	
														// // printGST();
														writeXexeHeader(filePtr);
														initVariables(filePtr);
														codeGen($2, filePtr);							
														INT_10(filePtr);
													}

		| BEGIN_ END SEMICOLON		{	
										printf("\n⛔ No Code Provided\n");
										exit(1);
									};

Slist	: Slist Stmt SEMICOLON 	{   // $$ = createASTNode(0, 1, 6, "C", -1, $1, NULL, $2);
									$$ = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, $1, NULL, $2);
								}
		| Stmt SEMICOLON		{}				;

Stmt	: inputStmt | outputStmt | assignStmt 
		| ifStmt | whileStmt | doWhileStmt
   		| breakStmt | continueStmt	
		| breakPointStmt	{}
		;

inputStmt : READ expr	 		{	// 	$$ = createASTNode(0, 1, 4, "R", -1, $2, NULL, NULL); 
									$$ = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, $2, NULL, NULL);
									++lineCount;
								}
	  			;

outputStmt : WRITE expr 		{
									// $$ = createASTNode(0, 1, 5, "W", -1, $2, NULL, NULL); 
									$$ = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, $2, NULL, NULL);
									++lineCount;
								}
	   			 ;

assignStmt 	: ID EQUAL expr				{
											// $$ = createASTNode(0, 1, 3, "=", -1, $1, NULL, $3);
											$$ = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, $1, NULL, $3);
											++lineCount;
										}
			| ID '[' expr ']' EQUAL expr	{	 
													$1->left = $3;
													// $$ = createASTNode(0, 1, 3, "=", -1, $1, NULL, $6);
													++lineCount;
			 									}
	   		;

ifStmt	: IF expr THEN Slist ELSE Slist ENDIF
	{
		// $$ = createASTNode(0, 2, 7, "I", -1, $2, $4, $6);  
		$$ = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, $2, $4, $6);
		++lineCount;	
	}
	| IF expr THEN Slist ENDIF {
									// $$ = createASTNode(0, 2, 7, "I", -1, $2, $4, NULL);
									$$ = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, $2, $4, NULL);
									++lineCount;
								}
	;

whileStmt : WHILE expr DO Slist ENDWHILE {
											// $$ = createASTNode(0, 2, 7, "W", -1, $2, NULL, $4);
											$$ = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, $2, NULL, $4);	
											++lineCount;
											}
	  ;

doWhileStmt : DO Slist WHILE expr ENDWHILE  { 
											 	// $$ = createASTNode(0, 2, 7, "DW", -1, $2, NULL, $4);
												$$ = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, $2, NULL, $4);
												++lineCount;
											}
 	    ;			

breakStmt : BREAK		{ 
							// $$ = createASTNode(0, 0, 7, "B", -1, NULL, NULL, NULL);
							$$ = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL);
						}
	  ;

continueStmt : CONTINUE		{ 
								// $$ = createASTNode(0, 0, 7, "CN", -1, NULL, NULL, NULL);
								$$ = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL);
							}	 
	     				;

breakPointStmt	:	BREAKPOINT { 
									// $$ = createASTNode(0, 0, 8, "BR", -1, NULL, NULL, NULL);
									$$ = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL);
								}
							 	;

/* Declarations	:	DECL DeclList ENDDECL	{ 
						 														struct declarationsTree* root = $2;
																				createGST($2, 0);				
																				declarationComplete();
																				// printDeclarationsTree($2);
																				// printGST();
																			}
						 	|	DECL ENDDECL	{ declarationComplete(); }
							;

DeclList	:	DeclList Decl	{ 
														$$ = createDTNode(3, 0, "c", 0, $1, $2);
				 									}
				 	|	Decl	{ $$ = $1; }
					;

Decl	:	Type VarList SEMICOLON	{
																	$1->left = $2;
																	$$ = $1;
																}
		 	;

Type	:	INT	{ $$ = createDTNode(1, 1, "int", 0, NULL, NULL); }	
		 	|	STR	{ $$ = createDTNode(1, 2, "str", 0, NULL, NULL); }
		 	;

VarList	:	VarList COMMA ID 							{ $$ = createDTNode(2, 0, $3->varname, 1, $1, NULL); }
		|	ID 										{ $$ = createDTNode(2, 0, $1->varname, 1, NULL, NULL); }
		|	VarList COMMA ID '[' NUM ']'				{ $$ = createDTNode(2, 0, $3->varname, $5->val, $1, NULL); }
		|	ID '[' NUM ']'							{ $$ = createDTNode(2, 0, $1->varname, $3->val, NULL, NULL); }
		| 	VarList COMMA ID '[' NUM ']' '[' NUM ']'	{ $$ = createDTNode(2, 0, $3->varname, $5->val * $8->val, $1, NULL); }
		|	ID '[' NUM ']' '[' NUM ']'				{ $$ = createDTNode(2, 0, $1->varname, $3->val * $6->val, NULL, NULL); }
		; */

expr		: expr PLUS expr		{// $$ = createASTNode(0, 1, 3, "+", -1, $1, NULL, $3);
										$$ =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, $1, NULL, $3);
									}
			| expr MINUS expr 		{// $$ = createASTNode(0, 1, 3, "-", -1, $1, NULL, $3);
										$$ =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, $1, NULL, $3);			
												}
			| expr MUL expr 		{// $$ = createASTNode(0, 1, 3, "*", -1, $1, NULL, $3);
										$$ =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, $1, NULL, $3);			
												}
			| expr DIV expr			{// $$ = createASTNode(0, 1, 3, "/", -1, $1, NULL, $3);
										$$ =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, $1, NULL, $3);			
												}
			| expr MOD expr			{// $$ = createASTNode(0, 1, 3, "%", -1, $1, NULL, $3);
										$$ =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, $1, NULL, $3);			
												}
			| expr EQ expr			{// $$ = createASTNode(0, 2, 3, "==", -1, $1, NULL, $3)
										$$ =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, $1, NULL, $3);			
												;}
			| expr NEQ expr			{// $$ = createASTNode(0, 2, 3, "!=", -1, $1, NULL, $3)
										$$ =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, $1, NULL, $3);			
												;}
			| expr LT expr			{// $$ = createASTNode(0, 2, 3, "<", -1, $1, NULL, $3);
										$$ =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, $1, NULL, $3);			
												}
			| expr LTE expr			{// $$ = createASTNode(0, 2, 3, "<=", -1, $1, NULL, $3)
										$$ =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, $1, NULL, $3);			
												;}
			| expr GT expr			{// $$ = createASTNode(0, 2, 3, ">", -1, $1, NULL, $3);
										$$ =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, $1, NULL, $3);			
												}
			| expr GTE expr			{// $$ = createASTNode(0, 2, 3, ">=", -1, $1, NULL, $3)
										$$ =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, $1, NULL, $3);			
												;}
			| '(' expr ')'			{$$ = $2;}
			| ID '[' expr ']' 	{	
										$1->left = $3;	
										$$ = $1;
										// $$ = createASTNode(0, 1, 2, $1->varname, 1, $3, NULL, NULL);
									}
			| ID				{$$ = $1;}
			| NUM					{$$ = $1;}
			| STRING				{$$ = $1;}
			;

%%

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at line %d\n", s, lineCount+1);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yydebug = 0;
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
