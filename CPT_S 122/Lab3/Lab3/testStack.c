
#include "testStack.h"


//Test function for isEmpty() function
void testIsEmpty()
{
	//First case: The given stack is empty
	StackNode* pTop = NULL;
	
	Boolean check1 = isEmpty(pTop);
	
	//Second case: The given stack is not empty
	pTop = (StackNode*)malloc(sizeof(StackNode));
	if (pTop != NULL)
	{
		pTop->data = 5.2;
		pTop->pNext = NULL;
	}

	Boolean check2 = isEmpty(pTop);


	if (check1 == True && check2 == False)
	{
		printf("The tes case for isEmpty() function passed!\n");
	}

	else
	{
		printf("The tes case for isEmpty() function failed!\n");
	}

	//Free up for avoiding memory leak
	free(pTop);
}




//Test function for push() function
void testPush()
{
	//First case: Push into an empty stack
	StackNode* pTop = NULL;

	Boolean check1 = False;
	double Data = 2.16;
	push(&pTop, Data);
	if (pTop->data == Data)
	{
		check1 = True;
	}

	//Second case: Push into a non-empty stack
	StackNode* pTop2 = (StackNode*)malloc(sizeof(StackNode));
	if (pTop2 != NULL)
	{
		pTop2->data = 5.2;
		pTop2->pNext = NULL;
	}

	Boolean check2 = False;
	push(&pTop2, Data);
	if (pTop2->data == Data)
	{
		check2 = True;
	}



	if (check1 == True && check2 == True)
	{
		printf("The tes case for push() function passed!\n");
	}

	else
	{
		printf("The tes case for push() function failed!\n");
	}

	//Free up for avoiding memory leak
	free(pTop);
	free(pTop2);
}




//Test function for pop() function
void testPop()
{
	//Create a stack containing two nodes
	StackNode* pTop = (StackNode*)malloc(sizeof(StackNode));
	//StackNode* pNode2 = (StackNode*)malloc(sizeof(StackNode));

	double data1 = 15.21;
	//double data2 = 23.11;
	if (pTop != NULL)
	{
		pTop->data = data1;

		/*if (pNode2 != NULL)
		{
			pNode2->data = data2;
			pNode2->pNext = NULL;
		}*/

		pTop->pNext = NULL;
	}

	//First pop
	Boolean check1 = False;
	pop(&pTop);
	if (pTop == NULL)
	{
		check1 = True;
	}

	////Second pop
	//Boolean check2 = False;
	//pop(&pTop);
	//if (pTop == NULL)
	//{
	//	check2 = True;
	//}


	if (check1 == True)
	{
		printf("The tes case for pop() function passed!\n");
	}

	else
	{
		printf("The tes case for pop() function failed!\n");
	}

	//Free up for avoiding memory leak
	free(pTop);  
	//free(pNode2);
}




//Test function for peek() function
void testPeek()
{
	StackNode* pTop = (StackNode*)malloc(sizeof(StackNode));
	double Data = 1.13;

	if (pTop != NULL)
	{
		pTop->data = Data;
		pTop->pNext = NULL;
	}

	if (peek(pTop) == Data)
	{
		printf("The tes case for peek() function passed!\n");
	}

	else
	{
		printf("The tes case for peek() function failed!\n");
	}

	//Free up for avoiding memory leak
	free(pTop);
}