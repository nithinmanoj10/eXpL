#include <stdio.h>
#include <stdlib.h>
#include "intepreter.h"

int codeIntepreter(struct ASTNode* root){


	// for NULL node
	if(root == NULL)
		return 1;

	// if its a leaf node
	if (root->left == NULL && root->right == NULL)
		return 1;

	codeIntepreter(root->left);
	codeIntepreter(root->right);

	// for an "=" OPERATOR Node
	if (root->nodetype == 3 && *root->varname == '=') {

		int variable = *root->left->varname - 97;
		int num = evalExprTree(root->right);

		variableStorage[variable] = num;	
		
		return 1;
	}

	// for a READ Node
	if (root->nodetype == 4) {
		
		int variable = *root->left->varname - 97;
		int num;
		char buffer[1024];

		fgets(buffer, 1024, stdin);
		num = atoi(buffer);		

		variableStorage[variable] = num;

		return 1;
	}

 	// for a WRITE Node
	if (root->nodetype == 5) {
		
		int num;

		num = evalExprTree(root->left);
		printf("%d\n", num);

		return 1;
	}
}
