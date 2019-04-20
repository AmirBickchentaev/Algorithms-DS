#include "pch.h"
#include"queue.h"


//getter for Queue head
	Node* Queue::getHead()
	{
		return this->head;
	}
//getter for Queue Tail
	Node* Queue::getTail()
	{
		return this->tail;
	}

//default constructor for Queue
	Queue::Queue()
	{
		//pointers for head and tail part
		Node* head = NULL;
		Node* tail = NULL;

		int size = 0;
		int info = 0;
	}
	//non-default constructor for Queue with pointer to first element as parameter
	Queue::Queue(Node* head)
	{
		this->head = head;
		Node* tail = NULL;
		size = 0;
	}
//destructor for queue element
	Queue::~Queue()
	{
		cout << "\nNode was successfuly deleted\n";
	}

//function for adding an element at head part 
	void Queue::push(int information)
	{
		//new element that'll be added
		Node *newNode = new Node(information);
		//statement that'll invoke in case if there's no elements in queue
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
			//node that'll store pointer to tail node
			Node* previousNode = getTail();
			//setting previous node adress for new node previous element
			newNode->setPrevious(previousNode);
			//setting next node adress for previous node next element 
			previousNode->setNext(newNode);

			//pointing tail to newly created node 
			this->tail = newNode;
			//size incrementor
			this->size++;
		}
	}


	//function for searching an element with speciffic info parameter
	Node* Queue:: search(int parameter)
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
	void Queue::remove(int information) 
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
		//assingning next variable adress to element to next element of searchEL
		Node* next = searchEl->getNext();
		//setting next element for previous element
		previous->setNext(next);
		//setting previous element for next element
		next->setPrevious(previous);
		//decreasing size
		this->size--;
		//deleting searchEL
		delete searchEl;
	}

	//fuction for deleting a first element in queue
	int Queue::pop()
	{
		//creating copy of head info field
		int info = this->head->getInfo();
		//moving head to the next position
		this->head = this->head->getNext();
		cout << "\nnode was successufly popped\ncurrent chain of nodes";
		//decreasing size
		this->size--;
		//print fucntion
		print();
		return info;
	}

	//fuction for returning size of queue
	int Queue:: getSize() 
	{
		cout << "\nA size of queue - ";
		return size;
	}

	//function for printing the whole queue
	void Queue::print() 
	{
		cout << "\nCurrent Queue chain is      ";
		//assigning head address to counter variable
		Node* counter = getHead();
		//queue loop
		for (counter; counter != NULL; counter = counter->getNext())
		{
			cout << counter->getInfo();
		}
		cout<<"\n";
	}
	