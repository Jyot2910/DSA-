#include <iostream>
#include <vector>
using namespace std;

class Stack {
    
    vector<int> arr;

public:

    // push function
    void push(int x) {
        arr.push_back(x);
        cout << x << " pushed into stack" << endl;
    }

    // pop function
    void pop() {

        if(arr.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << arr.back() << " popped from stack" << endl;
        arr.pop_back();
    }

    // top function
    int top() {

        if(arr.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return arr.back();
    }

    // empty function
    bool empty() {
        return arr.empty();
    }

    // size function
    int size() {
        return arr.size();
    }
};

int main() {

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    st.pop();

    cout << "Top element after pop: " << st.top() << endl;

    cout << "Stack size: " << st.size() << endl;

    return 0;
}