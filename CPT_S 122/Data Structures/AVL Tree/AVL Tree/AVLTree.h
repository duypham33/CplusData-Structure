#pragma once


#include "AVLNode.h"


template <class T>
class AVLTree
{
public:
	//Default Constructor
	AVLTree()
	{
		//Initializes an empty AVL tree
		this->mpRoot = NULL;
	}

	//Destructor
	~AVLTree()
	{
		this->destroyTree(this->mpRoot);
		if (!this->mpRoot)
			cout << "The AVL tree has been destroyed!" << endl;
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

private:
	AVLNode<T>* mpRoot;

	///////////////////////////// Private Functions \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//Destroy the tree in postorder
	void destroyTree(AVLNode<T>*& pNode);

	//Traversal
	void inOrderTraversal(AVLNode<T>* pNode);
	void preOrderTraversal(AVLNode<T>* pNode);
	void postOrderTraversal(AVLNode<T>* pNode);

	//Compute/Update heights of nodes
	int max(const int& a, const int& b);
	int nodeHeight(AVLNode<T>* pNode);
	void updateHeight(AVLNode<T>* pNode);  

	//Check balance of a node (Height of left child - height of right child)
	int balanceFactor(AVLNode<T>* pNode);
	void update(AVLNode<T>*& pNode);    //Update heights of nodes and balance the tree if needed

	//Rotations
	AVLNode<T>* rotateRight(AVLNode<T>*& pNode);   //Singly rotate in case Left Left
	AVLNode<T>* rotateLeft(AVLNode<T>*& pNode);    //Singly rotate in case Right Right

	//Insert
	void insertNode(AVLNode<T>*& pNode, const T& newData);
	//Delete
	void deleteNode(AVLNode<T>*& pNode, const T& key);
};



//Function Definitions

//Destroy tree in postorder
template <class T>
void AVLTree<T>::destroyTree(AVLNode<T>*& pNode)
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
void AVLTree<T>::inOrderTraversal()
{
	cout << "Traversal inOrder:" << endl;
	if (!this->mpRoot)
		cout << "The AVL tree is empty!";
	else
		this->inOrderTraversal(this->mpRoot);
	cout << endl;
}


template <class T>
void AVLTree<T>::inOrderTraversal(AVLNode<T>* pNode)
{
	if (pNode)
	{
		inOrderTraversal(pNode->getLeftPtr());
		cout << pNode->getData() << ": " << pNode->getHeight() << " in height,   ";     //Process
		inOrderTraversal(pNode->getRightPtr());
	}
}

template <class T>
void AVLTree<T>::preOrderTraversal()
{
	cout << "Traversal preOrder:" << endl;
	if (!this->mpRoot)
		cout << "The AVL tree is empty!";
	else
		this->preOrderTraversal(this->mpRoot);
	cout << endl;
}

template <class T>
void AVLTree<T>::preOrderTraversal(AVLNode<T>* pNode)
{
	if (pNode)
	{
		cout << pNode->getData() << "  ";        //Process
		preOrderTraversal(pNode->getLeftPtr());
		preOrderTraversal(pNode->getRightPtr());
	}
}

template <class T>
void AVLTree<T>::postOrderTraversal()
{
	cout << "Traversal postOrder:" << endl;
	if (!this->mpRoot)
		cout << "The AVL tree is empty!";
	else
		this->postOrderTraversal(this->mpRoot);
	cout << endl;
}

template <class T>
void AVLTree<T>::postOrderTraversal(AVLNode<T>* pNode)
{
	if (pNode)
	{
		postOrderTraversal(pNode->getLeftPtr());
		postOrderTraversal(pNode->getRightPtr());
		cout << pNode->getData() << "  ";        //Process
	}
}


//Compute height of a node
template <class T>
int AVLTree<T>::max(const int& a, const int& b)
{
	return (a > b) ? a : b;
}


template <class T>
int AVLTree<T>::nodeHeight(AVLNode<T>* pNode)
{
	return (pNode) ? (pNode->getHeight()) : -1;
}


template <class T>
void AVLTree<T>::updateHeight(AVLNode<T>* pNode)   
{
	if(pNode)
		pNode->setHeight(max(nodeHeight(pNode->getLeftPtr()), nodeHeight(pNode->getRightPtr())) + 1);
}



//Check balance of a node (Height of left child - height of right child)
template <class T>
int AVLTree<T>::balanceFactor(AVLNode<T>* pNode)
{
	return nodeHeight(pNode->getLeftPtr()) - nodeHeight(pNode->getRightPtr());
}

template <class T>
void AVLTree<T>::update(AVLNode<T>*& pNode)     //Update heights of nodes and balance the tree if needed
{
	//Update the heights of the nodes
	updateHeight(pNode);

	//Check the balance of the tree
	int BF = this->balanceFactor(pNode);
	// Left skew
	if (BF > 1)
	{
		//Case Left-Left: Singly right rotate  
		if (this->balanceFactor(pNode->getLeftPtr()) >= 0)
			pNode = this->rotateRight(pNode);
		else  //Case Left-Right: left rotate the left child, then right rotate the node  
		{
			pNode->getLeftPtr() = this->rotateLeft(pNode->getLeftPtr());
			pNode = this->rotateRight(pNode);
		}
	}

	// Right skew
	else if (BF < -1)
	{
		//Case Right-Right: Singly left rotate  
		if (this->balanceFactor(pNode->getRightPtr()) <= 0)
			pNode = this->rotateLeft(pNode);
		else  //Case Right-Left: right rotate the left child, then left rotate the node  
		{
			pNode->getRightPtr() = this->rotateRight(pNode->getRightPtr());
			pNode = this->rotateLeft(pNode);
		}
	}
}


//Rotations
template <class T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T>*& pNode)    //Singly rotate in case Left Left
{
	AVLNode<T>* newRoot = pNode->getLeftPtr();
	AVLNode<T>* pTemp = pNode->getLeftPtr()->getRightPtr();
	pNode->getLeftPtr()->setRightPtr(pNode);
	pNode->setLeftPtr(pTemp);

	//Update heights
	int tempHeight = nodeHeight(pTemp);
	int rightHeight = max(tempHeight, nodeHeight(pNode->getRightPtr())) + 1;
	pNode->setHeight(rightHeight);
	newRoot->setHeight(max(nodeHeight(newRoot->getLeftPtr()), rightHeight) + 1);

	return newRoot;
}


