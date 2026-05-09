#include <iostream>
using namespace std;

class CircularQueue {

    int *arr;
    int front;
    int rear;
    int size;

public:

    CircularQueue(int n) {
        size = n;
        arr = new int[size];

        front = -1;
        rear = -1;
    }

    // Enqueue
    void push(int val) {

        // Queue Full
        if((rear + 1) % size == front) {
            cout << "Queue Overflow\n";
            return;
        }

        // First Element
        if(front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = val;
    }

    // Dequeue
    void pop() {

        // Empty Queue
        if(front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        // Only One Element
        if(front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    // Front Element
    int peek() {

        if(front == -1) {
            cout << "Queue Empty\n";
            return -1;
        }

        return arr[front];
    }

    void display() {

        if(front == -1) {
            cout << "Queue Empty\n";
            return;
        }

        int i = front;

        while(i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }

        cout << arr[rear] << endl;
    }
};

int main() {

    CircularQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.display();

    q.pop();
    q.pop();

    q.display();

    q.push(50);
    q.push(60);

    q.display();

    return 0;
}