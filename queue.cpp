#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class Queue {
    Node* head;
    Node* tail;
public:
    Queue() {
        head = tail = NULL;
    }
    void push(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
   void pop() {
        if (head == NULL) {
            cout<<"underflow" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    q.display(); 
    return 0;
}
