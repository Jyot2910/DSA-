#include <iostream>
using namespace std;

int sum(int n) {
    // Base case
    if (n == 0)
        return 0;

    // Recursive call
    return n + sum(n - 1);
}

int main() {
    int n = 5;
    cout << sum(n);
}