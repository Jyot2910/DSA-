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

ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* first = head;
    ListNode* second = head->next;

    // recursive call
    first->next = swapPairs(second->next);

    // swap
    second->next = first;

    return second;
}

// helper
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

    cout << "Original: ";
    display(head);

    head = swapPairs(head);

    cout << "After Swap: ";
    display(head);

    return 0;
}