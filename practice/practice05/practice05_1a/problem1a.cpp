#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <limits>

int main() {
    std::vector<int> numbers;
    int input;

    std::cout << "Enter integers (type '0' to end): ";
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

    std::cout << "You entered: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    int sumEven = std::accumulate(numbers.begin(), numbers.end(), 0,
        [](int sum, int n) { return sum + (n % 2 == 0 ? n : 0); });

    std::cout << "Sum of even numbers: " << sumEven << "\n";

    return 0;
}
