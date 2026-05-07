#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(vector<int>& arr) {

    int n = arr.size();

    vector<int> ans(n);

    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {

        // remove smaller elements
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // no greater element
        if(st.empty()) {
            ans[i] = -1;
        }

        // greater element exists
        else {
            ans[i] = st.top();
        }

        // push current element
        st.push(arr[i]);
    }

    return ans;
}

int main() {

    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> ans = nextGreater(arr);

    cout << "Next Greater Elements: ";

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}