#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {

    unordered_map<char, int> m;

    queue<int> q;

    for(int i = 0; i < s.size(); i++) {

        // First occurrence
        if(m.find(s[i]) == m.end()) {
            q.push(i);
        }

        // Increase frequency
        m[s[i]]++;

        // Remove repeating characters
        while(!q.empty() &&
              m[s[q.front()]] > 1) {

            q.pop();
        }
    }

    // If queue empty
    if(q.empty()) {
        return -1;
    }

    return q.front();
}

int main() {

    string s = "loveleetcode";

    int ans = firstUniqChar(s);

    cout << "First Unique Character Index: " << ans;

    return 0;
}