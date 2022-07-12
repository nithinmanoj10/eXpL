%{
	// Lex program to count the number of integers and floating point numbers appearing in the input

	#include <stdio.h>
	#include <stdlib.h>
	#include <wchar.h>
	#include <locale.h>
	
	int intCount = 0, floatCount = 0;
%}

%option noyywrap

positiveInteger [+]?[0-9]+
negativeInteger [-][1-9]+
positiveFloat [+]?[0-9]+\.[0-9]+
negativeFloat [-][0-9]+\.[0-9]+

%%

{positiveInteger} {++intCount;}
{negativeInteger} {++intCount;}
{positiveFloat} {++floatCount;}
{negativeFloat} {++floatCount;}

%%

int main(){

	setlocale(LC_ALL, "en_US.utf8");
	const wchar_t codeEmoji = 0x1F4D1;
	const wchar_t stageEmoji = 0x1F4C0;
	const wchar_t inputEmoji = 0x1F4E5;
	const wchar_t resultEmoji = 0x2728;
	const wchar_t diamondEmoji = 0x1F539;

	printf("%lc Stage 0 : Lex Tutorial\n", stageEmoji);
	printf("\n%lc Lex Program to count the number of integers and floating point numbers appearing in the input\n", codeEmoji);
	printf("\n%lc Input integers or float numbers. ctrl+d to get the result\n\n", inputEmoji);

	yylex();

	printf("\n%lc Result:\n\n", resultEmoji);
	printf("%lc Number of Integers: %d\n", diamondEmoji, intCount);
	printf("%lc Number of Floats: %d\n", diamondEmoji, floatCount);
	return 1;
}
