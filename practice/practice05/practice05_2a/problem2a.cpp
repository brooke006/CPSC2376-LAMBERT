#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

int main() {
    std::vector<int> numbers;
    int input;
    int count = 5;  // Set a specific number of inputs

    std::cout << "Enter exactly " << count << " integers to calculate their sum and product (one per line):" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "Input " << i + 1 << ": ";
        while (!(std::cin >> input)) {
            std::cout << "Invalid input detected. Please enter a whole number: ";
            std::cin.clear(); // Clears error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards incorrect input
            std::cout << "Input " << i + 1 << ": ";
        }
        numbers.push_back(input);
    }

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());

    std::cout << "Total sum of the elements: " << sum << "\n";
    std::cout << "Product of the elements: " << product << "\n";

    return 0;
}
