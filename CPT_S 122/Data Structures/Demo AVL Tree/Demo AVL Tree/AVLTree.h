

#include "AVLNode.h"




int max(int a, int b);


class AVLTree
{
public:
	AVLNode* pRoot;

	AVLTree()
	{
		pRoot = NULL;
	}

	int nodeHeight(AVLNode* node)
	{
		return (node == NULL ? -1 : node->height);
	}

	int BF(AVLNode* node)
	{
		return (nodeHeight(node->pLeft) - nodeHeight(node->pRight));
	}

	AVLNode* rotateRight(AVLNode* node)
	{
		AVLNode* p = node->pLeft;

		node->pLeft = p->pRight;
		p->pRight = node;

		//Update heights
		node->height = max(nodeHeight(node->pLeft), nodeHeight(node->pRight)) + 1;
		p->height = max(nodeHeight(p->pLeft), nodeHeight(p->pRight)) + 1;

		return p;
	}

	AVLNode* rotateLeft(AVLNode* node)
	{
		AVLNode* p = node->pRight;

		node->pRight = p->pLeft;
		p->pLeft = node;

		//Update heights
		node->height = max(nodeHeight(node->pLeft), nodeHeight(node->pRight)) + 1;
		p->height = max(nodeHeight(p->pLeft), nodeHeight(p->pRight)) + 1;

		return p;
	}

	AVLNode* insert(AVLNode* node, int newData);

	void insert(int newData)
	{
		pRoot = insert(pRoot, newData);
	}


	void prePrint(AVLNode* node)
	{
		if (node != NULL)
		{
			cout << node->data << "  ";
			prePrint(node->pLeft);
			prePrint(node->pRight);
		}
	}

	void prePrint()      //Pre-oder: node-left-right
	{
		if (pRoot == NULL)
		{
			cout << "The tree is empty!" << endl;
		}

		else
		{
			prePrint(pRoot);
		}
	}



	void postPrint(AVLNode* node)
	{
		if (node != NULL)
		{
			postPrint(node->pLeft);
			postPrint(node->pRight);
			cout << node->data << "  ";
		}
	}

	void postPrint()     //Post-order: left-right-node
	{
		if (pRoot == NULL)
		{
			cout << "The tree is empty!" << endl;
		}

		else
		{
			postPrint(pRoot);
		}
	}

	void inorderPrint(AVLNode* node)
	{
		if (node != NULL)
		{
			inorderPrint(node->pLeft);
			cout << node->data << "  ";
			inorderPrint(node->pRight);
		}
	}

	void inorderPrint()   //In-order: left-node-right
	{
		if (pRoot == NULL)
		{
			cout << "The tree is empty!" << endl;
		}

		else
		{
			inorderPrint(pRoot);
		}
	}

};

