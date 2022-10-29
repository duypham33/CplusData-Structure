
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Stack class

*/


#ifndef STACK_H //guard code

#define STACK_H


#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;



using std::string;


class Stack
{
public:
	//Constructor
	Stack(std::vector <string> const newDataList = {});

	//Destructor
	~Stack();

	//Operations
	bool isEmpty();
	void push(string newData);
	string pop();
	string peek();

private:
	std::vector <string> mDataList;

	void destroy();
};








#endif

