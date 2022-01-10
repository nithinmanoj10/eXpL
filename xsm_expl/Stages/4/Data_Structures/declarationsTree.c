#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declarationsTree.h"

struct declarationsTree* createDTNode(int nodeType, int varType, char* varName, struct declarationsTree* left, struct declarationsTree* right) {

	struct declarationsTree* newNode;
	newNode = (struct declarationsTree*)malloc(sizeof(struct declarationsTree));
	newNode->varName = malloc(sizeof(char*));

	newNode->nodeType = nodeType;
	newNode->varType = varType;
	strcpy(newNode->varName, varName);
	newNode->left = left;
	newNode->right = right;

	return newNode;
}

int printDeclarationsTree(struct declarationsTree* root) {

	if (root == NULL)
		return 1;

	if (root->nodeType == 1) {
			
			printf("%s: ", root->varName);
			struct declarationsTree* temp = root->left;

			while (temp != NULL) {
				printf("%s ", temp->varName);
				temp = temp->left;
			}
			printf("\n");

			return 1;
	}

	printDeclarationsTree(root->left);
	printDeclarationsTree(root->right);

	return 1;
}
