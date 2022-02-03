#ifndef TUPLE_LIST_TABLE_H

#define TUPLE_LIST_TABLE_H

/**
 * Data Structure that stores information about Tuples locally declared.
 * Keeps track of the tuple name and its field lists
 */

/**
 *  Node of the Tuple Field List. Contains information about the
 *  fields present in the tuple definition. Important when using
 *  the dereferencing operator (. dot), on a tuple object.
 * 
 *  eg: tuple student(str name, int age, int rollNo) studOne;            
 *      
 *      tupleFieldName:     "name"              "age"               "rollNo"
 *      tupleFieldType:     TYPE_STR    -->     TYPE_INT    -->     TYPE_INT
 *      tupleFieldBinding:  0                   1                   2
 * 
 */
struct TupleFieldList
{
    char *tupleFieldName;        // Name of the tuple field
    int tupleFieldType;          // Data type of the tuple field
    int tupleFieldBinding;       // Binding of the tuple field
    struct TupleFieldList *next; // Next node in the Tuple Field List
} tuplefieldlist;

/**
 *  Node of the Tuple List. Contains information about the different
 *  tuple data types present locally. Important when trying to access
 *  any fields of a given tuple data type.
 * 
 *  eg: tuple student(str name, int age, int rollNo) studOne;
 *      tuple teacher(str name, str subject, int teacerID) teachOne;
 *  
 *      tupleName:              "student"   -->     "teacher"
 *      tupleFieldListHead:         |                   |
 *                                                                                          
 */

struct TupleList
{
    char *tupleName;                           // Name of the tuple data type
    struct TupleFieldList *tupleFieldListHead; // Pointer to head of Tuple Field List
    struct TupleList *next;                    // Next Node in the Tuple List
} tuplelist;

/**
 *  Node of the Tuple Type Table. Contains information about the Tuple Data
 *  type name and its associated integer value. 
 * 
 *  tupleTypeNum starts from 200 and goes till 220
 * 
 *  eg: tuple student(...) studOne;
 *      tuple teacher(...) teachOne;
 * 
 *      tupleTypeName:      "student"   -->     "teacher"
 *      tupleTypeNum:        200                201
 * 
 */
struct TupleTypeTable
{
    char *tupleTypeName;         // Name of the tuple data type
    int tupleTypeNum;            // Integer value associated with each tuple data type
    struct TupleTypeTable *next; // Pointer to next node
} tupletypetable;

// Functions ------------------------------------------------------------------------------

struct TupleList *insertTuple(char *tupleName);
struct TupleList *getTuple(char *tupleName);
int printTupleList();
int setCurrentTupleID(char *tupleID);
char *getCurrentTupleID();

struct TupleFieldList *insertTupleField(char *tupleFieldName, int tupleFieldType);
struct TupleFieldList *getTupleField(char *tupleFieldName);
struct TupleFieldList *searchTupleField(struct TupleFieldList *head, char *fieldName);
int printTupleFieldList();
int flushTupleFieldList();
int setTupleFieldType(int type);
int getTupleFieldType();

struct TupleTypeTable *insertTupleType(char *tupleTypeName);
int getTupleTypeNum(char *tupleTypeName);
char *getTupleTypeName(int tupleTypeNum);
int printTupleTypeTable();

// ----------------------------------------------------------------------------------------

// Tuple Field Count Functions ------------------------------------------------------------------------------

// Get the tupleFieldCount variable
int getTupleFieldCount();

// Increment the tupleFieldCount variable by one
int incTupleFieldCount();

// Set tupleFieldCount variable to 0
int flushTupleFieldCount();

// ----------------------------------------------------------------------------------------

// * Global Variables -----------------------------------------------------------------------

extern struct TupleList *tupleListHead; // Pointer to the Head of the Tuple List
extern struct TupleList *tupleListTail; // Pointer to the Tail of the Tuple List
extern char *currentTupleID;            // Name of the current Tuple being declared

extern struct TupleFieldList *tupleFieldListHead; // Pointer to the head of the Tuple Field List
extern struct TupleFieldList *tupleFieldListTail; // Pointer to the tail of the Tuple Field List
extern int tupleFieldType;

extern struct TupleTypeTable *tupleTypeTableHead; // Pointer to the head of the Tuple Type Head
extern struct TupleTypeTable *tupleTypeTableTail; // Pointer to the head of the Tuple Type Tail
extern int tupleTypeNumCount;                     // Starts from 200

extern int tupleFieldCount; // Count of number of fields in a tuple

// * ----------------------------------------------------------------------------------------

#endif