// Find the second largest and second smallest element from the array.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// vector<int> arr = {4, 5, 3, 6, 7, 1, 2, 0, 8};
	vector<int> arr = {3, 4, 5, 2};

	// = 1, 2, 3, 4, 5, 6, 7
	int len = arr.size();
	int smallest = INT_MAX;
	int secondSmallest = INT_MAX;
	int largest = INT_MIN;
	int secondLargest = INT_MIN;
	int i = 0;
	int j = len - 1;
	while (i < arr.size())
	{
		if (secondSmallest > arr[i])
		{

			int tmp = smallest;
			smallest = arr[i];
			secondSmallest = tmp;
			if (arr[i] > secondSmallest)
			{
				int tmp = smallest;
				smallest = secondSmallest;
				secondSmallest = tmp;
			}
			cout << "Smallest: " << smallest << " Second smallest: " << secondSmallest << endl;
		}
		else
		{
			int tmp = largest;
			largest = arr[i];
			secondLargest = tmp;
			cout << "Largest: " << smallest << " Second smallest: " << secondSmallest << endl;
		}
		i++;
	}
	cout << "LAST: Smallest: " << smallest << " Second smallest: " << secondSmallest << endl;
	cout << "LAST: Largest: " << largest << " Second Largest: " << secondLargest << endl;
}
