#include <stdio.h>
#include <stdlib.h>
#include "typeCheck.h"
#include "../Frontend/ast.h"

int typeCheck(int nodeType, struct ASTNode *leftTree, struct ASTNode *rightTree)
{

    switch (nodeType)
    {
    case PLUS_NODE:
        if (leftTree->dataType != TYPE_INT || rightTree->dataType != TYPE_INT)
        {
            printf("\nType Error: Addition Operator requires data type INT\n");
            exit(1);
        }
        break;

    case MINUS_NODE:
        if (leftTree->dataType != TYPE_INT || rightTree->dataType != TYPE_INT)
        {
            printf("\nType Error: Subtraction Operator requires data type INT\n");
            exit(1);
        }
        break;

    case MUL_NODE:
        if (leftTree->dataType != TYPE_INT || rightTree->dataType != TYPE_INT)
        {
            printf("\nType Error: Multiplication Operator requires data type INT\n");
            exit(1);
        }
        break;

    case DIV_NODE:
        if (leftTree->dataType != TYPE_INT || rightTree->dataType != TYPE_INT)
        {
            printf("\nType Error: Division Operator requires data type INT\n");
            exit(1);
        }
        break;

    case MOD_NODE:
        if (leftTree->dataType != TYPE_INT || rightTree->dataType != TYPE_INT)
        {
            printf("\nType Error: Modulus Operator requires data type INT\n");
            exit(1);
        }
        break;

    case LT_NODE:
        if (leftTree->dataType != TYPE_INT || rightTree->dataType != TYPE_INT)
        {
            printf("\nType Error: Less Than Operator requires data type INT\n");
            exit(1);
        }
        break;

    case LE_NODE:
        if (leftTree->dataType != TYPE_INT || rightTree->dataType != TYPE_INT)
        {
            printf("\nType Error: Less Than Equal Operator requires data type INT\n");
            exit(1);
        }
        break;

    case GT_NODE:
        if (leftTree->dataType != TYPE_INT || rightTree->dataType != TYPE_INT)
        {
            printf("\nType Error: Greater Than Operator requires data type INT\n");
            exit(1);
        }
        break;

    case GE_NODE:
        if (leftTree->dataType != TYPE_INT || rightTree->dataType != TYPE_INT)
        {
            printf("\nType Error: Greater Than Equal Operator requires data type INT\n");
            exit(1);
        }
        break;

    case EQ_NODE:
        if (leftTree->dataType != rightTree->dataType)
        {
            printf("\nType Error: Equal To Operator requires same data type on both sides\n");
            exit(1);
        }
        break;

    case NE_NODE:
        if (leftTree->dataType != rightTree->dataType)
        {
            printf("\nType Error: Not Equal To Operator requires same data type on both sides\n");
            exit(1);
        }
        break;

    case IF_NODE:
        if (leftTree->dataType != TYPE_BOOL)
        {
            printf("\nType Error: Conditional Statement of IF should be of type BOOL\n");
            exit(1);
        }
        break;

    case WHILE_NODE:
        if (leftTree->dataType != TYPE_BOOL)
        {
            printf("\nType Error: Conditional Statement of WHILE should be of type BOOL\n");
            exit(1);
        }
        break;

    case DO_WHILE_NODE:
        if (rightTree->dataType != TYPE_BOOL)
        {
            printf("\nType Error: Conditional Statement of DO WHILE should be of type BOOL\n");
            exit(1);
        }
        break;

    case READ_NODE:
        if (leftTree->nodeType != ID_NODE)
        {
            printf("\nType Error: read() expects an identifier as an argument\n");
            exit(1);
        }

        if (leftTree->dataType != TYPE_INT)
        {
            printf("\nType Error: read() expects argument of type INT\n");
            exit(1);
        }
        break;

    case WRITE_NODE:
        if (leftTree->dataType != TYPE_INT)
        {
            printf("\nType Error: write() expects argument of type INT\n");
            exit(1);
        }
        break;

    case ASGN_NODE:
        if (leftTree->nodeType != ID_NODE)
        {
            printf("\nType Error: Assignment Operator expects an Identifier in LHS\n");
            exit(1);
        }

        if (rightTree->dataType != TYPE_INT)
        {
            printf("\nType Error: Assignment Operator expects data type INT in RHS\n");
            exit(1);
        }

        break;

    default:
        return 1;
        break;
    }
}