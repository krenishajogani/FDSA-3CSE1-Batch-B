#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void Inorder(Node* root) {
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node* root) {
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void LevelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

int main() {


    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    
    cout << "Binary Tree:" << endl;
    cout << "           1(CEO)" << endl;
    cout << "          /      \\" << endl;
    cout << "     2(Manager)     3(Manager)" << endl;
    cout << "        / \\            / \\" << endl;
    cout << "   4(EMP)   5(EMP) 6(EMP)   7(EMP)" << endl;

 
    cout << "\nInorder Traversal: ";
    Inorder(root);

    cout << "\nPreorder Traversal: ";
    Preorder(root);

    cout << "\nPostorder Traversal: ";
    Postorder(root);

    cout << "\nLevel Order Traversal: ";
    LevelOrder(root);

    return 0;
} 