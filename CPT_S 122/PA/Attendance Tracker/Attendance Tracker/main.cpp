
/*
      * Programmer: Duy Pham

      * Class: CptS 122, Fall 2021; Section 01; Lab Section 06

      * Programming Assignment:    PA 7: Attendance Tracker w/ class Templates

      * Date:  November 8th, 2021

      * Description: This program creates an application that manages attendance for a course. All the student records from the classList.csv file, would
                     be imported into the master list. Then, the user can make absence for students if he/she was absent for the current day.
                     Besides, the user may also remove the absent date, if the student is later considered not absent in that day.
                     Additionally, the program also allows the user to generate two different reports:
                      Version 1: Shows all of the students in the class and the number of times they have been absent, along with the most recent absence.
                      Version 2: Shows the names of the students absent for those who are absent greater than some threshold set.
                     The student records is stored in a linked list data structure. In each node, beside of the basic records of students, 
                     absent dates is stored into a stack implemented by using a vector.
*/


#include "TrackerApp.h"


int main(void)
{
    //Allocate a space with 4 bytes for the main application
    TrackerApp* app = new TrackerApp();

    //Run the application
    app->runApp();

    //Free up the space after using
    delete app;
    
    return 0;     //The program was successful
}