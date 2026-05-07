#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int>& price) {

    int n = price.size();

    vector<int> ans(n);

    stack<int> st;

    for(int i = 0; i < n; i++) {

        // pop smaller or equal prices
        while(!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }

        // if no greater element on left
        if(st.empty()) {
            ans[i] = i + 1;
        }

        // greater element exists
        else {
            ans[i] = i - st.top();
        }

        // push current index
        st.push(i);
    }

    return ans;
}

int main() {

    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans = stockSpan(price);

    cout << "Stock Span: ";

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}