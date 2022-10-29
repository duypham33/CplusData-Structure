
#include "BST.h"
#include <fstream>
#include "MergeSort.h"

using std::ifstream;

//Functions
vector<string> loadArr(ifstream& fin);

template <typename T>
void arr_to_BST(vector<T> arr, BST<T>* pBstTree);

template <typename T>
ostream& operator <<(ostream& lhs, vector<T>& arr);


int main(void)
{
	//ifstream fin;
	//fin.open("NameList.txt", std::ios::in);

	////Load names from file into array
	//vector<string> arr;
	//if (fin.is_open())
	//	arr = loadArr(fin);
	//else
	//	cout << "Not successful to open the file!" << endl;
	//fin.close();
	//
	////Place names from array to BST
	//BST<int>* pBstTree = new BST<int>;
	////BST<int> BstTree = BST<int>();
	//vector<int> iArr = { 5, 6, 11, 1, 3, 9, 4 };
	//cout << iArr;

	//arr_to_BST(iArr, pBstTree);
	//cout << "Inorder: " << endl;
	//pBstTree->inOrderTraversal();

	//iArr = pBstTree->inorder();
	//cout << iArr;
	//cout << endl;
	//cout << "The kth largest number: " << pBstTree->KthLargest(1) << endl;

	//delete pBstTree;

	BST<int>* pBstTree = new BST<int>;
	pBstTree->insertNode(5);
	pBstTree->insertNode(7);
	pBstTree->inOrderTraversal();
	pBstTree->deleteNode(7);
	pBstTree->inOrderTraversal();

	vector<int> arr = { 13,11,32,42,26,5,0,1,2,3,7,6,9 };
	cout << "The original array:     " << arr;

	Sort<int> sortingMachine;
	sortingMachine.mergeSort(arr);
	cout << "The merge sorted array: " << arr;


	delete pBstTree;

	

	return 0;    //The program was successful
}




vector<string> loadArr(ifstream& fin)
{
	vector<string> arr;
	if (fin.eof())
		cout << "The file is empty!" << endl;
	else
	{
		string line;
		std::getline(fin, line);   //Read the header line
		while (!fin.eof())
		{
			std::getline(fin, line);

			if(line.size() > 0)     //Check whether it is a blank line
				arr.push_back(line);
		}
	}

	return arr;
}




template <typename T>
void arr_to_BST(vector<T> arr, BST<T>* pBstTree)
{
	if (arr.size() > 0)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			pBstTree->insertNode(arr[i]);
		}
	}
}


template <typename T>
ostream& operator <<(ostream& lhs, vector<T>& arr)
{
	int size = arr.size();
	if (size < 1)
		cout << "The array is empty!" << endl;

	else
	{
		for (int i = 0; i < arr.size(); i++)
		{
			lhs << arr[i] << "  ";
		}
		lhs << endl;
	}
	
	return lhs;
}