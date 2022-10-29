#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;


// Implement red black Node
template <class T>
class RBNode
{
public:
	//Constructor
	RBNode(const T& newData, const char& newColor = 'r', RBNode<T>* const newParentPtr = NULL,
		RBNode<T>* const newLeftPtr = NULL, RBNode<T>* const newRightPtr = NULL)
	{
		this->mData = newData;
		if (newColor == 'r' || newColor == 'b')
			this->color = newColor;
		else
			this->color = 'r';

		this->mpParent = newParentPtr;
		this->mpLeft = newLeftPtr;
		this->mpRight = newRightPtr;
	}

	//Destructor
	~RBNode()
	{
		//The left and right pointers would be destroyed, when the Red Black Tree has been is destroyed in postorder!
	}

	//Change color (Black to Red, or Red to Black)
	void reColor()
	{
		char newColor = (this->color == 'r') ? 'b' : 'r';
		this->color = newColor;
	}

	//Setters
	void setData(const T& newData)
	{
		this->mData = newData;
	}

	void setParentPtr(RBNode<T>* const newParentPtr)
	{
		this->mpParent = newParentPtr;
	}

	void setLeftPtr(RBNode<T>* const newLeftPtr)
	{
		this->mpLeft = newLeftPtr;
	}

	void setRightPtr(RBNode<T>* const newRightPtr)
	{
		this->mpRight = newRightPtr;
	}

	//Getters
	T& getData()
	{
		return this->mData;
	}

	char getColor() const
	{
		return this->color;
	}

	RBNode<T>*& getParentPtr()
	{
		return this->mpParent;
	}

	RBNode<T>*& getLeftPtr()
	{
		return this->mpLeft;
	}

	RBNode<T>*& getRightPtr()
	{
		return this->mpRight;
	}

private:
	//Data members
	T mData;
	char color;    // 'r' for red, 'b' for black
	RBNode<T>* mpParent;
	RBNode<T>* mpLeft;
	RBNode<T>* mpRight;
};
