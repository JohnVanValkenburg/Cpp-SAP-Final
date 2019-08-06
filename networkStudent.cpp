#include "networkStudent.h"

NetworkStudent::NetworkStudent():Student()
	{
		degreeType = NETWORKING;
	}

	NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, 
		int age, int courseDays[], DegreeType degreeType)
		:Student(studentID, firstName, lastName, email, age, courseDays)
	{
		degreeType = NETWORKING;
	}

	DegreeType NetworkStudent::getDegreeProgram() const
	{
		return NETWORKING;
	}
	
	void NetworkStudent::print()
	{
		this->Student::print();
		cout << "Degree: Networking" << endl;
	}

	//deconstructor
	NetworkStudent::~NetworkStudent()
	{
		Student::~Student();
	}
