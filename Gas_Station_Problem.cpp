#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas,
                       vector<int>& cost) {

    int totalGas = 0;
    int totalCost = 0;

    int currentGas = 0;

    int start = 0;

    for(int i = 0; i < gas.size(); i++) {

        totalGas += gas[i];
        totalCost += cost[i];

        currentGas += gas[i] - cost[i];

        // Cannot continue
        if(currentGas < 0) {

            start = i + 1;

            currentGas = 0;
        }
    }

    if(totalGas < totalCost) {
        return -1;
    }

    return start;
}

int main() {

    vector<int> gas  = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    int ans = canCompleteCircuit(gas, cost);

    cout << "Starting Index: " << ans;

    return 0;
}