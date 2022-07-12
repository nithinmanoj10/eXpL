#include <stdio.h>
#include <stdlib.h>
#include "stringMan.h"

char *removeStringQuotes(char *ogString)
{

	char *finalString = malloc(sizeof(char *));
	char *finalStringPtr = finalString;

	while (*ogString != '\0')
	{
		if (*ogString != '"')
		{
			*finalString = *ogString;
			++finalString;
		}
		++ogString;
	}

	return finalStringPtr;
}

char *getArrayName(char *ogString)
{

	char *finalString = malloc(sizeof(char *));
	char *finalStringPtr = finalString;

	while (*ogString != '[')
	{

		*finalString = *ogString;
		++finalString;
		++ogString;
	}

	return finalStringPtr;
}

int getArrayOffset(char *ogString)
{

	char *arrayOffset = malloc(sizeof(char *));
	char *arrayOffsetPtr = arrayOffset;

	while (*ogString != '[')
		++ogString;

	++ogString;

	while (*ogString != ']')
	{
		*arrayOffset = *ogString;
		++arrayOffset;
		++ogString;
	}

	return atoi(arrayOffsetPtr);
}

char *replaceStringLiteral(char *orginalString, int intLiteral, char *strLiteral)
{

	char *finalString = (char *)malloc(sizeof(orginalString));

	char *orginalStringPtr = orginalString;
	char *finalStringPtr = finalString;
	char intCharVal[50];

	while (*orginalStringPtr != '\0')
	{
		if (*orginalStringPtr == '%')
		{
			if (*(orginalStringPtr + 1) == 'd')
			{
				sprintf(intCharVal, "%d", intLiteral);
				*finalStringPtr = *intCharVal;
			}

			if (*(orginalStringPtr + 1) == 's')
				*finalStringPtr = *strLiteral;

			++finalStringPtr;
			++orginalStringPtr;
			++orginalStringPtr;
		}
		else
		{
			*finalStringPtr = *orginalStringPtr;
			++finalStringPtr;
			++orginalStringPtr;
		}
	}

	return finalString;
}