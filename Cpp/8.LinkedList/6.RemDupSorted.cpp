#include <iostream>
using namespace std;

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

	void removeDuplicates()
	{
		Node *itr = head;
		while (itr->next != nullptr)
		{
			if (itr->data != itr->next->data)
			{
				itr = itr->next;
			}
			else
			{
				Node *duplicateAddr = itr->next;
				itr->next = itr->next->next;
				delete duplicateAddr;
			}
		}
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
	Sll.print();
	Sll.removeDuplicates();
	Sll.print();
}
