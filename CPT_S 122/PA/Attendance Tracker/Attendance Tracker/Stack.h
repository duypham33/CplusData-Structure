
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Stack class

*/


#ifndef STACK_H //guard code

#define STACK_H


#include <iostream>   //Neccessary to input/output
#include <vector>     //Neccesary to implement a stack by array
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::string;


//This class is a stack for storing the dates of absences of each student.
class Stack
{
public:
	//Constructor
	Stack(const vector<string>& newAbsDates = {});

	//Destructor
	~Stack();

	//Operations

	//This function checks whether the stack is empty or not.
	bool isEmpty();

	//This function is to add a new element at the top of the stack
	void push(const string& newAbsDate);

	//This function is to remove the top element from the stack, if it is not empty. Returns true if the top element has been popped, false if it is empty.
	bool pop();

	//This function is for getting the top element from the stack, if it is not empty. If the stack is empty, returns a "" string
	string peek();

	//This function displays all the absent dates for the user to view when he/she wants to edit some absent date. Returns false, if stack is empty!
	bool print();
	//This function search the input date from the user in the stack. If it is found, then removes it from the stack and return true. Otherwise return false
	bool remove(string date);

private:
	//Data members
	vector<string> mAbsDates;   //The absent dates of a student
};


#endif