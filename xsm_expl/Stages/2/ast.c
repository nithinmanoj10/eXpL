struct ASTNode* createASTNode(int val, int nodetype, char* varname, struct ASTNode* left, struct ASTNode* right) {

	// dynamically allocates space for the new node
	struct ASTNode* newASTNode = (struct ASTNode*)malloc(sizeof(struct ASTNode));
	newASTNode->varname = malloc(sizeof(char));

	// assigns each property of the node
	newASTNode->val = val;
	newASTNode->nodetype = nodetype;
	*(newASTNode->varname) = *varname;
	newASTNode->left = left;
	newASTNode->right = right;

	return newASTNode;
}

int printAST(struct ASTNode* root){

	if(root == NULL)
		return 1;

	printAST(root->left);
	printAST(root->right);

	printf("val: %d\n", root->val);
	printf("varname: %s\n", root->varname);
	printf("nodetype: %d\n", root->nodetype);
	printf("left: %p\n", root->left);
	printf("right: %p\n", root->right);
	
	printf("\n");
	return 1;
}

/*
 * Variable name will be a lower case alphabet, and its address
 * is assigned as follows:
 *
 * a -> 4056
 * b -> 4057
 *    .
 *    .
 * z -> 4151
 *
 * Calculated as :
 *
 * address = 4056 + ascii(variable) - 97
 */
int getVariableAddress(char variable){

	int asciiValue = variable;
	return 4056 + asciiValue - 97;
}
