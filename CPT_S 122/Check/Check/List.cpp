
/*

    This file is to establish the definitions for all programmer-defined functions of List class, aside from main ()

*/


#include "List.h"


//Function definitions

template <typename T>
List<T>::List()
{
    this->mpHead = nullptr;
}


template <typename T>
List<T>::~List()
{
    destroy();
}


template <typename T>
void List<T>::destroy()
{
    delete (this->mpHead);
}



template <typename T>
void List<T>::setHeadPtr(Node<T>* const newHeadPtr)
{
    this->mpHead = newHeadPtr;
}


template <typename T>
Node<T>* List<T>::getHeadPtr() const
{
    return mpHead;
}



template <typename T>
bool List<T>::InsertAtFront(T& newData)
{
    bool success = false;
    Node<T>* pMem = new Node<T>(newData);

    if (pMem != nullptr)
    {
        success = true;

        //The list is empty
        if (mpHead == nullptr)
        {
            mpHead = pMem;
        }

        else   //The list is not empty
        {
            pMem->setNextPtr(mpHead);
            mpHead = pMem;
        }
    }

    return success;
}



template <typename T>
void List<T>::print()
{
    if (mpHead == NULL)
    {
        cout << "The master list is empty!" << endl;
    }

    else
    {
        Node<T>* pMem = mpHead;

        while (pMem != NULL)
        {
            cout << *(pMem->getDataPtr());

            pMem = pMem->getNextPtr();
        }
    }
}




template <typename T>
void List<T>::deleteFront()
{
    if (mpHead != NULL)
    {
        Node<T>* pTemp = mpHead;

        mpHead = mpHead->getNextPtr();
        delete pTemp;
    }
}




template <typename T>
void List<T>::clearList()
{
    while (mpHead != NULL)
    {
        deleteFront();
        mpHead = mpHead->getNextPtr();

    }
}