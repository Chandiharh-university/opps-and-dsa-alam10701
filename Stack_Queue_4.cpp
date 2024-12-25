#include <iostream>
#define MAX 1000
using namespace std;

class Queue {
    int front, rear, size;
    int arr[MAX];

public:
    Queue() {
        front = size = 0;
        rear = MAX - 1;
    }

    bool enqueue(int x) {
        if (size == MAX) {
            cout << "Queue Overflow\n";
            return false;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        size++;
        return true;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % MAX;
        size--;
        return item;
    }

    int frontElement() {
        if (size == 0) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() { return (size == 0); }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << "Front: " << q.frontElement() << endl;
    q.dequeue();
    cout << "Front after dequeue: " << q.frontElement() << endl;

    return 0;
}
