#include <iostream>
using namespace std;

struct Node
{
    int patient;
    Node* next;
};

class Queue
{
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void arrive(int patient)
    {
        Node* newNode = new Node();
        newNode->patient = patient;
        newNode->next = NULL;

        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Patient " << patient << " arrived." << endl;
        cout << "Front patient: " << front->patient << endl;
    }

    void attend()
    {
        if (front == NULL)
        {
            cout << "Error: No patients waiting." << endl;
            return;
        }

        Node* temp = front;

        cout << "Patient " << front->patient << " attended." << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;

        if (front != NULL)
            cout << "Front patient: " << front->patient << endl;
        else
            cout << "No patients waiting." << endl;
    }
};

int main()
{
    Queue q;
    int choice, patient;

    while (true)
    {
        cout << "1. Arrive" << endl;
        cout << "2. Attend" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter patient number: ";
            cin >> patient;

            q.arrive(patient);
        }
        else if (choice == 2)
        {
            q.attend();
        }
        else if (choice == 3)
        {
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

        cout << endl;
    }

    return 0;
} 