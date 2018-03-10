#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//struct is like a class, encapsulates with properties
struct student
{
	//these are the default values
	int studentID = -1;
	string studentName = "N/A";
	string studentMajor = "N/A";

};

int main()
{
	//make an array of students
	student studentArray[10];
	int numStudents = 0;

	//file.io
	//need to have txt document
	ifstream file_opener;
	file_opener.open("students");
	if (file_opener.fail())
	{
		cout << "ERROR" << endl;
	}
	else
	{
		cout << "File opened" << endl;
		//read through lines
		string currentLine;
		while (getline(file_opener, currentLine))
		{
			cout << "I just read: " << currentLine << endl;
		}

		//starts over
		//seekg needs to be with clear
		file_opener.clear();
		file_opener.seekg(0, ios::beg);

		while (getline(file_opener, currentLine))
		{
			//set up string stream
			stringstream curStrStream(currentLine);
			//curID = student ID, curSName = student name, curSMaj = student major
			//getline always returns strings
			string curID, curSName, curSMaj = "";
			getline(curStrStream, curID, ',');
			getline(curStrStream, curSName, ',');
			getline(curStrStream, curSMaj, ',');
			cout << "ID: " << curID << endl;
			cout << "Name: " << curSName << endl;
			cout << "Major: " << curSMaj << endl;

			//stoi because we're getting a string from getline and need to turn it into an integer
			studentArray[numStudents].studentID = stoi(curID);
			studentArray[numStudents].studentName = curSName;
			studentArray[numStudents].studentMajor = curSMaj;

			numStudents++;
		}
	}
	file_opener.close();

	//write to the file
	ofstream outfile_opener;
	outfile_opener.open("studentsinfo.txt");

	//iterate through data
	for (int i = 0; i < numStudents; i++)
	{
		outfile_opener << studentArray[i].studentID << "\t" << studentArray[i].studentName << "\t" << studentArray[i].studentMajor << "\t";
	}
	outfile_opener.close();
	return 0;
}