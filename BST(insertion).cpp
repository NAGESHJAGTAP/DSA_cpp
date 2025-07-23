
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
Node* insertion(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertion(root->left, val);
    } else {
        root->right = insertion(root->right, val);
    }
    return root;
}
void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    Node* root = NULL;
    root = insertion(root, 50);
    insertion(root, 30);
    insertion(root, 70);
    insertion(root, 20);
    insertion(root, 40);
    insertion(root, 60);
    insertion(root, 80);
    cout << "Level Order";
    levelOrder(root);

    return 0;
}
