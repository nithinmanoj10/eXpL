#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globalSymbolTable.h"
#include "declarationsTree.h"
#include "../Functions/stackMemory.h"

struct globalSTNode* GSTHead = NULL;
struct globalSTNode* GSTTail = NULL;

int createGSTNode(char* name, int type, int size) {

	if (searchGSTNode(name) != NULL) {
		printf("\n❌ Variable %s already declared\n", name);
		exit(0);
	}

	if (type != 1 && type != 2) {
		printf("\n❌ Variable %s of invalid type\n", name);
		exit(-1);
	}

	if (size < 1)	{
		printf("\n❌ Variable %s provided with invalid size\n", name);
		exit(-2);
	}

	struct globalSTNode* newNode;
	newNode = (struct globalSTNode*)malloc(sizeof(struct globalSTNode));
	newNode->name = malloc(sizeof(char*));

	strcpy(newNode->name, name);
	newNode->type = type;
	newNode->size = size;
	newNode->next = NULL;
	newNode->binding = getFreeStackMemory(size);
	
	// if GST is empty
	if (GSTHead == NULL && GSTTail == NULL) {

		GSTHead = newNode;
		GSTTail = newNode;
		return 1;
	}

	GSTTail->next = newNode;
	GSTTail = newNode;

	return 1;
}

struct globalSTNode* searchGSTNode(char* name) {

	// if Global Symbol Table is empty
	if (GSTHead == NULL && GSTTail == NULL)
		return NULL;

	struct globalSTNode* temp = GSTHead;

	while (temp != NULL) {

		if (strcmp(temp->name, name) == 0)
			return temp;

		temp = temp->next;
	}

	return NULL;
}

int createGST(struct declarationsTree* root, int varType) {

	if (root == NULL)
		return 1;

	if (root->nodeType == 1) {	

		createGST(root->left, root->varType);	
		return 1;
	}

	createGST(root->left, varType);
	createGST(root->right, varType);		

	if (root->nodeType == 2)
		createGSTNode(root->varName, varType, root->varSize);

	return 1;
}

int printGST() {

	struct globalSTNode* temp = GSTHead;

	while (temp != NULL) {

		printf("\nname: %s\n", temp->name);
		printf("type: %d\n", temp->type);
		printf("size: %d\n", temp->size);
		printf("binding: %d\n", temp->binding);
		printf("GST: %p\n", temp);

		temp = temp->next;
	}

	return 1;
}
