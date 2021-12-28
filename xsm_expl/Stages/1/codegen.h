/**
 * A function that generates assembly code corresponding to the program 
 * represented by the Abstract Syntax Tree.
 *
 * @params 	root:		Root of the the Abstract Syntax Tree.
 *		
 *		targetFile: 	Pointer to the target XSM file where the
 *		           	target code has to be written and executed.
 *
 * @return	1. [0-19] The register number that would contain the evaluated value 
 *		when the assembly code is executed.
 *
 *		2. [-1] If the tree cannot be evaluated.
 */
int codeGen(struct treeNode* root, FILE* targetFile);
