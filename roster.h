#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <iostream>
#include <iomanip>

#include "student.h"

class Roster : public Student {
    
    public:

        Roster();

        void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram, int i);

        void remove(std::string studentID);

        void printAll();

        void printAverageDaysInCourse(std::string studentID);

        void printInvalidEmails();

        void printByDegreeProgram(DegreeProgram degreeProgram);

        ~Roster();

    private:
        Student *classRosterArray[5];
        
};

#endif //ROSTER_H