#include "Queue.h"

Queue::Queue(Node* pNewHead, Node* pNewTail)
{
		this->mpHead = pNewHead;
		this->mpTail = pNewTail;
}

Node* Queue::getHeadPtr() const
{
	return this->mpHead;
}

bool Queue::enqueue(std::string newPrintJob)
{
	Node* pMem = nullptr;
	bool success = false;

	pMem = new Node(newPrintJob); // we need to implement a constructor with parameters for a Node!!!!

	if (pMem != nullptr)
	{
		success = true;

		// empty?
		if (this->mpHead == nullptr)
		{
			// yes, it's empty
			this->mpHead = this->mpTail = pMem;

			// setter
		}
		else // non empty queue
		{
			this->mpTail->setNextPtr(pMem);
			this->mpTail = pMem;
		}
	}

	return success;
}

bool Queue::isEmpty()
{
	return this->mpHead == nullptr;
}

// precondition: queue must not be empty
std::string Queue::dequeue()
{
	Node* pTemp = this->mpHead;
	std::string copyData = "";

	if (this->mpHead == this->mpTail) // there's only 1 node in queue
	{
		this->mpHead = this->mpTail = nullptr;
	}
	else // there's more than 1 node in queue
	{
		this->mpHead = this->mpHead->getNextPtr();
	}

	copyData = pTemp->getData();

	delete pTemp; // this would invoke the destructor for a Node

	return copyData;
}

void Queue::destroyQueue()
{
//	Node* pTemp = nullptr;

	while (!isEmpty())
	{
		dequeue();
	//	delete this->mpHead;
	}
}

Queue::~Queue()
{
	destroyQueue(); // only called within destructor
}