#include <iostream>
using namespace std;

int fibonacci(int &n, int index, int lastVal, int addedVal)
{
	if (index == 0)
		lastVal = 0;
	else if (index == 1)
		lastVal = 1;
	index++;
	cout << "Before: lastVal :" << lastVal << endl;
	addedVal = addedVal + lastVal;
	cout << "addedVal :" << addedVal << endl;
	lastVal = addedVal;
	cout << "After lastVal :" << lastVal << endl;
	return fibonacci(n, index, lastVal, addedVal);
}

int main()
{
	int n, fib;
	cout << "Enter a number: ";
	cin >> n;
	fib = fibonacci(n, 0, 0, 0);
	cout << "Fibonnaci at " << n << "is: " << fib << endl;
}