#include <iostream>
#include <string>

int main() {
    float redPotion{ 0.0f };    // Amount of red potion in mL
    float bluePotion{ 0.0f };   // Amount of blue potion in mL
    float* flask{ nullptr };    // Pointer to the selected potion
    std::string choice;

    while (true) {
        std::cout << "Which potion to add liquid to? (Red/Blue, or type 'Done' to exit): ";
        std::cin >> choice;

        if (choice == "Done" || choice == "done") {
            break;
        }
        else if (choice == "Red" || choice == "red") {
            flask = &redPotion;
        }
        else if (choice == "Blue" || choice == "blue") {
            flask = &bluePotion;
        }
        else {
            std::cout << "Invalid choice. Please enter 'Red', 'Blue', or 'Done'." << std::endl;
            continue;
        }

        std::cout << "How many milliliters to add? ";
        float amount;
        std::cin >> amount;

        if (amount < 0) {
            std::cout << "Invalid amount. Please enter a positive value." << std::endl;
            continue;
        }

        *flask += amount; // Update the selected potion level

        std::cout << "Red Potion: " << redPotion << " mL, Blue Potion: " << bluePotion << " mL" << std::endl;
    }

    return 0;
}
