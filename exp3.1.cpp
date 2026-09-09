#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song *prev;
    Song *next;
};


void addSong(Song *&head, string name) {
    Song *newSong = new Song;
    newSong->name = name;
    newSong->next = NULL;
    newSong->prev = NULL;

    if (head == NULL) {
        head = newSong;
    } else {
        Song *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->prev = temp;
    }
}


void deleteSong(Song *&head, string name) {
    Song *temp = head;

    while (temp != NULL && temp->name != name) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Song not found!" << endl;
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Song deleted successfully!" << endl;
}


void displaySongs(Song *head) {
    Song *temp = head;

    if (head == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    cout << "\nPlaylist (Forward):\n";

    while (temp != NULL) {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

int main() {
    Song *head = NULL;
    int choice;
    string name;

    do {
        cout << "\n1. Add Song";
        cout << "\n2. Delete Song";
        cout << "\n3. Display Playlist";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, name);
                addSong(head, name);
                break;

            case 2:
                cout << "Enter song name to delete: ";
                getline(cin, name);
                deleteSong(head, name);
                break;

            case 3:
                displaySongs(head);
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}