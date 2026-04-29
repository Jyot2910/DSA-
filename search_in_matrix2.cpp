#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size(), n = mat[0].size();

    int r = 0, c = n - 1;

    while (r < m && c >= 0) {
        if (mat[r][c] == target) {
            return true;
        } 
        else if (target < mat[r][c]) {
            c--;
        } 
        else {
            r++;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16}
    };

    int target = 5;

    if (searchMatrix(mat, target))
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}