// Abstract Syntax Tree (AST)

#ifndef AST_H

#define AST_H

// Structure of an Abstract Syntax Tree Node
struct ASTNode{
	int val;			// value of a number for NUM nodes.
	int type;			// data type of the node
	char *varname;			// name of a variable or operator  
	int nodetype;  			// information about non-leaf nodes - read/write/connector
	struct ASTNode *left, *middle, *right;	// left, middle and right branches  	
}anode;

/**
 * Function to dynamically create a node for an AST
 *
 * @params	val:		Value of a NUM node, set to 0 otherwise
 *
 *   		type:		1 - int
 *				2 - bool
 *
 * 		nodetype:	Value identifying the type of node
 *				1 - NUM 
 *				2 - Variable
 *				3 - Operator
 *				4 - Read
 *				5 - Write
 *				6 - Connector
 *				7 - Control Flow i.e if, else, etc
 *
 *		varname:	Name of the variable and operator node, others are 
 *				R - READ
 *				W - WRITE
 *				C - Connector
 *				N - NUM
 *				I - IF
 *				W - WHILE
 *				B - BREAK
 *				CN - CONTINUE
 *
 *		left, right:	Pointer to the left and right subtrees,
 *				set to NULL for variables and NUM
 *
 *		middle:		Pointer to the middle subtree, used for if-then-else
 *				and if-else nodes, set to NULL for others
 *
 * @return	newASTNode:	The newly created AST Node
 */
struct ASTNode* createASTNode(int val,int type, int nodetype, char* varname, struct ASTNode* left, struct ASTNode* middle, struct ASTNode* right);

/**
 * Function to print nodes of the AST in a Post-Order fashion
 *
 * @params	root:		Root of the AST
 *
 * @return	1:		Upon successfully printing all the nodes	
 */
int printAST(struct ASTNode* root);

/*
 * Function that returns the address of a variable in the XSM Machine
 *
 * @params	variable:	The variable, which is a lower case alphabet
 *
 * @return 	[4096-4121]:	The memory address
 */
int getVariableAddress(char variable);

/**
 * Function to translate an expression tree into XSM instructions.
 * 
 * @params	root:		Root of the Expression Tree
 *
 * @return	[0-19]:		Register number in which the result is stored
 */
int evalExprTree(FILE* filePtr, struct ASTNode* root);

#endif
