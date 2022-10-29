
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Node class

*/


#ifndef NODE_H //guard code

#define NODE_H


#include "Data.h"
//#include "Data.cpp"

template <typename N>
class Node
{
public:
	//Default constructor
	Node();

	//Constructor
	Node(const N& newData);

	//Destructor
	~Node();

	//Setters
	void setData(const N& newData);
	void setNextPtr(Node<N>* const newNextPtr);

	//Getters
	N* getDataPtr();
	Node<N>* getNextPtr() const;

private:
	N mData;
	Node<N>* mpNext;
};








#endif
