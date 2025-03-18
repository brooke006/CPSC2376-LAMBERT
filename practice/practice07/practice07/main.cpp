#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <memory>

// Base Class: Employee (As required in prompt)
class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string name, int id) : name(std::move(name)), id(id) {}
    virtual ~Employee() = default;

    virtual double calculateSalary() const = 0;  // Pure virtual function (As required in prompt)

    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

// Derived Class: SalariedEmployee (As required in prompt)
class SalariedEmployee : public Employee {
    double monthlySalary;

public:
    SalariedEmployee(std::string name, int id, double salary)
        : Employee(std::move(name), id), monthlySalary(salary) {
    }

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Salaried, Monthly Salary: $" << std::fixed << std::setprecision(2)
            << monthlySalary << "\n";
    }
};

// Derived Class: HourlyEmployee (As required in prompt)
class HourlyEmployee : public Employee {
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(std::string name, int id, double rate, int hours)
        : Employee(std::move(name), id), hourlyRate(rate), hoursWorked(hours) {
    }

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked
            << ", Hourly Rate: $" << std::fixed << std::setprecision(2)
            << hourlyRate << ", Salary: $" << calculateSalary() << "\n";
    }
};

// Derived Class: CommissionEmployee (As required in prompt)
class CommissionEmployee : public Employee {
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(std::string name, int id, double base, double sales, double rate)
        : Employee(std::move(name), id), baseSalary(base), salesAmount(sales), commissionRate(rate) {
    }

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Commission, Base Salary: $" << baseSalary
            << ", Sales: $" << salesAmount << ", Commission Rate: "
            << (commissionRate * 100) << "%, Salary: $" << calculateSalary() << "\n";
    }
};

// Function to process employee file (As required in prompt)
std::vector<std::unique_ptr<Employee>> readEmployeesFromFile(const std::string& filename) {
    std::vector<std::unique_ptr<Employee>> employees;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return employees;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        int id;
        std::string name;
        double val1, val2, val3;

        ss >> type >> id;
        std::getline(ss >> std::ws, name, ' ');

        if (type == "Salaried") {
            ss >> val1;
            if (!ss.fail() && val1 > 0) employees.push_back(std::make_unique<SalariedEmployee>(name, id, val1));
        }
        else if (type == "Hourly") {
            ss >> val1 >> val2;
            if (!ss.fail() && val1 > 0 && val2 >= 0) employees.push_back(std::make_unique<HourlyEmployee>(name, id, val1, static_cast<int>(val2)));
        }
        else if (type == "Commission") {
            ss >> val1 >> val2 >> val3;
            if (!ss.fail() && val1 > 0 && val2 >= 0 && val3 >= 0) employees.push_back(std::make_unique<CommissionEmployee>(name, id, val1, val2, val3));
        }
        else {
            std::cerr << "Warning: Invalid employee type found in file: " << type << "\n";
        }
    }

    return employees;
}

// Main Function (As required in prompt)
int main() {
    const std::string filename = "employees.txt";
    auto employees = readEmployeesFromFile(filename);

    if (employees.empty()) {
        std::cout << "No employees to display.\n";
        return 1;
    }

    std::cout << "==== Employee Salary Report ====\n";
    for (const auto& emp : employees) {
        emp->displayInfo();
    }

    return 0; // Smart pointers automatically clean up memory
}
