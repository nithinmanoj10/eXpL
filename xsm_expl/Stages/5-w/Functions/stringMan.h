// String Manipulation Functions

#ifndef STRINGMAN_H

#define STRINGMAN_H

/**
 *	A function that returns a string after removing 
 *	the double quotation marks
 *
 *	@params		ogString:			The original String
 *
 *	@return		finalString:	String without the quotation marks
 */
char* removeStringQuotes(char* ogString);

/**
 *	A function that returns the name of the array
 *	from the string passed
 *
 *	@params		ogString:			The original String
 *
 *	@return		arrayName:		The name of the array
 *
 *	eg. :			ogString = studentMarks[3]
 *						finalString = studentMarks
 */
char* getArrayName(char* ogString);

/**
 *	A function that returns the offset of an array variable
 *
 *	@params		ogString:			The original String
 *
 *	@return		arrayOffset:	The offset value (index)
 *
 *	eg.	:			ogString = studentMarks[3]
 *						arrayOffset = 3
 */
int getArrayOffset(char* ogString);

#endif
