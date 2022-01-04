#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int main(){

	struct node* head;
	head = (struct node*)malloc(sizeof(struct node));
	head->val = 10;
	head->next = NULL;

	head = insertLL(head, 12);
	head = insertLL(head, 2);

	printLL(head);
	printf("\n");
	
	return 0;
}
