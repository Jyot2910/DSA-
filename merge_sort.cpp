#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;

    // merge both halves
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // remaining left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // remaining right half
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // copy back to original array
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }
}

void mergeSort(vector<int>& arr, int st, int end) {
    // base case
    if (st < end) {

    int mid = (st + end) / 2;

    // left half
    mergeSort(arr, st, mid);

    // right half
    mergeSort(arr, mid + 1, end);

    // merge both
    merge(arr, st, mid, end);

    }
}

int main() {
    vector<int> arr = {5, 2, 4, 1, 3};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:\n";
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}