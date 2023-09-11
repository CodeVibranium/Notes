#include <iostream>
using namespace std;
/*
namespace is an identifier that allows you ti group identifiers under a single name
identifies can be (variable, functions, classes etc...)

*/

namespace MyOwnNameSpace
{
	int x = 10;
	string relaization = "yes this is my own name space";
	namespace insideMyOwn
	{
		string innerSelf = "This is my innser self namespace";
	}

}

string innerSelf = "This is my innser self namespace but it is outer";
using namespace MyOwnNameSpace::insideMyOwn;

int main()
{

	cout << "My relaization is: " << MyOwnNameSpace::relaization << endl;
	cout << "And innserself from global scope be: " << ::innerSelf << endl;
	cout << "And innserself from namespace scope be: " << innerSelf << endl;

	return 0;
}