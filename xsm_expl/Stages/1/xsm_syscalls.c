#include <stdio.h>
#include "xsm_syscalls.h"

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
