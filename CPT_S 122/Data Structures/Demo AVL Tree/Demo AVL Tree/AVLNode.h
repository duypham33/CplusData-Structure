



#include <iostream>

using std::cout;
using std::endl;



class AVLNode
{
public:
	int data;
	AVLNode* pLeft;
	AVLNode* pRight;
	int height;

	AVLNode(const int& newData = 0)
	{
		this->data = newData;
		pLeft = NULL;
		pRight = NULL;
		height = 0;
	}
};


