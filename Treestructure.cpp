
#include <iostream>
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
Node* Tree(int arr[], int& index, int size) {
    if (index >= size || arr[index] == -1) {
        index++;
        return NULL;
    }

    Node* newNode = new Node(arr[index++]);
    newNode->left = Tree(arr, index, size);
    newNode->right = Tree(arr, index, size);
    return newNode;
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root ==NULL) return;
    postorder(root->right);
    cout<<root->data<<" ";
    postorder(root->left);
}

int main() {
    int arr[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1}; 
    int index = 0;
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* root = Tree(arr, index, size);
    inorder(root);
    cout<<"\nindore travel sucssefully\n";
    preorder(root);
    cout << "\npreorder travel successfully!\n";
    postorder(root);
    cout<< "\n postorder travel successfully\n";

    return 0;
}





















