#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    vector<int> ans;
    unordered_set<int> s;
    int n = grid.size();
    int a = -1, b = -1;

    long long expSum = 0, actualSum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()) {
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }

    expSum = (long long)(n * n) * (n * n + 1) / 2;

    b = expSum + a - actualSum;
    ans.push_back(b);

    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {1, 3},
        {2, 2}
    };

    vector<int> result = findMissingAndRepeatedValues(grid);

    cout << result[0] << " " << result[1];

    return 0;
}