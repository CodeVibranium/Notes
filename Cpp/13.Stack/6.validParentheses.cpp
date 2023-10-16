// Valid parentheses
// {}()[] is valid
// {]} is invalid

// 1. if string length is odd return false;\
// 2. create a map where all opening are indexed as even and close indexed as odd
// (- 0
// {-2
// [-4
// ]-5
// }-3
// )-1

// {}()[] = 6/2 =3
// {}()[]
// [{({[]})}] 10/2 =5
// stack can be used to solve this
/*
1. first enter the value,
2. while entering check if the value if odd
3. if odd check the peak and compare odd-1 to peak
	if equal, pop
	else return false
3. if first entered item itself is odd return false
4. if len of str is not even return false;

*/

#include <iostream>
#include <string>
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
	Solution()
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
		for (char ch : s)
		{
			int val = parenthesisMap[ch];
			if (val % 2 == 0)
				parenthesis.push(val);
			else
			{
				if (parenthesis.empty())
					return false;

				if (parenthesis.peek() != val - 1)
					return false;
				parenthesis.pop();
			}
		}

		return parenthesis.empty();
	}

private:
	map<char, int> parenthesisMap;
};