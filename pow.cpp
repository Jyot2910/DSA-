#include <iostream>
using namespace std;

double power(double x, int n) {
    long  N = n;  
    
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    
    double result = 1;
    
    while (N > 0) {
        if (N % 2 == 1) {
            result *= x;
        }
        x *= x;
        N /= 2;
    }
    
    return result;
}

int main() {
    double x;
    int n;
    
    cout << "Enter base: ";
    cin >> x;
    
    cout << "Enter power: ";
    cin >> n;
    
    double ans = power(x, n);
    
    cout << "Result: " << ans << endl;
    
    return 0;
}