#include <iostream>
using namespace std;
#define Size 100
class stack {
    int* arr;
    int top;

public:
    stack() {
        arr=new int[Size];
        top = -1;
    }
    void push(int x) {
        if (top == Size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
        cout << x << " pushed to stack" << endl;
    }
    void pop() {
        if (top == -1) {
            cout << "unflow" << endl;
            return;
        }
        cout << arr[top]<< " pop"<< endl;
        top--;
    }

    void peek() {
        if (top == -1) {
            cout <<" empty" << endl;
        } else {
            cout << "Top element " << arr[top] << endl;
        }
    }
};

int main() {
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.peek();
    st.pop();
    st.peek();
    return 0;
}