#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"
#include "../Frontend/ast.h"
#include "../Data_Structures/loopStack.h"
#include "../Data_Structures/LSTable.h"
#include "../Data_Structures/paramStruct.h"
#include "../Data_Structures/classTable.h"
#include "../Data_Structures/memberFuncList.h"
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

	// for-loops
	if (root->nodeType == FOR_NODE)
	{

		int forLoopStartLabel = getLabel();
		int forLoopUpdateLabel = getLabel();
		int forLoopEndLabel = getLabel();

		struct loopStackNode *labelStartNode = createLSNode(forLoopUpdateLabel);
		struct loopStackNode *labelEndNode = createLSNode(forLoopEndLabel);

		pushLSNode(labelStartNode, labelEndNode);

		// evaluate the initialization statement
		codeGen(root->left, filePtr);

		// start of the for loop:
		fprintf(filePtr, "L%d:\n", forLoopStartLabel);

		// testExprReg holds the result of the Test Expression
		// of the for-loop. 1 if it's true, else 0
		int testExprReg = evalExprTree(filePtr, root->middle);

		// if test expression evalautes to false, jump to
		// the end of the for loop, else continue
		fprintf(filePtr, "JZ R%d, L%d\n", testExprReg, forLoopEndLabel);

		// generate codegen for the for-loop Statements
		codeGen(root->loopStmts, filePtr);

		fprintf(filePtr, "L%d:\n", forLoopUpdateLabel);

		// generate codegen for the for-loop update expression
		codeGen(root->right, filePtr);

		// Jump back to the start of the for-loop
		fprintf(filePtr, "JMP L%d\n", forLoopStartLabel);

		// end of the for loop
		fprintf(filePtr, "L%d:\n", forLoopEndLabel);

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

		if (root->right->nodeType == NEW_NODE)
		{
			multipush(filePtr);

			struct ASTNode *newNode = root->right;
			struct ASTNode *classVarNode = newNode->left;

			int newHeapAddrReg = Alloc(filePtr);
			int varAddressReg = getVariableAddress(filePtr, root->left);

			fprintf(filePtr, "MOV [R%d], R%d\n", varAddressReg, newHeapAddrReg);
			fprintf(filePtr, "ADD R%d, 1\n", varAddressReg);
			fprintf(filePtr, "MOV [R%d], %d\n", varAddressReg, getClassVirtFuncAddress(newNode->left->nodeName));

			freeReg(); // variableAddrReg from getVariableAddress();
			freeReg(); // tempReg from Alloc()
			freeReg(); // returnReg from Alloc()

			multipop(filePtr);
			return 1;
		}

		struct ASTNode *LHS = root->left;
		struct ASTNode *RHS = root->right;

		// For tuple constructors
		if (LHS->typeTablePtr)
		{
			if (LHS->typeTablePtr->typeCategory == TYPE_TUPLE && RHS->nodeType == TUPLE_CONSTRUCTOR_NODE)
			{
				constructTuple(filePtr, LHS, RHS->argListHead);
				return 1;
			}

			// For tuple assignments
			if (LHS->typeTablePtr->typeCategory == TYPE_TUPLE && RHS->typeTablePtr->typeCategory == TYPE_TUPLE)
			{
				assignTuple(filePtr, LHS, RHS);
				return 1;
			}
		}

		// class assignment
		if (LHS->classTablePtr != NULL && RHS->classTablePtr != NULL)
		{
			int LHSVarAddrReg = getVariableAddress(filePtr, root->left);
			int RHSVarAddrReg = getVariableAddress(filePtr, root->right);
			int classValReg = getReg();

			// saving the heap address
			fprintf(filePtr, "MOV R%d, [R%d]\n", classValReg, RHSVarAddrReg);
			fprintf(filePtr, "MOV [R%d], R%d\n", LHSVarAddrReg, classValReg);

			fprintf(filePtr, "ADD R%d, 1\n", LHSVarAddrReg);
			fprintf(filePtr, "ADD R%d, 1\n", RHSVarAddrReg);

			// saving the VFT Address
			fprintf(filePtr, "MOV R%d, [R%d]\n", classValReg, RHSVarAddrReg);
			fprintf(filePtr, "MOV [R%d], R%d\n", LHSVarAddrReg, classValReg);

			freeReg(); // variableAddrReg from getVariableAddress
			freeReg(); // variableAddrReg from getVariableAddress
			freeReg(); // classValReg from codeGen

			return 1;
		}

		// TODO:

		int resultRegNo = evalExprTree(filePtr, root->right);

		if (root->left->nodeType == MUL_NODE)
		{
			int varAddrReg = evalExprTree(filePtr, root->left->middle);
			fprintf(filePtr, "MOV [R%d], R%d\n", varAddrReg, resultRegNo);
			freeReg();
		}
		else
		{
			int varAddrReg = getVariableAddress(filePtr, root->left);
			fprintf(filePtr, "MOV [R%d], R%d\n", varAddrReg, resultRegNo);

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

		// for non-class variables
		if (writeArgument->classTablePtr == NULL)
		{
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

		// for class variables
		if (writeArgument->classTablePtr != NULL)
		{

			int resultRegNo = evalExprTree(filePtr, writeArgument);
			INT_7(filePtr, -2, resultRegNo);
			freeReg();
		}
	}

	// for printf node
	if (root->nodeType == PRINTF_NODE)
	{

		// char *originalString = (char *)malloc(sizeof(root->strConstVal));
		// strcpy(originalString, root->strConstVal);
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

	// Pushing local variables of the function from LST to stack
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

	if (classTableHead == NULL)
		fprintf(filePtr, "L0:\n");

	int freeStackMem = getFreeStackMemoryValue();
	fprintf(filePtr, "MOV SP, %d\n", freeStackMem - 1);
	fprintf(filePtr, "MOV BP, %d\n", freeStackMem);
	fprintf(filePtr, "PUSH R0\n");
	fprintf(filePtr, "CALL F0\n");
	fprintf(filePtr, "INT 10\n");
}

void printTuple(FILE *filePtr, struct ASTNode *root)
{

	int tupleBinding = (root->LSTEntry == NULL) ? (root->GSTEntry->binding) : (root->LSTEntry->binding);

	int tupleAddrReg = getReg();  // Holds address of current tuple field
	int tupleFieldReg = getReg(); // Holds field value to be printed

	fprintf(filePtr, "MOV R%d, %d\n", tupleAddrReg, tupleBinding);

	// if tuple is part of LST
	if (root->LSTEntry != NULL)
		fprintf(filePtr, "ADD R%d, BP\n", tupleAddrReg);

	int tupleSize = root->typeTablePtr->size;

	for (int fieldIndex = 0; fieldIndex < tupleSize; ++fieldIndex)
	{
		fprintf(filePtr, "MOV R%d, [R%d]\n", tupleFieldReg, tupleAddrReg);
		INT_7(filePtr, -2, tupleFieldReg);
		fprintf(filePtr, "ADD R%d, %d\n", tupleAddrReg, 1);
	}

	freeReg(); // tupleFieldReg from printTuple()
	freeReg(); // tupleAddrReg from printTuple()
}

void constructTuple(FILE *filePtr, struct ASTNode *tupleID, struct ASTNode *tupleFields)
{

	int tupleBinding = (tupleID->LSTEntry == NULL) ? (tupleID->GSTEntry->binding) : (tupleID->LSTEntry->binding);

	int tupleAddrReg = getReg();  // holds address of current tuple field
	int tupleFieldReg = getReg(); // holds tuple field value that has to be added to the tuple

	fprintf(filePtr, "MOV R%d, %d\n", tupleAddrReg, tupleBinding);

	// if tuple is part of LST
	if (tupleID->LSTEntry != NULL)
		fprintf(filePtr, "ADD R%d, BP\n", tupleAddrReg);

	int tupleSize = tupleID->typeTablePtr->size;

	for (int fieldIndex = 0; fieldIndex < tupleSize; ++fieldIndex)
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

void assignTuple(FILE *filePtr, struct ASTNode *LHSTuple, struct ASTNode *RHSTuple)
{
	int LHSTupleBinding = (LHSTuple->LSTEntry == NULL) ? (LHSTuple->GSTEntry->binding) : (LHSTuple->LSTEntry->binding);
	int RHSTupleBinding = (RHSTuple->LSTEntry == NULL) ? (RHSTuple->GSTEntry->binding) : (RHSTuple->LSTEntry->binding);

	int LHSTupleAddrReg = getReg(); // Holds address of LHS Tuple
	int RHSTupleAddrReg = getReg(); // Holds address of RHS Tuple

	fprintf(filePtr, "MOV R%d, %d\n", LHSTupleAddrReg, LHSTupleBinding);
	fprintf(filePtr, "MOV R%d, %d\n", RHSTupleAddrReg, RHSTupleBinding);

	// if LHSTuple is part of LST
	if (LHSTuple->LSTEntry != NULL)
		fprintf(filePtr, "ADD R%d, BP\n", LHSTupleAddrReg);

	// if RHSTuple is part of LST
	if (RHSTuple->LSTEntry != NULL)
		fprintf(filePtr, "ADD R%d, BP\n", RHSTupleAddrReg);

	int tupleSize = LHSTuple->typeTablePtr->size;

	for (int fieldIndex = 0; fieldIndex < tupleSize; ++fieldIndex)
	{
		fprintf(filePtr, "MOV [R%d], [R%d]\n", LHSTupleAddrReg, RHSTupleAddrReg);
		fprintf(filePtr, "ADD R%d, 1\n", LHSTupleAddrReg);
		fprintf(filePtr, "ADD R%d, 1\n", RHSTupleAddrReg);
	}

	freeReg(); // LHSTupleAddrReg from assignTuple
	freeReg(); // RHSTupleAddrReg from assignTuple
}

void initVirtualFuncTable(FILE *filePtr)
{

	if (!classTableHead)
		return;

	struct ClassTable *classTableEntry = classTableHead;
	struct MemberFuncList *classMemFunc = NULL;
	int funcLabelReg = getReg();

	while (classTableEntry != NULL)
	{

		classMemFunc = classTableEntry->virtualFunctionPtr;

		for (int i = 0; i < 8; ++i)
		{
			if (classMemFunc != NULL)
			{
				fprintf(filePtr, "MOV R%d, F%d\n", funcLabelReg, classMemFunc->funcLabel);
				fprintf(filePtr, "MOV [%d], R%d\n", getFreeStackMemory(1), funcLabelReg);
				classMemFunc = classMemFunc->next;
			}
			else
			{
				fprintf(filePtr, "MOV R%d, -1\n", funcLabelReg);
				fprintf(filePtr, "MOV [%d], R%d\n", getFreeStackMemory(1), funcLabelReg);
			}
		}

		classTableEntry = classTableEntry->next;
	}
}