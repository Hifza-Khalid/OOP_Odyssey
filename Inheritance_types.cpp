#include <iostream>
using namespace std;

// Base class for Single Inheritance
class Vehicle {
public:
    void startEngine() {
        cout << "🚗 Starting the engine..." << endl;
    }
};

// Single Inheritance: Car inherits from Vehicle
class Car : public Vehicle {
public:
    void honk() {
        cout << "📯 Honking the car horn!" << endl;
    }
};

// Multilevel Inheritance: SportsCar inherits from Car
class SportsCar : public Car {
public:
    void turboBoost() {
        cout << "💨 Activating turbo boost!" << endl;
    }
};

// Multiple Inheritance: ElectricCar inherits from both Vehicle and Car
class ElectricCar : public Vehicle, public Car {
public:
    void chargeBattery() {
        cout << "🔋 Charging the electric battery..." << endl;
    }
};

// Main function to demonstrate different types of inheritance
int main() {
    // Single Inheritance
    Car myCar;
    myCar.startEngine();  // Inherited from Vehicle
    myCar.honk();         // Defined in Car

    // Multilevel Inheritance
    SportsCar mySportsCar;
    mySportsCar.startEngine();  // Inherited from Vehicle
    mySportsCar.honk();         // Inherited from Car
    mySportsCar.turboBoost();   // Defined in SportsCar

    // Multiple Inheritance
    ElectricCar myElectricCar;
    myElectricCar.startEngine();  // Inherited from Vehicle
    myElectricCar.honk();         // Inherited from Car
    myElectricCar.chargeBattery(); // Defined in ElectricCar

    return 0;
}
