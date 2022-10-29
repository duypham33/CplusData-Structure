

#include "header.h"

//Functions definitions

void printArr(vector<int> arr)
{
    if(arr.empty())
        cout << "The array is empty!" << endl;
    else
    {
        for(int i = 0; i < (int) arr.size(); i++)
        {
            cout << arr[i] << " ,  ";
        }

        cout << endl;
    }
}

double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2)
{
    if(arr1.size() <= arr2.size())
        return helper(arr1, arr2);

    else
        return helper(arr2, arr1);
}

double helper(vector<int>& arr1, vector<int>& arr2)
{
    int m = arr1.size(), n = arr2.size();

    int l1 = 0, r1 = m - 1;
    int l2 = 0, r2 = n - 1;
    int mid1 = -1;
    int mid2 = -1;
    double median = 0.0;

    int num_left = ((m + n) % 2 == 0) ? ((m + n) / 2) : ((m + n + 1) / 2);
    if(m == 0)
    {
        if((m + n) % 2 == 0)
            median =  (double) (arr2[num_left - 1] + arr2[num_left]) / 2;
        else
            median =  (double) arr2[num_left- 1];

        cout << "Median: " << median << endl;
        return median;
    }

    while(l1 <= r1)
    {
        mid1 = l1 + (r1 - l1) / 2;
        if(mid1 == num_left - 1)
            break;

        mid2 = -1 + num_left - (mid1 + 1);

        if(arr1[mid1] > arr2[mid2])
        {
            if(mid2 < n - 1 && arr1[mid1] > arr2[mid2 + 1])
                r1 = mid1 - 1;
            else 
                break;
        }

        else   // arr1[mid1] <= arr2[mid2]
        {
            if(mid1 < m - 1 && arr2[mid2] > arr1[mid1 + 1])
                l1 = mid1 + 1;
            else 
                break;
        }
    }

    int endLeft = 0, startRight = 0;
    if(mid1 == num_left - 1)
    {
        cout << "Case 1: ";
        endLeft = arr1[mid1], startRight = arr2[0];
    }

    else if(r1 < 0)
    {
        cout << "Case 2:  ";
        endLeft = arr2[num_left], startRight = arr1[0];
    }

    else if(l1 > m)
    {
        mid2 = -1 + num_left - (mid1 + 1);

        cout << "Case 3:  ";
        endLeft = arr1[mid1], startRight = arr2[mid2 + 1];
    }

    else
    {
        cout << "Case 4:  ";
        endLeft = arr1[mid1], startRight = arr2[mid2 + 1];
    }

    cout << "End left: " << endLeft << " , Start Right: " << startRight << endl;
    cout << endl;

    if((m + n) % 2 == 0)
        median = (double) (endLeft + startRight) / 2;
    else
        median = (double) endLeft;

    cout << "Median: " << median << endl;

    return median;
}