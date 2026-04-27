#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {

    //  VECTOR
    vector<int> v = {10, 20, 30};

    v.push_back(40);

    cout << "Vector: ";
    for (int x : v) cout << x << " ";

    cout << "\nSize: " << v.size();
    cout << "\nFirst: " << v.front();
    cout << "\nLast: " << v.back();

    v.pop_back();        
    v.erase(v.begin());  

    cout << "\nAfter changes: ";
    for (int x : v) cout << x << " ";

    cout << "\n\n";


    // VECTOR OF PAIRS
    vector<pair<int,int>> vp;

    vp.push_back({1, 10});
    vp.push_back({2, 20});

    cout << "Vector of pairs:\n";
    for (auto p : vp) {
        cout << p.first << " " << p.second << endl;
    }

    cout << "\n";


    //  PAIR OF PAIRS
    pair<int, pair<int,int>> p = {1, {100, 200}};

    cout << "Pair of pairs: ";
    cout << p.first << " " << p.second.first << " " << p.second.second;

    cout << "\n\n";


    //  LIST
    list<int> l = {10, 20, 30};

    l.push_front(5);
    l.push_back(40);

    cout << "List: ";
    for (int x : l) cout << x << " ";

    cout << "\nSize: " << l.size();
    cout << "\nFirst: " << l.front();
    cout << "\nLast: " << l.back();

    l.pop_front();
    l.pop_back();

    cout << "\nAfter pop: ";
    for (int x : l) cout << x << " ";

    cout << endl;

    return 0;
}