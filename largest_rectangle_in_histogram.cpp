#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    vector<int> left(n);
    vector<int> right(n);

    stack<int> st;

    // Nearest Smaller Left

    for(int i = 0; i < n; i++) {

        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if(st.empty()) {
            left[i] = -1;
        }
        else {
            left[i] = st.top();
        }

        st.push(i);
    }

    // Clear stack

    while(!st.empty()) {
        st.pop();
    }

    // Nearest Smaller Right

    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if(st.empty()) {
            right[i] = n;
        }
        else {
            right[i] = st.top();
        }

        st.push(i);
    }

    int maxi = 0;

    // Area Calculation

    for(int i = 0; i < n; i++) {

        int width = right[i] - left[i] - 1;

        int area = heights[i] * width;

        maxi = max(maxi, area);
    }

    return maxi;
}

int main() {

    vector<int> heights = {2,1,5,6,2,3};

    cout << "Largest Rectangle Area = "
         << largestRectangleArea(heights);

    return 0;
}