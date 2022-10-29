#pragma once

//#include "List.h"


template<class N> class List;  // forward declaration


template<class N>
class ListNode

{
	friend class List<N>; // make List a friend
public:
	ListNode(const N& newData)   //constructor
	{
		this->mData = newData;
		this->mpNext = nullptr;
	}

	//Getters
	N getData() const      // return data in the node
	{
		return this->mData;
	}
	ListNode<N>* getNextPtr() const
	{
		return this->mpNext;
	}

	//Setters
	void setNextPtr(ListNode<N>* const newNextPtr)
	{
		this->mpNext = newNextPtr;
	}
private:
	N mData;          // data
	ListNode<N>* mpNext;   // next node in the list
};
