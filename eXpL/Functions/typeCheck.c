#include <stdio.h>
#include <stdlib.h>
#include "typeCheck.h"
#include "../Frontend/ast.h"
#include "../Data_Structures/classTable.h"
#include "../Functions/printError.h"

int typeCheck(int nodeType, struct ASTNode *leftTree, struct ASTNode *rightTree, struct ASTNode *middleTree)
{

    switch (nodeType)
    {
    case PLUS_NODE:
        if (leftTree->typeTablePtr != typeTableINT || rightTree->typeTablePtr != typeTableINT)
        {
            printError(ERR_TYPE, "Addition Operator requires data type INT");
            exit(1);
        }
        break;

    case MINUS_NODE:
        if (leftTree->typeTablePtr != typeTableINT || rightTree->typeTablePtr != typeTableINT)
        {
            printError(ERR_TYPE, "Subtraction Operator requires data type INT");
            exit(1);
        }
        break;

    case MUL_NODE:

        if (middleTree == NULL)
        {

            if ((leftTree->typeTablePtr != typeTableINT || rightTree->typeTablePtr != typeTableINT))
            {
                printError(ERR_TYPE, "Multiplication Operator requires data type INT");
                exit(1);
            }
        }
        else
        {
            if (middleTree->typeTablePtr != typeTableINTPtr && middleTree->typeTablePtr != typeTableSTRPtr)
            {
                printf("\nDereference Operator expects a pointer variables\n");
                exit(1);
            }
        }
        break;

    case DIV_NODE:
        if (leftTree->typeTablePtr != typeTableINT || rightTree->typeTablePtr != typeTableINT)
        {
            printError(ERR_TYPE, "Division Operator requires data type INT");
            exit(1);
        }
        break;

    case MOD_NODE:
        if (leftTree->typeTablePtr != typeTableINT || rightTree->typeTablePtr != typeTableINT)
        {
            printError(ERR_TYPE, "Modulus Operator requires data type INT");
            exit(1);
        }
        break;

    case AMP_NODE:
        if (leftTree->nodeType != ID_NODE)
        {
            printError(ERR_TYPE, "Ampersand Operator requires data type INT");
            exit(1);
        }
        break;

    case LT_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            printError(ERR_TYPE, "< Operator requires same data type on both sides");
            exit(1);
        }
        break;

    case LE_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            printError(ERR_TYPE, "<= Operator requires same data type on both sides");
            exit(1);
        }
        break;

    case GT_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            printError(ERR_TYPE, "> Operator requires same data type on both sides");
            exit(1);
        }
        break;

    case GE_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            printError(ERR_TYPE, ">= Operator requires same data type on both sides");
            exit(1);
        }
        break;

    case EQ_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            if (rightTree->nodeType != NULL_NODE)
            {
                printError(ERR_TYPE, "== Operator requires same data type on both sides");
                exit(1);
            }
        }
        break;

    case NE_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            if (rightTree->nodeType != NULL_NODE)
            {
                printError(ERR_TYPE, "!= Operator requires same data type on both sides");
                exit(1);
            }
        }
        break;

    case AND_NODE:
        if (leftTree->typeTablePtr != typeTableBOOL || leftTree->typeTablePtr != typeTableBOOL)
        {
            printError(ERR_TYPE, "AND Operator requires type BOOL on both sides");
            exit(1);
        }

    case OR_NODE:
        if (leftTree->typeTablePtr != typeTableBOOL || leftTree->typeTablePtr != typeTableBOOL)
        {
            printError(ERR_TYPE, "OR Operator requires type BOOL on both sides");
            exit(1);
        }

    case NOT_NODE:
        if (leftTree->typeTablePtr != typeTableBOOL)
        {
            printError(ERR_TYPE, "NOT Operator requires type BOOL on both sides");
            exit(1);
        }

    case IF_NODE:
        if (leftTree->typeTablePtr != typeTableBOOL)
        {
            printError(ERR_TYPE, "Conditional Statement of IF should be of type BOOL");
            exit(1);
        }
        break;

    case WHILE_NODE:
        if (leftTree->typeTablePtr != typeTableBOOL)
        {
            printError(ERR_TYPE, "Conditional Statement of WHILE should be of type BOOL");
            exit(1);
        }
        break;

    case DO_WHILE_NODE:
        if (rightTree->typeTablePtr != typeTableBOOL)
        {
            printError(ERR_TYPE, "Conditional Statement of DO-WHILE should be of type BOOL");
            exit(1);
        }
        break;

    case FOR_NODE:
        if (middleTree->typeTablePtr != typeTableBOOL)
        {
            printError(ERR_TYPE, "Test Expression of for-loop should be of type BOOL");
            exit(1);
        }
        break;

    case READ_NODE:
        if (leftTree->nodeType != ID_NODE && leftTree->nodeType != FIELD_NODE && leftTree->nodeType != TUPLE_NODE && leftTree->nodeType != SELF_NODE)
        {
            printError(ERR_FUNC, "read() expects an identifier as an argument");
            exit(1);
        }

        if (leftTree->typeTablePtr != typeTableINT && leftTree->typeTablePtr != typeTableSTR)
        {
            printError(ERR_TYPE, "read() expects argument of type INT or STR");
            exit(1);
        }
        break;

    case WRITE_NODE:
        // if (leftTree->typeTablePtr != typeTableINT && leftTree->typeTablePtr != typeTableSTR && leftTree->typeTablePtr != typeTableINTPtr && leftTree->typeTablePtr != typeTableSTRPtr)
        // {
        //     printf("\nType Error: write() expects argument of type INT or STR\n");
        //     exit(1);
        // }
        break;

    case ASGN_NODE:

        // printf("\nLeft Node: %s", leftTree->nodeName);
        // printf("\nRight Node: %s\n", rightTree->nodeName);

        if (leftTree->nodeType != ID_NODE && leftTree->nodeType != MUL_NODE && leftTree->nodeType != FIELD_NODE && leftTree->nodeType != TUPLE_NODE && leftTree->nodeType != SELF_NODE)
        {
            printError(ERR_TYPE, "Assignment Operator expects an Identifier in LHS");
            exit(1);
        }

        // if (rightTree->typeTablePtr != typeTableINT && rightTree->typeTablePtr != typeTableSTR && rightTree->typeTablePtr != typeTableINTPtr && rightTree->typeTablePtr != typeTableSTRPtr)
        // {
        //     printf("\nType Error: Assignment Operator expects data type INT or STR in RHS\n");
        //     exit(1);
        // }

        if (rightTree->nodeType == ALLOC_NODE || rightTree->nodeType == NEW_NODE)
        {
            if (isPrimitiveType(leftTree->typeTablePtr) && leftTree->classTablePtr == NULL)
            {
                printf("%s %s\n", getNodeName(leftTree->nodeType), leftTree->nodeName);
                printError(ERR_FUNC, "Dynamic Memory new Allocation function expects a user defined type on LHS of assignment operator");
                exit(1);
            }
            return 1;
        }

        // for non-class variables
        if (rightTree->typeTablePtr != NULL && leftTree->typeTablePtr != NULL)
        {
            if (rightTree->typeTablePtr != leftTree->typeTablePtr)
            {
                if (rightTree->nodeType != NULL_NODE)
                {
                    printError(ERR_TYPE, "Assignment Operator expects same data type on both sides");
                    exit(1);
                }
            }
        }

        if (rightTree->classTablePtr != NULL && leftTree->classTablePtr != NULL)
        {
            struct ClassTable *LHSClassEntry = leftTree->classTablePtr;
            struct ClassTable *RHSClassEntry = rightTree->classTablePtr;

            // if they are not variables of the same class type
            if (LHSClassEntry != RHSClassEntry)
            {

                // if RHS variable is part of child class of LHS
                if (RHSClassEntry->parentPtr != LHSClassEntry)
                {
                    printError(ERR_TYPE, "Assignment Operator expects class variables of same type or inherited type");
                    exit(1);
                }
            }
        }

        break;

    default:
        return 1;
        break;
    }
}