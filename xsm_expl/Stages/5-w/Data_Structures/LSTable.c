#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTable.h"
#include "../Frontend/ast.h"
#include "paramStruct.h"

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