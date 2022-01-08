#ifndef XSMSYSCALLS_H

#define XSMSYSCALLS_H

/**
 * Low Level System Call to gracefully Exit after the
 * execution of a program
 *
 * @params	filePtr:	Pointer to the file where the XSM Code
 *				has to be written for INT 10
 *
 * @return	[0]:		Success
 *		[-1]:		Fail
 */
int INT_10(FILE* filePtr);

/**
 * Low Level System Call to print data to the terminal. Data to be
 * printed is stored in memory location 5000
 *
 * @params	filePtr:	Pointer to the file where the XSM Code
 *		 		has to be written for INT 7
 * 		
 *		arg1:		File Descriptor (-2 for terminal)
 *		
 *		arg2:		Data to be written (pass "null" for now)
 *
 * @return	[0]:		Success
 *		[-1]:		File Descriptor is invalid
 *  
 */
int INT_7(FILE* filePtr, int arg1, char* arg2);

/**
 * Low Level System Call to read input from the user
 *
 * @params	filePtr:	Pointer to the file where the XSM Code
 *				has to be written for INT 6
 *
 *		arg1:		File Descriptor (-1 for terminal)
 *
 *		arg2:		Memory address to where the input read
 *				is stored
 *
 * @return	1:		Success
 */
int INT_6(FILE* filePtr, int arg1, int arg2);

#endif
