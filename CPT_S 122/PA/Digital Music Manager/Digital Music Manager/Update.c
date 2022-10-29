
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "Update.h"


//Function definitions


// I) "Insert" feature with one following function and reuse the insertFront() function
void insert(Node** pList)
{
    Record newData;

    //prompt and get the details of a new record from the user
    printf("Please, provide the details of a new record:\n");

    printf("Artist: ");   gets(newData.artist);
    printf("Album Titile: ");   gets(newData.albumTitile);
    printf("Song Titile: ");   gets(newData.songTitile);
    printf("Genre: ");   gets(newData.genre);
    printf("Song length:\n");
    printf(" Minute: ");    scanf("%d", &(newData.songLength.minutes));
    printf(" Second: ");    scanf("%d", &(newData.songLength.seconds));
    printf("Times played: ");   scanf("%d", &newData.num_played);
    printf("Rating: ");   scanf("%d", &newData.rating);

    //Insert the record at the front of the list
    insertFront(pList, newData);
}



// II) "Delete" feature with two following functions
Node* promptSong(Node* pList)
{
    Node* pSelect = NULL;

    if(pList != NULL)
    {
        Node* pCur = pList;

        //Display all songs in PlayList
        printf("The list of all songs:\n");

        while (pCur != NULL)
        {
            printf("%s\n", pCur->data.songTitile);

            pCur = pCur->pNext;
        }


        //Prompt to select the song
        char song[50] = "";
        printf("\nPlease, choose which song that you would like to delete its record (by typing its title): ");  gets(song);

        //Search for the node that matches this song
        pCur = pList;    //Reset pCur before the loop
        while (pCur != NULL && strcmp(pCur->data.songTitile, song) != 0)
        {
            pCur = pCur->pNext;
        }

        pSelect = pCur;
    }

    return pSelect;
}



int deleteRecord(Node** pList)
{
    //Use selectSong() function for prompt and search a song title
    Node* pSelect = promptSong(*pList);

    // If the song title does not exist, then the list remains unchanged.
    if (pSelect == NULL) { printf(" The song title does not exist in the PlayList!\n");   return 0; }

    else if (*pList == pSelect)    //The target node is the head node, so delete at front
    {
        *pList = pSelect->pNext;

        if (pSelect->pNext != NULL)
        {
            pSelect->pNext->pPrev = NULL;
        }

        free(pSelect);

        return 1;
    }

    else
    {
        pSelect->pPrev->pNext = pSelect->pNext;

        if (pSelect->pNext != NULL)
        {
            pSelect->pNext->pPrev = pSelect->pPrev;
        }

        free(pSelect);   //Free up the target node

        return 1;
    }
}





// III) "Sort" feature with three following functions

/*
There are 4 different methods to sort the records in the list. These include:
1.    Sort based on artist (A-Z)
2.    Sort based on album title (A-Z)
3.    Sort based on rating (1-5)
4.    Sort based on times played (largest-smallest)
*/
int compareRecord(Record data1, Record data2, int sortType)
{
    if (sortType == 1)   //Compare based on artist (returns  1 if the higher is of data 1, otherwise returns 0)
    {
        if (strcmp(data1.artist, data2.artist) == 1)
            return 1;

        else return 0;
    }

    else if (sortType == 2)   //Compare based on album title (returns  1 if the higher is of data 1, otherwise returns 0)
    {
        if (strcmp(data1.albumTitile, data2.albumTitile) == 1)
            return 1;

        else return 0;
    }

    else if (sortType == 3)   //Compare based on rating (returns  1 if the higher is of data 1, otherwise returns 0)
    {
        if (data1.rating > data2.rating)
            return 1;

        else return 0;
    }

    else if (sortType == 4)   //Compare based on times played (returns  1 if the higher is of data 2, otherwise returns 0)
    {
        if (data1.num_played < data2.num_played)
            return 1;

        else return 0;
    }
}



