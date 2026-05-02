#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int st, int end) {
    int pivot = arr[end];     // last element as pivot
    int idx = st - 1;         // place for smaller elements

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    // place pivot at correct position
    idx++;
    swap(arr[end], arr[idx]);

    return idx;
}

void quickSort(vector<int>& arr, int st, int end) {
    if (st < end) {
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx - 1);
        quickSort(arr, pivIdx + 1, end);
    }
}

int main() {
    vector<int> arr = {5, 2, 4, 1, 3};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:\n";
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}