#pragma once

#include <iostream>
#include "ListNode.h"

using std::cout;
using std::endl;

template<class N>
class List
{
public:
	List();      // constructor
	~List();     // destructor

	void insertAtFront(const N& newData);
	void insertAtBack(const N& newData);
	bool removeFromFront(N& removedData);
	bool removeFromBack(N& removedData);
	bool isEmpty() const;
	void print() const;

private:
	ListNode<N>* mpHead;  // pointer to first node
	ListNode<N>* mpTail;   // pointer to last node

	// Utility function to allocate a new node
	ListNode<N>* getNewNode(const N& newData);
	//Destroy the list
	void destroyList();
};





template<class N>
List<N>::List()      // constructor
{
	this->mpHead = nullptr;
	this->mpTail = nullptr;
}

template<class N>
List<N>::~List()     // destructor
{
	this->destroyList();
}


template<class N>
void List<N>::insertAtFront(const N& newData)
{
	ListNode<N>* pMem = this->getNewNode(newData);
	if (pMem)
	{
		pMem->setNextPtr(this->mpHead);
		this->mpHead = pMem;
		if (!this->mpTail)
			this->mpTail = pMem;
	}
}

template<class N>
void List<N>::insertAtBack(const N& newData)
{
	ListNode<N>* pMem = this->getNewNode(newData);
	if (pMem)
	{
		if (!this->mpTail)
			this->mpHead = this->mpTail = pMem;
		else
		{
			this->mpTail->setNextPtr(pMem);
			this->mpTail = pMem;
		}
	}
}

template<class N>
bool List<N>::removeFromFront(N& removedData)
{
	if (this->isEmpty())
		return false;
	ListNode<N>* pFront = this->mpHead;
	this->mpHead = pFront->getNextPtr();
	if (this->mpTail == pFront)
		this->mpTail = nullptr;
	removedData = pFront->getData();
	delete pFront;
	pFront = nullptr;

	return true;
}

template<class N>
bool List<N>::removeFromBack(N& removedData)
{
	if (this->isEmpty())
		return false;
	ListNode<N>* pLast = this->mpTail;
	if (this->mpHead == this->mpTail)
		this->mpHead = this->mpTail = nullptr;
	else
	{
		ListNode<N>* pCur = this->mpHead;
		while (pCur->getNextPtr() != pLast)
		{
			pCur = pCur->getNextPtr();
		}
		this->mpTail = pCur;
	}

	removedData = pLast->getData();
	delete pLast;
	pLast = nullptr;

	return true;
}

template<class N>
bool List<N>::isEmpty() const
{
	return (!this->mpHead);
}

template<class N>
void List<N>::print() const
{
	if (this->isEmpty())
		cout << "The list is empty!" << endl;
	else
	{
		ListNode<N>* pCur = this->mpHead;
		while (pCur)
		{
			cout << pCur->getData();
			pCur = pCur->getNextPtr();
			if (!pCur)
				cout << endl;
			else
				cout << "  -->  ";
		}
	}
}




// Utility function to allocate a new node
template<class N>
ListNode<N>* List<N>::getNewNode(const N& newData)
{
	return new ListNode<N>(newData);
}


//Destroy the list
template<class N>
void List<N>::destroyList()
{
	N* pData = new N;
	while (!this->isEmpty())
	{
		this->removeFromFront(*pData);
	}
	delete pData;
	pData = nullptr;
}