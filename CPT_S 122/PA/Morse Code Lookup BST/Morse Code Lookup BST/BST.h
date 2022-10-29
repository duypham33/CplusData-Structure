
/*

  This is the header file that stores standard library includes, #defined and function prototypes and definitions of BST Class

*/


#ifndef BST_H    //guard code

#define BST_H


#include <fstream>      //Neccessary to work with text files
#include <conio.h>      //Neccessary to use _getch() function
#include "BSTNode.h"



//This is a template class for BST tree
template <typename T1, typename T2>
class BST
{
public:
	//Constructor - open and read "MorseTable.txt" file, create nodes for each character in the tree, insert the nodes into the tree 
	BST();   

	//Destructor - This will call destroyTree() function to destroy all the nodes in the tree
	~BST();

	//Operations
	void insert(const T1& newSymbol, const T2& newMorseCode);  //Insert a node into the tree - calls private insert() function
	void print();    //Print the tree inorder(left most printed first) by calling the private print() function
	T2 search(T1& targetSymbol) const;    //Calls the private search() function to find a morse code matching with a symbol

	//This function runs the main application. First, print the tree to the screen, then convert the content of "Convert.txt" file into morse code to screen
	void MorseCodeConvertion();

private:
	BSTNode<T1, T2>* mpRoot;

	//////////////////////////////// Private Funtions \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	
	//This function deletes all the nodes in the tree in POSTORDER - left-right-root
	void destroyTree(BSTNode<T1, T2>* pTree);

	//This function inserts a node into the tree. Symbol is the key for comparision between nodes
	void insert(BSTNode<T1, T2>* pNode, const T1& newSymbol, const T2& newMorseCode);

	//Print the tree inorder(left most printed first) recursively
	void print(BSTNode<T1, T2>* pNode);

	//This function searchs a morse code matching with a given symbol by finding the node containing them in the BST
	T2 search(BSTNode<T1, T2>* pNode, T1& targetSymbol) const;

	//This function reads the content of the "Convert.txt" file, then look for each English character with a search ( ) function.
	//Then print the corresponding morse code to the screen.
	void convert();
};







//Member functions definitions

//Constructor - open and read "MorseTable.txt" file, create nodes for each character in the tree, insert the nodes into the tree 
template <typename T1, typename T2>
BST<T1, T2>::BST()
{
	std::ifstream fin;
	fin.open("MorseTable.txt");     //Open "MorseTable.txt" file

	if (fin.is_open())
	{
		//Read the file line by line until reaching the end of file
		while (!fin.eof())
		{
			T1 symbol;      //Used to read the symbol from the file
			T2 morseCode;   //Used to read the morse code from the file

			//Read the symbol
			fin >> symbol;
			fin.ignore(3);    //Ignore three white spaces between symbol and morse code
			//Read the morse code
			fin >> morseCode;

			//Insert the symbol and morse code into the tree
			this->insert(symbol, morseCode);     //Call the insert() function
		}
	}

	//Close the file
	fin.close();
}




//Destructor - This will call destroyTree() function to destroy all the nodes in the tree
template <typename T1, typename T2>
BST<T1, T2>::~BST()
{
	this->destroyTree(this->mpRoot);
}


//This function deletes all the nodes in the tree in POSTORDER - left-right-root
template <typename T1, typename T2>
void BST<T1, T2>::destroyTree(BSTNode<T1, T2>* pTree)
{
	if (!pTree)   //If the node is a null pointer, do nothing
		return;
	destroyTree(pTree->getLeftPtr());    //Go to left sub-tree
	destroyTree(pTree->getRightPtr());    //Go to right sub-tree
	//Process
	delete pTree;  
	pTree = NULL;
}






//Insert a node into the tree - calls private insert() function
template <typename T1, typename T2>
void BST<T1, T2>::insert(const T1& newSymbol, const T2& newMorseCode)
{
	this->insert(this->mpRoot, newSymbol, newMorseCode);
}



