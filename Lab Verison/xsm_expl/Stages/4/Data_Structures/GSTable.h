#ifndef GSTABLE_H

#define GSTABLE_H

struct GSTNode
{
    char *name;
    int type;
    int size;
    int binding;
    struct GSTNode *next;
} gstnode;

extern struct GSTNode *GSTHead;
extern struct GSTNode *GSTTail;
extern int declarationStatus;

int getDeclarationStatus();
int setDeclarationStatus(int status);

struct GSTNode *GSTInstall(char *name, int type, int size);

struct GSTNode *GSTLookup(char *name);

int GSTPrint();

#endif