#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

int main() {
    std::vector<int> numbers;
    int input;

    std::cout << "Enter integers to add to the vector (type '0' to end): ";
    while (true) {
        if (std::cin >> input) {
            if (input == 0) break;
            numbers.push_back(input);
        } else {
            std::cout << "Error: Invalid input. Please enter an integer: ";
            std::cin.clear(); // Clears error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore wrong input
        }
    }

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());

    std::cout << "Sum of elements: " << sum << "\n";
    std::cout << "Product of elements: " << product << "\n";

    return 0;
}
