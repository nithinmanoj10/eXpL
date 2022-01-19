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
	#include "../Data_Structures/LSTable.h"
	#include "../Data_Structures/typeTable.h"
	#include "../Data_Structures/paramStruct.h"
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
	struct LSTNode* lstnode;
}

%type <node> start Slist Stmt inputStmt outputStmt assignStmt ifStmt ID FID expr NUM STRING whileStmt doWhileStmt breakStmt continueStmt breakPointStmt retStmt retVal MBody FBody Arg ArgList


%token BEGIN_ END MAIN READ WRITE ID NUM STRING PLUS MINUS MUL DIV MOD AMPERSAND EQUAL BREAKPOINT
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE
%token DECL ENDDECL INT STR RETURN
%token SEMICOLON COMMA

%left EQUAL
%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MUL DIV MOD
%left AMPERSAND

%%

 /* Program Block ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
start 	: GDeclBlock FDefBlock MainBlock	{}
		| GDeclBlock MainBlock 				{}
		| GDeclBlock 						{	
												printf("\n⛔ No Code Provided\n");
												exit(1);
											};
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */



Slist	: Slist Stmt SEMICOLON 	{ $$ = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, $1, NULL, $2); }
		| Stmt SEMICOLON		{}				
		;

Stmt	: inputStmt | outputStmt | assignStmt 
		| ifStmt | whileStmt | doWhileStmt
   		| breakStmt | continueStmt	
		| breakPointStmt									{ ++statementCount; }
		;

inputStmt	: READ expr	 		{ $$ = TreeCreate(TYPE_VOID, READ_NODE, NULL, 0, NULL, $2, NULL, NULL); }
	  		;

outputStmt 	: WRITE expr 		{ $$ = TreeCreate(TYPE_VOID, WRITE_NODE, NULL, 0, NULL, $2, NULL, NULL); }
	   		;

