
#include "QueueNode.h"


QueueNode::QueueNode(const string& newData)
{
	this->data = newData;
	this->pNext = NULL;
}


QueueNode::~QueueNode()
{

}


void QueueNode::setNextPtr(QueueNode* const newNextPtr)
{
	this->pNext = newNextPtr;
}


string QueueNode::getData() const
{
	return data;
}


QueueNode* QueueNode::getNextPtr() const
{
	return pNext;
}