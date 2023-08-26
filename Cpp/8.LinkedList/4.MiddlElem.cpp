#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data) : next(nullptr), data(data) {}
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

	void print()
	{
		Node *tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->data << " -> ";
			tmp = tmp->next;
		}
		cout << "NULL" << endl;
	}

	int middle()
	{
		if (head == nullptr)
			return NULL;
		Node *tmp1 = head;
		Node *tmp2 = head;
		while (tmp2 != nullptr)
		{
			if (tmp2->next == nullptr)
			{
				tmp2 = tmp2->next;
				break;
			}
			tmp2 = tmp2->next->next;
			tmp1 = tmp1->next;
		}
		return tmp1->data;
	}

	~LinkedList()
	{
		cout << "Destructor invoked" << endl;
		Node *tmp = head;
		while (tmp != nullptr)
		{
			Node *newTmp = tmp->next;
			cout << "Deleted " << tmp << endl;
			delete tmp;
			tmp = newTmp;
		}
	}

private:
	Node *head;
	Node *tail;
};

int main()
{
	LinkedList sll;
	sll.push(60);
	sll.push(70);
	sll.print();
	cout << "Middle elem is " << sll.middle() << endl;
}