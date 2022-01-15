%{
	extern char yytext[];
	#define YYDEBUG_LEXER_TEXT yytext

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "ast.h"
	#include "../Backend/codegen.h"
	#include "../Data_Structures/loopStack.h"
	#include "../Data_Structures/GSTable.h"
	#include "../Data_Structures/typeTable.h"
	#include "../Functions/xsm_library.h"
	#include "../Functions/xsm_syscalls.h"
	#include "../Functions/stackMemory.h"
	#include "../Functions/stringMan.h"

	int yylex(void);
	void yyerror(char const *s);
	int statementCount = 0;
	char* fileName;
%}

%start start

%union {
	struct ASTNode* node;
}

%type <node> start Slist Stmt inputStmt outputStmt assignStmt ifStmt ID expr NUM STRING whileStmt doWhileStmt breakStmt continueStmt breakPointStmt

%token BEGIN_ END READ WRITE ID NUM STRING PLUS MINUS MUL DIV MOD EQUAL BREAKPOINT
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE
%token DECL ENDDECL INT STR
%token SEMICOLON COMMA

%left EQUAL
%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MUL DIV MOD

%%

start 	: GDeclBlock BEGIN_ Slist END SEMICOLON	{
											FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");
											writeXexeHeader(filePtr);
											initVariables(filePtr);
											codeGen($3, filePtr);							
											INT_10(filePtr);
											//printf("\n");
											// printAST($3);
										}

		| BEGIN_ END SEMICOLON		{	
										printf("\n⛔ No Code Provided\n");
										exit(1);
									};

Slist	: Slist Stmt SEMICOLON 	{ $$ = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, $1, NULL, $2); }
		| Stmt SEMICOLON		{}				
		;

Stmt	: inputStmt | outputStmt | assignStmt 
		| ifStmt | whileStmt | doWhileStmt
   		| breakStmt | continueStmt	
		| breakPointStmt	{ ++statementCount; }
		;

inputStmt	: READ expr	 		{ $$ = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, $2, NULL, NULL); }
	  		;

outputStmt 	: WRITE expr 		{ $$ = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, $2, NULL, NULL); }
	   		;

assignStmt 	: ID EQUAL expr					{ $$ = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| ID '[' expr ']' EQUAL expr	{	 
													$1->left = $3;
													$$ = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, $1, NULL, $6);
			 								}
	   		;

ifStmt	: IF expr THEN Slist ELSE Slist ENDIF	{ $$ = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, $2, $4, $6); }
		| IF expr THEN Slist ENDIF 				{ $$ = TreeCreate(TYPE_VOID, IF_NODE, NULL, 0, NULL, $2, $4, NULL); }
		;

whileStmt 	: WHILE expr DO Slist ENDWHILE { $$ = TreeCreate(TYPE_VOID, WHILE_NODE, NULL, 0, NULL, $2, NULL, $4); }
	  		;

doWhileStmt : DO Slist WHILE expr ENDWHILE  { $$ = TreeCreate(TYPE_VOID, DO_WHILE_NODE, NULL, 0, NULL, $2, NULL, $4); }
 	    	;			

breakStmt 	: BREAK	{ $$ = TreeCreate(TYPE_VOID, BREAK_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
	  		;

continueStmt	: CONTINUE	{ $$ = TreeCreate(TYPE_VOID, CONTINUE_NODE, NULL, 0, NULL, NULL, NULL, NULL); }	 
	     		;

breakPointStmt	:	BREAKPOINT { $$ = TreeCreate(TYPE_VOID, BREAKPOINT_NODE, NULL, 0, NULL, NULL, NULL, NULL); }
				;

GDeclBlock	:	DECL GDeclList ENDDECL	{ /* GSTPrint(); */}
			|	DECL ENDDECL			{}
			;

GDeclList	:	GDeclList GDecl			{}
			|	GDecl					{}
			;

GDecl		:	Type GIDList SEMICOLON	{}
			;

Type		: 	INT						{ setDeclarationType(TYPE_INT); }
			|	STR						{ setDeclarationType(TYPE_STR); }
			;

GIDList		:	GIDList COMMA GID		{}
			|	GID						{}
			;

GID			:	ID						{ GSTInstall($1->nodeName, getDeclarationType(), 1); }
			|	ID '[' NUM ']'			{ GSTInstall($1->nodeName, getDeclarationType(), $3->intConstVal); }
			;


expr		: expr PLUS expr		{ $$ =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr MINUS expr 		{ $$ =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr MUL expr 		{ $$ =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr DIV expr			{ $$ =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr MOD expr			{ $$ =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr EQ expr			{ $$ =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr NEQ expr			{ $$ =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr LT expr			{ $$ =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr LTE expr			{ $$ =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr GT expr			{ $$ =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr GTE expr			{ $$ =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| '(' expr ')'			{ $$ = $2; }
			| ID '[' expr ']' 		{	
										if ($3->dataType != TYPE_INT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										$1->left = $3;	
										$$ = $1;
									}
			| ID					{$$ = $1;}
			| NUM					{$$ = $1;}
			| STRING				{$$ = $1;}
			;

%%

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at line %d\n", s, statementCount);
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
