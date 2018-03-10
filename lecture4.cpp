#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	//expecting four things on the command line
	if (argc < 4)
	{
		cout << "not enough parameters for this program" << endl;
	}
	else
	{
		//check for parameters
		for (int i = 0; i < argc; i++)
		{
			cout << "parameters " << i << ": " << argv[i] << endl;
		}
		//the first parameter is the name of the executable
		//second is the number of lines in the file
		//third is the input file
		//fourth is the output file
	}
}

///////////////////////////////////////////////////////////////////

//pointer is a special kind of variable that contains a memory address

void psasbyval(int a);
void passbyref(int &a);

int main()
{
	int jenny = 5;
	int *jennypointer; //pointint to data type int
	jennypointer = &jenny;

	int billy = 2;
	int jimmy = 3;

	cout << "What's Jenny? " << jenny << endl;
	cout << "What's reference to Jenny (&): " << &jenny << endl;
	cout << "What's jennypointer? " << jennypointer << endl;
	cout << "What's stored at jennypointer? " << jennypointer << endl;

	//so what's the difference between references and pointers
	//pointers can be reassigned, references cannot

	cout << "Billy: " << billy << endl;
	count << "Jimmy: " << jimmy << endl;

	//Q: Can you move jenny reference to jimmy reference?
	//&jenny = &billy
	//A: NO

	//Q: Can you set jenny pointer to billy's reference?
	//jennypointer = &billy
	//A: YES
	//now, what's in jennypointer when we dereference it?
	//cout << "jennypointer is now << jennypointer << endl;

	cout << "dereferencing jennypointer: " << *jennypointer << endl;

	passbyval(jenny);
	cout << "What's Jenny after pass by val? " << jenny << endl;
	passbyref(jenny);
	cout << "What's Jenny after pass by ref? " << jenny << endl;

	passbyval(jimmy); //shouldn't change jimmy
	passbyref(billy); //should change billy
	cout << "jimmy is " << jimmy << endl;
	cout  << "billy is " << billy << endl;
	cout << "Jennypointer is now " << jennypointer << endl;
	cout << "dereferencing jennypointer: " <<< *jennypointer << endl;
}

void passbyval(int a)
{
	++a;
}

void passbyref(int &a)
{
	//this will increase a by one
	++a;
}



