#ifndef DECLTREE_H

#define DECLTREE_H

/** 
 *	Data Structure to keep track of all the declarations
 *	made in the program.
 */

/**
 *	@struct	declarationsTree
 *
 *	@fields		nodeType:		Type of the tree node
 *												1 - Type Node
 *												2 - VariableNode
 *
 *						varType:		Type of the variable
 *												1 - int
 *												2 - str
 *												0 - none variable node
 *
 *						varName:		Name of the variable
 *
 *						right,
 *						left:				Pointer to right and left subtree
 */  
struct declarationsTree {
	int nodeType;											
	int varType;
	char* varName;
	struct declarationsTree* right;
	struct declarationsTree* left;
}declNode;

/**
 *	Function to create a Declarations Tree Node
 *
 *	@params		nodeType:		Type of the tree node
 *												1 - Type Node
 *												2 - VariableNode
 *												3 - Connector Node
 *
 *						varType:		Type of the variable
 *												1 - int
 *												2 - str
 *												0 - none variable node
 *
 *						varName:		Name of the variable
 *
 *						right,
 *						left:				Pointer to right and left subtree
 */
struct declarationsTree* createDTNode(int nodeType, int varType, char* varName, struct declarationsTree* right, struct declarationsTree* left);

/**
 *	Function to print the Declarations Tree in a post order fashion
 *
 *	@params		root:				Pointer to the root of the tree
 *
 *	@return		1:					After successful printing
 */
int printDeclarationsTree(struct declarationsTree* root);

#endif
