#include <iostream>
using namespace std;

class Counter {
private:
    static int count;  // Static member variable

public:
    Counter() {
        count++;  // Increment static variable whenever an object is created
    }

    static int getCount() {  // Static member function
        return count;
    }
};

// Initialize static member outside the class definition
int Counter::count = 0;

int main() {
    cout << "Initial count: " << Counter::getCount() << endl;  // Access static method without creating an object

    Counter c1;  // Create first object
    Counter c2;  // Create second object

    cout << "Count after two objects: " << Counter::getCount() << endl;  // Access static method again

    return 0;
}
