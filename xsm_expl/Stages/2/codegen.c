#include <stdio.h>
#include <stdlib.h>
#include "codegen.h"
#include "../Functions/reg.c"
#include "../Functions/xsm_syscalls.h"

int codeGen(struct ASTNode* root, FILE* filePtr){

	// for NULL node
	if(root == NULL)
		return 1;

	// if its a leaf node
	if (root->left == NULL && root->right == NULL)
		return 1;

	codeGen(root->left, filePtr);
	codeGen(root->right, filePtr);

	// for an "=" OPERATOR Node
	if (root->nodetype == 3 && *root->varname == '=') {

		int resultRegNo = evalExprTree(filePtr, root->right);
		fprintf(filePtr, "MOV [%d], R%d\n", getVariableAddress(*root->left->varname), resultRegNo);

		return 1;

	}

	// for a READ Node
	if (root->nodetype == 4) {

		int varAddr = getVariableAddress(*(root->left->varname));
		INT_6(filePtr, -1, varAddr);

		return 1;
	}

 	// for a WRITE Node
	if (root->nodetype == 5) {
		fprintf(filePtr, "BRKP\n");	
		int resultRegNo = evalExprTree(filePtr, root->left);
		fprintf(filePtr, "MOV [5000], R%d\n", resultRegNo);
		INT_7(filePtr, -2, "null");
		return 1;
	}
}

int initVariables(FILE* filePtr){

	int reg1 = getReg();
	
	fprintf(filePtr, "MOV R%d, 0\n", reg1);

	for(int i = 0; i < 26; ++i)
		fprintf(filePtr, "PUSH R%d\n", reg1);

	freeReg();
	return 1;
}
