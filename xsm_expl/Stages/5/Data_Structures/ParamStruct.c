#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ParamStruct.h"

struct ParamStruct *paramListHead = NULL;
struct ParamStruct *paramListTail = NULL;

struct ParamStruct *paramListInstall(int paramType, char *paramName)
{

    if (paramListLookup(paramType, paramName) != NULL)
    {
        printf("\nSame function parameters not allowed\n");
        exit(1);
        return NULL;
    }

    struct ParamStruct *newParamStruct = (struct ParamStruct *)malloc(sizeof(struct ParamStruct));
    newParamStruct->paramName = (char *)malloc(sizeof(paramName));

    newParamStruct->paramType = paramType;
    strcpy(newParamStruct->paramName, paramName);
    newParamStruct->next = NULL;

    if (paramListHead == NULL && paramListTail == NULL)
    {
        paramListHead = newParamStruct;
        paramListTail = newParamStruct;
        return newParamStruct;
    }

    paramListTail->next = newParamStruct;
    paramListTail = newParamStruct;

    return newParamStruct;
}

struct ParamStruct *paramListLookup(int paramType, char *paramName)
{
    struct ParamStruct *traversalPtr = paramListHead;

    while (traversalPtr != NULL)
    {
        if (traversalPtr->paramType == paramType && strcmp(traversalPtr->paramName, paramName) == 0)
            return traversalPtr;

        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

int printParamList()
{
    struct ParamStruct *traversalPtr = paramListHead;

    while (traversalPtr != NULL)
    {
        printf("\nParameter Type: %d\n", traversalPtr->paramType);
        printf("\nParameter Name: %s\n", traversalPtr->paramName);
        traversalPtr = traversalPtr->next;
    }

    return 0;
}