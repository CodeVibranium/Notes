#include <iostream>
using namespace std;
// int **ptr1 = &ptr;
// int ***ptr3 = &ptr2;
// cout << &i << endl;
// cout << ptr << " & " << &ptr << endl;
// cout << ptr2 << " & " << **ptr2 << endl;
// cout << endl;
void update(int **ptr)
{
	// *ptr = *ptr + 1;
	cout << *ptr << endl;
	/* See this expression
	**ptr =**ptr +1;
	this statment says
	RHS get the value at **ptr which would be 5 add 1 = 6
	LHS get the value the address of i but as well checks that
	what type of value that this **ptr of LHS can store if its an int allow else
	throw error
	*
	*ptr =**ptr +1;
	RHS get the value at **ptr which would be 5 add 1 = 6
	LHS *ptr get the value address of i
	but it also checks the *ptr defination on type of value it cans store
	it says *ptr when created store int address but RHS evalutes to int
	so it throws error

	The LHS in both statements tells us not only about the memory location
	we're accessing or modifying but also about the type of value it's expected
	to store. If the RHS produces a different type, the compiler will flag it.
	*/
	// *ptr = **ptr + 1;
}

int main()
{
	int i = 5;
	int *ptr = &i;
	int **ptr2 = &ptr;

	cout << "BEFORE " << i << endl;
	cout << "BEFORE " << ptr << endl;
	cout << "BEFORE " << ptr2 << endl;
	update(ptr2);
	cout << "AFTER " << i << endl;
	cout << "AFTER " << ptr << endl;
	cout << "AFTER " << ptr2 << endl;
}