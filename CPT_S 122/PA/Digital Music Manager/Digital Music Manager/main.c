
/*
      * Programmer: Duy Pham

      * Class: CptS 122, Fall 2021; Section 01; Lab Section 06

      * Programming Assignment:    PA 3: Digital Music Manager & Doubly Linked Lists – Part II

      * Date:    Sep 20, 2021

      * Description: This program manipulates a music collection based on attributes 
                     such as artist, album title, song title, genre, song length, number times played, and rating.
                     This Digital Music Manager program has a text-based interface which allows the user 
                     to select from a main menu of options including: 
                     (1) load, (2) store, (3) display, (4) insert, (5) delete, (6) edit, (7) sort, (8) rate, (9) play, (10) shuffle, and (11) exit.
*/


// #include "DMM.h"
// #include "Update.h"
#include "Test.h"


int main(void)
{
    int opt = 0;

    do
    {
        //Prompt the user for choosing testing feature functions or running the application
        printf("\n  1. Test feature functions\n  2. Run the application\n");
        printf("  Please, enter your option (1-2): ");
        scanf("%d", &opt);

        if (opt == 1 || opt == 2)
        {
            system("cls");
            if (opt == 1)
            {
                testInsert();   printf("\nHit ENTER to continue!");   getch();
                printf("\n\n*******************************************************************************\n\n");

                testDelete();   printf("\nHit ENTER to continue!");   getch();
                printf("\n\n*******************************************************************************\n\n");

                testShuffle();
                printf("\n\n*******************************************************************************\n\n");

                printf("\n Hit ENTER to turn to the application!");
                getch();   system("cls");    //Clear the screen to turn the application
            }


            //The main PlayList
            Node* pList = NULL;

            //Run the application
            runApp(pList);
        }
        
        else
        {
            system("cls");
            printf(" Your option is invalid! Please, try again!\n\n");
        }
        
    } while(opt < 1 || opt > 2);


  
    return 0;     //The program was successful
}