#include"pch.h"
#include "node.h"


//default counstructor for Node
	Node::Node()
	{
		this->information = 0;
		this->next = NULL;
		this->previous = NULL;
	}

//non-default constuctor with information field
	Node::Node(int information)
	{
		this->information = information;
		this->next = NULL;
		this->previous = NULL;
	}

//destructor for any Node
	Node::~Node()
	{
		cout << "\nNode was successfuly deleted";
	}
//setter for next node
	void Node::setNext(Node* next)
	{
		this->next = next;
	}
//getter for node information
	int Node::getInfo()
	{
		return information;
	}
//setter for previous node
	void Node::setPrevious(Node* previous)
	{
		this->previous = previous;
	}
// getter for adress of next node
	Node* Node::getNext()
	{
		return next;
	}
//getter for adress of previous node
	Node* Node::getPrev()
	{
		return previous;
	}
