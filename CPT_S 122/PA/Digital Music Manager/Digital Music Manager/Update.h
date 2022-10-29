
/*

  This is the header file is for updated features (Insert, Delete, Sort, and Shuffle)

*/


#ifndef UPDATE_H //guard code

#define UPDATE_H


#include "DMM.h"


/*
    We define a struct Portion to support algorithm solving problems on shuffle. 
	In particular, it is a singly linked list, in which data represent order in which the songs are played (After randomly generated)
	For example: The PlayList has 5 songs at positions 1 – 5. An order 2, 5, 3, 1, 4 is generated, 
	             and then this portion list would have 5 nodes containing integers 2, 5, 3, 1, 4 as data respectively
*/

typedef struct portion
{
	int order;
	struct portion* pNext;

} Portion;





// I) "Insert" feature with one following function and reuse the insertFront() function

/*
  Function:    void insert()

  Date Created:     Sep 20, 2021

  Date Last Modifiled:       Sep 20, 2021

  Description:   This function first prompts the user for all record details, then insert this record at the front of the list 

  Input parameters:   The pointer to the address value of the list

  Returns:    None

  Preconditions:   The pointer to the address value of the list

  Postconditions:    The new record node has been inserted at the front of the list
*/
void insert(Node** pList);







// II) "Delete" feature with two following functions 

/*
  Function:    Node* promptSong()

  Date Created:     Sep 20, 2021

  Date Last Modifiled:    Sep 23, 2021

  Description:   This function prompt the user for a song title that matchs with deleted record

  Input parameters:    The pointer to the list

  Returns:    The pointer to node matching with a search song. If the song does not exist in the list, then returns NULL

  Preconditions:   The pointer to the list

  Postconditions:   The pointer to the target node has been returned, if found.
*/
Node* promptSong(Node* pList);




/*
  Function:    int deleteRecord()

  Date Created:    Sep 20, 2021

  Date Last Modifiled:     Sep 23, 2021

  Description:   This function deletes the target node from the list, if the node does not exist, then the list remains unchanged.

  Input parameters:    The pointer to the address value of the list

  Returns:    An integer 1 if the node exists and be deleted, otherwise returns 0. 

  Preconditions:      The pointer to the address value of the list

  Postconditions:   The integer 1 or 0 has been returned.
*/
int deleteRecord(Node** pList);








// III) "Sort" feature with three following functions


/*
  Function:       int compareRecord()

  Date Created:      Sep 20, 2021

  Date Last Modifiled:     Sep 20, 2021

  Description:   This function compares two records based on one of the four sort types 
                      1.    Sort based on artist (A-Z)
                      2.    Sort based on album title (A-Z)
                      3.    Sort based on rating (1-5)
                      4.    Sort based on times played (largest-smallest)

  Input parameters:   Two records and an integer representing a sort type

  Returns:    An integer 1 if record 1 is higher than record 2 based on the sort type, otherwise returns 0.

  Preconditions:    Two records and an integer representing a sort type

  Postconditions:    The integer 1 or 0 has been returned.
*/
int compareRecord(Record data1, Record data2, int sortType);



/*
  Function:   void swapData()

  Date Created:        Sep 20, 2021

  Date Last Modifiled:       Sep 20, 2021

  Description:   This function swaps data between two nodes, does not change the link of them

  Input parameters:   The two pointers to the two nodes

  Returns:    None

  Preconditions:    The two pointers to the two nodes

  Postconditions:    Data have been swapped
*/
void swapData(Node* node1, Node* node2);



/*
  Function:   void selectionSort()

  Date Created:        Sep 20, 2021

  Date Last Modifiled:         Sep 20, 2021

  Description:   This function applies selection sort to sort the nodes in the list based on the sort type

  Input parameters:   The pointer to the list and the sort type

  Returns:    None

  Preconditions:   The pointer to the list and the sort type

  Postconditions:  The nodes have been sorted
*/
void selectionSort(Node* pList, int sortType);







// IV) "Shuffle" feature with three following functions


/*
  Function:    void insertFrontPortion()

  Date Created:    Sep 20, 2021

  Date Last Modifiled:      Sep 20, 2021

  Description:   This function inserts a new node at the front of the portion list

  Input parameters:    The pointer to the address value of the head node, and a new integer data

  Returns:    None

  Preconditions:    The pointer to the address value of the head node, and a new integer data

  Postconditions:   The node has been inserted
*/
void insertFrontPortion(Portion** pHead, int newOrder);


/*
  Function:   int DoesExist()

  Date Created:       Sep 20, 2021

  Date Last Modifiled:       Sep 20, 2021

  Description:   This function checks whether an integer already exists in a portion list

  Input parameters:   The pointer to the head node, and an integer 

  Returns:    1 if the integer already exists, 0 is otherwise

  Preconditions:  The pointer to the head node, and the integer 

  Postconditions:   The check has been done
*/
int DoesExist(Portion* pHead, int newOrder);



/*
  Function:    void shuffleSong()

  Date Created:      Sep 20, 2021

  Date Last Modifiled:      Sep 20, 2021

  Description:   This function is for moving through the list (forwards and backwards) and playing the songs in the order generated

  Input parameters:   The pointer to the list, and the pointer to the portion head node

  Returns:    None

  Preconditions:   The pointer to the list, and the pointer to the portion head node

  Postconditions:   All songs have been played in generated order
*/
void shuffleSong(Node* pList, Portion* pHead);





/*
	V) Run the application by runApp() function
*/

/*
  Function:   void runApp()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 23, 2021

  Description:   This function runs the application

  Input parameters:  The pointer to the list head(the main list)

  Returns:  None

  Preconditions:   The pointer to the list head

  Postconditions:  The application has been run
*/
void runApp(Node* pList);







#endif
