/**
 * High Level ExpL API that translates and writes
 * the machine instruction in XSM for the Write() function
 *
 * @params	filePtr:	File to which the XSM instruction has to be written to
 *		arg1:		File Descriptor (-2 for Terminal)
 *		arg2:		Data to be written
 *		arg3:		-
 *
 * @return	0:	Success
 *		-1:	File Descriptor is invalid
 */
int Write(FILE* filePtr, int arg1, char* arg2, int arg3);

/**
 * Writes the header in XEXE Format to the first 8 lines
 * of the given file
 *
 * @params	filePtr:	File to which the XEXE Header has to be written into
 *
 * @return	-
 */
void writeXexeHeader(FILE* filePtr);
