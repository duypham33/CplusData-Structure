
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Node class

*/


#ifndef NODE_H //guard code

#define NODE_H


#include "Data.h"

//This is a template class of a node storing data for record and a next pointer to the next node
template <typename T>
class Node
{
public:
	//Constructor
	Node(const T& newData);

	//Destructor
	~Node();

	//Setters
	void setNextPtr(Node<T>* const newNextPtr);

	//Getters
	T* getDataPtr();
	Node<T>* getNextPtr() const;

private:
	T mData;           //The record data
	Node<T>* mpNext;   //The next pointer to the next node
};



//Function definitions


//Constructor
template <typename T>
Node<T>::Node(const T& newData)
{
	this->mData = newData;
	this->mpNext = NULL;
}


//Destructor
template <typename T>
Node<T>::~Node()
{

}


//Setters
template <typename T>
void Node<T>::setNextPtr(Node<T>* const newNextPtr)
{
	this->mpNext = newNextPtr;
}



//Getters
template <typename T>
T* Node<T>::getDataPtr()
{
	return (&this->mData);
}


template <typename T>
Node<T>* Node<T>::getNextPtr() const
{
	return this->mpNext;
}





#endif