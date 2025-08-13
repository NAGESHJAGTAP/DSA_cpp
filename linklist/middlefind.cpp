// middel Node find

// using formula  slow= +1;
//                fast= +2;

// middle size find node formula
                
        //    size/2=() +1 = ......


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
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       
        fast = fast->next->next;  
    }
    return slow; 
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* middle = findMiddle(head);
    if (middle != NULL)
        cout << " " << middle->data << endl;

    return 0;
}
