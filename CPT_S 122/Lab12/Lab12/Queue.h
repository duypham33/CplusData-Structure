#pragma once


#include "List.h"


template <class N>
class Queue : private List<N>
{
public:
	//Constructor
	Queue()
	{
		//The constructor of List class (base class) has been invoked!
	}

	//Destructor
	~Queue()
	{
		//The destructor of List class (base class) has been invoked!
	}

	//Enqueue
	void enqueue(const N& newData)
	{
		this->insertAtBack(newData);
	}
	//Dequeue
	bool dequeue(N& removedData)
	{
		return this->removeFromFront(removedData);
	}
	//Print queue
	void printQueue() const
	{
		this->print();
	}

private:
	
};



////Enqueue
//template <class N>
//void Queue<N>::enqueue(const N& newData)
//{
//	this->insertAtBack(newData);
//}
////Dequeue
//template <class N>
//bool Queue<N>::dequeue(N& removedData)
//{
//	return this->removeFromFront(removedData);
//}