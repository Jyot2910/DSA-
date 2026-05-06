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

// Your approach: recurse first, then reverse
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;

    // check if k nodes exist
    for (int i = 0; i < k; i++) {
        if (temp == NULL) return head;
        temp = temp->next;
    }

    // recursive call for rest
    ListNode* prevNode = reverseKGroup(temp, k);

    // reverse current k nodes
    temp = head;
    int cnt = 0;

    while (cnt < k) {
        ListNode* next = temp->next;
        temp->next = prevNode;

        prevNode = temp;
        temp = next;

        cnt++;
    }

    return prevNode;
}

// helper: insert
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
    ListNode* head = NULL;

    push_back(head, 1);
    push_back(head, 2);
    push_back(head, 3);
    push_back(head, 4);
    push_back(head, 5);
    push_back(head, 6);

    cout << "Original: ";
    display(head);

    head = reverseKGroup(head, 2);

    cout << "Reversed (k-group): ";
    display(head);

    return 0;
}