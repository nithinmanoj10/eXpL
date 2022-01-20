#ifndef STACKMEM_H

#define STACKMEM_H

/**
 *	Global Variable that holds the Stack Memory thats free
 */
extern int freeStackMemory;

/**
 *	Function that returns free stack memory
 *
 *	@params		num:			Amount of memory required
 *
 *	@return		freeMem:	Amount of memory	
 */
int getFreeStackMemory(int num);

int getFreeStackMemoryValue();

#endif
