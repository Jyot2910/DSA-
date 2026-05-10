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

bool isSame(Node* root, Node* subRoot) {

    if (root == NULL && subRoot == NULL) {
        return true;
    }

    if (root == NULL || subRoot == NULL) {
        return false;
    }

    if (root->data != subRoot->data) {
        return false;
    }

    return isSame(root->left, subRoot->left)
        && isSame(root->right, subRoot->right);
}

bool isSubtree(Node* root, Node* subRoot) {

    if (root == NULL) {
        return false;
    }

    if (isSame(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot)
        || isSubtree(root->right, subRoot);
}

int main() {

    Node* root = new Node(3);

    root->left = new Node(4);
    root->right = new Node(5);

    root->left->left = new Node(1);
    root->left->right = new Node(2);

    Node* subRoot = new Node(4);

    subRoot->left = new Node(1);
    subRoot->right = new Node(2);

    if (isSubtree(root, subRoot)) {
        cout << "Subtree Exists";
    }
    else {
        cout << "Not a Subtree";
    }

    return 0;
}