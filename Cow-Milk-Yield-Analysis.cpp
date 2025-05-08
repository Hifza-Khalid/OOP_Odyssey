// ---------------------------------------------------------------
// Title: Cow Milk Yield Management System
// Description: This program records and analyzes weekly milk yield 
//              for a herd of cows using classes, arrays, and basic 
//              statistical functions.
// Author: Hifza Khalid
// ---------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

const int herd = 2; // Total number of cows in the herd

// ---------------------------
// Class: CowRecord
// Purpose: Stores and processes milk yield for each cow
// ---------------------------
class CowRecord {
protected:
    float total = 0; // Total milk yield for a cow
    int record_ID; // Cow's record ID
    float milk_yield[7][2]; // 7 days, 2 milking sessions per day

public:
    // Getter for Record ID
    int getRecordID() {
        return record_ID;
    }

    // Incorrect getter for 2D array; placeholder only (won't work as intended)
    float get_milkyield() {
        return milk_yield[7][2]; // ❌ Incorrect usage; this will lead to out-of-bounds
    }

    // Function to input milk yield data
    int RecordCowData(int cow_number) {
        cout << "Enter Data of Record ID " << cow_number + 1 << " Cow: ";
        cin >> record_ID;

        // Loop through 7 days and 2 sessions per day
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 2; k++) {
                cout << "Enter milk yield for Day " << j + 1 << ", Milking cycle " << k + 1 << ": ";
                cin >> milk_yield[j][k];
            }
        }
    }

    // Function to calculate total yield
    float TotalYield() {
        total = 0; // Reset total before summing again
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 2; j++) {
                total += milk_yield[i][j];
            }
        }
        return total;
    }

    // Function to calculate average yield per session
    float AverageYield() {
        return total / 14; // 7 days * 2 sessions
    }

    // Getter for individual milk yield values
    float getMilkAt(int day, int session) {
        return milk_yield[day][session];
    }
};

// ---------------------------
// Class: Statistics
// Purpose: Provides static methods for calculating total and average yields
// ---------------------------
class Statistics {
public:
    // Calculates total weekly milk volume of all cows
    static float WeeklyVolume(CowRecord records[]) {
        float total = 0;
        for (int i = 0; i < herd; i++) {
            total += records[i].TotalYield();
        }
        return total;
    }

    // Calculates average milk yield per cow
    static float AverageYield(CowRecord records[]) {
        float total = 0;
        for (int i = 0; i < herd; i++) {
            total += records[i].TotalYield();
        }
        return total / herd;
    }
};

// ---------------------------
// Class: Productivity
// Purpose: Analyzes productivity of cows
// ---------------------------
class Productivity {
public:
    // Finds and displays the most productive cow
    static void MostProductiveCow(CowRecord records[]) {
        int most_productive = 0;
        float highest_yield = records[0].TotalYield();

        for (int i = 1; i < herd; i++) {
            float current_yield = records[i].TotalYield();
            if (current_yield > highest_yield) {
                highest_yield = current_yield;
                most_productive = i;
            }
        }

        cout << "Most productive cow is with Record ID " 
             << records[most_productive].getRecordID() 
             << " with total yield of " << highest_yield << " liters.\n";
    }

    // Finds and displays cows with 4 or more days having low yield (<12L)
    static void LowYieldCows(CowRecord records[]) {
        for (int i = 0; i < herd; i++) {
            int low_yield_days = 0;
            for (int j = 0; j < 7; j++) {
                float daily_total = 0;
                for (int k = 0; k < 2; k++) {
                    daily_total += records[i].getMilkAt(j, k);
                }
                if (daily_total < 12.0) {
                    low_yield_days++;
                }
            }

            if (low_yield_days >= 4) {
                cout << "Cow with Record ID " << records[i].getRecordID()
                     << " has produced less than 12 liters of milk on four or more days this week.\n";
            }
        }
    }
};

// ---------------------------
// Main Function
// ---------------------------
int main() {
    CowRecord records[herd]; // Array of CowRecord objects
    Statistics stats;
    Productivity productivity;

    int choice;

    // Menu-based interface
    do {
        cout << "\nMenu:\n";
        cout << "1. Record milk yield for cows\n";
        cout << "2. Calculate total weekly volume and average yield per cow\n";
        cout << "3. Identify the most productive cow and cows with low yield\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < herd; i++) {
                    records[i].RecordCowData(i);
                }
                break;

            case 2:
                cout << "\nTotal weekly volume of milk for the herd: "
                     << stats.WeeklyVolume(records) << " liters.\n";
                cout << "Average yield per cow in a week: "
                     << stats.AverageYield(records) << " liters.\n";
                break;

            case 3:
                productivity.MostProductiveCow(records);
                productivity.LowYieldCows(records);
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
