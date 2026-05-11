#include <iostream>
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

Node* LCA(Node* root, int p, int q) {

    if (root == NULL) {
        return NULL;
    }

    if (root->data == p || root->data == q) {
        return root;
    }

    Node* leftAns = LCA(root->left, p, q);

    Node* rightAns = LCA(root->right, p, q);

    if (leftAns != NULL && rightAns != NULL) {
        return root;
    }

    if (leftAns != NULL) {
        return leftAns;
    }

    return rightAns;
}

int main() {

    Node* root = new Node(3);

    root->left = new Node(5);
    root->right = new Node(1);

    root->left->left = new Node(6);
    root->left->right = new Node(2);

    root->right->left = new Node(0);
    root->right->right = new Node(8);

    Node* ans = LCA(root, 5, 1);

    cout << "LCA = " << ans->data;

    return 0;
}