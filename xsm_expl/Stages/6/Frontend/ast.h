#ifndef AST_N_H

#define AST_N_H

#include <stdio.h>
#include "../Data_Structures/GSTable.h"
#include "../Data_Structures/LSTable.h"
#include "../Data_Structures/typeTable.h"

#define CONST_INT_NODE 0 // Constant Node
#define CONST_STR_NODE 1

#define ID_NODE 2 // Identifier Node
#define TUPLE_FIELD_NODE 82

#define PLUS_NODE 3 // Operator Node
#define MINUS_NODE 4
#define MUL_NODE 5
#define DIV_NODE 6
#define MOD_NODE 7
#define AMP_NODE 80
#define DOT_NODE 81

#define GT_NODE 8 // Relational Operator Node
#define LT_NODE 9
#define GE_NODE 10
#define LE_NODE 11
#define EQ_NODE 12
#define NE_NODE 13

#define IF_NODE 14 // Control Flow Operator Node
#define WHILE_NODE 15
#define DO_WHILE_NODE 16
#define BREAK_NODE 17
#define CONTINUE_NODE 18

#define READ_NODE 19 // I/O Functions Node
#define WRITE_NODE 20

#define ASGN_NODE 21 // Assignment Operator Node

#define SLIST_NODE 22 // Statement List Node

#define BREAKPOINT_NODE 23 // Breakpoint Node

#define RETURN_NODE 24
#define FUNC_NODE 25

#define FIELD_NODE 26

#define AND_NODE 30
#define OR_NODE 31
#define NOT_NODE 32

#define INITIALIZE_NODE 40
#define ALLOC_NODE 41
#define FREE_NODE 42

#define TYPE_INT 50
#define TYPE_BOOL 51
#define TYPE_VOID 52
#define TYPE_STR 53
#define TYPE_INT_PTR 54
#define TYPE_STR_PTR 55
#define TYPE_TUPLE 56

#define LABEL_CONTROL 60
#define LABEL_FUNCTION 61

#define DECL_START 70
#define DECL_END 71
#define DECL_NULL 72

#define NULL_NODE 100

// TODO: Add typetable field
struct ASTNode
{
    int sno;
    int dataType;                          // Data type of the node
    int nodeType;                          // Type of the node
    struct TypeTable *typeTablePtr;        // Pointer to type table entry
    char *nodeName;                        // Name of variable
    int intConstVal;                       // Value of int const
    char *strConstVal;                     // Value of str const
    struct ASTNode *argListHead;           // Pointer to head of list of arguments of a function
    struct ASTNode *argListNext;           // Pointer to next element of arg list
    struct ASTNode *left, *middle, *right; // Left, middle and right subtrees
    struct GSTNode *GSTEntry;              // Pointer to Global Symbol Table entry for a variable
    struct LSTNode *LSTEntry;              // Pointer to Local Symbol Table entry for a function
} astnode;

struct ASTNode *TreeCreate(struct TypeTable *typeTablePtr, int nodeType, char *nodeName, int intConstVal, char *strConstVal, struct ASTNode *left, struct ASTNode *middle, struct ASTNode *right);

int printAST(struct ASTNode *root, int sno);
void printASTTable(struct ASTNode *root, int sno);
extern int ASTTableSno;
char *getNodeName(int nodeType);

int getVariableAddress(FILE *filePtr, struct ASTNode *root);

int getStructVariableAddress(FILE *filePtr, struct ASTNode *root, int structAddrReg);

int getAddress(FILE *filePtr, struct ASTNode *root);

int evalExprTree(FILE *filePtr, struct ASTNode *root);

/**
 * @brief   Check if an identifier is defined in the LST or GST
 *
 * @param   IDName Name of the variable
 * @return  struct ASTNode*
 */
struct ASTNode *lookupID(struct ASTNode *IDNode);

/**
 * @brief   Insert node to the argument list of a function
 *
 * @param   argListHead Head of the argument list
 * @param   argNode Argument node to be inserted
 * @return  struct ASTNode*
 */
struct ASTNode *insertToArgList(struct ASTNode *argListHead, struct ASTNode *argNode);

/**
 * @brief   Verify whether the arguments passed to a function is correct
 *          according to the function signature.
 *
 * @param   funcName Name of the function
 * @param   argumentList List of arguments passed
 * @return  int
 */
int verifyFunctionArguments(char *funcName, struct ASTNode *argumentList);

#endif