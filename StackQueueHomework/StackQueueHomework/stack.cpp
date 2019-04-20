#include "pch.h"
#include"stack.h"

//getter for Stack head
	Node* Stack::getHead()
	{
		return this->head;
	}
	//getter for Stack Tail
	Node* Stack::getTail()
	{
		return this->tail;
	}
	//default constructor for Stack
	Stack::Stack()
	{
		//pointers for head and tail part
		Node* head = NULL;
		Node* tail = NULL;
		int size = 0;
	}


	//non-default constructor for Stack with pointer to first element as parameter
	Stack::Stack(Node* first)
	{
		//pointers for head and tail part
		this->head = head;
		Node* tail = NULL;
		size = 0;
	}
	//destructor for Stack element
	Stack::~Stack()
	{
		cout << "\nNode was successfuly deleted\n";
	}

	//function for adding an element at head part 
	void Stack::push(int information)
	{
		//new element that'll be added
		Node *newNode = new Node(information);
		//statement that'll invoke in case if there's no elements in Stack
		if (this->head == NULL)
		{
			//assingning head and tail elemets to new node
			this->head = newNode;
			this->tail = newNode;
			//incrementing size
			this->size++;
			return;
		}
		else
		{
			//node that'll store pointer to head part
			Node* prevNode = getHead();
			//setting previous node adress for new node next elemtent
			newNode->setNext(prevNode);
			//setting previous node adress for new node next element 
			prevNode->setPrevious(newNode);
			//pointing tail to newly created node 
			this->head = newNode;
			//size incrementor
			this->size++;
		}
	}

	//function for searching an element with speciffic info parameter
	Node* Stack:: search(int parameter)
	{
		//element for storing head part
		Node* counter = getHead();
		//for loop for searching the desired element
		for (counter; counter != NULL; counter = counter->getNext())
		{
			if (counter->getInfo() == parameter)
			{
				return counter;
			}
		}
		return NULL;
	}

	//function for deleting element with specific info parameter 
	void Stack::remove(int information)
	{
		//searching for element and assigning him to searchEL 
		Node* searchEl = search(information);


		//if searchEL doesn't have previous element
		//(non-default deleting case)
		if (searchEl->getPrev() == NULL)
		{
			//assigning head to next element;
			this->head = searchEl->getNext();
			this->head->setPrevious(NULL);
			//deleting searchEL
			delete searchEl;
			//decreasing of queue size
			this->size--;
			return;
		}
		//if searchEL doesn't have next element
		//(non-default deleting case)
		if (searchEl->getNext() == NULL)
		{
			//assigning tail to previous element;
			this->tail = searchEl->getPrev();
			//setting tail next elemtnt to NULL
			this->tail->setNext(NULL);
			//deleting searchEL
			delete searchEl;
			//decreasing of queue size
			this->size--;
			return;
		}
		//(default case)
		//assingning previous variable adress to previous element of searchEL
		Node* previous = searchEl->getPrev();
		//assingning next variable adress to next element of searchEL
		Node* next = searchEl->getNext();
		//setting previous element of previous element to next variable
		previous->setNext(next);
		//setting previous element of next element to previous variable
		next->setPrevious(previous); 
		//decreasing size
		this->size--;
		//deleting searchEL
		delete searchEl;
	}

	//fuction for deleting a first element in Stack
	int Stack::pop()
	{
		//creating copy of head info field
		int info = this->head->getInfo();
		//moving head to the next position
		this->head = this->head->getNext();
		cout << "\nnode was successufly popped\ncurrent chain of nodes";
		//decreasing size
		this->size--;
		//print function
		print();
		return info;
	}
	//function for returning size of Stack
	int Stack:: getSize()
	{
		cout << "\nA size of stack - ";
		return size;
	}
	//function for printing the whole Stack
	void Stack::print()
	{
		cout << "\nCurrent Stack chain is      ";
		//assigning head address to counter variable
		Node* counter = getHead();
		//stack loop
		for (counter; counter != NULL; counter = counter->getNext())
		{
			cout << counter->getInfo();
			
			}
		cout << "\n";
	}