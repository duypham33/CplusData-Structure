

#include "RedBlackTree.h"


int main(void)
{
	//Initializes an empty Red Black Tree
	RedBlackTree<int>* pRBTree = new RedBlackTree<int>();

	pRBTree->inOrderTraversal();
	cout << endl;

	pRBTree->insertNode(30);
	pRBTree->inOrderTraversal();
	pRBTree->preOrderTraversal();
	pRBTree->postOrderTraversal();
	cout << endl;

	pRBTree->insertNode(15);
	pRBTree->inOrderTraversal();
	pRBTree->preOrderTraversal();
	pRBTree->postOrderTraversal();
	cout << endl;

	pRBTree->insertNode(22);
	pRBTree->inOrderTraversal();
	pRBTree->preOrderTraversal();
	pRBTree->postOrderTraversal();
	cout << endl;

	pRBTree->insertNode(3);
	pRBTree->inOrderTraversal();
	pRBTree->preOrderTraversal();
	pRBTree->postOrderTraversal();
	cout << endl;

	pRBTree->insertNode(41);
	pRBTree->inOrderTraversal();
	pRBTree->preOrderTraversal();
	pRBTree->postOrderTraversal();
	cout << endl;

	pRBTree->insertNode(10);
	pRBTree->inOrderTraversal();
	pRBTree->preOrderTraversal();
	pRBTree->postOrderTraversal();
	cout << endl;

	pRBTree->insertNode(54);
	pRBTree->inOrderTraversal();
	pRBTree->preOrderTraversal();
	pRBTree->postOrderTraversal();
	cout << endl;

	pRBTree->insertNode(7);
	pRBTree->inOrderTraversal();
	pRBTree->preOrderTraversal();
	pRBTree->postOrderTraversal();
	cout << endl;

	pRBTree->insertNode(60);
	pRBTree->inOrderTraversal();
	pRBTree->preOrderTraversal();
	pRBTree->postOrderTraversal();
	cout << endl;

	pRBTree->insertNode(1);
	pRBTree->insertNode(6);
	pRBTree->inOrderTraversal();
	pRBTree->preOrderTraversal();
	pRBTree->postOrderTraversal();
	cout << endl;

	//Free up the space
	delete pRBTree;
	pRBTree = NULL;

	return 0;     //The program was successful
}