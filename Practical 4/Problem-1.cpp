#include<iostream>
using namespace std;

class Node{
    public:
   int data;
   Node*next;

 };
  
 void insertEnd(Node*& head, int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertBeginning(Node*& head, int value){

    Node* newNode = new Node();

    newNode -> data = value;
    newNode -> next = head;
    
    head = newNode;
}

 void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;

    // Insert at beginning
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    // Move to the node before the required position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    
    if (temp == NULL) {
        delete newNode;
        cout << "Invalid position!" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    if (head == NULL)
        return;

    cout << head->data << " ";
    display(head->next);
}
 
int main() {
    Node* head = NULL;

    int value[] = {10, 11, 12, 13};
    int n = 4;

    for (int i = 0; i < n; i++) {
        insertEnd(head, value[i]);
    }

    cout << "Hospital Patient Queue\n";
    cout << "----------------------\n";

    cout << "\nInitial patient queue:\n";
    display(head);

    cout << "\n\nCritical patient (Token 14):\n";
    insertBeginning(head, 14);
    display(head);

    cout<<"\n\nRoutine Patient(Token 15):\n";
    insertEnd(head,15);
    display(head);

    cout<<"\n\nPatient with a priority number(Token 27) inserted at position 2:\n";
    insertAtPosition(head,27,2);
    display(head);
  
    cout<<"\n\nPatient with a priority number(Token 27) inserted at position 12:\n";
    insertAtPosition(head,27,12);
    

    return 0;
}
