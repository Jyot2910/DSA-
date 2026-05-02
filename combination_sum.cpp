#include <iostream>
#include <vector>
using namespace std;

void getAllCombinations(vector<int>& arr, int idx, int tar,
                       vector<vector<int>>& ans, vector<int>& combin) {
    
    //  target achieved
    if (tar == 0) {
        ans.push_back(combin);
        return;
    }

    //  invalid cases
    if (idx == arr.size() || tar < 0) {
        return;
    }

    // include (can take multiple times)
    combin.push_back(arr[idx]);
    getAllCombinations(arr, idx, tar - arr[idx], ans, combin);

    // backtrack
    combin.pop_back();

    //  exclude (move to next index)
    getAllCombinations(arr, idx + 1, tar, ans, combin);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> combin;

    getAllCombinations(arr, 0, target, ans, combin);
    return ans;
}

int main() {
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(arr, target);

    cout << "Combinations are:\n";
    for (auto vec : result) {
        for (auto x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}