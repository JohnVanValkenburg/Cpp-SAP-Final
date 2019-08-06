#pragma once

#include "student.h"
#include "securityStudent.h"

class SecurityStudent : public Student
{
protected:
	DegreeType degreeType;
public:
	SecurityStudent();
	SecurityStudent(
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

	~SecurityStudent();
};