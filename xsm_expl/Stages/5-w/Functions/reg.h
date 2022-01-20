#ifndef REG_H

#define REG_H

/*
 * Keeps count of number of registers currently in use by the machine.
 */
extern int regNum;

/**
 * Allocates a free register (R0-R19)
 * 
 * @return:	Integer value from 0-19 indicating the
 *		number of the free register.

		exits the program if there are no more free registers.
 */
int getReg();

/**
 * Frees a register from use
 *
 * @return:	Register number (0-19), if successfully freed.
 *
 *		-1 if all registers are already freed.	
 */
int freeReg();

/**
 * @brief 	Get the regNum value 
 * 
 * @return 	int 
 */
int getRegNumValue();

#endif
