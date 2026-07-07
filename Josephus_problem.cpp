#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;

    cout << "Enter size: ";
    cin >> n;

    queue<int> q;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    while (q.size() > 1) {
       
        q.push(q.front());
        q.pop();
        q.pop();
    }

    cout << "Output: " << q.front() << endl;

    return 0;
}