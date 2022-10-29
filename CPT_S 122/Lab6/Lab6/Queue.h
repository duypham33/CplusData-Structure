
#include "QueueNode.h"
using std::cout;
using std::endl;

class Queue
{
public:
	//Constructor
	Queue(QueueNode* const newHeadPtr = NULL, QueueNode* const newTailPtr = NULL);

	//Destructor
	~Queue();

	//Setters
	void setHeadPtr(QueueNode* const newHeadPtr);
	void setTailPtr(QueueNode* const newTailPtr);

	//Getters
	QueueNode* getHeadPtr() const;
	QueueNode* getTailPtr() const;

	//Operation
	//A predicate function which checks to see if the queue is empty; returns true if the queue is empty; false otherwise
	bool isEmpty();

	/*
	   Inserts a node into the queue at the tail; 
	   the node is allocated dynamically on the heap using the C++ operator new;
	   returns true if the memory was allocated for a node, false otherwise
	*/
	bool enqueue(const string& newData);

	/*
	    Deletes a node from the head of the queue using the C++ operator delete; 
		Eeturns the data in the node; 
		Precondition: queue is not empty (isEmpty () must be called before dequeue () is called)
	*/
	string dequeue();


	//Print the queue recursively
	void printQueueRecursive();

private:
	QueueNode* pHead;
	QueueNode* pTail;

	void printQueueRecursive(QueueNode* node);
};