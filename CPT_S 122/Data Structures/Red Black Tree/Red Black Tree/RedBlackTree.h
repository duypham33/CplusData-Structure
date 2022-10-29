#pragma once


#include "RBNode.h"


// Implement Red Black Tree
template <class T>
class RedBlackTree
{
public:
	//Default Constructor
	RedBlackTree()
	{
		//Initializes an empty Red Black Tree
		this->mpRoot = NULL;
	}

	//Destructor
	~RedBlackTree()
	{
		this->destroyTree(this->mpRoot);
		if (!this->mpRoot)
			cout << "The Red Black Tree has been destroyed!" << endl;
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

private:
	RBNode<T>* mpRoot;   //The root of the tree

	///////////////////////////// Private Functions \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//Destroy the tree in postorder
	void destroyTree(RBNode<T>*& pNode);

	//Traversal
	void inOrderTraversal(RBNode<T>* pNode);
	void preOrderTraversal(RBNode<T>* pNode);
	void postOrderTraversal(RBNode<T>* pNode);

	//Rotations
	RBNode<T>* rotateRight(RBNode<T>* pNode);   //Singly rotate in case Left Left
	RBNode<T>* rotateLeft(RBNode<T>* pNode);    //Singly rotate in case Right Right

	//Insert
	void insertNode(RBNode<T>*& pNode, const T& newData);
	RBNode<T>* reStruct(RBNode<T>* pNode, const bool& leftSide);
};





//Function Definitions

//Destroy tree in postorder
template <class T>
void RedBlackTree<T>::destroyTree(RBNode<T>*& pNode)
{
	if (pNode)
	{
		destroyTree(pNode->getLeftPtr());
		destroyTree(pNode->getRightPtr());
		//Process
		pNode->setParentPtr(NULL);   //Set parent pointer to NULL before delete, to avoid delete the real parent node, which may raise error.
		delete pNode;
		pNode = NULL;
	}
}



//Traversal
template <class T>
void RedBlackTree<T>::inOrderTraversal()
{
	cout << "Traversal inOrder:" << endl;
	if (!this->mpRoot)
		cout << "The Red Black Tree is empty!";
	else
		this->inOrderTraversal(this->mpRoot);
	cout << endl;
}

template <class T>
void RedBlackTree<T>::inOrderTraversal(RBNode<T>* pNode)
{
	if (pNode)
	{
		inOrderTraversal(pNode->getLeftPtr());
		cout << pNode->getData() << " : " << ((pNode->getColor() == 'r') ? "Red   " : "Black   ");     //Process
		inOrderTraversal(pNode->getRightPtr());
	}
}

template <class T>
void RedBlackTree<T>::preOrderTraversal()
{
	cout << "Traversal preOrder:" << endl;
	if (!this->mpRoot)
		cout << "The Red Black Tree is empty!";
	else
		this->preOrderTraversal(this->mpRoot);
	cout << endl;
}

template <class T>
void RedBlackTree<T>::preOrderTraversal(RBNode<T>* pNode)
{
	if (pNode)
	{
		cout << pNode->getData() << "  ";        //Process
		preOrderTraversal(pNode->getLeftPtr());
		preOrderTraversal(pNode->getRightPtr());
	}
}

template <class T>
void RedBlackTree<T>::postOrderTraversal()
{
	cout << "Traversal postOrder:" << endl;
	if (!this->mpRoot)
		cout << "The Red Black Tree is empty!";
	else
		this->postOrderTraversal(this->mpRoot);
	cout << endl;
}

template <class T>
void RedBlackTree<T>::postOrderTraversal(RBNode<T>* pNode)
{
	if (pNode)
	{
		postOrderTraversal(pNode->getLeftPtr());
		postOrderTraversal(pNode->getRightPtr());
		cout << pNode->getData() << "  ";        //Process
	}
}


//Rotations
template <class T>
RBNode<T>* RedBlackTree<T>::rotateRight(RBNode<T>* pNode)    //Singly rotate in case Left Left
{
	RBNode<T>* pTemp = pNode->getLeftPtr();
	pNode->setLeftPtr(pTemp->getRightPtr());
	if (pTemp->getRightPtr())
		pTemp->getRightPtr()->setParentPtr(pNode);
	pTemp->setParentPtr(pNode->getParentPtr());
	if (!pNode->getParentPtr())
		this->mpRoot = pTemp;
	else if (pNode->getParentPtr()->getLeftPtr() == pNode)
		pNode->getParentPtr()->setLeftPtr(pTemp);
	else
		pNode->getParentPtr()->setRightPtr(pTemp);
	pTemp->setRightPtr(pNode);
	pNode->setParentPtr(pTemp);

	return pTemp;
}


template <class T>
RBNode<T>* RedBlackTree<T>::rotateLeft(RBNode<T>* pNode)     //Singly rotate in case Right Right
{
	RBNode<T>* pTemp = pNode->getRightPtr();
	pNode->setRightPtr(pTemp->getLeftPtr());
	if (pTemp->getLeftPtr())
		pTemp->getLeftPtr()->setParentPtr(pNode);
	pTemp->setParentPtr(pNode->getParentPtr());
	if (!pNode->getParentPtr())
		this->mpRoot = pTemp;
	else if (pNode->getParentPtr()->getLeftPtr() == pNode)
		pNode->getParentPtr()->setLeftPtr(pTemp);
	else
		pNode->getParentPtr()->setRightPtr(pTemp);
	pTemp->setLeftPtr(pNode);
	pNode->setParentPtr(pTemp);

	return pTemp;
}




//Insert
template <class T>
void RedBlackTree<T>::insertNode(RBNode<T>*& pNode, const T& newData)
{
	if (!pNode)
		pNode = new RBNode<T>(newData, 'b');   //Insert node as the root

	else
	{
		bool leftSide = false;

		if (pNode->getData() > newData)
		{
			leftSide = true;
			if (!pNode->getLeftPtr())
				pNode->setLeftPtr(new RBNode<T>(newData, 'r', pNode));
			else
				insertNode(pNode->getLeftPtr(), newData);
		}

		else if (pNode->getData() < newData)
		{
			if (!pNode->getRightPtr())
				pNode->setRightPtr(new RBNode<T>(newData, 'r', pNode));
			else
				insertNode(pNode->getRightPtr(), newData);
		}

		// Re-struct the tree (rotate or/and recolor) to keep the conditions satisfied
		reStruct(pNode, leftSide);
	}
}

template <class T>
RBNode<T>* RedBlackTree<T>::reStruct(RBNode<T>* pNode, const bool& leftSide)
{
	if (pNode->getColor() == 'b')
		return pNode;

	if (leftSide)  // Consider the left child 
	{
		if (!pNode->getLeftPtr() || pNode->getLeftPtr()->getColor() == 'b')
			return pNode;

		// NOTE: In this case, the parent node is not NULL (Because the node is RED)
		bool leftChild = (pNode->getParentPtr()->getLeftPtr() == pNode) ? true : false;
		//Check sibling pointer
		if (leftChild)
		{
			if (!pNode->getParentPtr()->getRightPtr() || pNode->getParentPtr()->getRightPtr()->getColor() == 'b')
			{
				//Singly right rotate at the parent node, and change color of the node and the parent
				pNode->reColor();
				pNode->getParentPtr()->reColor();
				pNode = rotateRight(pNode->getParentPtr());
			}

			else  //The sibling color is red
			{
				//Recolor the parent and the two children
				pNode->reColor();
				pNode->getParentPtr()->reColor();
				pNode->getParentPtr()->getRightPtr()->reColor();

				if(pNode->getParentPtr() == this->mpRoot)
					pNode->getParentPtr()->reColor();
			}
		}
		
		else  // The node is the right child
		{
			if (!pNode->getParentPtr()->getLeftPtr() || pNode->getParentPtr()->getLeftPtr()->getColor() == 'b')
			{
				pNode = rotateRight(pNode);
				pNode->reColor();
				pNode->getParentPtr()->reColor();
				pNode = rotateLeft(pNode->getParentPtr());
			}

			else  //The sibling color is red
			{
				//Recolor the parent and the two children
				pNode->reColor();
				pNode->getParentPtr()->reColor();
				pNode->getParentPtr()->getLeftPtr()->reColor();

				if (pNode->getParentPtr() == this->mpRoot)
					pNode->getParentPtr()->reColor();
			}
		}
	}


	else   // Consider the right child 
	{
		if (!pNode->getRightPtr() || pNode->getRightPtr()->getColor() == 'b')
			return pNode;

		// NOTE: In this case, the parent node is not NULL (Because the node is RED)
		bool rightChild = (pNode->getParentPtr()->getRightPtr() == pNode) ? true : false;
		//Check sibling pointer
		if (rightChild)
		{
			if (!pNode->getParentPtr()->getLeftPtr() || pNode->getParentPtr()->getLeftPtr()->getColor() == 'b')
			{
				//Singly left rotate at the parent node, and change color of the node and the parent
				pNode->reColor();
				pNode->getParentPtr()->reColor();
				pNode = rotateLeft(pNode->getParentPtr());
			}

			else  //The sibling color is red
			{
				//Recolor the parent and the two children
				pNode->reColor();
				pNode->getParentPtr()->reColor();
				pNode->getParentPtr()->getLeftPtr()->reColor();

				if (pNode->getParentPtr() == this->mpRoot)
					pNode->getParentPtr()->reColor();
			}
		}

		else  // The node is the left child
		{
			if (!pNode->getParentPtr()->getRightPtr() || pNode->getParentPtr()->getRightPtr()->getColor() == 'b')
			{
				pNode = rotateLeft(pNode);
				pNode->reColor();
				pNode->getParentPtr()->reColor();
				return rotateRight(pNode->getParentPtr());
			}

			else  //The sibling color is red
			{
				//Recolor the parent and the two children
				pNode->reColor();
				pNode->getParentPtr()->reColor();
				pNode->getParentPtr()->getRightPtr()->reColor();

				if (pNode->getParentPtr() == this->mpRoot)
					pNode->getParentPtr()->reColor();
			}
		}
	}

	return pNode;
}