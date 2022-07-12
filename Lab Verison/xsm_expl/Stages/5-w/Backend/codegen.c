#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"
#include "../Frontend/ast.h"
#include "../Data_Structures/loopStack.h"
#include "../Data_Structures/LSTable.h"
#include "../Data_Structures/paramStruct.h"
#include "../Functions/reg.h"
#include "../Functions/xsm_syscalls.h"
#include "../Functions/label.h"

int codeGen(struct ASTNode *root, FILE *filePtr)
{

	// for NULL node
	if (root == NULL)
		return 1;

	// if its a NUM or VARIABLE (array variable as well)
	if (root->nodeType == CONST_INT_NODE || root->nodeType == CONST_STR_NODE || root->nodeType == ID_NODE)
		return 1;

	// for a IF Node
	if (root->nodeType == IF_NODE)
	{

		int labelIfEnd = getLabel();
		int labelElseEnd = 0;

		codeGenWhile(filePtr, root->left, labelIfEnd, 1);
		codeGen(root->middle, filePtr);

		if (root->right != NULL)
		{

			labelElseEnd = getLabel();
			fprintf(filePtr, "JMP L%d\n", labelElseEnd);
		}

		fprintf(filePtr, "L%d:\n", labelIfEnd);

		if (root->right != NULL)
		{
			codeGen(root->right, filePtr);
			fprintf(filePtr, "L%d:\n", labelElseEnd);
		}
		return 1;
	}

	// for a WHILE Node
	if (root->nodeType == WHILE_NODE)
	{

		int labelStart = getLabel();
		int labelEnd = getLabel();

		struct loopStackNode *labelStartNode = createLSNode(labelStart);
		struct loopStackNode *labelEndNode = createLSNode(labelEnd);

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
	if (root->nodeType == DO_WHILE_NODE)
	{

		int labelStart = getLabel();
		int labelEnd = getLabel();

		struct loopStackNode *labelStartNode = createLSNode(labelStart);
		struct loopStackNode *labelEndNode = createLSNode(labelEnd);

		pushLSNode(labelStartNode, labelEndNode);

		fprintf(filePtr, "L%d:\n", labelStart);
		codeGen(root->left, filePtr);
		codeGenWhile(filePtr, root->right, labelStart, 2);
		fprintf(filePtr, "L%d:\n", labelEnd);

		popLSNode();

		return 1;
	}

	// for a BREAK Node
	if (root->nodeType == BREAK_NODE)
	{

		if (LSisEmpty() == 0)
			fprintf(filePtr, "JMP L%d\n", getEndLabel());

		return 1;
	}

	// for a CONTINUE Node
	if (root->nodeType == CONTINUE_NODE)
	{

		if (LSisEmpty() == 0)
			fprintf(filePtr, "JMP L%d\n", getStartLabel());

		return 1;
	}

	// for a BREAKPOINT Node
	if (root->nodeType == BREAKPOINT_NODE)
	{

		fprintf(filePtr, "BRKP\n");
		return 1;
	}

	// for a RETURN Node
	if (root->nodeType == RETURN_NODE)
	{
		int resultRegNo = evalExprTree(filePtr, root->left);
		int returnValueReg = getReg();

		// Save the return value at [BP-2]
		fprintf(filePtr, "MOV R%d, BP\n", returnValueReg);
		fprintf(filePtr, "SUB R%d, 2\n", returnValueReg);
		fprintf(filePtr, "MOV [R%d], R%d\n", returnValueReg, resultRegNo);

		// POP all the local variables
		for (int i = 0; i < getLSTSize() - paramCount; ++i)
			fprintf(filePtr, "POP R0\n");

		// Set BP to old value saved in SP
		fprintf(filePtr, "MOV BP, [SP]\n");
		fprintf(filePtr, "POP R0\n");

		fprintf(filePtr, "RET\n");

		freeReg();
		freeReg();
	}

	codeGen(root->left, filePtr);
	codeGen(root->right, filePtr);

	// for an "=" OPERATOR Node
	if (root->nodeType == ASGN_NODE)
	{

		int resultRegNo = evalExprTree(filePtr, root->right);

		if (root->left->nodeType == MUL_NODE)
		{
			int varAddrReg = evalExprTree(filePtr, root->left->middle);
			fprintf(filePtr, "MOV [R%d], R%d\n", varAddrReg, resultRegNo);
			freeReg();
		}
		else
		{
			fprintf(filePtr, "MOV [R%d], R%d\n", getVariableAddress(filePtr, root->left), resultRegNo);
			freeReg();
		}
		freeReg();
	}

	// for a READ Node
	if (root->nodeType == READ_NODE)
	{

		int varAddrReg = getVariableAddress(filePtr, root->left);
		INT_6(filePtr, -1, varAddrReg);
		freeReg();
	}

	// for a WRITE Node
	if (root->nodeType == WRITE_NODE)
	{

		int resultRegNo = evalExprTree(filePtr, root->left);
		INT_7(filePtr, -2, resultRegNo);
		freeReg();
	}

	return 1;
}

int initVariables(FILE *filePtr)
{

	int reg1 = getReg();

	fprintf(filePtr, "MOV R%d, 0\n", reg1);

	for (int i = 0; i < 26; ++i)
		fprintf(filePtr, "PUSH R%d\n", reg1);

	freeReg();
	return 1;
}

int codeGenWhile(FILE *filePtr, struct ASTNode *root, int label, int option)
{

	// struct ASTNode *LHS;
	// struct ASTNode *RHS;
	// int reg1, reg2;

	// LHS = root->left;
	// RHS = root->right;

	// reg1 = evalExprTree(filePtr, LHS);
	// reg2 = evalExprTree(filePtr, RHS);

	// if (root->nodeType == EQ_NODE)
	// 	fprintf(filePtr, "EQ R%d, R%d\n", reg1, reg2);

	// if (root->nodeType == NE_NODE)
	// 	fprintf(filePtr, "NE R%d, R%d\n", reg1, reg2);

	// if (root->nodeType == LT_NODE)
	// 	fprintf(filePtr, "LT R%d, R%d\n", reg1, reg2);

	// if (root->nodeType == LE_NODE)
	// 	fprintf(filePtr, "LE R%d, R%d\n", reg1, reg2);

	// if (root->nodeType == GT_NODE)
	// 	fprintf(filePtr, "GT R%d, R%d\n", reg1, reg2);

	// if (root->nodeType == GE_NODE)
	// 	fprintf(filePtr, "GE R%d, R%d\n", reg1, reg2);

	int condValueReg = evalExprTree(filePtr, root);

	if (option == 1)
		fprintf(filePtr, "JZ R%d, L%d\n", condValueReg, label);

	if (option == 2)
		fprintf(filePtr, "JNZ R%d, L%d\n", condValueReg, label);

	freeReg();

	return 1;
}

int initFuncCalle(FILE *filePtr, int paramCount)
{
	struct LSTNode *traversalPtr = LSTHead;

	// setting the function parameters binding in the LST
	for (int i = paramCount; i > 0; --i)
	{
		traversalPtr->binding = -(i + 2);
		traversalPtr = traversalPtr->next;
	}

	// pushing and setting new BP = SP
	fprintf(filePtr, "PUSH BP\n");
	fprintf(filePtr, "MOV BP, SP\n");

	int relativeBinding = 1;

	while (traversalPtr != NULL)
	{
		for (int i = 0; i < traversalPtr->size; ++i)
			fprintf(filePtr, "PUSH R0\n");

		traversalPtr->binding = relativeBinding;
		relativeBinding += traversalPtr->size;
		traversalPtr = traversalPtr->next;
	}

	// LSTPrint();

	return 1;
}

int codeGenFuncCaller(FILE *filePtr, struct ASTNode *funcNode)
{

	// Push all registers in use to stack
	for (int i = 0; i <= getRegNumValue(); ++i)
	{
		fprintf(filePtr, "PUSH R%d\n", i);
	}
}