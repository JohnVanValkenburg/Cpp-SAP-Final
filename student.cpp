#pragma
#include "student.h"

	// default constructor
	Student::Student()
	{
		this->studentID = "";
		this->firstName = "";
		this->lastName = "";
		this->email = "";
		this->age = 0;
		for (int i = 0; i < courseArraySize; i++)
		{
			this->courseDays[i] = 0;
		}
	}
	// full constructor
	Student::Student(string studentID, string firstName, string lastName, string email,
		int age,int courseDays[]) 
	{
		this->studentID = studentID;
		this->firstName = firstName;
		this->lastName = lastName;
		this->email = email;
		this->age = age;

		for (int i = 0; i < courseArraySize; i++)
		{
			this->courseDays[i] = courseDays[i];
		}
	}

	// getters
	string Student::getStudentID() const 
	{
		return studentID;
	}

	string Student::getFirstName() const 
	{
		return firstName;
	}

	string Student::getLastName() const 
	{
		return lastName;
	}

	string Student::getEmail() const 
	{
		return email;
	}

	int Student::getAge() const 
	{
		return age;
	}

	int* Student::getCourseDays()
	{
		return courseDays;
	}

	// setters
	void Student::setStudentID(string firstName) 
	{
		this->studentID = studentID;
	}
	void Student::setFirstName(string firstName) 
	{
		this->firstName = firstName;
	}
	void Student::setLastName(string lastName) 
	{
		this->lastName = lastName;
	}
	void Student::setEmail(string email)
	{
		this->email = email;
	}
	void Student::setAge(int age)
	{
		this->age = age;
	}
	void Student::setCourseDays(int courseDays[])
	{
		for (int i = 0; i < courseArraySize; i++)
		{
			this->courseDays[i] = courseDays[i];
		}
	}

	void Student::print() 
	{
		cout << left 
			<< "Name: " << getFirstName() << " " << getLastName() << endl
			<< "Student ID: " << getStudentID() << endl
			<< "Age: " << getAge() << endl
			<< "email: " << getEmail() << endl
			<< "Days in courses: " << getCourseDays()[0] << ", " << getCourseDays()[1] << ", " << getCourseDays()[2] << endl;
	}

	//destructor
	Student::~Student()
	{
	}



