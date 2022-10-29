
#include "header.h"




int findMaxConsecutiveOnes(std::vector<int>& nums)
{
	int max = 0;
	int csctLength = 0;

	for(int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 1)
		{
			++csctLength;

			if ((i + 1 == nums.size() || nums[i + 1] == 0) && max < csctLength)
			{
				max = csctLength;
			}
		}

		else
		{
			csctLength = 0;  //Reset
		}
	}

	return max;
}


int findNumbers(std::vector<int>& nums)
{
	int count = 0;
	int digits = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		digits = 0;

		int n = abs(nums[i]);
		do
		{
			digits++;
			n /= 10;
		} while(n > 0);

		if (digits % 2 == 0)
			count++;
	}

	return count;
}


std::vector<int> sortedSquares(std::vector<int>& nums)
{
	int size = nums.size();     //Because it takes O(n), should call once
	std::vector<int> squareArr;
	squareArr.assign(size, 0);   //Fill the array with 0s 'size' times
	int index = size - 1;

	int left = 0, right = size - 1;
	while (left <= right)
	{
		int leftSquare = nums[left]*nums[left], rightSquare = nums[right]*nums[right];
		if (leftSquare >= rightSquare)
		{
			squareArr[index] = leftSquare;
			left++;
		}
			
		else
		{
			squareArr[index] = rightSquare;
			right--;
		}

		index--;
	}

	return squareArr;
}


void printList(Node* pHead)
{
	Node* pCur = pHead;
	if (pHead != NULL)
	{
		while (pCur != NULL)
		{
			cout << pCur->val;
			pCur = pCur->pNext;
			if (pCur != NULL)
				cout << " --> ";
			else
				cout << endl;
		}
	}

	else
	{
		cout << "The list is empty!" << endl;
	}
}




Node* reverseList(Node* pHead)
{
	Node* pPrev = NULL;
	Node* pCur = pHead;

	while (pCur != NULL)
	{
		Node* pTemp = pCur;
		pCur = pCur->pNext;
		pTemp->pNext = pPrev;
		pPrev = pTemp;
	}

	return pPrev;
}


