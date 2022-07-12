#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "../Functions/reg.h"
#include "../Functions/typeCheck.h"
#include "../Functions/label.h"
#include "../Data_Structures/GSTable.h"
#include "../Data_Structures/LSTable.h"
#include "../Data_Structures/typeTable.h"

struct ASTNode *TreeCreate(int dataType, int nodeType, char *nodeName, int intConstVal, char *strConstVal, struct ASTNode *left, struct ASTNode *middle, struct ASTNode *right)
{

    typeCheck(nodeType, left, right, middle);

    struct ASTNode *newASTNode = (struct ASTNode *)malloc(sizeof(struct ASTNode));

    newASTNode->dataType = dataType;
    newASTNode->nodeType = nodeType;
    newASTNode->nodeName = NULL;
    newASTNode->intConstVal = intConstVal;
    newASTNode->strConstVal = NULL;
    newASTNode->argListHead = NULL;
    newASTNode->argListNext = NULL;
    newASTNode->left = left;
    newASTNode->right = right;
    newASTNode->middle = middle;
    newASTNode->GSTEntry = NULL;
    newASTNode->LSTEntry = NULL;

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

    return newASTNode;
}

int printAST(struct ASTNode *root)
{

    if (root == NULL)
        return 1;

    printAST(root->left);
    printAST(root->middle);
    printAST(root->right);

    printf("\n-----------------------------------------------------\n");
    printf("🌳 nodeName: %s\n", root->nodeName);
    printf("➡ Data Type: %d\n", root->dataType);
    printf("➡ nodeType: %d\n", root->nodeType);
    printf("➡ intConstVal: %d\n", root->intConstVal);
    printf("➡ strConstVal: %s\n", root->strConstVal);
    printf("➡ left: %p\n", root->left);
    printf("➡ middle: %p\n", root->middle);
    printf("➡ right: %p\n", root->right);
    printf("➡ GST: %p\n", root->GSTEntry);
    printf("➡ LST: %p\n\n", root->LSTEntry);

    // if (root->argList != NULL)
    // {
    //     printf("➡ Arg List Start:\n");
    //     struct ASTNode *traversalPtr = root->argList;
    //     while (traversalPtr != NULL)
    //     {
    //         printAST(traversalPtr);
    //         traversalPtr = traversalPtr->argList;
    //     }
    //     printf("➡ Arg List End:\n");
    // }

    return 0;
}

int getVariableAddress(FILE *filePtr, struct ASTNode *root)
{
    int variableAddrReg = getReg();
    struct LSTNode *varLSTEntry = LSTLookup(root->nodeName);

    if (varLSTEntry == NULL)
    {
        if (root->GSTEntry == NULL)
        {
            printf("\nVariable %s undeclared before use\n", root->nodeName);
            exit(1);
        }

        int variableAddr = root->GSTEntry->binding;
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
    }
    else
    {
        int variableBindingReg = getReg();
        fprintf(filePtr, "MOV R%d, %d\n", variableBindingReg, varLSTEntry->binding);
        fprintf(filePtr, "MOV R%d, BP\n", variableAddrReg);
        fprintf(filePtr, "ADD R%d, R%d\n", variableAddrReg, variableBindingReg);

        if (root->nodeType == TUPLE_FIELD_NODE)
        {
        }

        freeReg();
    }

    return variableAddrReg;
}

// int getVariableAddress(FILE *filePtr, struct ASTNode *root)
// {
//     int variableAddrReg = getReg();
//     int variableAddr = root->GSTEntry->binding;

//     fprintf(filePtr, "MOV R%d, %d\n", variableAddrReg, variableAddr);

//     // for array variable
//     if (root->left != NULL)
//     {

//         int offsetReg = getReg();
//         fprintf(filePtr, "MOV R%d, R%d\n", offsetReg, evalExprTree(filePtr, root->left));
//         fprintf(filePtr, "ADD R%d, R%d\n", variableAddrReg, offsetReg);
//         freeReg();
//         freeReg();
//     }

