#pragma once


#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <class T>
class AVLNode
{
public:
	//Constructor
	AVLNode(const T& newData, AVLNode<T>* const newLeftPtr = NULL, AVLNode<T>* const newRightPtr = NULL)
	{
		this->mData = newData;
		this->mpLeft = newLeftPtr;
		this->mpRight = newRightPtr;
		this->height = 0;
	}

	//Destructor
	~AVLNode()
	{
		//The left and right pointers would be destroyed, when the AVL Tree has been is destroyed in postorder!
	}

	
	//Setters
	void setData(const T& newData)
	{
		this->mData = newData;
	}
	
	void setLeftPtr(AVLNode<T>* const newLeftPtr)
	{
		this->mpLeft = newLeftPtr;
	}

	void setRightPtr(AVLNode<T>* const newRightPtr)
	{
		this->mpRight = newRightPtr;
	}

	void setHeight(const int& newHeight)
	{
		this->height = newHeight;
	}


	//Getters
	T& getData()
	{
		return this->mData;
	}

	AVLNode<T>*& getLeftPtr()
	{
		return this->mpLeft;
	}


	AVLNode<T>*& getRightPtr()
	{
		return this->mpRight;
	}

	int getHeight() const
	{
		return this->height;
	}
	
private:
	T mData;
	AVLNode<T>* mpLeft;
	AVLNode<T>* mpRight;
	int height;
};

