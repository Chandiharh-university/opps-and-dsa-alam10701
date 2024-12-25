#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insert elements at both ends
    dq.push_back(10);
    dq.push_front(20);

    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    // Remove elements from both ends
    dq.pop_back();
    cout << "Back after pop_back: " << dq.back() << endl;

    dq.pop_front();
    if (dq.empty()) {
        cout << "Deque is now empty." << endl;
    }

    return 0;
}
