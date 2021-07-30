#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

#include "degree.h"

class Student {
    
    public:

        Student();
        // constructor
        Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

        // accessors
        std::string GetStudentID();
        std::string GetFirstName();
        std::string GetLastName();
        std::string GetEmailAddress();
        int GetStudentAge();
        int *GetNumDaysEachCourse();
        DegreeProgram GetDegreeProgram();

        // mutators
        void SetStudentID(std::string studentID);
        void SetFirstName(std::string firstName);
        void SetLastName(std::string lastName);
        void SetEmailAddress(std::string emailAddress);
        void SetStudentAge(int studentAge);
        void SetNumDaysEachCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
        void SetDegreeProgram(DegreeProgram degreeProgram);

        // print function
        std::string Print();

    
    private:
        // variables
        std::string studentID;
        std::string firstName;
        std::string lastName;
        std::string emailAddress;
        int studentAge;
        int daysInCourse [3];
        DegreeProgram degreeProgram;

};

#endif //STUDENT_H