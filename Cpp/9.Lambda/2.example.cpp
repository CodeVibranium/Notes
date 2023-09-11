#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "Enter a value for A: ";
	cin >> a;

	auto doSomething = []()
	{ cout << "Doing something" << endl; };
	doSomething();
	function<void(int)> lambdaFunc;
	lambdaFunc = [&lambdaFunc](int a) -> void
	{
		cout << "Enterd no is " << a << endl;
		a = a * 10;
		cout << "A 10x would be " << a;
		lambdaFunc(a);
	};
}