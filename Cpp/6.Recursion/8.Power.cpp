#include <iostream>
using namespace std;

int Power(int n, int power, int multiplied = 1)
{

	if (power == 0)
		return multiplied;
	multiplied *= n;
	power--;
	return Power(n, power, multiplied);
}

int PowerOP(int n, int power)
{
	if (power == 0)
		return 1;
	return n * PowerOP(n, power - 1);
}

int main()
{

	int n, power;
	cout << "Enter a number: ";
	cin >> n;
	cout << "Enter the exponent: ";
	cin >> power;
	int powered = Power(n, power);
	cout << n << " to the power of " << power << " is " << powered << endl;
}