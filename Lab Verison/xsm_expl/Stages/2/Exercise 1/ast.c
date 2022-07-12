#include "ast.h"

int initVariableStorage(){
	for(int i = 0; i < 26; ++i)
		variableStorage[i] = 0;
	return 1;
}

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

