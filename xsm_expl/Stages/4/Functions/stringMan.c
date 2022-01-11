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
