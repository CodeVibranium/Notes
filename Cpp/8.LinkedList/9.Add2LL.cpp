/*
Given two linked lists
1. Add both linked lists
2. Return a new linked list with the result of addtion of two linked lists
*/

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
			cout << tmp->data << " -> ";
			tmp = tmp->next;
		}
		cout << "NULL" << endl;
	}

	Node *getHead()
	{
		return head;
	}

	int addList(LinkedList A)
	{
		Node *BListHead = head;
		Node *AListHead = A.getHead();
		int AListSum = getSum(AListHead);
		int BListSum = getSum(BListHead);
		cout << "AListSum " << AListSum << " BListSum " << BListSum << endl;
		return AListSum + BListSum;
	}

	LinkedList createNewList(LinkedList A)
	{
		int listNums = addList(A);
		cout << "List sum is " << listNums << endl;
		LinkedList newList;
		while (listNums > 0)
		{
			newList.push(listNums % 10);
			listNums = listNums / 10;
		}
		return newList;
	}

	void reverse()
	{
		Node *prev = nullptr;
		Node *curr = head ;
		Node *next = nullptr;
		while (curr != nullptr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
	}

private:
	int getSum(Node *head)
	{
		int sum = 0;
		while (head != nullptr)
		{
			sum = (sum * 10) + head->data;
			head = head->next;
		}
		return sum;
	}
	Node *head;
	Node *tail;
};

int main()
{

	LinkedList listA;
	LinkedList listB;
	listA.push(1);
	listA.push(2);
	listA.push(3);
	listA.push(4);
	listB.push(1);
	listB.push(2);
	listB.push(3);
	listB.push(4);
	listB.push(5);
	listB.push(6);
	listA.print();
	listB.print();
	LinkedList newList = listA.createNewList(listB);
	newList.print();
	newList.reverse();
	newList.print();
}