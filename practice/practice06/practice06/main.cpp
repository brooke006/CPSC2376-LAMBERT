#include "MixedFraction.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

vector<string> history;

void displayMenu() {
    cout << "\nOptions:\n";
    cout << "1. Enter a fraction manually\n";
    cout << "2. Add a fraction\n";
    cout << "3. Subtract a fraction\n";
    cout << "4. Multiply by a fraction\n";
    cout << "5. Divide by a fraction\n";
    cout << "6. Display as Mixed Fraction\n";
    cout << "7. View History\n";
    cout << "8. Print History to File\n";
    cout << "9. Clear Fraction\n";
    cout << "10. Exit\n";
}

Fraction getFractionInput() {
    int n, d;
    while (true) {
        cout << "Enter fraction (numerator denominator): ";
        cin >> n >> d;
        if (cin.fail() || d == 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Denominator cannot be zero. Try again.\n";
            system("msg * Error: Invalid fraction input!");
        }
        else {
            break;
        }
    }
    return Fraction(n, d);
}

void saveHistoryToFile() {
    ofstream file("fraction_history.txt");
    if (!file) {
        cout << "Error opening file.\n";
        system("msg * Error: Unable to open file for writing.");
        return;
    }
    file << "Fraction Calculation History:\n";
    for (const string& entry : history) {
        file << entry << endl;
    }
    file.close();
    cout << "History saved to 'fraction_history.txt'.\n";
}

int main() {
    Fraction currentFraction;
    int choice;

    cout << "Fraction Calculator\n";

    do {
        cout << "\nCurrent Fraction: " << currentFraction << endl;
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 10) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Enter a number between 1 and 10.\n";
            system("msg * Error: Invalid menu choice!");
            continue;
        }

        if (choice == 1) {
            currentFraction = getFractionInput();
        }
        else if (choice >= 2 && choice <= 5) {
            Fraction newFraction = getFractionInput();
            switch (choice) {
            case 2: currentFraction = currentFraction + newFraction; break;
            case 3: currentFraction = currentFraction - newFraction; break;
            case 4: currentFraction = currentFraction * newFraction; break;
            case 5: currentFraction = currentFraction / newFraction; break;
            }

            ostringstream ss;
            ss << currentFraction.getNumerator() << "/" << currentFraction.getDenominator();
            history.push_back(ss.str());
        }
        else if (choice == 6) {
            cout << "Mixed Fraction: " << MixedFraction(currentFraction) << endl;
        }
        else if (choice == 7) {
            cout << "History:\n";
            for (const auto& entry : history) cout << entry << endl;
        }
        else if (choice == 8) {
            saveHistoryToFile();
        }
        else if (choice == 9) {
            currentFraction = Fraction();
            cout << "Fraction reset to 0/1.\n";
        }
    } while (choice != 10);

    cout << "Exiting program.\n";
    return 0;
}
