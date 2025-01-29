#include <iostream>
#include <vector>
#include <limits>

// Returns true if the vector is empty, prints a message if it is
bool checkIfEmpty(const std::vector<int>& vec)
{
    if (vec.empty())
    {
        std::cout << "The vector is currently empty. Please add some numbers first (Option 1).\n\n";
        return true;
    }
    return false;
}

// Prints all elements in the vector
void printVector(const std::vector<int>& vec)
{
    std::cout << "Current Vector Elements:\n";
    for (const auto& element : vec) // Using range-based for loop with const auto&
    {
        std::cout << element << ' ';
    }
    std::cout << "\n\n";
}

// Doubles all values in the vector
void doubleVector(std::vector<int>& vec)
{
    std::cout << "Doubling the vector values...\n";
    for (auto& element : vec) // Using range-based for loop with auto&
    {
        element *= 2;
    }
    std::cout << "Vector values doubled.\n";
    printVector(vec);
}

// Returns the sum of all elements in the vector
int calculateSum(const std::vector<int>& vec)
{
    int sum{ 0 };
    for (const auto& element : vec)
    {
        sum += element;
    }
    return sum;
}

// Prints all numbers that are multiples of the divisor
void printMultiples(const std::vector<int>& vec, int divisor)
{
    std::cout << "Multiples of " << divisor << " in the vector:\n";
    for (const auto& element : vec)
    {
        if (element % divisor == 0)
        {
            std::cout << element << ' ';
        }
    }
    std::cout << "\n\n";
}

// Cleans invalid input and clears buffer
void cleanInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Gets valid integer input from user
int getValidInput()
{
    int input{};
    while (!(std::cin >> input))
    {
        cleanInput();
        std::cout << "Invalid input. Please enter a valid integer: ";
    }
    return input;
}

int main()
{
    std::vector<int> numbers{};
    int choice{};

    do
    {
        std::cout << "\nMenu Options:\n"
            << "1. Add an item to the vector\n"
            << "2. Print the vector\n"
            << "3. Double the values in the vector\n"
            << "4. Find the sum of vector elements\n"
            << "5. Print multiples of a specific value\n"
            << "6. Exit\n\n"
            << "Enter your choice: ";

        choice = getValidInput();

        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter a number to add to the vector: ";
            int value{ getValidInput() };
            numbers.push_back(value);
            std::cout << value << " added to the vector.\n";
            printVector(numbers);
            break;
        }
        case 2:
        {
            if (!checkIfEmpty(numbers))
            {
                printVector(numbers);
            }
            break;
        }
        case 3:
        {
            if (!checkIfEmpty(numbers))
            {
                doubleVector(numbers);
            }
            break;
        }
        case 4:
        {
            if (!checkIfEmpty(numbers))
            {
                std::cout << "Sum of vector elements: " << calculateSum(numbers) << "\n\n";
            }
            break;
        }
        case 5:
        {
            if (!checkIfEmpty(numbers))
            {
                std::cout << "Enter the divisor (non-zero integer): ";
                int divisor{ getValidInput() };
                if (divisor == 0)
                {
                    std::cout << "Error: Divisor cannot be zero.\n";
                    break;
                }
                printMultiples(numbers, divisor);
            }
            break;
        }
        case 6:
        {
            std::cout << "Exiting program...\n";
            break;
        }
        default:
        {
            std::cout << "Invalid option. Please try again.\n\n";
            break;
        }
        }
    } while (choice != 6);

    return 0;
}
