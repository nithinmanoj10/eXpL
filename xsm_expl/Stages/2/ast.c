#include <stdio.h>
#include <stdlib.h>
#include "../Functions/reg.h"
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
int getVariableAddress(char variable){

	int asciiValue = variable;
	return 4096 + asciiValue - 97;
}

int evalExprTree(FILE* filePtr, struct ASTNode* root){

 	// if its a leaf node - NUM or Variable
	if (root->nodetype == 1 || root->nodetype == 2) {

		int reg1 = getReg();
		int val;		

		// NUM Node
		if (root->nodetype == 1)	
			fprintf(filePtr, "MOV R%d, %d\n", reg1, root->val);

		if (root->nodetype == 2)
			fprintf(filePtr, "MOV R%d, [%d]\n", reg1, getVariableAddress(*root->varname));

		return reg1;	
	
	}

	// For internal nodes in the Expression Tree

	int leftRegNo, rightRegNo;

	leftRegNo = evalExprTree(filePtr, root->left);
	rightRegNo = evalExprTree(filePtr, root->right);

	freeReg();

	char op = *root->varname; 

	if (op == '+')
		fprintf(filePtr, "ADD R%d, R%d\n", leftRegNo, rightRegNo);
	
	if (op == '-')
		fprintf(filePtr, "SUB R%d, R%d\n", leftRegNo, rightRegNo);

	if (op == '*')
		fprintf(filePtr, "MUL R%d, R%d\n", leftRegNo, rightRegNo);

	if (op == '/')
		fprintf(filePtr, "DIV R%d, R%d\n", leftRegNo, rightRegNo);
	
	return leftRegNo;
}


