#include <iostream>
#include <stack>
using namespace std;

class MyQueue {

    stack<int> s1;
    stack<int> s2;

public:

    // Enqueue
    void push(int x) {

        // Move s1 -> s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element
        s1.push(x);

        // Move back s2 -> s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue
    void pop() {

        if(s1.empty()) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Deleted: " << s1.top() << endl;
        s1.pop();
    }

    // Front Element
    int peek() {

        if(s1.empty()) {
            return -1;
        }

        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }

    void display() {

        stack<int> temp = s1;

        while(!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {

    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue: ";
    q.display();

    cout << "Front: " << q.peek() << endl;

    q.pop();

    cout << "After Pop: ";
    q.display();

    return 0;
}