
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef DMM_H //guard code

#define DMM_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()


#include<stdio.h>    //necessary to use printf() and scanf()

#include<stdlib.h>   //necessary to use malloc(), free(), and atoi()

#include<string.h>   //necessary to use strcmp(), strcpy(), strtok() and strchr()

#include<Windows.h>  //necessary to use Sleep()




//Strcut Duration for  representing song length
typedef struct duration
{
	int minutes;
	int seconds;     //from 0-59
} Duration;




typedef struct record
{
	char artist[30];
	char albumTitile[50];
	char songTitile[50];
	char genre[20];
	Duration songLength;
	int num_played;
	int rating;     //an integer (1 – 5)
} Record;




typedef struct node
{
	Record data;
	struct node* pPrev;     //Pointer to the next node
	struct node* pNext;     //Pointer to the previous node
} Node;





//The function prototypes 




/*
   I) Constructing a doubly linked list by 4 following functions
*/


/*
  Function:    Node* makeNode()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function allocates a memory and then initializes a node

  Input parameters:    A Record struct for the data

  Returns:    A pointer to the node allocated

  Preconditions:    A Record struct for the data

  Postconditions:    The pointer to the node allocated
*/
Node* makeNode(Record data);






/*
  Function:     int insertFront()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function inserts a node in the front of the list

  Input parameters:    A pointer to the address of the list, and a Record struct for a new data

  Returns:     an integer: 1 for successfully allocating space for a node; 0 otherwise

  Preconditions:     The pointer to the address of the list, and the Record struct for a new data

  Postconditions:    The flag of success
*/
int insertFront(Node** pList, Record newData);



/*
  Function:   void printNode()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function print the content of one node to the screen

  Input parameters:    A pointer to a node

  Returns:     None

  Preconditions:   The pointer to the node

  Postconditions:    The content has been displayed
*/
void printNode(Node* node);   //This function display the content of one node, which is useful for display seperated record later 



/*
  Function:      void printList()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function prints all of the records in the list

  Input parameters:    A pointer to a list

  Returns:    None

  Preconditions:    The pointer to the list

  Postconditions:   All records have been displayed
*/
void printList(Node* pList);



/*
   II) "Load" and "Store" features with 2 following functions
*/

/*
  Function:    Node* loadData()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function reads all records in the cvs file for the main list

  Input parameters:   A pointer to the list head and an input file

  Returns:    A pointer to the list head

  Preconditions:     The pointer to the list head and the input file

  Postconditions:    The pointer to the list head has been returned
*/
Node* loadData(Node* pList, FILE* infile);



/*
  Function:     void storeRecord()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function overwrites all records in the manin list to the output file

  Input parameters:    A pointer to the list head and an output file

  Returns:     None

  Preconditions:    The pointer to the list head and an output file

  Postconditions:   ALl records have been overwritten to the file
*/
void storeRecord(Node* pList, FILE* file);



/*
   III) "Display" and "Edit" features with 5 following functions
*/


/*
  Function:    Node* searchingArtist()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function searches the nearest node with the target artist name

  Input parameters:   The pointer to the list head, and the string of the artist name

  Returns:   The pointer to the node found

  Preconditions:    The pointer to the list head, and the string of the artist name

  Postconditions:   The target node has been found
*/
Node* searchingArtist(Node* pList, char* searchArtist);




/*
  Function:    int displayRecords_artist()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function displays all records that match with the artist name

  Input parameters:   The pointer to the list head, and the string of the artist name

  Returns:  The number of all records displayed

  Preconditions:    The pointer to the list head, and the string of the artist name

  Postconditions:   The number of all records displayed has been returned
*/
int displayRecords_artist(Node* pList, char* searchArtist);




/*
  Function:    Node* recordChosenEdit()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function finds the poiter to the node that the user wants to edit

  Input parameters:   The pointer to the list head, and the string of the artist name

  Returns:   The pointer to the target node

  Preconditions:   The pointer to the list head, and the string of the artist name

  Postconditions:  The pointer to the target node has been found
*/
Node* recordChosenEdit(Node* pList, char* searchArtist);




/*
  Function:   char promptEdit()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function prompts the user for keeping or editing an attribute in the record

  Input parameters:   A string of the attribute

  Returns:   A characte of an option 'e' for edit, or 'k' for keep

  Preconditions:   The string of the attribute

  Postconditions:   The option has been returned
*/
char promptEdit(char* attribute);




/*
  Function:   void editRecord()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function edits a record

  Input parameters:   The pointer to the node that the user wants to edit

  Returns:   None

  Preconditions:    The pointer to the node that the user wants to edit

  Postconditions:   The record has been editted
*/
void editRecord(Node* pEdit);




/*
	IV) "Rate" and "Play" features with 3 following functions
*/

/*
  Function:   Node* selectSong()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function searches a node based on song title

  Input parameters:  The pointer to the list head, and the string of the feature

  Returns:   The pointer to the node with target song

  Preconditions:   The pointer to the list head, and the string of the feature

  Postconditions:   The pointer to the node with target song has been returned
*/
Node* selectSong(Node* pList, char* feature);






/*
  Function:   void rateSong()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function rates a song

  Input parameters:  The pointer to the node with target song

  Returns:  None

  Preconditions:   The pointer to the node with target song

  Postconditions:  The song has been rated
*/
void rateSong(Node* pSelect);




/*
  Function:   void playSong()

  Date Created:      Sep 11, 2021

  Date Last Modifiled:       Sep 13, 2021

  Description:   This function plays all songs from the target song until the end of the PlayList

  Input parameters:   The pointer to the node with target song

  Returns:   None

  Preconditions:   The pointer to the node with target song

  Postconditions:   Songs have been displayed
*/
void playSong(Node* pSelect);





#endif

