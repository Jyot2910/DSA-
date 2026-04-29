#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& arr, int tar) {
    unordered_map<int, int> m;
    vector<int> ans;

    for(int i = 0; i < arr.size(); i++) {
        int first = arr[i];
        int sec = tar - first;

        if(m.find(sec) != m.end()) {
            ans.push_back(m[sec]); 
            ans.push_back(i);     
            break;
        }

        m[first] = i; 
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(arr, target);

    if(!result.empty()) {
        cout << result[0] << " " << result[1];
    } else {
        cout << "No solution found";
    }

    return 0;
}