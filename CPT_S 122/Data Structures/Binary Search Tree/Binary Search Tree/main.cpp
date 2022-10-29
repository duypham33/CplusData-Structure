

#include "BST.h"


int main(void)
{
	//Initializes an empty BST
	BST<int>* pBST = new BST<int>();
	pBST->inOrderTraversal();
	
	pBST->insertNode(5);
	pBST->insertNode(3);
	pBST->insertNode(6);
	pBST->insertNode(4);
	pBST->insertNode(1);
	pBST->insertNode(8);
	pBST->insertNode(2);
	pBST->inOrderTraversal();
	pBST->preOrderTraversal();
	pBST->postOrderTraversal();
	cout << endl;

	pBST->deleteNode(3);
	pBST->inOrderTraversal();
	pBST->preOrderTraversal();
	pBST->postOrderTraversal();
	cout << endl;

	pBST->deleteNode(1);
	pBST->inOrderTraversal();
	pBST->preOrderTraversal();
	pBST->postOrderTraversal();
	cout << endl;

	pBST->deleteNode(9);
	pBST->inOrderTraversal();
	pBST->preOrderTraversal();
	pBST->postOrderTraversal();
	cout << endl;

	pBST->deleteNode(4);
	pBST->inOrderTraversal();
	pBST->preOrderTraversal();
	pBST->postOrderTraversal();
	cout << endl;

	pBST->deleteNode(8);
	pBST->inOrderTraversal();
	pBST->preOrderTraversal();
	pBST->postOrderTraversal();
	cout << endl;
	
	//Free up the space
	delete pBST;
	pBST = NULL;

	return 0;   //The program was successful
}