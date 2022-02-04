#ifndef GSTABLE_H

#define GSTABLE_H

#include "typeTable.h"

struct GSTNode
{
    char *name;                     // Name of the variable or function
    int type;                       // Data type of the variable: int or str
    struct TypeTable *typeTablePtr; // Pointer to the type table entry of the Global Variable
    int size;                       // Size of the variable
    int binding;                    // Static binding of global variables
    struct ParamStruct *paramList;  // Pointer to Formal Parameter List, for a function
    int fLabel;                     // Lablel identifying a function uniquely
    struct GSTNode *next;           // Pointer to next node
} gstnode;

extern struct GSTNode *GSTHead;
extern struct GSTNode *GSTTail;
extern int declarationStatus;

extern struct TypeTable *currentGDeclType;

int getDeclarationStatus();
int setDeclarationStatus(int status);

struct GSTNode *GSTInstall(char *name, struct TypeTable *typeTablePtr, int size, struct ParamStruct *paramList);

struct GSTNode *GSTLookup(char *name);

int GSTPrint();

/**
 * @brief   Get the Function Type
 *
 * @param   name Name of the function
 * @return  int
 */
int getFunctionType(char *name);

/**
 * @brief   Get the Function Label
 *
 * @param   name Name of the function
 * @return  int
 */
int getFunctionLabel(char *name);

#endif