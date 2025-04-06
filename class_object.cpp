#include <iostream>
using namespace std;

// Defining the class
class Car {
public:
    // Attributes (properties)
    string make;
    string model;
    int year;

    // Constructor to initialize the attributes
    Car(string carMake, string carModel, int carYear) {
        make = carMake;
        model = carModel;
        year = carYear;
    }

    // Method to display car information with emojis
    void displayInfo() {
        cout << "🚗 Car Information: " << year << " " << make << " " << model << " 🏎️" << endl;
    }
};

// Main function
int main() {
    // Creating an object of the Car class
    Car myCar("Toyota", "Corolla", 2020);

    // Accessing the object's method with emojis
    myCar.displayInfo();  // Output: 🚗 Car Information: 2020 Toyota Corolla 🏎️

    return 0;
}
