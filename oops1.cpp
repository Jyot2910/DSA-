#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    // 1️⃣ Default Constructor
    Student() {
        cout << "Default Constructor Called\n";
        name = "Unknown";
        age = 0;
    }

    // 2️⃣ Parameterized Constructor
    Student(string n, int a) {
        cout << "Parameterized Constructor Called\n";
        name = n;
        age = a;
    }

    // 3️⃣ Copy Constructor
    Student(const Student &s) {
        cout << "Copy Constructor Called\n";
        name = s.name;
        age = s.age;
    }

    // function
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    
    // object 1 → default constructor
    Student s1;
    s1.display();

    // object 2 → parameterized constructor
    Student s2("Jyot", 20);
    s2.display();

    // object 3 → copy constructor
    Student s3 = s2;
    s3.display();

    return 0;
}