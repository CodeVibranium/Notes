#include <iostream>
using namespace std;
string sayDidgits(int n, string names[])
{
	string numInDigit = names[n % 10];
	n = n / 10;
	if (n <= 0)
		return numInDigit;
	string prevNumInDigit = sayDidgits(n, names);
	cout << prevNumInDigit << " " << endl;
	return prevNumInDigit + numInDigit;
}

int main()
{

	int n;
	cout << "Enter a number: ";
	cin >> n;
	string names[10] = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
	};

	string finalNum = sayDidgits(n, names);
	cout << "finalNum : " << finalNum << " " << endl;
}