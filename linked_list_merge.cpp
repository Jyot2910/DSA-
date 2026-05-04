#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

// Recursive merge
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

    // Base case
    if (head1 == NULL || head2 == NULL) {
        return head1 == NULL ? head2 : head1;
    }

    // Case 1
    if (head1->data <= head2->data) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    } 
    else { // Case 2
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
}

// helper to insert
void push_back(ListNode* &head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// display
void display(ListNode* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    // list 1
    push_back(l1, 1);
    push_back(l1, 2);
    push_back(l1, 4);

    // list 2
    push_back(l2, 1);
    push_back(l2, 3);
    push_back(l2, 4);

    cout << "List 1: ";
    display(l1);

    cout << "List 2: ";
    display(l2);

    ListNode* merged = mergeTwoLists(l1, l2);

    cout << "Merged: ";
    display(merged);

    return 0;
}