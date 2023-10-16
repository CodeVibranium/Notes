#include <iostream>
#include <string>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &valToBeInsertedAtBottom)
{

	if (st.empty())
	{
		st.push(valToBeInsertedAtBottom);
		return;
	}
	int top = st.top();
	st.pop();
	insertAtBottom(st, valToBeInsertedAtBottom);
	st.push(top);
}

int main()
{

	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	int valToBeInsertedAtBottom = 10;
	insertAtBottom(st, valToBeInsertedAtBottom);
	// st.push(1);
	// st.push(1);
	// st.push(1);
	// st.push(1);
	// st.push(1);
	// st.push(1);
}
