#ifndef PARAMSTRUCT_H

#define PARAMSTRUCT_H

// Node of a functions parameter list
struct ParamStruct
{
    int paramType;            // Data Type of the parameter, int or str
    char *paramName;          // Name of the parameter
    struct ParamStruct *next; // Pointer to next element in the list
} paramstruct;

extern struct ParamStruct *paramListHead; // Pointer to head of parameter list
extern struct ParamStruct *paramListTail; // Pointer to tail of parameter list

/**
 * @brief   Add a function parameter to its parameter list
 * 
 * @param   paramType Data Type of the Parameter
 * @param   paramName Name of the Parameter
 * @return  struct ParamStruct* Pointer to the new parameter list node
 */
struct ParamStruct *paramListInstall(int paramType, char *paramName);

/**
 * @brief   Search for a function parameter in its parameter list 
 * 
 * @param   paramType Data Type of the parameter 
 * @param   paramName Name of the parameter
 * @return  struct ParamStruct* Pointer to node, if found.
 *          NULL, if not found. 
 */
struct ParamStruct *paramListLookup(int paramType, char *paramName);

/**
 * @brief   Get the Param List Head object
 * 
 * @return  struct ParamStruct*
 */
struct ParamStruct *getParamListHead();

/**
 * @brief   Set the Param List Head object
 * 
 * @param   newHead Pointer to the new head
 * @return  int
 */
int setParamListHead(struct ParamStruct *newHead);

/**
 * @brief   Print the paramlist of a function 
 * 
 */
int printParamList()

#endif