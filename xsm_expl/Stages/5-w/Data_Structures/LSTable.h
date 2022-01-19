#ifndef LSTABLE_H

#define LSTABLE_H

#include "../Frontend/ast.h"
#include "paramStruct.h"

// Node of a Local Symbol Table
struct LSTNode
{
    char *name;           // Name of the variable
    int type;             // Data type of the variable: int or str
    int binding;          // Dynamic Binding
    struct LSTNode *next; // Pointer to next node
} lstnode;

extern struct LSTNode *LSTHead;
extern struct LSTNode *LSTTail;

/**
 * @brief   Add new variable to the Local Symbol Table 
 * 
 * @param   name Name of the new variable 
 * @param   type Data type of the new variable 
 * @return  struct LSTNode* 
 */
struct LSTNode *LSTInstall(char *name, int type);

/**
 * @brief   Search for a given variable in the Local Symbol Table 
 * 
 * @param   name Name of the variable to be searched for 
 * @return  struct LSTNode* 
 */
struct LSTNode *LSTLookup(char *name);

/**
 * @brief   Print the Local Symbol Table 
 * 
 * @return  struct LSTNode* 
 */
struct LSTNode *LSTPrint();

/**
 * @brief   Adds the formal parameters of a function to the Local Symbol Table
 * 
 * @return  int 
 */
int LSTAddParams();

/**
 * @brief   Verify if a functions signature matches the one declared in the
 *          global variable section 
 * 
 * @param   funcName Name of the function
 * @return  int 
 */
int verifyFunctionSignature(char *funcName);

/**
 * @brief   Set LSTHead and LSTTail to NULL 
 * 
 * @return  int 
 */
int flushLST();

#endif