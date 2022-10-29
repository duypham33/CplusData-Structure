
/*
      * Programmer: Duy Pham

      * Class: CptS 122, Fall 2021; Section 01; Lab Section 06

      * Programming Assignment:    Lab 2: Data Structures and Dynamic Singly Linked Lists in C

      * Date:       Sep 9, 2021

      * Description: This program

*/

#include "header.h"


int main(void)
{

    //Node* pList = NULL;

    //Contact data1 = { "Kenndy", "01836456277", "kenbo@gmail.com", "Ma" },
    //    data2 = { "Geogre", "03846239874", "geogre@gmail.com", "Prof" },
    //    data3 = { "Anna", "01236458910", "mariaan@gmail.com", "Doc" },
    //    data4 = { "Kenndy", "04962578622", "kennari@gmail.com", "Doc" },
    //    data5 = { "Anna", "07789523788", "annae@gmail.com", "Ceo" };


    //insertContactInOrder(&pList, data1);
    //insertContactInOrder(&pList, data2);
    //insertContactInOrder(&pList, data3);
    //insertContactInOrder(&pList, data4);
    //insertContactInOrder(&pList, data5);
    ////printList(pList);

    ///*printf("\n\nAfter delete: \n");
    //Contact searchData = { "", "", "", "" };
    //printf("\n\nPlease, enter the name of the contact that you would like to delete: ");
    //gets(searchData.name);
    //printf("%s\n", searchData.name);

    //strcpy(searchData.name, "Geogre");
    //deleteContact(&pList, searchData);
    //deleteContact(&pList, data2);
    //printList(pList);*/

    ///*printf("\n\n\nEdit:\n");
    //editContact(pList, data4);
    //printList(pList);*/



    //Contact searchData = { "", "", "", "" };
    //printList(pList);
    //getchar();
    //printf("\n\nPlease, enter the name of the contact that you would like to delete: ");
    //gets(searchData.name);


    //deleteContact(&pList, searchData);
    //printf('\n\n');
    //printList(pList);


    ///*printf("\nContact\n");

    //FILE* infile = NULL;

    //infile = fopen("Contacts.txt", "r");

    //loadContacts(infile, &pList);

    //printList(pList);

    //fclose(infile);*/


    ////runApp(pList);

	
    LNODE* pNode = NULL;

    pNode = (LNODE*)malloc(sizeof(LNODE));
    //printf("Hello");
    strcpy(pNode->pData, "Test item");
    printf("Hello");
    puts(pNode->pData);
    printf("Hello");

	return 0;    //The program was successful
}