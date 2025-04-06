#include <iostream>
#include <vector>
using namespace std;

// Abstract class - Vehicle (Abstraction)
class Vehicle {
protected:
    string brand;
    int year;

public:
    // Constructor to initialize brand and year
    Vehicle(string b, int y) : brand(b), year(y) {}

    // Pure virtual function (abstract method) for starting the vehicle
    virtual void start() = 0;

    // Virtual method to display general vehicle information
    virtual void displayInfo() {
        cout << "🚗 Brand: " << brand << ", Year: " << year << endl;
    }

    // Virtual destructor
    virtual ~Vehicle() {}
};

// Derived class - Car (Inheritance & Polymorphism)
class Car : public Vehicle {
private:
    int doors;  // Encapsulation: private attribute

public:
    // Constructor
    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {}

    // Overriding the start method (Polymorphism)
    void start() override {
        cout << "🚗 Starting the car engine... Vroom Vroom!" << endl;
    }

    // Overriding the displayInfo method (Polymorphism)
    void displayInfo() override {
        Vehicle::displayInfo();  // Calling the base class method
        cout << "🚙 Doors: " << doors << endl;
    }

    // Getter and Setter for doors (Encapsulation)
    void setDoors(int d) {
        doors = d;
    }

    int getDoors() {
        return doors;
    }
};

// Derived class - Motorcycle (Inheritance & Polymorphism)
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;  // Encapsulation: private attribute

public:
    // Constructor
    Motorcycle(string b, int y, bool sidecar) : Vehicle(b, y), hasSidecar(sidecar) {}

    // Overriding the start method (Polymorphism)
    void start() override {
        cout << "🏍️ Starting the motorcycle engine... Vroom Vroom!" << endl;
    }

    // Overriding the displayInfo method (Polymorphism)
    void displayInfo() override {
        Vehicle::displayInfo();  // Calling the base class method
        cout << "🏍️ Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }

    // Getter and Setter for sidecar (Encapsulation)
    void setSidecar(bool sidecar) {
        hasSidecar = sidecar;
    }

    bool getSidecar() {
        return hasSidecar;
    }
};

// Derived class - ElectricCar (Inheritance & Polymorphism)
class ElectricCar : public Car {
private:
    int batteryCapacity;  // Encapsulation: private attribute

public:
    // Constructor
    ElectricCar(string b, int y, int d, int battery) : Car(b, y, d), batteryCapacity(battery) {}

    // Overriding the start method (Polymorphism)
    void start() override {
        cout << "🔋 Starting the electric car silently..." << endl;
    }

    // Overriding the displayInfo method (Polymorphism)
    void displayInfo() override {
        Car::displayInfo();  // Calling the base class method
        cout << "🔋 Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }

    // Getter and Setter for batteryCapacity (Encapsulation)
    void setBatteryCapacity(int battery) {
        batteryCapacity = battery;
    }

    int getBatteryCapacity() {
        return batteryCapacity;
    }
};

int main() {
    // Creating objects of different vehicle types
    Vehicle* myCar = new Car("Toyota", 2020, 4);
    Vehicle* myMotorcycle = new Motorcycle("Harley-Davidson", 2019, true);
    Vehicle* myElectricCar = new ElectricCar("Tesla", 2022, 4, 75);

    // Storing all vehicles in a vector
    vector<Vehicle*> vehicles;
    vehicles.push_back(myCar);
    vehicles.push_back(myMotorcycle);
    vehicles.push_back(myElectricCar);

    // Demonstrating runtime polymorphism: calling the start method
    cout << "Starting the vehicles..." << endl;
    for (auto vehicle : vehicles) {
        vehicle->start();  // Runtime polymorphism based on object type
    }

    // Demonstrating runtime polymorphism: displaying vehicle info
    cout << "\nDisplaying vehicle info:" << endl;
    for (auto vehicle : vehicles) {
        vehicle->displayInfo();  // Runtime polymorphism based on object type
    }

    // Cleanup: Deleting dynamically allocated objects
    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
