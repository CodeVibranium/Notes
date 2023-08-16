#include <iostream>
using namespace std;

void merge(int arr[], int start, int middle, int end)
{
	cout << "JUST ENTERED: start " << start << " Middle " << middle + 1 << " end " << end << endl;
	for (int i = 0; i <= end; i++)
		cout << arr[i] << " , ";
	cout << endl;
	int mid = middle;
	int arrCopy[end + 1];
	int index = 0;
	while (start < middle)
	{
		cout << "LOOP: start " << start << " Middle " << middle + 1 << " end " << end << endl;
		if (arr[mid] > arr[start])
		{
			arrCopy[index] = arr[start];
			start++;
		}
		else
		{
			arrCopy[index] = arr[mid];
			mid++;
		}
		index++;
	}
	mid = index;
	cout << "INDEX: " << mid << endl;
	index = 0;
	while (index < mid)
	{
		arr[index] = arrCopy[index];
		index++;
	}
	cout << "FINAL: " << endl;
	for (int i = 0; i <= end; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

void mergeSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int middle = start + end / 2;
	mergeSort(arr, start, middle);
	mergeSort(arr, middle + 1, end);
	merge(arr, start, middle, end);
}

int main()
{

	int arr[5] = {1, 2, 3, 1, 4};
	int end = (sizeof(arr) / sizeof(arr[0])) - 1;
	int start = 0;
	int middle = ((start + end) / 2) + 1;
	// merge(arr, start, middle, end);
	mergeSort(arr, start, end);
	for (int i = 0; i <= end; i++)
		cout << arr[i] << ' ';
	cout << endl;
}