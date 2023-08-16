#include <iostream>
using namespace std;
/*
0. Sorts an array by default in it ascending order.
1. Pick a pivot from the array (any element; consider first)
2. Place the pivot in its correct position inside the sorted array.
3. Then smaller elements on the left
4. Greater elements larger elements on the right
5. After placing elements u will find
*/
/*
How do u place pivot at its correct position?
1. Take two variable high(len-1) and low(0) where pivot would arr[low]
2. Placing the pivot
3. Take a pointer i which would be left most part and pointer j would be at right most part
4. Find the element greater than the piviot
5. once found move i twowards right
6. Find the element which is lower than the piviot
7. once found move j towards left side.
8. once done swap(i,j);
9. Repeat from point 4 unless (i &j) cross each other.
10. when j crossed i swap(pivot, j),
11. After doing this u will find out that the left part of the piviot
is smaller than the piviot and right side is greater than the pivot

*/

int partition(int arr[], int low, int high)
{

	int pivot = arr[low];
	int i = low;
	int j = high;
	while (i < j)
	{

		while (i < high && arr[i] <= pivot)
			i++;
		while (j > low && arr[j] >= pivot)
			j--;

		// while (i < high)
		// {
		// 	if (arr[i] > pivot)
		// 		break;
		// 	i++;
		// }
		// while (j > low)
		// {
		// 	if (arr[j] < pivot)
		// 		break;
		// 	j--;
		// }
		if (i < j)
		{
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	arr[low] = arr[j];
	arr[j] = pivot;
	return j;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int prtIdx = partition(arr, low, high);
		quickSort(arr, low, prtIdx - 1);
		quickSort(arr, prtIdx + 1, high);
	}
}

int main()
{

	int arr[9] = {4, 6, 2, 5, 7, 9, 1, 3, 2};
	int low = 0;
	int high = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, low, high - 1);
	for (int i = 0; i < high; i++)
		cout << arr[i] << ' ';
	cout << endl;
}