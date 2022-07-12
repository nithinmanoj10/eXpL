#include <stdio.h>
#include <stdlib.h>

#include "loopStack.h"

struct loopStackNode *LSHead = NULL;

struct loopStackNode *createLSNode(int val)
{

	struct loopStackNode *newNode;
	newNode = (struct loopStackNode *)malloc(sizeof(struct loopStackNode));

	newNode->labelNum = val;
	newNode->next = NULL;

	return newNode;
}

struct loopStackNode *pushLSNode(struct loopStackNode *loopStart, struct loopStackNode *loopEnd)
{

	if (loopStart == NULL | loopEnd == NULL)
		return NULL;

	loopStart->next = LSHead;
	loopEnd->next = loopStart;
	LSHead = loopEnd;

	return LSHead;
}

int getStartLabel()
{

	if (LSHead == NULL)
		return -1;

	return LSHead->next->labelNum;
}

int getEndLabel()
{

	if (LSHead == NULL)
		return -1;

	return LSHead->labelNum;
}

int popLSNode()
{

	if (LSHead == NULL)
		return -1;

	struct loopStackNode *temp1 = LSHead;
	struct loopStackNode *temp2 = LSHead->next;

	LSHead = temp2->next;

	free(temp1);
	free(temp2);
	temp1 = NULL;
	temp2 = NULL;

	return 1;
}

int LSisEmpty()
{

	if (LSHead == NULL)
		return 1;

	return 0;
}

int printLS()
{

	struct loopStackNode *temp = LSHead;
	printf("\n");

	while (temp != NULL)
	{
		printf("\nLabel End: %d\n", temp->labelNum);
		temp = temp->next;
		printf("Label Start: %d\n", temp->labelNum);
		temp = temp->next;
	}

	return 1;
}
