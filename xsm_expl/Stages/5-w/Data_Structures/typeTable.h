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

#endif