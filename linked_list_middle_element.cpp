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

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    display(head);

    ListNode* mid = middleNode(head);

    cout << "Middle: " << mid->data << endl;

    return 0;
}