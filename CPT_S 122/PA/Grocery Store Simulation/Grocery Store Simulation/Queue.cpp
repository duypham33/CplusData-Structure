
/*

	This file is to establish the definitions for all programmer-defined functions of Queue Class, aside from main ()

*/


#include "Queue.h"


//Function definitions

//Default constructor - This initializes an empty queue with head and tail NULL pointers
Queue::Queue()
{
	this->pHead = NULL;
	this->pTail = NULL;
}

//Destructor
Queue::~Queue()
{
	//Destroy queue
	while (!isEmpty())
	{
		dequeue();   //Dequeues until the queue is empty
	}
}


//Getter
QueueNode* Queue::getHeadPtr() const
{
	return this->pHead;
}


QueueNode* Queue::getTailPtr() const
{
	return this->pTail;
}


//Operations

//This function checks whether the queue is empty. Returns true if it is empty(pHead == pTail == NULL), false is otherwise 
bool Queue::isEmpty()
{
	return (this->pHead == NULL);
}

//This function prints the content of nodes in the queue to the screen. The parameter is a width value to set a field width when printing the queue.
//This is because we will display two lanes at the same time, so should set a field width between them.
void Queue::printQueue(int w_value)
{
	if (!isEmpty())   //Check whether the queue is empty
	{
		QueueNode* pCur = this->pHead;

		while (pCur != NULL)
		{
			cout << std::setw(w_value) << "\t\tCustomer " << pCur->getData().getCustomerNumber() << endl;
			pCur = pCur->getNextPtr();

			if (pCur != NULL)
			{
				//Display the link between nodes (customers)
				cout << std::setw(w_value) << "\t\t    |" << endl
					<< std::setw(w_value) << "\t\t    |" << endl
					<< std::setw(w_value) << "\t\t    V" << endl;
			}
		}

		cout << endl;
	}
}


//This function inserts a node at the end of the queue. Returns true if the memory is allocated for the new node, false is otherwise
bool Queue::enqueue(const Data& newData)
{
	bool success = false;   //To check the memory is allocated successfully
	QueueNode* pMem = new QueueNode(newData);   //Allocate space for the new node

	if (pMem)   //Check the memory is available
	{
		success = true;    //The memory is allocated
		
		if (isEmpty())  //If the queue is currently empty, update pHead as well
			this->pHead = pMem;
		else  //Not empty, update next pointer of pTail to insert at the end
			this->pTail->setNextPtr(pMem);
		this->pTail = pMem;   //Update pTail
	}

	return success;
}


//This function deletes a node at the head of the queue. If queue is empty, do nothing.
void Queue::dequeue()
{
	if (!isEmpty())   //The queue is not empty
	{
		QueueNode* pFront = this->pHead;

		if (this->pHead == this->pTail)   //If there is currently one node in the queue, set pHead and pTail to nullptr
			this->pHead = this->pTail = NULL;
		else     //Otherwise just update pHead to the next pointer
			this->pHead = pFront->getNextPtr();
		delete pFront;   //Free up the memory 
	}
}




//This function return the first data in the queue. Precondition: The queue is not empty.
//This function is useful to display information on checking-out customer, and to compute the next checkout time, which is vital.
Data Queue::top() const
{
	return (this->pHead->getData());
}