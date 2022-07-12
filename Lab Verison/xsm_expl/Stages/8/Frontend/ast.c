#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ast.h"
#include "../Functions/reg.h"
#include "../Functions/typeCheck.h"
#include "../Functions/label.h"
#include "../Functions/xsm_library.h"
#include "../Data_Structures/GSTable.h"
#include "../Data_Structures/LSTable.h"
#include "../Data_Structures/typeTable.h"
#include "../Data_Structures/memberFuncList.h"
#include "../Data_Structures/classTable.h"

int ASTTableSno = 0;
int sourceLineNumber = 0;

struct ASTNode *TreeCreate(struct TypeTable *typeTablePtr, int nodeType, char *nodeName, int intConstVal, char *strConstVal, struct ASTNode *left, struct ASTNode *middle, struct ASTNode *right)
{

    typeCheck(nodeType, left, right, middle);

    struct ASTNode *newASTNode = (struct ASTNode *)malloc(sizeof(struct ASTNode));

    newASTNode->sno = 0;
    newASTNode->typeTablePtr = typeTablePtr;
    newASTNode->classTablePtr = NULL;
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

int printAST(struct ASTNode *root, int sno)
{

    if (root == NULL)
        return 1;

    printAST(root->left, sno);
    printAST(root->middle, sno);
    printAST(root->right, sno);

    ++ASTTableSno;
    root->sno = ASTTableSno;

    printf("%3d", ASTTableSno);
    printf("%19s", getNodeName(root->nodeType));

    if (root->typeTablePtr != NULL)
        printf("%15s", root->typeTablePtr->typeName);
    else
        printf("%15s", "-");

    if (root->classTablePtr != NULL)
        printf("%15s", root->classTablePtr->className);
    else
        printf("%15s", "-");

    if (root->nodeName != NULL)
        printf("%20s", root->nodeName);
    else
        printf("%20s", "-");

    if (root->intConstVal == INT_MAX)
        printf("%13s", "-");
    else
        printf("%13d", root->intConstVal);

    if (root->strConstVal != NULL)
        printf("%21s", root->strConstVal);
    else
        printf("%21s", "-");

    if (root->left != 0)
        printf("%6d", root->left->sno);
    else
        printf("%6s", "-");

    if (root->middle != 0)
        printf("%8d", root->middle->sno);
    else
        printf("%8s", "-");

    if (root->right != 0)
        printf("%7d\n", root->right->sno);
    else
        printf("%7s\n", "-");

    // if (root->GSTEntry != NULL)
    //     printf("%19p", root->GSTEntry);
    // else
    //     printf("%19s", "-");

    // if (root->LSTEntry != NULL)
    //     printf("%19p\n", root->LSTEntry);
    // else
    //     printf("%19s\n", "-");

    return 0;
}

void printASTTable(struct ASTNode *root, int sno)
{
    ASTTableSno = 0;
    printf("\n\nAbstract Syntax Tree\n\n");

    printf("SNo         NodeType       DataType      ClassType            NodeName  intConstVal          strConstVal  Left  Middle  Right\n");
    printf("─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n\n");
    printAST(root, sno);
}

char *getNodeName(int nodeType)
{
    switch (nodeType)
    {
    case CONST_INT_NODE:
        return "Number 🔢";
        break;

    case CONST_STR_NODE:
        return "String 🧵";
        break;

    case ID_NODE:
        return "Identifier 🆔";
        break;

    case PLUS_NODE:
        return "Plus ➕";
        break;

    case MINUS_NODE:
        return "Minus ➖";
        break;

    case MUL_NODE:
        return "Multiply 💑";
        break;

    case DIV_NODE:
        return "Division ➗";
        break;

    case AMP_NODE:
        return "Ampersand ⚓";
        break;

    case GT_NODE:
        return "Greater Than >";
        break;

    case LT_NODE:
        return "Lesser Than <";
        break;

    case GE_NODE:
        return "Greater Equal >=";
        break;

    case LE_NODE:
        return "Less Equal <=";
        break;

    case EQ_NODE:
        return "Equal To ==";
        break;

    case NE_NODE:
        return "Not Equal To !=";
        break;

    case IF_NODE:
        return "If 🤷";
        break;

    case WHILE_NODE:
        return "While 💁";
        break;

    case DO_WHILE_NODE:
        return "Do While 💆";
        break;

    case BREAK_NODE:
        return "Break 💔";
        break;

    case CONTINUE_NODE:
        return "Continue 🏃";
        break;

    case ASGN_NODE:
        return "Assignment 💫";
        break;

    case READ_NODE:
        return "Read() 📖";
        break;

    case WRITE_NODE:
        return "write() 📝";
        break;

    case SLIST_NODE:
        return "SList 🔗";
        break;

    case BREAKPOINT_NODE:
        return "Breakpoint 🛑";
        break;

    case FUNC_NODE:
        return "Function 🎁";
        break;

    case FIELD_NODE:
        return "Struct Field 📦";
        break;

    case SELF_NODE:
        return "Self 🤳";
        break;

    case MEM_FUNC_NODE:
        return "Member Func 🧨";
        break;

    case SELF_FUNC_NODE:
        return "Self Func 🎇";
        break;

    case TUPLE_NODE:
        return "Tuple 🥡";

    case RETURN_NODE:
        return "Return 🔙";
        break;

    case AND_NODE:
        return "And 🔷";
        break;

    case OR_NODE:
        return "Or 🔶";
        break;

    case NOT_NODE:
        return "Not 🙅";
        break;

    case INITIALIZE_NODE:
        return "Initialize 🌟";
        break;

    case ALLOC_NODE:
        return "Alloc 🧧";
        break;

    case FREE_NODE:
        return "Free 🆓";
        break;

    case NEW_NODE:
        return "New 🆕";
        break;

    case NULL_NODE:
        return "NULL 🎃";
        break;

    case TUPLE_CONSTRUCTOR_NODE:
        return "Tuple Constr. 👷";
        break;

    default:
        break;
    }

    return "-";
}

int getVariableAddress(FILE *filePtr, struct ASTNode *root)
{
    int variableAddrReg = getReg();

    // if the variable is dereferenced using self
    if (root->nodeType == SELF_NODE)
        return getSelfVariableAddress(filePtr, root, variableAddrReg);

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

        if (root->nodeType == FIELD_NODE)
            getStructVariableAddress(filePtr, root, variableAddrReg);

        if (root->nodeType == TUPLE_NODE)
            getTupleVariableAddress(filePtr, root, variableAddrReg);
    }
    else
    {
        int variableBindingReg = getReg();
        fprintf(filePtr, "MOV R%d, %d\n", variableBindingReg, varLSTEntry->binding);
        fprintf(filePtr, "MOV R%d, BP\n", variableAddrReg);
        fprintf(filePtr, "ADD R%d, R%d\n", variableAddrReg, variableBindingReg);

        // for array variable
        if (root->left != NULL)
        {
            int offsetReg = getReg();
            fprintf(filePtr, "MOV R%d, R%d\n", offsetReg, evalExprTree(filePtr, root->left));
            fprintf(filePtr, "ADD R%d, R%d\n", variableAddrReg, offsetReg);
            freeReg();
            freeReg();
        }

        if (root->nodeType == FIELD_NODE)
            getStructVariableAddress(filePtr, root, variableAddrReg);

        if (root->nodeType == TUPLE_NODE)
            getTupleVariableAddress(filePtr, root, variableAddrReg);

        freeReg();
    }

