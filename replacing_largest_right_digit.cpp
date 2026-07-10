#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n; 

    long long result = 0, pow10 = 1;
    int maxRight = 0; 
    
    
    while (n > 0) {
        int digit = n % 10;
        
        
        if (digit < maxRight) {
            digit = maxRight;
        } else {
            maxRight = digit; 
        
        result = digit * pow10 + result;
        pow10 *= 10;
        n /= 10;
    }
    
    cout << result; 
    return 0;
    }

}
