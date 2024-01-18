#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Student.h"

using namespace std;

// Function prototypes
void viewStudentGrades(const vector<Student>& students);
void addStudentData(vector<Student>& students);

int main() {
    ifstream studentFile("StudentFile.txt");
    ofstream outFile("StudentFile.txt", ios::app);

    if (!studentFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    vector<Student> students;  // Vector to hold student data

    int choice;
    do {
        cout << "\n***** Student Grade Management System *****" << endl;
        cout << "1. View Student Grades" << endl;
        cout << "2. Add Student Data" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewStudentGrades(students);
                break;
            case 2:
                addStudentData(students);
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    studentFile.close();
    outFile.close();
    return 0;
}

// Function to view student grades
void viewStudentGrades(const vector<Student>& students) {
    cout << setw(15) << left << "Student Name" << setw(5) << "Grade" << endl;
    for (const auto& student : students) {
        cout << setw(15) << left << student.getName() << setw(5) << student.getGrade() << endl;
    }
}

// Function to add student data
void addStudentData(vector<Student>& students) {
    Student newStudent;
    string studentName;
    int studentGrade;

    cout << "Enter student name: ";
    cin >> studentName;
    newStudent.setName(studentName);

    cout << "Enter student grade: ";
    cin >> studentGrade;
    newStudent.setGrade(studentGrade);

    students.push_back(newStudent);  // Add student to vector
    cout << "Data successfully added!" << endl;
}
