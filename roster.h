#pragma once
#include "student.h"
#include "degree.h"

class Roster {
private:
	const static int numStudents = 5;
public:
	Student* classRosterArray[numStudents];
	int minusOne = -1;

	void e2(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, DegreeProgram program);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID, int day1, int day2, int day3);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram program);
	
	// deconstructor for Roster class
	~Roster();
};
