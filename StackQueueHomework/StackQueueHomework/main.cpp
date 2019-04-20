#include "pch.h"
#include <iostream>
#include"stack.h"

int main() 
{
	
	//queue part
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << "\nthe current queue is :";
	q.print();
	q.pop();
	q.print();
	q.remove(4);
	q.print();
	cout<<q.getSize();


	cout << "\n\n\n\n\nSwitching to stack\n\n\n\n";
	//stack part
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.print();
	st.pop();	
	st.print();
	st.remove(1);
	st.print();
	cout << st.getSize();






}