#ifndef CLASS_TABLE_H

#define CLASS_TABLE_H

/**
 *  The class table stores information pertaining to all the classes
 *  declared in an OExpL program. For a class it stores member fields,
 *  member functions, name of the class and parent class pointer.
 */

struct ClassTable
{
    char *className;                           // Name of the class
    struct FieldList *memberField;             // Pointer to class member field list
    struct MemberFuncList *virtualFunctionPtr; // Pointer to class member function list
    struct ClassTable *parentPtr;              // Pointer to parent class table
    int classIndex;                            // Position of the class in the virtual function table
    int fieldCount;                            // Count of class fields
    int methodCount;                           // Count of class methods
    struct ClassTable *next;                   // Pointer to next class table entry
} classtable;

extern struct ClassTable *classTableHead;          // Pointer to Class Table head
extern struct ClassTable *classTableTail;          // Pointer to Class Table tail
extern struct ClassTable *currentClassTable;       // Pointer to class table being currently defined
extern struct ClassTable *currentParentClassTable; // Pointer to class table entry of parent class
extern struct ClassTable *currentCDeclType;        // Pointer to current class table entry for varaible declaration
extern struct ClassTable *currentFieldCType;       // Pointer to class table entry for field class type

/**
 *  @brief  Creates a ClassTable entry of given 'className' and
 *          extends the fields and the methods of parent class
 *          and returns a pointer to the newly created class entry.
 *
 *  @param  className           Name of the new class
 *  @param  parentClassName     Name of the parent class
 *
 *  @return struct ClassTable*
 */
struct ClassTable *CTInstall(char *className, char *parentClassName);

/**
 *  @brief  Search for a class table entry with the given 'className',
 *          if exists, return pointer to class table entry else return NULL
 *
 *  @param  className   Name of the class to be searched
 *
 *  @return struct ClassTable*
 */
struct ClassTable *CTLookUp(char *className);

/**
 *  @brief  Installs the member field into the given class table entry
 *          which is given as an argument
 *
 *  @param  classTablePtr       Pointer to class table entry
 *  @param  memberTypeName      Name of the type of the member to be added
 *  @param  memberName          Name of the member to be added
 */
void CTMemberInstall(struct ClassTable *classTablePtr, char *memberTypeName, char *memberName);

/**
 *  @brief  Installs the method into the given class table entry
 *          which is given as an argument
 *
 *  @param  classTablePtr       Pointer to class table entry
 *  @param  methodName          Name of the class method
 *  @param  methodType          Pointer to TableType entry for class method
 *  @param  methodParamList     Pointer to head of parameter list of the method
 */
void CTMethodInstall(struct ClassTable *classTablePtr, char *methodName, struct TypeTable *methodType, struct ParamStruct *methodParamList);

/**
 *  @brief  Verify whether a field belongs to a class. Returns 1 if it
 *          does, else returns 0
 *
 *  @param  classTablePtr   Pointer to class table entry
 *  @param  fieldName       Name of the field
 *
 *  @return int
 */
int verifyClassField(struct ClassTable *classTablePtr, char *fieldName);

/**
 *  @brief  Returns the Virtual Function Table entry address of the class
 *          named 'className'
 *
 *  @param  className   Name of the class
 *
 *  @return int
 */
int getClassVirtFuncAddress(char *className);

/**
 *  @brief  Returns 1 if the class named 'childClassName' is a descented
 *          of the class named 'parentClassName', else returns 0
 *
 *  @param  childClassName      Name of the child class
 *  @param  parentClassName     Name of the parent class
 *
 *  @return int
 */
int isDescentedClass(char *childClassName, char *parentClassName);

/**
 *  @brief  Pretty-print the Class Table
 */
void CTPrint();

#endif