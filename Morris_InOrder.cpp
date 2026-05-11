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

vector<int> morrisInorder(Node* root) {

    vector<int> ans;

    Node* curr = root;

    while (curr != NULL) {

        // Case 1 : No left child
        if (curr->left == NULL) {

            ans.push_back(curr->data);

            curr = curr->right;
        }

        // Case 2 : Left subtree exists
        else {

            // Find inorder predecessor
            Node* IP = curr->left;

            while (IP->right != NULL &&
                   IP->right != curr) {

                IP = IP->right;
            }

            // Create thread
            if (IP->right == NULL) {

                IP->right = curr;

                curr = curr->left;
            }

            // Thread already exists
            else {

                // Remove thread
                IP->right = NULL;

                ans.push_back(curr->data);

                curr = curr->right;
            }
        }
    }

    return ans;
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = morrisInorder(root);

    cout << "Morris Inorder: ";

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}