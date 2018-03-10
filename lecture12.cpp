#include <iostream>

using namespace std;

const int MAX_SIZE = 5;
class arrStack
 {
 	public:
 		arrStack();
 		~arrStack();
 		bool isEmpty();
 		bool isFull();
 		int peek(); //going to return int because tells what's on top of stack
 		int pop();
 		//can also do bool pop(int*);
 		bool push(int);

 	private:
 		int stackOfInts[MAX_SIZE];
 		int currentSize = 0;
 };

arrStack::arrStack()
{

}

arrStack::~arrStack()
{

}

bool arrStack::isFull()
{
	if (currentSize == MAX_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool arrStack::isEmpty()
{
	if (currentSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool arrStack::push(int itemToAdd)
{
	if (isFull()) //same as if currentSize == MAX_SIZE
	{
		return false;
	}
	else
	{
		stackOfInts[currentSize] = itemToAdd;
		currentSize += 1;
		return true;
	}
}

int main()
{
	arrStack matey;
	if (matey.isEmpty())
	{
		cout << "Stack is empty." << endl;
	}
	if (matey.push(19))
	{
		cout << "19 pushed to stack" << endl;
	}	
}