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
	#include "../Data_Structures/classTable.h"
	#include "../Data_Structures/memberFuncList.h"
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
	int isFuncDef = 0;
	char* fileName;
	FILE* filePtr;
%}

%start start

%union {
	struct ASTNode* node;
	struct LSTNode* lstnode;
	struct TypeTable* TTNode;
	struct FieldList* FLNode;
	struct ClassTable* CTNode;
	struct MemberFuncList* MFLNode;
}

%type <node> start Slist Stmt inputStmt outputStmt assignStmt ifStmt ID FID expr NUM STRING whileStmt doWhileStmt breakStmt continueStmt breakPointStmt retStmt retVal MBody FBody Arg ArgList GPtrID Field INITIALIZE InitializeStmt ALLOC AllocStmt FREE FreeStmt NULL_ DynaMemID FieldID TupleFieldName  
%type <TTNode> TypeName TypeID GType LType TupleFieldType ClassDef
%type <FLNode> FieldDecl FieldDeclList TupleFieldDecl TupleFieldDeclList TupleDecl
%type <CTNode> ClassName ClassMembers

%token BEGIN_ END MAIN READ WRITE ID NUM STRING PLUS MINUS MUL DIV MOD AMPERSAND BREAKPOINT TYPE ENDTYPE TUPLE
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE AND OR NOT
%token DECL ENDDECL INT STR RETURN NULL_
%token ALLOC FREE INITIALIZE ',' ')' SELF
%token CLASS ENDCLASS

%left '='
%left '.'
%left '('
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
start 	: TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock	{}
		| TypeDefBlock ClassDefBlock GDeclBlock MainBlock			{}	
		| TypeDefBlock GDeclBlock MainBlock 						{}
		| TypeDefBlock GDeclBlock FDefBlock MainBlock 				{}
		| TypeDefBlock GDeclBlock 									{	
																		printf("\n⛔ No Code Provided\n");
																		exit(1);
																	};
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Type Definition Block ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

TypeDefBlock	:	TYPE TypeDefList ENDTYPE	{ printTypeTable(); }
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

													FLPrint($1->typeName); 
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
													$$ = FLCreateNode($2->nodeName, $1, currentFieldCType); 
													++typeFieldCount;
													currentFieldCType = NULL;
												}
				;

