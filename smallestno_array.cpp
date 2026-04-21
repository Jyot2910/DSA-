#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = 5;

    int smallest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    cout << "Smallest number: " << smallest;

    return 0;
}