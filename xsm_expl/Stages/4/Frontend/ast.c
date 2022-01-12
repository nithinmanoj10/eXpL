#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Functions/reg.h"
#include "ast.h"
#include "../Data_Structures/globalSymbolTable.h"

struct ASTNode* createASTNode(int val, int type, int nodetype, char* varname, int arrayOffset, struct ASTNode* left, struct ASTNode* middle, struct ASTNode* right) {

	// dynamically allocates space for the new node
	struct ASTNode* newASTNode = (struct ASTNode*)malloc(sizeof(struct ASTNode));
	newASTNode->varname = malloc(sizeof(char));

	// assigns each property of the node
	newASTNode->val = val;
	newASTNode->type = type;
	newASTNode->nodetype = nodetype;
	strcpy(newASTNode->varname, varname);
	newASTNode->arrayOffset = arrayOffset;
	newASTNode->left = left;
	newASTNode->middle = middle;
	newASTNode->right = right;

	if (nodetype != 2)
		newASTNode->GSTEntry = NULL; 	
	else {
		newASTNode->GSTEntry = searchGSTNode(varname);
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
	printf("arrayOffset: %d\n", root->arrayOffset);
	printf("left: %p\n", root->left);
	printf("right: %p\n", root->right);
	printf("GST: %p\n", root->GSTEntry);

	printf("\n");
	return 1;
}

/**
 * @brief	Function that returns the register number in which the 
 * 			address of the required variable is stored
 * 
 * @param 	filePtr	File pointer of the target file
 * @param 	root	ASTNode of the variable	 
 * @return 	int		Address of the variable		 
 */
int getVariableAddress(FILE* filePtr, struct ASTNode* root){

	int variableAddrReg = getReg();
	int variableAddr = root->GSTEntry->binding;
	int offset = root->arrayOffset;
	
	fprintf(filePtr, "MOV R%d, %d\n", variableAddrReg, variableAddr);

	// for array variable
	if (offset != -1)
		fprintf(filePtr, "ADD R%d, %d\n", variableAddrReg, offset);

	freeReg();
	return variableAddrReg;
}

int evalExprTree(FILE* filePtr, struct ASTNode* root){

 	// if its a leaf node - NUM, Variable or STR
	if (root->nodetype == 1 || root->nodetype == 2 || root->nodetype == 9) {

		int reg1 = getReg();
		int val;		

		// if its an array variable
		if (root->left != NULL && root->nodetype == 2) {

			fprintf(filePtr, "MOV R%d, [R%d]\n", reg1, getVariableAddress(filePtr, root));
			return reg1;
		}

		// NUM Node
		if (root->nodetype == 1)	
			fprintf(filePtr, "MOV R%d, %d\n", reg1, root->val);

		// Variable Node
		if (root->nodetype == 2)
			fprintf(filePtr, "MOV R%d, [R%d]\n", reg1, getVariableAddress(filePtr, root));

		// STR Node
		if (root->nodetype == 9)
			fprintf(filePtr, "MOV R%d, \"%s\"\n", reg1, root->varname);

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


