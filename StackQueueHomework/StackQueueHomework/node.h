#include "pch.h"

//basic structure of node
struct Node {

private:
	int information = 0;
	//fields for storing address for next and previous elements
	Node* next = NULL;
	Node* previous = NULL;
public:
	//default counstructor for Node
	Node();
	//non-default constuctor with information field
	Node(int information);
	//destructor for any Node
	~Node();
	//setter for next node
	void setNext(Node* next);
	//getter for node information
	int getInfo();
	//setter for previous node
	void setPrevious(Node* previous);
	// getter for adress of next node
	Node* getNext();
	//getter for adress of previous node
	Node* getPrev();

};