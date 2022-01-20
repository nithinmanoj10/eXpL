#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Frontend/ast.h"
#include "LSTable.h"
#include "GSTable.h"
#include "paramStruct.h"
#include "../Data_Structures/typeTable.h"

struct LSTNode *LSTHead = NULL;
struct LSTNode *LSTTail = NULL;

struct FunctionLSTTable *FLTHead = NULL;
struct FunctionLSTTable *FLTTail = NULL;

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
    newLSTNode->binding = 0;
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

    printf("%p\n", traversalPtr);

    while (traversalPtr != NULL)
    {
        printf("%s %s %d\n", (traversalPtr->type == TYPE_INT) ? ("int") : ("str"), traversalPtr->name, traversalPtr->binding);
        traversalPtr = traversalPtr->next;
    }

    printf("\n\n");
}

int getLSTSize()
{
    if (LSTHead == NULL && LSTTail == NULL)
        return 0;

    struct LSTNode *traversalPtr = LSTHead;
    int size = 0;

    while (traversalPtr != NULL)
    {
        ++size;
        traversalPtr = traversalPtr->next;
    }

    return size;
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

struct FunctionLSTTable *addFunctionLST(char *funcName, struct LSTNode *funcLST)
{
    if (getFunctionLST(funcName) != NULL)
        return NULL;

    struct FunctionLSTTable *newFLTNode = (struct FunctionLSTTable *)malloc(sizeof(struct FunctionLSTTable));
    newFLTNode->funcName = (char *)malloc(sizeof(funcName));

    strcpy(newFLTNode->funcName, funcName);
    newFLTNode->funcLST = funcLST;
    newFLTNode->next = NULL;

    if (FLTHead == NULL && FLTTail == NULL)
    {
        FLTHead = newFLTNode;
        FLTTail = newFLTNode;
        return newFLTNode;
    }

    FLTTail->next = newFLTNode;
    FLTTail = newFLTNode;

    return newFLTNode;
}

struct LSTNode *getFunctionLST(char *funcName)
{
    if (FLTHead == NULL)
        return NULL;

    struct FunctionLSTTable *traversalPtr = FLTHead;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->funcName, funcName) == 0)
            return traversalPtr->funcLST;
        traversalPtr = traversalPtr->next;
    }

    return NULL;
}

int printFLT()
{
    struct FunctionLSTTable *traversalPtr = FLTHead;

    printf("\nFunction-LST Table -----------------------------\n\n");

    while (traversalPtr != NULL)
    {
        printf("%s: %p\n", traversalPtr->funcName, traversalPtr->funcLST);
        traversalPtr = traversalPtr->next;
    }

    printf("\n------------------------------------------------\n");

    return 0;
}