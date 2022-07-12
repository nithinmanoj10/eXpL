#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paramStruct.h"
#include "typeTable.h"
#include "GSTable.h"

struct ParamStruct *paramListHead = NULL;
struct ParamStruct *paramListTail = NULL;

struct TypeTable *currentParamType = NULL;

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

struct ParamStruct *paramListInstall(struct TypeTable *typeTablePtr, char *paramName)
{

    if (paramListLookup(typeTablePtr, paramName) != NULL)
    {
        printf("\nSame function parameters (%s) not allowed\n", paramName);
        exit(1);
        return NULL;
    }

    struct ParamStruct *newParamStruct = (struct ParamStruct *)malloc(sizeof(struct ParamStruct));
    newParamStruct->paramName = (char *)malloc(sizeof(paramName));

    newParamStruct->typeTablePtr = typeTablePtr;
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

struct ParamStruct *paramListLookup(struct TypeTable *typeTablePtr, char *paramName)
{
    struct ParamStruct *traversalPtr = paramListHead;

    while (traversalPtr != NULL)
    {
        if (traversalPtr->typeTablePtr == typeTablePtr && strcmp(traversalPtr->paramName, paramName) == 0)
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
        printf("%14s%22s\n", traversalPtr->typeTablePtr->typeName, traversalPtr->paramName);
        traversalPtr = traversalPtr->next;
    }

    printf("\n");

    return 0;
}

void printGlobalParamList()
{

    struct GSTNode *traversalPtr = GSTHead;

    printf("\n\n🎁 Param List ----------------------------------------------------------------------\n\n");

    while (traversalPtr != NULL)
    {
        if (traversalPtr->binding == -1)
        {
            printf("\nParam List for %s - %p\n\n", traversalPtr->name, traversalPtr->paramList);
            printf("          Type            Param Name\n\n");
            printParamList(traversalPtr->paramList);
        }
        traversalPtr = traversalPtr->next;
    }
    printf("------------------------------------------------------------------------------------\n\n");
}
