#include <iostream>
using namespace std;

class Animal
{
public:
	void talks()
	{
		cout << "Yes animal talks" << endl;
	}
};

class Dog : public Animal
{
public:
	void talks()
	{
		cout << "Yes Dog barks" << endl;
	}
};

int main()
{

	Dog lab;
	lab.talks();
}