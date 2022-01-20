#ifndef GETLABEL_H

#define GETLABEL_H

// Keeps count of number of labels used
extern int labelNum;

// Keeps count of number of Function Labels used
// Label F0 is reserved for int main()
extern int funcLabelNum;

/**
 * Function to return an unused label number
 *
 * @params	none
 *
 * @return	[0,]:		Positive label number starting from 0
 */
int getLabel();

/**
 * @brief Get the funcLabelNum
 * 
 * @return int 
 */
int getFuncLabel();

/**
 * Function to calculate the address from line number
 *
 * @params	lineNumber:	Line number of the label
 *
 * @return	address:	Address of that label
 */
int calcLabelAddress(int lineNumber);

/**
 * Node of labelAddressLL
 */
struct labelAddressNode
{
	int labelNum;
	int address;
	struct labelAddressNode *next;
} lanode;

/**
 * Function to create a labelAddress Node
 *
 * @params	labelNum:	The Label Number
 *
 * 		address:	The address of the respective label
 *
 * @return	newLabelNode:	Pointer to the newly created labelAddress Node
 */
struct labelAddressNode *createLabelAddressNode(int labelNum, int address);

/**
 * Function to insert a node to labelAddressLL
 *
 * @params	head:		Head of the Linked List
 *		
 *  		newNode:	New node to be inserted
 *
 * @return	head:		Head of the Linked List
 */
struct labelAddressNode *insertLabelAddressNode(struct labelAddressNode *newNode);

/**
 * Function to get the address of a given label
 *
 * @params	labelNum:	The label number
 *
 * @return	address:	Address of the label number
 *
 *		-1:		If address doesnt exists
 */
int getLabelAddress(int labelNum);

/**
 * Global variable pointing to the head of the Label Address Table (linked list)
 */
extern struct labelAddressNode *headLAT;
extern struct labelAddressNode *tailLAT;

int printLabelAddressTable();

#endif
