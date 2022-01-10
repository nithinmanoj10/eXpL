#ifndef CODEGEN_H

#define CODEGEN_H

#include "../Frontend/ast.h"

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

/**
 * Function that generates XSM Machine Code corresponding to the conditional
 * statement of an if condition or while loop
 *
 * @params	filePtr: 	Pointer to the file where the XSM instructions
 *				has to be written
 *
 *		root:		Pointer to the WHILE Node
 * 
 *		label:		Label number to where the execution should continue
 *				from after evaluating the conditon
 *
 *		option:		Number indicating the type of the loop
 *				1 - While Loop
 *				2 - Do While Loop
 *
 * @return	1: 		Success
 */
int codeGenWhile(FILE* filePtr, struct ASTNode* root, int label, int option);

#endif
