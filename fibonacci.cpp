#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;

    int a = 0, b = 1, c;

    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci = " << fib(n);

    return 0;
}