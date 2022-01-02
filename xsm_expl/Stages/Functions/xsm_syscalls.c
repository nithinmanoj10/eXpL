#include <stdio.h>
#include "xsm_syscalls.h"

int INT_7(FILE* filePtr, int arg1, char* arg2){

	if (arg1 != -2)
		return -1;

	fprintf(filePtr, "MOV R1, 5\n");
	fprintf(filePtr, "PUSH R1\n");

	fprintf(filePtr, "MOV R1, %d\n", arg1);
	fprintf(filePtr, "PUSH R1\n");
	
	// TODO: For now value to be printed is stored in R2
	fprintf(filePtr, "MOV R1, R2\n");
	fprintf(filePtr, "PUSH R1\n");

	fprintf(filePtr, "PUSH R1\n");

	fprintf(filePtr, "PUSH R0\n");
	fprintf(filePtr, "INT 7\n");

	fprintf(filePtr, "POP R0\n"); 
	
	for(int i = 0; i < 4; ++i)
		fprintf(filePtr, "POP R1\n");

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
