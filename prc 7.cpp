#include <iostream>
using namespace std;

#define SIZE 5

struct Request {
    int id;
    string name;
    string issue;
};

Request cq[SIZE], dq[SIZE];
int front = -1, rear = -1;
int df = -1, dr = -1;

bool cqEmpty() {
    return front == -1;
}

bool cqFull() {
    return (rear + 1) % SIZE == front;
}

void addRegular(Request r) {
    if (cqFull()) {
        cout << "Regular queue is full!\n";
        return;
    }

    if (cqEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    cq[rear] = r;
    cout << "Regular request added.\n";
}

Request removeRegular() {
    Request r = cq[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;

    return r;
}

bool dqEmpty() {
    return df == -1;
}

bool dqFull() {
    return (df == 0 && dr == SIZE - 1) ||
           (df == dr + 1);
}

void addPriorityFront(Request r) {
    if (dqFull()) {
        cout << "Priority deque is full!\n";
        return;
    }

    if (dqEmpty())
        df = dr = 0;
    else if (df == 0)
        df = SIZE - 1;
    else
        df--;

    dq[df] = r;
    cout << "Priority request added at front.\n";
}

void addPriorityRear(Request r) {
    if (dqFull()) {
        cout << "Priority deque is full!\n";
        return;
    }

    if (dqEmpty())
        df = dr = 0;
    else
        dr = (dr + 1) % SIZE;

    dq[dr] = r;
    cout << "Priority request added at rear.\n";
}

Request removePriorityFront() {
    Request r = dq[df];

    if (df == dr)
        df = dr = -1;
    else
        df = (df + 1) % SIZE;

    return r;
}

Request removePriorityRear() {
    Request r = dq[dr];

    if (df == dr)
        df = dr = -1;
    else
        dr = (dr - 1 + SIZE) % SIZE;

    return r;
}

Request getRequest() {
    Request r;

    cout << "Enter request ID: ";
    cin >> r.id;

    cout << "Enter customer name: ";
    getline(cin >> ws, r.name);

    cout << "Enter issue: ";
    getline(cin >> ws, r.issue);

    return r;
}

void displayRequest(Request r) {
    cout << "ID: " << r.id
         << " | Customer: " << r.name
         << " | Issue: " << r.issue << '\n';
}

void serveNext() {
    Request r;

    if (!dqEmpty()) {
        r = removePriorityFront();
        cout << "\nServing priority customer:\n";
        displayRequest(r);
    }
    else if (!cqEmpty()) {
        r = removeRegular();
        cout << "\nServing regular customer:\n";
        displayRequest(r);
    }
    else {
        cout << "No pending requests.\n";
    }
}

void displayQueues() {
    cout << "\nPriority Requests:\n";

    if (dqEmpty()) {
        cout << "No priority requests.\n";
    } else {
        int i = df;
        while (true) {
            displayRequest(dq[i]);
            if (i == dr) break;
            i = (i + 1) % SIZE;
        }
    }

    cout << "\nRegular Requests:\n";

    if (cqEmpty()) {
        cout << "No regular requests.\n";
    } else {
        int i = front;
        while (true) {
            displayRequest(cq[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
    }
}

int main() {
    int choice;
    Request r;

    do {
        cout << "\n===== CALL CENTER SYSTEM =====\n";
        cout << "1. Add regular request\n";
        cout << "2. Add priority request at front\n";
        cout << "3. Add priority request at rear\n";
        cout << "4. Serve next customer\n";
        cout << "5. Remove priority request from rear\n";
        cout << "6. Display all requests\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            break;
        }

        switch (choice) {
            case 1:
                r = getRequest();
                addRegular(r);
                break;

            case 2:
                r = getRequest();
                addPriorityFront(r);
                break;

            case 3:
                r = getRequest();
                addPriorityRear(r);
                break;

            case 4:
                serveNext();
                break;

            case 5:
                if (dqEmpty()) {
                    cout << "No priority requests.\n";
                } else {
                    r = removePriorityRear();
                    cout << "Removed request:\n";
                    displayRequest(r);
                }
                break;

            case 6:
                displayQueues();
                break;

            case 7:
                cout << "System closed.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}

