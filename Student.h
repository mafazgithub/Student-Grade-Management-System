// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int grade;

public:
    void setName(const std::string& studentName);
    void setGrade(int studentGrade);

    std::string getName() const;
    int getGrade() const;
};

#endif // STUDENT_H
