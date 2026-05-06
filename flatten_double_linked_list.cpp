#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

// Flatten function
Node* flatten(Node* head) {
    if (head == NULL) return head;

    Node* curr = head;

    while (curr != NULL) {

        if (curr->child != NULL) {
            Node* next = curr->next;

            // flatten child
            curr->next = flatten(curr->child);
            curr->next->prev = curr;
            curr->child = NULL;

            // go to tail of child
            Node* temp = curr->next;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            // reconnect next
            temp->next = next;
            if (next != NULL) {
                next->prev = temp;
            }
        }

        curr = curr->next;
    }

    return head;
}

// display
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating sample multilevel list
    // 1 - 2 - 3 - 4
    //         |
    //         7 - 8

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    // main list
    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    // child list
    n3->child = n7;
    n7->next = n8;
    n8->prev = n7;

    cout << "Original (top level only):\n";
    display(n1);

    Node* flat = flatten(n1);

    cout << "\nFlattened:\n";
    display(flat);

    return 0;
}