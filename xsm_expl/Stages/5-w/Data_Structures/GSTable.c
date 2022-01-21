#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GSTable.h"
#include "../Functions/stackMemory.h"
#include "../Frontend/ast.h"
#include "../Functions/label.h"
#include "../Data_Structures/paramStruct.h"

struct GSTNode *GSTHead = NULL;
struct GSTNode *GSTTail = NULL;
int declarationStatus = DECL_NULL;

int getDeclarationStatus()
{
    return declarationStatus;
}

int setDeclarationStatus(int status)
{

    if (status != DECL_NULL && status != DECL_START && status != DECL_END)
    {
        printf("\nInvalid Declaration Status\n");
        exit(1);
    }

    declarationStatus = status;
    return 0;
}

struct GSTNode *GSTInstall(char *name, int type, int size, struct ParamStruct *paramList)
{
    if (GSTLookup(name) != NULL)
    {
        printf("\nVariable %s declared more than once\n", name);
        exit(1);
    }

    struct GSTNode *newGSTNode = (struct GSTNode *)malloc(sizeof(struct GSTNode));
    newGSTNode->name = (char *)malloc(sizeof(name));
    int binding;

    // if function, assign binding to -1
    if (size == -1)
        binding = -1;
    else
        binding = getFreeStackMemory(size);

    // if function, assign a valid function label number
    // else for variable set it to -1
    if (size == -1)
        newGSTNode->fLabel = getFuncLabel();
    else
        newGSTNode->fLabel = -1;

    strcpy(newGSTNode->name, name);
    newGSTNode->type = type;
    newGSTNode->size = size;
    newGSTNode->binding = binding;
    newGSTNode->paramList = paramList;
    newGSTNode->next = NULL;

    // if the GST is empty
    if (GSTHead == NULL && GSTTail == NULL)
    {
        GSTHead = newGSTNode;
        GSTTail = newGSTNode;
        return newGSTNode;
    }

    GSTTail->next = newGSTNode;
    GSTTail = newGSTNode;

    return newGSTNode;
}

struct GSTNode *GSTLookup(char *name)
{

    struct GSTNode *traversalPtr = GSTHead;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->name, name) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

int GSTPrint()
{
    struct GSTNode *traversalPtr = GSTHead;

    while (traversalPtr != NULL)
    {
        printf("\n📦 %s:\n", traversalPtr->name);
        printf("➡ Address: %p\n", traversalPtr);
        printf("➡ Type: %d\n", traversalPtr->type);
        printf("➡ Size: %d\n", traversalPtr->size);
        printf("➡ Binding: %d\n", traversalPtr->binding);

        printf("➡ Param List: ");
        printParamList(traversalPtr->paramList);

        printf("➡ FLabel: %d\n", traversalPtr->fLabel);
        printf("➡ Next: %p\n", traversalPtr->next);
        traversalPtr = traversalPtr->next;
    }

    return 0;
}

int getFunctionType(char *name)
{
    struct GSTNode *traverslPtr = GSTHead;

    while (traverslPtr != NULL)
    {
        if (strcmp(traverslPtr->name, name) == 0)
            return traverslPtr->type;
        traverslPtr = traverslPtr->next;
    }
}

int getFunctionLabel(char *name)
{
    struct GSTNode *funcNode = GSTLookup(name);
    return funcNode->fLabel;
}