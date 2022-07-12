/**
 * A Function that generates assembly code corresponding to the program
 * represented by the Abstract Syntax Tree.
 *
 * @params	root:           Root of the the Abstract Syntax Tree.
 * 		
 * 		targetFile:     Pointer to the target XSM file where the
 *				target code has to be written and executed.
 *
 * @return	1:		Success
 */
int codeGen(struct ASTNode* root, FILE* filePtr);

/**
 * Function to assign the first 26 spaces in the stack for the variables
 * [a-z]. Address starting from 4096 to 4121.
 *
 * @params	filePtr:	Pointer to the file where the XSM instructions
 *				has to be written
 *
 * @return	1:		Success
 */
int initVariables(FILE* filePtr);
