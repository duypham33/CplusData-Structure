


#include"AVLTree.h"


int main()
{
	//Initializes an empty AVL Tree
	AVLTree<int>* pTree = new AVLTree<int>();

	pTree->inOrderTraversal();
	cout << endl;

	pTree->insertNode(1);
	pTree->insertNode(5);
	pTree->insertNode(3);
	pTree->insertNode(10);
	pTree->insertNode(8);
	pTree->insertNode(4);
	pTree->insertNode(2);
	pTree->insertNode(6);
	pTree->insertNode(9);
	pTree->insertNode(7);
	pTree->insertNode(12);
	pTree->insertNode(11);
	pTree->inOrderTraversal();
	pTree->preOrderTraversal();
	pTree->postOrderTraversal();
	cout << endl;


	pTree->deleteNode(5);
	pTree->deleteNode(6);
	pTree->inOrderTraversal();
	pTree->preOrderTraversal();
	pTree->postOrderTraversal();
	cout << endl;

	//Free up the space
	delete pTree;
	pTree = NULL;

	return 0;   //The program was successful
}