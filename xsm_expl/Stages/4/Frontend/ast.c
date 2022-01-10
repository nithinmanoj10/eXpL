#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Functions/reg.h"
#include "ast.h"
#include "../Data_Structures/globalSymbolTable.h"

struct ASTNode* createASTNode(int val, int type, int nodetype, char* varname, struct ASTNode* left, struct ASTNode* middle, struct ASTNode* right) {

	// dynamically allocates space for the new node
	struct ASTNode* newASTNode = (struct ASTNode*)malloc(sizeof(struct ASTNode));
	newASTNode->varname = malloc(sizeof(char));

	// assigns each property of the node
	newASTNode->val = val;
	newASTNode->type = type;
	newASTNode->nodetype = nodetype;
	strcpy(newASTNode->varname, varname);
	newASTNode->left = left;
	newASTNode->middle = middle;
	newASTNode->right = right;

	if (nodetype != 2)
		newASTNode->GSTEntry = NULL; 	
	else {
		newASTNode->GSTEntry = searchGSTNode(varname);
		if (newASTNode->GSTEntry == NULL){
			printf("\n❌ Undeclared variable %s used in program\n", varname);
			exit(1);
		}
	}

	return newASTNode;
}

int printAST(struct ASTNode* root){

	if(root == NULL)
		return 1;

	printAST(root->left);
	printAST(root->middle);
	printAST(root->right);

	printf("val: %d\n", root->val);
	printf("type: %d\n", root->type);
	printf("varname: %s\n", root->varname);
	printf("nodetype: %d\n", root->nodetype);
	printf("left: %p\n", root->left);
	printf("right: %p\n", root->right);
	printf("GST: %p\n", root->GSTEntry);

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
int getVariableAddress(struct ASTNode* root){
	return root->GSTEntry->binding;
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
			fprintf(filePtr, "MOV R%d, [%d]\n", reg1, getVariableAddress(root));

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
	
	if (op == '%')
		fprintf(filePtr, "MOD R%d, R%d\n", leftRegNo, rightRegNo);

	return leftRegNo;
}


