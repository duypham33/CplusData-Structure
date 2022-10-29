
/*

  This is the header file that stores standard library includes, #defined and function prototypes and definitions of TransactionNode Class

*/


#ifndef TRANSACTION_NODE_H   //guard code

#define TRANSACTION_NODE_H

#include "Node.h"



//This class publically inherits from abstract base class Node. It has an addition private data member as the number of product units.
class TransactionNode : public Node
{
public:
	//Constructor - invokes class Node’s constructor
	TransactionNode(const string& newData = "", const int& newUnits = 0);

	//Destructor
	~TransactionNode();

	//Setter
	void setUnits(const int& newUnits);
	//Getter
	int getUnits() const;

	//Overrides the pure virtual printData() function in class Node
	void printData();

private:
	//Private data member
	int mUnits;
};




#endif