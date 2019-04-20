#pragma once
#include"pch.h"
#include"queue.h"

class Stack
{
private:
	//queue size
	int size;
public:
	//variable for Stack head
	Node* head;
	//variable for Stack Tail
	Node* tail;
	//getter for Stack head
	Node* getHead();
	//getter for Stack Tail
	Node* getTail();
	//default constructor for Stack
	Stack();
	//non-default constructor for Stack	
	Stack(Node* head);
	//destructor for queue element
	~Stack();
	//funtion for adding an elemtnt at head part 
	Node* search(int parameter);
	//fuction for searching an element with speciffic info parameter
	void push(int information);
	//function for deleting element with specific info parameter 
	void remove(int information);
	//fuction for deleting a first element in Stack
	int pop();
	//fuction for returning size of Stack
	int getSize();
	//function for printing the whole Stack
	void print();

};