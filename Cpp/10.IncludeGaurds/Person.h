#pragma once
#include <string>
#include <map>
#include <variant>

using std::map;
using std::string;
using std::variant;

class Person
{

public:
	Person(string gender, float height, float weight, string name) : gender(gender), height(height), weight(weight), name(name){};
	map<string, variant<int, float, string>> getDetails()
	{
		map<string, variant<int, float, string>> personDetails;
		personDetails["gender"] = this->gender;
		personDetails["height"] = this->height;
		personDetails["weight"] = this->weight;
		personDetails["name"] = this->name;
		return personDetails;
	}
	~Person()
	{
		delete this;
	}

private:
	string gender;
	float height;
	float weight;
	string name;
};
