
#include <iostream>
using namespace std;

class Node {
public:
    int code;
    Node* next;

    Node(int c) {
        code = c;
        next = NULL;
    }
};

class Library {
    Node* shelves[10];

public:
    Library() {
        for (int i = 0; i < 10; i++) {
            shelves[i] = NULL;
        }
    }

    void addBook(int code) {
        int index = code % 10;

        Node* newNode = new Node(code);

        if (shelves[index] == NULL) {
            shelves[index] = newNode;
        } else {
            Node* temp = shelves[index];

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "Book " << code
             << " added to shelf " << index << endl;
    }

    void display() {
        cout << "\nFinal Shelf Contents:\n";

        for (int i = 0; i < 10; i++) {
            cout << "Shelf " << i << ": ";

            Node* temp = shelves[i];

            if (temp == NULL) {
                cout << "Empty";
            }

            while (temp != NULL) {
                cout << temp->code << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
    }

    ~Library() {
        for (int i = 0; i < 10; i++) {
            Node* temp = shelves[i];

            while (temp != NULL) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }
    }
};

int main() {
    Library lib;
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> code;

        if (code < 0) {
            cout << "Book code must be non-negative." << endl;
            i--;
            continue;
        }

        lib.addBook(code);
    }

    lib.display();

    return 0;
}
 