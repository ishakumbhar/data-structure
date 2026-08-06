#include <iostream>
#include <stdlib.h>
using namespace std;

struct employee
{
    int id;
    char name[50];
    float salary;
    employee *next;
};


void insert(employee *&head)
{
    employee *newnode = (employee *)malloc(sizeof(employee));

    cout << "Enter Employee ID: ";
    cin >> newnode->id;

    cout << "Enter Employee Name: ";
    cin >> newnode->name;

    cout << "Enter Employee Salary: ";
    cin >> newnode->salary;

    newnode->next = head;
    head = newnode;

    cout << "Employee inserted successfully\n";
} 



void display(employee *head)
{
    if(head == NULL)
    {
        cout << "No employee records available\n";
        return;
    }

    while(head != NULL)
    {
        cout << "\nEmployee ID: " << head->id;
        cout << "\nName: " << head->name;
        cout << "\nSalary: " << head->salary;

        cout << "\n----------------";

        head = head->next;
    }
}



void search(employee *head, int id)
{
    while(head != NULL)
    {
        if(head->id == id)
        {
            cout << "\nEmployee Found";
            cout << "\nID: " << head->id;
            cout << "\nName: " << head->name;
            cout << "\nSalary: " << head->salary;
            return;
        }

        head = head->next;
    }

    cout << "Employee not found";
}



void deleteEmployee(employee *&head, int id)
{
    employee *temp = head;
    employee *prev = NULL;


    
    if(head != NULL && head->id == id)
    {
        head = head->next;
        free(temp);

        cout << "Employee deleted successfully";
        return;
    }


    
    while(temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }


    if(temp == NULL)
    {
        cout << "Employee not found";
        return;
    }


    prev->next = temp->next;
    free(temp);

    cout << "Employee deleted successfully";
}


int main()
{
    employee *head = NULL;

    int choice, id;

    do
    {
        cout << "\n\n1. Insert Employee";
        cout << "\n2. Display Employees";
        cout << "\n3. Search Employee";
        cout << "\n4. Delete Employee";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
                insert(head);
                break;

            case 2:
                display(head);
                break;

            case 3:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                search(head,id);
                break;

            case 4:
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                deleteEmployee(head,id);
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    }while(choice != 5);


   
}
