
/*

  This is the header file that stores standard library includes, #defined and function prototypes of List class

*/


#ifndef LIST_H //guard code

#define LIST_H

#include "Node.h"


//This is a template class that contains nodes, which is considerd as the master list.
template <typename T>
class List
{
public:
	//Constructor
	List();

	//Destructor
	~List();

	//Getter
	Node<T>* getHeadPtr() const;

	//Operations

	//Check whether the list is empty or not.
	bool isEmpty();

	//Insertion at front - Returns true if the space is successfully allocated for the new node. Otherwise is false.
	bool insertFront(const T& newData);

	//Delete the node at the head of the list. This takes O(1) time complexity. This function is useful to destroy the list.
	void deleteFront();

	//This function destroys the list, used in destructor and the load() fucntion in TrackerApp class
	void destroyList();

	//This function prints out the content of the list
	void print();

private:
	Node<T>* mpHead;    //The pointer to the head node of the list
};



//Function definitions


//Constructor
template <typename T>
List<T>::List()
{
	//Initialize an empty list
	this->mpHead = NULL;
}


//Destructor
template <typename T>
List<T>::~List()
{
	//Call the destroy() function to destroy the list
	this->destroyList();
}



//Getter
template <typename T>
Node<T>* List<T>::getHeadPtr() const
{
	return this->mpHead;
}


//Check whether the list is empty or not.
template <typename T>
bool List<T>::isEmpty()
{
	return (!this->mpHead);
}


//Insertion at front - Returns true if the space is successfully allocated for the new node. Otherwise is false.
template <typename T>
bool List<T>::insertFront(const T& newData)
{
	bool success = false;
	//Allocate space for the new node
	Node<T>* pMem = new Node<T>(newData);
	if (pMem)
	{
		//The memory is available
		success = true;
		pMem->setNextPtr(this->mpHead);
		this->mpHead = pMem;
	}

	return success;
}


//Delete the node at the head of the list. This takes O(1) time complexity. This function is useful to destroy the list.
template <typename T>
void List<T>::deleteFront()
{
	if (this->mpHead)   //Check whether the list is empty or not
	{
		Node<T>* pFront = this->mpHead;
		this->mpHead = pFront->getNextPtr();
		delete pFront;
		pFront = NULL;
	}
}


//This function destroys the list, used in destructor and the load() fucntion in TrackerApp class
template <typename T>
void List<T>::destroyList()
{
	//Delete at front of the list until it is empty!
	while (this->mpHead)
	{
		deleteFront();
	}
}


//This function prints out the content of the list
template <typename T>
void List<T>::print()
{
	if (!this->mpHead)
		cout << "The list is empty!" << endl;
	else
	{
		Node<T>* pNode = this->mpHead;
		while (pNode)
		{
			cout << *pNode->getDataPtr();
			cout << endl;
			pNode = pNode->getNextPtr();
		}
	}
}


#endif