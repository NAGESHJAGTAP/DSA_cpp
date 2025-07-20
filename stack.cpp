// #include <iostream>
// using namespace std;
// #define Size 100
// class stack {
//     int* arr;
//     int top;

// public:
//     stack() {
//         arr=new int[Size];
//         top = -1;
//     }
//     void push(int x) {
//         if (top == Size - 1) {
//             cout << "Stack Overflow" << endl;
//             return;
//         }
//         top++;
//         arr[top] = x;
//         cout << x << " pushed to stack" << endl;
//     }
//     void pop() {
//         if (top == -1) {
//             cout << "unflow" << endl;
//             return;
//         }
//         cout << arr[top]<< " pop"<< endl;
//         top--;
//     }

//     void peek() {
//         if (top == -1) {
//             cout <<" empty" << endl;
//         } else {
//             cout << "Top element " << arr[top] << endl;
//         }
//     }
// };

// int main() {
//     stack st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.peek();
//     st.pop();
//     st.peek();
//     return 0;
// }








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

class Stack {
    Node* head;
    Node* tail;

public:
    Stack() {
        head = tail = NULL;
    }

 
    void push(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }


    void pop() {
        if (head == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL) {
            tail = NULL;
        }
    }

    void display() {
        Node* temp = head;
        cout << "Stack: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();  

    s.pop();      
    s.display();  

    return 0;
}
