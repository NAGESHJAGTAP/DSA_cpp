
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

class list {
    Node* head;
    Node* tail;

public:
    list() {
        head = tail = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << " head" << endl;
    }
};
 
int main() {
    list cll;
    cll.push(1);
    cll.push(2);
    cll.push(3);

    cll.printList();

    return 0;
}