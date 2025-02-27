#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <limits>

int main() {
    std::vector<int> numbers;
    int input;
    int count = 5;  // Set the specific number of inputs

    std::cout << "Enter exactly " << count << " integers (one per line):" << std::endl;
    for (int i = 0; i < count; i++) {
        while (true) {
            std::cout << "Input " << i + 1 << ": ";
            if (!(std::cin >> input)) {
                std::cout << "Invalid input detected. Please enter a whole number: ";
                std::cin.clear(); // Clears error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards incorrect input
            } else {
                numbers.push_back(input);
                break;
            }
        }
    }

    std::cout << "You entered: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    int sumEven = std::accumulate(numbers.begin(), numbers.end(), 0,
        [](int sum, int n) { return sum + (n % 2 == 0 ? n : 0); });

    std::cout << "Sum of the even numbers: " << sumEven << "\n";

    return 0;
}
