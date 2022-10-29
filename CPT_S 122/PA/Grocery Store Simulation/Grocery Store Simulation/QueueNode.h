
/*

  This is the header file that stores standard library includes, #defined and function prototypes of QueueNode Class

*/


#ifndef QUEUE_NODE_H //guard code

#define QUEUE_NODE_H 


#include "Data.h"


//This class is for storing pointer to Data, which is a node in the main queue
class QueueNode
{
public:
	//Constructor
	QueueNode(const Data& newData);

	//Destructor
	~QueueNode();

	//Setters - Only need to set NextPtr, no step need to set Data in this program
	void setNextPtr(QueueNode* const newNextPtr);

	//Getters
	Data getData() const;
	QueueNode* getNextPtr() const;

private:
	Data* pData;    //The memory for Data is allocated on the heap, instead of the stack
	QueueNode* pNext;
};




#endif
