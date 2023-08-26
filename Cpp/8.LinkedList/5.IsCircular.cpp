#include <iostream>
#include <map>

using namespace std;

/*Can be done using
1. Using map
2. using floyd detection
*/
class Node
{

public:
	int data;
	Node *next;
	Node(int data) : data(data), next(nullptr) {}
};

class LinkedList
{

public:
	LinkedList() : head(nullptr), tail(nullptr) {}
	void insert(int data)
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

	void makeCircular(int index)
	{
		int idx = 0;
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		Node *tmp = head;
		while (tmp != nullptr)
		{
			if (idx == index)
			{
				cout << "Given list circular, tail is pointing too " << tmp->data << endl;
				tail->next = tmp;
				break;
			}
			idx++;
			tmp = tmp->next;
		}
		if (idx != index)
			cout << "Index out of range" << endl;
	}

	void isListCircular()
	{
		Node *tmp = head;
		map<Node *, bool> visited;

		while (tmp != nullptr)
		{
			if (visited[tmp] == true)
			{
				cout << "Given list is circular at " << tmp->data << endl;
				break;
			}
			visited[tmp] = true;
			tmp = tmp->next;
		}
		// cout << "Given list is not circular " << endl;
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

	~LinkedList()
	{
		Node *tmp = head;
		while (tmp != nullptr)
		{

			Node *newTmp = tmp->next;
			delete tmp;
			tmp = newTmp;
		}
		delete tmp;
	}

private:
	Node *head;
	Node *tail;
};

int main()
{

	LinkedList sll;
	sll.insert(11);
	sll.insert(12);
	sll.insert(13);
	sll.insert(14);
	sll.insert(15);
	sll.insert(16);
	sll.insert(17);
	sll.print();
	sll.isListCircular();
	sll.makeCircular(4);
	// sll.print();
	sll.isListCircular();
}