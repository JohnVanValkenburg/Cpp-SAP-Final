#pragma once

#include "student.h"

// roster stores a collection of students
class Roster
{
private:
	int lastIndex; // last index, essentially keeping track of # of students in roster
	int capacity; // max size
	Student** classRosterArray;
	/*
	// personal note to remember: could of declared as "Student* students[x]" but that means the array is size of x
	// doing the previous syntax allows the array size to be dynamic in runtime instead of decided when compiled
	// arrays are pointers to addresses in C++ so Student** is an array of pointers which is what we want
	*/
public:
	// constructors
	Roster(); // empty constructor with default values
	Roster(int capacity); // same as above but sets max size of roster

	// methods
	Student* getStudentAt(int index);
	void parseThenAdd(string data); // parses the long string from the array of string information to add
	void add(string studentID, string firstName, string lastName, string email,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeType);


	void remove(string studentID); // remove student from roster based on student ID
	void printAll(); // prints all students in roster
	void printDaysInCourse(string studentID); // print average number of days in the three courses
	void printInvalidEmails(); // verifies student email and displays invalid email addresses
	void printByDegreeProgram(DegreeType degreeProgram); // print all student information based on degree programs

	// destructor
	~Roster();
	

};