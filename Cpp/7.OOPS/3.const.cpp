#include <iostream>
using namespace std;
class Point
{
public:
	Point(int x, int y, string graphName) : x(x), y(y), graphName(graphName) {}
	// By declaring this function as const member function, i'm telling
	// 1.That this function will not modify the object's state.
	// 2.Anyone reading the code immediately understands that this function is used only for reading information,
	double DistanceFromOrigin() const
	{
		return sqrt(x * x + y * y);
	}
	const string &getName()
	{
		return graphName;
	}

private:
	int x, y;
	string graphName;
};

class Area
{

public:
	Area(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int area()
	{
		return 2 * (x + y);
	}

private:
	int x, y;
};
int main()
{
	cout << "P1 Class declared without using `const`" << endl;
	Point p1(2, 3, "ABC");
	string myPointP1Name = p1.getName();
	cout << "myPointP1Name BEFORE: " << myPointP1Name << endl;
	myPointP1Name = "SHAHED";
	cout << "myPointP1Name AFTER: " << myPointP1Name << endl;
	cout << "myPointP1Name AFTER: " << p1.getName() << endl;
	double distanceP1 = p1.DistanceFromOrigin();
	cout << "Distance from origin : " << distanceP1 << endl;
	cout << "P2 Class declared using `const`" << endl;
	const Point p2(3, 3, "DEF");
	double distanceP2 = p1.DistanceFromOrigin();
	cout << "Distance from origin : " << distanceP2 << endl;
	Area rectangle(2, 3);
	int area = rectangle.area();
}
