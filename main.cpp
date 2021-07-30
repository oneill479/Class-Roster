#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "roster.h"
#include "student.h"
#include "degree.h"

int main () {

    std::cout << "-------------------------------" << std::endl;
    std::cout << "C867: Scripting and Programming" << std::endl;
    std::cout << "C++" << std::endl;
    std::cout << "Student ID: #001092382" << std::endl;
    std::cout << "Caleb O'Neill" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    Roster classRoster;
    DegreeProgram degreeProgram;

const std::string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Caleb,Oneill,oneill479@gmail.com,28,15,14,20,SOFTWARE"};



    for (int i = 0; i < 5; ++i) {
        std::string studentInfo = studentData[i];
        std::vector<std::string> result;
        std::stringstream ss(studentInfo);
        while(ss.good()) {
            std::string substr;
            getline(ss, substr, ',');
            result.push_back(substr);
        }


        if (result.at(8) == "SECURITY") {
            degreeProgram = DegreeProgram::SECURITY;
        }
        if (result.at(8) == "NETWORK") {
            degreeProgram = DegreeProgram::NETWORK;
        }
        if (result.at(8) == "SOFTWARE") {
            degreeProgram = DegreeProgram::SOFTWARE;
        }

        classRoster.add(result.at(0), result.at(1), result.at(2), result.at(3), std::stoi(result.at(4)), std::stoi(result.at(5)), std::stoi(result.at(6)), std::stoi(result.at(7)), degreeProgram, i);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();

    // loop through each student and print average days
    for (int i = 1; i <= 5; ++i) {
        std::string student = "A" + std::to_string(i);
        classRoster.printAverageDaysInCourse(student);

        // add additional end line for space
        if (i == 5) {
            std::cout << std::endl;
        }
    }

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}