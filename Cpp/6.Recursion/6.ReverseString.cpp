#include <iostream>
using namespace std;

string reverseStr(string name, int length, string reverseName = "")
{
	length--;
	reverseName += name[length];
	if (length == 0)
		return reverseName;
	return reverseStr(name, length, reverseName);
}
int main()
{
	string name;
	cout << "Enter your name: ";
	cin >> name;
	name = reverseStr(name, name.length());
	cout << "Reverse of your name is : " << name << endl;
}