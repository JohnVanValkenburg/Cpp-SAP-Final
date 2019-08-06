#include "softwareStudent.h"

	SoftwareStudent::SoftwareStudent():Student()
	{
		degreeType = SOFTWARE;
	}

	SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email,
		int age, int courseDays[], DegreeType degreeType)
		:Student(studentID, firstName, lastName, email, age, courseDays)
	{
		degreeType = SOFTWARE;
	}

	DegreeType SoftwareStudent::getDegreeProgram() const
	{
		return SOFTWARE;
	}

	void SoftwareStudent::print()
	{
		this->Student::print();
		cout << "Degree: Software" << endl;
	}

	// destructor
	SoftwareStudent::~SoftwareStudent()
	{
		Student::~Student();
	}