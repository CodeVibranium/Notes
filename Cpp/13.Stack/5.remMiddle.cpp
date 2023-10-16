// Using stack remove middle elem
#include <iostream>
using namespace std;

class Stack
{

public:
	Stack(int size) : arr(new int[size]), top(-1), size(size){};

	void push(int data)
	{
		if (top != size - 1)
		{
			top += 1;
			arr[top] = data;
		}
	}
	void pop()
	{
		if (top != -1)
		{
			top -= 1;
		}
	}
	bool empty()
	{
		return top == -1;
	}

	int peak()
	{
		return arr[top];
	}
	void print()
	{
		int itr = top;
		while (itr >= 0)
		{
			cout << "_____" << endl;
			cout << "| " << arr[itr] << " |" << endl;
			itr--;
		}
		cout << "_____" << endl;
	}
	// int size()
	// {
	// 	return top;
	// }
	int stackSize() { return top; }

private:
	int *arr;
	int top;
	int size;
};

void removeMiddleElem(Stack &inputStack, int size)
{

	Stack poppedItems = Stack(size);
	while (inputStack.stackSize() > size / 2)
	{
		poppedItems.push(inputStack.peak());
		inputStack.pop();
	}
	inputStack.pop();
	while (!poppedItems.empty())
	{
		inputStack.push(poppedItems.peak());
		poppedItems.pop();
	}
}

int main()
{

	Stack myStack = Stack(6);
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	myStack.push(6);
	myStack.print();
	removeMiddleElem(myStack, myStack.stackSize());
	myStack.print();
}