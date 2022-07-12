#include "typeTable.h"
#include "../Frontend/ast.h"

int declarationType = TYPE_VOID;
int paramType = TYPE_VOID;

int getDeclarationType()
{
    return declarationType;
}

int setDeclarationType(int type)
{
    declarationType = type;
    return 0;
}

int getParamType()
{
    return paramType;
}

int setParamType(int type)
{
    paramType = type;
    return 0;
}