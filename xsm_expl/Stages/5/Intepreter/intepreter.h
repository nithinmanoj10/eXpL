#ifndef INTEPRETER_H

#define INTEPRETER_H

#include "ast.h"

/**
 * Function to intepret the AST of the code 
 *
 * @params	root:	Root of the AST
 *
 * @return	1:	Success
 */
int codeIntepreter(struct ASTNode *root);

#endif