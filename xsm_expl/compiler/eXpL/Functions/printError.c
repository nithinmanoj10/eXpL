#include <stdio.h>
#include <stdlib.h>
#include "printError.h"

int errorLineNumber = 0;
char *errorInputFileName = NULL;

void printError(int errorType, char *errorMessage)
{

    printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET ": %s in ", getErrorName(errorType), errorMessage);
    printf(ANSI_COLOR_CYAN "%s:%d\n" ANSI_COLOR_RESET, errorInputFileName, errorLineNumber);
}

char *getErrorName(int errorType)
{

    if (errorType == ERR_TYPE)
        return "Type Error";

    if (errorType == ERR_FUNC)
        return "Function Error";
}