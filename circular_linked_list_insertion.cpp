#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;
    Node* tail;

    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // insert at head
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;  // circular link
            return;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;  // maintain circular
    }

    // insert at tail
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        tail->next = head;  // circular link
    }

    // display
    void display() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList cll;

    cll.push_front(20);
    cll.push_front(10);

    cll.push_back(30);
    cll.push_back(40);

    cll.display();

    return 0;
}