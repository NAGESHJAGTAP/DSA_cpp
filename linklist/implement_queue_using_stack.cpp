
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s;
public:
    void push(int x) {
        s.push(x);
    }
    int pop() {
        if (s.empty()) {
            cout << "empty" << endl;
            return -1;
        }
        int topVal = s.top();
        s.pop();
        if (s.empty()) {
            return topVal;
        }

        int res = pop(); 
        s.push(topVal);  
        return res;
    }
    int front() {
        if (s.empty()) {
            cout << "empty" << endl;
            return -1;
        }
        int topVal = s.top();
        s.pop();
        if (s.empty()) {
            s.push(topVal);
            return topVal;
        }
        int res = front();
        s.push(topVal);
        return res;
    }

    bool empty() {
        return s.empty();
    }
};
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl; 
    cout << q.pop() << endl;   
    cout << q.front() << endl; 
    cout << q.pop() << endl;   
    cout << q.front() << endl; 
    cout << q.pop() << endl;   
    cout << q.empty() << endl;

    return 0;
}