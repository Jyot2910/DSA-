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

int transform(Node* root) {

    if (root == NULL) {
        return 0;
    }

    int oldValue = root->data;

    int leftSum = transform(root->left);

    int rightSum = transform(root->right);

    root->data = leftSum + rightSum;

    return root->data + oldValue;
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

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    transform(root);

    cout << "Sum Tree Preorder: ";

    preorder(root);

    return 0;
}