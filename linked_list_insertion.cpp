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

    // push_front
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {   // empty
            head = newNode;
        } else {              // not empty
            newNode->next = head;
            head = newNode;
        }
    }

    // push_back
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {   // empty
            head = newNode;
        } else {              // not empty
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // display
    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main() {
    LinkedList ll;

    ll.push_front(10);   // 10
    ll.push_front(20);   // 20 -> 10
    ll.push_back(30);    // 20 -> 10 -> 30
    ll.push_back(40);    // 20 -> 10 -> 30 -> 40

    ll.display();

    return 0;
}