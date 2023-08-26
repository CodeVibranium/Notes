#include <iostream>
using namespace std;

class Node
{
public:
	Node *prev;
	int data;
	Node *next;
	Node(int data) : prev(nullptr), data(data), next(nullptr) {}
};

class Dll
{

public:
	Dll()
	{
		cout << "Doubly Linked list constructor invoked" << endl;
		this->head = nullptr;
		this->tail = nullptr;
	}
	void push(int data)
	{
		if (tail == nullptr && head == nullptr)
		{
			Node *newNode = new Node(data);
			newNode->prev = newNode;
			head = newNode;
			tail = newNode;
		}
		else
		{
			Node *newNode = new Node(data);
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
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

	void pushAt(int data, int index)
	{
		Node *tmp = head;
		int idx = 0;

		if (index == 0)
		{
			Node *newNode = new Node(data);
			if (head)
			{
				tmp->prev = newNode;
				newNode->next = tmp;
			}
			else
			{
				tail = newNode;
			}
			head = newNode;
			return;
		}
		while (tmp != nullptr)
		{
			if (idx == index)
			{
				Node *newNode = new Node(data);
				newNode->prev = tmp->prev;
				tmp->prev->next = newNode;
				tmp->prev = newNode;
				newNode->next = tmp;
				break;
			}
			tmp = tmp->next;
			idx++;
		}
		if (idx != index)
			cout << "Sorry we could'nt insert the item at the given index " << endl;
	}

	void pop()
	{
		if (!tail)
		{
			cout << "List is empty!" << endl;
			return;
		}
		if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		Node *tmpTail = tail->prev;
		tail->prev->next = nullptr;
		delete tail;
		tail = tmpTail;
	}

	void popAt(int index)
	{
		if (head == nullptr)
		{
			cout << "List is empty!" << endl;
			return;
		}
		if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		int idx = 0;
		Node *tmp = head;
		if (index == 0)
		{
			head = tmp->next;
			delete tmp;
			return;
		}
		while (tmp != nullptr)
		{
			if (idx == index)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
				break;
			}
			tmp = tmp->next;
			idx++;
		}
		if (idx != index)
			cout << "Sorry we could'nt delete the item at the given index " << endl;
	}

	int search(int data)
	{
		int idx = 0;
		Node *tmp = head;
		while (tmp != nullptr)
		{
			if (tmp->data == data)
				return idx;
			tmp = tmp->next;
			idx++;
		}
		return -1;
	}

	int size()
	{
		int idx = 0;
		Node *tmp = head;
		while (tmp != nullptr)
		{
			tmp = tmp->next;
			idx++;
		}
		return idx;
	}
	inline bool isEmpty()
	{
		if (head == nullptr)
			return true;
		return false;
	}
	void printRev()
	{
		if (head == nullptr)
		{
			cout << "List is empty!" << endl;
			return;
		}

		Node *lastNode = tail;
		while (lastNode != head)
		{
			cout << lastNode->data << " <- ";
			lastNode = lastNode->prev;
		}
		cout << head->data << " <- NULL" << endl;
	}

	~Dll()
	{
		cout << "Destructor invoked" << endl;
		Node *tmp = head;
		while (tmp != nullptr)
		{
			Node *nextTmp = tmp->next;
			cout << "Deleted node " << tmp << endl;
			delete tmp;
			tmp = nextTmp;
		}
	}

private:
	Node *head;
	Node *tail;
};

int main()
{
	Dll linkedList;
	linkedList.push(10);
	linkedList.push(20);
	linkedList.push(30);
	linkedList.push(40);
	linkedList.print();
	linkedList.pushAt(15, 1);
	linkedList.print();
	linkedList.pop();
	linkedList.print();
	linkedList.popAt(0);
	linkedList.print();
	linkedList.printRev();
	cout << linkedList.isEmpty() << endl;
	cout << linkedList.size() << endl;
	cout << linkedList.search(13) << endl;
}