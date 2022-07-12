#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

int initVariableStorage()
{
	for (int i = 0; i < 26; ++i)
		variableStorage[i] = 0;
	return 1;
}

struct ASTNode *createASTNode(int val, int nodetype, char *varname, struct ASTNode *left, struct ASTNode *right)
{

	// dynamically allocates space for the new node
	struct ASTNode *newASTNode = (struct ASTNode *)malloc(sizeof(struct ASTNode));
	newASTNode->varname = malloc(sizeof(char));

	// assigns each property of the node
	newASTNode->val = val;
	newASTNode->nodetype = nodetype;
	*(newASTNode->varname) = *varname;
	newASTNode->left = left;
	newASTNode->right = right;

	return newASTNode;
}

int printAST(struct ASTNode *root)
{

	if (root == NULL)
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
 * address = 4096 + ascii(variable) - 97
 */
int getVariableAddress(char variable)
{

	int asciiValue = variable;
	return 4096 + asciiValue - 97;
}

int evalExprTree(struct ASTNode *root)
{

	// if its a leaf node - NUM
	if (root->nodetype == 1)
	{
		return root->val;
	}

	// if its a leaf node - VAR
	if (root->nodetype == 2)
	{
		int variable = *root->varname - 97;
		return variableStorage[variable];
	}

	// For internal nodes in the Expression Tree

	int leftVal, rightVal;

	leftVal = evalExprTree(root->left);
	rightVal = evalExprTree(root->right);

	char op = *root->varname;

	if (op == '+')
		return leftVal + rightVal;

	if (op == '-')
		return leftVal - rightVal;

	if (op == '*')
		return leftVal * rightVal;

	if (op == '/')
		return leftVal / rightVal;
}
