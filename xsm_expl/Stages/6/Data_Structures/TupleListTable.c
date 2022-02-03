#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TupleListTable.h"

int tupleFieldCount = 0;
int tupleFieldType = 0;
struct TupleFieldList *tupleFieldListHead = NULL;
struct TupleFieldList *tupleFieldListTail = NULL;

struct TupleList *tupleListHead = NULL;
struct TupleList *tupleListTail = NULL;
char *currentTupleID = NULL;

struct TupleTypeTable *tupleTypeTableHead = NULL;
struct TupleTypeTable *tupleTypeTableTail = NULL;
int tupleTypeNumCount = 200;

int getTupleFieldCount()
{
    return tupleFieldCount;
}

int incTupleFieldCount()
{
    ++tupleFieldCount;
    return 1;
}

int flushTupleFieldCount()
{
    tupleFieldCount = 0;
    return 1;
}

struct TupleList *insertTuple(char *tupleName)
{
    // if the tuple record already exists
    struct TupleList *TLNode = getTuple(tupleName);
    if (TLNode != NULL)
        return TLNode;

    struct TupleList *newTLNode = (struct TupleList *)malloc(sizeof(struct TupleList));
    newTLNode->tupleName = (char *)malloc(sizeof(tupleName));

    strcpy(newTLNode->tupleName, tupleName);
    newTLNode->tupleFieldListHead = NULL;

    if (tupleListHead == NULL && tupleListTail == NULL)
    {
        tupleListHead = newTLNode;
        tupleListTail = newTLNode;
        return newTLNode;
    }

    tupleListTail->next = newTLNode;
    tupleListTail = newTLNode;

    return newTLNode;
}

struct TupleList *getTuple(char *tupleName)
{

    if (tupleListHead == NULL && tupleListTail == NULL)
        return NULL;

    struct TupleList *traversalPtr = tupleListHead;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->tupleName, tupleName) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

int printTupleList()
{
    if (tupleListHead == NULL && tupleListTail == NULL)
        return 0;

    struct TupleList *traversalPtr = tupleListHead;

    printf("\nTuple List --------------------------------------------\n");
    printf("tupleName\ttupleFieldListHead\n");

    while (traversalPtr != NULL)
    {
        printf("%s\t%p\n", traversalPtr->tupleName, traversalPtr->tupleFieldListHead);
        traversalPtr = traversalPtr->next;
    }

    printf("\n-------------------------------------------------------\n");
}

int setCurrentTupleID(char *tupleID)
{
    currentTupleID = (char *)malloc(sizeof(tupleID));
    strcpy(currentTupleID, tupleID);

    return 1;
}

char *getCurrentTupleID()
{
    return currentTupleID;
}

struct TupleFieldList *insertTupleField(char *tupleFieldName, int tupleFieldType)
{

    struct TupleFieldList *newTFLNode = (struct TupleFieldList *)malloc(sizeof(struct TupleFieldList));
    newTFLNode->tupleFieldName = (char *)malloc(sizeof(char *));

    strcpy(newTFLNode->tupleFieldName, tupleFieldName);
    newTFLNode->tupleFieldType = tupleFieldType;

    if (tupleFieldListHead == NULL && tupleFieldListTail == NULL)
    {
        tupleFieldListHead = newTFLNode;
        tupleFieldListTail = newTFLNode;
        newTFLNode->tupleFieldBinding = 0;

        return newTFLNode;
    }

    newTFLNode->tupleFieldBinding = tupleFieldListTail->tupleFieldBinding + 1;
    tupleFieldListTail->next = newTFLNode;
    tupleFieldListTail = newTFLNode;

    return newTFLNode;
}

struct TupleFieldList *getTupleField(char *tupleFieldName)
{
    if (tupleFieldListHead == NULL && tupleFieldListTail == NULL)
        return NULL;

    struct TupleFieldList *traversalPtr = tupleFieldListHead;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->tupleFieldName, tupleFieldName) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

struct TupleFieldList *searchTupleField(struct TupleFieldList *head, char *fieldName)
{
    struct TupleFieldList *traversalPtr = head;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->tupleFieldName, fieldName) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

int printTupleFieldList()
{
    struct TupleFieldList *traversalPtr = tupleFieldListHead;
    printf("Tuple %s -> %p\n", getCurrentTupleID(), traversalPtr);

    while (traversalPtr != NULL)
    {
        printf(" %s %d %d\n", traversalPtr->tupleFieldName, traversalPtr->tupleFieldType, traversalPtr->tupleFieldBinding);
        traversalPtr = traversalPtr->next;
    }

    printf("\n");

    return 1;
}

int flushTupleFieldList()
{
    tupleFieldListHead = NULL;
    tupleFieldListTail = NULL;
    return 1;
}

int setTupleFieldType(int type)
{
    tupleFieldType = type;
    return 1;
}

int getTupleFieldType()
{
    return tupleFieldType;
}

struct TupleTypeTable *insertTupleType(char *tupleTypeName)
{

    if (getTupleTypeNum(tupleTypeName) != -1)
        return NULL;

    struct TupleTypeTable *newTTTNode = (struct TupleTypeTable *)malloc(sizeof(struct TupleTypeTable));
    newTTTNode->tupleTypeName = (char *)malloc(sizeof(tupleTypeName));

    strcpy(newTTTNode->tupleTypeName, tupleTypeName);
    newTTTNode->tupleTypeNum = tupleTypeNumCount++;
    newTTTNode->next = NULL;

    if (tupleTypeTableHead == NULL)
    {
        tupleTypeTableHead = newTTTNode;
        tupleTypeTableTail = newTTTNode;
        return newTTTNode;
    }

    tupleTypeTableTail->next = newTTTNode;
    tupleTypeTableTail = newTTTNode;

    return newTTTNode;
}

int getTupleTypeNum(char *tupleTypeName)
{

    struct TupleTypeTable *traversalPtr = tupleTypeTableHead;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->tupleTypeName, tupleTypeName) == 0)
            return traversalPtr->tupleTypeNum;
        traversalPtr = traversalPtr->next;
    }

    return -1;
}

char *getTupleTypeName(int tupleTypeNum)
{
    struct TupleTypeTable *traversalPtr = tupleTypeTableHead;

    while (traversalPtr != NULL)
    {
        if (traversalPtr->tupleTypeNum == tupleTypeNum)
            return traversalPtr->tupleTypeName;
        traversalPtr = traversalPtr->next;
    }

    return NULL;
}

int printTupleTypeTable()
{
    struct TupleTypeTable *traversalPtr = tupleTypeTableHead;

    printf("\nTuple Type Table -----------------------------------\n");

    while (traversalPtr != NULL)
    {
        printf("%s %d\n", traversalPtr->tupleTypeName, traversalPtr->tupleTypeNum);
        traversalPtr = traversalPtr->next;
    }
    printf("\n----------------------------------------------------\n");

    return 1;
}