TypeName		:	INT							{ $$ = TTLookUp("int"); }
				|	STR							{ $$ = TTLookUp("str"); }
				|	ID							{ 
													$$ = TTLookUp($1->nodeName); 

													// if it's a class type
													if ($$ == NULL) {
														currentFieldCType = CTLookUp($1->nodeName);

														if (currentFieldCType == NULL) {
															printf("\nType Error: Unknown type %s\n", $1->nodeName);
															exit(1);
														}
													}
												}
				;	

 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

 /* Class Definitions ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

ClassDefBlock	:	CLASS ClassDefList ENDCLASS		{ CTPrint(); }								
				;	

ClassDefList	:	ClassDefList ClassDef			{}
				|	ClassDef						{}
				;

ClassDef		:	ClassName '{'
						ClassMembers
						MethodDefns
					'}'								{ 
														FLPrint($1->className);
														MFLPrint($1->className);

														// adding the class to the Type Table
														if (typeFieldCount > 8) {
															printf("\nError: Class %s has more than 8 fields\n", $1->className);
															exit(1);	
														}
														// $$ = TTInstall($1->className, typeFieldCount, $1->memberField);
														// $$->typeCategory = TYPE_CLASS;

														fieldListTail = NULL;
														fieldListHead = NULL;
														typeFieldCount = 0;

														memFuncListHead = NULL;
														memFuncListTail = NULL;
														currentClassTable = NULL;
					 								}
				;

ClassMembers	:	DECL
						FieldDeclList
						MethodDeclList
					ENDDECL							{
														currentClassTable->memberField = $2;
														currentClassTable->virtualFunctionPtr = memFuncListHead;
														currentClassTable->fieldCount = fieldListTail->fieldIndex + 1;
														currentClassTable->methodCount = memFuncListTail->funcPosition;
													}	
				;

ClassName		:	ID								{ 
														$$ = CTInstall($1->nodeName, NULL);
														currentClassTable = $$;
													}
				;

MethodDeclList	:	MethodDeclList MethodDecl		{}
				|	MethodDecl						{}
				;

MethodDecl		:	TypeName ID'('ParamList')'';'	{ 
														MFLInstall($2->nodeName, $1, paramListHead);
														//  printParamList(paramListHead); 
														flushParamList();
													}
				;

MethodDefns		:	FDefBlock						{}
				;

 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

Slist		: 	Slist Stmt ';' 					{ $$ = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, $1, NULL, $2); }
			| 	Stmt ';'						{}				
			;

Stmt		: 	inputStmt | outputStmt | assignStmt 
			| 	ifStmt | whileStmt | doWhileStmt
   			| 	breakStmt | continueStmt	
			| 	breakPointStmt
			| 	DynamicMemStmt					{ ++statementCount; }
			;

inputStmt	: 	READ expr	 					{ $$ = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, $2, NULL, NULL); }
	  		;

outputStmt 	: 	WRITE expr 						{ $$ = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, $2, NULL, NULL); }
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
			| 	Field '=' expr					{
													if (currentClassTable == NULL) {

														struct ClassTable* classType = GSTLookup($1->nodeName)->classTablePtr;
														struct ASTNode* fieldNode = $1;

														while (fieldNode->right != NULL)
															fieldNode = fieldNode->right;	

														if (isFuncDef && verifyClassField(classType, fieldNode->nodeName)) {
															printf("Class Error: Can't access class field '%s' outside of class '%s'\n", fieldNode->nodeName, classType->className);
															exit(1);
														}	
													}

													$$ = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, $1, NULL, $3);
												}
	   		;


 /* Return Statement ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
retVal		:	expr				{}
			;

retStmt		: 	RETURN retVal ';'	{ $$ = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, $2, NULL, NULL); }
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
												GSTPrint(); 
												printTypeTable();					
												initStackBP(filePtr);
												printGlobalParamList();
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

												FLPrint($1->typeName);

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentGDeclType = NULL;
												currentCDeclType = NULL;
												tupleFieldCount = 0;
											}
			;

GType		:	INT							{ currentGDeclType = TTLookUp("int"); }
			|	STR							{ currentGDeclType = TTLookUp("str"); }
			|	ID							{ 
												// for user-defined types						
												currentGDeclType = TTLookUp($1->nodeName);
												if(currentGDeclType == NULL) {

													// for class types
													currentCDeclType = CTLookUp($1->nodeName);

													if (currentCDeclType == NULL) {
														printf("\nType %s undeclared before use\n", $1->nodeName);
														exit(1);
													}
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
												int varSize;

												if (currentGDeclType != NULL)
													varSize = (currentGDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentGDeclType->size);
												if (currentCDeclType != NULL)
													varSize = currentCDeclType->fieldCount;	

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
																	$$ = FLCreateNode($2->nodeName, $1, NULL);
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
															// Check for function in GST		
															if(GSTLookup($1->nodeName) == NULL){

																if (currentClassTable == NULL) {
																	printf("\nFunction %s() not declared globally\n", $1->nodeName);
																	exit(1);
																}
															
																// if not in GST, search in current Class Table
																if (MemberFuncLookUp(currentClassTable, $1->nodeName) == NULL) {
																	printf("\nFunction %s() not declared in class %s\n", $1->nodeName, currentClassTable->className);
																	exit(1);
																}

															}
															$$ = $1; 
															setCurrentFuncName($1->nodeName);
														}
			;

FDef		:	FuncSign
				'{' LDeclBlock FBody '}'				{
															char* currentFuncName = getCurrentFuncName();

															// // TODO: Pls check!!!
															// // addFunctionLST(currentFuncName, LSTHead);	
															
															// fprintf(filePtr, "F%d:\n", GSTLookup(currentFuncName)->fLabel);
															// initFuncCalle(filePtr, paramCount);

															// printASTTable($4, 0);
															// codeGen($4, filePtr);

															LSTPrint();
															flushLST();
															paramCount = 0;
															
														}
			;

FuncSign	:	FuncType FID '(' ParamList ')'			{
															verifyFunctionSignature($2->nodeName);
															// LSTAddParams();
															flushParamList();
														}

FuncType	:	INT										{ currentFDefType = TTLookUp("int"); }
			|	STR										{ currentFDefType = TTLookUp("str"); }
			|	INT MUL									{ currentFDefType = TTLookUp("int*"); }
			|	STR MUL									{ currentFDefType = TTLookUp("str*"); }
			|	ID										{ currentFDefType = TTLookUp($1->nodeName); }
			;

FBody		:	BEGIN_ Slist retStmt END ';'			{
															struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, $2, NULL, $3);
															$$ = funcBodyStmt;
															isFuncDef = 0;
														}	
			;
 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */


 /* Local Declarations ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
LDeclBlock	:	DECL LDeclList ENDDECL	{  
											// printTupleList();
											isFuncDef = 1;	
										}
			|	DECL ENDDECL			{ isFuncDef = 1; }
			|							{ isFuncDef = 1; }
			;

LDeclList	:	LDeclList LDecl			{}
			|	LDecl					{}
			;

LDecl		:	LType LIDList ';'			{}
			|	LType TupleDecl LIDList ';'	{
												$1->typeCategory = TYPE_TUPLE;				
												$1->fields = $2; 
												$1->size = tupleFieldCount;

												FLPrint($1->typeName);

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

														printASTTable($6, 0);
														codeGen($6, filePtr);
														LSTPrint();
														flushLST();
														paramCount = 0;
												
														// printFLT();
													}
			;

MainFunc	:	INT MAIN							{ setCurrentFuncName("int main"); }
			;

MBody		:	BEGIN_ Slist retStmt END ';'		{
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

 /* Class Field Functions ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

FieldFunction	:	Field '(' ArgList ')'			{
														// verify whether the user passed the right arguments for 
														// a class member function
														struct ASTNode* classVariablePtr = $1;
														struct ASTNode* classFunctionPtr = $1->right;

														// if (classVariablePtr->nodeType == SELF_NODE) {
														// 	verifyClassFuncArgs(classVariablePtr, $3);
														// }
														// else {
															while (classFunctionPtr->right != NULL) {
																classVariablePtr = classVariablePtr->right;
																classFunctionPtr = classFunctionPtr->right;
															}

															verifyClassFuncArgs(classVariablePtr, $3);
														// }
													}
				;	

 /* ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */
 /* Struct Fields ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― */

