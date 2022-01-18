#include <stdlib.h>
#include <string.h>
#include "typeTable.h"
#include "../Frontend/ast.h"

int declarationType = TYPE_VOID;
int paramType = TYPE_VOID;
int funcType = TYPE_VOID;
char *currentFuncName = NULL;

int getDeclarationType()
{
    return declarationType;
}

int setDeclarationType(int type)
{
    declarationType = type;
    return 0;
}

int getParamType()
{
    return paramType;
}

int setParamType(int type)
{
    paramType = type;
    return 0;
}

int getFuncType()
{
    return funcType;
}

int setFuncType(int type)
{
    funcType = type;
    return 0;
}

char *getCurrentFuncName()
{
    return currentFuncName;
}

int setCurrentFuncName(char *newFuncName)
{
    if (currentFuncName == NULL)
        currentFuncName = (char *)malloc(50 * sizeof(char));
    strcpy(currentFuncName, newFuncName);
    return 0;
}