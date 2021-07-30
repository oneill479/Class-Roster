#include <iostream>
#include <string>

#include "student.h"

Student::Student() {}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    SetStudentID(studentID);
    SetFirstName(firstName);
    SetLastName(lastName);
    SetEmailAddress(emailAddress);
    SetStudentAge(studentAge);
    SetNumDaysEachCourse(daysInCourse1, daysInCourse2, daysInCourse3);
    SetDegreeProgram(degreeprogram);
}

/*------------------------------------------------------------------------------
 * GETTERS
 *----------------------------------------------------------------------------*/

// get student ID
std::string Student::GetStudentID() {
    return studentID;
}

// get first name
std::string Student::GetFirstName() {
    return firstName;
}

// get last name
std::string Student::GetLastName() {
    return lastName;
}

// get email address
std::string Student::GetEmailAddress() {
    return emailAddress;
}

// get student age
int Student::GetStudentAge() {
    return studentAge;
}

// get number of days for each course
int *Student::GetNumDaysEachCourse() {
    return daysInCourse;
}

// get degree program
DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}

/*------------------------------------------------------------------------------
 * SETTERS
 *----------------------------------------------------------------------------*/

// set student id
void Student::SetStudentID(std::string studentID) {
    this->studentID = studentID;
}

// set first name
void Student::SetFirstName(std::string firstName) {
    this->firstName = firstName;
}

// set last name
void Student::SetLastName(std::string lastName) {
    this->lastName = lastName;
}

// set email address
void Student::SetEmailAddress(std::string emailAddress) {
    this->emailAddress = emailAddress;
}

// set student age
void Student::SetStudentAge(int studentAge) {
    this->studentAge = studentAge;
}

// set number of days in each course
void Student::SetNumDaysEachCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
}

// set number of days in each course
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

std::string Student::Print() {
    std::string print;
    std::string degree;

    print.append(GetStudentID() + "\t");
    print.append("First Name: " + GetFirstName() + "\t");
    print.append("Last Name: " + GetLastName() + "\t");
    print.append("Age: " + std::to_string(GetStudentAge()) + "\t\t");
    print.append("daysInCourse: {" + std::to_string(GetNumDaysEachCourse()[0]) + ", " + std::to_string(GetNumDaysEachCourse()[1]) + ", " + std::to_string(GetNumDaysEachCourse()[2]) + "}\t");
    
    

    if (GetDegreeProgram() == SECURITY) {
        degree = "Security";
    }
    if (GetDegreeProgram() == NETWORK) {
        degree = "Network";
    }
    if (GetDegreeProgram() == SOFTWARE) {
        degree = "Software";
    }
    
    print.append("Degree Program: " + degree + "\t");
    print.append("\n");

    return print;

}
