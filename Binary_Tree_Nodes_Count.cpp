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

int countNodes(Node* root) {

    if (root == NULL) {
        return 0;
    }

    int leftCount = countNodes(root->left);

    int rightCount = countNodes(root->right);

    return 1 + leftCount + rightCount;
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Total Nodes = " << countNodes(root);

    return 0;
}