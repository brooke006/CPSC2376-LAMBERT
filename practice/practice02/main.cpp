#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

const string FILE_EXTENSION = "_balance.txt";

// Function prototypes
double readBalanceFromFile(const string& accountType);
void writeBalanceToFile(const string& accountType, double balance);
void checkBalance(const string& accountType, double balance);
void deposit(const string& accountType, double& balance);
void withdraw(const string& accountType, double& balance);
void printStatement(const string& accountType, double balance);

int main() {
    string userName, accountType;

    cout << "Enter your name: ";
    getline(cin, userName);

    while (true) {
        cout << "Choose account type (Checking/Savings): ";
        getline(cin, accountType);

        // Convert input to lowercase for case-insensitive comparison
        transform(accountType.begin(), accountType.end(), accountType.begin(), ::tolower);

        if (accountType == "checking" || accountType == "savings") {
            // Convert back to title case for display
            accountType[0] = toupper(accountType[0]);
            break;
        }
        else {
            cout << "Invalid choice. Please enter 'Checking' or 'Savings'." << endl;
        }
    }

    double balance = readBalanceFromFile(accountType);

    cout << "Welcome, " << userName << "! You are using your " << accountType << " account." << endl;
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Print Statement" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            checkBalance(accountType, balance);
            break;
        case 2:
            deposit(accountType, balance);
            break;
        case 3:
            withdraw(accountType, balance);
            break;
        case 4:
            printStatement(accountType, balance);
            break;
        case 5:
            cout << "Thank you for using Your Bank Account, " << userName << "! Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }
}

// Function to read the balance from the file
double readBalanceFromFile(const string& accountType) {
    ifstream inFile(accountType + FILE_EXTENSION);
    double balance;

    if (!inFile) {
        cout << "Initializing " << accountType << " account with $100.00..." << endl;
        balance = 100.00;
        writeBalanceToFile(accountType, balance);
    }
    else {
        inFile >> balance;
    }

    inFile.close();
    return balance;
}

// Function to write the balance to the file
void writeBalanceToFile(const string& accountType, double balance) {
    ofstream outFile(accountType + FILE_EXTENSION);
    if (!outFile) {
        cerr << "Error: Unable to write to file." << endl;
        exit(1);
    }
    outFile << fixed << setprecision(2) << balance;
    outFile.close();
}

// Function to check the balance
void checkBalance(const string& accountType, double balance) {
    cout << "Your " << accountType << " account balance is: $" << fixed << setprecision(2) << balance << endl;
}

// Function to deposit money
void deposit(const string& accountType, double& balance) {
    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;
    if (cin.fail() || amount <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Deposit amount must be a positive number." << endl;
        return;
    }

    balance += amount;
    writeBalanceToFile(accountType, balance);
    cout << "Deposit successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
}

// Function to withdraw money
void withdraw(const string& accountType, double& balance) {
    double amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    if (cin.fail() || amount <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Withdrawal amount must be a positive number." << endl;
        return;
    }
    if (amount > balance) {
        cout << "Error: Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << endl;
        return;
    }

    balance -= amount;
    writeBalanceToFile(accountType, balance);
    cout << "Withdrawal successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
}

// Function to print the account statement
void printStatement(const string& accountType, double balance) {
    cout << "\n--- Account Statement for " << accountType << " Account ---" << endl;
    cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "---------------------------------------\n";
}
