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

// reverse function
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* next = curr->next; // store next
        curr->next = prev;           // reverse
        prev = curr;                 // move prev
        curr = next;                 // move curr
    }

    return prev;
}

// insert at end (helper)
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
    ListNode* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    ListNode* head = NULL;

    push_back(head, 1);
    push_back(head, 2);
    push_back(head, 3);
    push_back(head, 4);
    push_back(head, 5);

    cout << "Original: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed: ";
    display(head);

    return 0;
}