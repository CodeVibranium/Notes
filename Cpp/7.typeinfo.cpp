#include <iostream>
#include <any>
#include <typeinfo>
using namespace std;
int main()
{
	any someData = 42;
	const type_info &typeOfSomeData = someData.type();
	if (typeOfSomeData == typeid(int))
		cout << "Data is of type int" << any_cast<int>(someData) << endl;
	// u need to declare a newVariable tomknow the type if type everchages

	// someData = "hellow";
	// typeOfSomeData = someData.type();
	// if (typeOfSomeData == typeid(string))
	// 	cout << "Data is of type string" << any_cast<string>(someData) << endl;
	// someData = 1.234543;
	// typeOfSomeData = someData.type();
	// if (typeOfSomeData == typeid(double))
	// 	cout << "Data is of type double" << any_cast<double>(someData) << endl;
	// someData = false;
	// typeOfSomeData = someData.type();
	// if (typeOfSomeData == typeid(bool))
	// 	cout << "Data is of type double" << any_cast<bool>(someData) << endl;
	// typeOfSomeData = someData.type();

	return 0;
}