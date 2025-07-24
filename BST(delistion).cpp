
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
    if (root == NULL) return new Node(val);
    if (val < root->data)
        root->left = insertion(root->left, val);
    else
        root->right = insertion(root->right, val);
    return root;
}
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}
Node* deletion(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deletion(root->left, key);
    } else if (key > root->data) {
        root->right = deletion(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
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

    cout << " ";
    levelOrder(root);

    root = deletion(root, 70);

    cout << " " ;
    levelOrder(root);

    return 0;
}
