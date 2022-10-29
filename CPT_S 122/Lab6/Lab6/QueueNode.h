

#include <iostream>


using std::string;


class QueueNode
{
public:
	//Constructor
	QueueNode(const string& newData = "");

	//Destructor
	~QueueNode();

	//Setters
	void setNextPtr(QueueNode* const newNextPtr);

	//Getters
	string getData() const;
	QueueNode* getNextPtr() const;

private:
	string data;
	QueueNode* pNext;
};
