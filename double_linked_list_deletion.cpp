#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // push_back
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // pop_front
    void pop_front() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;  

        temp->next = NULL;
        delete temp;
    }

    // pop_back 
    void pop_back() {
        if (tail == NULL) return;

        Node* temp = tail;     
        tail = tail->prev;     

        if (tail != NULL) {
            tail->next = NULL; 
        } else {
            head = NULL;       
        }

        temp->prev = NULL;     
        delete temp;           
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;

    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.push_back(40);

    dll.display();

    dll.pop_back();
    dll.display();

    dll.pop_front();
    dll.display();

    return 0;
}