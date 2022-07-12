#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intepreter.h"
#include "ast.h"
#include "../Functions/typeCheck.h"

int initVariableStorage()
{
    for (int i = 0; i < 26; ++i)
        variableStorage[i] = 0;
    return 1;
}

struct ASTNode *TreeCreate(int dataType, int nodeType, char *nodeName, int intConstVal, char *strConstVal, struct ASTNode *left, struct ASTNode *middle, struct ASTNode *right)
{

    typeCheck(nodeType, left, right);

    struct ASTNode *newASTNode = (struct ASTNode *)malloc(sizeof(struct ASTNode));

    newASTNode->dataType = dataType;
    newASTNode->nodeType = nodeType;
    newASTNode->nodeName = NULL;
    newASTNode->intConstVal = intConstVal;
    newASTNode->strConstVal = NULL;
    newASTNode->left = left;
    newASTNode->right = right;
    newASTNode->middle = middle;

    if (nodeName != NULL)
    {
        newASTNode->nodeName = (char *)malloc(sizeof(nodeName));
        strcpy(newASTNode->nodeName, nodeName);
    }

    if (strConstVal != NULL)
    {
        newASTNode->strConstVal = (char *)malloc(sizeof(strConstVal));
        strcpy(newASTNode->strConstVal, strConstVal);
    }

    // TODO: GST Entry node

    return newASTNode;
}

int printAST(struct ASTNode *root)
{

    if (root == NULL)
        return 1;

    printAST(root->left);
    printAST(root->middle);
    printAST(root->right);

    printf("Data Type: %d\n", root->dataType);
    printf("nodeType: %d\n", root->nodeType);
    printf("nodeName: %s\n", root->nodeName);
    printf("intConstVal: %d\n", root->intConstVal);
    printf("strConstVal: %s\n", root->strConstVal);
    printf("left: %p\n", root->left);
    printf("middle: %p\n", root->middle);
    printf("right: %p\n", root->right);
    printf("GST: %p\n\n", root->GSTEntry);

    return 0;
}

int evalExprTree(struct ASTNode *root)
{

    if (root->nodeType == CONST_INT_NODE || root->nodeType == CONST_STR_NODE || root->nodeType == ID_NODE)
    {

        if (root->nodeType == CONST_INT_NODE)
            return root->intConstVal;

        if (root->nodeType == ID_NODE)
        {
            int variable = *root->nodeName - 97;
            return variableStorage[variable];
        }
    }

    int leftVal, rightVal;

    leftVal = evalExprTree(root->left);
    rightVal = evalExprTree(root->right);

    int operator= root->nodeType;

    if (operator== PLUS_NODE)
        return leftVal + rightVal;

    if (operator== MINUS_NODE)
        return leftVal - rightVal;

    if (operator== MUL_NODE)
        return leftVal * rightVal;

    if (operator== DIV_NODE)
        return leftVal / rightVal;

    if (operator== MOD_NODE)
        return leftVal % rightVal;
}

int evalCondTree(struct ASTNode *root)
{
    int condOp = root->nodeType;
    int leftVal = evalExprTree(root->left);
    int rightVal = evalExprTree(root->right);

    if (condOp == LT_NODE)
        return leftVal < rightVal;

    if (condOp == LE_NODE)
        return leftVal <= rightVal;

    if (condOp == GT_NODE)
        return leftVal > rightVal;

    if (condOp == GE_NODE)
        return leftVal >= rightVal;

    if (condOp == EQ_NODE)
        return leftVal == rightVal;

    if (condOp == NE_NODE)
        return leftVal != rightVal;
}