assignStmt 	: ID EQUAL expr					{ 
												$1 = lookupID($1);
												$$ = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, $1, NULL, $3); 
											}
			| ID '[' expr ']' EQUAL expr	{	 
												$1 = lookupID($1);	
												$1->left = $3;
												$$ = TreeCreate(TYPE_VOID, ASGN_NODE, NULL, 0, NULL, $1, NULL, $6);
			 								}
	   		;


 /* Return Statement ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
retVal		:	expr						{}
			;

retStmt		: RETURN retVal SEMICOLON		{ $$ = TreeCreate(TYPE_VOID, RETURN_NODE, NULL, 0, NULL, $2, NULL, NULL); }
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


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

 /* Global Declaration ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
GDeclBlock	:	DECL GDeclList ENDDECL	{ GSTPrint(); }
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

GID			:	ID						{ GSTInstall($1->nodeName, getDeclarationType(), 1, NULL); }
			|	ID '[' NUM ']'			{ 
											if ($3->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											GSTInstall($1->nodeName, getDeclarationType(), $3->intConstVal, NULL); 
										}
			|	ID '(' ParamList ')'	{ 
											GSTInstall($1->nodeName, getDeclarationType(), -1, getParamListHead());
											flushParamList();
											setParamType(TYPE_VOID);
										}
			|	MUL ID					{
											if (getDeclarationType() == TYPE_INT)
												GSTInstall($2->nodeName, TYPE_INT_PTR, 1, NULL);

											if (getDeclarationType() == TYPE_STR)
												GSTInstall($2->nodeName, TYPE_STR_PTR, 1, NULL);
										}
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Function Parameters ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
ParamList	:	ParamList COMMA Param	{}
			|	Param					{}
			;

ParamType	:	INT						{ setParamType(TYPE_INT); }
			|	STR						{ setParamType(TYPE_STR); }
			;

Param		:	ParamType ID			{ paramListInstall(getParamType(), $2->nodeName); }
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Function Arguments ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
ArgList		:	ArgList COMMA Arg		{ 
											$$ = insertToArgList($1, $3);
										}
			|	Arg						{ $$ = $1; }
			;

Arg			:	expr					{ $$ = $1; }
			;			
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Function Block ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
FDefBlock	:	FDefBlock FDef							{}
			|	FDef									{}
			;

FID			:	ID										{ 
															if(GSTLookup($1->nodeName) == NULL){
																printf("\nFunction %s is not declared\n", $1->nodeName);
																exit(1);
															}
															$$ = $1; 
															setCurrentFuncName($1->nodeName);
														}
			;

FDef		:	FuncSign
				'{' LDeclBlock FBody '}'				{
															printf("\nFor function %s: \n", getCurrentFuncName());
															printAST($4);
															flushLST();
														}
			;

FuncSign	:	FuncType FID '(' ParamList ')'			{
															verifyFunctionSignature($2->nodeName);
															LSTAddParams();
															flushParamList();
														}

FuncType	:	INT										{ setFuncType(TYPE_INT); }
			|	STR										{ setFuncType(TYPE_STR); }
			;

FBody		:	BEGIN_ Slist retStmt END SEMICOLON		{
															struct ASTNode* funcBodyStmt = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, $2, NULL, $3);
															$$ = funcBodyStmt;
														}	
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Local Declarations ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
LDeclBlock	:	DECL LDeclList ENDDECL	{ LSTPrint(); }
			|	DECL ENDDECL			{}
			;

LDeclList	:	LDeclList LDecl			{}
			|	LDecl					{}
			;

LDecl		:	Type LIDList SEMICOLON	{}
			;

LIDList		:	LIDList COMMA LID		{}
			|	LID						{}
			; 

LID			:	ID						{ LSTInstall($1->nodeName, getDeclarationType()); }
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Main Block ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
MainBlock	:	MainFunc '('')'
				'{' 
					LDeclBlock 
					MBody 
				'}'									{
														printf("\nFor function %s: \n", getCurrentFuncName());
														printAST($6);	
														// FILE* filePtr = fopen("../Target_Files/round1.xsm", "w");
														// writeXexeHeader(filePtr);
														// initVariables(filePtr);
														// codeGen($6, filePtr);							
														// INT_10(filePtr);
														// printf("\n");
													}
			;

MainFunc	:	INT MAIN							{ setCurrentFuncName("int main"); }
			;

MBody		:	BEGIN_ Slist retStmt END SEMICOLON	{
														struct ASTNode* statementList = TreeCreate(TYPE_VOID, SLIST_NODE, NULL, 0, NULL, $2, NULL, $3);
														$$ = statementList;
													}
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


expr		: expr PLUS expr		{ $$ =  TreeCreate(TYPE_INT, PLUS_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr MINUS expr 		{ $$ =  TreeCreate(TYPE_INT, MINUS_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr MUL expr 		{ $$ =  TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr DIV expr			{ $$ =  TreeCreate(TYPE_INT, DIV_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr MOD expr			{ $$ =  TreeCreate(TYPE_INT, MOD_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| AMPERSAND expr		{ $$ = 	TreeCreate(TYPE_INT, AMP_NODE, NULL, 0, NULL, $2, NULL, NULL); }
			| MUL expr				{ 
										if ($2->dataType == TYPE_INT_PTR)
											$$ = TreeCreate(TYPE_INT, MUL_NODE, NULL, 0, NULL, NULL, $2, NULL);

										if ($2->dataType == TYPE_STR_PTR)
											$$ = TreeCreate(TYPE_STR, MUL_NODE, NULL, 0, NULL, NULL, $2, NULL);	
			 						}
			| expr EQ expr			{ $$ =  TreeCreate(TYPE_BOOL, EQ_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr NEQ expr			{ $$ =  TreeCreate(TYPE_BOOL, NE_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr LT expr			{ $$ =  TreeCreate(TYPE_BOOL, LT_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr LTE expr			{ $$ =  TreeCreate(TYPE_BOOL, LE_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr GT expr			{ $$ =  TreeCreate(TYPE_BOOL, GT_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| expr GTE expr			{ $$ =  TreeCreate(TYPE_BOOL, GE_NODE, NULL, 0, NULL, $1, NULL, $3); }
			| '(' expr ')'			{ $$ = $2; }
			| ID '(' ArgList ')'	{ 
										$1 = lookupID($1);	
										verifyFunctionArguments($1->nodeName, $3);	
										$$ = TreeCreate(getFunctionType($1->nodeName), FUNC_NODE, $1->nodeName, 0, NULL, NULL, NULL, NULL); 
										$$->argList = $3;
										$$->GSTEntry = $1->GSTEntry;
									}
			| ID '[' expr ']' 		{	
										if ($3->dataType != TYPE_INT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										$1->left = $3;	
										$$ = $1;
									}
			| ID					{
										$1 = lookupID($1);
										$$ = $1;
									}
			| NUM					{$$ = $1;}
			| STRING				{$$ = $1;}
			;

%%

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at statement %d\n", s, statementCount);
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
