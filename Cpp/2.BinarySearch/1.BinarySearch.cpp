#include <iostream>
using namespace std;
int main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length = sizeof(arr) / sizeof(arr[0]);
	int start = 0;
	int end = length;

	int target;
	cout << "Enter the number to find: ";
	cin >> target;
	int middle;
	while (start < end)
	{
		middle = (start + end) / 2;
		cout << "Start: " << start << " End: " << end << " Middle: " << middle << endl;
		if (target == arr[middle])
			break;
		else if (arr[middle] < target)
			start = middle + 1;
		else
			end = middle - 1;
	}
	if (start != end)
		cout << "Target " << target << " was found at " << middle << " index" << endl;
	else
		cout << "Target " << target << " was not found in the given array" << endl;
}