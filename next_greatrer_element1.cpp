#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    unordered_map<int, int> mp;

    stack<int> st;

    // process nums2 from right to left
    for(int i = nums2.size() - 1; i >= 0; i--) {

        // remove smaller elements
        while(!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }

        // no greater element
        if(st.empty()) {
            mp[nums2[i]] = -1;
        }
        else {
            mp[nums2[i]] = st.top();
        }

        // push current element
        st.push(nums2[i]);
    }

    vector<int> ans;

    // answer for nums1
    for(int i = 0; i < nums1.size(); i++) {
        ans.push_back(mp[nums1[i]]);
    }

    return ans;
}

int main() {

    vector<int> nums1 = {4, 1, 2};

    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}