#ifndef GSTABLE_H

#define GSTABLE_H

struct GSTNode
{
    char *name;                    // Name of the variable or function
    int type;                      // Data type of the variable: int or str
    int size;                      // Size of the variable
    int binding;                   // Static binding of global variables
    struct ParamStruct *paramList; // Pointer to Formal Parameter List, for a function
    int fLabel;                    // Lablel identifying a function uniquely
    struct GSTNode *next;          // Pointer to next node
} gstnode;

extern struct GSTNode *GSTHead;
extern struct GSTNode *GSTTail;
extern int declarationStatus;

int getDeclarationStatus();
int setDeclarationStatus(int status);

struct GSTNode *GSTInstall(char *name, int type, int size, struct ParamStruct *paramList);

struct GSTNode *GSTLookup(char *name);

// int GSTNode*

int GSTPrint();

#endif