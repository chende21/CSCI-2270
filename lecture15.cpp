#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int id = -1;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
};

class BST
{
	private:
		Node* root = nullptr;
		Node* createNode(int, Node*, Node*, Node*); //for left, right, and parent
		int getSize(Node*); //get particular node from sub-tree (picking any node and getting whatever is below)
		bool addNodeRPriv(Node* ,int);
		Node* search(Node* startNode);

	public:
		BST();
		~BST(); //to delete all the nodes
		bool addNode(int);
		bool addNodeR(int);
		bool deleteNode(int);
		//int findSmallestNode();
		//int findLargestNode(); 
		bool findSmallestNode(int&);
		bool findLargestNode(int&);
		//start from root, but can rewrite to find subtree's root
		int getSizeOfTree();
};

BST::BST()
{
	//con
}

BST::~BST()
{
	//decon
}

Node* BST::createNode(int itemToAdd, Node* parentNode, Node* leftChild, Node* rightChild)
{
	Node* newNode = new Node;
	newNode->id = itemToAdd;
	newNode->parent = parentNode;
	newNode->left = leftChild;
	newNode->right = rightChild;

	return newNode; //need to return a node (newNode) for Node* type function
}

bool BST::findLargestNode(int& itemToFind)
{
	if (root != nullptr)
	{
		Node* tempNode = root;
		while (tempNode->right != nullptr)
		{
			tempNode = tempNode->right;
		}
		return tempNode->id;
	}
	else
	{
		return -1;
	}
}

int BST::getSizeOfTree()
{
	return getSize(root);
}

int BST::getSize(Node* startNode)
{
	int* size = 0;
	if (startNode != nullptr)
	{
		size++;
		size+=getSize(startNode->left);
		size+=getSize(startNode->right);
	}
	return *size;
}

bool BST::addNode(int itemToAdd)
{
	//start at the root
	//when adding node, must start from root
	Node* tempNode = root;
	//moving through tree, want to keep track of parent
	Node* currentParent = nullptr;
	//this isn't adding the node to our tree, this is just checking where to put it
	while (tempNode != nullptr)
	{
		currentParent = tempNode;
		//checking if the thing we want to add matches the node's id (if it's already there)
		if (itemToAdd == tempNode->id)
		{
			//going to return false because it's already in there
			cout << "Item already in tree." << endl;
			return false;
		}
		else
		{
			//if our item is less than the tempNode's id
			if (itemToAdd < tempNode->id)
			{
				//go to the left side
				tempNode = tempNode->left;
			}
			else
			{	
				//gp tp the right side
				tempNode = tempNode->right;
			}
		}
	}
	if (currentParent == nullptr)
	{
		//this will be our first node
		root = createNode(itemToAdd, nullptr, nullptr, nullptr);
		cout << "Item " << itemToAdd << " added to root" << endl;
	}
	else if (itemToAdd < currentParent->id)
	{
		//if it's less, put it on the left
		currentParent->left = createNode(itemToAdd, currentParent, nullptr, nullptr);
		cout << "Item " << itemToAdd << " added to left of " << currentParent->id << endl;
	}
	else
	{
		//if it's more, put it on the right
		currentParent->right = createNode(itemToAdd, currentParent, nullptr, nullptr);
		cout << "Item " << itemToAdd << " added to right of " << currentParent->id << endl;
	}
	return true;
}

bool BST::addNodeR(int itemToAdd)
{
	if (root == nullptr)
	{
		Node* newNode = createNode(itemToAdd, nullptr, nullptr, nullptr);
		ro0t = newNode;
		cout << "Item " << itemToAdd << " added as root" << endl;
		return true;
	}
	else
	{
		return addNodeRPrivate(root, itemToAdd);
	}
}

bool BST::addNodeRPriv(Node* curNode, int itemToAdd)
{
	if (itemToAdd < curNode->id)
	{
		if (curNode->left != nullptr)
		{
			return addNodeRPriv(curNode->left, itemToAdd);
		}
		else
		{
			curNode->left = createNode(itemToAdd, curNode, nullptr, nullptr);
			cout << "Item " << itemToAdd << " added to left of " << curNode->id << endl;
			return true;
		}
	}
	else if (itemToAdd > curNode->id)
	{
		if (curNode->right != nullptr)
		{
			return addNodeRPriv(curNode->right, itemToAdd);
		}
		else
		{
			curNode->right = createNode(itemToAdd, curNode, nullptr, nullptr);
			cout << "Item " << itemToAdd << " added to right of " << curNode->id << endl;
			return true;
		}
	}
	else
	{
		cout << "Item " << itemToAdd << " already in tree" << endl;
		return false;
	}
}

Node* BST::search(Node* startNode, int itemToFind)
{
	if (startNode != nullptr)
	{
		if (itemToFind < startNode->id) && (startNode->left != nullptr)
		{
			return search(startNode->left, itemToFind);
		}
		else if (itemToFind > startNode->id && startNode->right != nullptr)
		{
			return search(startNode->right, itemtoFind)
		}
			else if (itemToFind == startNode->id)
		{
			return startNode;
		}
		else
		{
			cout << "Value " << itemtoFind << " not found" << endl;
		}
	}
	return startNode;
}

int main()
{
	BST groot;
	//non-recursive add
	groot.addNode(17);
	groot.addNode(42);
	groot.addNode(12);
	groot.addNode(18);
	groot.addNode(18);
	
	/*
	output: Item 17 added to root
	Item 42 added to right of 17
	Item 12 added to left of 17
	Item 18 added to left of 42
	Item already in tree.
	*/

	groot.addNodeR(17);
	groot.addNodeR(42);
	groot.addNodeR(12);
	groot.addNodeR(18);
	groot.addNodeR(18);

}







