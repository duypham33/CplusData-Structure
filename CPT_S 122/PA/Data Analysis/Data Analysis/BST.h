
/*

  This is the header file that stores standard library includes, #defined and function prototypes and definitions of TransactionNode Class

*/


#ifndef BST_H   //guard code

#define BST_H

#include "TransactionNode.h"


//This is a BST class. It is going to represent the products that were sold and the products that were bought
class BST
{
public:
	//Default constructor
	BST();

	//Destructor - calls destroyTree() private function to destroy the BST
	~BST();

	//Setter
	void setRootPtr(Node* const newRootPtr);
	//Getter
	Node*& getRootPtr();  //Returns a reference to the pointer

	//This calls the private insert function() to insert a new node into the BST
	void insert(const string& newData, const int& newUnits);

	//This function also calls the private inOrderTraversal function() to display the content of the tree inorder
	void inOrderTraversal();

	//This function finds the node with the smallest mUnits, and returns its reference.
	TransactionNode& findSmallest();
	//This function finds the node with the largest mUnits, and returns its reference.
	TransactionNode& findLargest();
private:
	//Data members
	Node* mpRoot;   //The pointer to the root node of the BST

	/////////////////////////////////// Private Functions \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//This function visits each node in postOrder to delete them
	void destroyTree(Node* pTree);
	//This function is passed a reference to a Node pointer, then inserts a new TransactionNode into the BST based on mUnits
	void insert(Node*& pTree, const string& newData, const int& newUnits);
	//This function recursively visits and prints the contents (mData and mUnits) of each node in the tree in order;
	//each node’s printData () is called, and the contents is printed on a separate line.
	void inOrderTraversal(Node* pTree);
};


#endif