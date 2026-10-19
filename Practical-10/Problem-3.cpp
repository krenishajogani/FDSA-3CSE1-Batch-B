
#include <iostream>
using namespace std;

class HashTable {
    int table[10];

public:
    HashTable() {
        for (int i = 0; i < 10; i++) {
            table[i] = -1;
        }
    }

    int hash1(int id) {
        return id % 10;
    }

    int hash2(int id) {
        return 7 - (id % 7);
    }

    void insert(int id) {
        int index = hash1(id);
        int step = hash2(id);
        int i = 0;

        while (i < 10 && table[index] != -1) {
            index = (hash1(id) + i * step) % 10;
            i++;
        }

        if (i == 10) {
            cout << "Hash table is full! Cannot insert "
                 << id << endl;
        } else {
            table[index] = id;
            cout << "Student ID " << id
                 << " inserted at slot " << index << endl;
        }
    }

    void display() {
        cout << "\nFinal Hash Table:\n";

        for (int i = 0; i < 10; i++) {
            cout << "Slot " << i << ": ";

            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << endl;
        }
    }
};

int main() {
    HashTable h;
    int n, id;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> id;

        if (id < 0) {
            cout << "ID must be non-negative." << endl;
            i--;
            continue;
        }

        h.insert(id);
    }

    h.display();

    return 0;
}
 