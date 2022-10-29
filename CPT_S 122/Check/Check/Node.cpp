
/*

    This file is to establish the definitions for all programmer-defined functions of Node class, aside from main ()

*/


#include "Node.h"

//Function definitions

template <typename N>
Node<N>::Node()
{
    this->mpNext = nullptr;
}



template <typename N>
Node<N>::Node(const N& newData)
{
    this->mData = newData;
    this->mpNext = nullptr;
}


template <typename N>
Node<N>::~Node()
{

}



template <typename N>
void Node<N>::setData(const N& newData)
{
    this->mData = newData;
}


template <typename N>
void Node<N>::setNextPtr(Node<N>* const newNextPtr)
{
    this->mpNext = newNextPtr;
}



template <typename N>
N* Node<N>::getDataPtr()
{
    return &mData;
}



template <typename N>
Node<N>* Node<N>::getNextPtr() const
{
    return mpNext;
}