
#include <iostream>
using namespace std;

class ParkingLot {
    int slots[10];

public:
    ParkingLot() {
        for (int i = 0; i < 10; i++) {
            slots[i] = -1;
        }
    }

    void parkVehicle(int regno) {
        int index = regno % 10;
        int count = 0;

        while (slots[index] != -1 && count < 10) {
            index = (index + 1) % 10;
            count++;
        }

        if (count == 10) {
            cout << "Parking full! Vehicle " << regno
                 << " cannot be parked." << endl;
        } else {
            slots[index] = regno;
            cout << "Vehicle " << regno
                 << " parked at slot " << index << endl;
        }
    }

    void display() {
        cout << "\nFinal Parking Slots:\n";

        for (int i = 0; i < 10; i++) {
            cout << "Slot " << i << ": ";

            if (slots[i] == -1)
                cout << "Empty";
            else
                cout << slots[i];

            cout << endl;
        }
    }
};

int main() {
    ParkingLot p;
    int n, regno;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> regno;
        p.parkVehicle(regno);
    }

    p.display();

    return 0;
}
