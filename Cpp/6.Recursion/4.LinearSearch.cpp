#include <iostream>
using namespace std;

bool linearSearch(int arr[], int key, int &length, int &index)
{

	if (arr[index] == key)
		return true;
	if (index == length - 1)
		return false;
	index++;
	return linearSearch(arr, key, length, index);
}
int main()
{

	int arr[10] = {1, 3, 5, 7, 2, 4, 8, 9, 0};
	int index = 0;
	int length = sizeof(arr) / sizeof(arr[0]);
	bool found = linearSearch(arr, 120, length, index);
	if (found)
		cout << "Given number is found at " << index << endl;
	else
		cout << "Given number is not found " << endl;
}