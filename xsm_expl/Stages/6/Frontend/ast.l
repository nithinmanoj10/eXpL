%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>
	#include "y.tab.h"
	#include "ast.h"
	#include "../Functions/stringMan.h"
	#include "../Data_Structures/typeTable.h"

	int yywrap();
	char* getString(char* ogString);
	int line = 0;
%}

%%

"main"				{ return MAIN; }
"begin" 			{ return BEGIN_;}	/* Keywords */
"end" 				{ return END;}
"decl"				{ setDeclarationStatus(DECL_START); return DECL;}
"enddecl"			{ setDeclarationStatus(DECL_END); return ENDDECL;}
"int"				{ return INT;}
"str"				{ return STR;}
"breakpoint"		{ return BREAKPOINT;}
"return"			{ return RETURN; }
"AND"				{ return AND; }
"OR"				{ return OR; }
"NOT"				{ return NOT;}
"type"				{ return TYPE;}
"endtype"			{ return ENDTYPE;}
"null"				{ 
						yylval.node = TreeCreate(typeTableVOID, NULL_NODE, NULL, INT_MAX, "null", NULL, NULL, NULL);
						return NULL_;
					}

"read" 				{ return READ;}		/* Functions */
"write" 			{ return WRITE;}
"alloc"				{ 
						yylval.node = TreeCreate(typeTableVOID, ALLOC_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL);
						return ALLOC;
					}
"free"				{ 
						yylval.node = TreeCreate(typeTableINT, FREE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL);
						return FREE;
					}
"initialize" 		{ 
						yylval.node = TreeCreate(typeTableINT, INITIALIZE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL);
						return INITIALIZE;
					}

"tuple"				{ return TUPLE;}

"if"		{ return IF;}		/* Control Flow */
"then"		{ return THEN;}
"else"		{ return ELSE;}
"endif"		{ return ENDIF;}
"while"		{ return WHILE;}
"do"		{ return DO;}
"endwhile"	{ return ENDWHILE;}
"break"		{ return BREAK;}
"continue"	{ return CONTINUE;}


[a-zA-Z][a-zA-Z0-9_]*	{	
							// ECHO;
							yylval.node = TreeCreate(typeTableVOID, ID_NODE, yytext, INT_MAX, NULL, NULL, NULL, NULL);
							return ID;
						}



[0-9]+	{
			yylval.node = TreeCreate(typeTableINT, CONST_INT_NODE, NULL, atoi(yytext), NULL, NULL, NULL, NULL);
			return NUM;
		}




["][a-zA-Z0-9" "]*["] 	{	
							char* stringConst = removeStringQuotes(yytext);
							yylval.node = TreeCreate(typeTableSTR, CONST_STR_NODE, NULL, INT_MAX, stringConst, NULL, NULL, NULL);
							return STRING;
						}

"+"		{return PLUS;}		/* Operators */
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"="		{return *yytext;}
"%"		{return MOD;}
"&"		{return AMPERSAND;}

"=="	{return EQ;}		/* Conditional Operators */
"!="	{return NEQ;}
"<"		{return LT;}
">"		{return GT;}
"<="	{return LTE;}
">="	{return GTE;}

[()\[\]\{\}]	{return *yytext;}	/* Others */
[ \t]		{}
[\r\n]		{}

"."			{ return *yytext;}
";"			{ return *yytext;}
","			{ return *yytext;}

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
