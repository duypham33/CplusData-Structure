

#include "header.h"
#include "testStack.h"
#include "Maze.h"

int main(void)
{
	//Task 1 and 2
	printf("Task 1 and 2)\n");
	testIsEmpty();

	testPush();

	testPop();

	testPeek();
	


	//Task 4
	printf("\nTask 4)\n");
	printf("A random maze was created!\n\n");

	int maze[ROWS][COLS] = { -1 };
	createMaze(maze);
	displayMaze(maze);

	int flag = findMaze(maze);

	if (flag == 1)
	{
		printf("\nPath\n\n");
		displayPath(maze);
	}

	else
	{
		printf("\nNo path to exit the maze!\n");
	}

	return 0;    //The program was successful
}