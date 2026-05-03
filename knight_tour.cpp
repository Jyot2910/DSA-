#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<int>>& grid, int r, int c, int expVal) {

    int n = grid.size(); // used internally (not passed)

    // invalid cases
    if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) {
        return false;
    }

    // reached last value
    if (expVal == n * n - 1) {
        return true;
    }

    return 
        isValid(grid, r-2, c+1, expVal+1) ||
        isValid(grid, r-1, c+2, expVal+1) ||
        isValid(grid, r+1, c+2, expVal+1) ||
        isValid(grid, r+2, c+1, expVal+1) ||
        isValid(grid, r+2, c-1, expVal+1) ||
        isValid(grid, r+1, c-2, expVal+1) ||
        isValid(grid, r-1, c-2, expVal+1) ||
        isValid(grid, r-2, c-1, expVal+1);
}

int main() {
    vector<vector<int>> grid = {
        {0, 3, 6},
        {5, 8, 1},
        {2, 7, 4}
    };

    if (grid[0][0] != 0) {
        cout << "Invalid Knight Tour\n";
        return 0;
    }

    bool ans = isValid(grid, 0, 0, 0);

    cout << (ans ? "Valid Knight Tour" : "Invalid Knight Tour") << endl;

    return 0;
}