#include <iostream>
using namespace std;

void binarySearch(int arr[], int &key, int end, int start = 0)
{
	int mid = start / end;
	if (arr[mid] == key)
		return mid;
	binarySearch(arr, key, )
}
int main()
{
	int key;
	cout << "Enter the element you want to find: ";
	cin >> key;
	int arr[10] = {2, 3, 5, 7, 9, 11, 13, 23, 24, 26};
	int length = sizeof(arr) / sizeof(arr[0]);
	binarySearch(arr, key, length);
}