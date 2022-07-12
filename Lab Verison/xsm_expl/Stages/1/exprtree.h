// Declarations of Expression Tree Node and functions it uses

struct treeNode {
	int val;			// value of leaf node
	char *op;			// operator of internal node
	struct treeNode *left, *right;	// left and right child of internal node
}tnode;

/*
 * Function to create and return a leaf node 
 * with the value passed to the function
 */
struct treeNode* makeLeafNode(int val);

/*
 * Function to create and return an internal node 
 * with the operator and its left and right child
 * passed to the function
 */
struct treeNode* makeInternalNode(char op, struct treeNode* left, struct treeNode* right);

/*
 * Function to evaluate an expression tree and return
 * its value by passing its root to the function.
 */
int evaluateTree(struct treeNode* root);
