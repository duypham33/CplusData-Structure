


#include "header.h"



Boolean isEmpty(StackNode* pTop)
{
	return ((pTop == NULL) ? True : False);
}



Boolean push(StackNode** pTop, double newData)
{
	Boolean success = False;

	//Allocate memory dynamically
	StackNode* pMem = (StackNode*)malloc(sizeof(StackNode));

	if (pMem != NULL)
	{
		//The memmory has been available
		pMem->data = newData;
		pMem->pNext = *pTop;

		*pTop = pMem;
		success = True;
	}

	return success;
}


void pop(StackNode** pTop)
{
	if (isEmpty(*pTop) != True)   //The stack is not empty
	{
		//Delete at front of the stack
		StackNode* pFront = *pTop;
		*pTop = pFront->pNext;
		free(pFront);    //Free memory up 
	}
}



double peek(StackNode* pTop)
{
	if (pTop == NULL)
	{
		return -1.0;    
	}

	else
	{
		return (pTop->data);
	}
}