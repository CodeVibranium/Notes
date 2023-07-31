#include <iostream>
using namespace std;

bool isArraySorted(int arr[], int &length, int index = 0)
{
	cout << index << ": " << endl;
	if (index == length - 1)
		return true;
	else if (arr[index] <= arr[index + 1])
		index++;
	else if (arr[index] > arr[index + 1])
		return false;
	bool isSorted = isArraySorted(arr, length, index);
	return isSorted;
}

int main()
{
	int arr[6] = {2, 4, 6, 3, 11, 13};
	int length = sizeof(arr) / sizeof(arr[0]);
	string isSorted = to_string(isArraySorted(arr, length));
	cout << "The given array is " << isSorted << endl;
}