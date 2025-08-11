
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
        left = NULL;
        right = NULL;
    }
};
void deleteleaf(Node* root, Node* target) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->left) {
            if (temp->left == target) {
                delete temp->left;
                temp->left = NULL;
                return;
            } else {
                q.push(temp->left);
            }
        }
        if (temp->right) {
            if (temp->right == target) {
                delete temp->right;
                temp->right = NULL;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
}
void deleteNode(Node* root, int key) {
    if (root == NULL) return;
    queue<Node*> q;
    Node* temp;
    Node* keyNode = NULL;
    q.push(root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == key) {
            keyNode = temp;
        }

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    if (keyNode) {
        int x = temp->data;
        deleteleaf(root, temp); 
        keyNode->data = x; 
    }
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << " ";
    inorder(root);

    deleteNode(root, 3); 

    cout << "\n ";
    inorder(root);

    return 0;
}
