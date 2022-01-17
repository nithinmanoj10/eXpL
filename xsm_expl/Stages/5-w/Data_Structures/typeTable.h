#ifndef TYPETABLE_H

#define TYPETABLE_H

extern int declarationType;

// Current parameter type
extern int paramType;

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

#endif