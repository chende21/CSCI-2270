#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//the big difference between structs and classes are that structs
//classes are for keeping things clean, reusability, and is easy to share
//by default, everything in structs are public, they're lightweight and easy to implement
struct Node
{
	int id = -1;
	//particular null for pointers (should use this)
	Node* next = nullptr;
};

//.h file defines what's going to be in the class
//.cpp is where we actually do the implementation
//this would be in the .h file
class singlyLL
{
	private:
		//createNode = helper function to make a new Node
		Node* createNode(int, Node*);
		//when we create the Node, it's going to be null, therefore nullptr
		Node* head = nullptr;

		void deleteList();
	public:
		//constructor, going to create link list where head is null
		singlyLL();
		//what if you want to assign the head?
		//make constructor that takes a parameter, called OVERLOADED CONSTRUCTOR
		singlyLL(int);
		//destructor, gets called automatically
		~singlyLL();
		//pass in integer for id of node, puts at end of link list, why use bool then?
		//to see if it works!
		//bool may return false if deleted
		bool insertNodeAtEnd(int);
		bool deleteNode(int);
		void printList();
};

//default constructor
//this would be in the .cpp file
singlyLL::singlyLL()
{
	//does nothing
}

singlyLL::singlyLL(int nodeID)
{
	//set head with the nodeID
	head = createNode(nodeID, nullptr);
}

singlyLL::~singlyLL()
{
	//will free memory, deconstructor
	deleteList();
}

Node* singlyLL::createNode(int nodeID, Node* nextNode)
{
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nextNode;
	return newNode;
}

bool singlyLL::insertNodeAtEnd(int nodeID)
{
	//first thing when inserting a node
	//the state of the list when starting out is nothing
	//so check if the head is null
	Node* newNode = createNode(nodeID, nullptr);
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		//head is not null?
		//need to iterate
		//where does the new node go? at the end!
		Node* currentNode = head;
		//traverse to the end of the list
		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	//shouldn't be a case where this doesn't return true
	return head;
}

void singlyLL::printList()
{
	if (head == nullptr)
	{
		cout << "Empty list." << endl;
	}
	else
	{
		Node* currentNode = head;
		while (currentNode != nullptr)
		{
			cout << "Node ID: " << currentNode->id << endl;
			currentNode = currentNode->next;
		}
	}
}

void singlyLL::deleteList()
{
	Node* currentNode = head;
	Node* tempNode;
	while (currentNode != nullptr)
	{
		tempNode = currentNode->next;
		cout << "Deleting node: " << currentNode->id << endl;
		delete currentNode;
		currentNode = tempNode;
	}
}

int main()
{
	//singlyLL coolList; head is nullptr
	//singlyLL coolList(10); head is 10! because this is the overloaded constructor passing an int
	//coolList.createNode(15); WON'T WORK, it's a private item!
	singlyLL coolList(10);
	coolList.insertNodeAtEnd(15);
	coolList.insertNodeAtEnd(30);
	coolList.insertNodeAtEnd(5);

	singlyLL secondList(37);
	secondList.insertNodeAtEnd(44);

	cout << "Printing first list: " << endl;
	coolList.printList();

	cout << "Printing second list: " << endl;
	secondList.printList();

	cout << "Printing third list:" << endl;
	//singlyLL* thirdList = new singlyLL;
		//couts empty list.
	singlyLL* thirdList = new singlyLL(99);
		//returns node id: 99
	//things called with new are on heap
	thirdList->printList();
	//this line of code is the same thing as the one above
	//(*thirdList).printlist();

	delete thirdList;
	//result:
		//Printing first list: 
		//Node ID: 10
		//Node ID: 15
		//Node ID: 30
		//Node ID: 5
		//Printing second list: 
		//Node ID: 37
		//Node ID: 44

	return 0;
}