    return variableAddrReg;
}

int getStructVariableAddress(FILE *filePtr, struct ASTNode *root, int structAddrReg)
{
    int fieldIndexReg = getReg();
    int heapAddrReg = getReg();
    struct FieldList *currentField = NULL;
    struct TypeTable *currentStructType = NULL;
    struct LSTNode *structLSTEntry = NULL;

    while (root->nodeType == FIELD_NODE)
    {
        structLSTEntry = LSTLookup(root->nodeName);

        if (structLSTEntry == NULL)
        {
            struct GSTNode *structGSTEntry = GSTLookup(root->nodeName);

            if (structGSTEntry == NULL)
                currentStructType = root->typeTablePtr;
            else
                currentStructType = structGSTEntry->typeTablePtr;
        }
        else
            currentStructType = structLSTEntry->typeTablePtr;

        currentField = FLLookUp(currentStructType, NULL, root->right->nodeName);

        fprintf(filePtr, "MOV R%d, [R%d]\n", heapAddrReg, structAddrReg);
        fprintf(filePtr, "MOV R%d, %d\n", fieldIndexReg, currentField->fieldIndex);
        fprintf(filePtr, "ADD R%d, R%d\n", heapAddrReg, fieldIndexReg);
        fprintf(filePtr, "MOV R%d, R%d\n", structAddrReg, heapAddrReg);

        root = root->right;
    }

    freeReg(); // heapAddrReg from getStructVariableAddress()
    freeReg(); // fieldIndexReg from getStructVariableAddress()

    return structAddrReg;
}

