#include <iostream>    
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int addtwonums(int onenum, int twonum);

int main()
{
	//variables
	int anint = 7;
	float afloat = 7.5;
	double adouble = 19.3924209384;
	int intarray[10];

	string socks[10];
	socks[0] = "blue";
	socks[1] = "red";
	char myChar = 'a';

	//2D Arrays
	int twodarray[10][10];

	//if, else if, else
	string girlname = "Arya";
	if (girlname == "Arya")
	{
		cout << "A girl is no one" << endl;
	}
	else if (girlname == "waif")
	{
		cout << "SPOILER ALERT" << endl;
	}
	else
	{
		cout << "I don't know you who are" << endl;
	}

	//for loop
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			twodarray[i][j] = i*j;
			cout << addtwonums(i, j) << endl;
		}
	}

	//while loop
	int counter = 0;
	while (counter < 10)
	{
		cout << "Counter is " << counter << endl;
		//There's a difference between ++counter and counter++
		//++counter will add to count and then do the function
		//counter++ will do the function and then add to count
		counter++;
	}
}

int addtwonums(int onenum, int twonum)
{
	return onenum * twonum;
}