#include "evalTree.h"

int evalTree(struct ASTNode* root){

	// for leaf nodes - NUM and variable
	if (root->left == NULL && root->right == NULL)
		return 1;

	// for READ nodes
	if (root->nodetype == 4) {

		int variableLocation = root->left->varchar - 97;
		scanf("%d", variableStorage[variableLocation]);

	}	

}
