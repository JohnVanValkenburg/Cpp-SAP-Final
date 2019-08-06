#pragma once

#include "student.h"
#include "networkStudent.h"

class NetworkStudent : public Student
{
protected:
	DegreeType degreeType;
public:
	NetworkStudent();
	NetworkStudent(
		string studentID,
		string firstName, 
		string lastName, 
		string email, 
		int age, 
		int courseDays[], 
		DegreeType degreeType
	);

	DegreeType getDegreeProgram() const override;
	void print() override;

	~NetworkStudent();
};