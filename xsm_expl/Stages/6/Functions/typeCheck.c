#include <stdio.h>
#include <stdlib.h>
#include "typeCheck.h"
#include "../Frontend/ast.h"
#include "../Data_Structures/typeTable.h"

int typeCheck(int nodeType, struct ASTNode *leftTree, struct ASTNode *rightTree, struct ASTNode *middleTree)
{

    switch (nodeType)
    {
    case PLUS_NODE:
        if (leftTree->typeTablePtr != typeTableINT || rightTree->typeTablePtr != typeTableINT)
        {
            if (leftTree->typeTablePtr->typeCategory == TYPE_POINTER || rightTree->typeTablePtr->typeCategory == TYPE_POINTER)
                return 1;

            printf("\nType Error: Addition Operator requires data type INT\n");
            exit(1);
        }
        break;

    case MINUS_NODE:
        if (leftTree->typeTablePtr != typeTableINT || rightTree->typeTablePtr != typeTableINT)
        {
            printf("\nType Error: Subtraction Operator requires data type INT\n");
            exit(1);
        }
        break;

    case MUL_NODE:

        if (middleTree == NULL)
        {

            if ((leftTree->typeTablePtr != typeTableINT || rightTree->typeTablePtr != typeTableINT))
            {
                printf("\nType Error: Multiplication Operator requires data type INT\n");
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
            printf("\nType Error: Division Operator requires data type INT\n");
            exit(1);
        }
        break;

    case MOD_NODE:
        if (leftTree->typeTablePtr != typeTableINT || rightTree->typeTablePtr != typeTableINT)
        {
            printf("\nType Error: Modulus Operator requires data type INT\n");
            exit(1);
        }
        break;

    case AMP_NODE:
        if (leftTree->nodeType != ID_NODE)
        {
            printf("\nType Error: Ampersand Operator expects an Identifier\n");
            exit(1);
        }
        break;

    case LT_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            printf("\nType Error: Less Than Operator requires same data type on both sides\n");
            exit(1);
        }
        break;

    case LE_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            printf("\nType Error: Less Than Equal Operator requires same data type on both sides\n");
            exit(1);
        }
        break;

    case GT_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            printf("\nType Error: Greater Than Operator requires same data type on both sides\n");
            exit(1);
        }
        break;

    case GE_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            printf("\nType Error: Greater Than Equal Operator requires same data type on both sides\n");
            exit(1);
        }
        break;

    case EQ_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            if (rightTree->nodeType != NULL_NODE)
            {
                printf("\nType Error: Equal To Operator requires same data type on both sides\n");
                exit(1);
            }
        }
        break;

    case NE_NODE:
        if (leftTree->typeTablePtr != rightTree->typeTablePtr)
        {
            if (rightTree->nodeType != NULL_NODE)
            {
                printf("\nType Error: Equal To Operator requires same data type on both sides\n");
                exit(1);
            }
        }
        break;

    case AND_NODE:
        if (leftTree->typeTablePtr != typeTableBOOL || leftTree->typeTablePtr != typeTableBOOL)
        {
            printf("\nType Error: AND Operator requires type BOOL on both sides\n");
            exit(1);
        }

    case OR_NODE:
        if (leftTree->typeTablePtr != typeTableBOOL || leftTree->typeTablePtr != typeTableBOOL)
        {
            printf("\nType Error: OR Operator requires type BOOL on both sides\n");
            exit(1);
        }

    case NOT_NODE:
        if (leftTree->typeTablePtr != typeTableBOOL)
        {
            printf("\nType Error: NOT Operator requires type BOOL\n");
            exit(1);
        }

    case IF_NODE:
        if (leftTree->typeTablePtr != typeTableBOOL)
        {
            printf("\nType Error: Conditional Statement of IF should be of type BOOL\n");
            exit(1);
        }
        break;

    case WHILE_NODE:
        if (leftTree->typeTablePtr != typeTableBOOL)
        {
            printf("\nType Error: Conditional Statement of WHILE should be of type BOOL\n");
            exit(1);
        }
        break;

    case DO_WHILE_NODE:
        if (rightTree->typeTablePtr != typeTableBOOL)
        {
            printf("\nType Error: Conditional Statement of DO WHILE should be of type BOOL\n");
            exit(1);
        }
        break;

    case READ_NODE:
        if (leftTree->nodeType != ID_NODE && leftTree->nodeType != FIELD_NODE && leftTree->nodeType != TUPLE_NODE)
        {
            printf("\nType Error: read() expects an identifier as an argument\n");
            exit(1);
        }

        if (leftTree->typeTablePtr != typeTableINT && leftTree->typeTablePtr != typeTableSTR)
        {
            printf("\nType Error: read() expects argument of type INT or STR\n");
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
        if (leftTree->nodeType != ID_NODE && leftTree->nodeType != MUL_NODE && leftTree->nodeType != FIELD_NODE && leftTree->nodeType != TUPLE_NODE)
        {
            printf("\nType Error: Assignment Operator expects an Identifier in LHS\n");
            exit(1);
        }

        // if (rightTree->typeTablePtr != typeTableINT && rightTree->typeTablePtr != typeTableSTR && rightTree->typeTablePtr != typeTableINTPtr && rightTree->typeTablePtr != typeTableSTRPtr)
        // {
        //     printf("\nType Error: Assignment Operator expects data type INT or STR in RHS\n");
        //     exit(1);
        // }

        if (rightTree->nodeType == ALLOC_NODE)
        {
            if (isPrimitiveType(leftTree->typeTablePtr))
            {
                printf("\nType Error: Dynamic Memory Allocation function expects a user defined type on LHS of assignment operator\n");
                exit(1);
            }
            return 1;
        }

        if (rightTree->typeTablePtr != leftTree->typeTablePtr)
        {

            if (!((leftTree->typeTablePtr == typeTableINTPtr && rightTree->typeTablePtr == typeTableINT) || (leftTree->typeTablePtr == typeTableSTRPtr && rightTree->typeTablePtr == typeTableINT)))
            {
                printf("\nType Error: Assignment Operator expects same data type on both sides\n");
                exit(1);
            }
            else
            {
                return 1;
            }

            if (rightTree->nodeType != NULL_NODE)
            {
                printf("\nType Error: Assignment Operator expects same data type on both sides\n");
                exit(1);
            }
        }

        break;

    default:
        return 1;
        break;
    }
}