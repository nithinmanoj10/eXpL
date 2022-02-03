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

"main"				{ return MAIN; }
"begin" 			{ return BEGIN_;}	/* Keywords */
"end" 				{ return END;}
"decl"				{ setDeclarationStatus(DECL_START); return DECL;}
"enddecl"			{ setDeclarationStatus(DECL_END); return ENDDECL;}
"int"				{ return INT;}
"str"				{ return STR;}
"tuple"				{ return TUPLE; } 
"breakpoint"		{ return BREAKPOINT;}
"return"			{ return RETURN; }
"AND"				{ return AND; }
"OR"				{ return OR; }
"NOT"				{ return NOT;}
"type"				{ return TYPE;}
"endtype"			{ return ENDTYPE;}

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


[a-zA-Z][a-zA-Z0-9]*	{	
							yylval.node = TreeCreate(TYPE_VOID, ID_NODE, yytext, 0, NULL, NULL, NULL, NULL);
							return ID;
						}



[0-9]+	{
			yylval.node = TreeCreate(TYPE_INT, CONST_INT_NODE, NULL, atoi(yytext), NULL, NULL, NULL, NULL);
			return NUM;
		}




["][a-zA-Z0-9" "]*["] 	{	
							char* stringConst = removeStringQuotes(yytext);
							yylval.node = TreeCreate(TYPE_STR, CONST_STR_NODE, NULL, 0, stringConst, NULL, NULL, NULL);
							return STRING;
						}

"+"		{return PLUS;}		/* Operators */
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"="		{return EQUAL;}
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
