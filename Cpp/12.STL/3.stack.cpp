#include <iostream>
#include <stack>

using namespace std;

int main()
{

	stack<int> myStack;
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	myStack.push(6);
	myStack.push(7);
	cout << (myStack.empty() ? "Stack is Empty" : "Stack is not empty") << endl;
	cout << "Size of myStack is " << myStack.size() << endl;
	cout << "Top element at myStack is" << myStack.top() << endl;
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();
	cout << (myStack.empty() ? "Stack is Empty" : "Stack is not empty") << endl;
	cout << "Size of myStack is " << myStack.size() << endl;
	cout << "Top element at myStack is" << myStack.top() << endl;
	// After this we get segmentation fault
	// myStack.pop();
	// myStack.pop();
	// myStack.pop();
	// myStack.pop();
	// cout << (myStack.empty() ? "Stack is Empty" : "Stack is not empty") << endl;
	// cout << "Size of myStack is " << myStack.size() << endl;
	// cout << "Top element at myStack is" << myStack.top() << endl;
}