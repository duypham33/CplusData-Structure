
#include "Test.h"


void testInsert()
{
	Node* pList = NULL;   //Initially empty

	Record newData = { "Perry, Katy", "Witness" , "Chained to the Rhythm", "pop", {4, 36}, -1, 6 };
	printf("Record used to insert into the empty list:\n");
	printf(" Artist: %s, Album Titile: %s, Song Title: %s, Genre: %s, Song length: %d:%d, Times played: %d, Rating: %d\n\n",
		newData.artist, newData.albumTitile, newData.songTitile, newData.genre, newData.songLength.minutes
		, newData.songLength.seconds, newData.num_played, newData.rating); 
	Sleep(1000);


	insertFront(&pList, newData);
	//Display the head node after inserting
	printf("The first record after inserting:\n");
	printNode(pList);   Sleep(1000);

	int check = 0;
	if (pList != NULL)   //Check whether the head node is updated
	{
		if (strcmp(pList->data.artist, newData.artist) == 0 && strcmp(pList->data.albumTitile, newData.albumTitile) == 0)
		{
			if (strcmp(pList->data.songTitile, newData.songTitile) == 0 && strcmp(pList->data.genre, newData.genre) == 0)
			{
				if (pList->data.songLength.minutes == newData.songLength.minutes && pList->data.songLength.seconds == newData.songLength.seconds)
				{
					if (pList->data.num_played == newData.num_played && pList->data.rating == newData.rating)
					{
						check = 1;
					}
				}
			}
		}
	}

	if (check == 1)   //Success
	{
		printf("\nTest insert function passed!\n\n");
	}

	else
	{
		printf("\nTest insert function failed!\n\n");
	}

	free(pList);
}



void testDelete()
{
	Node* pList = NULL;
	Record newData = { "Perry, Katy", "Witness" , "Chained to the Rhythm", "pop", {4, 36}, 3, 5 };
	insertFront(&pList, newData);

	//Now we test deleting this head node
	getchar();
	printf("Please, type \"Chained to the Rhythm\" as a song title in order to test delete function!\n\n");

	deleteRecord(&pList);
	
	if (pList == NULL)
	{
		printf("\nTest delete function passed!\n\n");
	}

	else
	{
		printf("\nTest delete function failed!\n\n");
	}

	free(pList);
}


//Play order = 3, 1, 2.
void testShuffle()
{
	Node* pList = NULL;

	Record data1 = { "Perry, Katy", "Witness" , "Chained to the Rhythm", "pop", {4, 36}, 3, 5 },
		   data2 = { "Brooks, Garth", "FRESH HORSES" , "The Old Stuff", "Country", {2, 57}, 11, 2 },
		   data3 = { "Drake", "NOTHING WAS THE SAME" , "Own it", "Rap", {3, 23}, 3, 3 };
	insertFront(&pList, data3);   //Insert in a opposite order to have a right order because of the property of inserting at front
	insertFront(&pList, data2);
	insertFront(&pList, data1);
	
	
	//Play order = 3, 1, 2
	Portion* pHead = NULL;
	insertFrontPortion(&pHead, 2);   //Insert in a opposite order to have a right order because of the property of inserting at front
	insertFrontPortion(&pHead, 1);
	insertFrontPortion(&pHead, 3);

	shuffleSong(pList, pHead);

	char check = '\0';
	printf("\n\nWere songs 3, 1, 2 played in order?('y' / 'n')  ");
	scanf(" %c", &check);

	if (check == 'y')   //Success
	{
		printf("\nTest shuffle function passed!\n\n");
	}

	else
	{
		printf("\nTest shuffle function failed!\n\n");
	}

	free(pList);
	free(pHead);
}