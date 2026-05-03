#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1); 
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // copy back
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }

    return invCount;
}

int mergeSort(vector<int>& arr, int st, int end) {
    int invCount = 0;

    if (st < end) {
        int mid = (st + end) / 2;

        invCount += mergeSort(arr, st, mid);       
        invCount += mergeSort(arr, mid + 1, end);   
        invCount += merge(arr, st, mid, end);       
    }

    return invCount;
}

int main() {
    vector<int> arr = {5, 3, 2, 4, 1};

    int count = mergeSort(arr, 0, arr.size() - 1);

    cout << "Inversion Count: " << count << endl;

    return 0;
}