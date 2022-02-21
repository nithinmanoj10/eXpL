%{
	extern char yytext[];
	#define YYDEBUG_LEXER_TEXT yytext

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <limits.h>
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
	#include "../Functions/label.h"

	int yylex(void);
	void yyerror(char const *s);
	int statementCount = 0;
	int typeFieldCount = 0;
	int tupleFieldCount = 0;
	char* fileName;
	FILE* filePtr;
%}

%start start

%union {
	struct ASTNode* node;
	struct LSTNode* lstnode;
	struct TypeTable* TTNode;
	struct FieldList* FLNode;
}

%type <node> start Slist Stmt inputStmt outputStmt assignStmt ifStmt ID FID expr NUM STRING whileStmt doWhileStmt breakStmt continueStmt breakPointStmt retStmt retVal MBody FBody Arg ArgList GPtrID StructField INITIALIZE InitializeStmt ALLOC AllocStmt FREE FreeStmt NULL_ DynaMemID StructID TupleFieldName
%type <TTNode> TypeName TypeID GType LType TupleFieldType
%type <FLNode> FieldDecl FieldDeclList TupleFieldDecl TupleFieldDeclList TupleDecl

%token BEGIN_ END MAIN READ WRITE ID NUM STRING PLUS MINUS MUL DIV MOD AMPERSAND BREAKPOINT TYPE ENDTYPE TUPLE
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE AND OR NOT
%token DECL ENDDECL INT STR RETURN NULL_
%token ALLOC FREE INITIALIZE ',' ')'

%left '='
%left OR
%left AND
%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MUL DIV MOD
%left AMPERSAND
%left NOT
%left ','


