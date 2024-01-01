#include <map>
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

class Solution
{
public:
	{
		parenthesisMap['('] = 0;
		parenthesisMap[')'] = 1;
		parenthesisMap['{'] = 2;
		parenthesisMap['}'] = 3;
		parenthesisMap['['] = 4;
		parenthesisMap[']'] = 5;
	}
	bool isValid(string s)
	{
		if (s.size() % 2 != 0)
			return false;
		Stack parenthesis = Stack(s.size());
		int idx = 0;
		while (idx < s.size())
		{
			int val = parenthesisMap[s[idx]];
			if (val % 2 == 0)
				parenthesis.push(val);
			else if (parenthesis.peek() == val - 1)
				parenthesis.pop();
			else
				return false;
			idx++;
		}
		return true;
	}

private:
	std::map<char, int> parenthesisMap;
};