#include <iostream>
using namespace std;

#define MAX 5

int arr[MAX], topA = -1;

struct Node {
    int id;
    Node* next;
};

Node* topL = NULL;

void pushArray(int id) {
    if (topA == MAX - 1)
        cout << "Stack Overflow!\n";
    else {
        arr[++topA] = id;
        cout << "Ticket " << id << " added.\n";
    }
}

void popArray() {
    if (topA == -1)
        cout << "Stack is empty!\n";
    else
        cout << "Removed ticket: " << arr[topA--] << endl;
}

void peekArray() {
    if (topA == -1)
        cout << "Stack is empty!\n";
    else
        cout << "Latest ticket: " << arr[topA] << endl;
}

void displayArray() {
    if (topA == -1) {
        cout << "No reservations.\n";
        return;
    }

    for (int i = topA; i >= 0; i--)
        cout << arr[i] << endl;
}

void pushList(int id) {
    Node* n = new Node{id, topL};
    topL = n;
    cout << "Ticket " << id << " added.\n";
}

void popList() {
    if (topL == NULL) {
        cout << "Stack is empty!\n";
        return;
    }

    Node* temp = topL;
    cout << "Removed ticket: " << temp->id << endl;
    topL = topL->next;
    delete temp;
}

void peekList() {
    if (topL == NULL)
        cout << "Stack is empty!\n";
    else
        cout << "Latest ticket: " << topL->id << endl;
}

void displayList() {
    if (topL == NULL) {
        cout << "No reservations.\n";
        return;
    }

    Node* temp = topL;
    while (temp !=NULL) {
        cout << temp->id << endl;
        temp = temp->next;
    }
}

int main() {
    int method, choice, id;

    cout << "Choose implementation:\n";
    cout << "1. Array\n2. Linked List\n";
    cin >> method;

    if (method != 1 && method != 2) {
        cout << "Invalid implementation!\n";
        return 0;
    }

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n";
        cout << "4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ticket ID: ";
                cin >> id;
                if (method == 1)
                    pushArray(id);
                else
                    pushList(id);
                break;

            case 2:
                if (method == 1)
                    popArray();
                else
                    popList();
                break;

            case 3:
                if (method == 1)
                    peekArray();
                else
                    peekList();
                break;

            case 4:
                if (method == 1)
                    displayArray();
                else
                    displayList();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    while (topL != NULL   ) {
        Node* temp = topL;
        topL = topL->next;
        delete temp;
    }

    return 0;
}

