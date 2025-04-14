# 🎲 Board Game Café Inventory System Design

## Program Overview

This is a lightweight system for managing board game lending at a café. The goal is to track what games the café has, how many are available, who borrowed what, and when it’s due back. Staff should be able to see the full inventory, check out games, and mark them as returned. Simple, organized, and easy to use.

---

## Nouns and Verbs

### Nouns (used as classes or attributes)
- Board Game  
- Customer  
- Loan  
- Inventory  
- Due Date  
- Copies  
- Checkout Date  

### Verbs (used as methods)
- View inventory  
- Check out a game  
- Return a game  
- Add or remove games  
- Find customers or games  
- Show loans by customer  

---

## Class Definitions

```cpp
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
classDiagram
    class BoardGame {
        -string title
        -string category
        -int totalCopies
        -int availableCopies
        +BoardGame(title: string, category: string, totalCopies: int)
        +getTitle() string
        +getCategory() string
        +getTotalCopies() int
        +getAvailableCopies() int
        +incrementAvailable() void
        +decrementAvailable() void
        +isAvailable() bool
    }
    
    class Customer {
        -string name
        -string contactInfo
        -vector~Loan*~ activeLoans
        +Customer(name: string, contactInfo: string)
        +getName() string
        +getContactInfo() string
        +addLoan(loan: Loan*) void
        +removeLoan(loan: Loan*) void
        +getActiveLoans() vector~Loan*~
    }
    
    class Loan {
        -BoardGame* game
        -Customer* borrower
        -string checkoutDate
        -string dueDate
        -bool isReturned
        +Loan(game: BoardGame*, borrower: Customer*, checkoutDate: string, dueDate: string)
        +getGame() BoardGame*
        +getBorrower() Customer*
        +getCheckoutDate() string
        +getDueDate() string
        +getReturnStatus() bool
        +markAsReturned() void
    }
    
    class InventorySystem {
        -vector~BoardGame*~ games
        -vector~Customer*~ customers
        -vector~Loan*~ loans
        +InventorySystem()
        +~InventorySystem()
        +addGame(title: string, category: string, copies: int) void
        +removeGame(title: string) void
        +addCustomer(name: string, contactInfo: string) void
        +findGame(title: string) BoardGame*
        +findCustomer(name: string) Customer*
        +checkoutGame(gameTitle: string, customerName: string, loanDays: int) Loan*
        +returnGame(loan: Loan*) void
        +getAvailableGames() vector~BoardGame*~
        +getActiveLoans() vector~Loan*~
        +displayInventory() void
        +displayLoansByCustomer(customerName: string) void
    }
    
    InventorySystem "1" --* "many" BoardGame: manages
    InventorySystem "1" --* "many" Customer: tracks
    InventorySystem "1" --* "many" Loan: records
    Loan "0..n" --o "1" BoardGame: references
    Loan "0..n" --o "1" Customer: belongs to
    Customer "1" --o "0..n" Loan: has