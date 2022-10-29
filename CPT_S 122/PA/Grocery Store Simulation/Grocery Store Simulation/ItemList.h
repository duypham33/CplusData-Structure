
/*

  This is the header file that stores standard library includes, #defined and function prototypes of ItemList Class

*/


#ifndef ITEM_LIST_H //guard code

#define ITEM_LIST_H 

#include <iostream>  //To use cin, cout, endl
#include<string>     //Use string to represent grocery items

using std::cin;
using std::cout;
using std::endl;
using std::string;





//Struct node, containing a string like “cereal”, “milk”, “steak”, etc. 
struct Node
{
	string item;
	Node* pNext;

	//Constructor - like a makeNode() function
	Node(const string& newItem = "")
	{
		item = newItem;
		pNext = NULL;
	}
};


//This class is a dynamic linked list, which represents a grocery item list of one customer.
class ItemList
{
public:
	//Constructor - Initializes an empty list
	ItemList();
	
	//Destructor - call destroy() function
	~ItemList();

	//This function inserts a node at the head of the list. Returns true if the memory is allocated for the new node, false is otherwise.
	bool insertFront(const string& newItem);


	//This function randomly generates a item list for a customer by randomly generating the total number of items first, then generating each item.
	//We suppose that the number of items ranges from 1 to 20, for each customer. 
	void generateList();

	//Getter: Get the total number of items generated, which helps compute the service time for the customer PROPORTIONALLY
	int getNumberItems() const;

	//This function displays the number of items and the shortcut of the list that the customer bought.
	//If there are less than four items, it displays all the items. Otherwise it displays two first items and ... to the last item in the list 
	void printList();

private:
	Node* mpHead;    //The pointer to the start of a dynamic singly linked list
	int numberItems; //The total number of items generated in the list (simply, it is the number of nodes in the linked list), useful to compute serviceTime

	//Destroy list, in order to save memory when it is no longer used
	void destroy();
};




#endif
