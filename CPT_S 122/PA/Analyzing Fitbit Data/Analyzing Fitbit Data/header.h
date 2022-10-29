
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about fopen()

#include<stdio.h>    //necessary to use printf()

#include<string.h>  //necessary to use strcpy(), strcmp(), strlen() and strtok()

#include <stdlib.h> //necessary to use atof () and atoi()



#define SIZE 1440         //The size of record array

#define D_INVALID -1.0    //The invalid value for double data (used to insert into the empty data)
#define I_INVALID -1      //The invalid value for integer data (used to insert into the empty data)



//The enum of sleep level type
typedef enum sleep
{
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;




//The struct of a fitbit record
typedef struct fitbit
{
    char patient[10];            //Patient ID
    char minute[9];              //The minute in during 24 hour period
    double calories;             //The caloriies burned at the minute
    double distance;             //The distance walked in miles
    unsigned int floors;         //The number of floors walked
    unsigned int heartRate;      //The heart rate
    unsigned int steps;          //The number of steps taken
    Sleep sleepLevel;            //The sleep level representing for poor sleep

} FitbitData;







//All the function prototypes 



/*
  Function:    char* remove_front( )

  Date Created:     September 5, 2021

  Date Last Modifiled:     September 7, 2021

  Description:  This function removes the first character out of a string. 
                This is used to remove the character ',' in the token strings in case we get the empty data.

  Input parameters:  An char pointer to the source string and an char pointer to the destination string

  Returns:   An char pointer to the destination string

  Preconditions:   The char pointers to the source string and the destination string

  Postconditions:   The destination string has been the source after being removed the first character
*/
char* remove_front(char* source, char* desination);





/*
  Function:    int longest_poorSleep_range()

  Date Created:      September 5, 2021

  Date Last Modifiled:       September 5, 2021

  Description:     This function find the length of the longest consecutive range of poor sleep, 
                   and indirectly find the starting and ending indexes of the record with the longest range.
                   
  Input parameters:    Pointers to the the starting and ending indexes, and an array of FitbitData record

  Returns:     The length of the longest consecutive range of poor sleep

  Preconditions:    The pointers to the the starting and ending indexes, and the array of FitbitData record

  Postconditions:    The longest length has been found, and the starting and ending indexes have been indirectly found.
*/
int longest_poorSleep_range(int* start_index, int* end_index, FitbitData record[]);




/*
  Function:         void display ()

  Date Created:           September 5, 2021

  Date Last Modifiled:       September 7, 2021

  Description:     This function displays the filtered, deduped, and cleansed data to the screen

  Input parameters:   An array of Fitbit records

  Returns:     None

  Preconditions:     The array of Fitbit records

  Postconditions:   The filtered, deduped, and cleansed data have been displayed to the screen
*/
void display(FitbitData record[]);




/*
  Function:     void report_to_file()

  Date Created:       September 7, 2021

  Date Last Modifiled:      September 7, 2021

  Description:  This function writes the filtered, deduped, and cleansed data out the output file

  Input parameters:   An output file, and an array of Fitbit records

  Returns:     None

  Preconditions:     The output file, and the array of Fitbit records

  Postconditions:   The filtered, deduped, and cleansed data have been printed out the output file
*/
void report_to_file(FILE* outfile, FitbitData record[]);





#endif

