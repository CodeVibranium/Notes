#include <iostream>
using namespace std;
// USAGE
// 1. They maintain their state between calls to that function.
// 2.
class StaticClass
{
public:
	static int staticvariable;
	static int staticfunction()
	{
		return 4;
	}
};

int StaticClass::staticvariable = 10;
int main()
{
	int StaticVal2 = StaticClass::staticfunction();
}