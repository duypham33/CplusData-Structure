#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <typename T>
class BST
{
public:
	BST();

	void insert(const T &newData); // convert to template
	void inorderTraversal();
	void postorderTraversal();

private:
	void insert(Node<T>* pTree, const T &newData); // convert to template
	void inorderTraversal(Node<T>* pTree);
	void postorderTraversal(Node<T>* pTree);
	Node<T>* mpRoot;
};

template <typename T>
BST<T>::BST()
{
	this->mpRoot = nullptr; // empty tree
}

template <typename T>
void BST<T>::insert(const T &newData)
{
	insert(this->mpRoot, newData);
}

template <typename T>
void BST<T>::insert(Node<T>* pTree, const T &newData)
{
	if (pTree == nullptr)
	{
		// tree is empty
		this->mpRoot = new Node<T>(newData);
	}
	else // tree not empty
	{
		if (newData < pTree->getData()) // left subtree
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				// we found the place to insert in left subtree
				pTree->setLeftPtr(new Node<T>(newData));
			}
			else
			{
				// recursive step - we have to continue to traverse down tree
				// left subtree
				insert(pTree->getLeftPtr(), newData);
			}
		}
		else if (pTree->getData() < newData )
		{
			if (pTree->getRightPtr() == nullptr)
			{
				// attach the data to tree in right subtree
				pTree->setRightPtr(new Node<T>(newData));
			}
			else
			{
				// traverse thru tree - right subtree
				insert(pTree->getRightPtr(), newData);
			}
		}
		else
		{
			std::cout << "duplicate: " << newData << std::endl;
		}
	}
}

template <typename T>
void BST<T>::inorderTraversal()
{
	inorderTraversal(this->mpRoot);
}

template <typename T>
void BST<T>::inorderTraversal(Node<T>* pTree)
{
	if (pTree != nullptr)
	{
		// recursive step
		inorderTraversal(pTree->getLeftPtr()); // left
		std::cout << pTree->getData() << std::endl; // process
		inorderTraversal(pTree->getRightPtr()); // right
	}
}

template <typename T>
void BST<T>::postorderTraversal()
{
	postorderTraversal(this->mpRoot);
}

template <typename T>
void BST<T>::postorderTraversal(Node<T>* pTree)
{
	if (pTree != nullptr)
	{
		postorderTraversal(pTree->getLeftPtr()); // left
		postorderTraversal(pTree->getRightPtr()); // right
		std::cout << pTree->getData() << std::endl; // process
	}
}