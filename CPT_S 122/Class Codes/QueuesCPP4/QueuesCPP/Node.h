#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Node
{
public:
	Node(const std::string& newPrintJob = "");

	void setNextPtr(Node* const newNextPtr);
	Node* getNextPtr() const;
	std::string getData() const;

private:
	std::string mPrintJob;
	Node* mpNext;
};