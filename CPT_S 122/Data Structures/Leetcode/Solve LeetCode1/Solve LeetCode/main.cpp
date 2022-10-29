
#include "header.h"


std::ostream& operator << (std::ostream& lhs, vector<int> rhs);
char nextGreatestLetter(vector<char>& letters, char target);
int num_recur_comp = 0;

int main(void)
{
    /*vector<char> letters = { 'c', 'f', 'j' };
    char target = 'j';
    cout << nextGreatestLetter(letters, target) << endl;*/
   

	return 0;   //The program was successfull
}


std::ostream& operator << (std::ostream& lhs, vector<int> rhs)
{
    int size = rhs.size();
    if (size == 0)
        cout << "The array is empty!" << endl;
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << rhs[i] << "   ";
        }
        cout << endl;
    }

    return lhs;
}

char nextGreatestLetter(vector<char>& letters, char target)
{
    int size = letters.size();
    int l = 0, r = size - 1;
    if (target >= letters[r] || target < letters[0])
        return letters[0];
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (letters[mid] <= target && letters[mid + 1] > target)
            return letters[mid + 1];
        else if (letters[mid] <= target && letters[mid + 1] <= target)
            l = mid + 1;
        else if (letters[mid] > target && letters[mid - 1] <= target)
            return letters[mid];
        else
            r = mid;
    }

    return letters[l];
}

