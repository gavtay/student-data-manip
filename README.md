# Student Data Manipulation

## Overview

This C++ project involves the migration of an existing student system to a new platform, focusing on implementing key Object-Oriented Programming (OOP) concepts. The project consists of creating two classes, namely `Student` and `Roster`, which collectively manage student data and manipulations.

## Scenario

As a contractor for a university, the task involves transferring an existing student system to a new platform using C++. The provided requirements outline the scope of the project, which is to read and manipulate student data. The existing data includes student information such as student ID, first name, last name, email address, age, course completion days, and degree program.

## Key Features

- Implementation of the four pillars of OOP: encapsulation, inheritance, abstraction, and polymorphism.
- Use of two main classes: `Student` and `Roster`, each responsible for distinct aspects of student data management.

## Requirements

The project entails the following components:

1. **Student Class:** Represents individual student data with attributes such as student ID, personal information, course completion days, and degree program.

2. **Roster Class:** Manages a current roster of students within a given course. It handles functions related to adding students, removing students, and printing student information.

3. **Parsing Data:** The program reads a predefined list of student data entries, creating student objects as it parses the data.

4. **Data Manipulation:** The program should demonstrate the manipulation of student data using appropriate function calls, ensuring that the specified data-related outputs are directed to the console.

## Usage

To compile and run the program, follow these steps:

1. Clone this repository to your local machine.

2. Navigate to the project directory using the terminal.

3. Use a C++ compiler to compile the source code files:

   ```bash
   g++ -o main main.cpp Student.cpp Roster.cpp
