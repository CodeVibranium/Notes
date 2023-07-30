#include <iostream>
using namespace std;
int main()
{
	int arr[10] = {1, 5, 3, 4, 5, 6, 7, 8, 9};
	cout << "Value stored in variable arr " << arr << endl;
	cout << "Address of index 0 " << &arr[0] << endl;
	cout << "&arr " << &arr << endl;
	cout << "&arr+1 would be = &arr[1] " << arr + 1 << " &arr[1] " << &arr[1] << endl;
	cout << "Dereferencing means give the the value stored in that location " << endl;
	cout << "Deferencing Arr => " << *arr << endl;
	cout << "Deferencing Arr+1 => " << *(arr + 1) << endl;
	cout << "arr[i] would eval to *(arr+i) " << endl;
	cout << "i[arr](0[arr]) : " << 5 [arr] << " bcz eval to *(arr+i) " << endl;
	cout << "In simple words &arr[0] == &arr == arr " << endl;
}