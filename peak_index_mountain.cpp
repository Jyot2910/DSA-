#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& A) {
    if (A.size() < 3) return -1;

    int st = 1, end = A.size() - 2;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
            return mid;
        } 
        else if (A[mid - 1] < A[mid]) {
            st = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> A = {1, 3, 20, 4, 1};
    int result = findPeakElement(A);
    cout << result << endl;
    return 0;
}