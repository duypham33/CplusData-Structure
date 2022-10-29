
#include "header.h"




Node* makeNode(Contact newData)
{
	Node* pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->data = newData;
		pMem->pNext = NULL;
	}

	return pMem;
}



Boolean insertContactInOrder(Node** pList, Contact newData)
{
	Boolean success = FALSE;

	Node* pMem = makeNode(newData);

	if (pMem != NULL)
	{
		success = TRUE;
		if (*pList == NULL)   //The list is empty, insert at front of the list
		{
			*pList = pMem;
		}

		else
		{
			Node* pCur = *pList;
			Node* pPrev = NULL;

			while (pCur != NULL && strcmp(newData.name, pCur->data.name) >= 0)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			if (pPrev == NULL)   //Insert at front of the list
			{
				pMem->pNext = pCur;
				*pList = pMem;
			}

			else
			{
				pPrev->pNext = pMem;
				pMem->pNext = pCur;
			}
		}
	}

	return success;
}



Boolean deleteContact(Node** pList, Contact searchContact)
{
	Boolean success = FALSE;

	if (*pList != NULL)
	{
		Node* pPrev = NULL;
		Node* pCur = *pList;

		while (pCur != NULL && strcmp(searchContact.name, pCur->data.name) != 0)
		{
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		//if pCur == NULL, means the search contact was not found

		if (pCur != NULL)  //The serach contact is pCur->data
		{
			success = TRUE;

			if (pPrev == NULL)   //Delete at front
			{
				*pList = pCur->pNext;
				free(pCur);
			}

			else
			{
				pPrev->pNext = pCur->pNext;
				free(pCur);
			}
		}
	}

	return success;
}



Boolean editContact(Node* pList, Contact searchContact)
{
	Boolean success = FALSE;

	if (pList != NULL)
	{
		Node* pCur = pList;

		while (pCur != NULL && strcmp(searchContact.name, pCur->data.name) != 0)
		{
			pCur = pCur->pNext;
		}

		//if pCur == NULL, means the search contact was not found

		if (pCur != NULL)  //The serach contact is pCur->data
		{
			success = TRUE;

			printf("Current name: %s", pCur->data.name);
			printf("\nNew name: ");
			gets(pCur->data.name);

		}

	}

	return success;
}




Boolean loadContacts(FILE* infile, Node** pList)
{
	Boolean success = FALSE;

	if (infile != NULL)
	{
		char line[150];    //The string used to read line by line from the file

		while (fgets(line, 150, infile) != NULL)
		{
			Contact newData = { "", "", "", "" };
			//Get the name
			strcpy(newData.name, strtok(line, "\n"));

			//Get the phone number
			fgets(line, 150, infile);
			strcpy(newData.phone, strtok(line, "\n"));

			//Get the email
			fgets(line, 150, infile);
			strcpy(newData.email, strtok(line, "\n"));

			//Get the title
			fgets(line, 150, infile);
			strcpy(newData.title, strtok(line, "\n"));

			success = insertContactInOrder(pList, newData);
		}
	}

	return success;
}



Boolean storeContacts(FILE* outfile, Node* pList)
{
	Boolean success = FALSE;

	if (pList == NULL)
	{
		fprintf(outfile, "The list is empty!\n");
	}

	else
	{
		Node* pCur = pList;

		while (pCur != NULL)
		{
			fprintf(outfile, "%s\n%s\n%s\n%s\n", pCur->data.name, pCur->data.phone, pCur->data.email, pCur->data.title);
			pCur = pCur->pNext;
		}

		success = TRUE;
	}

	return success;
}



void printList(Node* pList)
{
	if (pList == NULL)
	{
		printf("The list is empty!\n");
	}

	else
	{
		Node* pCur = pList;

		while (pCur != NULL)
		{
			printf("%s, %s, %s, %s", pCur->data.name, pCur->data.phone, pCur->data.email, pCur->data.title);
			pCur = pCur->pNext;
			
			if (pCur != NULL)
			{
				printf("\n\t\t|\n\t\tV\n");
			}
		}
	}
}




void display_menu()
{
	printf("   MENU\n");
	printf("1. Add in order\n");
	printf("2. Delete\n");
	printf("3. Edit\n");
	printf("4. Print\n");
	printf("5. Load\n");
	printf("6. Store\n");
	printf("7. Exit\n");
}


void runApp(Node* pList)
{
	int opt = 0;

	do
	{
		display_menu();

		printf("\nPlease, enter your option(1-7): ");
		scanf("%d", &opt);

		system("cls");

		if (opt == 1)
		{
			Contact newData = { "", "", "", "" };
			printf("Please, fill in a contact that you would like to add:\n");
			getchar();
			printf("Name: ");   gets(newData.name);
			printf("Phone(no more than 11 numbers): ");   gets(newData.phone);
			printf("Email: ");   gets(newData.email);
			printf("Title: ");   gets(newData.title);

			insertContactInOrder(&pList, newData);
		}

		else if (opt == 2)
		{
			Contact searchData = { "", "", "", "" };
			printList(pList);
			printf("\n\nPlease, enter the name of the contact that you would like to delete: ");
			getchar();
			gets(searchData.name);
			

			deleteContact(&pList, searchData);
			printf('\n\n');
			printList(pList);
		}

		else if (opt == 3)
		{
			Contact searchData = { "", "", "", "" };
			printList(pList);
			getchar();
			printf("\n\nPlease, enter the name that you would like to edit: ");
			gets(searchData.name);

			editContact(pList, searchData);
			printf('\n\n');
			printList(pList);
		}


		else if (opt == 4)
		{
			printList(pList);
		}

		else if (opt == 5)
		{
			FILE* infile = NULL;

			infile = fopen("Contacts.txt", "r");

			loadContacts(infile, &pList);

			printList(pList);

			fclose(infile);
		}

		else if (opt == 6)
		{
			FILE* outfile = NULL;

			outfile = fopen("Contacts.txt", "r");

			storeContacts(outfile, pList);

			printList(pList);

			fclose(outfile);
		}

		printf("\n\n****************************************************\n");
		printf("Please, hit the enter to return the main menu!");
		getch();
		system("cls");

	} while (opt != 7);
}
