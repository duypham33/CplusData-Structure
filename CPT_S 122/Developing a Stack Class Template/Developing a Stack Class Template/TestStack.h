

#include "Stack.h"

template <class T>
class TestStack
{
public:
	TestStack();
	~TestStack();
	bool Test(T& item1, T& item2);

private:
	Stack<T> theStack;
};

template <class T>
TestStack<T>::TestStack() : theStack(-1)
{

}

template <class T>
TestStack<T>::~TestStack()
{

}

template <class T>
bool TestStack<T>::Test(T& item1, T& item2)
{
	theStack.push(item1);
	theStack.peek(item2);
	cout << "peek: " << item2 << endl;

	return (item1 == item2);
}

