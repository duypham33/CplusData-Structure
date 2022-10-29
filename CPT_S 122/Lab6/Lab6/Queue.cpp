
#include "Queue.h"


Queue::Queue(QueueNode* const newHeadPtr, QueueNode* const newTailPtr)
{
	this->pHead = newHeadPtr;
	this->pTail = newTailPtr;
}

Queue::~Queue()
{
	delete pHead;
	delete pTail;
}


void Queue::setHeadPtr(QueueNode* const newHeadPtr)
{
	this->pHead = newHeadPtr;
}

void Queue::setTailPtr(QueueNode* const newTailPtr)
{
	this->pTail = newTailPtr;
}

QueueNode* Queue::getHeadPtr() const
{
	return pHead;
}

QueueNode* Queue::getTailPtr() const
{
	return pTail;
}


bool Queue::isEmpty()
{
	return (pHead == NULL);
}


bool Queue::enqueue(const string& newData)
{
	QueueNode* pMem = new QueueNode(newData);
	bool success = false;

	if (pMem)
	{
		success = true;    //The memory was allocated for a node
		if (isEmpty())
		{
			pHead = pMem;
			pTail = pMem;
		}

		else
		{
			pMem->setNextPtr(pTail);
			pTail = pMem;	
		}
	}

	return success;
}



string Queue::dequeue()
{
	string retData = pHead->getData();
	QueueNode* pFront = pHead;
	if (pHead == pTail)
		pHead = pTail = NULL;

	else
		pHead = pFront->getNextPtr();
	
	delete pFront;

	return retData;
}




void Queue::printQueueRecursive(QueueNode* node)
{
	if (!node)
		return;
	cout << node->getData() << endl << "\t |" << endl << "\t |" << endl << "\t V" << endl;
	printQueueRecursive(node->getNextPtr());
}

void Queue::printQueueRecursive()
{
	if (isEmpty())
		cout << "The queue is empty!" << endl;
	else
		printQueueRecursive(pHead);
}