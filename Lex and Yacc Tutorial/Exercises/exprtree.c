// Definitions for all the Expression Tree functions
// declared in exprtree.h

struct treeNode* makeLeafNode(int val){
	struct treeNode* temp;
	temp = (struct treeNode*)malloc(sizeof(struct treeNode));
	
	temp->op = NULL;
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct treeNode* makeInternalNode(char op, struct treeNode* left, struct treeNode* right){
	struct treeNode* temp;
	temp = (struct treeNode*)malloc(sizeof(struct treeNode));
	
	temp->op = malloc(sizeof(char));
	*(temp->op) = op;
	temp->left = left;
	temp->right = right;

	return temp;
}

int evaluateTree(struct treeNode* root){

	// If the tree node is a leaf node
	if (root->op == NULL)
		return root->val;

	// Else if its an internal node with
	// an operator
	char op = *(root->op);

	if (op == '+')
		return evaluateTree(root->left) + evaluateTree(root->right);
	if (op == '-')
		return evaluateTree(root->left) - evaluateTree(root->right);
	if (op == '*')
		return evaluateTree(root->left) * evaluateTree(root->right);
	if (op == '/')
		return evaluateTree(root->left) / evaluateTree(root->right);
		
}
