#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push elements into the stack
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    // Pop an element
    s.pop();
    cout << "Top after pop: " << s.top() << endl;

    // Display stack size
    cout << "Stack size: " << s.size() << endl;

    return 0;
}
