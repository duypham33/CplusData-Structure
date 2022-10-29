#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;


template <class T>
class BSTNode
{
public:
	//Constructor
	BSTNode(const T& newData, BSTNode<T>* const newLeftPtr = nullptr, BSTNode<T>* const newRightPtr = nullptr)
	{
		this->mData = newData;
		this->mpLeft = newLeftPtr;
		this->mpRight = newRightPtr;
	}

	//Destructor
	~BSTNode()
	{
		//The left and right pointers would be destroyed, when the BST is destroyed!
	}

	//Getters
	T& getData()
	{
		return this->mData;
	}

	BSTNode<T>*& getLeftPtr()
	{
		return this->mpLeft;
	}

	BSTNode<T>*& getRightPtr()
	{
		return this->mpRight;
	}

	//Setters
	void setData(const T& newData)
	{
		this->mData = newData;
	}

	void setLeftPtr(BSTNode<T>* const newLeftPtr)
	{
		this->mpLeft = newLeftPtr;
	}

	void setRightPtr(BSTNode<T>* const newRightPtr)
	{
		this->mpRight = newRightPtr;
	}

private:
	T mData;
	BSTNode<T>* mpLeft;
	BSTNode<T>* mpRight;
};