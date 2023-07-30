#include <iostream>
using namespace std;

int bubbleSort(int arr[], int length)
{
	bool anySwaps = false;
	int i = 0;
	while (i < length)
	{
		int j = 0;
		while (j < length)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				anySwaps = true;
			}
			j++;
		}
		if (anySwaps == false)
			break;

		length -= 1;
	}
	return 0;
}
int main()
{

	int arr[10] = {1, 4, 3, 5, 9, 11, 22, 12, 18, 0};
	int length = sizeof(arr) / sizeof(arr[0]) - 1;
	cout << "BEFORE" << length << endl;
	bubbleSort(arr, length);
	cout << "AFTER" << length << endl;
	for (int i = 0; i <= length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}