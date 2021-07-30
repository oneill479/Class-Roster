#include <cstring>

#include "roster.h"
#include "student.h"


Roster::Roster() {}

// adds a student to roster
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram, int i) {

    classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);

    return;
}

// removes a student by id
void Roster::remove(std::string studentID) {

    bool found = false;

    for (int i = 0; i < 5; ++i) {

        if (classRosterArray[i] == nullptr) {
            // Do Nothing
        }
        else if (studentID == classRosterArray[i]->GetStudentID()) {
            classRosterArray[i] = nullptr;

            found = true;
        }
    }

    if (found == false) {
        std::cout << "Student ID not found." << "\n" << std::endl;
    }

    return;
}

void Roster::printAll() {

    std::string print;

    for (int i = 0; i < 5; ++i) {

        if (classRosterArray[i] != NULL) {
            print.append(classRosterArray[i]->Print());
        }
    }

    std::cout << print << std::endl;

    return;
}

void Roster::printAverageDaysInCourse(std::string studentID) {

    bool found = false;
    int courseOne, courseTwo, courseThree;
    double averageDays;


    for (int i = 0; i < 5; ++i) {
        if (studentID == classRosterArray[i]->GetStudentID()) {
            courseOne = classRosterArray[i]->GetNumDaysEachCourse()[0];
            courseTwo = classRosterArray[i]->GetNumDaysEachCourse()[1];
            courseThree = classRosterArray[i]->GetNumDaysEachCourse()[2];

            averageDays = double(courseOne + courseTwo + courseThree) / 3;

            found = true;
        }
    }

    if (found == false) {
        std::cout << "Student ID not found." << std::endl;

        return;
    }

    std::cout << std::fixed;
    std::cout << studentID << " average days: " << std::setprecision(1) << averageDays << std::endl;

    return;

}

void Roster::printInvalidEmails() {

    std::cout << "Invalid Emails: ";

    for (int i = 0; i < 5; ++i) {

        std::string email = classRosterArray[i]->GetEmailAddress();

        // create a character array with the length of the string
        int size = (email.size() + 1);

        char *newStr = new char[size];

        // copy the contents of the string into the character array
        strcpy(newStr, email.c_str());

        // string with comma
        std::string ending = "  ";

        // @
        if (strchr(newStr, '@') == NULL || strchr(newStr, '.') == NULL || strchr(newStr, ' ') != NULL) {
            std::cout << email << ending;
        }

        delete newStr;

    }

    std::cout << "\n" << std::endl;

    return;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

    std::string printDegree;

    for (int i = 0; i < 5; ++i) {
        if (degreeProgram == classRosterArray[i]->GetDegreeProgram()) {
            printDegree.append(classRosterArray[i]->Print());
        }
    }

    std::cout << printDegree << std::endl;

    return;
}

Roster::~Roster() {
}