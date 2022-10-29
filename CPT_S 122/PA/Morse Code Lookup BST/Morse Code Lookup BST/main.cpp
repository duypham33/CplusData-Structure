
/*
      * Programmer: Duy Pham

      * Class: CptS 122, Fall 2021; Section 01; Lab Section 06

      * Programming Assignment:    PA 6: Morse Code Lookup BST

      * Date:  October 24, 2021

      * Description: This program constructs a template BST to convert English characters to Morse code strings.
                     This create a template BSTNode class with two different generic types for data members and the two child pointers(left and right).
                     Then, the BST class are implemented with a root node as a data members and some operations like insert, print, search and convert. 
                     The constructor of BST class allows to read Morse table from the "MorseTable.txt" file and then insert all symbols and morse code
                     into the BST. Then, use it to convert the content of the "Convert.txt" file from English characters into Morse code strings.
*/

#include "BST.h"
#include <string>

using std::string;

int main(void)
{
    //Declare a pointer to the main BST of the application with template <char, string> (char for symbol characters, string for corresponding morse code)
    BST<char, string>* pBstTree = new BST<char, string>;
    
    //Run the application
    pBstTree->MorseCodeConvertion();

    //Destroy the tree, free the space up
    delete pBstTree;

    return 0;    //The program was successful
}