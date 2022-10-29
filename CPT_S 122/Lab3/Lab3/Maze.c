

#include "Maze.h"




int is_empty(Node* pTop)
{
	return ((pTop == NULL) ? 1 : 0);
}



int pushCell(Node** pTop, Point newCell)
{
	int success = 0;

	//Allocate memory dynamically
	Node* pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		//The memmory has been available
		pMem->cell = newCell;
		pMem->pNext = *pTop;

		*pTop = pMem;
		success = 1;
	}

	return success;
}


void popCell(Node** pTop)
{
	if (isEmpty(*pTop) == 0)   //The stack is not empty
	{
		//Delete at front of the stack
		Node* pFront = *pTop;
		*pTop = pFront->pNext;
		free(pFront);    //Free memory up 
	}
}




void createMaze(int maze[ROWS][COLS])
{
	//Random values for the cells
	srand((unsigned int)time(NULL));
	
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			//A wall may be represented by a 0 and a door may be represented by a 1
			maze[i][j] = rand() % 2;
		}
	}

	//The starting point is (0, 0) and ending point is (ROWS-1, COLS-1). So they should be a door represented by a 1
	maze[0][0] = 1;
	maze[ROWS - 1][COLS - 1] = 1;
}


void displayMaze(int maze[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		printf("  ");

		for (int j = 0; j < COLS; j++)
		{
			//A wall may be represented by a 0 and a door may be represented by a 1
			printf("%d  ", maze[i][j]);
		}

		printf("\n");
	}
}



int findMaze(int maze[ROWS][COLS])
{
	//Declare an empty stack for finding the path out of the maze
	Node* pStack = NULL;

	/*
	   Whenever a fork in the maze is encountered, store the coordinates of 
	   the fork on the stack. If the current path does not provide a path to the end of the maze, 
	   then the last forking point can be popped and a different path may be taken.
	*/

	int row = 0;   
	int col = 0;

	//Push the starting point into the stack 
	Point cell = { row, col };
	pushCell(&pStack, cell);

	//The cell was in the target path
	maze[row][col] = 2;

	do
	{
		//Find the below cell
		if (row + 1 < ROWS && maze[row + 1][col] == 1)   //A door
		{
			row++;
			cell.row = row;
			cell.col = col;
			pushCell(&pStack, cell);

			//The cell was in the target path
			maze[row][col] = 2;
		}

		//Find the right cell
		else if (col + 1 < COLS && maze[row][col + 1] == 1)   //A door
		{
			col = col++;
			cell.row = row;
			cell.col = col;
			pushCell(&pStack, cell);

			//The cell was in the target path
			maze[row][col] = 2;
		}

		//Find the left cell
		else if (col - 1 < COLS && maze[row][col - 1] == 1)   //A door
		{
			col = col - 1;
			cell.row = row;
			cell.col = col;
			pushCell(&pStack, cell);

			//The cell was in the target path
			maze[row][col] = 2;
		}

		//Find the above cell
		else if (row - 1 < ROWS && maze[row - 1][col] == 1)   //A door
		{
			row = row - 1;
			cell.row = row;
			cell.col = col;
			pushCell(&pStack, cell);

			//The cell was in the target path
			maze[row][col] = 2;
		}

		else
		{
			popCell(&pStack);
			maze[row][col] = 3;  //Cannot find path here
		}

	} while ((row != ROWS - 1 || col != COLS - 1) && is_empty(pStack) == 0);

	int flag = 1;
	if (is_empty(pStack) == 1)
	{
		flag = 0;  //No path
	}

	return flag;
}



void displayPath(int maze[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		printf("  ");

		for (int j = 0; j < COLS; j++)
		{
			//A wall may be represented by a 0 and a door may be represented by a 1
			printf("%c  ", (maze[i][j] != 2 && maze[i][j] != 1) ? 'X' : '*');
		}

		printf("\n");
	}
}

