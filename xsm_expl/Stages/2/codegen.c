#include <stdio.h>
#include <stdlib.h>
#include "codegen.h"
#include "../Functions/reg.c"

int codeGen(struct ASTNode* root, FILE* filePtr){

	int varAddr;

	// if its a leaf node
	if (root->left == NULL && root->right == NULL)
		return 1;

	// for a READ Node
	if (root->nodetype == 4) {

		varAddr = getVariableAddress(*(root->left->varname));
		return 1;
	}

	return 1;
}
