#include <iostream>
using namespace std;

// 🔹 Abstraction (abstract class)
class Animal {
public:
    // pure virtual function
    virtual void sound() = 0;

    void eat() {
        cout << "Animal eats\n";
    }
};

// 🔹 Inheritance (Dog inherits Animal)
class Dog : public Animal {
public:
    // 🔹 Polymorphism (function overriding)
    void sound() {
        cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void sound() {
        cout << "Cat meows\n";
    }
};

int main() {
    Animal* a;   // base class pointer

    Dog d;
    Cat c;

    // runtime polymorphism
    a = &d;
    a->sound();   // Dog version
    a->eat();     // inherited function

    a = &c;
    a->sound();   // Cat version

    return 0;
}