#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> topView(Node* root) {

    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    map<int, int> mp;

    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {

        pair<Node*, int> temp = q.front();
        q.pop();

        Node* node = temp.first;
        int hd = temp.second;

        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->data;
        }

        if (node->left != NULL) {
            q.push({node->left, hd - 1});
        }

        if (node->right != NULL) {
            q.push({node->right, hd + 1});
        }
    }

    for (auto x : mp) {
        ans.push_back(x.second);
    }

    return ans;
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    root->left->right->right = new Node(5);

    vector<int> ans = topView(root);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}