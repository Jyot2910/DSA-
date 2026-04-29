#include <iostream>
using namespace std;

pair<int, int> linearSearch2D(int arr[][3], int rows, int cols, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                return {i, j};  
            }
        }
    }
    return {-1, -1}; 
}

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int target = 5;

    pair<int, int> result = linearSearch2D(arr, 3, 3, target);

    if (result.first != -1)
        cout << "Found at index: (" << result.first << ", " << result.second << ")";
    else
        cout << "Not Found";

    return 0;
}