void swapData(Node* node1, Node* node2)
{
    Record temp = node2->data;
    node2->data = node1->data;
    node1->data = temp;
}



void selectionSort(Node* pList, int sortType)
{
    if (pList == NULL)   //The list is empty
    {
        return;
    }


    else
    {
        Node* pKey = pList;
        Node* pTemp = NULL;

        while (pKey->pNext != NULL)
        {
            pTemp = pKey->pNext;

            while (pTemp != NULL)
            {
                if (compareRecord(pKey->data, pTemp->data, sortType) == 1)
                {
                    swapData(pKey, pTemp);
                }

                pTemp = pTemp->pNext;
            }

            pKey = pKey->pNext;
        }
    }
}





// IV) "Shuffle" feature with three following functions

void insertFrontPortion(Portion** pHead, int newOrder)
{
    Portion* pMem = (Portion*)malloc(sizeof(Portion));

    if (pMem != NULL)
    {
        pMem->order = newOrder;
        pMem->pNext = *pHead;

        *pHead = pMem;
    }
}




int DoesExist(Portion* pHead, int newOrder)
{
    int status = 0;     //1, if newOrder is already in the list of portions; 0 is otherwise

    Portion* pCur = pHead;
    while (pCur != NULL)
    {
        if (pCur->order == newOrder)
        {
            status = 1;
            break;
        }

        pCur = pCur->pNext;
    }

    return status;
}





//Preposition: PlayList is not empty, and the order has already been generated randomly.
//This function is for moving through the list (forwards and backwards) and playing the songs in the order generated
void shuffleSong(Node* pList, Portion* pHead)   //Assume PlayList is not empty
{
    Node* pCur = pList;

    Portion* pCurPor = pHead;
    Portion* pNextPor = NULL;

    int order = 1;



    //Play the first portion
    if (pCurPor->order > 1)
    {
        while (order != pCurPor->order) { pCur = pCur->pNext;   order++; }  //pCur and order would be updated after loop
    }

    //Display the first song in generated order
    printf("\nSong %d\n", order);
    printNode(pCur);
    Sleep(pCur->data.songLength.minutes * 600 + pCur->data.songLength.seconds * 10);  //Display the song for seconds (based on the length of the song)


    //Play the other portions
    while (pCurPor->pNext != NULL)
    {
        pNextPor = pCurPor->pNext;

        if (pCurPor->order < pNextPor->order)   // Moving forwards
        {
            while (order != pNextPor->order) { pCur = pCur->pNext;   order++; }  //pCur and order would be updated after loop
        }

        else if (pCurPor->order > pNextPor->order)   // Moving backwards
        {
            while (order != pNextPor->order) { pCur = pCur->pPrev;   order--; }  //pCur and order would be updated after loop
        }

        //Display the first song in generated order
        printf("\nSong %d\n", order);
        printNode(pCur);
        Sleep(pCur->data.songLength.minutes * 600 + pCur->data.songLength.seconds * 10);  //Display the song for seconds (based on the song length)

        
        pCurPor = pCurPor->pNext;
    }
}







/*
    V) Run the application by runApp() function
*/

