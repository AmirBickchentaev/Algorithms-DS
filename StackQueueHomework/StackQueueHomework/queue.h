#pragma once
#include"Node.h"

class Queue
{	
private:
	//queue size
	int size;
public:
	//variable for Queue head
	Node* head;
	//variable for Queue Tail
	Node* tail;
	//getter for Queue head
	Node* getHead();
	//getter for Queue Tail
	Node* getTail();
	//default constructor for Queue
	Queue();
	//non-default constructor for Queue
	Queue(Node* head);
	//destructor for queue element
	~Queue();
	//funtion for adding an elemtnt at head part 
	Node* search(int parameter);
	//fuction for searching an element with speciffic info parameter
	void push(int information);
	//function for deleting element with specific info parameter 
	void remove(int information);
	//fuction for deleting a first element in queue
	int pop();
	//fuction for returning size of queue
	int getSize();
	//function for printing the whole queue
	void print();

};