#include <iostream>
using namespace std;
class Human
{
public:
	int height;
	int weight;
	int age;
	string name;

protected:
	string mother;
	string father;

private:
	int bodyCount;
};

class Male : public Human
{
public:
	int carsOnwned;
	int hobbies;

	void setMothersName(string name)
	{
		this->mother = name;
	}
	void setFathersName(string name)
	{
		this->father = name;
	}
	string mothersName()
	{
		return mother;
	}
	string fathersName()
	{
		return father;
	}

protected:
	int girlFriends;
};

int main()
{

	Male Shahed;
	Shahed.setMothersName("Shaik Rahamathunnisa");
	Shahed.setFathersName("Mohammed Zahed Ali");
	cout << "FATHERS NAME:" << Shahed.fathersName() << endl;
}