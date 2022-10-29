

#include "AVLTree.h"



int max(int a, int b)
{
	return (a > b ? a : b);
}







AVLNode* AVLTree::insert(AVLNode* node, int newData)
{
	if (node == NULL)
	{
		node = new AVLNode(newData);
	}

	else if (newData < node->data)
	{
		/*if (node->pLeft == NULL)
		{
			node->pLeft = new AVLNode(newData);
		}

		else
		{*/
		node->pLeft = insert(node->pLeft, newData);
		//}
	}

	else if (newData > node->data)
	{
		/*if (node->pRight == NULL)
		{
			node->pRight = new AVLNode(newData);
		}

		else
		{*/
		node->pRight = insert(node->pRight, newData);
		//}
	}

	//Update height of nodes
	node->height = max(nodeHeight(node->pLeft), nodeHeight(node->pRight)) + 1;


	//Balance tree 
	if (BF(node) == 2 && BF(node->pLeft) >= 0)         //Case 1 (Left-Left)
	{
		node = rotateRight(node);
	}
	else if (BF(node) == 2 && BF(node->pLeft) < 0)     //Case 2 (Left-Right)
	{
		node->pLeft = rotateLeft(node->pLeft);
		node = rotateRight(node);
	}
	else if (BF(node) == -2 && BF(node->pRight) > 0)   //Case 3 (Right-Left)
	{
		node->pRight = rotateRight(node->pRight);
		node = rotateLeft(node);
	}

	else if (BF(node) == -2 && BF(node->pRight) <= 0)  //Case 4 (Right-Right)
	{
		node = rotateLeft(node);
	}

	return node;
}
