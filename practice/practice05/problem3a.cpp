#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

int main() {
    std::vector<int> numbers;
    int input;

    std::cout << "Enter integers to be squared (type '0' to end): ";
    while (true) {
        if (std::cin >> input) {
            if (input == 0) break;
            numbers.push_back(input);
        }
        else {
            std::cout << "Error: Invalid input. Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << "Elements squared: ";
    std::for_each(numbers.begin(), numbers.end(), [](int& n) {
        n *= n;
        std::cout << n << " ";
        });
    std::cout << "\n";

    int sumSquares = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of squares: " << sumSquares << "\n";

    return 0;
}
