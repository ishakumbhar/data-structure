#include <iostream>
#include <string>
using namespace std;

struct Employee 
{
    int id;
    string name;
    float salary;
    Employee *next;
};


Employee *head = NULL;

void insertEmployee()
 {
    Employee *newEmp = new Employee;

    cout << "Enter Employee ID: ";
    cin >> newEmp->id;

    cout << "Enter Employee Name: ";
    cin >> newEmp->name;

    cout << "Enter Employee Salary: ";
    cin >> newEmp->salary;

    newEmp->next = NULL;
    

    if (head == NULL) 
	{
		
        head = newEmp;
        
    }
    
	 else 
	{
		
        Employee *temp = head;
        while (temp->next != NULL)
        
		 {
		 	
            temp = temp->next;
            
        }
        
        temp->next = newEmp;
        
    }

    cout << "Employee inserted successfully." << endl;
    
}


void deleteEmployee(int id)

 {
 	
    if (head == NULL)
    
	 {
	 	
        cout << "List is empty." << endl;
        return;
        
    }

    Employee *temp = head;
    Employee *prev = NULL;

    
    if (temp != NULL && temp->id == id)
    
	 {
	 	
        head = temp->next;
        delete temp;
        cout << "Employee deleted successfully." << endl;
        return;
        
    }

  
    while (temp != NULL && temp->id != id)
    
	 {
	 	
        prev = temp;
        temp = temp->next;
        
    }

 
    if (temp == NULL)
    
	 {
	 	
        cout << "Employee not found." << endl;
        return;
        
    }

    prev->next = temp->next;
    delete temp;

    cout << "Employee deleted successfully." << endl;
    
}


void searchEmployee(int id)

 {
 	
    Employee *temp = head;

    while (temp != NULL)
    
	 {
	 	
        if (temp->id == id)
        
		 {
            cout << "\nEmployee Found" << endl;
            cout << "ID     : " << temp->id << endl;
            cout << "Name   : " << temp->name << endl;
            cout << "Salary : " << temp->salary << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Employee not found." << endl;
}

void displayEmployees() 

 {
 	
    Employee *temp = head;

    if (temp == NULL)
    
	 {
	 	
        cout << "No employee records available." << endl;
        return;
        
    }

    cout << "\nEmployee Records:" << endl;
    
    while (temp != NULL)
	 {
        cout << "ID: " << temp->id
             << "\tName: " << temp->name
             << "\tSalary: " << temp->salary << endl;
        temp = temp->next;
    }
    
}


int main()
 {
    int choice, id;

    do {
    	
        cout << "\n--- Employee Management ---" << endl;
        cout << "1. Insert Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Display Employees" << endl;
        cout << "5. Exit" << endl;
        

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
		 
		{
			
        case 1:
            insertEmployee();
            break;
            

        case 2:
            cout << "Enter Employee ID to delete: ";
            cin >> id;
            deleteEmployee(id);
            break;
            

        case 3:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            searchEmployee(id);
            break;
            

        case 4:
            displayEmployees();
            break;
            

        case 5:
            cout << "Exiting..." << endl;
            break;
            

        default:
            cout << "Invalid choice." << endl;
            
        }

    } 
	
	while (choice != 5);

    return 0;
}
