#include <iostream>
#include <climits>
using namespace std;

int reverseNum(int x) {
    int ans = 0;

    while (x != 0) {
        int digit = x % 10;

        if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
            return 0;

        ans = ans * 10 + digit;
        x /= 10;
    }

    return ans;
}

int main() {
    int x;
    cin >> x;

    cout << reverseNum(x);

    return 0;
}