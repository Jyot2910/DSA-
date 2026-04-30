#include <iostream>
using namespace std;

int factorial(int n) {
    // Base case
    if (n == 0 || n == 1)
        return 1;

    // Recursive call
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Factorial = " << factorial(n);

    return 0;
}