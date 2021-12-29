#include <stdio.h>
#include "codegen.h"
#include "reg.c"

int codeGen(struct treeNode* root, FILE* targetFile){

	// if it is a leaf node
	if (root->op == NULL){
		
		int regNo = getReg();

		fprintf(targetFile, "MOV R%d, %d\n", regNo, root->val);			// MOV R0, 3
		return regNo;
	}	

	// Following code will be executed if its an internal node

	int leftRegNo, rightRegNo;

	// traversing through the expression tree 
	// in a Post Order fashion
	leftRegNo = codeGen(root->left, targetFile);
	rightRegNo = codeGen(root->right, targetFile);

	freeReg();

	char op = *(root->op);

	if (op == '+')
		fprintf(targetFile, "ADD R%d, R%d\n", leftRegNo, rightRegNo);		// ADD R0, R1	
	if (op == '-')
		fprintf(targetFile, "SUB R%d, R%d\n", leftRegNo, rightRegNo);		// SUB R0, R1
	if (op == '*')
		fprintf(targetFile, "MUL R%d, R%d\n", leftRegNo, rightRegNo);		// MUL R0, R1
	if (op == '/')
		fprintf(targetFile, "DIV R%d, R%d\n", leftRegNo, rightRegNo);		// DIV R0, R1

	// returning the register number where the
	// result for the subtree is stored
	return leftRegNo;
}
