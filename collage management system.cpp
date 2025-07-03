#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student {
public:
    string Name, Branch;
    int Rollno;

    void input() {
        cout << "Enter student name: ";
        cin.ignore(); 
        getline(cin, Name);
        cout << "Enter Roll no: ";
        cin >> Rollno;
        cout << "Enter Branch: ";
        cin >> Branch;
    }

    void display() {
        cout << "Name: " << Name << ", Rollno: " << Rollno << ", Branch: " << Branch << endl;
    }

    void save() {
        ofstream file("student.txt", ios::app); 
        file << Name << " " << Rollno << " " << Branch << endl;
        file.close();
    }

    static void show() {
        ifstream file("student.txt");
        Student s;
        while (file >> s.Name >> s.Rollno >> s.Branch) {
            s.display();
        }
        file.close();
    }
};

class Faculty {
public:
    string Name, Department;
    int Id;

    void input() {
        cout << "Enter faculty name: ";
        cin.ignore();
        getline(cin, Name);
        cout << "Enter Department: ";
        cin >> Department;
        cout << "Enter ID: ";
        cin >> Id;
    }

    void display() {
        cout << "Name: " << Name << ", Department: " << Department << ", ID: " << Id << endl;
    }

    void save() {
        ofstream file("faculty.txt", ios::app);
        file << Name << " " << Department << " " << Id << endl;
        file.close();
    }

    static void show() {
        ifstream file("faculty.txt");
        Faculty f;
        while (file >> f.Name >> f.Department >> f.Id) {
            f.display();
        }
        file.close();
    }
};

class Course {
public:
    string Name, subject;
    int Code;

    void input() {
        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, Name);
        cout << "Enter subject name: ";
        cin >> subject;
        cout << "Enter code: ";
        cin >> Code;
    }

    void display() {
        cout << "Course Name: " << Name << ", Subject: " << subject << ", Code: " << Code << endl;
    }

    void save() {
        ofstream file("course.txt", ios::app);
        file << Name << " " << subject << " " << Code << endl;
        file.close();
    }

    static void show() {
        ifstream file("course.txt");
        Course c;
        while (file >> c.Name >> c.subject >> c.Code) {
            c.display();
        }
        file.close();
    }
};

int main() {
    int choice;
    do {
        cout << "\n----- Welcome to College Management System -----\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Add Faculty\n";
        cout << "4. View All Faculties\n";
        cout << "5. Add Course\n";
        cout << "6. View All Courses\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student s;
                s.input();
                s.save();
                break;
            }
            case 2:
                Student::show();
                break;

            case 3: {
                Faculty f;
                f.input();
                f.save();
                break;
            }
            case 4:
                Faculty::show();
                break;

            case 5: {
                Course c;
                c.input();
                c.save();
                break;
            }
            case 6:
                Course::show();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
