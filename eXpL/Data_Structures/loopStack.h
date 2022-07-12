/**
 * Stack Data Structure to know which loop the program
 * is currently running in
 */

#ifndef LOOPSTACK_H

#define LOOPSTACK_H

struct loopStackNode
{
	int labelNum;
	struct loopStackNode *next;
} lsnode;

// head of the loop stack
extern struct loopStackNode *LSHead;

// to create a loopStackNode
struct loopStackNode *createLSNode(int val);

// to insert node into loopstack node
struct loopStackNode *pushLSNode(struct loopStackNode *loopStart, struct loopStackNode *loopEnd);

// to get the start label number of current while loop
int getStartLabel();

// to get the end label number of current while loop
int getEndLabel();

// to pop the start and end label node from the stack
int popLSNode();

// to check if the loop Stack is empty or not
int LSisEmpty();

// print the loop stack
int printLS();

#endif
