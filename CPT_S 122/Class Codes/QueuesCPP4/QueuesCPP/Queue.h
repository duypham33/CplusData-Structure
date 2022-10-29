#pragma once

#include <iostream>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(Node* pNewHead = nullptr, Node* pNewTail = nullptr);

	// deep copy vs. shallow copy
	// shallow
	// this->mpHead = copy.mpHead // copy of address
	// this->mpTail= copy.mpTail // copy of address

	Node* getHeadPtr() const;

	bool enqueue(std::string newPrintJob);

	// predicate functions
	bool isEmpty();

	// precondition: queue must not be empty
	std::string dequeue();

	

	~Queue();

private:
	Node* mpHead;
	Node* mpTail;

	void destroyQueue();
};