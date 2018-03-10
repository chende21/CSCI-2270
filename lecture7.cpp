#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*
NOTES:
LISTS:
	Each element (NODE) in the list has some sort of identifying factor
	Pointer points to the memory address
	The starting point is the head of the list
	list element (head) -> list element -> list element -> NULL
	
NODE:
	Frrst thing points to Null, then Head = Null
	When adding something to the node, create new node which points to Null 
	Then we have to go to the list and find the end of the list, then whatever that is,
		point to the new Node
	How to know we're at the end of the list? The next pointer = Null 
		(head - start of list, tail - end of list)
*/

struct Node
{
	int id = -1;
	Node* next = NULL;
	//by default, it equals to NULL
};

//will return a Node pointer
Node* createNode(int nodeID, Node* nextNode)
{
	Node* newNode = new Node;
	//newNode is a pointer, not a statically defined variable. Because of this, we use an arrow
	//to reference the pointer.
	newNode->id = nodeID;
	newNode->next = nextNode;
	return newNode;
}

//insertNode -- inserts at end of list, returns head of list
Node* insertNode(Node* head, int newNodeID)
{
	//first thing when inserting a node
	//the state of the list when starting out is nothing
	//so check if the head is null
	if (head == NULL)
	{
		Node* newNode = createNode(newNodeID, NULL);
		head = newNode;
	}
	else
	{
		//head is not null?
		//need to iterate
		//where does the new node go? at the end!
		Node* currentNode = head;
		//traverse to the end of the list
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		Node* newNode = createNode(newNodeID, NULL);
		currentNode->next = newNode;
	}
	return head;
}
//worst case: O(n)

void printList(Node* head)
{
	if (head == NULL) 
	{
		cout << "Empty list" << endl;
	}
	else
	{
		Node* currentNode = head;
		while (currentNode != NULL)
		{
			cout << "Node ID: " << currentNode->id << endl;
			currentNode = currentNode->next;
		}
	}
}

Node& deleteNode(Node* head, int nodeID)
{
	//find the node
	bool nodeFound = false;
	//report back that we didnt find node if not found
	//first check if hea dis null
	if (head == NULL)
		{
			cout << "Empty list, nothing to delte" << endl;
			return NULL;
		}
	else
	{
		//first check the head
		if (head->id == nodeID)
		{
			//need to delete the head, what becomes the new head? whatever is next
			//not freeing up memory, just reassigning
			Node* nextNode = head->next;
			delete head;
			head = nextNode;
			nodeFound = true;
			cout << "Node " << nodeID << " deleted." << endl;
		}
		else if ((head-> next != NULL) && (head->next->id == nodeID))
		{
			//delete the second node
			Node* newNextNode = head->next->next;
			delete head->next;
			head->next = newNextNode;
			nodeFound = true;
			cout << "Node " << nodeID << " deleted" << endl;
		}
		else
		{
			Node* currentNode = head->next;
			while ((currentNode-> next != NULL) && (!nodeFound))
			{
				if (currentNode->next->id == nodeID)
				{
					Node* newNextNode = currentNode->next->next;
					delete currentNode->next;
					currentNode->next = newNextNode;
					nodeFound = true;
					cout << "Node " << nodeID << " deleted" << endl;
				}
				else
				{
					currentNode = currentNode->next;
				}
			}
			if (!nodeFound)
			{
				cout << "Node " << nodeID << " not found, nothing deleted." << endl;
			}
		}
		return head;
	}
}

int main()
{
	Node* head = NULL;
	//the 30 is just the number we're passing as the newNodeID into the insertNode function
	head = insertNode(head, 30);
	printList(head);

	head = deleteNode(head, 30);
	printList(head);
}