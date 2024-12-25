#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;

    // Dequeue an element
    q.pop();
    cout << "Front after pop: " << q.front() << endl;

    // Display queue size
    cout << "Queue size: " << q.size() << endl;

    return 0;
}
