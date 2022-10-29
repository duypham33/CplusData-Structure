
#include "testQueue.h"


void testIsEmpty()
{
	//Create an empty queue
	Queue* pQueue = new Queue();
	bool check1 = pQueue->isEmpty();

	QueueNode* pMem = new QueueNode("Movie");
	pQueue->setHeadPtr(pMem);
	pQueue->setTailPtr(pMem);

	bool check2 = !pQueue->isEmpty();
	if (check1 && check2)
		cout << "The isEmpty() function passed!" << endl;
	else
		cout << "The isEmpty() function failed!" << endl;

	//delete pQueue;
}



void testEnqueue()
{
	//Create an empty queue
	Queue* pQueue = new Queue();

	//Enqueue an empty queue
	if (pQueue->enqueue("Movie"))
	{
		bool check1 = false;
		if (pQueue->isEmpty() && pQueue->getHeadPtr()->getData() == "Movie" && pQueue->getTailPtr()->getData() == "Movie")
			check1 = true;

		if (check1)
		{
			//Enqueue a non-empty queue
			if (pQueue->enqueue("Cartoon"))
			{
				bool check2 = false;
				if (pQueue->isEmpty() && pQueue->getTailPtr()->getData() == "Cartoon")
					check2 = true;
				if (check2)
					cout << "The enqueue() function passed!" << endl;
				else
					cout << "The enqueue() function failed!" << endl;
			}
		}
		else
			cout << "The enqueue() function failed!" << endl;
	}
	else
		cout << "The enqueue() function failed!" << endl;

	delete pQueue;
}



void testDequeue()
{
	Queue* pQueue = new Queue();
	QueueNode* pMem = new QueueNode("Movie");
	pQueue->setHeadPtr(pMem);
	pQueue->setTailPtr(pMem);

	if (!pQueue->isEmpty())
	{
		string retData = pQueue->dequeue();
		bool check1 = false;
		if (pQueue->isEmpty() && retData == "Movie")
			check1 = true;
	}
}