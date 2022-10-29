
/*
      * Programmer: Duy Pham

      * Class: CptS 122, Fall 2021; Section 01; Lab Section 06

      * Programming Assignment:    PA 8: Data Analysis using Binary Search Trees

      * Date:  November 12, 2021

      * Description: This program implements a system for detecting trends in consumer products over a 48-hour period.
                     The main data structure in this program is a binary search tree. We are going to build two node classes:
                     A Node class is the base case, and the TransactionNode class is te derived class.
                     The tree is going to store the type of products and the number of units that they are sold or purchased.
                     The application would read data.csv file, and insert data into the BST. 
                     Then, find and display the product with the number of units that were most/least sold or purchased.
*/

#include "DataAnalysis.h"

int main(void)
{
    //Allocate the space for the pointer to a DataAnalysis object (Only costs 4 bytes)
    DataAnalysis* pApp = new DataAnalysis;
    
    //Run the analysis
    pApp->runAnalysis();

    //Free up the memory
    delete pApp;

    return 0;     //The program was successfully
}