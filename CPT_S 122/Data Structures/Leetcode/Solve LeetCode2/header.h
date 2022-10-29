


#ifndef HEADER_H   //guard code
#define HEADER_H

#include <iostream>
#include <vector>
//#include <set>


using std::cout;
using std::endl;
using std::vector;


//Function prototypes
void printArr(vector<int> arr);

double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2);

double helper(vector<int>& arr1, vector<int>& arr2);


#endif