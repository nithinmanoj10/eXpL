#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Frontend/ast.h"
#include "typeTable.h"
#include "classTable.h"

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

struct TypeTable *typeTableINT;
struct TypeTable *typeTableINTPtr;
struct TypeTable *typeTableSTR;
struct TypeTable *typeTableSTRPtr;
struct TypeTable *typeTableBOOL;
struct TypeTable *typeTableVOID;

void TypeTableCreate()
{
    // Allocate necessary space for the 4 entries in the
    // Type Table - int, str, bool and void
    typeTableINT = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableINT->typeName = (char *)malloc(10 * sizeof(char *));
    typeTableINT->typeCategory = TYPE_PRIMITIVE;

    typeTableINTPtr = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableINTPtr->typeName = (char *)malloc(10 * sizeof(char *));
    typeTableINTPtr->typeCategory = TYPE_POINTER;

    typeTableSTR = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableSTR->typeName = (char *)malloc(10 * sizeof(char *));
    typeTableSTR->typeCategory = TYPE_PRIMITIVE;

    typeTableSTRPtr = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableSTRPtr->typeName = (char *)malloc(10 * sizeof(char *));
    typeTableSTRPtr->typeCategory = TYPE_POINTER;

    typeTableBOOL = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableBOOL->typeName = (char *)malloc(10 * sizeof(char *));
    typeTableBOOL->typeCategory = TYPE_PRIMITIVE;

    typeTableVOID = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    typeTableVOID->typeName = (char *)malloc(10 * sizeof(char *));
    typeTableVOID->typeCategory = TYPE_PRIMITIVE;

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

    printf("\n\n👔 Type Table\n");
    printf("──────────────────────────────────────────────────────────────────────────────\n");
    printf("          typeName       typeCategory  size           fields         location\n");
    printf("──────────────────────────────────────────────────────────────────────────────\n\n");
    while (traversalPtr != NULL)
    {
        printf("%18s%21s%6d%17p%17p\n", traversalPtr->typeName, getTypeCategory(traversalPtr->typeCategory), traversalPtr->size, traversalPtr->fields, traversalPtr);
        traversalPtr = traversalPtr->next;
    }
    // printf("\n-------------------------------------------------------------\n");
}

char *getTypeCategory(int typeCategory)
{
    switch (typeCategory)
    {
    case TYPE_PRIMITIVE:
        return "Primitive 🐉";
        break;

    case TYPE_POINTER:
        return "Pointer 📌";
        break;

    case TYPE_USER_DEFINED:
        return "User Defined 👤";
        break;

    case TYPE_TUPLE:
        return "Tuple 🥡";
        break;

    case TYPE_CLASS:
        return "Class 📚";
        break;

    default:
        break;
    }
}

int isPrimitiveType(struct TypeTable *typeTablePtr)
{
    if (typeTablePtr == typeTableINT || typeTablePtr == typeTableINTPtr || typeTablePtr == typeTableSTR || typeTablePtr == typeTableSTRPtr || typeTablePtr == typeTableBOOL || typeTablePtr == typeTableVOID)
        return 1;

    return 0;
}

/* Field List ------------------------------------------------------------------------------- */

struct FieldList *fieldListHead = NULL;
struct FieldList *fieldListTail = NULL;

struct FieldList *FLCreateNode(char *fieldName, struct TypeTable *type, struct ClassTable *classType)
{
    struct FieldList *newFLNode = (struct FieldList *)malloc(sizeof(struct FieldList));
    newFLNode->fieldName = (char *)malloc(sizeof(fieldName));

    strcpy(newFLNode->fieldName, fieldName);
    newFLNode->fieldIndex = 0;
    newFLNode->type = type;
    newFLNode->classType = classType;
    newFLNode->next = NULL;

    return newFLNode;
}

struct FieldList *FLLookUp(struct TypeTable *type, struct ClassTable *classType, char *fieldName)
{
    struct FieldList *traversalPtr = (type == NULL) ? (classType->memberField) : (type->fields);

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->fieldName, fieldName) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

void FLPrint(char *fieldTableName, struct FieldList *headPtr)
{
    struct FieldList *traversalPtr = (headPtr == NULL) ? (fieldListHead) : (headPtr);

    printf("\n\nField List for %s - %p\n", fieldTableName, fieldListHead);
    printf("---------------------------------------------------\n\n");
    printf("fieldIndex              fieldName             type        classType\n");
    printf("────────────────────────────────────────────────────────────────────\n\n");
    while (traversalPtr != NULL)
    {

        printf("%10d", traversalPtr->fieldIndex);
        printf("%23s", traversalPtr->fieldName);

        if (traversalPtr->type != NULL)
            printf("%17p", traversalPtr->type);
        else
            printf("%17s", "-");

        if (traversalPtr->classType != NULL)
            printf("%17p\n", traversalPtr->classType);
        else
            printf("%17s\n", "-");

        traversalPtr = traversalPtr->next;
    }

    printf("\n────────────────────────────────────────────────────────────────────\n\n");
}
