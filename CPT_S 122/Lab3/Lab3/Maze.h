
#ifndef MAZE_H //guard code

#define MAZE_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()


#include<stdio.h>    //necessary to use printf() and scanf()

#include<stdlib.h>   //necessary to use malloc() and free()


//The size of the maze
#define ROWS 4
#define COLS 5



typedef struct point
{
	int row;
	int col;
} Point;



typedef struct node
{
	Point cell;
	struct node* pNext;
} Node;



int is_empty(Node* pTop);



int pushCell(Node** pTop, Point newCell);


void popCell(Node** pTop);


void createMaze(int maze[ROWS][COLS]);


void displayMaze(int maze[ROWS][COLS]);

int findMaze(int maze[ROWS][COLS]);

void displayPath(int maze[ROWS][COLS]);

#endif
