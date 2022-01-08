#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"
#include "../Frontend/ast.h"
#include "../Data_Structures/loopStack.h"
#include "../Functions/reg.h"
#include "../Functions/xsm_syscalls.h"
#include "../Functions/label.h"

int codeGen(struct ASTNode* root, FILE* filePtr){


	// for NULL node
	if(root == NULL)
		return 1;

	// if its a NUM or VARIABLE
	if (root->nodetype == 1 || root->nodetype == 2)
		return 1;

	char* nodeName = malloc(sizeof(char));
	strcpy(nodeName, root->varname);

	// for a IF Node
	if (root->nodetype == 7 && *root->varname == 'I') {

		int labelIfEnd = getLabel();
		int labelElseEnd = 0;

		codeGenWhile(filePtr, root->left, labelIfEnd, 1);	
		codeGen(root->middle, filePtr);

		if (root->right != NULL) {
		
			labelElseEnd = getLabel();
			fprintf(filePtr, "JMP L%d\n", labelElseEnd);
		}

		fprintf(filePtr, "L%d:\n", labelIfEnd);

		if (root->right != NULL) { 
			codeGen(root->right, filePtr);
			fprintf(filePtr, "L%d:\n", labelElseEnd);
		}
		return 1;
	}

	// for a WHILE Node
	if (root->nodetype == 7 && *root->varname == 'W') {

		int labelStart = getLabel();
		int labelEnd = getLabel();

		struct loopStackNode* labelStartNode = createLSNode(labelStart);
		struct loopStackNode* labelEndNode = createLSNode(labelEnd);
	
		pushLSNode(labelStartNode, labelEndNode);
	
		fprintf(filePtr, "L%d:\n", labelStart);
		codeGenWhile(filePtr, root->left, labelEnd, 1);
		codeGen(root->right, filePtr);
		fprintf(filePtr, "JMP L%d\n", labelStart);
		fprintf(filePtr, "L%d:\n", labelEnd);				
		
		popLSNode();

		return 1;
	}

	// for a DO WHILE Node
	if (root->nodetype == 7 && strcmp(nodeName, "DW") == 0) {

		int labelStart = getLabel();
		int labelEnd = getLabel();	

		struct loopStackNode* labelStartNode = createLSNode(labelStart);
		struct loopStackNode* labelEndNode = createLSNode(labelEnd);
	
		pushLSNode(labelStartNode, labelEndNode);

		fprintf(filePtr, "L%d:\n", labelStart);
		codeGen(root->left, filePtr);
		codeGenWhile(filePtr, root->right, labelStart, 2);
		fprintf(filePtr, "L%d:\n", labelEnd);				

		popLSNode();

		return 1;
	}

	// for a BREAK Node
	if (root->nodetype == 7 && *root->varname == 'B') {

		if (LSisEmpty() == 0)
			fprintf(filePtr, "JMP L%d\n", getEndLabel());	
		
		return 1;
	}

	// for a CONTINUE Node
	if (root->nodetype == 7 && *root->varname == 'C') {

		if (LSisEmpty() == 0)
			fprintf(filePtr, "JMP L%d\n", getStartLabel());	
		
		return 1;
	}
	
	codeGen(root->left, filePtr);
	codeGen(root->right, filePtr);

	char* conditionalOp = malloc(sizeof(char));
	strcpy(conditionalOp, root->varname);
	

	// for an "=" OPERATOR Node
	if (root->nodetype == 3 && strcmp(conditionalOp, "=") == 0) {

		int resultRegNo = evalExprTree(filePtr, root->right);
		fprintf(filePtr, "MOV [%d], R%d\n", getVariableAddress(*root->left->varname), resultRegNo);
		freeReg();

	}

	// for a READ Node
	if (root->nodetype == 4) {

		int varAddr = getVariableAddress(*(root->left->varname));
		INT_6(filePtr, -1, varAddr);
	}

 	// for a WRITE Node
	if (root->nodetype == 5) {

		fprintf(filePtr, "BRKP\n");	
		int resultRegNo = evalExprTree(filePtr, root->left);
		fprintf(filePtr, "MOV [5000], R%d\n", resultRegNo);
		freeReg();
		INT_7(filePtr, -2, "null");
	}


	return 1;
}

int initVariables(FILE* filePtr){

	int reg1 = getReg();
	
	fprintf(filePtr, "MOV R%d, 0\n", reg1);

	for(int i = 0; i < 26; ++i)
		fprintf(filePtr, "PUSH R%d\n", reg1);

	freeReg();
	return 1;
}

int codeGenWhile(FILE* filePtr, struct ASTNode* root, int label, int option){

	struct ASTNode* LHS;
	struct ASTNode* RHS;
	int reg1, reg2;
	char* conditionalOp = malloc(sizeof(char));

	LHS = root->left;
	RHS = root->right;
	strcpy(conditionalOp, root->varname);

//	reg1 = getReg();
//	reg2 = getReg();

//	(LHS->nodetype == 1)
//	?	fprintf(filePtr, "MOV R%d, %d\n", reg1, LHS->val)				// if its a NUM
//	:	fprintf(filePtr, "MOV R%d, [%d]\n", reg1, getVariableAddress(*LHS->varname));  	// if its a VARIABLE

//	(RHS->nodetype == 1)
//	?	fprintf(filePtr, "MOV R%d, %d\n", reg2, RHS->val)				// if its a NUM
//	:	fprintf(filePtr, "MOV R%d, [%d]\n", reg2, getVariableAddress(*RHS->varname));  	// if its a VARIABLE

	reg1 = evalExprTree(filePtr, LHS);
	reg2 = evalExprTree(filePtr, RHS);

	if (strcmp(conditionalOp, "==") == 0)
		fprintf(filePtr, "EQ R%d, R%d\n", reg1, reg2);

	if (strcmp(conditionalOp, "!=") == 0)
		fprintf(filePtr, "NE R%d, R%d\n", reg1, reg2);

	if (strcmp(conditionalOp, "<") == 0)
		fprintf(filePtr, "LT R%d, R%d\n", reg1, reg2);

	if (strcmp(conditionalOp, "<=") == 0)
		fprintf(filePtr, "LE R%d, R%d\n", reg1, reg2);

	if (strcmp(conditionalOp, ">") == 0)
		fprintf(filePtr, "GT R%d, R%d\n", reg1, reg2);

	if (strcmp(conditionalOp, ">=") == 0)
		fprintf(filePtr, "GE R%d, R%d\n", reg1, reg2);


	if (option == 1)
		fprintf(filePtr, "JZ R%d, L%d\n", reg1, label);

	if (option == 2)
		fprintf(filePtr, "JNZ R%d, L%d\n", reg1, label);
		

	freeReg();
	freeReg();

	return 1;
}
