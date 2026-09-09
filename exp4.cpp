#include <iostream>
#include <string>
using namespace std;

struct Team {
    string name;
    Team *next;
};


void addTeam(Team *&head, string name) {
    Team *newTeam = new Team;
    newTeam->name = name;

    if (head == NULL) {
        head = newTeam;
        newTeam->next = head;
    } else {
        Team *temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newTeam;
        newTeam->next = head;
    }
}


void displaySchedule(Team *head) {
    if (head == NULL) {
        cout << "No teams available!" << endl;
        return;
    }

    Team *temp = head;

    cout << "\nRound Robin Team Order:\n";

    do {
        cout << temp->name << endl;
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Team *head = NULL;
    int n;
    string name;

    cout << "Enter number of teams: ";
    cin >> n;

    cin.ignore();

    
    for (int i = 0; i < n; i++) {
        cout << "Enter team name: ";
        getline(cin, name);

        addTeam(head, name);
    }

    
    displaySchedule(head);

    return 0;
}