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

int height(Node* root) {

    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);

    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height = " << height(root);

    return 0;
}