#ifndef MEM_FUNC_LIST_H

#define MEM_FUNC_LIST_H

/**
 *  Memberfunc list is used to store the information regarding the type,
 *  name of the function, argument list, it's flabel and it's position of
 *  class methods
 */

struct MemberFuncList
{
    char *funcName;                // Name of the member function
    struct TypeTable *funcType;    // Pointer to typeTable entry for return type
    struct ParamStruct *paramList; // Pointer to head of the formal parameter list
    int funcPosition;              // Position of the function in the class table
    int funcLabel;                 // Label for addressing the functions code
    struct MemberFuncList *next;   // Pointer to next element in the table
} memberfunclist;

extern struct MemberFuncList *memFuncListHead;
extern struct MemberFuncList *memFuncListTail;

/**
 *  @brief  Create a Member Function List entry with function name 'funcName',
 *          function return type 'funcType' and parameter list 'paramList'
 *
 *  @param  funcName    Name of the function
 *  @param  funcType    Return type of the function
 *  @param  paramList   List of function parameters
 *
 *  @return struct MemberFuncList*
 */
struct MemberFuncList *MFLInstall(char *funcName, struct TypeTable *funcType, struct ParamStruct *paramList);

/**
 *  @brief  Search for a Member Function List entry of name 'funcName'
 *          in current Member Function List
 *
 *  @param  funcName    Name of the function to be searched for
 *
 *  @return struct MemberFuncList*
 */
struct MemberFuncList *MFLLookup(char *funcName);

/**
 *  @brief  Search for the Member Function List entry of name 'memberFuncName' for the
 *          class 'classType'. Returns pointer to MemberFuncList entry, else returns
 *          NULL if not found
 *
 *  @param  classType           Pointer to class table entry
 *  @param  memberFuncName      Name of the member function name
 *
 *  @return struct MemberFuncList*
 */
struct MemberFuncList *MemberFuncLookUp(struct ClassTable *classType, char *memberFuncName);

/**
 *  @brief  Verify whether the right arguments are passed for a class
 *          member function
 *
 *  @param  classVar    Pointer to AST node for the class variable
 *  @param  argList     Pointer to AST node for head of argument list
 *
 *  @return int
 */
int verifyClassFuncArgs(struct ASTNode *classVar, struct ASTNode *argList);

void MFLPrint(char *className);

#endif