#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "label.h"

int labelNum = -1;

int getLabel(){
	++labelNum;
	return labelNum;
}

int calcLabelAddress(int lineNumber){
	return 2056 + 2*(lineNumber - 9);
}

// initialising the Label Address Table (linked list) head 
struct labelAddressNode* headLAT = NULL;
struct labelAddressNode* tailLAT = NULL;

struct labelAddressNode* createLabelAddressNode(int labelNum, int address){

	// allocating memory for the new node
	struct labelAddressNode* newNode;
	newNode = (struct labelAddressNode*)malloc(sizeof(struct labelAddressNode));

	newNode->labelNum = labelNum;
	newNode->address = address;
	newNode->next = NULL;

	return newNode;
}


struct labelAddressNode* insertLabelAddressNode(struct labelAddressNode* newNode){

	// if linked list is empty
	if (headLAT == NULL) {
		headLAT = newNode;	
		tailLAT = newNode;
	}
	else {
		tailLAT->next = newNode;
		tailLAT = newNode;
	}
			
	return headLAT; 
}

int getLabelAddress(int labelNum){

	if (headLAT == NULL){
		printf("\nError: Label Doesn't Exists\n");
		exit(1);
	}

	// to traverse though the Linked List
	struct labelAddressNode* temp = headLAT;	

	while(temp) {
		if (temp->labelNum == labelNum)
			return temp->address;
		temp = temp->next;
	}

	return -1;

}

int printLabelAddressTable(){

	struct labelAddressNode* temp = headLAT;
	
	while (temp != NULL){
		printf("\nLabel Number: %d\n", temp->labelNum);
		printf("Address: %d\n", temp->address);
		temp = temp->next;
	}	
	
	return 1;
}
