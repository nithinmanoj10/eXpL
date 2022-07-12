#include <stdio.h>
#include "xsm_library.h"
#include "stackMemory.h"
#include "reg.h"

int Write(FILE *filePtr, int arg1, char *arg2, int arg3)
{

	// invoking the Write Library Module
	fprintf(filePtr, "MOV SP, 4095\n");
	fprintf(filePtr, "MOV R1, \"Write\"\n");
	fprintf(filePtr, "PUSH R1\n");
	fprintf(filePtr, "MOV R1, %d\n", arg1);
	fprintf(filePtr, "PUSH R1\n");
	fprintf(filePtr, "MOV R1, R2\n");
	fprintf(filePtr, "PUSH R1\n");
	fprintf(filePtr, "MOV R1, %d\n", arg3);
	fprintf(filePtr, "PUSH R1\n");
	fprintf(filePtr, "PUSH R1\n");
	fprintf(filePtr, "CALL 0\n");

	// after returning from the Library Module
	for (int i = 0; i < 5; ++i)
		fprintf(filePtr, "POP R16\n");
}

void writeXexeHeader(FILE *filePtr)
{

	fprintf(filePtr, "0\n2056\n");
	for (int i = 0; i < 6; ++i)
		fprintf(filePtr, "0\n");

	// fprintf(filePtr, "MOV SP, %d\n", freeStackMemory);
}

int Initialize(FILE *filePtr)
{
	int emptyPushReg = getReg();

	fprintf(filePtr, "MOV R%d, \"Heapset\"\n", emptyPushReg);

	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);

	freeReg();

	fprintf(filePtr, "CALL 0\n");

	int returnReg = getReg();
	int tempReg = getReg();

	fprintf(filePtr, "POP R%d\n", returnReg);
	fprintf(filePtr, "POP R%d\n", tempReg);
	fprintf(filePtr, "POP R%d\n", tempReg);
	fprintf(filePtr, "POP R%d\n", tempReg);
	fprintf(filePtr, "POP R%d\n", tempReg);

	return returnReg;
}

int Alloc(FILE *filePtr)
{
	int emptyPushReg = getReg();

	fprintf(filePtr, "MOV R%d, \"Alloc\"\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);

	fprintf(filePtr, "MOV R%d, 8\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);

	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);

	freeReg();

	fprintf(filePtr, "CALL 0\n");

	int returnReg = getReg();
	int tempReg = getReg();

	fprintf(filePtr, "POP R%d\n", returnReg);
	fprintf(filePtr, "POP R%d\n", tempReg);
	fprintf(filePtr, "POP R%d\n", tempReg);
	fprintf(filePtr, "POP R%d\n", tempReg);
	fprintf(filePtr, "POP R%d\n", tempReg);

	return returnReg;
}

int Free(FILE *filePtr, int pointerReg)
{
	int emptyPushReg = getReg();

	fprintf(filePtr, "MOV R%d, \"Free\"\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);

	fprintf(filePtr, "MOV R%d, R%d\n", emptyPushReg, pointerReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);

	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);
	fprintf(filePtr, "PUSH R%d\n", emptyPushReg);

	freeReg();

	fprintf(filePtr, "CALL 0\n");

	int returnReg = getReg();
	int tempReg = getReg();

	fprintf(filePtr, "POP R%d\n", returnReg);
	fprintf(filePtr, "POP R%d\n", tempReg);
	fprintf(filePtr, "POP R%d\n", tempReg);
	fprintf(filePtr, "POP R%d\n", tempReg);
	fprintf(filePtr, "POP R%d\n", tempReg);

	return returnReg;
}