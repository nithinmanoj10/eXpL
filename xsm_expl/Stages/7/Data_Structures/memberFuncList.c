#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "paramStruct.h"
#include "typeTable.h"
#include "classTable.h"
#include "memberFuncList.h"
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

    struct MemberFuncList *traversalPtr = classType->virtualFunctionPtr;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->funcName, memberFuncName) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
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