int getTupleVariableAddress(FILE *filePtr, struct ASTNode *root, int tupleAddrReg)
{
    int fieldIndexReg = getReg();
    struct FieldList *Field = NULL;
    struct TypeTable *TupleType = NULL;
    struct LSTNode *tupleLSTEntry = NULL;

    tupleLSTEntry = LSTLookup(root->nodeName);

    if (tupleLSTEntry == NULL)
    {
        struct GSTNode *tupleGSTEntry = GSTLookup(root->nodeName);
        TupleType = tupleGSTEntry->typeTablePtr;
    }
    else
        TupleType = tupleLSTEntry->typeTablePtr;

    Field = FLLookUp(TupleType, NULL, root->right->nodeName);

    fprintf(filePtr, "MOV R%d, %d\n", fieldIndexReg, Field->fieldIndex);
    fprintf(filePtr, "ADD R%d, R%d\n", tupleAddrReg, fieldIndexReg);

    freeReg(); // fieldIndexReg from getTupleVariableAddress

    return tupleAddrReg;
}

int getSelfVariableAddress(FILE *filePtr, struct ASTNode *root, int variableAddrReg)
{
    int selfHeapAddrReg = getReg();
    struct LSTNode *LSTFirstEntry = LSTHead;
    int selfBinding = (LSTFirstEntry == NULL || LSTFirstEntry->binding > 0) ? (-4) : (LSTFirstEntry->binding - 2); // Binding of self
    int fieldIndex = 0;
    struct ASTNode *selfField = NULL;

    fprintf(filePtr, "MOV R%d, BP\n", selfHeapAddrReg);
    fprintf(filePtr, "ADD R%d, %d\n", selfHeapAddrReg, selfBinding);
    fprintf(filePtr, "MOV R%d, [R%d]\n", variableAddrReg, selfHeapAddrReg);

    while (root->right != NULL)
    {
        selfField = root->right;

        if (root->nodeType == FIELD_NODE)
        {
            fieldIndex = FLLookUp(root->typeTablePtr, NULL, selfField->nodeName)->fieldIndex;
        }

        if (root->nodeType == SELF_NODE)
        {
            fieldIndex = FLLookUp(NULL, currentClassTable, selfField->nodeName)->fieldIndex;
        }

        fprintf(filePtr, "ADD R%d, %d\n", variableAddrReg, fieldIndex);

        if (selfField->right != NULL)
            fprintf(filePtr, "MOV R%d, [R%d]\n", variableAddrReg, variableAddrReg);

        root = root->right;
    }

    freeReg(); // selfHeapAddrReg from getSelfVariableAddress

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

    if (root->nodeType == NULL_NODE)
    {
        int resultReg = getReg();
        fprintf(filePtr, "MOV R%d, \"null\"\n", resultReg);

        return resultReg;
    }

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

    if (root->nodeType == FIELD_NODE)
    {
        int exprTreeResultReg = getReg();
        int structAddressReg = getVariableAddress(filePtr, root);

        fprintf(filePtr, "MOV R%d, [R%d]\n", exprTreeResultReg, structAddressReg);

        freeReg(); // variableAddrReg from evalExprTree()

        return exprTreeResultReg;
    }

    if (root->nodeType == TUPLE_NODE)
    {
        int exprTreeResultReg = getReg();
        int tupleAddressReg = getVariableAddress(filePtr, root);

        fprintf(filePtr, "MOV R%d, [R%d]\n", exprTreeResultReg, tupleAddressReg);

        freeReg(); // variableAddrReg from evalExprTree()

        return exprTreeResultReg;
    }

    if (root->nodeType == SELF_NODE)
    {

        int exprTreeResultReg = getReg();
        int selfAddressReg = getVariableAddress(filePtr, root);

        fprintf(filePtr, "MOV R%d, [R%d]\n", exprTreeResultReg, selfAddressReg);

        freeReg(); // variableAddrReg from evalExprTree()

        return exprTreeResultReg;
    }

    // for a FUNCTION Node or a Member Function Node or Self Function Node
    if (root->nodeType == FUNC_NODE || root->nodeType == MEM_FUNC_NODE || root->nodeType == SELF_FUNC_NODE)
    {

        // save the context of all register in use by
        // pushing them all into the stack
        int regCount = getRegNumValue();
        for (int i = 0; i <= regCount; ++i)
            fprintf(filePtr, "PUSH R%d\n", i);

        int memFuncLabel; // function label of class member function
        int isMemFuncNode = (root->nodeType == MEM_FUNC_NODE) ? (1) : (0);
        int isSelfFuncNode = (root->nodeType == SELF_FUNC_NODE) ? (1) : (0);

        if (isMemFuncNode)
        {

            // find the index of the function being called from the class table entry
            // for that variable
            int functionIndex = MemberFuncLookUp(GSTLookup(root->nodeName)->classTablePtr, root->right->nodeName, root->right->argListHead)->funcPosition - 1;

            // get the calling address of the function from the VFT
            int VFTAddrReg = getReg();
            int funcCallAddrReg = getReg();
            int classVarBinding = GSTLookup(root->nodeName)->binding;

            // Base address of VFT is stored in VFTAddrReg
            fprintf(filePtr, "MOV R%d, %d\n", VFTAddrReg, classVarBinding);
            fprintf(filePtr, "ADD R%d, 1\n", VFTAddrReg);
            fprintf(filePtr, "MOV R%d, [R%d]\n", VFTAddrReg, VFTAddrReg);

            // calling address of the function is stored in funcCallAddrReg
            fprintf(filePtr, "MOV R%d, R%d\n", funcCallAddrReg, VFTAddrReg);
            fprintf(filePtr, "ADD R%d, %d\n", funcCallAddrReg, functionIndex);
            fprintf(filePtr, "MOV R%d, [R%d]\n", funcCallAddrReg, funcCallAddrReg);

            // Pushing the heap address and the pointer
            // to the VFT of the class variable  that is calling the function into the stack
            int classVarHeapAddrReg = getReg();
            fprintf(filePtr, "MOV R%d, [%d]\n", classVarHeapAddrReg, root->GSTEntry->binding);
            fprintf(filePtr, "PUSH R%d\n", classVarHeapAddrReg);
            fprintf(filePtr, "PUSH R%d\n", VFTAddrReg);

            freeReg(); // For classVarHeapAddrReg

            // struct ASTNode *classVarNode = root;

            // // root is currently pointing to the class variable, we need to
            // // make it point to the member function node
            // while (root->right != NULL)
            //     root = root->right;

            // memFuncLabel = getMemFuncLabel(classVarNode->nodeName, root->nodeName);
            memFuncLabel = funcCallAddrReg;
        }

        if (isSelfFuncNode)
        {
            // Heap address of self has to be pushed to the stack initially
            int VFTAddrReg = getReg();
            int funcCallAddrReg = getReg();
            int selfHeapAddrReg = getReg();

            struct LSTNode *LSTFirstEntry = LSTHead;
            int selfBinding = (LSTFirstEntry == NULL) ? (-4) : (LSTFirstEntry->binding); // Binding of self
            selfBinding = (selfBinding > 0) ? (selfBinding - 5) : (selfBinding - 2);
            int fieldIndex = 0;
            struct ASTNode *classVarNode = NULL;

            fprintf(filePtr, "MOV R%d, BP\n", selfHeapAddrReg);
            fprintf(filePtr, "ADD R%d, %d\n", selfHeapAddrReg, selfBinding);
            fprintf(filePtr, "MOV R%d, [R%d]\n", selfHeapAddrReg, selfHeapAddrReg);

            fprintf(filePtr, "MOV R%d, BP\n", VFTAddrReg);
            fprintf(filePtr, "ADD R%d, %d\n", VFTAddrReg, selfBinding + 1);
            fprintf(filePtr, "MOV R%d, [R%d]\n", VFTAddrReg, VFTAddrReg);

            while (root->right->nodeType == FIELD_NODE)
            {

                if (root->nodeType == SELF_FUNC_NODE)
                {
                    fieldIndex = FLLookUp(NULL, currentClassTable, root->right->nodeName)->fieldIndex;
                }
                else
                {
                    fieldIndex = FLLookUp(NULL, root->classTablePtr, root->right->nodeName)->fieldIndex;
                }

                fprintf(filePtr, "ADD R%d, %d\n", selfHeapAddrReg, fieldIndex);
                fprintf(filePtr, "MOV R%d, [R%d]\n", selfHeapAddrReg, selfHeapAddrReg);

                classVarNode = root->right;
                fprintf(filePtr, "MOV R%d, %d\n", VFTAddrReg, getClassVirtFuncAddress(classVarNode->classTablePtr->className));

                root = root->right;
            }

            fprintf(filePtr, "PUSH R%d\n", selfHeapAddrReg);
            fprintf(filePtr, "PUSH R%d\n", VFTAddrReg);

            int functionIndex = MemberFuncLookUp(currentClassTable, root->right->nodeName, root->right->argListHead)->funcPosition - 1;

            fprintf(filePtr, "MOV R%d, R%d\n", funcCallAddrReg, VFTAddrReg);
            fprintf(filePtr, "ADD R%d, %d\n", funcCallAddrReg, functionIndex);
            fprintf(filePtr, "MOV R%d, [R%d]\n", funcCallAddrReg, funcCallAddrReg);

            freeReg(); // selfHeapAddrReg from evalExprTree

            // struct ASTNode *classVarNode = root;

            // // root is currently pointing to the class variable, we need to
            // // make it point to the member function node
            // while (root->right != NULL)
            //     root = root->right;

            // if (classVarNode->classTablePtr != NULL)
            //     memFuncLabel = MemberFuncLookUp(classVarNode->classTablePtr, root->nodeName)->funcLabel;
            // else
            //     memFuncLabel = MemberFuncLookUp(currentClassTable, root->nodeName)->funcLabel;

            memFuncLabel = funcCallAddrReg;
        }

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
        // if its a function declared globally, search in GST for the function label
        // else if its a class member function, search Member Function List of that class
        if (root->nodeType == FUNC_NODE)
        {
            struct GSTNode *funcGSTEntry = GSTLookup(root->nodeName);
            fprintf(filePtr, "CALL F%d\n", funcGSTEntry->fLabel);
        }
        else if (isMemFuncNode)
        {
            fprintf(filePtr, "CALL R%d\n", memFuncLabel);
            freeReg(); // funcCallAddrReg
            freeReg(); // VFTAddrReg
        }
        else if (isSelfFuncNode)
        {
            fprintf(filePtr, "CALL R%d\n", memFuncLabel);
            freeReg(); // funcCallAddrReg
            freeReg(); // VFTAddReg from evalExprTree
        }

        // Store the return value in a register
        int returnValueReg = getReg();
        fprintf(filePtr, "POP R%d\n", returnValueReg);

        // POP out all the arguments
        for (int i = 0; i < argCount; ++i)
            fprintf(filePtr, "POP R10\n");

        // incase its a member function node, we pop out the
        // heap address and VFT pointer of the class variable that was pushed initially
        if (isMemFuncNode || isSelfFuncNode)
        {
            fprintf(filePtr, "POP R10\n");
            fprintf(filePtr, "POP R10\n");
        }

        // restore the saved context of all registers
        // by popping them all from the stack
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
            // if the ID is not a class variable
            if (IDNode->GSTEntry->classTablePtr == NULL)
            {
                IDNode->typeTablePtr = IDNode->GSTEntry->typeTablePtr;
                IDNode->classTablePtr = NULL;
            }

            // if the ID is a class variable
            if (IDNode->GSTEntry->classTablePtr != NULL)
            {
                IDNode->classTablePtr = IDNode->GSTEntry->classTablePtr;
                IDNode->typeTablePtr = NULL;
            }
        }
    }
    else
    {
        IDNode->LSTEntry = IdLSTEntry;
        IDNode->typeTablePtr = IdLSTEntry->typeTablePtr;
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

        if (funcParamList->typeTablePtr != argumentList->typeTablePtr)
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

int verifyTupleFields(struct TypeTable *tupleType, struct ASTNode *tupleFieldList)
{
    struct FieldList *definedFieldList = tupleType->fields;

    while (definedFieldList != NULL && tupleFieldList != NULL)
    {
        if (definedFieldList->type != tupleFieldList->typeTablePtr)
        {
            printf("\nTuple Error: Incorrect field passed during construction of tuple type %s\n", tupleType->typeName);
            exit(1);
        }
        definedFieldList = definedFieldList->next;
        tupleFieldList = tupleFieldList->argListNext;
    }

    if (definedFieldList == NULL && tupleFieldList == NULL)
        return 1;

    printf("\nTuple Error: Not enough tuple fields passed during construction of tuple type %s\n", tupleType->typeName);
    exit(1);
}
