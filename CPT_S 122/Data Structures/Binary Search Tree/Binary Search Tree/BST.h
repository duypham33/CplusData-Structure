#pragma once

#include "BSTNode.h"

//Global Variable for the currrent depth
int CUR_DEPTH = -1;

template <class T>
class BST
{
public:
	//Default Constructor
	BST()
	{
		//Initializes an empty tree
		this->mpRoot = NULL;
	}

	//Destructor
	~BST()
	{
		//Destroy the BST
		this->destroyTree(this->mpRoot);
		if (!this->mpRoot)
			cout << endl << "The tree has been destroyed!" << endl;
	}

	//Traversal
	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();

	//Insert
	void insertNode(const T& newData)
	{
		this->insertNode(this->mpRoot, newData);
	}

	//Delete
	void deleteNode(const T& key)
	{
		this->deleteNode(this->mpRoot, key);
	}

	//Depth Equal
	void DepthEqual()
	{
		this->DepthEqual(this->mpRoot);
	}

private:
	BSTNode<T>* mpRoot;

	/////////////////////////////// Private Functions \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//Destroy tree in postorder
	void destroyTree(BSTNode<T>*& pNode);
	
	//Traversal
	void inOrderTraversal(BSTNode<T>* pNode);
	void preOrderTraversal(BSTNode<T>* pNode);
	void postOrderTraversal(BSTNode<T>* pNode);

	//Insert
	void insertNode(BSTNode<T>*& pNode, const T& newData);
	//Delete
	void deleteNode(BSTNode<T>*& pNode, const T& key);

	//Depth Equal
	void DepthEqual(BSTNode<T>* pNode);
};



//Function Definitions


//Destroy tree in postorder
template <class T>
void BST<T>::destroyTree(BSTNode<T>*& pNode)
{
	if (pNode)
	{
		destroyTree(pNode->getLeftPtr());
		destroyTree(pNode->getRightPtr());
		//Process
		delete pNode;
		pNode = NULL;
	}
}



//Traversal
template <class T>
void BST<T>::inOrderTraversal()
{
	cout << "Traversal inOrder:" << endl;
	if (!this->mpRoot)
		cout << "The tree is empty!";
	else
		this->inOrderTraversal(this->mpRoot);
	cout << endl;
}

template <class T>
void BST<T>::inOrderTraversal(BSTNode<T>* pNode)
{
	if (pNode)
	{
		inOrderTraversal(pNode->getLeftPtr());
		cout << pNode->getData() << "  ";        //Process
		inOrderTraversal(pNode->getRightPtr());
	}
}

template <class T>
void BST<T>::preOrderTraversal()
{
	cout << "Traversal preOrder:" << endl;
	if (!this->mpRoot)
		cout << "The tree is empty!";
	else
		this->preOrderTraversal(this->mpRoot);
	cout << endl;
}

template <class T>
void BST<T>::preOrderTraversal(BSTNode<T>* pNode)
{
	if (pNode)
	{
		cout << pNode->getData() << "  ";        //Process
		preOrderTraversal(pNode->getLeftPtr());
		preOrderTraversal(pNode->getRightPtr());
	}
}

template <class T>
void BST<T>::postOrderTraversal()
{
	cout << "Traversal postOrder:" << endl;
	if (!this->mpRoot)
		cout << "The tree is empty!";
	else
		this->postOrderTraversal(this->mpRoot);
	cout << endl;
}

template <class T>
void BST<T>::postOrderTraversal(BSTNode<T>* pNode)
{
	if (pNode)
	{
		postOrderTraversal(pNode->getLeftPtr());
		postOrderTraversal(pNode->getRightPtr());
		cout << pNode->getData() << "  ";        //Process
	}
}



//Insert
template <class T>
void BST<T>::insertNode(BSTNode<T>*& pNode, const T& newData)
{
	if (!pNode)
		pNode = new BSTNode<T>(newData);

	else
	{
		if (pNode->getData() > newData)
			return insertNode(pNode->getLeftPtr(), newData);
		if (pNode->getData() < newData)
			return insertNode(pNode->getRightPtr(), newData);
	}
}


//Delete
template <class T>
void BST<T>::deleteNode(BSTNode<T>*& pNode, const T& key)
{
	if (!pNode)
		cout << "The key data does not EXIST in the Tree!" << endl;

	else
	{
		if (pNode->getData() > key)
			return deleteNode(pNode->getLeftPtr(), key);
		if (pNode->getData() < key)
			return deleteNode(pNode->getRightPtr(), key);

		// Case: pNode->getData() == key
		BSTNode<T>* pTemp = pNode;
		if (pNode->getLeftPtr() && !pNode->getRightPtr())
		{
			pNode = pNode->getLeftPtr();
			pTemp->setLeftPtr(NULL);
		}

		else if (!pNode->getLeftPtr() && pNode->getRightPtr())
		{
			pNode = pNode->getRightPtr();
			pTemp->setRightPtr(NULL);
		}

		else if (!pNode->getLeftPtr() && !pNode->getRightPtr())
			pNode = NULL;

		else if (pNode->getLeftPtr() && pNode->getRightPtr())
		{
			BSTNode<T>* succParent = pNode;
			BSTNode<T>* succ = pNode->getRightPtr();

			while (succ->getLeftPtr())
			{
				succParent = succ;
				succ = succ->getLeftPtr();
			}

			pNode->setData(succ->getData());
			if (succParent == pNode)
				succParent->setRightPtr(succ->getRightPtr());
			else
				succParent->setLeftPtr(succ->getRightPtr());

			succ->setRightPtr(NULL);
			pTemp = succ;
		}

		delete pTemp;
		pTemp = NULL;
	}
}


//Depth Equal
template <class T>
void BST<T>::DepthEqual(BSTNode<T>* pNode)
{
	if (!pNode)
		return;

	++CUR_DEPTH;
	if (pNode->getData() == CUR_DEPTH)
		cout << "The number " << pNode->getData() << " in depth " << CUR_DEPTH << endl;

	int temp = CUR_DEPTH;
	if (pNode->getData() > CUR_DEPTH)
		this->DepthEqual(pNode->getLeftPtr());

	CUR_DEPTH = temp;
	this->DepthEqual(pNode->getRightPtr());
}