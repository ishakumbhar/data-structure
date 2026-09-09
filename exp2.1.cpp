#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
    Employee *next;
};


void addEmployee(Employee *&head, int id, string name, float salary) {
    Employee *newEmployee = new Employee;

    newEmployee->id = id;
    newEmployee->name = name;
    newEmployee->salary = salary;
    newEmployee->next = NULL;

    if (head == NULL) {
        head = newEmployee;
    } else {
        Employee *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newEmployee;
    }
}


void searchEmployee(Employee *head, int searchId) {
    Employee *temp = head;

    while (temp != NULL) {
        if (temp->id == searchId) {
            cout << "\nEmployee Found!" << endl;
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Salary: " << temp->salary << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nEmployee not found!" << endl;
}

int main() {
    Employee *head = NULL;
    int n, id, searchId;
    string name;
    float salary;

    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Employee ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Salary: ";
        cin >> salary;

        addEmployee(head, id, name, salary);
    }

    cout << "\nEnter Employee ID to search: ";
    cin >> searchId;

    searchEmployee(head, searchId);

    return 0;
}