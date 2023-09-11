
#include <iostream>
#include <vector>
using namespace std;

/*
A pallindrome is something which is same when read from rtl or ltr.
for ex: 121 or 121
1234 or 4321
*/

class Node
{

public:
	Node *next;
	int data;
	Node(int data) : next(nullptr), data(data){};
};

class LinkedList
{

public:
	LinkedList() : head(nullptr), tail(nullptr){};
	void push(int data)
	{
		Node *newNode = new Node(data);
		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	void print()
	{
		Node *itr = head;
		while (itr->next != nullptr)
		{
			cout << itr->data << " => ";
			itr = itr->next;
		}
		cout << itr->data << " => NULL" << endl;
	}

	bool isPallindrome()
	{
		Node *itr = head;
		bool isListPallindrome = true;
		vector<int> vec;
		while (itr != nullptr)
		{
			vec.push_back(itr->data);
			itr = itr->next;
		}
		int start = 0;
		int end = vec.size() - 1;
		while (start <= end)
		{
			if (vec[start] == vec[end])
			{
				start++;
				end--;
			}
			else
			{
				isListPallindrome = false;
				break;
			}
		}
		return isListPallindrome;
	}

private:
	Node *head;
	Node *tail;
};

int main()
{

	LinkedList Sll;
	Sll.push(10);
	Sll.push(11);
	Sll.push(11);
	Sll.push(11);
	Sll.push(11);
	Sll.push(11);
	Sll.push(10);
	Sll.print();
	cout << "Given linked list is " << (Sll.isPallindrome() ? "a Pallindrome" : "not a pallindrome") << endl;
	Sll.print();
}
