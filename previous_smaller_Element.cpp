#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousSmaller(vector<int>& arr) {

    int n = arr.size();

    vector<int> ans(n);

    stack<int> st;

    for(int i = 0; i < n; i++) {

        // remove greater or equal elements
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // no smaller element
        if(st.empty()) {
            ans[i] = -1;
        }

        // smaller element exists
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

    vector<int> ans = previousSmaller(arr);

    cout << "Previous Smaller Elements: ";

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}