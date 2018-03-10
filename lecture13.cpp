#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 5;

class arrCircQueue
{
	public:
		arrCircQueue();
		~arrCircQueue();
		bool enqueue(int);
		bool dequeue(int&);
		bool peek(int&);
	private:
		bool isFull();
		bool isEmpty();
		int head = -1;
		int tail = -1;
		int arrQueue[MAX_SIZE];
};

arrCircQueue::arrCircQueue()
{
	//constructor
}

arrCircQueue::~arrCircQueue()
{
	//deconstructor
}

//function is returning if the queue is full
bool arrCircQueue::isFull()
{
	int tempHead = head;
	if (head == 0)
	{
		//do this because head is the first part of the array
		tempHead = MAX_SIZE;
	}
	//ex: if head is at 0 and tail is at 4 and max_size is 5
	if (tempHead - tail == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool arrCircQueue::isEmpty()
{
	//as stated in the class
	if (head == -1 && tail == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool arrCircQueue::enqueue(int itemToAdd)
{
	if (!isFull())
	{
		//add item
		int tempTail = tail+1;
		if (tempTail == MAX_SIZE)
		{
			tempTail = 0;
		}
		tail = tempTail;
		arrQueue[tail] = itemToAdd;
		if (head == -1)
		{
			head = 0;
		}
		cout << "Item " << itemToAdd << " added to queue." << endl;
		return true;
	}
	else
	{
		cout << "Queue full, item --" << itemToAdd << "-- not added to queue." << endl;
		return false;
	}
}

bool arrCircQueue::dequeue(int& itemToGet)
{
	if (isEmpty())
	{
		cout << "Queue empty, nothing to dequeue!" << endl;
		return false;
	}
	else
	{
		//remove at head
		itemToGet = arrQueue[head];
		//check if list is now empty
		if (head == tail)
		{
			//nothing left in the queue
			head = tail = -1;
		}
		else
		{
			head+=1; 
			if (head == MAX_SIZE)
			{
				head = 0;
			}
		}
		//impliment p
		return true;
	}
}
















int main()
{
	arrCircQueue pirateQ;
	pirateQ.enqueue(16);
	pirateQ.enqueue(19);

	int topOQueue;
	if (pirateQ.dequeue(topOQueue))
	{
		cout << "Dequeued " << topOQueue << endl;
	}
}