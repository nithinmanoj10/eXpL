%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	#include "ast.h"
	#include "../Functions/stringMan.h"

	int yywrap();
	char* getString(char* ogString);
	int line = 0;
%}

%%

"begin" 			{ return BEGIN_;}	/* Keywords */
"end" 				{ return END;}
"decl"				{ setDeclarationStatus(DECL_START); return DECL;}
"enddecl"			{ setDeclarationStatus(DECL_END); return ENDDECL;}
"int"				{ return INT;}
"str"				{ return STR;} 
"breakpoint"		{ return BREAKPOINT;}

"read" 	{ return READ;}		/* Functions */
"write" { return WRITE;}

"if"		{ return IF;}		/* Control Flow */
"then"		{ return THEN;}
"else"		{ return ELSE;}
"endif"		{ return ENDIF;}
"while"		{ return WHILE;}
"do"		{ return DO;}
"endwhile"	{ return ENDWHILE;}
"break"		{ return BREAK;}
"continue"	{ return CONTINUE;}

[a-zA-Z][a-zA-Z0-9]*	{			/* Variables and Numbers */
	
	// if declaration of all variables are done and
	// the given variable is not declared
	// if (getDeclarationStatus() == 1 && searchGSTNode(yytext) == NULL) {
	// 	printf("\n❌ There are undeclared variables in the program\n");
	// 	exit(1);
	// }

			// yylval.node = createASTNode(0, 1, 2, yytext, -1, NULL, NULL, NULL);
			yylval.node = TreeCreate(TYPE_VOID, ID_NODE, yytext, 0, NULL, NULL, NULL, NULL);
			return ID;
	}

	/*[a-zA-Z][a-zA-Z0-9]*[\[][0-9]*[\]]	{ 

	char* arrayName = getArrayName(yytext);
	int arrayOffset = getArrayOffset(yytext);

	// declaration of the array is done
	if (getDeclarationStatus() == 1) {

		struct globalSTNode* GSTnode = searchGSTNode(arrayName);
		
		if (GSTnode == NULL) {

			printf("\n❌ Array %s is undeclared\n", arrayName);
			exit(1);
		}

		if (arrayOffset >= GSTnode->size || arrayOffset < 0) {

			printf("\n❌ Array %s out of bounds\n", arrayName);
			exit(1);
		}
	}

	yylval.node = createASTNode(0, 1, 2, arrayName, arrayOffset, NULL, NULL, NULL);

	return ARRAY_VARIABLE;
} */


[0-9]+	{
		// yylval.node = createASTNode(atoi(yytext), 1, 1, "N", -1, NULL, NULL, NULL);
		yylval.node = TreeCreate(TYPE_INT, CONST_INT_NODE, NULL, atoi(yytext), NULL, NULL, NULL, NULL);
		return NUM;
	}




["][a-zA-Z0-9" "]*["] {	/* For strings */
		char* stringConst = removeStringQuotes(yytext);
		// yylval.node = createASTNode(0, 3, 9, stringConst, -1, NULL, NULL, NULL);
		yylval.node = TreeCreate(TYPE_STR, CONST_STR_NODE, NULL, 0, stringConst, NULL, NULL, NULL);
		 //ntf("\nString: %s\n", yytext);
		return STRING;
}

"+"		{return PLUS;}		/* Operators */
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"="		{return EQUAL;}
"%"		{return MOD;}

"=="	{return EQ;}		/* Conditional Operators */
"!="	{return NEQ;}
"<"		{return LT;}
">"		{return GT;}
"<="	{return LTE;}
">="	{return GTE;}

[()\[\]]	{return *yytext;}	/* Others */
[ \t]		{}
[\r\n]		{++line;}
";"			{return SEMICOLON;}
","			{return COMMA;}
.	{
		
		printf("\n%s", yytext);
		printf("\n❓ Unidentified Token, at line %d\n", line+1);
		exit(1);
	}

[ \t]*\/\/.* {}			/* Comments */

%%

int yywrap(){
	return 1;
}
