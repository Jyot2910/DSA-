#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter size: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int size = n;
    int index = 1;   

    while (size > 1) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
             }

        size--; 

        
        index = (index + 1) % size;
    }

    cout << "Output: " << arr[0];

    return 0;
}

