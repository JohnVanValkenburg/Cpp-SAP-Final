#pragma once

#include "student.h"
#include "softwareStudent.h"

class SoftwareStudent : public Student 
{
protected:
	DegreeType degreeType;
public:
	SoftwareStudent();
	SoftwareStudent(
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

	~SoftwareStudent();
};