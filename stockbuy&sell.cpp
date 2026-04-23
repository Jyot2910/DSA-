#include <iostream>
using namespace std;

int maxProfit(int prices[], int n) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int prices[n];
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = maxProfit(prices, n);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}