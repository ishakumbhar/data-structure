#include <iostream>
#include <string>
using namespace std;


struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void addSong(string song) {
        Node* newNode = new Node(song);

        if (head == nullptr) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << song << " added to playlist.\n";
    }

    void playCurrent() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
        } else {
            cout << "Playing: " << current->song << endl;
        }
    }

    
    void nextSong() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
        } 
        else if (current->next == nullptr) {
            cout << "Already at the last song.\n";
        } 
        else {
            current = current->next;
            cout << "Playing next: " << current->song << endl;
        }
    }

    
    void previousSong() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
        } 
        else if (current->prev == nullptr) {
            cout << "Already at the first song.\n";
        } 
        else {
            current = current->prev;
            cout << "Playing previous: " << current->song << endl;
        }
    }

   
    void display() {
        Node* temp = head;

        cout << "\nPlaylist:\n";

        while (temp != nullptr) {
            if (temp == current)
                cout << "-> ";

            cout << temp->song << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("shape of you");
    playlist.addSong("ride it");
    playlist.addSong("cheap thrills");
    playlist.addSong("woman");

    playlist.display();

    playlist.playCurrent();

    playlist.nextSong();
    playlist.nextSong();

    playlist.previousSong();

    playlist.display();

    return 0;
}