#include <iostream>
#include <vector>
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

int i = 0;

Node* buildTree(vector<int>& preorder,
                vector<int>& inorder,
                int start,
                int end) {

    if (start > end) {
        return NULL;
    }

    int rootValue = preorder[i];

    i++;

    Node* root = new Node(rootValue);

    int pos;

    for (pos = start; pos <= end; pos++) {

        if (inorder[pos] == rootValue) {
            break;
        }
    }

    root->left =
        buildTree(preorder,
                  inorder,
                  start,
                  pos - 1);

    root->right =
        buildTree(preorder,
                  inorder,
                  pos + 1,
                  end);

    return root;
}

void preorderPrint(Node* root) {

    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorderPrint(root->left);

    preorderPrint(root->right);
}

int main() {

    vector<int> preorder = {3,9,20,15,7};

    vector<int> inorder = {9,3,15,20,7};

    Node* root =
        buildTree(preorder,
                  inorder,
                  0,
                  inorder.size() - 1);

    cout << "Preorder Traversal: ";

    preorderPrint(root);

    return 0;
}