//     return variableAddrReg;
// }

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

    if (root->nodeType == CONST_INT_NODE || root->nodeType == CONST_STR_NODE || root->nodeType == ID_NODE || root->nodeType == AMP_NODE || (root->nodeType == MUL_NODE && root->middle != NULL))
    {

        int reg1 = getReg();
        int val;

        if (root->nodeType == CONST_INT_NODE)
            fprintf(filePtr, "MOV R%d, %d\n", reg1, root->intConstVal);

        if (root->nodeType == CONST_STR_NODE)
            fprintf(filePtr, "MOV R%d, \"%s\"\n", reg1, root->strConstVal);

        if (root->nodeType == ID_NODE)
        {
            fprintf(filePtr, "MOV R%d, [R%d]\n", reg1, getVariableAddress(filePtr, root));
            freeReg();
        }

        if (root->nodeType == AMP_NODE)
        {
            int variableAddressReg = getVariableAddress(filePtr, root->left);
            fprintf(filePtr, "MOV R%d, R%d\n", reg1, variableAddressReg);
        }

        if (root->nodeType == MUL_NODE && root->middle != NULL)
        {
            int pointerAddressReg = evalExprTree(filePtr, root->middle);
            fprintf(filePtr, "MOV R%d, [R%d]\n", reg1, pointerAddressReg);
            freeReg();
        }

        return reg1;
    }

    // for a FUNCTION Node
    if (root->nodeType == FUNC_NODE)
    {
        int regCount = getRegNumValue();
        // Push all register in use to the stack
        for (int i = 0; i <= regCount; ++i)
            fprintf(filePtr, "PUSH R%d\n", i);

        // Evaluate each argList node and push it in the stack (in the same order)
        struct ASTNode *argListHead = root->argListHead;
        int argValueReg;  // Register where each argument value is stored
        int argCount = 0; // Number of arguments pushed into the stack

        while (argListHead != NULL)
        {
            argValueReg = evalExprTree(filePtr, argListHead);
            fprintf(filePtr, "PUSH R%d\n", argValueReg);
            ++argCount;
            freeReg();

            argListHead = argListHead->argListNext;
        }

        // Pushing an empty space for the return value
        fprintf(filePtr, "PUSH R0\n");

        // Generate CALL Statement
        struct GSTNode *funcGSTEntry = GSTLookup(root->nodeName);
        fprintf(filePtr, "CALL F%d\n", funcGSTEntry->fLabel);

        // Store the return value in a register
        int returnValueReg = getReg();
        fprintf(filePtr, "POP R%d\n", returnValueReg);

        // POP out all the arguments
        for (int i = 0; i < argCount; ++i)
            fprintf(filePtr, "POP R10\n");

        // restore all registers saved in the stack
        for (int i = regCount; i >= 0; --i)
            fprintf(filePtr, "POP R%d\n", i);

        return returnValueReg;
    }

    int leftRegNo, rightRegNo;

    int operator= root->nodeType;
    leftRegNo = evalExprTree(filePtr, root->left);

    if (operator== NOT_NODE)
    {
        int label1 = getLabel();
        int label2 = getLabel();

        fprintf(filePtr, "JZ R%d, L%d\n", leftRegNo, label1);
        fprintf(filePtr, "MOV R%d, 0\n", leftRegNo);
        fprintf(filePtr, "JMP L%d\n", label2);
        fprintf(filePtr, "L%d:\n", label1);
        fprintf(filePtr, "MOV R%d, 1\n", leftRegNo);
        fprintf(filePtr, "L%d:\n", label2);

        return leftRegNo;
    }

    rightRegNo = evalExprTree(filePtr, root->right);

    freeReg();

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

    if (operator== EQ_NODE)
        fprintf(filePtr, "EQ R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== NE_NODE)
        fprintf(filePtr, "NE R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== LT_NODE)
        fprintf(filePtr, "LT R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== LE_NODE)
        fprintf(filePtr, "LE R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== GT_NODE)
        fprintf(filePtr, "GT R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== GE_NODE)
        fprintf(filePtr, "GE R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== AND_NODE)
        fprintf(filePtr, "MUL R%d, R%d\n", leftRegNo, rightRegNo);

    if (operator== OR_NODE)
        fprintf(filePtr, "ADD R%d, R%d\n", leftRegNo, rightRegNo);

    return leftRegNo;
}

struct ASTNode *lookupID(struct ASTNode *IDNode)
{

    struct LSTNode *IdLSTEntry = LSTLookup(IDNode->nodeName);

    if (IdLSTEntry == NULL)
    {
        IDNode->GSTEntry = GSTLookup(IDNode->nodeName);
        if (IDNode->GSTEntry == NULL)
        {
            printf("\nVariable %s undeclared before use in %s()\n", IDNode->nodeName, getCurrentFuncName());
            exit(1);
        }
        else
        {
            IDNode->dataType = IDNode->GSTEntry->type;
        }
    }
    else
    {
        IDNode->dataType = IdLSTEntry->type;
    }

    return IDNode;
}

struct ASTNode *insertToArgList(struct ASTNode *argListHead, struct ASTNode *argNode)
{
    struct ASTNode *traversalPtr = argListHead;

    while (traversalPtr->argListNext != NULL)
    {
        traversalPtr = traversalPtr->argListNext;
    }

    traversalPtr->argListNext = argNode;

    return argListHead;
}

int verifyFunctionArguments(char *funcName, struct ASTNode *argumentList)
{
    struct GSTNode *funcGSTEntry = GSTLookup(funcName);
    struct ParamStruct *funcParamList = funcGSTEntry->paramList;
    int argCount = 0;

    while (funcParamList != NULL)
    {
        ++argCount;
        if (funcParamList->paramType != argumentList->dataType)
        {
            printf("\n%s() expects data type %s for argument %d\n", funcName, (funcParamList->paramType == TYPE_INT) ? ("int") : ("str"), argCount);
            exit(1);
        }
        funcParamList = funcParamList->next;
        argumentList = argumentList->argListNext;
    }

    if (funcParamList != NULL || argumentList != NULL)
    {
        printf("\nNumber of arguments passed to %s() not equal to number of parameters in declaration\n", funcName);
        exit(1);
    }

    return 1;
}