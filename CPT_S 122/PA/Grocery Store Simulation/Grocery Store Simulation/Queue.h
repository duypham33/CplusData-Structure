
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Queue Class

*/


#ifndef QUEUE_H //guard code

#define QUEUE_H 

#include "QueueNode.h"


//This class represents grocery lines. We will simulate two lines- normal line and express line.
class Queue
{
public:
	//Default constructor - This initializes an empty queue with head and tail NULL pointers
	Queue();

	//Destructor
	~Queue();

	//Getter
	QueueNode* getHeadPtr() const;   
	QueueNode* getTailPtr() const;

	//Operations

	//This function checks whether the queue is empty. Returns true if it is empty(pHead == pTail == NULL), false is otherwise.
	bool isEmpty();
	//This function prints the content of nodes in the queue to the screen. The parameter is a width value to set a field width when printing the queue.
	//This is because we will display two lanes at the same time, so should set a field width between them.
	void printQueue(int w_value);
	//This function inserts a node at the end of the queue. Returns true if the memory is allocated for the new node, false is otherwise.
	bool enqueue(const Data& newData);
	//This function deletes a node at the head of the queue. If queue is empty, do nothing.
	void dequeue();
	//This function return the first data in the queue. Precondition: The queue is not empty. 
	//This function is useful to display information on checking-out customer, and to compute the next checkout time, which is vital.
	Data top() const;

private:
	QueueNode* pHead;     //The pointer to the beginning of the queue
	QueueNode* pTail;     // The pointer to the end of the queue
};


#endif




