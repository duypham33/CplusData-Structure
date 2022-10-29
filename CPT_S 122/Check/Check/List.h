
/*

  This is the header file that stores standard library includes, #defined and function prototypes of List class

*/


#ifndef LIST_H //guard code

#define LIST_H


#include "Node.h"
#include "Node.cpp"

template <typename T>
class List
{
public:
	//Constructor
	List();

	//Destructor
	~List();

	//Setter
	void setHeadPtr(Node<T>* const newHeadPtr);

	//Getter
	Node<T>* getHeadPtr() const;

	//Operation
	bool InsertAtFront(T& newData);    //Inserting at the front of a dynamic linked list is very efficient (constant time – O(1))

	void print();

	void deleteFront();

	void clearList();

private:
	Node<T>* mpHead;

	void destroy();
};






#endif

