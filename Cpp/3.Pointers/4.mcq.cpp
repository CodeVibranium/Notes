#include <iostream>
using namespace std;

void update(int **p)
{
	++(**p);
}

int main()
{
	// int i = 0;
	// int *ptr = &i;
	// *ptr = 10;
	// cout << i << endl;
	// ** Done-1
	// int f = 1;
	// int *p = &f;
	// int *q = p;
	// *q++;
	// cout << f << endl;
	// ** Done-2
	// int b = 8;
	// int *p = &b;
	// cout << (*p)++ << endl;
	// cout << b << endl;
	// ** Done-3
	// int *ptr = 0;
	// int f = 10;
	// *ptr = f;
	// because *ptr is referening to anything we will get errpr
	// ** Done-4
	int num = 10;
	int *ptr = &num;
	cout << ptr << " PTR " << endl;
	cout << &ptr << " &PTR " << endl;
	update(&ptr);
	cout << num << " NUM " << endl;
}
