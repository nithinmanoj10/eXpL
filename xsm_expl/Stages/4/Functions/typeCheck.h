#ifndef TYPE_CHECK_H

#define TYPE_CHECK_H

#include "../Frontend/ast.h"

int typeCheck(int nodeType, struct ASTNode *leftTree, struct ASTNode *rightTree);

#endif