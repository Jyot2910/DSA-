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

void kthLevel(Node* root, int k, int level) {

    if (root == NULL) {
        return;
    }

    if (level == k) {
        cout << root->data << " ";
        return;
    }

    kthLevel(root->left, k, level + 1);

    kthLevel(root->right, k, level + 1);
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;

    kthLevel(root, k, 0);

    return 0;
}