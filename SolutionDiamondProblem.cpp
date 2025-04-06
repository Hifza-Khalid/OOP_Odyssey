#include <iostream>
using namespace std;

// Base class A
class A {
public:
    void display() {
        cout << "Class A" << endl;
    }
};

// Class B inherits virtually from A
class B : virtual public A {
public:
    void display() {
        cout << "Class B" << endl;
    }
};

// Class C inherits virtually from A
class C : virtual public A {
public:
    void display() {
        cout << "Class C" << endl;
    }
};

// Class D inherits from both B and C
class D : public B, public C {
public:
    void display() {
        cout << "Class D" << endl;
    }
};

int main() {
    D obj;
    
    // Call display function on D object
    obj.display();  // Output: Class D
    
    // Calling the base class display function (A's display) would now be unambiguous.
    return 0;
}
