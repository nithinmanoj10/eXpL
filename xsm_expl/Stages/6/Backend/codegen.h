#ifndef CODEGEN_H

#define CODEGEN_H

#include "../Frontend/ast.h"
#include "../Data_Structures/LSTable.h"

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
int codeGen(struct ASTNode *root, FILE *filePtr);

/**
 * Function to assign the first 26 spaces in the stack for the variables
 * [a-z]. Address starting from 4096 to 4121.
 *
 * @params	filePtr:	Pointer to the file where the XSM instructions
 *				has to be written
 *
 * @return	1:		Success
 */
int initVariables(FILE *filePtr);

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
int codeGenWhile(FILE *filePtr, struct ASTNode *root, int label, int option);

/**
 * @brief   Pushes old BP to stack and sets new BP to SP. Also pushes all local
 *          variables in given order to stack and sets it's binding accordingly
 *
 * @param   filePtr     Pointer to file where the code has to be written
 * @param   paramCount  Number of parameters of the function. Needed to skip all the parameters
 *                      in the LST
 * @return  int
 */
int initFuncCalle(FILE *filePtr, int paramCount);

/**
 * @brief   Generates XSM code for the caller function before and after calling
 *          the callee function
 *
 * @param   filePtr Pointer to target code file
 * @param   funcNode Function Node
 * @return  int
 */
int codeGenFuncCaller(FILE *filePtr, struct ASTNode *funcNode);

/**
 *  @brief  Initialises the Stack and sets the BP register to SP + 1, then
 *          calls the int main() function.
 *
 *  @param  filePtr     Pointer to file where the XSM Code has to be written
 *
 *  @return void
 */
void initStackBP(FILE *filePtr);

/**
 *  @brief  Codegen function to be able to print an entire tuple
 *
 *  @param   filePtr     Pointer to target code file
 *  @param   root        AST Node of the tuple variable
 */
void printTuple(FILE *filePtr, struct ASTNode *root);

/**
 *  @brief  Codegen function for construction of a tuple
 *
 *  @param  filePtr         Pointer to target code file
 *  @param  tupleID         AST Node of the tuple variables to be constructed
 *  @param  tupleFields     List of tuple fields
 */
void constructTuple(FILE *filePtr, struct ASTNode *tupleID, struct ASTNode *tupleFields);

/**
 *  @brief  Codegen function for assignment of a tuple
 *
 *  @param  filePtr     Pointer to target code file
 *  @param  LHSTuple    AST Node of LHS Tuple variable
 *  @param  RHSTuple    AST Node of RHS Tuple variable
 */
void assignTuple(FILE *filePtr, struct ASTNode *LHSTuple, struct ASTNode *RHSTuple);

#endif
