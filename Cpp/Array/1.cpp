// Find largestElement using o(n)
#include <iostream>
#include <vector>
using namespace std;

int main()
{

	vector<int> arr = {4, 7, 8, 6, 7, 6};
	int bigNum = arr[0];
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > bigNum)
			bigNum = arr[i];
	}
	cout << "Big number inside the array is: " << bigNum;
}