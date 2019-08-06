#pragma once

using namespace std;
#include <iostream>
#include <string>
#include "degree.h"


class Student
{
public:
	const static int courseArraySize = 3;

protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int courseDays[courseArraySize];

public:
	// constructors
	Student();
	Student(
		string studentID,
		string firstName,
		string lastName, 
		string email, 
		int age, 
		int courseDays[]
	);
	
	//getters
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	int getAge() const;
	int* getCourseDays();
	virtual DegreeType getDegreeProgram() const = 0;

	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setCourseDays(int courseDays[]);

	virtual void print();
	
	//destructor
	~Student();


};