#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

class BrowserHistory {
    Node* top;
    string crntPage;

public:
    BrowserHistory() {
        top = NULL;
        crntPage = "Home(First page)";
    }

    void visit(string page) {
        Node* newNode = new Node;

        newNode->page = crntPage;
        newNode->next = top;
        top = newNode;

        crntPage = page;

        cout <<"\n" << page << " page is visited." << endl;
        cout << "Current page: " << crntPage << endl;
    }

    void back() {
        if (top == NULL) {
            cout << "\nNo previous page. Already on first page."
                 << endl;
            cout << "Current page: " << crntPage << endl;
            return;
        }

        Node* temp = top;

        crntPage = temp->page;
        top = top->next;

        delete temp;

        cout << "\nBack to page: " << crntPage << endl;
        cout << "Current page: " << crntPage << endl;
    }

    void displayHistory() {
        if (top == NULL) {
            cout << "\nNo history available." << endl;
            return;
        }

        cout << "\nPage history: ";

        Node* temp = top;

        while (temp != NULL) {
            cout << temp->page << " ";
            temp = temp->next;
        }

        cout << endl;
        cout << "Current page: " << crntPage << endl;
    }
};

int main() {
    BrowserHistory browser;

    browser.visit("Google");
    browser.visit("YouTube");
    browser.visit("Instagram");

    browser.displayHistory();

    browser.back();
    browser.back();
    browser.back();
    browser.back();

    browser.displayHistory();

    return 0;
} 