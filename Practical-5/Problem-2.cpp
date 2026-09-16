#include <iostream>
using namespace std;

class SinglyNode
{
public:
    string name;
    SinglyNode *next;

    SinglyNode(string n)
    {
        name = n;
        next = NULL;
    }
};

class SinglyCircular
{
    SinglyNode *head;

public:
    SinglyCircular()
    {
        head = NULL;
    }

    void insert(string name, int pos)
    {
        SinglyNode *newNode = new SinglyNode(name);

        // Empty circle
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        // Insert at first position
        if (pos == 1)
        {
            SinglyNode *last = head;

            while (last->next != head)
                last = last->next;

            newNode->next = head;
            last->next = newNode;
            head = newNode;
            return;
        }

        SinglyNode *temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove(int pos)
    {
        if (head == NULL)
        {
            cout << "Circle is empty\n";
            return;
        }

        // Only one student
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        // Remove first student
        if (pos == 1)
        {
            SinglyNode *last = head;

            while (last->next != head)
                last = last->next;

            SinglyNode *temp = head;

            head = head->next;
            last->next = head;

            delete temp;
            return;
        }

        SinglyNode *temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        if (temp->next == head)
        {
            cout << "Invalid position\n";
            return;
        }

        SinglyNode *del = temp->next;
        temp->next = del->next;

        delete del;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty\n";
            return;
        }

        SinglyNode *temp = head;

        do
        {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};




class DoublyNode
{
public:
    string name;
    DoublyNode *next;
    DoublyNode *prev;

    DoublyNode(string n)
    {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircular
{
    DoublyNode *head;

public:
    DoublyCircular()
    {
        head = NULL;
    }

    void insert(string name, int pos)
    {
        DoublyNode *newNode = new DoublyNode(name);

        // Empty circle
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        // Insert at first position
        if (pos == 1)
        {
            DoublyNode *last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;

            head = newNode;
            return;
        }

        DoublyNode *temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void remove(int pos)
    {
        if (head == NULL)
        {
            cout << "Circle is empty\n";
            return;
        }

        // Only one student
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        // Remove first student
        if (pos == 1)
        {
            DoublyNode *last = head->prev;
            DoublyNode *temp = head;

            head = head->next;

            last->next = head;
            head->prev = last;

            delete temp;
            return;
        }

        DoublyNode *temp = head;

        for (int i = 1; i < pos && temp->next != head; i++)
            temp = temp->next;

        if (temp == head)
        {
            cout << "Invalid position\n";
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty\n";
            return;
        }

        DoublyNode *temp = head;

        do
        {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};




int main()
{
   

    cout << "SINGLY CIRCULAR LINKED LIST\n";

    SinglyCircular s;

    s.insert("A", 1);
    cout << "After A joins: ";
    s.display();

    s.insert("B", 2);
    cout << "After B joins: ";
    s.display();

    s.insert("C", 3);
    cout << "After C joins: ";
    s.display();

    s.insert("D", 4);
    cout << "After D joins: ";
    s.display();

    s.remove(3);
    cout << "After C leaves: ";
    s.display();

    s.insert("P", 2);
    cout << "After P joins at position 2: ";
    s.display();


   

    cout << "\nDOUBLY CIRCULAR LINKED LIST\n";

    DoublyCircular d;

    d.insert("A", 1);
    cout << "After A joins: ";
    d.display();

    d.insert("B", 2);
    cout << "After B joins: ";
    d.display();

    d.insert("C", 3);
    cout << "After C joins: ";
    d.display();

    d.insert("D", 4);
    cout << "After D joins: ";
    d.display();

    d.remove(3);
    cout << "After C leaves: ";
    d.display();

    d.insert("P", 2);
    cout << "After P joins at position 2: ";
    d.display();

    return 0;
}