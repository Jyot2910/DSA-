#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result[n];

    for (int i = 0; i < n; i++) {
        int product = 1;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                product *= nums[j];
            }
        }

        result[i] = product;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}