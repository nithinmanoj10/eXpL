#include <stdio.h>
#include <stdlib.h>
#include "stackMemory.h"

int freeStackMemory = 4096;

int getFreeStackMemory(){

	if (freeStackMemory > 5119) {
		printf("\n📦 Out of Stack Memory, exiting program\n");
		exit(1);
	}

	return freeStackMemory++;
}
