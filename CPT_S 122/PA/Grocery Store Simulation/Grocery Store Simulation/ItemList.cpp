
/*

	This file is to establish the definitions for all programmer-defined functions of ItemList Class, aside from main ()

*/


#include "ItemList.h"


// An array of 30 grocery items
string items[30] = { "cereal", "milk", "steak", "tuna", "salmon", "garlic", "knife", "onions", "butter", "eggs", "cheese",
	"sugar", "honey", "pasta", "rice", "vegetables", "soup", "seeds", "bread", "pork", "ham", "vinegar", "yogurt", "snack", "pizza",
	"beef", "chicken", "salt", "soap", "paper" };



//Function definitions

//Constructor - Initializes an empty list
ItemList::ItemList()
{
	this->mpHead = NULL;
	this->numberItems = 0;
}

//Destructor - call destroy() function
ItemList::~ItemList()
{
	destroy();  //Destroy the list
}

//Destroy List - private function
void ItemList::destroy()
{
	while (this->mpHead)   //Delete at front until the list is empty
	{
		Node* pFront = this->mpHead;
		this->mpHead = pFront->pNext;
		delete pFront;

		this->numberItems--;  //Decrement the number of items in the list
	}
}



//This function inserts a node at the head of the list. Returns true if the memory is allocated for the new node, false is otherwise.
bool ItemList::insertFront(const string& newItem)
{
	bool success = false;   //To check the memory is allocated successfully
	Node* pMem = new Node(newItem);    //Allocate space for the new node

	if (pMem)     //Check the memory is available
	{
		success = true;      //The memory is allocated
		pMem->pNext = this->mpHead;
		this->mpHead = pMem;   //Update the head pointer

		this->numberItems++;   //Increment the number of items in the list
	}

	return success;
}


//This function randomly generates a item list for a customer by randomly generating the total number of items first, then generating each item.
//We suppose that the number of items ranges from 1 to 20, for each customer.
void ItemList::generateList()
{
	//Randomly generate the total number of items first
	int totalItems = rand() % 20 + 1;   //Ranges from 1 to 20
	int n = totalItems;

	//Then we randomly pick n different items from the array of 30 items, which is the same as pick n different number indice of the array from 0 - 29 
	string strList = "";   //This string helps check duplicated indice
	while (n > 0)   //The loop stops when n == 0, which means we already have n different indice as well as n differant items in the list
	{
		int itemIndex = 0;   //Initialize the index used to generated
		do
		{
			itemIndex = rand() % 30;    // Index ranges from 0 - 29 (Because the items array has 30 string elements)
			if (strList.find(std::to_string(itemIndex)) == string::npos)   //If cannot find this generated index in the helper string, we have a valid index
				break;   //break the do-while loop, when we found a non-duplicated index 
		} while (true);  //The infinite loop until valid index has been generated

		//Typecast the new generated index into string type, and append it to the helper string with a comma to seperate n different indice
		strList += (std::to_string(itemIndex) + ",");   
		insertFront(items[itemIndex]);    //Insert the item corresponding to the generated index at the front of the linked list
		n--;     //Decrement n once a valid index has been generated
	}
}


//Getter: Get the total number of items generated, which helps compute the service time for the customer PROPORTIONALLY
int ItemList::getNumberItems() const
{
	return this->numberItems;
}




//This function displays the number of items and the shortcut of the list that the customer bought.
//If there are less than four items, it displays all the items. Otherwise it displays two first items and ... to the last item in the list 
void ItemList::printList()
{
	Node* pCur = this->mpHead;
	int n = this->numberItems;  //The number of items in the list
	cout << n;     //Print out the number of items
	if (n == 1)
		cout << " item (";   //If only one, no 's'
	else
		cout << " items (";  //More than one item, has 's'

	//Display the shortcut of the list
	int count = 0;
	while (pCur && ++count < 3)   //If there are less than four items, it displays all the items
	{
		cout << pCur->item;
		pCur = pCur->pNext;
		if (pCur && n == 3 && count == 2)   //If there are exactly 3 items, display the third item as well
			cout << " --> " << pCur->item;
		else if (pCur)          
			cout << " --> ";
	}

	//If there are still some item left, then it displays ... to the last item in the list 
	if (n > 3)
	{
		cout << "... --> ";   //Display ... 
		while (pCur && pCur->pNext)   //Go to the last item
		{
			pCur = pCur->pNext;
		}

		cout << pCur->item;  //Print out the last item
	}
	cout << ")";
}

