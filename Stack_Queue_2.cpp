#include <iostream>
#define MAX 1000
using namespace std;

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    bool push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() { return (top < 0); }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top: " << s.peek() << endl;
    s.pop();
    cout << "Top after pop: " << s.peek() << endl;

    return 0;
}
