

#include "BSTNode.h"
#include <vector>
using std::vector;

template <typename T>
class BST
{
public:
	//Constructor
	BST()
	{
		this->mpRoot = NULL;
	}

	//Destructor
	~BST()
	{
		this->destroyTree(this->mpRoot);
		cout << "Destructor has been invoked! Tree has been destroyed!" << endl;
	}

	bool isEmpty();
	//Insert
	void insertNode(const T& newData);

	//Delete 
	void deleteNode(const T& key);

	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();

	vector<T> inorder();

	T KthLargest(int k);

private:
	BSTNode<T>* mpRoot;

	void destroyTree(BSTNode<T>* pNode);
	//Insert
	void insertNode(BSTNode<T>* pNode, const T& newData);

	//Delete Node
	void deleteNode(BSTNode<T>* pNode, const T& key);

	void inOrderTraversal(BSTNode<T>* pNode);
	void preOrderTraversal(BSTNode<T>* pNode);
	void postOrderTraversal(BSTNode<T>* pNode);

	void inorder(BSTNode<T>* pNode, vector<T>& arr);
	T KthLargest(BSTNode<T>* pNode, int k);
};


template <typename T>
bool BST<T>::isEmpty()
{
	return (!this->mpRoot);
}


template <typename T>
void BST<T>::destroyTree(BSTNode<T>* pNode)
{
	if (!pNode)
		return;
	destroyTree(pNode->getLeftPtr());
	destroyTree(pNode->getRightPtr());
	delete pNode;
	pNode = NULL;
}



template <typename T>
void BST<T>::insertNode(const T& newData)
{
	this->insertNode(this->mpRoot, newData);
}



template <typename T>
void BST<T>::insertNode(BSTNode<T>* pNode, const T& newData)
{
	if (!pNode)
		this->mpRoot = new BSTNode<T>(newData);

	else
	{
		if (pNode->getData() != newData)
			pNode->increaseCounter();

		if (pNode->getData() > newData)
		{
			if (!pNode->getLeftPtr())
				pNode->setLeftPtr(new BSTNode<T>(newData));

			else
				insertNode(pNode->getLeftPtr(), newData);
		}

		else if (pNode->getData() < newData)
		{
			if (!pNode->getRightPtr())
				pNode->setRightPtr(new BSTNode<T>(newData));

			else
				insertNode(pNode->getRightPtr(), newData);
		}
	}
}



template <typename T>
void BST<T>::deleteNode(const T& key)
{
	this->deleteNode(this->mpRoot, key);
}


//Delete Node
template <typename T>
void BST<T>::deleteNode(BSTNode<T>* pNode, const T& key)
{
	if (!pNode)
		return;
	if (pNode->getData() > key)
		deleteNode(pNode->getLeftPtr(), key);
	else if (pNode->getData() < key)
		deleteNode(pNode->getRightPtr(), key);
	else   //This node is the target node to delete
	{
		//Case1: This node has no children (a leaf)
		if (!pNode->getLeftPtr() && !pNode->getRightPtr())
		{
			delete pNode;
			pNode = NULL;
			/*if (pNode == this->mpRoot)
			{
				delete this->mpRoot;
				this->mpRoot = NULL;
			}
			else
			{
				delete pNode;
				pNode = NULL;
			}*/
		}

		//Case2: This node has only one child
		else if (!pNode->getLeftPtr() && pNode->getRightPtr())
		{
			BSTNode<T>* pTemp = pNode;
			pNode = pNode->getLeftPtr();
			delete pTemp;
			pTemp = NULL;
		}
		else if (pNode->getLeftPtr() && !pNode->getRightPtr())
		{
			BSTNode<T>* pTemp = pNode;
			pNode = pNode->getRightPtr();
			delete pTemp;
			pTemp = NULL;
		}

		//Case3: This node has two children
		else
		{
			//Find inorder-successor of this node
			BSTNode<T>* pSucc = pNode->getRightPtr();
			BSTNode<T>* pSuccParent = pNode;

			while (pSucc->getLeftPtr())
			{
				pSuccParent = pSucc;
				pSucc = pSucc->getLeftPtr();
			}

			//Get value of successor node
			pNode->setData(pSucc->getData());
			//Delete successor
			if (pSuccParent == pNode)
				pSuccParent->setRightPtr(pSucc->getRightPtr());
			else
				pSuccParent->setLeftPtr(pSucc->getRightPtr());

			delete pSucc;
			pSucc = NULL;
		}
	}
}






template <typename T>
void BST<T>::inOrderTraversal()
{
	if (!this->mpRoot)
		cout << "The tree is empty!" << endl;
	else
		this->inOrderTraversal(this->mpRoot);
}



template <typename T>
void BST<T>::preOrderTraversal()
{
	if (!this->mpRoot)
		cout << "The tree is empty!" << endl;
	else
		this->preOrderTraversal(this->mpRoot);
}



template <typename T>
void BST<T>::postOrderTraversal()
{
	if (!this->mpRoot)
		cout << "The tree is empty!" << endl;
	else
		this->postOrderTraversal(this->mpRoot);
}



template <typename T>
void BST<T>::inOrderTraversal(BSTNode<T>* pNode)
{
	if (!pNode)
		return;
	inOrderTraversal(pNode->getLeftPtr());   //Left subtree
	cout << pNode;       //Process
	inOrderTraversal(pNode->getRightPtr());  //Right subtree
}

template <typename T>
void BST<T>::preOrderTraversal(BSTNode<T>* pNode)
{
	if (!pNode)
		return;
	cout << pNode;   //Process
	preOrderTraversal(pNode->getLeftPtr());   //Left subtree
	preOrderTraversal(pNode->getRightPtr());  //Right subtree
}


template <typename T>
void BST<T>::postOrderTraversal(BSTNode<T>* pNode)
{
	if (!pNode)
		return;
	postOrderTraversal(pNode->getLeftPtr());   //Left subtree
	postOrderTraversal(pNode->getRightPtr());  //Right subtree
	cout << pNode;   //Process
}



template <typename T>
vector<T> BST<T>::inorder()
{
	vector<T> arr;
	this->inorder(this->mpRoot, arr);
	return arr;
}


template <typename T>
void BST<T>::inorder(BSTNode<T>* pNode, vector<T>& arr)
{
	if (!pNode)
		return;
	inorder(pNode->getLeftPtr(), arr);
	arr.push_back(pNode->getData());
	inorder(pNode->getRightPtr(), arr);
}


template <typename T>
T BST<T>::KthLargest(int k)
{
	if (k > this->mpRoot->getCounter())
		cout << "k exceeds the size!" << endl;
	else
		return this->KthLargest(this->mpRoot, k);
	return -1;
}

template <typename T>
T BST<T>::KthLargest(BSTNode<T>* pNode, int k)
{
	if (!pNode->getRightPtr())
	{
		if (k == 1 || !pNode->getLeftPtr())
			return pNode->getData();
		return KthLargest(pNode->getLeftPtr(), k - 1);
	}
	else
	{
		int rCount = pNode->getRightPtr()->getCounter();
		if(rCount >= k)
			return KthLargest(pNode->getRightPtr(), k);
		if(k == rCount + 1)
			return pNode->getData();
		else
			return KthLargest(pNode->getLeftPtr(), k - rCount - 1);
	}
}