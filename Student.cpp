// Student.cpp
#include "Student.h"

void Student::setName(const std::string& studentName) {
    name = studentName;
}

void Student::setGrade(int studentGrade) {
    grade = studentGrade;
}

std::string Student::getName() const {
    return name;
}

int Student::getGrade() const {
    return grade;
}
