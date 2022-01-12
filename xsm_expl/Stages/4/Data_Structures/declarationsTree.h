#ifndef DECLTREE_H

#define DECLTREE_H

/**
 *	Global variable that tells us if all variables are 
 *	added to the declaration tree.
 *
 *	0 - Declaration of all variables are not done
 *	1 - Declaration of all variables are done
 */
extern int declarationStatus;

/**
 *	Function to get the current declarationStatus value
 */
int getDeclarationStatus();

/**
 *	Function to set the declarationStatus value to 1
 */
int declarationComplete();

/** 
 *	Data Structure to keep track of all the declarations
 *	made in the program.
 */

struct declarationsTree {
	int nodeType;											
	int varType;
	char* varName;
	int varSize;
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
 *						varSize:		Size of the variable, rest set to 0
 *
 *						right,
 *						left:				Pointer to right and left subtree
 */
struct declarationsTree* createDTNode(int nodeType, int varType, char* varName, int varSize, struct declarationsTree* right, struct declarationsTree* left);

/**
 *	Function to print the Declarations Tree in a post order fashion
 *
 *	@params		root:				Pointer to the root of the tree
 *
 *	@return		1:					After successful printing
 */
int printDeclarationsTree(struct declarationsTree* root);

#endif
