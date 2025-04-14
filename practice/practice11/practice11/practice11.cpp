// practice11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

class BoardGame {
private:
    std::string title;
    std::string category;
    int totalCopies;
    int availableCopies;

public:
    BoardGame(std::string title, std::string category, int totalCopies);
    std::string getTitle() const;
    std::string getCategory() const;
    int getTotalCopies() const;
    int getAvailableCopies() const;
    void incrementAvailable();
    void decrementAvailable();
    bool isAvailable() const;
};
cpp
Copy
Edit
class Customer {
private:
    std::string name;
    std::string contactInfo;
    std::vector<Loan*> activeLoans;

public:
    Customer(std::string name, std::string contactInfo);
    std::string getName() const;
    std::string getContactInfo() const;
    void addLoan(Loan* loan);
    void removeLoan(Loan* loan);
    std::vector<Loan*> getActiveLoans() const;
};
cpp
Copy
Edit
class Loan {
private:
    BoardGame* game;
    Customer* borrower;
    std::string checkoutDate;
    std::string dueDate;
    bool isReturned;

public:
    Loan(BoardGame* game, Customer* borrower, std::string checkoutDate, std::string dueDate);
    BoardGame* getGame() const;
    Customer* getBorrower() const;
    std::string getCheckoutDate() const;
    std::string getDueDate() const;
    bool getReturnStatus() const;
    void markAsReturned();
};
cpp
Copy
Edit
class InventorySystem {
private:
    std::vector<BoardGame*> games;
    std::vector<Customer*> customers;
    std::vector<Loan*> loans;

public:
    InventorySystem();
    ~InventorySystem();
    void addGame(std::string title, std::string category, int copies);
    void removeGame(std::string title);
    void addCustomer(std::string name, std::string contactInfo);
    BoardGame* findGame(std::string title) const;
    Customer* findCustomer(std::string name) const;
    Loan* checkoutGame(std::string gameTitle, std::string customerName, int loanDays);
    void returnGame(Loan* loan);
    std::vector<BoardGame*> getAvailableGames() const;
    std::vector<Loan*> getActiveLoans() const;
    void displayInventory() const;
    void displayLoansByCustomer(std::string customerName) const;
};


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
