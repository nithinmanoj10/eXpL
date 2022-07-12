#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Frontend/ast.h"
#include "paramStruct.h"
#include "typeTable.h"
#include "classTable.h"
#include "memberFuncList.h"
#include "GSTable.h"
#include "../Functions/label.h"

struct MemberFuncList *memFuncListHead = NULL;
struct MemberFuncList *memFuncListTail = NULL;

struct MemberFuncList *MFLInstall(char *funcName, struct TypeTable *funcType, struct ParamStruct *paramList)
{

    if (MFLLookup(funcName) != NULL)
    {
        printf("\nClass Error: Member function %s() declared more than once in class %s\n", funcName, currentClassTable->className);
        exit(1);
    }

    struct MemberFuncList *newMFLNode = (struct MemberFuncList *)malloc((sizeof(struct MemberFuncList)));
    newMFLNode->funcName = (char *)malloc(sizeof(funcName));

    strcpy(newMFLNode->funcName, funcName);
    newMFLNode->funcType = funcType;
    newMFLNode->paramList = paramList;
    newMFLNode->funcPosition = (memFuncListTail == NULL) ? (1) : (memFuncListTail->funcPosition + 1);
    newMFLNode->funcLabel = getFuncLabel();
    newMFLNode->next = NULL;

    if (memFuncListHead == NULL && memFuncListTail == NULL)
    {
        memFuncListHead = newMFLNode;
        memFuncListTail = newMFLNode;
        return newMFLNode;
    }

    memFuncListTail->next = newMFLNode;
    memFuncListTail = newMFLNode;

    return newMFLNode;
}

struct MemberFuncList *MFLLookup(char *funcName)
{
    struct MemberFuncList *traversalPtr = memFuncListHead;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->funcName, funcName) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

struct MemberFuncList *MemberFuncLookUp(struct ClassTable *classType, char *memberFuncName)
{

    if (classType == NULL)
        return NULL;

    struct MemberFuncList *traversalPtr = classType->virtualFunctionPtr;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->funcName, memberFuncName) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

int verifyClassFuncArgs(struct ASTNode *classVar, struct ASTNode *argList)
{
    struct ASTNode *classMemFuncNode = classVar->right;
    struct ClassTable *classVarType = NULL;

    if (classVar->nodeType == SELF_NODE)
    {
        classVarType = currentClassTable;
    }
    else
    {
        struct GSTNode *GSTEntry = GSTLookup(classVar->nodeName);
        classVarType = (GSTEntry == NULL) ? (classVar->classTablePtr) : (GSTEntry->classTablePtr);
    }

    struct MemberFuncList *classMemFunc = MemberFuncLookUp(classVarType, classMemFuncNode->nodeName);

    // if its not a member function and a member field
    if (classMemFunc == NULL)
    {
        printf("\nClass Method Error: %s class member field '%s' called as a function\n", classVarType->className, classMemFuncNode->nodeName);
        exit(1);
    }

    struct ParamStruct *formalParams = classMemFunc->paramList;
    struct ASTNode *actualParams = argList;
    int paramCount = 1;

    while (formalParams != NULL && actualParams != NULL)
    {
        if (formalParams->typeTablePtr != actualParams->typeTablePtr)
        {
            printf("Class Method Error: Expected data type %s for argument no. %d of function %s() belonging to class %s\n", formalParams->typeTablePtr->typeName, paramCount, classMemFunc->funcName, classVarType->className);
            exit(1);
        }
        ++paramCount;
        formalParams = formalParams->next;
        actualParams = actualParams->argListNext;
    }

    if (formalParams == NULL && actualParams != NULL)
    {
        printf("Class Method Error: Too many arguments passed for function %s() belonging to class %s\n", classMemFunc->funcName, classVarType->className);
        exit(1);
    }
    if (formalParams != NULL && actualParams == NULL)
    {
        printf("Class Method Error: Not enough arguments passed for function %s() belonging to class %s\n", classMemFunc->funcName, classVarType->className);
        exit(1);
    }

    return 0;
}

int getMemFuncLabel(char *classVarName, char *memFuncName)
{

    // get the class table entry for the class variable
    // 'classVarName' from the GST
    struct ClassTable *classTableEntry = GSTLookup(classVarName)->classTablePtr;

    // get the Member Function List entry for the function
    // named 'memFuncName'
    struct MemberFuncList *memFuncListEntry = MemberFuncLookUp(classTableEntry, memFuncName);

    return memFuncListEntry->funcLabel;
}

void MFLPrint(char *className)
{
    if (memFuncListHead == NULL && memFuncListTail == NULL)
        return;

    printf("\n\nMember Function list for class %s\n\n", className);

    printf("funcPosition            funcName  funcType       paramList  funcLabel\n");
    printf("──────────────────────────────────────────────────────────────────────\n\n");

    struct MemberFuncList *traversalPtr = memFuncListHead;

    while (traversalPtr != NULL)
    {
        printf("%12d", traversalPtr->funcPosition);
        printf("%20s", traversalPtr->funcName);
        printf("%10s", traversalPtr->funcType->typeName);

        if (traversalPtr->paramList == NULL)
            printf("%16s", "-");
        else
            printf("%16p", traversalPtr->paramList);

        printf("%11d\n", traversalPtr->funcLabel);

        traversalPtr = traversalPtr->next;
    }
    printf("\n\n──────────────────────────────────────────────────────────────────────\n\n");
}