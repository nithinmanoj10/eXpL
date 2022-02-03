#ifndef AST_H

#define AST_H

#include "../Data_Structures/globalSymbolTable.h"


// Structure of an Abstract Syntax Tree Node
struct ASTNode{
	int val;			  												// value of a number for NUM nodes.
	int type;																// data type of the node
	char *varname;													// name of a variable or operator  
	int nodetype;  													// information about non-leaf nodes - read/write/connector
	int arrayOffset;												// Offset of an array variable i.e Index
	struct globalSTNode* GSTEntry;					// Pointer to GST Entry - for variables
	struct ASTNode *left, *middle, *right;	// left, middle and right branches  	
}anode;

/**
 * Function to dynamically create a node for an AST
 *
 * @param	val:		Value of a NUM node, set to 0 otherwise
 *
 *   		type:		1 - int
 *						2 - bool
 *						3 - str
 *
 * 		nodetype:	Value identifying the type of node
 *				1 - NUM 
 *				2 - Variable
 *				3 - Operator
 *				4 - Read
 *				5 - Write
 *				6 - Connector
 *				7 - Control Flow i.e if, else, etc
 *				8 - Break Point
 *				9 - STR
 *
 *		varname:	Name of the variable, value of string and operator node, others are 
 *				R - READ
 *				W - WRITE
 *				C - Connector
 *				N - NUM
 *				I - IF
 *				W - WHILE
 *				DW - DO WHILE
 *				B - BREAK
 *				CN - CONTINUE
 *				BR - BREAKPOINT
 *
 *		arrayOffset:	Offset of an array variable. Set to -1 for non-array variables
 *
 *		left, right:	Pointer to the left and right subtrees,
 *				set to NULL for variables and NUM
 *
 *		middle:		Pointer to the middle subtree, used for if-then-else
 *				and if-else nodes, set to NULL for others
 *
 * @return	newASTNode:	The newly created AST Node
 */
struct ASTNode* createASTNode(int val,int type, int nodetype, char* varname, int arrayOffset, struct ASTNode* left, struct ASTNode* middle, struct ASTNode* right);

/**
 * Function to print nodes of the AST in a Post-Order fashion
 *
 * @params	root:		Root of the AST
 *
 * @return	1:		Upon successfully printing all the nodes	
 */
int printAST(struct ASTNode* root);

/**
 * @brief	Function that returns the register number in which the 
 * 			address of the required variable is stored
 * 
 * @param 	filePtr	File pointer of the target file
 * @param 	root	ASTNode of the variable	 
 * @return 	int		Address of the variable		 
 */
int getVariableAddress(FILE* filePtr, struct ASTNode* root);

/**
 * Function to translate an expression tree into XSM instructions.
 * 
 * @params	root:		Root of the Expression Tree
 *
 * @return	[0-19]:		Register number in which the result is stored
 */
int evalExprTree(FILE* filePtr, struct ASTNode* root);

#endif
