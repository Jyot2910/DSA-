#include <iostream>
using namespace std;


int sum(int n) {
    int s = 0;
    for(int i = 1; i <= n; i++) {
        s += i;
    }
    return s;
}


int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum = " << sum(n) << endl;
    cout << "Factorial = " << factorial(n) << endl;

    return 0;
}