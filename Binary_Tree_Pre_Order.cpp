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

Node* buildTree() {

    int val;
    cin >> val;

    // NULL node
    if (val == -1) {
        return NULL;
    }

    // Create node
    Node* root = new Node(val);

    // Build left subtree
    root->left = buildTree();

    // Build right subtree
    root->right = buildTree();

    return root;
}

void preorder(Node* root) {

    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

int main() {

    Node* root = buildTree();

    cout << "Preorder Traversal: ";

    preorder(root);

    return 0;
}