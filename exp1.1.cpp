#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};


void display(Student *s, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nRoll No: " << (s + i)->rollNo;
        cout << "\nName: " << (s + i)->name;
        cout << "\nMarks: " << (s + i)->marks << endl;
    }
}
void search(Student *s, int n, int roll) {
    for (int i = 0; i < n; i++) {
        if ((s + i)->rollNo == roll) {
            cout << "\nStudent Found: "
                 << (s + i)->name << endl;
            return;
        }
    }
    cout << "\nStudent not found!" << endl;
}


void update(Student *s, int n, int roll) {
    for (int i = 0; i < n; i++) {
        if ((s + i)->rollNo == roll) {
            cout << "Enter new marks: ";
            cin >> (s + i)->marks;
            cout << "Record updated successfully!";
            return;
        }
    }
    cout << "Student not found!";
}

int main() {
    Student students[3];

    for (int i = 0; i < 3; i++) {
        cout << "\nEnter Roll No: ";
        cin >> students[i].rollNo;

        cout << "Enter Name: ";
        cin >> students[i].name;

        cout << "Enter Marks: ";
        cin >> students[i].marks;
    }

    display(students, 3);

    int roll;
    cout << "\nEnter Roll No to search: ";
    cin >> roll;
    search(students, 3, roll);

    cout << "\nEnter Roll No to update: ";
    cin >> roll;
    update(students, 3, roll);

    display(students, 3);

    return 0;
}