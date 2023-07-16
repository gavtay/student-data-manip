#include <iostream>
#include "roster.h"
#include "student.h"
using std::cout;
using std::string;
using std::endl;

int main() {
    // string array is created holding the data provided
    // this array will hold 5 strings, 3 of which will contain intended errors
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Gavin,Taylor,gtay205@wgu.edu,24,5,16,48,SOFTWARE"
    };



    // printing to screen an about me section
    cout << "Course: C867 - Scripting and Programming: Applications\t" << "Language Used: C++\t";
    cout << endl << "Student ID: 011097232\t" << "Student Name: Gavin Taylor" << endl << endl;



    Roster classRoster;


    // The object classRoster is filled with the student data that is gathered from the e2 object
    for (int i = 0; i < 5; i++) {
        classRoster.e2(studentData[i]);
    }




    // The print all function is called and is found through the roster.h file. This print function will print all student information to screen in an ordered format.
    cout << "Displaying all students:" << endl;
    classRoster.printAll();




    // this function is called to print emails that are invalid that is located in the roster.cpp file.
    classRoster.printInvalidEmails();




    // average days per course for each student is printed to screen from the function call
    cout << "Calculating average days in course per student..." << endl << "Printing average days in course per student: " << endl;
    // Loop created in main and is used to call this function multiple times for each student
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID(), classRoster.classRosterArray[i]->GetDaysPerCourse()[0], classRoster.classRosterArray[i]->GetDaysPerCourse()[1], classRoster.classRosterArray[i]->GetDaysPerCourse()[2]);
    }
    cout << endl;




    // students are all printed to screen but are formated by their degree
    cout << "Printing students by degree program..." << endl;
    for (int i = 0; i < 1; i++) {
        classRoster.printByDegreeProgram((DegreeProgram)i);
    }
    cout << endl;




    // the student with ID A3 is removed here, and then all students are printed to screen to display that the student was successfully removed
    classRoster.remove("A3");
    classRoster.printAll();
    // a student with ID A3 is attempted to be removed here, however, this will fail and will display a message
    classRoster.remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.
    cout << endl;




    return 0;
}
