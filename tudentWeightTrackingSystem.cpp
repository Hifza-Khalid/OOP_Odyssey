// ********************************************************************
// Title: Student Weight Tracking System
// Description: This program tracks the weight of 30 students by 
// taking initial weights and names, recording the final weights,
// and calculating the difference. It also identifies students
// with a weight change of more than 2.5 kg.
// ********************************************************************

#include <iostream>
#include <string>
using namespace std;

const int maximum_pupil = 30;  // Maximum number of students

// Function to input initial weights and names
void Student_data(double weights[], string names[]) {
    cout << "Enter the weights and names for the class of 30 pupils:\n";
    for (int i = 0; i < maximum_pupil; ++i) {
        cout << "Enter weight for pupil " << i + 1 << " (in kilograms): ";
        cin >> weights[i];

        // Validate positive weight
        while (weights[i] <= 0) {
            cout << "Invalid weight. Please enter a positive value: ";
            cin >> weights[i];
        }

        cout << "Enter name for pupil " << i + 1 << ": ";
        cin.ignore();  // Clear newline character from buffer
        getline(cin, names[i]);  // Read full name
    }
}

// Function to input final term weights and compute weight differences
void calculating_weight_difference(double weights[], double weightDifferences[]) {
    double lastDayWeight;
    for (int i = 0; i < maximum_pupil; ++i) {
        cout << "Enter weight on the last day of term for pupil " << i + 1 << " (in kilograms): ";
        cin >> lastDayWeight;

        // Validate positive final weight
        while (lastDayWeight <= 0) {
            cout << "Invalid weight. Please enter a positive value: ";
            cin >> lastDayWeight;
        }

        // Calculate and store the difference in weight
        weightDifferences[i] = lastDayWeight - weights[i];
    }
}

// Function to output students with weight difference greater than 2.5 kg
void output_weight_difference(double weights[], string names[], double weightDifferences[]) {
    cout << "\nPupils with a weight difference of more than 2.5 kilograms:\n";
    bool check_student = false;

    for (int i = 0; i < maximum_pupil; ++i) {
        if (weightDifferences[i] > 2.5) {
            cout << "Name: " << names[i] << ", Difference: " << weightDifferences[i] << " kg\n";
            check_student = true;
        }
    }

    if (!check_student) {
        cout << "No student has a weight difference greater than 2.5 kilograms.\n";
    } else {
        cout << "\nAt least one student has a significant weight difference!\n";
    }
}

// Main function to handle user interaction
int main() {
    double weights[maximum_pupil];             // Array to store initial weights
    string names[maximum_pupil];               // Array to store student names
    double weightDifferences[maximum_pupil];   // Array to store weight differences

    // Display menu
    cout << "*************************************************************\n";
    cout << "*         STUDENT WEIGHT TRACKING SYSTEM MENU               *\n";
    cout << "*************************************************************\n";
    cout << "  1. Enter weights and names of students\n";
    cout << "  2. Enter weights on the last day of term\n";
    cout << "  3. Display weight differences greater than 2.5 kg\n";
    cout << "  0. Exit\n";
    cout << "*************************************************************\n";

    int choice;
    do {
        cout << "\nEnter choice for task completion (1, 2, 3, 0 to exit): ";
        cin >> choice;

        switch (choice) {
            case 1:
                Student_data(weights, names);
                break;
            case 2:
                calculating_weight_difference(weights, weightDifferences);
                break;
            case 3:
                output_weight_difference(weights, names, weightDifferences);
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
