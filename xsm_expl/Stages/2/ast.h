// Abstract Syntax Tree (AST)

// Structure of an Abstract Syntax Tree Node
struct ASTNode{
	int val;			// value of a number for NUM nodes.
	char *varname;			// name of a variable or operator  
	int nodetype;  			// information about non-leaf nodes - read/write/connector
	struct ASTNode *left,*right;	// left and right branches  	
}anode;

// Static Array that stores values of all 26 variables [a-z]
int variableStorage[26];

int initVariableStorage();

/**
 * Function to dynamically create a node for an AST
 *
 * @params	val:		Value of a NUM node, set to 0 otherwise
 *
 * 		nodetype:	Value identifying the type of node
 *				1 - NUM 
 *				2 - Variable
 *				3 - Operator
 *				4 - Read
 *				5 - Write
 *				6 - Connector
 *
 *		varname:	Name of the variable or operator node, 
 *				set to NULL otherwise
 *
 *		left, right:	Pointer to the left and right subtrees,
 *				set to NULL for variables and NUM
 *
 * @return	newASTNode:	The newly created AST Node
 */
struct ASTNode* createASTNode(int val, int nodetype, char* varname, struct ASTNode* left, struct ASTNode* right);

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