void runApp(Node* pList)
{
    int opt = 0;

    do
    {
        //Display the main menu to the screen
        printf("Digital Music Manager\n       MENU\n");
        printf("    1. Load\n    2. Store\n    3. Display\n    4. Insert\n    5. Delete\n");
        printf("    6. Edit\n    7. Sort\n    8. Rate\n    9. Play\n    10. Shuffle\n    11. Exit\n");

        //Prompt the user for a feature
        printf("\nPlease, select your option (1-11): ");
        scanf("%d", &opt);



        if (opt == 1)    //"Load" feature
        {
            //Open the .csv file with mode “read”
            FILE* infile = fopen("musicPlayList.csv", "r");

            //Load data 
            pList = loadData(pList, infile);

            fclose(infile);   //Close the file

            printf("\n Hit ENTER to return the menu!");
            getch();   system("cls");    //Clear the screen to return the main menu
        }





        else if (opt == 2)    //"Store" feature
        {
            //Open the .csv file with mode “write”
            FILE* outfile = fopen("musicPlayList.csv", "w");

            //Store List
            storeRecord(pList, outfile);

            Sleep(2000);  system("cls");
            printf("The PlayList has stored into the file!\n");

            fclose(outfile);   //Close the file

            printf("\n Hit ENTER to return the menu!");
            getch();   system("cls");     //Clear the screen to return the main menu
        }





        else if (opt == 3)    //"Display" feature
        {
            //Print two methods to the screen 
            system("cls");
            printf("    DISPLAY\n1. Print all records.\n2. Print all records that match an artist.\n");
            int opt_dpl = 0;

            do    //The loop prompting the user for a method option
            {
                printf("\nPlease, select your option(1 or 2): ");    scanf("%d", &opt_dpl);

                if (opt_dpl != 1 && opt_dpl != 2)
                {
                    printf("\nYour option is invalid! Try again!\n");
                }
            } while (opt_dpl != 1 && opt_dpl != 2);


            if (opt_dpl == 1)   //Display all records in the PlayList
            {
                system("cls");
                printList(pList);
            }

            else if (opt_dpl == 2)  //Print all records that match an artist
            {
                system("cls");

                //Prompt the user for an artist name
                char searchArtist[50] = "";  getchar();
                printf("Please, type name of the artist that you would like to search: ");
                gets(searchArtist);

                Node* pSearch = searchingArtist(pList, searchArtist);

                system("cls");

                displayRecords_artist(pList, searchArtist);
            }


            printf("\n\n\nHit ENTER to return the menu!");
            getch();   system("cls");   //Clear the screen to return the main menu
        }





        else if (opt == 4)   //"Insert" feature
        {
            system("cls");    getchar();

            insert(&pList);

            Sleep(1000);    system("cls");
            printf("The new record has been inserted successfully!\n");

            printf("\n\nHit ENTER to return the menu!");
            getch();   system("cls");
        }



        else if (opt == 5)      //"Delete" feature
        {
            if (pList != NULL)
            {
                system("cls");    getchar();
                int flag = deleteRecord(&pList);

                if (flag == 1)
                {
                    system("cls");
                    printf("  DELETE SUCCESSFULLY!");
                }
            }
          
            else
            {
                system("cls");
                printf("The PlayList is empty!");     
            }

            printf("\n\nHit ENTER to return the menu!");
            getch();   system("cls");
        }





        else if (opt == 6)     //"Edit" feature
        {
            system("cls");

            //Prompt the user for an artist name
            getchar();
            char searchArtist[50] = "";
            printf("Please, type name of the artist that you would like to search: ");
            gets(searchArtist);

            //Use recordChosenEdit() function to prompt the user for which record want to edit, and return a pointer to this target node
            system("cls");
            Node* pEdit = recordChosenEdit(pList, searchArtist);

            if (pEdit != NULL)
            {
                system("cls");

                //Edit the record 
                editRecord(pEdit);

                system("cls");
                printf("     EDIT SUCCESSFULLY\n");

            }

            printf("\n\nHit ENTER to return the menu!");
            getch();   system("cls");    //Clear the screen to return the main menu

        }





        else if (opt == 7)   //"Sort" feature
        {
           system("cls");
           printf("\t    SORT\n1. Sort based on artist (A-Z)\n2. Sort based on album title (A-Z)\n");
           printf("3. Sort based on rating(1 - 5)\n4.Sort based on times played(largest - smallest)\n");
           int opt_sort = 0;

           do
           {
               printf("\nPlease, select your option(1-4): ");    scanf("%d", &opt_sort);

               if (opt_sort < 1 || opt_sort > 4)
               {
                   printf("\nYour option is invalid! Try again!\n");
               }
           } while (opt_sort < 1 || opt_sort > 4);

           system("cls");
           
           selectionSort(pList, opt_sort);
           printf("\nThe PlayList after softing:\n\n");
           printList(pList);

           printf("\n\n\nHit ENTER to return the menu!");
           getch();   system("cls");
        }




        else if (opt == 8)    //"Rate" feature
        {
            if (pList != NULL)   //The list is not empty
            {
                system("cls");

                //Prompt the user for an song title to rate, and return a pointer to the node with that song by selectSong() function
                getchar();
                Node* pSelect = selectSong(pList, "rate");

                //Rate the song
                system("cls");
                rateSong(pSelect);
                system("cls");
                printf("     RATE SUCCESSFULLY\n");
                printf("\n\nHit ENTER to return the menu!");
                getch();   system("cls");       //Clear the screen to return the main menu
            }

            else   //The list is empty
            {
                system("cls");
                printf("The PlayList is empty!");
                printf("\n\nHit ENTER to return the menu!");
                getch();   system("cls");      //Clear the screen to return the main menu
            }
        }





        else if (opt == 9)      //"Play" feature
        {
            if (pList != NULL)     //The list is not empty
            {
                //Print two methods to the screen 
                system("cls");
                printf("    PLAY\n1. PLay all songs in PlayList.\n2. Choose a song and play all songs until the end of the list has been reached.\n");
                int opt_pl = 0;

                do    //The loop prompting the user for a method option
                {
                    printf("\nPlease, select your option(1 or 2): ");    scanf("%d", &opt_pl);

                    if (opt_pl != 1 && opt_pl != 2)
                    {
                        printf("\nYour option is invalid! Try again!\n");
                    }
                } while (opt_pl != 1 && opt_pl != 2);


                if (opt_pl == 1)   //Play all records in the PlayList
                {
                    system("cls");
                    playSong(pList);
                }


                else if (opt_pl == 2)
                {
                    system("cls");

                    //Prompt the user for an song title to play, and return a pointer to the node with that song by selectSong() function
                    getchar();
                    Node* pSelect = selectSong(pList, "play");
                    system("cls");

                    playSong(pSelect);
                }

                printf("The end of PlayList!\n");

                printf("\n\nHit ENTER to return the menu!");
                getch();   system("cls");   //Clear the screen to return the main menu
            }

            else    //The list is empty
            {
                system("cls");
                printf("The PlayList is empty!");
                printf("\n\nHit ENTER to return the menu!");
                getch();   system("cls");      //Clear the screen to return the main menu
            }
        }





        else if (opt == 10)   //"Shuffle" feature
        {
           if (pList == NULL)
           {
               system("cls");
               printf("The PlayList is empty!");
           }

           else
           {
               srand((time(NULL)));

               Portion* pHead = NULL;

               int newOrder = 0;
               int count = 0;

               int N = 0;    //The number of songs in PlayList
               Node* pCur = pList;

               while (pCur != NULL)    //Compute the number of songs in the PlayList
               {
                   ++N;
                   pCur = pCur->pNext;
               }


               do     //Generate random portions 
               {
                   newOrder = rand() % N + 1;

                   if (DoesExist(pHead, newOrder) == 0)
                   {
                       insertFrontPortion(&pHead, newOrder);
                       ++count;
                   }

               } while (DoesExist(pHead, newOrder) == 1 && count < N);


               system("cls");   //Clear the screen
               shuffleSong(pList, pHead);      //Shuffle

               free(pHead);   //Free up the memory
           }

           printf("\n\nHit ENTER to return the menu!");
           getch();   system("cls");
        }




        else if (opt == 11)    //"Exit" feature, which writes the records in the list to the musicPlayList.csv file, and exits the program.
        {
            FILE* file = fopen("musicPlayList.csv", "w");
            storeRecord(pList, file);
            system("cls");
            printf("The most recent list has been saved to the file!\n");
            fclose(file);
        }



        else   //Invalid option 
        {
            system("cls");
            printf("Your option is invalid! Try again\n\n");
        }

    } while (opt != 11);   //Exit the program when the option 11 is hit

}