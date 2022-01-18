#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTable.h"
#include "GSTable.h"
#include "../Frontend/ast.h"
#include "paramStruct.h"
#include "../Data_Structures/typeTable.h"

struct LSTNode *LSTHead = NULL;
struct LSTNode *LSTTail = NULL;

struct LSTNode *LSTInstall(char *name, int type)
{
    if (LSTLookup(name) != NULL)
    {
        printf("\nVariable %s already declared before\n", name);
        exit(1);
    }

    struct LSTNode *newLSTNode = (struct LSTNode *)malloc(sizeof(struct LSTNode));
    newLSTNode->name = (char *)malloc(sizeof(name));

    strcpy(newLSTNode->name, name);
    newLSTNode->type = type;
    newLSTNode->binding = 1;
    newLSTNode->next = NULL;

    if (LSTHead == NULL && LSTTail == NULL)
    {
        LSTHead = newLSTNode;
        LSTTail = newLSTNode;
        return newLSTNode;
    }

    LSTTail->next = newLSTNode;
    LSTTail = newLSTNode;

    return newLSTNode;
}

struct LSTNode *LSTLookup(char *name)
{
    struct LSTNode *traversalPtr = LSTHead;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->name, name) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

struct LSTNode *LSTPrint()
{

    struct LSTNode *traversalPtr = LSTHead;

    while (traversalPtr != NULL)
    {
        printf("%s %s\n", (traversalPtr->type == TYPE_INT) ? ("int") : ("str"), traversalPtr->name);
        traversalPtr = traversalPtr->next;
    }

    printf("\n\n");
}

int LSTAddParams()
{
    struct ParamStruct *listHead = getParamListHead();

    while (listHead != NULL)
    {
        LSTInstall(listHead->paramName, listHead->paramType);
        listHead = listHead->next;
    }

    return 1;
}

int verifyFunctionSignature(char *funcName)
{

    // check if the function's return type and its parameters
    // and their types are the same. If not same, display
    // error and exit from the program.

    struct GSTNode *funcGSTEntry = GSTLookup(funcName);

    // checking if the return type matches
    if (funcGSTEntry->type != getFuncType())
    {
        printf("\nReturn type for %s() doesn't match one given in declaration\n", funcName);
        exit(1);
    }

    struct ParamStruct *declaredParamList = funcGSTEntry->paramList;
    struct ParamStruct *formalParamList = getParamListHead();

    // checking if the formal parameters and its types matches
    while (declaredParamList != NULL && formalParamList != NULL)
    {
        if (strcmp(declaredParamList->paramName, formalParamList->paramName) != 0 || declaredParamList->paramType != formalParamList->paramType)
        {
            printf("\nFunction parameters for %s() doesn't match one given in declaration\n", funcName);
            exit(1);
        }
        declaredParamList = declaredParamList->next;
        formalParamList = formalParamList->next;
    }

    // if the number of parameters doesn't match
    if (declaredParamList != NULL || formalParamList != NULL)
    {
        printf("\nFunction parameters for %s() doesn't match one given in declaration\n", funcName);
        exit(1);
    }

    return 0;
}

int flushLST()
{
    LSTHead = NULL;
    LSTTail = NULL;

    return 0;
}