#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVec = {1, 2, 3};
	myVec.push_back(1);
	myVec.insert(myVec.begin() + 3, 19);
	// myVec.assign()
	cout << "Size of vector " << myVec.size() << endl;
	cout << "Front of vector " << myVec.front() << endl;
	vector<int> vec = myVec;
	for (int x : myVec)
		cout << x << " ";
	cout << endl;
	return 0;
}