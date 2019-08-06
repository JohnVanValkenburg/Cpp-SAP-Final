#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include <iostream>
#include <regex>

	Roster::Roster() // empty constructor with default values
	{
		this->capacity = 0;
		this->lastIndex = -1; // 0 is valid array index, -1 indicates a bad array index and it is empty
		this->classRosterArray = nullptr;
	}
	Roster::Roster(int capacity) // same as above but sets max size of roster
	{
		this->capacity = capacity;
		this->lastIndex = -1;
		this->classRosterArray = new Student * [capacity];
		// note to self. YOU HAVE USED THE NEW KEYWORD. YOU WILL NEED TO DELETE THIS OR WILL GET MEMORY LEAK
	}
	
	Student * Roster::getStudentAt(int index)
	{
		return classRosterArray[index];
	}

	void Roster::parseThenAdd(string data)
	{
		if (lastIndex < capacity)
		{
			lastIndex++;
			DegreeType dType;

			// read student id
			int rhs = data.find(",");
			string studID = data.substr(0, rhs);
		
			// read first name
			int lhs = rhs + 1;
			rhs = data.find(",", lhs);
			string fName = data.substr(lhs, rhs - lhs);

			// read last name
			lhs = rhs + 1;
			rhs = data.find(",", lhs);
			string lName = data.substr(lhs, rhs - lhs);

			// read email
			lhs = rhs + 1;
			rhs = data.find(",", lhs);
			string email = data.substr(lhs, rhs - lhs);

			// read age
			lhs = rhs + 1;
			rhs = data.find(",", lhs);
			string ageString = data.substr(lhs, rhs - lhs);
			int age = stoi(ageString);

			// read course one
			lhs = rhs + 1;
			rhs = data.find(",", lhs);
			int c1 = stoi(data.substr(lhs, rhs - lhs));

			// read course two
			lhs = rhs + 1;
			rhs = data.find(",", lhs);
			int c2 = stoi(data.substr(lhs, rhs - lhs));

			// read course three
			lhs = rhs + 1;
			rhs = data.find(",", lhs);
			int c3 = stoi(data.substr(lhs, rhs - lhs));

			// read degree program
			lhs = rhs + 1;
			rhs = data.find(",", lhs);
			string degree = data.substr(lhs, rhs - lhs);
			
			// check possible degree programs
			if (!degree.compare("NETWORK"))
			{
				// adding network student
				dType = NETWORKING;
			}
			else if (!degree.compare("SOFTWARE"))
			{
				// adding software student
				dType = SOFTWARE;
			}
			else if (!degree.compare("SECURITY"))
			{
				// adding security student
				dType = SECURITY;
			}
			else
			{
				cerr << "You attempted to add a student with an invalid degree program";
				exit(-2);
			}

			// ADDING STUDENT DATA TO ROSTER FINALLY!! :D
			add(studID, fName, lName, email, age, c1, c2, c3, dType);

		}
		else
		{
			cerr << "you have exceeded the roster capacity";
			exit(-1);
		}
	
	}

	// this creates student objects to put into the roster array.  
	// remember when we delete the roster we need to delete each student object to avoid mem leak
	void Roster::add(string studentID, string firstName, string lastName, string email,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeType)
	{
		int courses[Student::courseArraySize];
		courses[0] = daysInCourse1;
		courses[1] = daysInCourse2;
		courses[2] = daysInCourse3;

		if(degreeType == NETWORKING)
		{
			classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, email, age, courses, degreeType);
		}
		else if(degreeType == SOFTWARE)
		{
			classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, email, age, courses, degreeType);
		}
		else if (degreeType == SECURITY)
		{
			classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, email, age, courses, degreeType);
		}
	}

	void Roster::remove(string studentID) // remove student from roster based on student ID
	{
		for (int i = 0; i <= lastIndex; i++)
		{
			if (this->getStudentAt(i)->getStudentID() == studentID)
			{
				delete this->classRosterArray[i];
				this->classRosterArray[i] = this->classRosterArray[lastIndex];
				lastIndex--;
				cout << "The student has been removed.\n";
				return;
			}
		}
		cout << "such a student with this ID was not found\n";
		return;
	}

	void Roster::printAll()
	{
		for (int i = 0; i <= lastIndex; i++)
		{
			this->classRosterArray[i]->print();
		}
	}

	void Roster::printDaysInCourse(string studentID)
	{
		for (int i = 0; i <= lastIndex; i++)
		{
			if (this->classRosterArray[i]->getStudentID() == studentID)
			{
				int* days = this->classRosterArray[i]->getCourseDays();
				int average = (days[0] + days[1] + days[2]) / 3;
				cout << "The average days for " << this->classRosterArray[i]->getStudentID() << " are " << average << endl;
			}
		}
	}
	
	void Roster::printInvalidEmails()
	{
		cout << "Checking for valid emails" << endl;
		bool any = false;
		for (int i = 0; i <= lastIndex; i++)
		{
			string email = this->classRosterArray[i]->getEmail();
			regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
			regex spaceCheck("(\\s+)");

			// checking regex pattern for proper email syntax
			if (!regex_match(email, pattern))
			{
				cout << "invalid email found: " << this->classRosterArray[i]->getEmail() << endl;
				any = true;
			}
			// separately checking for spaces in email that were not found in the pattern match that may be a problem
			
		}
		if (any == false)
		{
			cout << "No invalid emails were found!" << endl;
		}
	}

	void Roster::printByDegreeProgram(DegreeType degreeProgram)
	{
		cout << "Print by degree program: " << degreeTypeStrings[degreeProgram] << endl;

		for (int i = 0; i <= lastIndex; i++)
		{
			if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram)
			{
				this->classRosterArray[i]->print();
			}
		}
	}

	Roster::~Roster()
	{
		for (int i = 0; i < lastIndex; i++)
		{
			delete this->classRosterArray[i]; // deleting each student in the roster
		}
		delete classRosterArray; // to delete the dynamically assigned pointers
	}


int main() {

	cout << "Scripting and Programming - Applications\nProgramming language: C++\nStudent ID: 001094638\nJohn Van Valkenburg\n";

	const string studentData[] = 
	{
	"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,John,Van Valkenburg,jvanva2@wgu.edu,29,20,30,25,SOFTWARE"
	};

	int numberOfStudents = 5;

	// parse data and add to roster
	Roster* classRoster = new Roster(numberOfStudents);
	cout << "Parsing student data and adding students to roster." << endl;

	for (int i = 0; i < numberOfStudents; i++)
	{
		classRoster->parseThenAdd(studentData[i]); 
	}

	cout << "Finished parsing student data.\nThank you for your patience\n";
	
	// printing all students in roster
	cout << "Printing all objects in class roster\n";
	classRoster->printAll();

	// checking emails
	classRoster->printInvalidEmails();

	// calculating avg number of days for all students in roster
	cout << "calculating average days in courses for all students" << endl;
	for (int i = 0; i < numberOfStudents; i++)
	{
		classRoster->printDaysInCourse(classRoster->getStudentAt(i)->getStudentID());
	}

	// printing degree by program
	classRoster->printByDegreeProgram(SOFTWARE);

	// removing same student from roster twice
	cout << "Attempting to remove Student ID A3 from class Roster.\n";
	classRoster->remove("A3");
	cout << "Printing all students to verify removal\n";
	classRoster->printAll();

	cout << "Attempting to remove Student ID A3 from class Roster.\n";
	classRoster->remove("A3");

	// delete roster
	cout << "Deleting the roster";
	classRoster->~Roster();

	return 0;
};