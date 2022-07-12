#include <stdio.h>
#include <stdlib.h>
#include "copyFile.h"

int copyFile(char* sourceFileName, char* destFinalName){

	FILE *fptr1, *fptr2;
	char  c;

	// Open one file for reading
	fptr1 = fopen(sourceFileName, "r");
	if (fptr1 == NULL)
	{
		exit(0);
	}

	// Open another file for writing
	fptr2 = fopen(destFinalName, "w");
	if (fptr2 == NULL)
	{
		exit(0);
	}

	// Read contents from file
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}

	fclose(fptr1);
	fclose(fptr2);
	return 0;

}
