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

		while (itr != nullptr)
		{
			cout << itr->data << " -> ";
		}
		cout << "NULL" << endl;
	}

	void reverse()
	{

		Node *A = head;
		Node *B = head->next;
		Node *C = head->next->next;
		Node *itr = head;
		while (itr != nullptr)
		{
			if (itr == head)
			{

				A->next = nullptr;
				B->next = A;
				itr = C;
				// Node *tmp = head->next;
				// Node *nextHead = tmp->next;
				// itr->next->next = head;
				// itr->next = nullptr;
				// itr = nextHead;
			}
			else
			{

				itr->next = A;
				itr->next = B;
				B = A->next;
			}
		}
	}

private:
	Node *head;
	Node *tail;
};
int main() {}
