// ================================
// Title: Senior Citizens Outing Management System
// Description: 
// This program manages the outing of senior citizens by:
// - Gathering outing information
// - Recording participants and their payments
// - Calculating outing costs and profits/losses
// ================================

#include<iostream>
#include<cmath>
using namespace std;

// Global Variables
int total_citizens;            // Total number of citizens going for outing
int Cares_for_outing = 0;      // Number of carers required

// ================================
// Class: Citizen_information
// Purpose: Handles citizen outing input and cost calculations
// ================================
class Citizen_information
{ 
protected:
    double total_cost_meal;
    double cost_for_coach;
    double cost_for_tickets;
    double Total_cost;

public:
    // Set default carers for outing
    int set_Care_for_outing(int care_by_default)
    {
        Cares_for_outing = care_by_default;
        return Cares_for_outing;
    }

    // Get user input and validate number of citizens
    void Citizens_Information()
    {
        cout << "\n Enter total Number of Citizens for Outing: ";
        cin >> total_citizens;

        // Validation: between 10 and 36 (exclusive)
        while (total_citizens < 10 || total_citizens >= 36)
        {
            cout << "\n Minimum Citizens required to go out for outing is 10.\n";
            cout << "Enter valid Number of Citizens (10-35): ";
            cin >> total_citizens;
        }

        // Assign carer if citizens > 24
        if (total_citizens > 24)
        {
            Cares_for_outing++;
        }
    }

    // Calculate total cost for outing based on slabs
    int calculate_information(int total_citizens)
    {
        cout << "\n Calculated Total Cost of Outing Through " << total_citizens << " citizens.\n";

        // Cost slabs
        if (total_citizens >= 11 && total_citizens <= 16)
        {
            total_cost_meal = 14.00;
            cost_for_coach = 150;
            cost_for_tickets = 21.00;
        }
        else if (total_citizens >= 17 && total_citizens <= 26)
        {
            total_cost_meal = 13.50;
            cost_for_coach = 190;
            cost_for_tickets = 20.00;
        }
        else if (total_citizens >= 27 && total_citizens <= 36)
        {
            total_cost_meal = 13.00;
            cost_for_coach = 225;
            cost_for_tickets = 19.00;
        }

        // Total cost calculated
        Total_cost = total_citizens * total_cost_meal * cost_for_tickets;
        return Total_cost;
    }
};

// ================================
// Class: ParticipantRecorder
// Purpose: Records participant details and calculates total amount paid
// ================================
class ParticipantRecorder {
public:
    int recordParticipants(int total_citizens) {
        string names[total_citizens + Cares_for_outing];         // Combined array for citizens and carers
        double amountsPaid_for_meal[total_citizens + Cares_for_outing] = {0};
        double amountsPaid_for_ticket[total_citizens + Cares_for_outing] = {0};

        // Display cost slabs
        cout << "\n______________________________________________________________\n";
        cout << "\nNo of people  : Cost for Meal  : Ticket Amount\n";
        cout << "12-16         :   $14.00       : $21.00\n";
        cout << "17-26         :   $13.50       : $20.00\n";
        cout << "27-36         :   $13.00       : $19.00\n";
        cout << "______________________________________________________________\n";

        // Input names and payments for senior citizens
        for (int i = 0; i < total_citizens; i++) {
            cout << "\nEnter name of Senior Citizen " << i + 1 << ": ";
            cin >> names[i];
            cout << "Enter amount for meal paid by " << names[i] << ": ";
            cin >> amountsPaid_for_meal[i];
            cout << "Enter amount for ticket paid by " << names[i] << ": ";
            cin >> amountsPaid_for_ticket[i];
        }

        // Input names of carers (no cost input assumed)
        for (int i = 0; i < Cares_for_outing; i++) {
            cout << "\nEnter name of Carer " << i + 1 << ": ";
            cin >> names[total_citizens + i];
        }

        // Display all participants and amount paid
        cout << "\n\nList of Participants and Amounts Paid:\n";
        for (int i = 0; i < total_citizens; i++) {
            cout << names[i] << "\t      $ " << amountsPaid_for_meal[i] + amountsPaid_for_ticket[i] << endl;
        }
        for (int i = total_citizens; i < total_citizens + Cares_for_outing; i++) {
            cout << names[i] << "\t      $0.00 (Carer)\n";
        }

        // Calculate total collected amount
        double totalAmountCollected = 0;
        for (int i = 0; i < total_citizens; i++) {
            totalAmountCollected += amountsPaid_for_meal[i] + amountsPaid_for_ticket[i];
        }
        cout << "\nTotal Amount Collected: $" << totalAmountCollected << endl;
        return totalAmountCollected;
    }
};

// ================================
// Class: OutingProfitCalculator
// Purpose: Calculates profit or loss from outing
// ================================
class OutingProfitCalculator {
public:
    void calculateProfit(double totalCost, double totalAmountCollected) {
        if (totalAmountCollected >= totalCost) {
            double profit = totalAmountCollected - totalCost;
            cout << "\nThe outing has made a profit of $" << profit << endl;
        } else {
            double loss = totalCost - totalAmountCollected;
            cout << "\nThe outing has incurred a loss of $" << loss << endl;
        }
    }
};

// ================================
// Function: main()
// Purpose: User interaction and menu
// ================================
int main() {
    Citizen_information citizenInfo;
    ParticipantRecorder participantRecorder;
    OutingProfitCalculator profitCalculator;
    int choice;
    double total_cost = 0, user_cost = 0;

    do {
        // Menu options
        cout << "\n=================== MENU ===================";
        cout << "\n1. Enter Citizens Information (Task 1)";
        cout << "\n2. Record Participants (Task 2)";
        cout << "\n3. Calculate Profit (Task 3)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Handle user choice
        switch (choice) {
            case 1:
                citizenInfo.Citizens_Information();
                citizenInfo.set_Care_for_outing(2); // Set default carers
                total_cost = citizenInfo.calculate_information(total_citizens);
                break;
            case 2:
                user_cost = participantRecorder.recordParticipants(total_citizens);
                break;
            case 3:
                profitCalculator.calculateProfit(total_cost, user_cost);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