%%

 /* Program Block ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
start 	: TypeDefBlock GDeclBlock FDefBlock MainBlock	{}
		| TypeDefBlock GDeclBlock MainBlock 				{}
		| TypeDefBlock GDeclBlock 						{	
												printf("\n⛔ No Code Provided\n");
												exit(1);
											};
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Type Definition Block ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

TypeDefBlock	:	TYPE TypeDefList ENDTYPE	{ 
													// printTypeTable(); 
												}
				|
				;

TypeDefList		:	TypeDefList TypeDef			{}
				|	TypeDef						{}
				;

TypeDef			:	TypeID 
					'{' FieldDeclList '}'		{ 
													if (typeFieldCount > 8){
														printf("\nError: User defined type %s has more than 8 fields\n", $1->typeName);
														exit(1);
													}

													// FLPrint($1); 
													$1->typeCategory = TYPE_USER_DEFINED;
													$1->fields = $3;
													$1->size = typeFieldCount;

													fieldListTail = NULL;
													fieldListHead = NULL;
													typeFieldCount = 0;
												}
				;

TypeID			:	ID							{ $$ = TTInstall($1->nodeName, 0, NULL); }
				;

FieldDeclList	:	FieldDeclList FieldDecl		{ 
													$2->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = $2;
													fieldListTail = $2;
													$$ = $1;
												}
				|	FieldDecl					{ 
													$1->fieldIndex = 0;
													fieldListHead = $1;
													fieldListTail = $1;
													$$ = $1;
				 								}
				;

FieldDecl		:	TypeName ID ';'				{ 
													$$ = FLCreateNode($2->nodeName, $1); 
													++typeFieldCount;
												}
				;

TypeName		:	INT							{ $$ = TTLookUp("int"); }
				|	STR							{ $$ = TTLookUp("str"); }
				|	ID							{ $$ = TTLookUp($1->nodeName); }
				;	

 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

Slist	: Slist Stmt ';' 	{ $$ = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, $1, NULL, $2); }
		| Stmt ';'		{}				
		;

Stmt	: inputStmt | outputStmt | assignStmt 
		| ifStmt | whileStmt | doWhileStmt
   		| breakStmt | continueStmt	
		| breakPointStmt
		| DynamicMemStmt									{ ++statementCount; }
		;

inputStmt	: READ expr	 		{ $$ = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, $2, NULL, NULL); }
	  		;

outputStmt 	: WRITE expr 		{ $$ = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, $2, NULL, NULL); }
	   		;

assignStmt 	: 	ID '=' expr						{ 
													$1 = lookupID($1);
													$$ = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); 
												}
			| 	ID '[' expr ']' '=' expr		{	 
													$1 = lookupID($1);	
													$1->left = $3;
													$$ = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, $1, NULL, $6);
												}
			| 	MUL ID '=' expr					{
													$2 = lookupID($2);	
													struct ASTNode* mulNode;
													if ($2->typeTablePtr == typeTableINTPtr)
														mulNode = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, $2, NULL);

													if ($2->typeTablePtr == typeTableSTRPtr)
														mulNode = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, $2, NULL);
													$$ = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, mulNode, NULL, $4);
												}
			| 	StructField '=' expr			{
													$$ = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, $1, NULL, $3);
												}
	   		;


 /* Return Statement ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
retVal		:	expr						{}
			;

retStmt		: RETURN retVal ';'		{ $$ = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, $2, NULL, NULL); }
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


ifStmt	: IF expr THEN Slist ELSE Slist ENDIF	{ $$ = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, $2, $4, $6); }
		| IF expr THEN Slist ENDIF 				{ $$ = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, $2, $4, NULL); }
		;

whileStmt 	: WHILE expr DO Slist ENDWHILE { $$ = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, $2, NULL, $4); }
	  		;

doWhileStmt : DO Slist WHILE expr ENDWHILE  { $$ = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, $2, NULL, $4); }
 	    	;			

breakStmt 	: BREAK	{ $$ = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
	  		;

continueStmt	: CONTINUE	{ $$ = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }	 
	     		;

breakPointStmt	:	BREAKPOINT { $$ = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
				;

 /* Global Declaration ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

GDeclBlock	:	DECL GDeclList ENDDECL		{
												// GSTPrint(); 
												// printTypeTable();					
												initStackBP(filePtr);
												// printGlobalParamList();
											}
			|	DECL ENDDECL				{}
			;

GDeclList	:	GDeclList GDecl				{}
			|	GDecl						{}
			;

GDecl		:	GType GIDList ';'			{}
			|	GType TupleDecl GIDList ';'	{ 
												$1->typeCategory = TYPE_TUPLE;				
												$1->fields = $2; 
												$1->size = tupleFieldCount;

												// FLPrint($1);

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentGDeclType = NULL;
												tupleFieldCount = 0;
											}
			;

GType		:	INT							{ currentGDeclType = TTLookUp("int"); }
			|	STR							{ currentGDeclType = TTLookUp("str"); }
			|	ID							{ 
												currentGDeclType = TTLookUp($1->nodeName);
												if(currentGDeclType == NULL) {
													printf("\nType %s undeclared before use\n", $1->nodeName);
													exit(1);
												}
			 								}
			|	TUPLE ID					{ 
												if (TTLookUp($2->nodeName) != NULL){
													printf("\nType Error: Tuple %s decalred twice\n", $2->nodeName);
													exit(1);
												}					
												currentGDeclType = TTInstall($2->nodeName, 0, NULL); 
												$$ = currentGDeclType;
											}
			;

GIDList		:	GIDList ',' GID				{}
			|	GID							{}
			;

GID			:	ID							{ 
												int varSize = (currentGDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentGDeclType->size);
												GSTInstall($1->nodeName, currentGDeclType, varSize, NULL); 
											}
			|	ID '[' NUM ']'				{
												if ($3->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall($1->nodeName, currentGDeclType, $3->intConstVal, NULL); 
											}
			|	ID '(' ParamList ')'		{
												GSTInstall($1->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
			|	GPtrID						{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall($1->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall($1->nodeName, TTLookUp("str*"), 1, NULL);	
											}
			|	GPtrID '(' ParamList ')'	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall($1->nodeName, TTLookUp("int*"), -1, getParamListHead());	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall($1->nodeName, TTLookUp("str*"), -1, getParamListHead());

												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
			;

GPtrID		:	MUL ID						{ $$ = $2; }
			;		

 /* Tuple Declarations ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

TupleDecl			:	'(' TupleFieldDeclList ')'				{ 
																	$$ = $2; 

																	if (currentGDeclType != NULL)
																		currentGDeclType->size = tupleFieldCount;
																	if (currentLDeclType != NULL)
																		currentLDeclType->size = tupleFieldCount;		
																}
					;

TupleFieldDeclList	:	TupleFieldDeclList ',' TupleFieldDecl	{
																	$3->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = $3;
																	fieldListTail = $3;
																	$$ = $1;
																}
					|	TupleFieldDecl							{
																	$1->fieldIndex = 0;
																	fieldListHead = $1;
																	fieldListTail = $1;
																	$$ = $1;
																}
					;

TupleFieldDecl		:	TupleFieldType TupleFieldName			{
																	$$ = FLCreateNode($2->nodeName, $1);
																	++tupleFieldCount;
																}
					;

TupleFieldType		:	INT										{ $$ = TTLookUp("int"); }
					|	STR										{ $$ = TTLookUp("str"); }
					;	

TupleFieldName		:	ID										{ $$ = $1; }
					;

 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


	/* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

ParamList	:	ParamList ',' Param		{}
			|	Param					{}
			|	/* empty */				{}
			;

