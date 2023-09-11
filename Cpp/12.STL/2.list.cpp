#include <iostream>
#include <list>
using namespace std;

void print(list<int> &myList)
{
	for (int x : myList)
		cout
			<< x << " => ";
	cout << "NULL" << endl;
}
int main()
{

	int data = 10;
	list<int> myList;
	list<int> myList2(2, 1);
	for (int x : myList)
		cout << x << " => ";
	cout << "NULL" << endl;

	print(myList2);
	myList2.assign(3, 5);
	print(myList2);
	myList2.emplace_back(20);
	print(myList2);
	myList2.emplace_front(210);
	print(myList2);
	myList2.swap(myList);
	print(myList2);
	print(myList);
	myList.sort();
	print(myList);
	// myList.remove(5);
	// print(myList);
	myList.unique();
	print(myList);

	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	myList.push_back(40);
	myList.push_back(50);
	myList.push_front(11);
	// for (int x : myList)
	// 	cout << x << " => ";
	// cout << "NULL" << endl;
}