#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int maxSum = INT_MIN;
    int currSum = 0;

    for (int x : nums) {
        currSum += x;
        maxSum = max(maxSum, currSum);

        if (currSum < 0) {
            currSum = 0;
        }
    }

    cout << "Maximum subarray sum = " << maxSum;

    return 0;
}