Param		:	ParamType ID			{ 
											paramListInstall(currentParamType, $2->nodeName);
											++paramCount;	
										}
			;

ParamType	:	INT						{ currentParamType = TTLookUp("int"); }
			|	STR						{ currentParamType = TTLookUp("str"); }
			|	INT MUL					{  }
			|	STR MUL					{  }
			|	ID						{ currentParamType = TTLookUp($1->nodeName); }
			;

				
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Function Arguments ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

ArgList		:	ArgList ',' Arg			{ $$ = insertToArgList($1, $3); }
			|	Arg						{ $$ = $1; }
			|							{}
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
															char* currentFuncName = getCurrentFuncName();

															// TODO: Pls check!!!
															// addFunctionLST(currentFuncName, LSTHead);	
															
															fprintf(filePtr, "F%d:\n", GSTLookup(currentFuncName)->fLabel);
															initFuncCalle(filePtr, paramCount);

															// printASTTable($4, 0);
															codeGen($4, filePtr);

															// LSTPrint();
															flushLST();
															paramCount = 0;
														}
			;

FuncSign	:	FuncType FID '(' ParamList ')'			{
															verifyFunctionSignature($2->nodeName);
															LSTAddParams();
															flushParamList();
														}

FuncType	:	INT										{ currentFDefType = TTLookUp("int"); }
			|	STR										{ currentFDefType = TTLookUp("str"); }
			|	INT MUL									{ currentFDefType = TTLookUp("int*"); }
			|	STR MUL									{ currentFDefType = TTLookUp("str*"); }
			|	ID										{ currentFDefType = TTLookUp($1->nodeName); }
			;

FBody		:	BEGIN_ Slist retStmt END ';'		{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, $2, NULL, $3);
															$$ = funcBodyStmt;
														}	
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Local Declarations ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
LDeclBlock	:	DECL LDeclList ENDDECL	
			|							{  
											// printTupleList();
										}
			|	DECL ENDDECL			{}
			;

LDeclList	:	LDeclList LDecl			{}
			|	LDecl					{}
			;

LDecl		:	LType LIDList ';'			{}
			|	LType TupleDecl LIDList ';'	{
												$1->typeCategory = TYPE_TUPLE;				
												$1->fields = $2; 
												$1->size = tupleFieldCount;

												// FLPrint($1);

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentLDeclType = NULL;
												tupleFieldCount = 0;
											}
			;

