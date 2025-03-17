#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

int main() {
    std::vector<int> numbers;
    int input;
    int count = 5;  // Set a specific number of inputs

    std::cout << "Enter exactly " << count << " integers to square each and compute the sum of squares (one per line):" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "Input " << i + 1 << ": ";
        while (!(std::cin >> input)) {
            std::cout << "Invalid input detected. Please enter a whole number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input " << i + 1 << ": ";
        }
        numbers.push_back(input);
    }

    std::cout << "Each number squared: ";
    std::for_each(numbers.begin(), numbers.end(), [](int& n) {
        n *= n;
        std::cout << n << " ";
        });
    std::cout << "\n";

    int sumSquares = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of the squared numbers: " << sumSquares << "\n";

    return 0;
}

