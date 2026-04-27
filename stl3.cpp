#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {

    // 🔹 MAP
    map<int, string> m;
    m[1] = "One";
    m[2] = "Two";

    cout << "Map:\n";
    for (auto x : m) {
        cout << x.first << " " << x.second << endl;
    }

    cout << "\n";


    // 🔹 SET
    set<int> s = {10, 20, 30, 40};

    cout << "Set: ";
    for (int x : s) cout << x << " ";

    cout << "\n";


    // 🔹 LOWER & UPPER BOUND
    auto lb = s.lower_bound(20); 
    auto ub = s.upper_bound(20); 

    cout << "Lower bound of 20: " << *lb << endl;
    cout << "Upper bound of 20: " << *ub << endl;

    cout << "\n";


    // 🔹 SORT + REVERSE
    vector<int> v = {5, 2, 8, 1};

    sort(v.begin(), v.end());

    cout << "Sorted: ";
    for (int x : v) cout << x << " ";

    reverse(v.begin(), v.end());

    cout << "\nReversed: ";
    for (int x : v) cout << x << " ";

    cout << "\n";


    // 🔹 NEXT PERMUTATION
    vector<int> p = {1, 2, 3};

    next_permutation(p.begin(), p.end());

    cout << "Next permutation: ";
    for (int x : p) cout << x << " ";

    cout << "\n";


    // 🔹 BINARY SEARCH
    vector<int> b = {1, 2, 3, 4, 5};

    if (binary_search(b.begin(), b.end(), 3))
        cout << "3 Found\n";
    else
        cout << "3 Not Found\n";

    return 0;
}