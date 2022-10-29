#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <typename N>
class Node
{
public:
	Node(const N &newData);

	N getData() const;
	Node<N>* getLeftPtr() const;
	Node<N>* getRightPtr() const;

	void setLeftPtr(Node<N>* newLeftPtr);
	void setRightPtr(Node<N>* newRightPtr);

private:
	N mData;
	Node<N>* mpLeft;
	Node<N>* mpRight;
};

template <typename N>
Node<N>::Node(const N &newData)
{
	this->mData = newData;
	this->mpLeft = this->mpRight = nullptr;
}

template <typename N>
N Node<N>::getData() const
{
	return this->mData;
}

template <typename N>
Node<N>* Node<N>::getLeftPtr() const
{
	return this->mpLeft;
}

template <typename N>
Node<N>* Node<N>::getRightPtr() const
{
	return this->mpRight;
}

template <typename N>
void Node<N>::setLeftPtr(Node<N>* newLeftPtr)
{
	this->mpLeft = newLeftPtr;
}

template <typename N>
void Node<N>::setRightPtr(Node<N>* newRightPtr)
{
	this->mpRight = newRightPtr;
}