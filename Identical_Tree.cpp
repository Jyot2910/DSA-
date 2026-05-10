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

bool identical(Node* root1, Node* root2) {

    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    if (root1->data != root2->data) {
        return false;
    }

    bool leftSame = identical(root1->left, root2->left);

    bool rightSame = identical(root1->right, root2->right);

    return leftSame && rightSame;
}

int main() {

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if (identical(root1, root2)) {
        cout << "Identical Trees";
    }
    else {
        cout << "Not Identical";
    }

    return 0;
}