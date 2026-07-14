#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped from stack.\n";
        top = top->next;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return;
        }

        cout << "Top Element: " << top->data << endl;
    }

    // Display by popping all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return;
        }

        cout << "Stack Elements: ";

        while (!isEmpty()) {
            cout << top->data << " ";
            Node* temp = top;
            top = top->next;
            delete temp;
        }

        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}