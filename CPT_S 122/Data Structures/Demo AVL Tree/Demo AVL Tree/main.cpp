


#include"AVLTree.h"


int main()
{
	AVLTree* pTree = new AVLTree();

	cout << "The initial AVL tree: " << endl;

	cout << "Pre-order: ";
	pTree->prePrint();
	cout << endl;

	cout << "Post-order: ";
	pTree->postPrint();
	cout << endl;

	cout << "In-order: ";
	pTree->inorderPrint();
	cout << endl;

	//Insert 
	pTree->insert(10);



	//pTree->getRootPtr()->setHeight(h);
	//cout << pTree->getRootPtr() << endl;

	pTree->insert(50);
	pTree->insert(30);
	pTree->insert(60);
	pTree->insert(80);
	pTree->insert(40);
	pTree->insert(20);

	cout << "The AVL tree after insertions: " << endl;

	cout << "Pre-order: ";
	pTree->prePrint();
	cout << endl;

	cout << "Post-order: ";
	pTree->postPrint();
	cout << endl;

	cout << "In-order: ";
	pTree->inorderPrint();
	cout << endl;



	delete pTree;






	return 0;   //The program was successful
}