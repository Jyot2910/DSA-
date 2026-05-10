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

int sumNodes(Node* root) {

    if (root == NULL) {
        return 0;
    }

    int leftSum = sumNodes(root->left);

    int rightSum = sumNodes(root->right);

    return root->data + leftSum + rightSum;
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Sum of Nodes = " << sumNodes(root);

    return 0;
}