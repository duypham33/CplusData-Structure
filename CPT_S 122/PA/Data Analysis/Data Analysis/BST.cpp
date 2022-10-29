
/*

    This file is to establish the definitions for all programmer-defined functions of BST Class, aside from main ()

*/

#include "BST.h"

//Function definitions

//Default constructor
BST::BST()
{
    this->mpRoot = NULL;   //Initializes an empty BST
}

//Destructor - calls destroyTree() private function to destroy the BST
BST::~BST()
{
    this->destroyTree(this->mpRoot);
}


//This function visits each node in postOrder to delete them
void BST::destroyTree(Node* pTree)
{
    if (!pTree)  //If the node is null, do nothing
        return;
    this->destroyTree(pTree->getLeftPtr());   //Visit left-subtree
    this->destroyTree(pTree->getRightPtr());  //Visit right-subtree
    delete pTree;   //Process
    pTree = nullptr;
}


//Setter
void BST::setRootPtr(Node* const newRootPtr)
{
    this->mpRoot = newRootPtr;
}
//Getter
Node*& BST::getRootPtr()   //Returns a reference to the pointer
{
    return this->mpRoot;
}


//This calls the private insert function() to insert a new node into the BST
void BST::insert(const string& newData, const int& newUnits)
{
    this->insert(this->mpRoot, newData, newUnits);
}


//This function is passed a reference to a Node pointer, then inserts a new TransactionNode into the BST based on mUnits
void BST::insert(Node*& pTree, const string& newData, const int& newUnits)
{
    if (!pTree)   //If the node is null, insert new node there
        this->mpRoot = new TransactionNode(newData, newUnits);

    else
    {
        //Down cast pTree to TransactionNode*, to get access mUnits for comparison with newUnits
        TransactionNode* pNode = (TransactionNode*)pTree;
        if (pNode->getUnits() > newUnits)    //Go to the left sub-tree
        {
            if (!pTree->getLeftPtr())    //If the left child is null, insert at the left child
                pTree->setLeftPtr(new TransactionNode(newData, newUnits));

            else   //Otherwise, call the function with the left child as the root node
                insert(pTree->getLeftPtr(), newData, newUnits);
        }

        else if (pNode->getUnits() < newUnits)    //Go to the right sub-tree
        {
            if (!pTree->getRightPtr())    //If the right child is null, insert at the right child
                pTree->setRightPtr(new TransactionNode(newData, newUnits));

            else   //Otherwise, call the function with the right child as the root node
                insert(pTree->getRightPtr(), newData, newUnits);
        }

        else   //pNode->getUnits() = newUnits, we check whether the mData is the same as newData or not
        {
            //If the product type is different from the new type, then inserts the new node between the current node and the right sub-tree
            if (pTree->getData() != newData)
            {
                TransactionNode* pMem = new TransactionNode(newData, newUnits);
                if (pMem)
                {
                    pMem->setRightPtr(pTree->getRightPtr());  //The new node right-points to the right sub-tree of the current node
                    pTree->setRightPtr(pMem);     //The current node right-points to the new node
                }
            }
        }
    }
}



//This function also calls the private inOrderTraversal function() to display the content of the tree inorder
void BST::inOrderTraversal()
{
    if (!this->mpRoot)
        cout << "The tree is empty!" << endl;
    else
        this->inOrderTraversal(this->mpRoot);
}



//This function recursively visits and prints the contents (mData and mUnits) of each node in the tree in order;
//each node’s printData () is called, and the contents is printed on a separate line.
void BST::inOrderTraversal(Node* pTree)
{
    if (!pTree)  //If the node is null, do nothing
        return;
    inOrderTraversal(pTree->getLeftPtr());   //Visit left sub-tree
    pTree->printData();     //Process
    inOrderTraversal(pTree->getRightPtr());   //Visit right sub-tree
}


//This function finds the node with the smallest mUnits, and returns its reference.
TransactionNode& BST::findSmallest()
{
    Node* pNode = this->mpRoot;
    //Go to the leftmost node, which is the node with smallest mUnits (property of BST)
    while (pNode->getLeftPtr())
    {
        pNode = pNode->getLeftPtr();
    }
    
    return *(TransactionNode*) pNode;  //Returns reference
}

//This function finds the node with the largest mUnits, and returns its reference.
TransactionNode& BST::findLargest()
{
    Node* pNode = this->mpRoot;
    //Go to the rightmost node, which is the node with largest mUnits (property of BST)
    while (pNode->getRightPtr())
    {
        pNode = pNode->getRightPtr();
    }

    return *(TransactionNode*)pNode;  //Returns reference
}