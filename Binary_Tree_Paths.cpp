#include <iostream>
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

void solve(Node* root,
           string path,
           vector<string>& ans) {

    if (root == NULL) {
        return;
    }

    path += to_string(root->data);

    if (root->left == NULL &&
        root->right == NULL) {

        ans.push_back(path);

        return;
    }

    path += "->";

    solve(root->left, path, ans);

    solve(root->right, path, ans);
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);

    vector<string> ans;

    solve(root, "", ans);

    for (string x : ans) {
        cout << x << endl;
    }

    return 0;
}