LType		: 	INT						{ currentLDeclType = TTLookUp("int"); }
			|	STR						{ currentLDeclType = TTLookUp("str"); }
			|	ID						{ 
											currentLDeclType = TTLookUp($1->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", $1->nodeName);
												exit(1);
											}
										}
			|	TUPLE ID				{
											if (TTLookUp($2->nodeName) != NULL){
												printf("\nType Error: Tuple %s decalred twice\n", $2->nodeName);
												exit(1);
											}					
											currentLDeclType = TTInstall($2->nodeName, 0, NULL); 
											$$ = currentLDeclType;
										}
			;

LIDList		:	LIDList ',' LID		{}
			|	LID						{}
			; 

LID			:	ID						{ 
											int varSize = (currentLDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentLDeclType->size);							
											LSTInstall($1->nodeName, currentLDeclType, varSize); 
										}
			|	ID '[' NUM ']'			{
											if ($3->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall($1->nodeName, currentLDeclType, $3->intConstVal); 
										}
			|	MUL ID					{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall($2->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall($2->nodeName, TTLookUp("int*"), 1);	
										}
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Main Block ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
MainBlock	:	MainFunc '('')'
				'{' 
					LDeclBlock 
					MBody 
				'}'									{
														char* currentFuncName = getCurrentFuncName();

														// TODO: Check!!!
														// addFunctionLST(currentFuncName, LSTHead);	

														fprintf(filePtr, "F0:\n");
														initFuncCalle(filePtr, paramCount);

														// printASTTable($6, 0);
														codeGen($6, filePtr);
														// LSTPrint();
														flushLST();
														paramCount = 0;
												
														// printFLT();
													}
			;

MainFunc	:	INT MAIN							{ setCurrentFuncName("int main"); }
			;

MBody		:	BEGIN_ Slist retStmt END ';'	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, $2, NULL, $3);
														$$ = statementList;
													}
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Dynamic Memory Allocation ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

DynamicMemStmt	:	AllocStmt
				|	FreeStmt
				|	InitializeStmt
				;	

AllocStmt		:	DynaMemID ALLOC '(' ')'		{
															$1 = lookupID($1);
															$$ = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, $1, NULL, $2);
														}
				;

FreeStmt		:	DynaMemID FREE '(' expr ')'	{
															$1 = lookupID($1);
															$2->left = $4;
															$$ = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, $1, NULL, $2);
														}
				;

InitializeStmt	:	DynaMemID INITIALIZE '(' ')'	{
															$1 = lookupID($1);
															$$ = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, $1, NULL, $2);
														}
				;

