#include <stdlib.h>
#include <stdio.h>
#include "test.h"

struct node* insertLL(struct node* head, int val){

	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->val = val;

	struct node* temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;
	return head;
}

int printLL(struct node* head){

	struct node* temp = head;

	while(temp != NULL){
		printf("%d ", temp->val);
		temp = temp->next;
	}
	
	return 1;
}
