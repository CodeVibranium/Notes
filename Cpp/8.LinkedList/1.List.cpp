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
	LinkedList()
	{
		cout << "Linked list constructor called" << endl;
		head = nullptr;
		tail = nullptr;
	}
	void push(int data)
	{
		Node *newNode = new Node(data);
		// cout << "HEAD: " << head << endl;
		// cout << "TAIL: " << tail << endl;
		// cout << "NEW NODE : " << newNode << endl;
		if (head == nullptr)
			head = tail = newNode;
		tail->next = newNode;
		tail = newNode;
		// cout << "TAIL: " << tail << endl;
		// cout << "******************" << endl;
	}

	void print()
	{
		Node *tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->data << " -> ";
			tmp = tmp->next;
		}
		cout << "NULL" << endl;
	}

	void insertAt(int data, int index)
	{
		int idx = 0;
		Node *tmp = head;
		Node *nodeAtIdx = nullptr;
		while (tmp != NULL)
		{
			if (idx == index)
			{
				nodeAtIdx = tmp;
				tmp = tmp->next;
				break;
			}
			tmp = tmp->next;
			idx++;
		}
		if (idx == index)
		{
			Node *newNode = new Node(data);
			nodeAtIdx->next = newNode;
			newNode->next = tmp;
		}
		else if (idx != index)
		{
			cout << "No element is found at given index ";
			this->push(data);
			cout << "So added data at the last of the list" << endl;
			return;
		}
	}

	void deleteAt(int index)
	{

		int idx = 0;
		Node *tmp = head;
		if (index == 0)
		{
			head = tmp->next;
			return;
		}
		Node *nodeAtIdx = nullptr;
		Node *prevNode = nullptr;
		while (tmp != NULL)
		{
			prevNode = tmp;
			tmp = tmp->next;
			if (idx == index)
			{
				nodeAtIdx = tmp;
				break;
			}
			idx++;
		}
		if (idx == index)
		{
			prevNode->next = nodeAtIdx->next;
			delete nodeAtIdx;
		}
	}

	void search(int data)
	{
		int idx = 0;
		Node *tmp = head;
		while (tmp != NULL)
		{
			if (tmp->data == data)
			{
				cout << "Node is found at index " << idx << endl;
				idx = -1;
				return;
			}
			tmp = tmp->next;
			idx++;
		}
		if (idx == -1)
			cout << "Node couldnt be found in the list " << endl;
	}

private:
	Node *head;
	Node *tail;
};

int main()
{

	LinkedList sll;
	sll.push(10);
	sll.push(20);
	sll.push(30);
	sll.push(40);
	sll.push(50);
	sll.push(60);
	sll.print();
	sll.insertAt(35, 9);
	sll.print();
	sll.deleteAt(1);
	sll.print();
	sll.search(20);
}