#include <stdio.h>
#include "codegen.h"
#include "reg.c"

int codeGen(struct treeNode* root, FILE* targetFile){

	// if it is a leaf node
	if (root->op == NULL){
		
		// allocating a free register to store
		// the leaf node value
		int regNo = getReg();

		/** 
		 * eg.	regNo = 1
		 *	root->val = 3
		 *	targetFile = target.xsm	
		 *
		 *	"MOV R1, 3" written in target.xsm
		 */
		fprintf(targetFile, "MOV R%d, %d\n", regNo, root->val);
		return regNo;
	}	

	// Following code will be executed if its an internal node

	int leftRegNo, rightRegNo;

	// traversing through the expression tree 
	// in a Post Order fashion
	leftRegNo = codeGen(root->left, targetFile);
	rightRegNo = codeGen(root->right, targetFile);

	// freeing the right register used
	freeReg();

	char op = *(root->op);

	/** 
	 * eg.	leftRegNo = 1
	 *	rightRegNo = 2
	 *	targetFile = target.xsm	
	 *
	 *	"ADD R1, R2" written in target.xsm
	 */
	if (op == '+')
		fprintf(targetFile, "ADD R%d, R%d\n", leftRegNo, rightRegNo);	

	// returning the register number where the
	// result for the subtree is stored
	return leftRegNo;
}
