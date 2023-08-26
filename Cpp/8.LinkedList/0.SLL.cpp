#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList
{

public:
	LinkedList() : head(nullptr), tail(nullptr) {}

	void push(int data)
	{

		Node *newNode = new Node(data);

		if (head == nullptr)
		{
			head = tail = newNode;
			return;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
			return;
		}
	}

	void rmDup(bool isSorted)
	{
		if (isSorted == false)
			return;
		Node *tmp = head;
		while (head != nullptr)
		{
				}
	}

private:
	Node *head;
	Node *tail;
};

int main()
{
}