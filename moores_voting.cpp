#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;


    int i = 0;
    while (i < nums.size()) {
        if (count == 0) {
            candidate = nums[i];
        }

        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }

        i++;
    }

    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = majorityElement(nums);
    cout << "Majority Element: " << result;

    return 0;
}