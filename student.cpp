#pragma once
#include <iostream>
#include "student.h"
#include "degree.h"
using std::string;
using std::cout;
using std::endl;

// empty constructor

Student::Student() {
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";
    age = 0;
    for (int i = 0; i < courseCount; i++) {
        daysPerCourse[i] = 0;
    }
    this->degreeProgram = DegreeProgram::NETWORK;
}



// constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysPerCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    // for loop to assign days per course array into another parallel array
    for (int i = 0; i < courseCount; i++) {
        this->daysPerCourse[i] = daysPerCourse[i];

    }
    this->degreeProgram = degreeProgram;
}



// deconstructor
Student::~Student() {}



// accesors
string Student::GetStudentID() {
    return studentID;
}
string Student::GetFirstName() {
    return firstName;
}
string Student::GetLastName() {
    return lastName;
}
string Student::GetEmailAddress() {
    return emailAddress;
}
int Student::GetAge() {
    return age;
}
int* Student::GetDaysPerCourse() {
    return this->daysPerCourse;
}
DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}




// mutators
void Student::SetStudentID(string id) {
    this->studentID = id;
}
void Student::SetFirstName(string fName) {
    this->firstName = fName;
}
void Student::SetLastName(string lName) {
    this->lastName = lName;
}
void Student::SetEmailAddress(string eAddress) {
    this->emailAddress = eAddress;
}
void Student::SetAge(int studentAge) {
    this->age = studentAge;
}
void Student::SetDaysPerCourse(int daysPerCourse[]) {
    for (int i = 0; i < courseCount; i++) {
        this->daysPerCourse[i] = daysPerCourse[i];
    }
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}




// print function
void Student::print() {
    cout << GetStudentID() << "\t";
    if (GetFirstName().size() < 5) {
        cout << "First Name:" << GetFirstName() << "\t\t";
    }
    else if (GetFirstName().size() > 4) {
        cout << "First Name:" << GetFirstName() << "\t";
    }
    if (GetLastName().size() > 5) {
        cout << "Last Name:" << GetLastName() << "\t";
    }
    else {
        cout << "Last Name:" << GetLastName() << "\t" << "\t";
    }
    cout << "Age:" << GetAge() << "\t";
    cout << "daysInCourse: {" << GetDaysPerCourse()[0] << ", ";
    cout << GetDaysPerCourse()[1] << ", ";
    cout << GetDaysPerCourse()[2] << "}\t";
    if (GetDegreeProgram() == 0) {
        cout << "Degree Program:" << programStrings[0] << endl;
    }
    if (GetDegreeProgram() == 1) {
        cout << "Degree Program:" << programStrings[1] << endl;
    }
    if (GetDegreeProgram() == 2) {
        cout << "Degree Program:" << programStrings[2] << endl;
    }
}
