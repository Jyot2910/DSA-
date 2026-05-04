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

    // push_back
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

    // insert at position (no temp==NULL check)
    void insertAtPosition(int pos, int val) {
        Node* newNode = new Node(val);

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // search with index (1-based)
    int search(int key) {
        Node* temp = head;
        int index = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                return index;
            }
            temp = temp->next;
            index++;
        }

        return -1; // not found
    }

    // display
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
    ll.push_back(40);

    ll.display();

    ll.insertAtPosition(3, 25);
    ll.display();

    int pos = ll.search(25);

    if (pos != -1)
        cout << "Found at position: " << pos << endl;
    else
        cout << "Not Found\n";

    return 0;
}