Field			:	Field '.' ID		{
												struct ASTNode* traversalPtr = $1;
												while (traversalPtr->right != NULL){
													traversalPtr = traversalPtr->right;
												}

												printf("\nLast field: %s\n", traversalPtr->nodeName);

												struct TypeTable* lastFieldType = traversalPtr->typeTablePtr;
												struct ClassTable* lastFieldClassType = traversalPtr->classTablePtr;

												traversalPtr->nodeType = FIELD_NODE;

												if(lastFieldType == typeTableINTPtr || lastFieldType == typeTableSTRPtr){
													printf("\n. operator cannot be used for non User Defined variable\n");
													exit(1);
												}
												
												// for non-Class fields
												if (lastFieldClassType == NULL) {

													struct FieldList* fieldListEntry = FLLookUp(lastFieldType, NULL,$3->nodeName);

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
												else if (lastFieldClassType != NULL) {

													// check if the field belongs to the class
													struct FieldList* fieldListEntry = FLLookUp(NULL, lastFieldClassType, $3->nodeName);
													struct MemberFuncList* funcListEntry = MemberFuncLookUp(lastFieldClassType, $3->nodeName); 

													if (fieldListEntry != NULL){
														printf("\nIt is a class field member\n");

														$3->typeTablePtr = fieldListEntry->type;
														$3->classTablePtr = fieldListEntry->classType;
														traversalPtr->right = $3;
														$$ = $1;
														$$->typeTablePtr = $3->typeTablePtr;
														$$->classTablePtr = $3->classTablePtr;
													}
													else if (funcListEntry != NULL){
														printf("\nIt is a class function member\n");

														$3->typeTablePtr = funcListEntry->funcType;
														$3->classTablePtr = NULL;
														traversalPtr->right = $3;
														$$ = $1;
														$$->typeTablePtr = $3->typeTablePtr;
														$$->classTablePtr = $3->classTablePtr;
													}
													else {
														printf("\nClass Error: Unknown class member %s in %s.%s\n", $3->nodeName, $1->nodeName, $3->nodeName);
														exit(1);
													}
												}
											}
				|	FieldID '.' ID			{
												// Checking if ID($1) exists in LST or GST
												$1 = lookupID($1);

												int isClassVariable = ($1->classTablePtr == NULL) ? (0) : (1);

												// for non-class variables
												if ($1->typeTablePtr != NULL) {
													if ($1->typeTablePtr->typeCategory == TYPE_USER_DEFINED)
														$1->nodeType = FIELD_NODE;

													else if ($1->typeTablePtr->typeCategory == TYPE_TUPLE)
														$1->nodeType = TUPLE_NODE;
													
													else {
														printf("\n. operator can only be used for User-Defined and class variables\n");
														exit(1);
													}
												}

												// // if it is not a class variable
												// if ($1->classTablePtr == NULL || ) {
												// 	printf("\n. operator can only be used for User-Defined and class variables 1\n");
												// 	exit(1);
												// }
												// else {
												// 	$1->nodeType = FIELD_NODE;
												// }

												// for non-class variables i.e tuples and user-defined
												if (!isClassVariable){
													struct FieldList* fieldListEntry = FLLookUp($1->typeTablePtr, NULL,$3->nodeName);

													// if field is not present in the field list
													if(fieldListEntry == NULL){
														printf("\nUndeclared field \"%s\" used in variable %s\n", $3->nodeName, $1->nodeName);
														exit(1);
													}

													$3->typeTablePtr = fieldListEntry->type;
													$3->classTablePtr = NULL;
													$1->right = $3;
													$$ = $1;
													$$->typeTablePtr = $3->typeTablePtr;
													$$->classTablePtr = NULL;
												}								

												// for class variable
												if (isClassVariable) {

													// check if the field belongs to the class
													struct FieldList* fieldListEntry = FLLookUp(NULL, $1->classTablePtr, $3->nodeName);
													struct MemberFuncList* funcListEntry = MemberFuncLookUp($1->classTablePtr, $3->nodeName); 
													$1->nodeType = FIELD_NODE;

													if (fieldListEntry != NULL){
														printf("\nIt is a class field member\n");

														$3->typeTablePtr = fieldListEntry->type;
														$3->classTablePtr = fieldListEntry->classType;
														$1->right = $3;
														$$ = $1;
														$$->typeTablePtr = $3->typeTablePtr;
														$$->classTablePtr = $3->classTablePtr;
													}
													else if (funcListEntry != NULL){
														printf("\nIt is a class function member\n");

														$3->typeTablePtr = funcListEntry->funcType;
														$3->classTablePtr = NULL;
														$1->right = $3;
														$$ = $1;
														$$->typeTablePtr = $3->typeTablePtr;
														$$->classTablePtr = $3->classTablePtr;
													}
													else {
														printf("\nClass Error: Unknown class member %s in %s.%s\n", $3->nodeName, $1->nodeName, $3->nodeName);
														exit(1);
													}
												}
											}
				|	SELF '.' ID				{
												// can only be used inside a class method definiton
												if (currentClassTable == NULL || isFuncDef == 0) {
													printf("\nClass Error: 'self.%s'. Keyword 'self' can only be used in a class function definition\n", $3->nodeName);
													exit(1);
												}	

												$$ = TreeCreate(typeTableVOID, SELF_NODE, NULL, INT_MAX, NULL, NULL, NULL, $3);

												// check if the class field or class method exists
												struct FieldList* fieldListEntry = FLLookUp(NULL, currentClassTable, $3->nodeName);
												struct MemberFuncList* funcListEntry = MemberFuncLookUp(currentClassTable, $3->nodeName);

												if (fieldListEntry != NULL) {
													$3->typeTablePtr = fieldListEntry->type;
													$3->classTablePtr = fieldListEntry->classType;
													$$->typeTablePtr = $3->typeTablePtr;
													$$->classTablePtr = $3->classTablePtr;
												}
												else if (funcListEntry != NULL) {
													$3->typeTablePtr = funcListEntry->funcType;
													$3->classTablePtr = NULL;
													$$->typeTablePtr = $3->typeTablePtr;
													$$->classTablePtr = $3->classTablePtr;
												}
												else {
													printf("\nClass Error: Unknown class member %s in self.%s\n", $3->nodeName, $3->nodeName);
													exit(1);
												}
											}
				;

FieldID			:	ID						{ $$ = $1; }
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
			| Field					{ 
										// struct ASTNode* fieldHead = lookupID($1);

										if (currentClassTable == NULL && $1->classTablePtr != NULL) {

											struct ClassTable* classType = GSTLookup($1->nodeName)->classTablePtr;
											struct ASTNode* fieldNode = $1;

											while (fieldNode->right != NULL)
												fieldNode = fieldNode->right;	

											if (isFuncDef && verifyClassField(classType, fieldNode->nodeName)) {
												printf("Class Error: Can't access class field '%s' outside of class '%s'\n", fieldNode->nodeName, classType->className);
												exit(1);
											}	
										}

										$$ = $1; 
									}
			| FieldFunction			{  }
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

										// checking if the identifier called is a class field called
										// inside a class function definition
										// if (currentClassTable != NULL && isFuncDef == 1) {
										// 	struct FieldList* classField = FLLookUp(NULL, currentClassTable, $1->nodeName);
										// 	struct MemberFuncList* classMemFunc = MemberFuncLookUp(currentClassTable, $1->nodeName);

										// 	if (classField != NULL) {
										// 		printf("\nClass Error: Class member field %s can only be accessed using the self keyword\n", $1->nodeName);
										// 		exit(1);
										// 	}
										// 	else if (classMemFunc != NULL) {
										// 		printf("\nClass Error: Class member function %s() can only be accessed using the self keyword\n", $1->nodeName);
										// 		exit(1);
										// 	}
										// }

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
