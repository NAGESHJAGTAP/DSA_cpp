#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* insert(Node* root, int val) {
    Node* newNode = new Node(val);
    if (!root) return newNode;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode;
            return root;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = newNode;
            return root;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}


void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    cout << " ";
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}
int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 25);
    printLevelOrder(root);
    return 0;
}
