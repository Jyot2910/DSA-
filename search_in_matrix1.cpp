#include <iostream>
#include <vector>
using namespace std;

// Function 1: Binary search in a row
bool searchInRow(vector<vector<int>>& mat, int target, int row) {
    int n = mat[0].size();
    int st = 0, end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (mat[row][mid] == target)
            return true;
        else if (mat[row][mid] < target)
            st = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

// Function 2: Find correct row using binary search
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();

    int startRow = 0, endRow = m - 1;

    while (startRow <= endRow) {
        int midRow = startRow + (endRow - startRow) / 2;

        if (target >= mat[midRow][0] && target <= mat[midRow][n - 1]) {
            return searchInRow(mat, target, midRow);
        } 
        else if (target > mat[midRow][n - 1]) {
            startRow = midRow + 1;
        } 
        else {
            endRow = midRow - 1;
        }
    }

    return false;
}

// main function (only calling)
int main() {
    vector<vector<int>> mat = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    };

    int target = 9;

    if (searchMatrix(mat, target))
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}