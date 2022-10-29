
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "DMM.h"


//Function definitions



/*
   I) Constructing a doubly linked list by 4 following functions
*/

Node* makeNode(Record data)
{
    //Allocate space for the node
    Node* pMem = (Node*)malloc(sizeof(Node));

    if (pMem != NULL)
    {
        //Memory was allocated successfully
        pMem->data = data;
        pMem->pNext = NULL;
        pMem->pPrev = NULL;
    }

    return pMem;
}





int insertFront(Node** pList, Record newData)
{
    int success = 0;    //1 for successfully allocating space for a node; 0 otherwise

    Node* pMem = makeNode(newData);


    if (pMem != NULL)     //Memory was available
    {
        success = 1;

        if (*pList == NULL)   //The list is empty
        {
            *pList = pMem;
        }

        else
        {
            pMem->pNext = *pList;
            (*pList)->pPrev = pMem;
            *pList = pMem;
        }
    }

    return success;
}




//This function display the content of one node, which is useful for display seperated record later 
void printNode(Node* node)
{
    if (node != NULL)
    {
        //Display the record content of the node to the screen
        printf(" Artist: %s, Album Titile: %s, Song Title: %s, Genre: %s, Song length: %d:%d, Times played: %d, Rating: %d\n",
            node->data.artist, node->data.albumTitile, node->data.songTitile, node->data.genre, node->data.songLength.minutes
            , node->data.songLength.seconds, node->data.num_played, node->data.rating);
    }
}




void printList(Node* pList)
{
    if (pList == NULL)
    {
        printf("\nThe PlayList is empty!\n");
    }

    else
    {
        Node* pCur = pList;

        while (pCur != NULL)
        {
            //Display the record content of the node to the screen
            printNode(pCur);

            if (pCur->pNext != NULL)
            {
                printf("%45c%3c\n%45c%3c\n%45c%3c\n", '^', '|', '|', '|', '|', 'v');    //Display the link between nodes
            }

            pCur = pCur->pNext;
        }
    }
}





/*
   II) "Load" and "Store" features with 2 following functions
*/

Node* loadData(Node* pList, FILE* infile)
{
    char line[200];   //The string used to read the file line by line


    if (infile != NULL)
    {
        //The file is opened successfully


        //Start to read the records
        Record readData;
        while (fgets(line, 200, infile) != NULL)
        {
            //Read field of artist
            if (line[0] == '\"')
            {
                strcpy(readData.artist, strtok(line, "\""));
            }

            else
            {
                strcpy(readData.artist, strtok(line, ","));
            }

            //Read field of album title
            strcpy(readData.albumTitile, strtok(NULL, ","));

            //Read field of song title
            strcpy(readData.songTitile, strtok(NULL, ","));

            //Read field of genre
            strcpy(readData.genre, strtok(NULL, ","));

            //Read field of song length
            readData.songLength.minutes = atoi(strtok(NULL, ":"));
            readData.songLength.seconds = atoi(strtok(NULL, ","));

            //Read field of times played
            readData.num_played = atoi(strtok(NULL, ","));

            //Read field of rating
            readData.rating = atoi(strtok(NULL, "\n"));

            //Insert the record at the front of the list
            insertFront(&pList, readData);
        }

        system("cls");
        printf("All the records have been loaded!\n");
    }


    else  //Fail to open file 
    {
        system("cls");
        printf("Failed to open the file!\n");
    }

    return pList;
}




void storeRecord(Node* pList, FILE* file)
{
    if (pList == NULL)    //The list is empty
    {
        printf("\nThe PlayList is empty!\n");
        fprintf(file, "The PlayList is empty!\n");
    }

    else
    {
        while (pList != NULL)
        {
            //If there is a comma ',' in the artist name, then we put it between " ". 
            //Otherwise, just print itself (This is the style in the original file).
            if (strchr(pList->data.artist, ',') != NULL)
            {
                fprintf(file, "\"%s\",", pList->data.artist);
            }

            else
            {
                fprintf(file, "%s,", pList->data.artist);
            }

            fprintf(file, "%s,%s,%s,%d:%d,%d,%d\n", pList->data.albumTitile, pList->data.songTitile, pList->data.genre,
                pList->data.songLength.minutes, pList->data.songLength.seconds, pList->data.num_played, pList->data.rating);

            pList = pList->pNext;
        }
    }
}







/*
   III) "Display" and "Edit" features with 5 following functions
*/


//This function is for searching for specific record based on artist (use for feature Display and Edit)
//It return a pointer to the node with the search artist

Node* searchingArtist(Node* pList, char* searchArtist)
{
    Node* pSearch = NULL;

    if (pList == NULL)  //The list is empty
    {
        pSearch = NULL;
    }


    else
    {
        Node* pCur = pList;

        while (pCur != NULL && strcmp(pCur->data.artist, searchArtist) != 0)
        {
            pCur = pCur->pNext;
        }

        if (pCur == NULL)  //The search artist was not found
        {
            pSearch = NULL;
        }

        else  //The search artist is in the current node
        {
            pSearch = pCur;
        }
    }


    return pSearch;
}



