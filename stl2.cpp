#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {

    // 🔹 STACK (LIFO)
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack top: " << st.top();
    cout << "\nSize: " << st.size();

    st.pop();

    cout << "\nAfter pop, top: " << st.top();

    cout << "\n\n";


    // 🔹 QUEUE (FIFO)
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue front: " << q.front();
    cout << "\nQueue back: " << q.back();
    cout << "\nSize: " << q.size();

    q.pop();

    cout << "\nAfter pop, front: " << q.front();

    cout << "\n\n";


    // 🔹 PRIORITY QUEUE (MAX HEAP by default)
    priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Priority Queue top: " << pq.top(); 
    cout << "\nSize: " << pq.size();

    pq.pop();

    cout << "\nAfter pop, top: " << pq.top();

    cout << "\n\n";


    // 🔹 MIN HEAP (extra)
    priority_queue<int, vector<int>, greater<int>> minpq;

    minpq.push(10);
    minpq.push(30);
    minpq.push(20);

    cout << "Min Heap top: " << minpq.top(); 
    return 0;
}