
/*

  This is the header file is for test functions

*/


#ifndef TEST_H //guard code

#define TEST_H


#include "Update.h"



/*
  Function:   void testInsert()

  Date Created:      Sep 23, 2021

  Date Last Modifiled:    Sep 23, 2021

  Description:   This function tests insertFront() function by inserting a new node into an empty list, then check whether the head node is updated,
                     containing the same data added.

  Input parameters:    None

  Returns:    None

  Preconditions:   None

  Postconditions:  Print out the test result(pass/failed) to the screen.
*/
void testInsert();



/*
  Function:     void testDelete()

  Date Created:      Sep 23, 2021

  Date Last Modifiled:    Sep 23, 2021

  Description:   This function tests deleteRecord() function. The test case is that there is a list with only one node, then choose a song title 
                      matching with that node to delete the whole node. Checks whether the head node is updated, it is NULL.

  Input parameters:    None

  Returns:    None

  Preconditions:    None

  Postconditions:    Print out the test result(pass/failed) to the screen.
*/
void testDelete();




/*
  Function:    void testShuffle()

  Date Created:      Sep 23, 2021

  Date Last Modifiled:      Sep 23, 2021

  Description:   This function tests shuffleSong() function. First load 3 data to the list, then just play songs 3, 1, 2 in order, asks the user 
                    whether the songs have been played in order. Finally, displays a message.

  Input parameters:   None

  Returns:    None

  Preconditions:   None

  Postconditions:     Print out the test result(pass/failed) to the screen.
*/
void testShuffle();





#endif
