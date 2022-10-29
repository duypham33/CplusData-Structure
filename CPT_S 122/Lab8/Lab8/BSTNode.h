

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

template <typename T>
class BSTNode
{
public:
	//Constructor
	BSTNode(const T& newData)
	{
		this->mData = newData;
		this->mpLeft = NULL;
		this->mpRight = NULL;
		this->cnt = 1;
	}

	//Destructor
	~BSTNode()
	{

	}

	//Setters
	void setData(const T& newData)
	{
		this->mData = newData;
	}
	void setLeftPtr(BSTNode<T>* const newLeftPtr)
	{
		this->mpLeft = newLeftPtr;
	}
	void setRightPtr(BSTNode<T>* const newRightPtr)
	{
		this->mpRight = newRightPtr;
	}
	
	//Getters
	T getData() const
	{
		return this->mData;
	}
	BSTNode<T>* getLeftPtr() const
	{
		return this->mpLeft;
	}
	BSTNode<T>* getRightPtr() const
	{
		return this->mpRight;
	}
	int getCounter() const
	{
		return this->cnt;
	}

	void increaseCounter()
	{
		this->cnt++;
	}

private:
	T mData;
	BSTNode<T>* mpLeft;
	BSTNode<T>* mpRight;
	int cnt;
};


//Overload the stream insertion operator
template <typename T>
ostream& operator << (ostream& lhs, BSTNode<T>* rhs)
{
	if (rhs)
		lhs << rhs->getData() << endl;
	return lhs;
}