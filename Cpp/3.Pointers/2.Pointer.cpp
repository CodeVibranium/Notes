#include <iostream>
using namespace std;

int main()
{
	int num = 10;
	int *ptr;
	int *numPoi = &num;
	// int *addrOfNumPoi= &numPoi;
	cout << "Address of num variable is" << &num << endl;
	cout << "Pointer *numPoi of pointing at " << numPoi << endl;
	cout << "Value stored in numPoin is " << *numPoi << endl;
	cout << "Address of pointer numPoin varibale is " << &numPoi << endl;
	cout << "Size of Pointer numPoin is" << sizeof(numPoi) << endl;
	cout << "POINTER Addition by 1" << endl;
	numPoi += 1;
	cout << "Pointer numPoi after incrementing by1 is pointing at: " << numPoi << endl;
	cout << "Value of Pointer numPoi after incrementing by is: " << *numPoi << endl;
	cout << "Address of  numPoi after incrementing by1 is pointing at: " << &numPoi << endl;
	cout << "POINTER Addition by 1" << endl;
	numPoi *= 1;
	cout << "Pointer numPoi after incrementing by1 is pointing at: " << numPoi << endl;
	cout << "Value of Pointer numPoi after incrementing by is: " << *numPoi << endl;
	cout << "Address of  numPoi after incrementing by1 is pointing at: " << &numPoi << endl;
}