//This function inserts a node into the tree. Symbol is the key for comparision between nodes
template <typename T1, typename T2>
void BST<T1, T2>::insert(BSTNode<T1, T2>* pNode, const T1& newSymbol, const T2& newMorseCode)
{
	if (!pNode)   //The node is a null pointer, insert the new node here
		this->mpRoot = new BSTNode<T1, T2>(newSymbol, newMorseCode);

	else
	{
		if (pNode->getSymbol() > newSymbol)    //Go to the left sub-tree
		{
			if (!pNode->getLeftPtr())    //If the left child is null, insert at the left child
				pNode->setLeftPtr(new BSTNode<T1, T2>(newSymbol, newMorseCode));

			else   //Otherwise, call the function with the left child as the root node
				insert(pNode->getLeftPtr(), newSymbol, newMorseCode);
		}

		else if (pNode->getSymbol() < newSymbol)   //Go to the right sub-tree
		{
			if(!pNode->getRightPtr())    //If the right child is null, insert at the right child
				pNode->setRightPtr(new BSTNode<T1, T2>(newSymbol, newMorseCode));

			else   //Otherwise, call the function with the right child as the root node
				insert(pNode->getRightPtr(), newSymbol, newMorseCode);
		}

		// else   pNode->getSymbol() = newSymbol, do nothing
	}
}





//Print the tree inorder(left most printed first) by calling the private print() function
template <typename T1, typename T2>
void BST<T1, T2>::print() 
{
	if (!this->mpRoot)   //Check whether the tree is empty
		cout << "The tree is empty!" << endl;
	else
		this->print(this->mpRoot);
}



//Print the tree inorder(left most printed first) recursively
template <typename T1, typename T2>
void BST<T1, T2>::print(BSTNode<T1, T2>* pNode)
{
	if (pNode)
	{
		print(pNode->getLeftPtr());    //Print the left subtree
		//Process 
		cout << pNode->getSymbol() << "   " << pNode->getMorseCode() << endl;
		print(pNode->getRightPtr());    //Print the right subtree
	}
}




//Calls the private search() function to find a morse code matching with a symbol
template <typename T1, typename T2>
T2 BST<T1, T2>::search(T1& targetSymbol) const
{
	return this->search(this->mpRoot, targetSymbol);
}


//This function searchs a morse code matching with a given symbol by finding the node containing them in the BST
template <typename T1, typename T2>
T2 BST<T1, T2>::search(BSTNode<T1, T2>* pNode, T1& targetSymbol) const
{
	//Preprocessing: If the symbol is a lowercase English character, then convert it into uppercase
	if (targetSymbol >= 97 && targetSymbol <= 122)    //Lowwercase (based on ASCII table)
		targetSymbol -= 32;    //Convert into uppercase (based on ASCII table)

	//Serch the symbol from the tree
	if (pNode && pNode->getSymbol() == targetSymbol)   //The current node is the target node, so get the morse code from the node
		return pNode->getMorseCode();
	if (pNode && pNode->getSymbol() > targetSymbol)    //If the target < Node's symbol, search from left subtree
		return search(pNode->getLeftPtr(), targetSymbol);
	
	//Else, search from right subtree
	return search(pNode->getRightPtr(), targetSymbol);
}



//This function reads the content of the "Convert.txt" file, then look for each English character with a search ( ) function.
//Then print the corresponding morse code to the screen.
template <typename T1, typename T2>
void BST<T1, T2>::convert()
{
	std::ifstream fin;
	fin.open("Convert.txt");   //Open the file

	if (fin.is_open())
	{
		T1 temp;   //Used to read character
		//Read the file character by character until reaching the end of file
		while (fin.get(temp))    //Loop getting single characters. It can automatically check eof and stop the process 
		{
			if (temp == ' ')   //If it is a space, it means we got a complete string, so put three spaces to separate 
				cout << "   ";
			else if (temp == '\n')   //If meet the newline, display a newline
				cout << endl;

			else    //This includes English text and others like FULLSTOP '.'  Comma ','  or Query '?'
				cout << this->search(temp) << " ";
		}
	}

	//Close the file
	fin.close();
}



//This function runs the main application. First, print the tree to the screen, then convert the content of "Convert.txt" file into morse code to screen
template <typename T1, typename T2>
void BST<T1, T2>::MorseCodeConvertion()
{
	if (this->mpRoot)
		cout << "The content of the BST (Morse Table)" << endl;
	
	//Print the BST
	this->print();
	cout << endl << "***************************************************************************************************************" << endl;
	cout << "Please, hit ENTER key to convert the content of \"Convert.txt\" file into morse code, and print it out the screen!";
	_getch();
	cout << endl << endl;

	//Convert and display morse code to the screen
	this->convert();
}



#endif