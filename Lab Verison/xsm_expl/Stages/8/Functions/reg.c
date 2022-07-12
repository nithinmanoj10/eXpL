#include <stdio.h>
#include <stdlib.h>
#include "reg.h"

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"

int regNum = -1;

int getReg()
{

	++regNum;

	// Number of registers available is 20 (R0-R19)
	if (regNum > 19)
	{
		printf("%s\n🚫 Out of Registers: Exiting Program%s\n", KRED, KNRM);
		exit(1);
	}

	return regNum;
}

int freeReg()
{

	// If all registers are already freed
	if (regNum == -1)
		return -1;

	--regNum;
	return regNum;
}

int getRegNumValue()
{
	return regNum;
}

void multipush(FILE *filePtr)
{
	for (int currentReg = 0; currentReg <= regNum; ++currentReg)
	{
		fprintf(filePtr, "PUSH R%d\n", currentReg);
	}
}

void multipop(FILE *filePtr)
{
	for (int currentReg = regNum; currentReg >= 0; --currentReg)
	{
		fprintf(filePtr, "POP R%d\n", currentReg);
	}
}