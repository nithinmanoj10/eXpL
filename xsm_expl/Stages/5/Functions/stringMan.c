#include <stdlib.h>
#include "stringMan.h"

char* removeStringQuotes(char* ogString) {

	char* finalString = malloc(sizeof(char*));
	char* finalStringPtr = finalString;

	while (*ogString != '\0') {
		if (*ogString != '"') {
			*finalString = *ogString;
			++finalString;
		}
		++ogString;
	}

	return finalStringPtr;
}

char* getArrayName(char* ogString) {

	char* finalString = malloc(sizeof(char*));
	char* finalStringPtr = finalString;

	while (*ogString != '[') {

		*finalString = *ogString;
		++finalString;
		++ogString;
	}

	return finalStringPtr;
}

int getArrayOffset(char* ogString) {

	char* arrayOffset = malloc(sizeof(char*));
	char* arrayOffsetPtr = arrayOffset;

	while (*ogString != '[')
		++ogString;

	++ogString;

	while (*ogString != ']') {
		*arrayOffset = *ogString;
		++arrayOffset;
		++ogString;
	}

	return atoi(arrayOffsetPtr);

}
