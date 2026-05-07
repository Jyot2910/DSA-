#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {

    stack<char> st;

    for(int i = 0; i < s.size(); i++) {

        char ch = s[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }

        else {

            if(st.empty()) {
                return false;
            }

            if(ch == ')' && st.top() == '(') {
                st.pop();
            }
            else if(ch == '}' && st.top() == '{') {
                st.pop();
            }
            else if(ch == ']' && st.top() == '[') {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {

    string s = "{[()]}";

    if(isValid(s)) {
        cout << "Valid";
    }
    else {
        cout << "Invalid";
    }

    return 0;
}