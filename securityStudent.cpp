#include "securityStudent.h"

	SecurityStudent::SecurityStudent():Student()
	{
		degreeType = SECURITY;
	}

	SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, 
		int age, int courseDays[], DegreeType degreeType)
		:Student(studentID, firstName, lastName, email, age, courseDays)
	{
		degreeType = SECURITY;
	}

	DegreeType SecurityStudent::getDegreeProgram() const
	{
		return SECURITY;
	}

	void SecurityStudent::print()
	{
		this->Student::print();
		cout << "Degree: Security" << endl;
	}

	// destructor
	SecurityStudent::~SecurityStudent()
	{
		Student::~Student();
	}