template <class T>
AVLNode<T>* AVLTree<T>::rotateLeft(AVLNode<T>*& pNode)     //Singly rotate in case Right Right
{
	AVLNode<T>* newRoot = pNode->getRightPtr();
	AVLNode<T>* pTemp = pNode->getRightPtr()->getLeftPtr();
	pNode->getRightPtr()->setLeftPtr(pNode);
	pNode->setRightPtr(pTemp);

	//Update heights
	int tempHeight = nodeHeight(pTemp);
	int leftHeight = max(nodeHeight(pNode->getLeftPtr()), tempHeight) + 1;
	pNode->setHeight(leftHeight);
	newRoot->setHeight(max(leftHeight, nodeHeight(newRoot->getRightPtr())) + 1);

	return newRoot;
}





//Insert
template <class T>
void AVLTree<T>::insertNode(AVLNode<T>*& pNode, const T& newData)
{
	if (!pNode)
		pNode = new AVLNode<T>(newData);

	else
	{
		if (pNode->getData() > newData)
			insertNode(pNode->getLeftPtr(), newData);
		else if (pNode->getData() < newData)
			insertNode(pNode->getRightPtr(), newData);

		//Update heights of nodes and balance the tree if needed
		this->update(pNode);
	}
}



//Delete
template <class T>
void AVLTree<T>::deleteNode(AVLNode<T>*& pNode, const T& key)
{
	if (!pNode)
		cout << "The key data does not EXIST in the Tree!" << endl;

	else
	{
		if (pNode->getData() > key)
			deleteNode(pNode->getLeftPtr(), key);
		else if (pNode->getData() < key)
			deleteNode(pNode->getRightPtr(), key);

		else  // Case: pNode->getData() == key
		{
			if (pNode->getLeftPtr() && pNode->getRightPtr())
			{
				AVLNode<T>* succ = pNode->getRightPtr();

				while (succ->getLeftPtr())
				{
					succ = succ->getLeftPtr();
				}

				pNode->setData(succ->getData());
				
				//Apply for the right sub-tree
				deleteNode(pNode->getRightPtr(), succ->getData());
			}

			else
			{
				AVLNode<T>* pTemp = pNode;
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

				delete pTemp;
				pTemp = NULL;
			}
		}

		//Update heights of nodes and balance the tree if needed
		if(pNode)
			this->update(pNode);
	}
}