#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    int t;
    cout << "Enter number of shifts: ";
    cin >> t;

    vector<string> words;
    string temp;
    stringstream ss(s);

    while (ss >> temp)
        words.push_back(temp);

    int n = words.size();

    vector<int> pos(n), dir(n);

    for (int i = 0; i < n; i++) {
        pos[i] = i;

        if (words[i].length() % 2 == 0)
            dir[i] = 1;     
        else
            dir[i] = -1;    
    }

    while (t--) {

        
        for (int i = 0; i < n; i++) {
            if (pos[i] == 0 && dir[i] == -1)
                dir[i] = 1;
            else if (pos[i] == n - 1 && dir[i] == 1)
                dir[i] = -1;
        }

        // Move
        for (int i = 0; i < n; i++)
            pos[i] += dir[i];
    }

    vector<string> ans(n);

    // Preserve original order on collisions
    for (int p = 0; p < n; p++) {
        for (int i = 0; i < n; i++) {
            if (pos[i] == p) {
                ans[p] = words[i];
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}