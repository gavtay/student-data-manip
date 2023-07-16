#pragma once
#include <iostream>
#include "degree.h"
#include <string>
using std::string;

class Student {
public: 
	const static int courseCount = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysPerCourse[courseCount];
	DegreeProgram degreeProgram;

public:
	// empty constructor
	Student();
	// Constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysPerCourse[], DegreeProgram degreeProgram);
	// destructor
	~Student();
	
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysPerCourse();
	DegreeProgram GetDegreeProgram();

	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetDaysPerCourse(int daysPerCourse[]);
	void SetDegreeProgram(DegreeProgram program);

	void print();
};
