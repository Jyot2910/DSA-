#include <iostream>
#include <vector>
using namespace std;

void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
    // base case
    if(i == nums.size()) {
        allSubsets.push_back(ans);
        return;
    }

    // include
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allSubsets);

    // backtrack
    ans.pop_back();

    // exclude
    getAllSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allSubsets);

    return allSubsets;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    cout << "All Subsets:\n";
    for(auto subset : result) {
        cout << "[ ";
        for(int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}