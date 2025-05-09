#include "TextProcessor.h"
#include "ReverseStrategy.h"
#include "UppercaseStrategy.h"
#include "RemoveVowelsStrategy.h"
#include "CensorStrategy.h"
#include <iostream>
#include <limits>
#include <memory>

int getChoice(int min, int max) {
    int c;
    while (true) {
        std::cout << "Select an option: ";
        if (std::cin >> c && c >= min && c <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return c;
        }
        std::cout << "Invalid. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    TextProcessor processor;
    std::string text;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, text);
    processor.setText(text);

    while (true) {
        std::cout << "\n1. Reverse\n2. Uppercase\n3. Remove Vowels\n4. Censor\n"
            << "5. New text\n6. Exit\n";
        int choice = getChoice(1, 6);
        if (choice == 6) break;
        if (choice == 5) {
            std::cout << "New sentence: ";
            std::getline(std::cin, text);
            processor.setText(text);
            continue;
        }
        std::unique_ptr<TextFilterStrategy> strat;
        std::string name;
        switch (choice) {
        case 1: strat = std::make_unique<ReverseStrategy>();      name = "Reverse";      break;
        case 2: strat = std::make_unique<UppercaseStrategy>();    name = "Uppercase";    break;
        case 3: strat = std::make_unique<RemoveVowelsStrategy>(); name = "Remove Vowels"; break;
        case 4: strat = std::make_unique<CensorStrategy>();       name = "Censor Bad Words"; break;
        }
        processor.setStrategy(std::move(strat));
        std::cout << "Current filter: " << name << "\n";
        std::cout << "Original: " << processor.getOriginalText() << "\n";
        std::cout << "Filtered: " << processor.processText() << "\n";
    }
    return 0;
}
