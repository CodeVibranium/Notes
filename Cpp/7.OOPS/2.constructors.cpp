#include <iostream>
using namespace std;

class Point
{

public:
	// Default Constructor
	Point()
	{
		cout << "Default Constructor invoked" << endl;
	}
	// Paramterized constructor
	Point(int x, int y)
	{
		cout << "Paramterized Constructor invoked" << endl;
		this->x = x;
		this->y = y;
	}

	Point(const Point &point)
	{
		this->x = point.x;
		this->y = point.y;
	}
	~Point()
	{
		cout << "De-Constructor invoked" << endl;
	}

private:
	int x;
	int y;
};

int main()
{
	cout << "Static memory allocation" << endl;
	Point p1(1, 2);
	cout << "Dynamic memory allocation" << endl;
	Point *p2 = new Point(1, 2);
	delete p2;
	return 0;
}
/*
