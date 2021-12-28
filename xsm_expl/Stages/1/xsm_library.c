#include <stdio.h>
#include "xsm_library.h"

int Write(FILE* filePtr, int arg1, char* arg2, int arg3){

	// invoking the Write Library Module  		// ┌───────────────────┐
	fprintf(filePtr, "MOV SP, 4095\n");		// MOV SP, 4095		|
	fprintf(filePtr, "MOV R1, \"Write\"\n");	// MOV R1, "Write	|
	fprintf(filePtr, "PUSH R1\n");			// PUSH R1		|
	fprintf(filePtr, "MOV R1, %d\n", arg1);		// MOV R1, (arg1)	|
	fprintf(filePtr, "PUSH R1\n");			// PUSH R1		|
	fprintf(filePtr, "MOV R1, R2\n");
	fprintf(filePtr, "PUSH R1\n");
	fprintf(filePtr, "MOV R1, %d\n", arg3);
	fprintf(filePtr, "PUSH R1\n");
	fprintf(filePtr, "PUSH R1\n");
	fprintf(filePtr, "CALL 0\n");			

	// after returning from the Library Module
	for(int i = 0; i < 5; ++i)
		fprintf(filePtr, "POP R16\n");	

}


void writeXexeHeader(FILE* filePtr){

	fprintf(filePtr, "0\n2056\n");
	for(int i = 0; i < 6; ++i)
		fprintf(filePtr ,"0\n");	

}
