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
        tail->next = head;
    }

    // delete at head
    void delete_head() {
        if (head == NULL) return;

        Node* temp = head;

        // single node
        if (head == tail) {
            head = tail = NULL;
            delete temp;
            return;
        }

        head = head->next;
        tail->next = head;

        temp->next = NULL;
        delete temp;
    }

    //  delete at tail 
    void delete_tail() {
        if (head == NULL) return;

        // single node
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = tail;   
        Node* prev = head;   

        while (prev->next != tail) {
            prev = prev->next;
        }

        tail = prev;        
        tail->next = head;   

        temp->next = NULL;   
        delete temp;         
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

    cll.push_back(10);
    cll.push_back(20);
    cll.push_back(30);
    cll.push_back(40);

    cout << "Initial: ";
    cll.display();

    cll.delete_head();
    cout << "After delete head: ";
    cll.display();

    cll.delete_tail();
    cout << "After delete tail: ";
    cll.display();

    return 0;
}