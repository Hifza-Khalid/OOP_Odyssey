#include <iostream>
using namespace std;

// Base class A
class A {
public:
    void display() {
        cout << "Class A" << endl;
    }
};

// Class B inherits from A
class B : public A {
public:
    void display() {
        cout << "Class B" << endl;
    }
};

// Class C inherits from A
class C : public A {
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
    
    // Which display function from A should be called? This is the ambiguity.
    return 0;
}
