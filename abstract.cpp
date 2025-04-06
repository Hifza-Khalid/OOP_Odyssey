#include <iostream>
using namespace std;

// Abstract class with a pure virtual function (abstract method)
class Vehicle {
public:
    // Pure virtual function (abstract method)
    virtual void startEngine() = 0;  // No implementation, must be overridden by derived class
    
    // Regular method to show common behavior
    void fuelUp() {
        cout << "⛽ Fueling up the vehicle!" << endl;
    }
};

// Derived class that provides implementation for the abstract method
class Car : public Vehicle {
public:
    // Overriding the pure virtual function (abstract method)
    void startEngine() override {
        cout << "🚗 Starting the car's engine... Vroom Vroom!" << endl;
    }
};

// Main function
int main() {
    // Creating an object of the derived class (Car)
    Car myCar;

    // Calling the implemented methods
    myCar.startEngine();  // Output: 🚗 Starting the car's engine... Vroom Vroom!
    myCar.fuelUp();       // Output: ⛽ Fueling up the vehicle!

    return 0;
}
