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
	void reverse()
	{
		Node *tmp = head->next;
		Node *orgH = head;
		Node *orgT = tail;
		Node *newhead = head;
		Node *replacedNext;
		Node *nextHead;
		while (tmp != nullptr)
		{
			replacedNext = newhead->next->next;
			newhead->next->next = head;
			head = replacedNext;
			newhead = head->next;
			// nextHead = head->next->next;
			// head->next->next = head;

			// ;
			// newhead = head->next;
			// head = newhead;
			// tmp = head;
		}
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
}