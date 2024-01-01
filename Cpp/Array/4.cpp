// Left Rotate an Array by One
#include <iostream>
#include <vector>
using namespace std;

int main()
{

	vector<int> arr = {4, 0, 3, 2, 5};
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int tmp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = tmp;
	}
	for (auto &num : arr)
	{
		cout << num << " ";
	}
	cout << endl;
}