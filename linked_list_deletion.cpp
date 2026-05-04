#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // helper to add data (so we can test pop)
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // pop_front
    void pop_front() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // pop_back
    void pop_back() {
        if (head == NULL) return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList ll;

    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);

    ll.display();   // 10 -> 20 -> 30 -> NULL

    ll.pop_front();
    ll.display();   // 20 -> 30 -> NULL

    ll.pop_back();
    ll.display();   // 20 -> NULL

    return 0;
}