DynaMemID		:	ID '='							{ $$ = $1; }
				|	ID '[' expr ']'	'='				{
															$$ = $1;
															$$->left = $3;	
														}
				;

 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

 /* Struct Fields ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

StructField		:	StructField '.' ID		{
												struct ASTNode* traversalPtr = $1;
												while (traversalPtr->right != NULL){
													traversalPtr = traversalPtr->right;
												}

												struct TypeTable* lastFieldType = traversalPtr->typeTablePtr;
												traversalPtr->nodeType = FIELD_NODE;

												if(lastFieldType == typeTableINTPtr || lastFieldType == typeTableSTRPtr){
													printf("\n. operator cannot be used for non User Defined variable\n");
													exit(1);
												}
												
												struct FieldList* fieldListEntry = FLLookUp(lastFieldType, $3->nodeName);

												// if field is not present in the field list
												if(fieldListEntry == NULL){
													printf("\nUndeclared field \"%s\" used in variable %s\n", $3->nodeName, traversalPtr->nodeName);
													exit(1);
												}

												$3->typeTablePtr = fieldListEntry->type;
												traversalPtr->right = $3;
												$$ = $1;
												$$->typeTablePtr = $3->typeTablePtr;
											}
				|	StructID '.' ID			{
												// Checking if ID($1) exists in LST or GST
												$1 = lookupID($1);

												if ($1->typeTablePtr->typeCategory == TYPE_USER_DEFINED)
													$1->nodeType = FIELD_NODE;

												else if ($1->typeTablePtr->typeCategory == TYPE_TUPLE)
													$1->nodeType = TUPLE_NODE;
												
												else {
													printf("\n. operator cannot be used for non User Defined variable\n");
													exit(1);
												}

												struct FieldList* fieldListEntry = FLLookUp($1->typeTablePtr, $3->nodeName);

												// if field is not present in the field list
												if(fieldListEntry == NULL){
													printf("\nUndeclared field \"%s\" used in variable %s\n", $3->nodeName, $1->nodeName);
													exit(1);
												}

												$3->typeTablePtr = fieldListEntry->type;
												$1->right = $3;
												$$ = $1;
												$$->typeTablePtr = $3->typeTablePtr;
											}
				;

StructID		:	ID						{ $$ = $1; }
				|	ID '[' expr ']'			{
												$$ = $1;
												$$->left = $3;
											}				

 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


expr		: expr PLUS expr		{ $$ =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr MINUS expr 		{ $$ =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr MUL expr 		{ $$ =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr DIV expr			{ $$ =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr MOD expr			{ $$ =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr EQ expr			{ $$ =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr NEQ expr			{ $$ =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr LT expr			{ $$ =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr LTE expr			{ $$ =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr GT expr			{ $$ =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr GTE expr			{ $$ =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr AND expr			{ $$ =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| expr OR expr			{ $$ =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, $1, NULL, $3); }
			| NOT expr				{ $$ =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, $2, NULL, NULL); }
			| '(' expr ')'			{ $$ = $2; }
			| StructField			{ $$ = $1; }
			| ID '(' ArgList ')'	{ 
										// check if ID is a type constructor
										struct TypeTable* idTTEntry = TTLookUp($1->nodeName);

										// if its a Tuple Constructor		
										if (idTTEntry != NULL && idTTEntry->typeCategory == TYPE_TUPLE){
											verifyTupleFields(idTTEntry, $3);
											$$ = TreeCreate(idTTEntry, TUPLE_CONSTRUCTOR_NODE, $1->nodeName, INT_MAX, NULL, NULL, NULL, NULL);
											$$->argListHead = $3;
										}

										// if its a function
										if(idTTEntry == NULL){
											$1 = lookupID($1);	
											verifyFunctionArguments($1->nodeName, $3);	
											$$ = TreeCreate(getFunctionType($1->nodeName), FUNC_NODE, $1->nodeName, INT_MAX, NULL, NULL, NULL, NULL); 
											$$->argListHead = $3;
											$$->GSTEntry = $1->GSTEntry;
										}
									}
			| ID '[' expr ']' 		{	
										$1 = lookupID($1);
										if ($3->typeTablePtr != typeTableINT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										$1->left = $3;	
										$$ = $1;
									}
			| AMPERSAND ID			{
										$2 = lookupID($2);
										if ($2->typeTablePtr == typeTableINT || $2->typeTablePtr == typeTableINTPtr)
											$$ = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, $2, NULL, NULL);

										if ($2->typeTablePtr == typeTableSTR || $2->typeTablePtr == typeTableSTRPtr)
											$$ = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, $2, NULL, NULL);	
									}
			| MUL ID				{
										$2 = lookupID($2);
										if ($2->typeTablePtr == typeTableINTPtr)
											$$ = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, $2, NULL);

										if ($2->typeTablePtr == typeTableSTRPtr)
											$$ = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, $2, NULL);	
									}
			| ID					{
										$1 = lookupID($1);
										$$ = $1;
									}
			| NUM					{$$ = $1;}
			| STRING				{$$ = $1;}
			| NULL_					{$$ = $1;}
			;

%%

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at statement %d\n", s, statementCount);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yydebug = 0;
		filePtr = fopen("../Target_Files/round1.xsm", "w");
		writeXexeHeader(filePtr);
		TypeTableCreate();
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
