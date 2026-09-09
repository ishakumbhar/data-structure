#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

class Stack {
    string pages[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    
    void push(string page) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            pages[top] = page;
            cout << page << " visited successfully." << endl;
        }
    }

    
    void pop() {
        if (top == -1) {
            cout << "No previous page!" << endl;
        } else {
            cout << "Going back from: " << pages[top] << endl;
            top--;
        }
    }

    
    void peek() {
        if (top == -1) {
            cout << "Browser history is empty!" << endl;
        } else {
            cout << "Current page: " << pages[top] << endl;
        }
    }

    
    void display() {
        if (top == -1) {
            cout << "Browser history is empty!" << endl;
        } else {
            cout << "\nVisited Webpages:\n";

            for (int i = top; i >= 0; i--) {
                cout << pages[i] << endl;
            }
        }
    }
};

int main() {
    Stack browser;
    int choice;
    string page;

    do {
        cout << "\n1. Visit Page (Push)";
        cout << "\n2. Back (Pop)";
        cout << "\n3. Current Page (Peek)";
        cout << "\n4. Display History";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter webpage name: ";
                cin >> page;
                browser.push(page);
                break;

            case 2:
                browser.pop();
                break;

            case 3:
                browser.peek();
                break;

            case 4:
                browser.display();
                break;

            case 5:
                cout << "Exiting...........";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}Antara Mane