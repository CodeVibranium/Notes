#include <iostream>
using namespace std;

int selectionSort(int arr[], int length)
{
	int i = 0;
	while (i < length)
	{
		// int smallest = arr[i];
		// ** here i was holding some uncecessary value where i can get that value
		// ** just if i had the index of it.
		int smallstValIdx = i;
		int j = i;
		while (j < length)
		{

			// ** if(arr[j] < smallest)
			// ** Iwas holding this value to do the comparisio n
			// ** But i can do this just by accessing the value at index
			// ** the main reason why i was holding the vaue in the varibale was
			// ** due to diiffence in index varibales.
			// ** but it is not required.
			if (arr[j] < arr[smallstValIdx])
				smallstValIdx = j;
			// ** I was doing this swap at the end of inner loop
			// ** even if dont need it
			// if (j == length - 1)
			// {
			// 	int temp = arr[i];
			// 	arr[i] = smallest;
			// 	arr[smallstValIdx] = temp;
			// }
			j++;
		}

		if (smallstValIdx != i)
		{
			int temp = arr[i];
			arr[i] = arr[smallstValIdx];
			arr[smallstValIdx] = temp;
		}
		i++;
	}
	return 0;
}

int main()
{

	int arr[7] = {15, 28, 21, 4, 140, 9, 6};
	int length = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, length);
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}