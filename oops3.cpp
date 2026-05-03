#include <iostream>
using namespace std;

// 🔹 Abstract class
class Shape {
protected:
    static int count;   // static variable (shared across all objects)

public:
    Shape() {
        count++;   // count how many objects created
    }

    // pure virtual function (abstraction)
    virtual void area() = 0;

    // static function
    static void showCount() {
        cout << "Total Shapes Created: " << count << endl;
    }
};

// define static variable
int Shape::count = 0;


// 🔹 Derived class
class Circle : public Shape {
    int r;

public:
    Circle(int r) {
        this->r = r;
    }

    void area() {
        cout << "Circle Area: " << 3.14 * r * r << endl;
    }
};


// 🔹 Another derived class
class Rectangle : public Shape {
    int l, b;

public:
    Rectangle(int l, int b) {
        this->l = l;
        this->b = b;
    }

    void area() {
        cout << "Rectangle Area: " << l * b << endl;
    }
};


int main() {
    Shape* s;

    Circle c1(2);
    Rectangle r1(3, 4);

    // polymorphism
    s = &c1;
    s->area();

    s = &r1;
    s->area();

    // static function call
    Shape::showCount();

    return 0;
}