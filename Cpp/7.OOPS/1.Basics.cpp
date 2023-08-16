#include <iostream>
using namespace std;

class Hero
{

private:
	int health;
	int warsFought;
	int wives;
	int children;

public:
	string name;
	int level;
	int accolades_count;
	// Normal construcotr
	// Hero()
	// {
	// 	cout << "****Constructor called****" << endl;
	// 	cout << "this keyword stores the address of the cureent object" << endl;
	// }
	// paramterized constructor
	Hero(int health = 5, int warsFought = 6, int wives = 90, int children = 9000)
	{
		this->health = health;
		this->children = children;
		this->wives = wives;
		this->warsFought = warsFought;
	}

	int getHealth()
	{
		return health;
	}
	int getWarsFought()
	{
		return health;
	}
	int getWives()
	{
		return health;
	}
	int getChildren()
	{
		return health;
	}
	int setHealth(int newHealth)
	{
		health = newHealth;
		return health;
	}
};

int main()
{

	// creation of object
	// static allocation
	Hero h12;
	Hero h1(1, 2, 3, 4);
	cout << "SIZE of object hero is " << sizeof(h1) << endl;
	cout << "Size of an object would be the sum of size of all variables" << endl;
	cout << "By default size of an empty object would be  1 byte" << endl;
	cout << "ACCESS MODIFIERS" << endl;
	cout << "Level " << h1.level << endl;
	cout << "Private var health " << h1.getHealth() << endl;

	// Dynamic Allocation
	Hero *noob = new Hero(2, 4, 6, 8);
	cout << "DYNAMIC ACCESS can be done by ->" << endl;
	cout << "Noob Cyber health: " << (*noob).getHealth() << endl;
	cout << "Noob Cyber wives: " << noob->getHealth() << endl;
	cout << "Noob Cyber Children: " << noob->getChildren() << endl;

	cout << "Constructor" << endl;
	cout << "Called when creating the object" << endl;
	cout << "By default there is a constructor" << endl;

	return 0;
}