
/*

  This is the header file that stores standard library includes, #defined and function prototypes and definitions of Node Class

*/


#ifndef NODE_H   //guard code

#define NODE_H


#include <iostream>  //Neccessary to print out the screen 
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//This is an abstract base class Node for class TransactionNode. It stores the type of the product as data.
class Node
{
public:
	//Constructor
	Node(const string& newData = "");

	//Virtual destructor
	virtual ~Node();

	//Setters
	void setData(const string& newData);
	void setLeftPtr(Node* const newLeftPtr);
	void setRightPtr(Node* const newRightPtr);

	//Getters
	string getData() const;
	//Returns a reference to the pointers
	Node*& getLeftPtr();
	Node*& getRightPtr();

	//Pure virtual printData() function, which is overridden in class TransactionNode
	virtual void printData() = 0;

protected:
	//Protected data members
	string mData;
	Node* mpLeft;
	Node* mpRight;
};



#endif
