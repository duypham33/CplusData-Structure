
/*
      * Programmer: Duy Pham

      * Class: CptS 122, Fall 2021; Section ; Lab Section

      * Programming Assignment:    PA 7: Attendance Tracker w/ class Templates

      * Date:       , 2021

      * Description: This program

*/



#include "TrackerApp.h"


int main(void)
{
    TrackerApp* app = new TrackerApp();

    app->run();


    delete app;

    //cout << setw(60) << "(y/n)" << endl;




    return 0;     //The program was successful
}