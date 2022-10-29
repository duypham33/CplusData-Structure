
/*

    This file is to establish the definitions for all programmer-defined functions of Stack class, aside from main ()

*/


#include "Stack.h"


//Function definitions

Stack::Stack(std::vector <string> const newDataList)
{
    this->mDataList = newDataList;
}

Stack::~Stack()
{
    destroy();
}



void Stack::destroy()
{
    mDataList.clear();
}




bool Stack::isEmpty()
{
    return mDataList.empty();
}


void Stack::push(string newData)
{
    mDataList.push_back(newData);
}

string Stack::pop()
{
    string retData = "";
    if (!isEmpty())
    {
        retData = mDataList.back();
        mDataList.pop_back();
    }

    return retData;
}

string Stack::peek()
{
    string retData = "";
    if (!isEmpty())
    {
        retData = mDataList.back();       
    }

    return retData;
}



void Stack::print()
{
    if (!isEmpty())
    {
        cout << endl;

        for (int i = 0; i < mDataList.size(); i++)
        {
            cout << "       " << mDataList[i] << endl;
        }      
    }
}



bool Stack::remove(string data)
{
    int i = 0;
    bool found = false;
    
    for (i = 0; i < mDataList.size(); i++)
    {
        if (mDataList[i] == data)
        {
            found = true;
            break;
        }
    }

    if (found == true)
    {
        mDataList.erase(mDataList.begin() + i);
    }

    return found;
}