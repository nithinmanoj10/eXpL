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
#include "../Functions/stackMemory.h"
#include "../Functions/xsm_library.h"

int codeGen(struct ASTNode *root, FILE *filePtr)
{

	if (root == NULL)
		return 1;

	if (root->nodeType == NULL_NODE)
		return 1;

	// if its a NUM or VARIABLE (array variable as well)
	if (root->nodeType == CONST_INT_NODE || root->nodeType == CONST_STR_NODE || root->nodeType == ID_NODE)
		return 1;

	if (root->nodeType == FIELD_NODE || root->nodeType == TUPLE_NODE)
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

		if (root->right->nodeType == NULL_NODE)
		{
			fprintf(filePtr, "MOV [R%d], \"null\"\n", getVariableAddress(filePtr, root->left));

			freeReg(); // variableAddrReg from getVariableAddress()
			return 1;
		}

		if (root->right->nodeType == INITIALIZE_NODE)
		{
			multipush(filePtr);

			int returnReg = Initialize(filePtr);
			fprintf(filePtr, "MOV [R%d], R%d\n", getVariableAddress(filePtr, root->left), returnReg);

			freeReg(); // variableAddrReg from getVariableAddress()
			freeReg(); // tempReg from Initialize()
			freeReg(); // returnReg from Initialize()

			multipop(filePtr);
			return 1;
		}

		if (root->right->nodeType == ALLOC_NODE)
		{
			multipush(filePtr);

			int returnReg = Alloc(filePtr);
			fprintf(filePtr, "MOV [R%d], R%d\n", getVariableAddress(filePtr, root->left), returnReg);

			freeReg(); // variableAddrReg from getVariableAddress()
			freeReg(); // tempReg from Alloc()
			freeReg(); // returnReg from Alloc()

			multipop(filePtr);
			return 1;
		}

		if (root->right->nodeType == FREE_NODE)
		{
			multipush(filePtr);

			struct ASTNode *allocNode = root->right;

			int exprReg = evalExprTree(filePtr, allocNode->left);
			int returnReg = Free(filePtr, exprReg);
			fprintf(filePtr, "MOV [R%d], R%d\n", getVariableAddress(filePtr, root->left), returnReg);

			freeReg(); // variableAddrReg from getVariableAddress()
			freeReg(); // tempReg from Free()
			freeReg(); // returnReg from Free()
			freeReg(); // returnValueReg from evalExprTree()

			multipop(filePtr);
			return 1;
		}

		struct ASTNode *LHS = root->left;
		struct ASTNode *RHS = root->right;

		// For tuple constructors
		if (LHS->typeTablePtr->typeCategory == TYPE_TUPLE && RHS->nodeType == TUPLE_CONSTRUCTOR_NODE)
		{
			constructTuple(filePtr, LHS, RHS->argListHead);
			return 1;
		}

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

		struct ASTNode *writeArgument = root->left;

		// for printing an entire tuple
		if (writeArgument->nodeType == ID_NODE && writeArgument->typeTablePtr->typeCategory == TYPE_TUPLE)
		{
			printTuple(filePtr, writeArgument);
		}
		else
		{
			int resultRegNo = evalExprTree(filePtr, writeArgument);
			INT_7(filePtr, -2, resultRegNo);
			freeReg();
		}
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

void initStackBP(FILE *filePtr)
{
	int freeStackMem = getFreeStackMemoryValue();
	fprintf(filePtr, "MOV SP, %d\n", freeStackMem - 1);
	fprintf(filePtr, "MOV BP, %d\n", freeStackMem);
	fprintf(filePtr, "PUSH R0\n");
	fprintf(filePtr, "CALL F0\n");
	fprintf(filePtr, "INT 10\n");
}

void printTuple(FILE *filePtr, struct ASTNode *root)
{

	// find the LST Entry for the tuple
	struct LSTNode *tupleLSTEntry = LSTLookup(root->nodeName);

	// if not present in LST, search in GST
	if (tupleLSTEntry == NULL)
	{
		struct GSTNode *tupleGSTEntry = GSTLookup(root->nodeName);

		int tupleAddrReg = getReg();  // holds address of current tuple field
		int tupleFieldReg = getReg(); // holds tuple field value that has to be printed
		fprintf(filePtr, "MOV R%d, %d\n", tupleAddrReg, tupleGSTEntry->binding);

		for (int fieldIndex = 0; fieldIndex < tupleGSTEntry->size; ++fieldIndex)
		{
			fprintf(filePtr, "MOV R%d, [R%d]\n", tupleFieldReg, tupleAddrReg);
			INT_7(filePtr, -2, tupleFieldReg);
			fprintf(filePtr, "ADD R%d, %d\n", tupleAddrReg, 1);
		}

		freeReg(); // tupleFieldReg from printTuple()
		freeReg(); // tupleAddrReg from printTuple()
	}
	else
	{
		// TODO : For tuples declared locally
	}
}

void constructTuple(FILE *filePtr, struct ASTNode *tupleID, struct ASTNode *tupleFields)
{

	// check if tuple is present in LST
	struct LSTNode *tupleLSTEntry = LSTLookup(tupleID->nodeName);

	// if not present in LST, search in GST
	if (tupleLSTEntry == NULL)
	{
		struct GSTNode *tupleGSTEntry = GSTLookup(tupleID->nodeName);

		int tupleAddrReg = getReg();  // holds address of current tuple field
		int tupleFieldReg = getReg(); // holds tuple field value that has to be added to the tuple
		fprintf(filePtr, "MOV R%d, %d\n", tupleAddrReg, tupleGSTEntry->binding);

		for (int fieldIndex = 0; fieldIndex < tupleGSTEntry->size; ++fieldIndex)
		{
			if (tupleFields->nodeType == CONST_INT_NODE)
				fprintf(filePtr, "MOV R%d, %d\n", tupleFieldReg, tupleFields->intConstVal);
			if (tupleFields->nodeType == CONST_STR_NODE)
				fprintf(filePtr, "MOV R%d, \"%s\"\n", tupleFieldReg, tupleFields->strConstVal);

			fprintf(filePtr, "MOV [R%d], R%d\n", tupleAddrReg, tupleFieldReg);
			fprintf(filePtr, "ADD R%d, 1\n", tupleAddrReg);

			tupleFields = tupleFields->argListNext;
		}

		freeReg(); // tupleFieldReg from printTuple()
		freeReg(); // tupleAddrReg from printTuple()
	}
	else
	{
		// TODO : For tuples declared locally
	}
}