#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typeTable.h"
#include "../Frontend/ast.h"

int declarationType = TYPE_VOID;
int paramType = TYPE_VOID;
int funcType = TYPE_VOID;
char *currentFuncName = NULL;

int getDeclarationType()
{
    return declarationType;
}

int setDeclarationType(int type)
{
    declarationType = type;
    return 0;
}

int getParamType()
{
    return paramType;
}

int setParamType(int type)
{
    paramType = type;
    return 0;
}

int getFuncType()
{
    return funcType;
}

int setFuncType(int type)
{
    funcType = type;
    return 0;
}

char *getCurrentFuncName()
{
    return currentFuncName;
}

int setCurrentFuncName(char *newFuncName)
{
    if (currentFuncName == NULL)
        currentFuncName = (char *)malloc(50 * sizeof(char));
    strcpy(currentFuncName, newFuncName);
    return 0;
}

/* Stage 6 Onwards ------------------------------------------------------------------------- */

struct TypeTable *typeTableHead = NULL;
struct TypeTable *typeTableTail = NULL;

void TypeTableCreate()
{
    // Allocation necessary space for the 4 entries in the
    // Type Table - int, str, bool and void
    struct TypeTable *typeTableINT = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableINT->typeName = (char *)malloc(10 * sizeof(char *));

    struct TypeTable *typeTableINTPtr = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableINTPtr->typeName = (char *)malloc(10 * sizeof(char *));

    struct TypeTable *typeTableSTR = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableSTR->typeName = (char *)malloc(10 * sizeof(char *));

    struct TypeTable *typeTableSTRPtr = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableSTRPtr->typeName = (char *)malloc(10 * sizeof(char *));

    struct TypeTable *typeTableBOOL = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableBOOL->typeName = (char *)malloc(10 * sizeof(char *));

    struct TypeTable *typeTableVOID = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableVOID->typeName = (char *)malloc(10 * sizeof(char *));

    // Setting the typeName for each entry
    strcpy(typeTableINT->typeName, "int");
    strcpy(typeTableINTPtr->typeName, "int*");
    strcpy(typeTableSTR->typeName, "str");
    strcpy(typeTableSTRPtr->typeName, "str*");
    strcpy(typeTableBOOL->typeName, "boolean");
    strcpy(typeTableVOID->typeName, "void");

    // Setting the size for each entry
    typeTableINT->size = 1;
    typeTableINTPtr->size = 1;
    typeTableSTR->size = 1;
    typeTableSTRPtr->size = 1;
    typeTableBOOL->size = 1;
    typeTableVOID->size = 1;

    // Setting the fields entry to NULL for each entry
    typeTableINT->fields = NULL;
    typeTableINTPtr->fields = NULL;
    typeTableSTR->fields = NULL;
    typeTableSTRPtr->fields = NULL;
    typeTableBOOL->fields = NULL;
    typeTableVOID->fields = NULL;

    // Setting the next pointer for each entry
    // int -> str -> bool -> void
    typeTableINT->next = typeTableINTPtr;
    typeTableINTPtr->next = typeTableSTR;
    typeTableSTR->next = typeTableSTRPtr;
    typeTableSTRPtr->next = typeTableBOOL;
    typeTableBOOL->next = typeTableVOID;
    typeTableVOID->next = NULL;

    // Seeting the head and tail pointer of the
    // type table linked list
    typeTableHead = typeTableINT;
    typeTableTail = typeTableVOID;
}

struct TypeTable *TTLookUp(char *typeName)
{
    struct TypeTable *traversalPtr = typeTableHead;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->typeName, typeName) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

struct TypeTable *TTInstall(char *typeName, int size, struct FieldList *fields)
{
    struct TypeTable *newTTNode = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    newTTNode->typeName = (char *)malloc(sizeof(typeName));

    strcpy(newTTNode->typeName, typeName);
    newTTNode->size = size;
    newTTNode->fields = fields;

    typeTableTail->next = newTTNode;
    typeTableTail = newTTNode;

    return newTTNode;
}

void printTypeTable()
{
    struct TypeTable *traversalPtr = typeTableHead;

    printf("\n\nType Table --------------------------------------------------\n\n");
    printf("          typeName  size           fields         location\n\n");
    while (traversalPtr != NULL)
    {
        printf("%18s%6d%17p%17p\n", traversalPtr->typeName, traversalPtr->size, traversalPtr->fields, traversalPtr);
        traversalPtr = traversalPtr->next;
    }
    printf("\n-------------------------------------------------------------\n");
}

/* Field List ------------------------------------------------------------------------------- */

struct FieldList *fieldListHead = NULL;
struct FieldList *fieldListTail = NULL;

struct FieldList *FLCreateNode(char *fieldName, struct TypeTable *type)
{
    struct FieldList *newFLNode = (struct FieldList *)malloc(sizeof(struct FieldList));
    newFLNode->fieldName = (char *)malloc(sizeof(fieldName));

    strcpy(newFLNode->fieldName, fieldName);
    newFLNode->fieldIndex = 0;
    newFLNode->type = type;
    newFLNode->next = NULL;

    return newFLNode;
}

void FLPrint(struct TypeTable *typeNode)
{
    struct FieldList *traversalPtr = fieldListHead;

    printf("\n\nField List for %s --------------------------------\n", typeNode->typeName);
    printf("%p\n\n", fieldListHead);
    printf("fieldIndex  fieldName   type\n\n");
    while (traversalPtr != NULL)
    {
        printf("%10d%11s%17p\n", traversalPtr->fieldIndex, traversalPtr->fieldName, traversalPtr->type);
        traversalPtr = traversalPtr->next;
    }
    printf("\n---------------------------------------------------\n");
}