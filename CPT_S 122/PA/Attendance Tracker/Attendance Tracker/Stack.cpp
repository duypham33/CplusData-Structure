
/*

    This file is to establish the definitions for all programmer-defined functions of Stack class, aside from main ()

*/


#include "Stack.h"


//Function definitions

//Constructor
Stack::Stack(const vector<string>& newAbsDates)
{
    this->mAbsDates = newAbsDates;
}


//Destructor
Stack::~Stack()
{
    //Clear the stack
    this->mAbsDates.clear();
}



//This function checks whether the stack is empty or not.
bool Stack::isEmpty()
{
    return this->mAbsDates.empty();
}

//This function is to add a new element at the top of the stack
void Stack::push(const string& newAbsDate)
{
    this->mAbsDates.push_back(newAbsDate);
}

//This function is to remove the top element from the stack, if it is not empty. Returns true if the top element has been popped, false if it is empty.
bool Stack::pop()
{
    if (!isEmpty())
    {
        this->mAbsDates.pop_back();
        return true;
    }

    return false;
}

//This function is for getting the top element from the stack, if it is not empty. If the stack is empty, returns a "" string
string Stack::peek()
{
    if (!this->isEmpty())
        return this->mAbsDates.back();
    return "";
}

//This function displays all the absent dates for the user to view when he/she wants to edit some absent date. Returns false, if stack is empty!
bool Stack::print()
{
    if (!isEmpty())  //Check whether the stack is empty!
    {
        cout << endl;
        for (int i = 0; i < this->mAbsDates.size(); i++)
        {
            cout << "       " << this->mAbsDates[i] << endl;
        }
        return true;
    }
    else
        cout << "    EMPTY" << endl;
    return false;
}

//This function search the input date from the user in the stack. If it is found, then removes it from the stack and return true. Otherwise return false
bool Stack::remove(string date)
{
    int i = 0;
    bool found = false;

    for (i = 0; i < this->mAbsDates.size(); i++)
    {
        if (this->mAbsDates[i] == date)
        {
            found = true;
            break;
        }
    }

    if (found)
        this->mAbsDates.erase(this->mAbsDates.begin() + i);   //Remove the date

    return found;
}