#include <stdio.h>
#include "xsm_syscalls.h"
#include "reg.h"

int INT_7(FILE* filePtr, int arg1, char* arg2){

	if (arg1 != -2)
		return -1;

	int reg1 = getReg();
	int reg2 = getReg();

	fprintf(filePtr, "MOV R%d, 5\n", reg1);
	fprintf(filePtr, "PUSH R%d\n", reg1);

	fprintf(filePtr, "MOV R%d, %d\n", reg1, arg1);
	fprintf(filePtr, "PUSH R%d\n", reg1);
	
	// TODO: For now value to be printed is stored in address 5000
	fprintf(filePtr, "MOV R%d, [5000]\n", reg1);
	fprintf(filePtr, "PUSH R%d\n", reg1);

	fprintf(filePtr, "PUSH R%d\n", reg1);

	fprintf(filePtr, "PUSH R%d\n", reg2);
	fprintf(filePtr, "INT 7\n");

	fprintf(filePtr, "POP R%d\n", reg2); 
	
	for(int i = 0; i < 4; ++i)
		fprintf(filePtr, "POP R%d\n", reg1);

}

int INT_10(FILE* filePtr){

	int i;

	fprintf(filePtr, "MOV R1, 10\n");

	for(i = 0; i < 4; ++i)
		fprintf(filePtr, "PUSH R1\n");

	fprintf(filePtr, "PUSH R0\n");
	fprintf(filePtr, "INT 10\n");	

	for(i = 0; i < 5; ++i)
		fprintf(filePtr, "POP R1\n");

	return 1;
}
