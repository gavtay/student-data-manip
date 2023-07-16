#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"
using std::string;
using std::cout;
using std::endl;

// Roster destructor
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete(classRosterArray[i]);
	}
}



// An instance of class Roster
void Roster::e2(string studentData) {
	int minusOne = -1;

	// id
	long long int a = studentData.find(",");
	string id = studentData.substr(0, a);

	// first name
	long long int b = a + 1;
	a = studentData.find(",", b);
	string fName = studentData.substr(b, a - b);

	// last name
	b = a + 1;
	a = studentData.find(",", b);
	string lName = studentData.substr(b, a - b);

	// email
	b = a + 1;
	a = studentData.find(",", b);
	string eAddress = studentData.substr(b, a - b);

	// age
	// stoi is a stirng to integer converter
	// this allows the string age to be converted and stored as an integer
	b = a + 1;
	a = studentData.find(",", b);
	int age = stoi(studentData.substr(b, a - b));

	// days for courses
	b = a + 1;
	a = studentData.find(",", b);
	int dayCourse1 = stoi(studentData.substr(b, a - b));

	b = a + 1;
	a = studentData.find(",", b);
	int dayCourse2 = stoi(studentData.substr(b, a - b));

	b = a + 1;
	a = studentData.find(",", b);
	int dayCourse3 = stoi(studentData.substr(b, a - b));

	// degree
	b = a + 1;
	a = studentData.find(",", b);
	string degree = studentData.substr(b, a - b);

	// setting degree program
	// initializing the enumerated type program to Software
	DegreeProgram program = SOFTWARE;
	if (degree == "SECURITY") {
		program = SECURITY;
	}
	// same process for NETWORK
	if (degree == "NETWORK") {
		program = NETWORK;
	}
	add(id, fName, lName, eAddress, age, dayCourse1, dayCourse2, dayCourse3, program);
}




// adding each student and their corresponding information to classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, DegreeProgram program) {
	// sets the instance variables from part D1 and updates the roster
	// array for days in course
	int dayArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	//storing
	classRosterArray[++minusOne] = new Student(studentID, firstName, lastName, emailAddress, age, dayArray, program);

}




void Roster::remove(string studentID) {

	// removes students from the roster by student ID.If the student ID does not exist, the function prints an error message indicating that the student was not found.	
	bool boolean = false;

	// notifying the user that the function is processing the attempt to remove a student
	cout << "Attempting to find student to remove..." << endl;

	for (int i = 0; i <= Roster::minusOne; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			// sort algorithm
			if (i < numStudents - 1) {
				Student* a = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = a;

				// confirming to screen that a student was removed
				cout << "Student successfully removed." << endl;
			}
			Roster::minusOne--;
			// if StudentID is found then set the boolean to true so we know the student was found
			boolean = true;
		}
	}

	// swap
	Student* b = classRosterArray[2];
	classRosterArray[2] = classRosterArray[3];
	classRosterArray[3] = b;

	if (boolean != true) {
		cout << "Student could not be found." << endl;
	}
}




void Roster::printAll() {

	// loop runs for how many students there are in the roster
	for (int i = 0; i < 5; i++) {
		// print function is called for each student
		classRosterArray[i]->print();
	}
	cout << endl;
}




void Roster::printAverageDaysInCourse(string studentID, int day1, int day2, int day3) {
	// this function will grab the 3 days per course for each student, then do basic math to calculate the average between the 3 classes, then print this information to the screen
	Student s;
	// that correctly prints a student’s average number of days in the three courses.The student is identified by the studentID parameter


	int daySum = day1 + day2 + day3;
	int dayAvg = daySum / s.courseCount;

	cout << "Average for: " << studentID << " - " << dayAvg << " days per course" << endl;
}




// E.3.e
void Roster::printInvalidEmails() {
	// displaying emails that have been inputed and are invalid such as missing the @ symbol, the . or a space in the email

	cout << "Testing for invalid emails..." << endl;

	for (int i = 0; i < 5; i++) {
		string email = classRosterArray[i]->GetEmailAddress();

		// creating a conditional to find if the email is invalid
		if (email.find("@") == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
			cout << "Invalid Email(s): " << classRosterArray[i]->GetEmailAddress() << endl;
		}
	}

	cout << endl;
}




void Roster::printByDegreeProgram(DegreeProgram program) {

	// printing out student information for a degree program specified by an enumerated type.

	cout << "SOFTWARE Degree Program Students: " << endl;
	for (int i = 0; i < 5; i++) {
		// check if student degree matches the software type
		if (classRosterArray[i]->GetDegreeProgram() == SOFTWARE) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}
