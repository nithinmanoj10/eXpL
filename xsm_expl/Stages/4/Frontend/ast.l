%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	#include "ast.h"
	#include "../Data_Structures/declarationsTree.h"
	#include "../Functions/stringMan.h"

	int yywrap();
	char* getString(char* ogString);
	int line = 0;
%}

%%

"begin" 			{ECHO; return BEGIN_;}	/* Keywords */
"end" 				{ECHO; return END;}
"decl"				{ECHO; return DECL;}
"enddecl"			{ECHO; return ENDDECL;}
"int"					{ECHO; return INT;}
"str"					{ECHO; return STR;}
"breakpoint"	{ECHO; return BREAKPOINT;}

"read" 	{ECHO; return READ;}		/* Functions */
"write" {ECHO; return WRITE;}

"if"		{ECHO; return IF;}		/* Control Flow */
"then"		{ECHO; return THEN;}
"else"		{ECHO; return ELSE;}
"endif"		{ECHO; return ENDIF;}
"while"		{ECHO; return WHILE;}
"do"		{ECHO; return DO;}
"endwhile"	{ECHO; return ENDWHILE;}
"break"		{ECHO; return BREAK;}
"continue"	{ECHO; return CONTINUE;}

[a-zA-Z][a-zA-Z0-9]*	{			/* Variables and Numbers */
	ECHO;
	// if declaration of all variables are done and
	// the given variable is not declared
	if (getDeclarationStatus() == 1 && searchGSTNode(yytext) == NULL) {
		printf("\n❌ There are undeclared variables in the program\n");
		exit(1);
	}

			yylval.node = createASTNode(0, 1, 2, yytext, -1, NULL, NULL, NULL);
			return VARIABLE;
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


[0-9]+	{ECHO;
		yylval.node = createASTNode(atoi(yytext), 1, 1, "N", -1, NULL, NULL, NULL);
		return NUM;
	}




["][a-zA-Z0-9" "]*["] {	/* For strings */
		ECHO;char* stringConst = removeStringQuotes(yytext);
		yylval.node = createASTNode(0, 3, 9, stringConst, -1, NULL, NULL, NULL);
		 //ntf("\nString: %s\n", yytext);
		return STRING;
}

"+"		{ECHO;return PLUS;}		/* Operators */
"-"		{ECHO;return MINUS;}
"*"		{ECHO;return MUL;}
"/"		{ECHO;return DIV;}
"="		{ECHO;return EQUAL;}
"%"		{ECHO;return MOD;}

"=="	{ECHO;return EQ;}		/* Conditional Operators */
"!="	{ECHO;return NEQ;}
"<"		{ECHO;return LT;}
">"		{ECHO;return GT;}
"<="	{ECHO;return LTE;}
">="	{ECHO;return GTE;}

[()\[\]]	{ECHO;return *yytext;}	/* Others */
[ \t]		{ECHO;}
[\r\n]		{ECHO;++line;}
";"			{ECHO;return SEMICOLON;}
","			{ECHO;return COMMA;}
.	{
		ECHO;
		printf("\n%s", yytext);
		printf("\n❓ Unidentified Token, at line %d\n", line+1);
		exit(1);
	}

[ \t]*\/\/.* {}			/* Comments */

%%

int yywrap(){
	return 1;
}
