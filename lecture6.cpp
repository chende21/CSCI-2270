#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void leaky(double* doublePointer)
{
	double* leakyCopy = doublePointer;
	*doublePointer = (*doublePointer) * (*doublePointer);
}
//leakyCopy leaks memory
//if you create a pointer, need to decide to keep or clean up

int main()
{
	int *anIntPointer = NULL;
	//Null is nothing, it's not pointing to anything
	anIntPointer = new int;
	//this line assigns memory to it, 4 bytes (integer), 8 bytes (double), new is making a new pointer
	//use delete with new
	//at this point, random stuff is stored
	*anIntPointer = 500;
	//deference pointer
	cout << "anIntPointer is storing: " << *anIntPointer << endl;
	//result: anIntPointer is storing: 500

	int* intPointer = new int;
	*intPointer = 17;
	++*intPointer;
	//make sure not to type *intPointer++;
	cout << "What's in intPointer? " << *intPointer << endl;
	//result: What's in inPointer? 18

	double *doublePointer = new double(55.248575);
	cout << "doublePointer reference: " << doublePointer << endl;
	cout << "doublePointer value: " << *doublePointer << endl;

	//you can put stuff in an allocated memory reference, but as long as it's an int pointer 
	//it's 4 bytes, it will always point to int pointer unless you change where it points to
	//you can change the interior of your house but the address will always stay the same

	double* seconddoublePointer = doublePointer;
	cout << "doublePointer reference: " << doublePointer << endl;
	cout << "doublePointer value: " << *doublePointer << endl;
	cout << "seconddoublePointer reference: " << seconddoublePointer << endl;
	cout << "seconddoublePointer value: " << *seconddoublePointer << endl;
	//result: doublePointer reference: 0x7f96b0500010
	//doublePointer value: 55.2486
	//seconddoublePointer reference: 0x7f96b0500010
	//seconddoublePointer value: 55.2486

	cout << "incrementing *doublePointer: " << endl;
	(*doublePointer)++;
	cout << "doublePointer reference: " << doublePointer << endl;
	cout << "doublePointer value: " << *doublePointer << endl;
	cout << "seconddoublePointer reference: " << seconddoublePointer << endl;
	cout << "seconddoublePointer value: " << *seconddoublePointer << endl;
	//result: doublePointer reference: 0x7fbe52f00000
	//doublePointer value: 56.2486
	//seconddoublePointer reference: 0x7fbe52f00000
	//seconddoublePointer value: 56.2486

	doublePointer++;
	cout << "increasing doublePointer: " << doublePointer << endl;
	doublePointer++;
	cout << "increasing doublePointer: " << doublePointer << endl;
	doublePointer++;
	//result: increasing doublePointer: 0x7f925a500028
	//increasing doublePointer: 0x7f925a500030

	cout << "Deleting doublePointer:  " << endl;
	delete doublePointer;
	cout << "What happened to seconddoublePointer?" << seconddoublePointer << endl;
	//result: malloc: *** error for object 0x7f91c1d00028: pointer being freed was not allocated
	//*** set a breakpoint in malloc_error_break to debug

	//
	//
	//
	//
	//

	//LINK LISTS:
}