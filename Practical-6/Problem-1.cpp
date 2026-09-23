#include <iostream>
using namespace std;

class Stack
{
    int arr[3];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if(top == 2)
        {
            cout << "Counter is full. No more tray will be added." << endl;
            return;
        }

        top++;
        arr[top] = x;

        cout << "Tray " << x << " added to counter." << endl;
        cout << "Top tray: " << arr[top] << endl;
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "Counter is empty. No tray to remove." << endl;
            return;
        }

        cout << "Tray " << arr[top] << " removed from counter." << endl;
        top--;

        if(top == -1)
        {
            cout << "Top tray: None" << endl;
        }
        else
        {
            cout << "Top tray: " << arr[top] << endl;
        }
    }

    void display()
    {
        if(top == -1)
        {
            cout << "Counter is empty. No tray to display." << endl;
            return;
        }

        cout << "Trays in counter: ";

        for(int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
        cout << "Top tray: " << arr[top] << endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);


    s.push(40);

    cout << endl;

    s.display();

    cout << endl;

    s.pop();
    s.pop();
    s.pop();

    
    s.pop();

    cout << endl;

    s.display();

    return 0;
}