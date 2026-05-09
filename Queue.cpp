// Queue using Linked List in C++

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

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Enqueue
    void push(int val) {
        Node* newNode = new Node(val);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue
    void pop() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        // If queue becomes empty
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // Front element
    int peek() {
        if (front == NULL) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return front->data;
    }

    // Check empty
    bool isEmpty() {
        return front == NULL;
    }

    // Display
    void display() {
        if (front == NULL) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue: ";
    q.display();

    cout << "Front Element: " << q.peek() << endl;

    q.pop();

    cout << "After Pop: ";
    q.display();

    return 0;
}