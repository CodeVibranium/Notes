// You have been given an array a of n  non-negative integers.You have to check whether the given array
// is sorted in the non-decreasing order or not.
// Your task is to return 1 if the given array is sorted. Else, return 0.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr = {1, 2, 3, 11, 5, 6};
	int sorted = 1;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			sorted = 0;
			break;
		}
	}
	cout << "Sorted: " << sorted << endl;
}