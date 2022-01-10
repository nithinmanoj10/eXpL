#ifndef GSTABLE_H

#define GSTABLE_H

#include "declarationsTree.h"

/**
 *	Linked List Data structure that holds information
 *	about all the variables declared in the program.
 */

struct globalSTNode {
	char* name;
	int type;
	int size;
	int binding;
	struct globalSTNode* next;
}gstNode;

/**
 *	Global Variables pointing to the head and tail 
 *	of the Global Symbol Table
 */
extern struct globalSTNode* GSTHead;
extern struct globalSTNode* GSTTail;

/**
 *	Function to create a Global Symbol Table Entry
 *
 *	@params		name:		Name of the variable
 *
 *	   				type:		Type of variable
 *	   								1 - int
 *	   								2 - str
 *
 *	   				size:		Size of the variable, set to 1 for now
 *
 *	@return		1:			Successfully Created
 *						0:			Variable already exists
 *						-1:			Unknown variable type
 *						-2:			Invalid Size
 */
int createGSTNode(char* name, int type, int size);

/**
 *	Function to search for a variable in the Global Symbol Table Entry
 *
 *	@params		name:		Name of the variable
 *
 *	@return		node:		Node to be searched, if found
 *						NULL:		If node doesnt exists
 */
struct globalSTNode* searchGSTNode(char* name);


/**
 *	Function to create the entire Global Symbol Table from
 *	the declarations tree.
 *
 *	@params		root:		Root of the Declarations Tree
 *
 *	@return 	1:			Successfully Created
 *						2:			No declarations made
 */
int createGST(struct declarationsTree* root, int varType);

int printGST();

#endif
