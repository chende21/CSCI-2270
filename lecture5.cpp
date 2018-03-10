#include <iostream>
#include <string>

using namespace std;

void passbypointer(int *ptr)
{
	//these two lines are the same, but in different formats
	*ptr = *ptr + 1;
	++*ptr;
	//the ++ goes to the memory reference, not to the actual value, so this would give an error
	*ptr++;
	//however, if you do (*ptr)++;, it will work and the same as the other two lines
	(*ptr)++;
}

//resizing an array
//we need a * in the function definition because we are returning a pointer
//int *multiple_arraysize() is the same thing as int* multiple_arraysize()
int *multiple_arraysize(int p[], int length, int multiplier)
{
	int *new_array = new int[length * multiplier];
	//length because copying stuff out of old array
	for (int index = 0; index < length; index++)
	{
		new_array[index] = p[index];
	}
	//not having brackets deletes only the first thing in the array
	delete [] p;
	return new_array;
}

int main()
{
	
	//Q1: Can I do this?
	int x = 10; 
	//iterating x and then saying while bigger than 0
	while (x-- > 0)
	{
		cout << "x: " << x << endl;
	}
	//A1: YES.
	

	//passing pointer into the function passbypointer
	//allocate pointers with new
	//when you make something with "new", you can also delete it
	//a stack is memory that is managed by the operating system when the program runs
	//computer compiles and runs and allocated memory on the stack
	//you cannot remove things from the stack themselves, you'll get errors otherwise

	//int *intPtr = new int; would be on the heap
	//heap is a larger pool of memory, which is managed by the program, aka you.
	//if you forget about these, it'll take up memory, causing a memory leak
	//if you're resizing an array or you want to free memory or if you know you're going to be 
	////deleting/modifying, use new
	//int normal_int; would be on the stack

	int *intPtr = new int;
	//free up memory
	delete intPtr;

	*intPtr = 0;
	passbypointer(intPtr);
	cout << "What is stored in intPtr? " << *intPtr << endl;

	int *my_array = new int[200];
	int static_array[200]; //you can't delete this array
	for (int index = 0; index < 200; index++)
	{
		my_array[index] = index + 1;
	}
	cout << "Reference of my_array: " << my_array << endl;
	cout << "Reference of static_array: " << static_array << endl;

	int *a_newarray = multiple_arraysize(my_array, 200, 3);
	for (int index = 0; index < 600; index++)
	{
		cout << "index: " << index << ": " << a_newarray[index] << endl;
	}



}