int displayRecords_artist(Node* pList, char* searchArtist)
{
    int k = 0;    //count the number of records that match the artist in the list

    Node* pCur = pList;
    Node* pSearch = NULL;

    printf("%80s", "SEARCH RESULTS\n");

    do  //The loop for searching all the nodes with the target artist, and display all the record related 
    {
        //Use searchingArtist() function to find the nearest node with the target artist
        pSearch = searchingArtist(pCur, searchArtist);

        if (pSearch != NULL)
        {
            k++;
            printf("%d)", k);
            printNode(pSearch);

            pCur = pSearch->pNext;
        }

    } while (pCur != NULL && pSearch != NULL);


    if (k == 0)
    {
        printf("%105s", "There is no record with the search artist in the PlayList!\n\n");
    }


    return k;
}



//This function is to find the poiter to the node that the user wants to edit
Node* recordChosenEdit(Node* pList, char* searchArtist)
{
    int k = displayRecords_artist(pList, searchArtist);    //The number of records that match the target artist in the list

    //The pointer to a node chosen to edit 
    Node* pEdit = NULL;


    if (k == 0)
    {
        pEdit = NULL;
    }


    else if (k == 1)    //There is only one record with the search artist
    {
        pEdit = searchingArtist(pList, searchArtist);
    }



    else      //There are multiple records with the same artist
    {
        //Prompt the user which one to edit
        int opt = 0;
        printf("\nThere are %d records found in the Play List!\nPlease, choose which one to edit by its order in the search list above (1-%d): ", k, k);
        scanf("%d", &opt);

        //Then, we will find the position of the node chosen based on the option that the user typed

        int count = 0;       //count the number of records that match the artist in the list

        Node* pCur = pList;

        do    //The loop for finding the ith target node with i is the user's option 
        {
            pEdit = searchingArtist(pCur, searchArtist);

            if (pEdit != NULL)
            {
                count++;
                if (count == opt)
                {
                    break;    //The chosen record has been found, break the loop!
                }

                pCur = pEdit->pNext;
            }

        } while (pCur != NULL && pEdit != NULL);
    }

    //We found the pointer to the target node that the user wants to edit.
    return pEdit;
}


//This function is to prompt the user for keeping or editing an attribute in the record
char promptEdit(char* attribute)
{
    char opt = '\0';
    printf("Would you like to edit or keep %s (type 'e' for edit / 'k' for keep): ", attribute);
    scanf(" %c", &opt);

    return opt;
}



void editRecord(Node* pEdit)
{
    //Display the current record for the user to view while editing
    printNode(pEdit);

    //Prompt the user to edit
    printf("\nPlease edit the record(enter):\n");   getchar();

    char opt = '\0';

    opt = promptEdit("Artist Name");
    if (opt == 'e')
    {
        getchar();
        printf("Artist: ");   gets(pEdit->data.artist);
        printf("\n");
    }


    opt = promptEdit("Album Titile");
    if (opt == 'e')
    {
        getchar();
        printf("Album Titile: ");   gets(pEdit->data.albumTitile);
        printf("\n");
    }

    opt = promptEdit("Song Titile");
    if (opt == 'e')
    {
        getchar();
        printf("Song Titile: ");   gets(pEdit->data.songTitile);
        printf("\n");
    }

    opt = promptEdit("Genre");
    if (opt == 'e')
    {
        getchar();
        printf("Genre: ");   gets(pEdit->data.genre);
        printf("\n");
    }

    opt = promptEdit("Song length");
    if (opt == 'e')
    {
        printf("Song length:\n");
        printf(" Minute: ");   scanf("%d", &(pEdit->data.songLength.minutes));
        printf(" Second: ");   scanf("%d", &(pEdit->data.songLength.seconds));
        printf("\n");
    }

    opt = promptEdit("Times played");
    if (opt == 'e')
    {
        printf("Times played: ");   scanf("%d", &pEdit->data.num_played);
        printf("\n");
    }


    opt = promptEdit("Rating");
    if (opt == 'e')
    {
        printf("Rating: ");   scanf("%d", &pEdit->data.rating);
        printf("\n");
    }
}






/*
    IV) "Rate" and "Play" features with 3 following functions
*/

//This function is to search based on song title (use for features Rate and Play)
Node* selectSong(Node* pList, char* feature)
{
    Node* pSelect = NULL;

    if (pList == NULL)
    {
        printf("\nThe PlayList is empty!\n");
        pSelect = NULL;
    }

    else
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
        printf("\nPlease, choose which song to %s (by typing its title): ", feature);  gets(song);

        //Search for the node that matches this song
        do
        {
            pCur = pList;
            while (pCur != NULL && strcmp(pCur->data.songTitile, song) != 0)
            {
                pCur = pCur->pNext;
            }

            if (pCur == NULL)  //Song does not exist in the list
            {
                printf("\nThe song is not in the PlayList! Please, type another song title!\n");
                //getchar();
                printf("Please, choose which song to %s (by typing its title): ", feature);  gets(song);
            }

            pSelect = pCur;

        } while (pSelect == NULL);
    }


    return pSelect;
}



void rateSong(Node* pSelect)
{

    if (pSelect == NULL)
    {
        return;
    }

    else
    {
        //Prompt the rating
        printf("Please, rate for the song (1 is the lowest rating and 5 is the highest rating): ");
        scanf("%d", &(pSelect->data.rating));
    }
}



void playSong(Node* pSelect)
{
    Node* pCur = pSelect;

    while (pCur != NULL)
    {
        printf("\n");
        printNode(pCur);
        //Display the song for seconds (based on the length of the song)
        Sleep(pCur->data.songLength.minutes * 600 + pCur->data.songLength.seconds * 10);   

        pCur = pCur->pNext;
        system("cls");    //Clear the screen
    }
}



