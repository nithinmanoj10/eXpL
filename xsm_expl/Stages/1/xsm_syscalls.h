/**
 * Low Level System Call to gracefully Exit after the
 * execution of a program
 *
 * @params	filePtr:	Pointer to the file where the XSM Code
 *				has to be written for INT10
 *
 * @return	[0]:		Success
 *		[-1]:		Fail
 */
int INT_10(FILE* filePtr);

/**
 * Low Level System Call to print data to the terminal
 *
 * @params	filePtr:	Pointer to the file where the XDM Code
 *		 		has to be written for INT7
 * 		
 *		arg1:		File Descriptor (-2 for terminal)
 *		
 *		arg2:		Data to be written
 *
 * @return	[0]:		Success
 *		[-1]:		File Descriptor is invalid
 *  
 */
int INT_7(FILE* filePtr, int arg1, char* arg2);
