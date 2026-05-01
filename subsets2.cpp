#include <iostream>
#include <vector>
#include <algorithm>
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

    ans.pop_back();

    
    int idx = i + 1;
    while(idx < nums.size() && nums[idx] == nums[idx - 1]) {
        idx++;
    }

    // exclude (jump to next unique element)
    getAllSubsets(nums, ans, idx, allSubsets);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // VERY IMPORTANT

    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allSubsets);

    return allSubsets;
}

int main() {
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = subsetsWithDup(nums);

    cout << "Subsets (no duplicates):\n";
    for(auto subset : result) {
        cout << "[ ";
        for(int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}