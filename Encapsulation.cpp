#include <iostream>
using namespace std;

class Car {
private:
    // Private attributes (encapsulated)
    string make;
    string model;
    int year;

public:
    // Constructor to initialize the car
    Car(string carMake, string carModel, int carYear) {
        make = carMake;
        model = carModel;
        year = carYear;
    }

    // Setter methods to set the values (Encapsulation)
    void setMake(string carMake) {
        make = carMake;
    }

    void setModel(string carModel) {
        model = carModel;
    }

    void setYear(int carYear) {
        year = carYear;
    }

    // Getter methods to access the values (Encapsulation)
    string getMake() {
        return make;
    }

    string getModel() {
        return model;
    }

    int getYear() {
        return year;
    }

    // Method to display car information with emojis
    void displayInfo() {
        cout << "🚗 Car Information: " << getYear() << " " << getMake() << " " << getModel() << " 🏎️" << endl;
    }
};

int main() {
    // Creating an object of the Car class
    Car myCar("Toyota", "Corolla", 2020);

    // Accessing the object's methods to display info with emojis
    myCar.displayInfo();  // Output: 🚗 Car Information: 2020 Toyota Corolla 🏎️

    // Modifying the car details using setter methods
    myCar.setMake("Honda");
    myCar.setModel("Civic");
    myCar.setYear(2023);

    // Displaying updated car information
    cout << "Updated Info: " << endl;
    myCar.displayInfo();  // Output: 🚗 Car Information: 2023 Honda Civic 🏎️

    return 0;
}
