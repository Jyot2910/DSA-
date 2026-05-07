#include <iostream>
#include <stack>
using namespace std;

class MinStack {

    stack<pair<int,int>> s;

public:

    // push
    void push(int val) {

        // first element
        if(s.empty()) {
            s.push({val, val});
        }

        else {

            int minVal = min(val, s.top().second);

            s.push({val, minVal});
        }
    }

    // pop
    void pop() {

        if(s.empty()) {
            cout << "Stack Empty" << endl;
            return;
        }

        s.pop();
    }

    // top
    int top() {

        if(s.empty()) {
            return -1;
        }

        return s.top().first;
    }

    // get minimum
    int getMin() {

        if(s.empty()) {
            return -1;
        }

        return s.top().second;
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(2);
    st.push(10);
    st.push(1);

    cout << "Top Element: " << st.top() << endl;

    cout << "Minimum Element: " << st.getMin() << endl;

    st.pop();

    cout << "After Pop" << endl;

    cout << "Top Element: " << st.top() << endl;

    cout << "Minimum Element: " << st.getMin() << endl;

    return 0;
}