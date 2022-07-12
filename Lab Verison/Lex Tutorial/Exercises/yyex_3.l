%{
	// Lex program to list out all words of length three, starting with "A" to uppercase

	#include <stdio.h>
	#include <stdlib.h>
	#include <wchar.h>
	#include <locale.h>

%}

%option noyywrap

word [A][a-zA-Z0-9]*

%%

{word} {
	setlocale(LC_ALL, "en_US.utf8");
	const wchar_t correctEmoji = 0x2705;
	const wchar_t wrongEmoji = 0x274c;

	if(yyleng == 3)
		printf("%lc %s", correctEmoji,yytext);
	else
		printf("%lc %s", wrongEmoji,yytext);
} 

(.)* {
	setlocale(LC_ALL, "en_US.utf8");
	const wchar_t wrongEmoji = 0x274c;
	printf("%lc %s", wrongEmoji,yytext);
} 

%%

int main(){

	setlocale(LC_ALL, "en_US.utf8");
	const wchar_t codeEmoji = 0x1F4D1;
	const wchar_t stageEmoji = 0x1F4C0;
	const wchar_t inputEmoji = 0x1F4E5;
	const wchar_t resultEmoji = 0x2728;
	const wchar_t diamondEmoji = 0x1F539;

	printf("%lc Stage 0 : Lex Tutorial\n", stageEmoji);
        printf("\n%lc Lex program to list out all words of length three, starting with 'A' to uppercase\n\n", codeEmoji);

	FILE* fp = fopen("input_3.txt", "r");
	if(fp)
		yyin = fp;

	yylex();
	return 1;
}
