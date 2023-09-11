#include <iostream>
#include <map>
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
			head = tail = newNode;
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}
	void print()
	{
		Node *tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->data << " => ";
			tmp = tmp->next;
		}
		cout << "NULL" << endl;
	}

	void removeDup()
	{
		map<int, bool> visited;
		Node *prev = head;
		Node *tmp = head;
		while (tmp != nullptr)
		{
			if (!visited[tmp->data])
				visited[tmp->data] = true;
			else
			{
				prev->next = tmp->next;
				delete tmp;
				tmp = prev;
			}

			if (tmp != head && prev != tmp)
				prev = prev->next;
			tmp = tmp->next;
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
	Sll.push(10);
	Sll.push(10);
	Sll.push(14);
	Sll.push(10);
	Sll.push(11);
	Sll.push(14);
	Sll.push(15);

	Sll.print();
	Sll.removeDup();
	Sll.print();
}