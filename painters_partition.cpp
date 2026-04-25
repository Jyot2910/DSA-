#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool isValid(vector<int> &boards, int n, int k, int maxTime) {
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) {
            return false;
        }

        if (time + boards[i] <= maxTime) {
            time += boards[i];
        } else {
            painters++;
            time = boards[i];
        }
    }

    return painters <= k;
}

int paintersPartition(vector<int> &boards, int n, int k) {
    int sum = 0 , max_value = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += boards[i];
        max_value = max(max_value, boards[i]);
    }

    int low = max_value;
    int high = sum;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isValid(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int n = boards.size();
    int k = 2;

    cout << paintersPartition(boards, n, k);

    return 0;
}