#ifndef TYPETABLE_H

#define TYPETABLE_H

extern int declarationType;

// Current parameter type
extern int paramType;

// Current Function Type
extern int funcType;

// current Function name in function definitions
extern char *currentFuncName;

int getDeclarationType();

int setDeclarationType(int type);

/**
 * @brief   Get the Param Type
 *
 * @return  int
 */
int getParamType();

/**
 * @brief   Set the Param Type
 *
 * @param   type New Data Type
 * @return  int
 */
int setParamType(int type);

/**
 * @brief   Get the funcType global variable
 *
 * @return  int
 */
int getFuncType();

/**
 * @brief   Set the funcType global variable
 *
 * @return  int
 */
int setFuncType();

char *getCurrentFuncName();
int setCurrentFuncName(char *newFuncName);

/* Stage 6 Onwards ------------------------------------------------------------------------- */

#define TYPE_PRIMITIVE 1 // Type Categories
#define TYPE_POINTER 2
#define TYPE_USER_DEFINED 3
#define TYPE_TUPLE 4

/** Type Table - Linked List ------------------------------------------------------------------
 *
 *  @brief  Node of a Type Table entry. Type Table stores information regarding
 *          the various user defined types and primitive types in the source program.
 */
struct TypeTable
{
    char *typeName;           // Data Type name
    int typeCategory;         // Category of the data type
    int size;                 // Data Type size
    struct FieldList *fields; // Pointer to the head of fields list
    struct TypeTable *next;   // Pointer to the next type table entry
} typetable;

extern struct TypeTable *typeTableHead;
extern struct TypeTable *typeTableTail;

extern struct TypeTable *typeTableINT;    // Pointer to int Type Table entry
extern struct TypeTable *typeTableINTPtr; // Pointer to int* Type Table entry
extern struct TypeTable *typeTableSTR;    // Pointer to str Type Table entry
extern struct TypeTable *typeTableSTRPtr; // Pointer to str* Type Table entry
extern struct TypeTable *typeTableBOOL;   // Pointer to bool Type Table entry
extern struct TypeTable *typeTableVOID;   // Pointer to void Type Table entry

/**
 *  @brief  Function to initialise the Type Table entries with primitive types (int, str)
 *          and special entries(boolean, null, void).
 */
void TypeTableCreate();

/**
 *  @brief  Search through the type table and return pointer to Type Table entry of
 *          type 'typeName'.
 *
 *  @param  typeName    Name of type to be searched for.
 *
 *  @return Pointer to Type Table pointer.
 *          NULL if not found
 */
struct TypeTable *TTLookUp(char *typeName);

/**
 *  @brief  Creates a type table entry for the (user defined) type of 'typeName' with
 *          given 'fields' and 'size'. The field list must specify the field index,
 *          type and name of each field.
 *
 *          This routine is invoked when the compiler encounters a type definition
 *          in the source program.
 *
 *  @param  typeName    Name of the type
 *  @param  size        Size of the type
 *  @param  fields      Pointer to types field list
 *
 *  @return Pointer to the Type Table entry.
 */
struct TypeTable *TTInstall(char *typeName, int size, struct FieldList *fields);

/**
 *  @brief  Get the size of a user-defined data type
 *
 *  @param  typeTablePtr    Pointer to the type table entry
 *  @return Size of the user defined type
 */
int getTypeSize(struct TypeTable *typeTablePtr);

void printTypeTable();

char *getTypeCategory(int typeCategory);

/**
 *  @brief  Checks whether the type is a primitve type or not.
 *          Primitive type includes int, int*, str, str*, bool, void
 *
 * @param   typeTablePtr    Pointer to type table entry
 * @return  1 if it's a primitive type, else 0
 */
int isPrimitiveType(struct TypeTable *typeTablePtr);

/* ----------------------------------------------------------------------------------------- */

/** Field List - Linked List ------------------------------------------------------------------
 *
 *  @brief  Node of a Field List entry. Stores the information regarding the different
 *          fields of a user-defined type.
 */
struct FieldList
{
    char *fieldName;        // Name of user-defined type field
    int fieldIndex;         // Position of the field in the field list
    struct TypeTable *type; // Pointer to type table entry of the field's type
    struct FieldList *next; // Pointer to the next field
} fieldlist;

extern struct FieldList *fieldListHead;
extern struct FieldList *fieldListTail;

/**
 *  @brief  Create a FieldList node
 *
 *  @param  fieldName   Name of the field
 *  @param  type        Pointer to type table entry for the field
 *
 *  @return Newly created FieldList node
 */
struct FieldList *FLCreateNode(char *fieldName, struct TypeTable *type);

/**
 *  @brief  Searches for a field of given 'fieldName' in the 'fieldList' of the
 *          given user-defined type.
 *
 *  @param  type        Pointer to Type Table entry of given type
 *  @param  fieldName   Name of field
 *
 *  @return Pointer to fieldList entry
 */
struct FieldList *FLLookUp(struct TypeTable *type, char *fieldName);

// Print the current fieldList
void FLPrint(struct TypeTable *typeNode);

/* ----------------------------------------------------------------------------------------- */

#endif