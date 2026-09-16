#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    void insertBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAfter(string target, string song) {
        Node* temp = head;

        while (temp != NULL && temp->song != target) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found!" << endl;
            return;
        }

        Node* newNode = new Node(song);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }

        temp->next = newNode;
    }

    void deleteFirst() {
        if (head == NULL) {
            cout << "Playlist is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;
    }

    int countSongs() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "Empty";
            return;
        }

        while (temp != NULL) {
            cout << temp->song;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }
    }
};

int main() {

    Playlist p;

    cout << "Music Playlist\n";
    cout << "--------------\n";

    p.insertBeginning("Song 1");
    p.insertEnd("Song 2");
    p.insertEnd("Song 3");
    cout << "\nInitial playlist:\n";
    p.display();
    
    cout << "\nTotal songs: " << p.countSongs();

    p.insertEnd("Song 4");
    cout << "\n\nSong 4 added at end:\n";
    p.display();

    cout << "\nTotal songs: " << p.countSongs();

    p.insertBeginning("Song 5");
    cout << "\n\nSong 5 added at Beginning:\n";
    p.display();

    cout << "\nTotal songs: " << p.countSongs();

    p.insertAfter("Song 2", "Song 8");
    cout << "\n\nSong 8 inserted after Song 2:\n";
    p.display();

    cout << "\nTotal songs: " << p.countSongs();

    p.deleteFirst();
    cout << "\n\nFirst song removed:\n";
    p.display();

    cout << "\nTotal songs: " << p.countSongs();
    
    cout << "\n\nSong 10 inserted after Song 20:\n";
    p.insertAfter("Song 20", "Song 10");

    return 0;
}