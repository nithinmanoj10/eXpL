#include <stdio.h>
#include <stdlib.h>
#include "intepreter.h"
#include "ast.h"

int codeIntepreter(struct ASTNode *root)
{
    // for NULL node
    if (root == NULL)
        return 1;

    // if its a NUM or VARIABLE (array variable as well)
    if (root->nodeType == CONST_INT_NODE || root->nodeType == CONST_STR_NODE || root->nodeType == ID_NODE)
        return 1;

    // for an IF Node
    if (root->nodeType == IF_NODE)
    {

        if (evalCondTree(root->left))
        {
            codeIntepreter(root->middle);
        }
        else
        {
            codeIntepreter(root->right);
        }

        return 1;
    }

    // for a WHILE Node
    if (root->nodeType == WHILE_NODE)
    {
        while (evalCondTree(root->left))
        {
            codeIntepreter(root->right);
        }

        return 1;
    }

    // for a DO WHILE Node
    if (root->nodeType == DO_WHILE_NODE)
    {
        do
        {
            codeIntepreter(root->right);
        } while (evalCondTree(root->left));
    }

    codeIntepreter(root->left);
    codeIntepreter(root->right);

    // for an "=" OPERATOR Node
    if (root->nodeType == ASGN_NODE)
    {

        int variable = *root->left->nodeName - 97;
        int num = evalExprTree(root->right);

        variableStorage[variable] = num;

        return 1;
    }

    // for a READ Node
    if (root->nodeType == READ_NODE)
    {

        int variable = *root->left->nodeName - 97;
        int num;
        char buffer[1024];

        fgets(buffer, 1024, stdin);
        num = atoi(buffer);

        variableStorage[variable] = num;

        return 1;
    }

    // for a WRITE Node
    if (root->nodeType == WRITE_NODE)
    {

        int num;

        num = evalExprTree(root->left);
        printf("%d\n", num);

        return 1;
    }
}