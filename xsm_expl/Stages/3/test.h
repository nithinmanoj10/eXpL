#ifndef TEST_H 

#define TEST_H

struct node{
	int val;
	struct node* next;
} lnode;

// Function to insert into a LL
struct node* insertLL(struct node* head, int val);

// Print LL
int printLL(struct node* head);

#endif
