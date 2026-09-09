#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node *next;
};

class Stack {
    Node *top;

public:
    Stack() {
        top = NULL;
    }

    void push(string page) {
        Node *newNode = new Node;

        newNode->page = page;
        newNode->next = top;
        top = newNode;

        cout << "Visited: " << page << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "No previous page!" << endl;
        } else {
            Node *temp = top;

            cout << "Going back from: "
                 << top->page << endl;

            top = top->next;
            delete temp;
        }
    }

    void display() {
        Node *temp = top;

        cout << "\nBrowser History:\n";

        while (temp != NULL) {
            cout << temp->page << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Stack browser;

    browser.push("Google");
    browser.push("YouTube");
    browser.push("Instagram");

    browser.pop();

    browser.display();

    return 0;
}