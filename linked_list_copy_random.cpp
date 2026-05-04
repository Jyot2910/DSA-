#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Copy function
Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;

    unordered_map<Node*, Node*> m;

    // Step 1: copy nodes (next pointers)
    Node* newHead = new Node(head->val);
    Node* oldTemp = head->next;
    Node* newTemp = newHead;

    m[head] = newHead;

    while (oldTemp != NULL) {
        Node* copyNode = new Node(oldTemp->val);
        m[oldTemp] = copyNode;

        newTemp->next = copyNode;

        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    // Step 2: assign random pointers (NO if-else)
    oldTemp = head;
    newTemp = newHead;

    while (oldTemp != NULL) {
        newTemp->random = m[oldTemp->random];  // clean line
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    return newHead;
}

// Helper: print list (val + random)
void display(Node* head) {
    while (head != NULL) {
        cout << "Val: " << head->val << " ";
        if (head->random)
            cout << "Random: " << head->random->val;
        else
            cout << "Random: NULL";
        cout << endl;

        head = head->next;
    }
}

int main() {
    // Creating list: 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    // random pointers
    n1->random = n3; // 1 -> 3
    n2->random = n1; // 2 -> 1
    n3->random = NULL;

    cout << "Original:\n";
    display(n1);

    Node* copy = copyRandomList(n1);

    cout << "\nCopied:\n";
    display(copy);

    return 0;
}