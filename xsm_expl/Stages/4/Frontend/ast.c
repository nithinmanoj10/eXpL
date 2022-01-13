#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "../Functions/reg.h"
#include "../Data_Structures/globalSymbolTable.h"

struct ASTNode *TreeCreate(int nodeType, char *nodeName, int intConstVal, char *strConstVal, struct ASTNode *left, struct ASTNode *middle, struct ASTNode *right)
{

    struct ASTNode *newASTNode = (struct ASTNode *)malloc(sizeof(struct ASTNode));

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

int getVariableAddress(FILE *filePtr, struct ASTNode *root)
{
    int variableAddrReg = getReg();
    int variableAddr = root->GSTEntry->binding; // TODO: GST Struct

    fprintf(filePtr, "MOV R%d, %d\n", variableAddrReg, variableAddr);

    // for array variable
    if (root->left != NULL)
    {

        int offsetReg = getReg();
        fprintf(filePtr, "MOV R%d, R%d\n", offsetReg, evalExprTree(filePtr, root->left));
        fprintf(filePtr, "ADD R%d, R%d\n", variableAddrReg, offsetReg);
        freeReg();
        freeReg();
    }

    return variableAddrReg;
}

int getAddress(FILE *filePtr, struct ASTNode *root)
{
    int address;
    int addressReg = getReg();

    address = *root->nodeName - 97 + 4096;

    fprintf(filePtr, "MOV R%d, %d\n", addressReg, address);
    return addressReg;
}

int evalExprTree(FILE *filePtr, struct ASTNode *root)
{

    if (root->nodeType == CONST_INT_NODE || root->nodeType == CONST_STR_NODE || root->nodeType == ID_NODE)
    {

        int reg1 = getReg();
        int val;

        // TODO: Array Variables

        if (root->nodeType == CONST_INT_NODE)
            fprintf(filePtr, "MOV R%d, %d\n", reg1, root->intConstVal);

        if (root->nodeType == CONST_STR_NODE)
            fprintf(filePtr, "MOV R%d, \"%s\"\n", reg1, root->strConstVal);

        if (root->nodeType == ID_NODE)
        {
            fprintf(filePtr, "MOV R%d, [R%d]\n", reg1, getAddress(filePtr, root));
            freeReg();
        }

        return reg1;
    }

    int leftRegNo, rightRegNo;

    leftRegNo = evalExprTree(filePtr, root->left);
    rightRegNo = evalExprTree(filePtr, root->right);

    freeReg();

    int operator= root->nodeType;

    if (operator== PLUS_NODE)
        fprintf(filePtr, "ADD R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== MINUS_NODE)
        fprintf(filePtr, "SUB R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== MUL_NODE)
        fprintf(filePtr, "MUL R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== DIV_NODE)
        fprintf(filePtr, "DIV R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== MOD_NODE)
        fprintf(filePtr, "MOD R%d, R%d\n", leftRegNo, rightRegNo);

    return leftRegNo;
}