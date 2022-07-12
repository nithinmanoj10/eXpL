#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paramStruct.h"

struct ParamStruct *paramListHead = NULL;
struct ParamStruct *paramListTail = NULL;

int paramCount = 0;

struct ParamStruct *getParamListHead()
{
    return paramListHead;
}

struct ParamStruct *getParamListTail()
{
    return paramListTail;
}

int flushParamList()
{
    paramListHead = NULL;
    paramListTail = NULL;
}

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

int printParamList(struct ParamStruct *listHead)
{

    if (listHead == NULL)
    {
        printf("none\n");
        return 1;
    }

    struct ParamStruct *traversalPtr = listHead;

    while (traversalPtr != NULL)
    {
        printf("%s %s, ", (traversalPtr->paramType == 50) ? ("int") : ("str"), traversalPtr->paramName);
        traversalPtr = traversalPtr->next;
    }

    printf("\n");

    return 0;
}