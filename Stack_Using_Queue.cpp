#include <iostream>
#include <queue>
using namespace std;

class MyStack {

    queue<int> q1;
    queue<int> q2;

public:

    // Push Operation
    void push(int x) {

        // Move all elements from q1 to q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push new element into q1
        q1.push(x);

        // Move all elements back to q1
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Pop Operation
    void pop() {

        if(q1.empty()) {
            cout << "Stack Empty\n";
            return;
        }

        cout << "Deleted: " << q1.front() << endl;
        q1.pop();
    }

    // Top Element
    int top() {

        if(q1.empty()) {
            cout << "Stack Empty\n";
            return -1;
        }

        return q1.front();
    }

    // Check Empty
    bool empty() {
        return q1.empty();
    }

    // Display Stack
    void display() {

        if(q1.empty()) {
            cout << "Stack Empty\n";
            return;
        }

        queue<int> temp = q1;

        while(!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {

    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack: ";
    st.display();

    cout << "Top Element: " << st.top() << endl;

    st.pop();

    cout << "After Pop: ";
    st.display();

    return 0;
}