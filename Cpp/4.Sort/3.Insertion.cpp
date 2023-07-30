#include <iostream>
using namespace std;
int i = 1;
int insertionSort(int arr[], int length)
{
	int startIndex = 1;
	while (startIndex < length)
	{
		if (arr[startIndex] < arr[startIndex - 1])
		{
			int sortedIndex = startIndex - 1;

			while (0 <= sortedIndex)
			{
				cout << "sortedIndex: " << sortedIndex << " I: " << i << endl;
				if (arr[sortedIndex] > arr[sortedIndex + 1])
				{
					int temp = arr[sortedIndex];
					arr[sortedIndex] = arr[sortedIndex + 1];
					arr[sortedIndex + 1] = temp;
				}
				// else if (arr[sortedIndex] < arr[sortedIndex + 1])
				// {
				// 	break;
				// }
				sortedIndex--;
				i++;
			}
		}
		startIndex++;
	}
	return 0;
}
int main()

{
	// int arr[6] = {23, 42, 4, 16, 8, 15};
	// int arr[7] = {1, 2, 3, 4, 5, 6, 7};
	// int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	// int arr[6] = {5, 5, 5, 5, 5, 5};
	int arr[5] = {1000000, 500000, 250000, 125000, 62500};
	// int arr[7] = {3, -7, 0, 5, -2, 8, -1};
	// int arr[9] = {4, 3, 4, 1, 5, 3, 2, 2, 5};
	// int arr[1] = {42};
	int length = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, length);
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}