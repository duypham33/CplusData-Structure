#include "Node.h"

Node::Node(const std::string& newPrintJob)
{
	this->mPrintJob = newPrintJob;
	this->mpNext = nullptr;
}

void Node::setNextPtr(Node* const newNextPtr)
{
	this->mpNext = newNextPtr;
}

Node* Node::getNextPtr() const
{
	return this->mpNext;
}

std::string Node::getData() const
{
	return this->mPrintJob;
}