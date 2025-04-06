#include <iostream>
using namespace std;

// Base class: Shape
class Shape {
public:
    // Virtual function for runtime polymorphism (method overriding)
    virtual void draw() {
        cout << "🖼️ Drawing a shape!" << endl;
    }
};

// Derived class: Circle, overrides the draw method of the Shape class
class Circle : public Shape {
public:
    void draw() override {
        cout << "⭕ Drawing a Circle!" << endl;
    }
};

// Derived class: Square, overrides the draw method of the Shape class
class Square : public Shape {
public:
    void draw() override {
        cout << "🟦 Drawing a Square!" << endl;
    }
};

// Method Overloading (Compile-time Polymorphism)
class Printer {
public:
    // Overloaded methods with different parameter types
    void print(int n) {
        cout << "Printing an integer: " << n << endl;
    }

    void print(double n) {
        cout << "Printing a double: " << n << endl;
    }

    void print(string s) {
        cout << "Printing a string: " << s << endl;
    }
};

int main() {
    // Runtime Polymorphism: Using pointers to base class (Shape)
    Shape* shape;
    Circle circle;
    Square square;

    shape = &circle;
    shape->draw();  // Output: ⭕ Drawing a Circle!

    shape = &square;
    shape->draw();  // Output: 🟦 Drawing a Square!

    // Compile-time Polymorphism: Method Overloading
    Printer printer;
    printer.print(5);      // Output: Printing an integer: 5
    printer.print(5.5);    // Output: Printing a double: 5.5
    printer.print("Hello"); // Output: Printing a string: Hello

    return 0;
}
