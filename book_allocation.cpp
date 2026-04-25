#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) {
            return false;
        }

        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }

    return students <= m;
}

int allocateBooks(vector<int> &arr, int n, int m) {
    if (m > n) return -1;

   int sum = 0 ;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int low = 0, high = sum;

    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isValid(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;  
        } else {
            low = mid + 1;   
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();
    int m = 2;

    cout << allocateBooks(arr, n, m);

    return 0;
}