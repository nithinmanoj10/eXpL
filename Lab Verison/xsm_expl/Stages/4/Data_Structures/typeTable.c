#include "typeTable.h"
#include "../Frontend/ast.h"

int declarationType = TYPE_VOID;

int getDeclarationType()
{
    return declarationType;
}

int setDeclarationType(int type)
{
    declarationType = type;
}