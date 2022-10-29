
#include <vector>

using std::vector;

template<typename T>
class Sort
{
public:
	void mergeSort(vector<T>& arr)
	{
		int size = arr.size();
		if (size > 1)
			this->mergeSort(arr, 0, size - 1);
	}

private:
	void mergeSort(vector<T>& arr, int l, int r)
	{
		//Base case
		if (l == r)
			return;

		//Slipt the array into two sub-arrays
		int mid = l + (r - l) / 2;    // r - l to avoid overflow
		//Merge two sub-arrays(left and right)
		this->mergeSort(arr, l, mid);
		this->mergeSort(arr, mid + 1, r);

		//Merge two sorted sub-arrays into one 
		if (arr[mid + 1] > arr[mid])   //This would improve the best case
			return;

		vector<T> subLeft = {arr.begin() + l, arr.begin() + mid + 1};   //An temp array for containing the left sub-array
		int size = mid - l + 1;

		int cur1 = 0, cur2 = mid + 1;
		for (int i = l; i <= r; i++)
		{
			if (cur1 >= size)
				break;
			if (cur2 <= r && arr[cur2] < subLeft[cur1])
				arr[i] = arr[cur2++];
			else
				arr[i] = subLeft[cur1++];
		}

		//Clear the temp vector after merge
		subLeft.clear();
	}
};