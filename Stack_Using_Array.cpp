#include <iostream>
using namespace std;

class Stack {
    int top;
    int size;
    int* arr;

public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    int isempty() {
        if (top == -1) return 1;
        return 0;
    }

    int isfull() {
        if (top == size - 1) return 1;
        return 0;
    }

    void push(int data) {
        if (isfull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top = top + 1;
        arr[top] = data;
    }

    int pop() {
        if (isempty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int data = arr[top];
        top = top - 1;
        return data;
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    Stack s(size);

    int choice, data;
    do {
        cout << "\n1. Push\n2. Pop\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> data;
                s.push(data);
                break;
            case 2:
                cout << "Popped: " << s.pop() << endl;
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 3);

    return 0;
}