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

class Solution {
public:

    Node* prev = NULL;

    void flatten(Node* root) {

        if(root == NULL) {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};

void printList(Node* root) {

    while(root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->right = new Node(6);

    Solution obj;

    obj.flatten(root);

    printList(root);

    return 0;
}