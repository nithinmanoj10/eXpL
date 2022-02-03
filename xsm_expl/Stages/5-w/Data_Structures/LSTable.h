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
    int size;             // Size of the local variable
    struct LSTNode *next; // Pointer to next node
} lstnode;

// Node of a Function-LST Table
struct FunctionLSTTable
{
    char *funcName;                // Name of the function
    struct LSTNode *funcLST;       // Pointer to the functions LST
    struct FunctionLSTTable *next; // Pointer to the next element
} functionlsttable;

extern struct LSTNode *LSTHead;
extern struct LSTNode *LSTTail;

extern struct FunctionLSTTable *FLTHead; // Head pointer of the Function-LST Table
extern struct FunctionLSTTable *FLTTail; // Tail pointer of the Function-LST Table

/**
 * @brief   Add new variable to the Local Symbol Table 
 * 
 * @param   name Name of the new variable 
 * @param   type Data type of the new variable 
 * @param   size Size of the local variable
 * @return  struct LSTNode* 
 */
struct LSTNode *LSTInstall(char *name, int type, int size);

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
 * @brief   Get the size of the Local Symbol Tree 
 * 
 * @return  int 
 */
int getLSTSize();

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

/**
 * @brief   Add a function and its corresponding Local Symbol Table 
 *          to the Function-LST Table
 * 
 * @param   funcName Name of the function
 * @param   funcLST Pointer to the function's LST
 * @return  struct FunctionLSTTable*
 */
struct FunctionLSTTable *addFunctionLST(char *funcName, struct LSTNode *funcLST);

/**
 * @brief   Get a function's Local Symbol Table
 * 
 * @param   funcName Name of the function
 * @return  struct LSTNode* 
 */
struct LSTNode *getFunctionLST(char *funcName);

/**
 * @brief   Print the Function-LST Table 
 * 
 * @return  int 
 */
int printFLT();

#endif