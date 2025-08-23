#include <iostream>
using namespace std;
class CircularQueue {
    int *arr;
    int currSize, cap;
    int f, r;
public:
    CircularQueue(int size) {
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1;
        currSize = 0;
    }
    void push(int data) {
        if (currSize == cap) {
            cout << "Queue full" << endl;
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }
    void pop() {
        if (empty()) {
            cout << "Queue empty" << endl;
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }
    int front() {
        if (empty()) {
            cout << "Queue empty" << endl;
            return -1;
        }
        return arr[f];
    }
    bool empty() {
        return currSize == 0;
    }
    void display() {
        if (empty()) {
            cout << "Queue empty" << endl;
            return;
        }
        cout << "Queue: ";
        int count = currSize;
        int i = f;
        while (count--) {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();  
    cout << "Front: " << q.front() << endl; 
    q.pop();
    q.display(); 
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);  
    q.display(); 
    return 0;
}