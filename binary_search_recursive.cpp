#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int left, int right, int target) {
    if(left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if(arr[mid] == target)
        return mid;
    else if(arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, right, target);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7};
    int target = 5;

    int index = binarySearch(arr, 0, arr.size()-1, target);

    if(index != -1)
        cout << "Found at index: " << index;
    else
        cout << "Not Found";
}