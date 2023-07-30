#include <iostream>
using namespace std;
int main()
{

	int arrLen;
	cout << "Enter size of the array: ";
	cin >> arrLen;
	int *arr = new int[arrLen];
	cout << endl;
	for (int i = 0; i < arrLen; i++)
	{
		cout << i + 1 << ". Enter a number: ";
		cin >> arr[i];
	}
	cout << endl;
	cout << "numbers you have entered inside the heap are: " << endl;

	for (int i = 0; i < arrLen; i++)
	{
		cout << i + 1 << ")" << arr[i] << " ";
	}
	cout << endl;
}