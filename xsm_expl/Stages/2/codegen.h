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
