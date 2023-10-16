// Implementing stack using Array
#include <iostream>
using namespace std;
class Stack
{
public:
	Stack(int size)
	{
		this->arr = new int[size];
		this->size = size;
		this->top = -1;
	};

	void push(int data)
	{
		if (top == size - 1)
			cout << "Stack overflow" << endl;
		else
		{
			top += 1;
			arr[top] = data;
		}
	}

	int peek()
	{
		return arr[top];
	}

	bool empty()
	{
		return top == -1;
	}

	int len()
	{
		return top == -1 ? 0 : top;
	}

	void pop()
	{
		if (top != -1)
			top -= 1;
	}

	void print()
	{
		int itr = top;
		while (itr >= 0)
		{
			cout << "| " << arr[itr] << " |" << endl;
			cout << "_____" << endl;
			itr--;
		}
	}

	~Stack()
	{
		delete[] arr;
	}

private:
	int *arr;
	int size;
	int top;
};
int main()
{

	Stack myStack = Stack(10);
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	myStack.push(6);
	myStack.push(7);
	myStack.push(8);
	myStack.push(9);
	myStack.push(10);
	myStack.print();
	cout << myStack.peek() << endl;
	myStack.pop();
	myStack.pop();
	myStack.pop();
	// myStack.push(8);
	// myStack.push(9);
	// myStack.push(10);
	myStack.print();
}